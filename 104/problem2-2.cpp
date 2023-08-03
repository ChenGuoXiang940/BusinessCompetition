#include<iostream>
#include<sstream>
using namespace std;
int gcd(int a,int b){
    if(a==1)return b;
    else return a%b==0?b:gcd(b,a%b);
}
int main() {
    int n,a,b;
    string s;
    char del;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        ss>>a>>del>>b>>del;
        a=gcd(a,b);
        if(!ss.str().empty()){
            ss>>b>>del;
            a=a>b?gcd(a,b):gcd(b,a);
        }
        cout<<a<<endl;
    }
    cin.get();
    return 0;
}