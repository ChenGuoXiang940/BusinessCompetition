#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
    //5
    //0001
    //0010
    //0011
    //0100
    //0101
    //q=5/2=2...1 2*1=2 (1>=1)=>1-1+1=1
    //q=5/4=1...1 1*2=2
    //q=5/8=0...5 0*4=0 (5>4)=>5-4+1=2
    //total=2+1+2+2=7
    ll n;
    while(cin>>n){
        ll power=1;
        ll total=0;
        while (power<=n){
            ll quotient=n/(power<<1);
            ll remainder=n%(power<<1);
            total+=quotient*power;
            if (remainder>=power){
                total+=remainder-power+1;
            }
            power<<=1;
        }
        cout<<total<<endl;
    }
    cin.get();
    return 0;
}