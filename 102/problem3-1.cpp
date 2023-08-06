#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
    int n,a,b,m,k;
    char del;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m>>del>>k;
        unordered_map<int,int>mp;
        for(int j=0;j<m;j++){
            cin>>a>>del>>b;
            mp[a]=b;
        }
        int r=0;
        for(auto it:mp){
            int v=it.first;
            int u=0;
            while(mp[v]!=99){
                if(++u>k){
                    break;
                }
                v=mp[v];
            }
            if(u==k)r++;
        }
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}