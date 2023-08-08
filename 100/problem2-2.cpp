#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef vector<vector<int>> vvi;
bool check(int x,int y){
    if(x<0||y<0||x>14||y>14)return true;
    return false;
}
int moved[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void solve(int n,vvi mp,vvi rd){
    int a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;
    a=a-1,b=b-1,c=c-1,d=d-1;
    queue<pair<int,int>>q;
    q.push({a,b});
    rd[a][b]=1;
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
    cout<<(rd[c][d]-2<=n&&rd[c][d]!=0?"TRUE":"FALSE")<<endl;
}
int main() {
    int n;
    string s;
    cin>>n;
    vvi mp(15,vector<int>(15,0));
    vvi rd(15,vector<int>(15,0));
    for(int j=0;j<15;j++){
        cin>>s;
        for(int k=0;k<15;k++){
            mp[j][k]=s[k]^48;
        }
    }
    solve(n,mp,rd);
    solve(n,mp,rd);
    cin.get();
    return 0;
}