#include<iostream>
#include<sstream>
#include<cctype>
using namespace std;
string low(string& s){
    for(char &c:s){
        c=tolower(c);
    }
}
int main() {
    int r=0,n=0;
    string s,s1,s2;
    cin>>s;
    low(s);
    cin.ignore();
    while(true){
        getline(cin,s1);
        if(s1=="EOF")break;
        stringstream ss(s1);
        while(getline(ss,s2,' ')){
            low(s2);
            if(s2==s)r++;
            n++;
        }
    }
    cout<<r<<","<<n<<endl;
    cin.get();
    return 0;
}