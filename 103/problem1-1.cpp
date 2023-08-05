#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
bool check(ll v){
    if(v==3)return true;
    ll m=v%6;
    if(m!=1&&m!=5)return false;
    ll sq=(ll)sqrt(v);
    for(ll i=5;i<=sq;i+=6){
        if(v%i==0||v%(i+2)==0)return false;
    }
    return true;
}
int main() {
    int n,a,b;
    char del;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>del>>b;
        if(a+2==b&&check(a)&&check(b))cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    cin.get();
    return 0;
}