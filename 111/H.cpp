#include <iostream>
using namespace std;
int main() {
    int n;
    string s;
    while(cin>>n>>s){
        if(n==0)break;
        int group=s.size()/n;
        int i=0;
        string buffer="";
        string result="";
        for(char item:s){
            buffer=item+buffer;
            if(group==++i){
                result+=buffer;
                buffer="";
                i=0;
            }
        }
        cout<<result<<endl;
    }
    cin.get();
    return 0;
}