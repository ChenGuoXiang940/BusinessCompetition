#include<iostream>
#include<sstream>
using namespace std;
int main() {
    int n;
    cin>>n;
    string s;
    int a1,a2,a3,a4,b1,b2,b3,b4;
    char de;
    for(int i=0;i<n;i++){
        cin>>s;
        stringstream ss(s);
        ss>>a1>>de>>a2>>de>>a3>>de>>a4>>de>>b1>>de>>b2>>de>>b3>>de>>b4;
        b1=~b1&0xFF;
        b2=~b2&0xFF;
        b3=~b3&0xFF;
        b4=~b4&0xFF;
        cout<<(a1|b1)<<"."<<(a2|b2)<<"."<<(a3|b3)<<"."<<(a4|b4)<<endl;
    }
    cin.get();
    return 0;
}