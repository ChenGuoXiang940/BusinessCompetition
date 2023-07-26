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
        for(int i=3;i<=sqrt(n);i+=2){
            while(n%i==0){
                set.insert(i);
                n/=i;
            }
        }
        if(n>2)set.insert(n);
        cout<<text<<":"<<set.size()<<endl;
    }
    cin.get();
    return 0;
}