#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool dfs(int current,int end,unordered_map<int,vector<int>>&graph,vector<bool>&visited){
    if(current==end)return true;
    visited[current]=true;
    for(int next:graph[current]){
        if(!visited[next]&&dfs(next,end,graph,visited))return true;
    }
    return false;
}
int main(){
    int n,m,a,b,A,B;
    cin>>n>>m;
    unordered_map<int,vector<int>>graph;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
    }
    cin>>A>>B;
    vector<bool>visited(n+1,false);
    if(dfs(A,B,graph,visited))cout<<"Yes";
    else cout<<"No";
    system("Pause");
    return 0;
}