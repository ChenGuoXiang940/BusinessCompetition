#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct Data{
    int left;
    int right;
    int parent;
    int degree;
    int depth;
    int height;
    Data():left(-1),right(-1),parent(-1),degree(0),depth(0),height(0){}
};
void dfs(int index,int dep,map<int,Data>&mp){
    if(index==-1)return;
    mp[index].depth=dep;
    dfs(mp[index].left,dep+1,mp);
    dfs(mp[index].right,dep+1,mp);
}
void up(int index,int hei,map<int,Data>&mp){
    if(index==-1||mp[index].height>hei)return;
    mp[index].height=hei;
    up(mp[index].parent,hei+1,mp);
}
int main() {
    int n,root,l,r;
    cin>>n;
    map<int,Data>mp;
    vector<int>record;
    for(int i=0;i<n;i++){
        cin>>root>>l>>r;
        if(mp.count(root)==0){
            mp[root]=Data();
        }
        mp[root].left=l;
        mp[root].right=r;
        if(l!=-1){
            if(mp.count(l)==0){
                mp[l]=Data();
            }          
            mp[l].parent=root;
            mp[root].degree++;
        }
        if(r!=-1){
            if(mp.count(r)==0){
                mp[r]=Data();
            }
            mp[r].parent=root;
            mp[root].degree++;
        }
        if(l==-1&&r==-1)record.push_back(root);
    }
    dfs(0,0,mp);
    for(int index:record){
        up(index,0,mp);
    }
    for(const auto& item:mp){
        cout<<"node "<<item.first<<": parent="<<item.second.parent<<",degree="<<item.second.degree<<
        ",depth="<<item.second.depth<<",height="<<item.second.height<<endl;
    }
    cin.get();
    return 0;
/*
9
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1
*/
/*
6
0 3 -1
1 -1 5
2 -1 -1
3 4 -1
4 2 1
5 -1 -1
*/
}