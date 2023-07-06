#include<iostream>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        int a=s[0]-'0';
        for(int i=1;i<s.length();i++){
            a=i%2==1?a+(s[i]-'0'):a-(s[i]-'0');
        }
        cout<<a<<endl;
    }
    return 0;
}