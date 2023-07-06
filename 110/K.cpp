#include<iostream>
typedef long long ll;
using namespace std;
int main(){
    ll x,y,m;
    while(cin>>x>>y>>m){
        int ans=1;
        while(y!=0){
            if(y&1==1)ans=ans*x%m;
            y>>=1;
            x=x*x%m;
        }
        cout<<ans<<endl;
    }
    return 0;
}