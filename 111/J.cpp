#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
bool check(ll v){
    ll sq=(ll)sqrt(v);
    for(ll i=5;i<=sq;i+=6){
        if(v%i==0||v%(i+2)==0)return false;
    }
    return true;
}
int main() {
    int n;
    ll a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a<=2)cout<<"2\n";
        if(a<=3)cout<<"3\n",a=5;
        int j=((a-5)/6)*6+5;
        if(a<=j&&check(j))cout<<j<<endl;
        if(a<=j+2&&j+2<=b&&check(j+2))cout<<j+2<<endl;
        j+=6;
        for(;j<=b;j+=6){
            if(check(j))cout<<j<<endl;
            if(j+2<=b&&check(j+2))cout<<j+2<<endl;
        }
    }
    cin.get();
    return 0;
}