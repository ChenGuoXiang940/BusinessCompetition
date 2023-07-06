#include<iostream>
#include<map>
#define fo(b) for(int i=0;i<b;i++)
using namespace std;
int main(){
    int ans[4];
    int n,val;
    fo(4)cin>>ans[i];
    cin>>n;
    fo(n){
        int A=0,B=0;
        map<int,int>mp;
        fo(4){
            cin>>val;
            if(val==ans[i])A++;
            if(mp.find(val)!=mp.end())mp[val]++;
            else mp[val]=1;
        }
        fo(4){
            if(mp.find(ans[i])!=mp.end()&&mp[ans[i]]-->0)B++;
        }
        cout<<A<<"A"<<B-A<<"B"<<endl;
    }
    system("Pause");
    return 0;
}