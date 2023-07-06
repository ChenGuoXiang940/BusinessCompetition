#include<iostream>
#include<vector>
#include<math.h>
typedef long long ll;
using namespace std;
vector<ll>f;
bool check(ll v){
    ll m=v%6;
    if(m!=1&&m!=5)return false;
    ll sq=(ll)sqrt(v);
    for(ll i=5;i<=sq;i+=6){
        if (v%i==0||v%(i+2)==0)return false;
    }
    return true;
}
bool go(ll val){
    for(int i=0;i<6054;){//f.size()
        if(val%f[i]==0)return true;
        else i++;
    }
    return false;
}
int main(){
    f.push_back(7);
    for (ll i = 11; i <= 60000; i += 6){
        if (check(i)) f.push_back(i);
        if (check(i + 2)) f.push_back(i + 2);
    }
    int n;
    ll val;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        while(val%2==0)val/=2;
        while(val%3==0)val/=3;
        while(val%5==0)val/=5;
        if(val==1)cout<<"True\n";
        else if(go(val))cout<<"False\n";
        else cout<<"True\n";
    }
    system("Pause");
    return 0;
}