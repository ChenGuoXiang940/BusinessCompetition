#include<iostream>
#include<unordered_set>
#include<math.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        string text=to_string(n);
        unordered_set<ll>set;
        while((n&1)==0){
            set.insert(2);
            n>>=1;
        }
        while(n%3==0){
            set.insert(3);
            n/=3;
        }
        for(int i=5;i<=sqrt(n);i+=6){
            while(n%i==0){
                set.insert(i);
                n/=i;
            }
            while(n%(i+2)==0){
                set.insert(i+2);
                n/=(i+2);
            }
        }
        if(n>3)set.insert(n);
        cout<<text<<":"<<set.size()<<endl;
    }
    cin.get();
    return 0;
}