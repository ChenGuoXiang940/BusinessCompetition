#include <iostream>
using namespace std;
int main() {
    string s;
    while(getline(cin,s))
    {
        string s2="";
        bool fg=false;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='0')fg=true;
            if(fg)s2+=s[i];
        }
        cout<<s2<<endl;
    }
    cin.get();
    return 0;
}