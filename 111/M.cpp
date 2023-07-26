#include<iostream>
using namespace std;
int N;
string toBinary(int n)
{
    string r="";
    while (n!=0){
        r=((n&1)==0?"0":"1")+r;
        n>>=1;
    }
    string buffer(N-r.size(),'0');
    return buffer+r;
}
void f(int n){
    if(n==1){
        cout<<toBinary(0)<<endl;
        cout<<toBinary(1)<<endl;
        return;
    }
    f(n-1);
    int Add=1<<(n-1);
    for(int i=(1<<(n-1))-1;i>=0;i--){
        cout<<toBinary(i+Add)<<endl;
    }
}
int main() {
    int n;
    cin>>n;
    N=n;
    f(n);
    cin.get();
    return 0;
}