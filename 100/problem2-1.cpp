#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool check(int x,int y){
    if(x<0||y<0||x>14||y>14)return true;
    return false;
}
int moved[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main() {
    int n;
    string s;
    cin>>n;
    for(int i=0;i<2;i++){
        vector<vector<int>>mp(15,vector<int>(15,0));
        vector<vector<int>>rd(15,vector<int>(15,0));
        for(int j=0;j<15;j++){
            cin>>s;
            for(int k=0;k<15;k++){
                mp[j][k]=s[k]^48;
            }
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        rd[0][0]=1;
        while(q.size()>0){
            int len=q.size();
            for(int j=0;j<len;j++){
                auto cur=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int x=cur.first+moved[k][0];
                    int y=cur.second+moved[k][1];
                    if(check(x,y)||mp[x][y]==1)continue;
                    if(rd[x][y]==0||rd[x][y]>rd[cur.first][cur.second]+1){
                        rd[x][y]=rd[cur.first][cur.second]+1;
                        q.push({x,y});
                    }
                }
            }
        }
        cout<<(rd[14][14]-2<=n&&rd[14][14]!=0?"TRUE":"FALSE")<<endl;
    }
    cin.get();
    return 0;
}