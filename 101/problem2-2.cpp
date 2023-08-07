#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
typedef pair<bool,vector<int>> pr;
bool check(unordered_map<int,pr>&mp){
    /*BFS*/
    queue<pair<int,int>>q;//儲存當前節點、上一個節點
    q.push({0,0});
    mp[0].first=true;
    while(q.size()>0){
        int len=q.size();
        for(int i=0;i<len;i++){
            auto cur=q.front();
            q.pop();
            for(int it:mp[cur.first].second){
                if(cur.second==it)continue;
                q.push({it,cur.first});
                if(mp[it].first)return false;
                mp[it].first=true;
            }
        }
    }
    for(auto it:mp){
        if(!it.second.first)return false;
    }
    return true;
}
int main() {
    int n,a,b;
    string s,s1;
    char del;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        unordered_map<int,pr>mp;
        getline(cin,s);
        stringstream ss(s);
        while(getline(ss,s1,' ')){
            stringstream ss1(s1);
            ss1>>a>>del>>b;
            mp[a].second.push_back(b);
            mp[b].second.push_back(a);
            mp[a].first=mp[b].first=false;
        }
        if(!check(mp)){
            cout<<"F"<<endl;
            continue;
        }
        int r=0;
        for(auto it:mp){
            if(it.second.second.size()==1){
                r++;
            }
        }
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}