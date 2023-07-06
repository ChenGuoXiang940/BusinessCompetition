#include<iostream>
#include<vector>
using namespace std;
struct Data{
    int record=0;
    int val;
};
int moved[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int N,M;
bool check(int x,int y){
    //x y範圍分別介於1~N、1~M之間 x在0、N+1或y在0、M+1則算在地圖界外
    if(x==0||y==0||x==N+1||y==M+1)return false;
    return true;
}
void dfs(vector<vector<Data>>& map,vector<vector<bool>>fg,int x,int y){
    fg[x][y]=true;
    for(int i=0;i<4;i++){
        //x y當前座標 ; x2 y2上下左右的新座標
        int x2=x+moved[i][0];
        int y2=y+moved[i][1];
        //地圖record比較 1.如果原本沒東西把新路徑權重直接放
        //              2.如果有東西把新路徑權重和原本的做比較只取小的 遞迴dfs
        if(check(x2,y2)&&!fg[x2][y2]&&(map[x2][y2].record==0||
        map[x2][y2].record>map[x][y].record+map[x2][y2].val)){
            map[x2][y2].record=map[x][y].record+map[x2][y2].val;
            dfs(map,fg,x2,y2);
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>N;
        cin>>M;
        vector<vector<Data>> map(N+1,vector<Data>(M+1));
        vector<vector<bool>> fg(N+1,vector<bool>(M+1));    
        for(int j=1;j<=N;j++){
            for(int k=1;k<=M;k++){
                cin>>map[j][k].val;
            }
        }
        for(int j=1;j<=N;j++){
            for(int k=1;k<=M;k++){
                if(map[j][k].record==0){
                    dfs(map,fg,j,k);
                }
            }
        }
        cout<<map[N][M].record<<endl;
    }
    system("Pause");
    return 0;
}