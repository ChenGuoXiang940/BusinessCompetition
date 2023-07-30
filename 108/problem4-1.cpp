#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct Data
{
    int val=0;
    vector<int>v;
};
/*兩個顏色 0=>沒有 1或-1=>有被著色*/
bool dfs(unordered_map<int,Data>&graph,int node,int color){
    graph[node].val=color;
    for(auto& next:graph[node].v){
        //如果相鄰節點已經被著色(1或-1)，判斷當前節點顏色
        //如果相鄰節點未被著色，遞迴dfs
        if(graph[next].val==color)return false;
        if(graph[next].val==0&&!dfs(graph,next,-color))return false;
    }
    return true;
}
bool solve(unordered_map<int,Data>&graph){
    for(auto& node:graph){
        //遍歷每個未被著色的節點
        if(node.second.val==0&&!dfs(graph,node.first,1))return false;
    }
    return true;
}
int main(){
    int n,V,E,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>V;
        cin>>E;
        unordered_map<int,Data>graph;
        for(int j=0;j<E;j++){
            cin>>a>>b;
            //無向圖，需雙向
            graph[a].v.push_back(b);
            graph[b].v.push_back(a);
        }
        if(solve(graph))cout<<"T"<<endl;
        else cout<<"F"<<endl;
    }
    system("Pause");
    return 0;
}