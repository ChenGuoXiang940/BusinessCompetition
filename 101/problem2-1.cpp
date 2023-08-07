#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
    int n,n1,a,b;
    char del;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>n1;
        unordered_map<int,int>mp;
        for(int j=1;j<n1;j++){
            cin>>a>>del>>b;
            mp[a]=b;
        }
        int r=0;
        for(auto it:mp){
            int index=it.first;
            int p=1;
            while(index!=0){
                index=mp[index];
                p++;
            }
            r=max(r,p);
        }
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}