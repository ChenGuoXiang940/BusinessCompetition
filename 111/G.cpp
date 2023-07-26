#include <iostream>
using namespace std;
string f(char ch,string& data){
    string buffer(atoi(data.c_str()),ch);
    return buffer;
}
int main() {
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        string result="";
        string data="";
        char ch='@';
        for(char item:s){
            if(item>='A'&&item<='Z'){
                if(ch!='@')result+=f(ch,data);
                ch=item;
                data="";
            }
            else{
                data+=item;
            }
        }
        cout<<result+f(ch,data)<<endl;
    }
    cin.get();
    return 0;
}