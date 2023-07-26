#include <iostream>
#include<unordered_map>
using namespace std;
int main() {
    string s;
    string s2;
    getline(cin,s);
    getline(cin,s2);
    unordered_map<char,bool>fg;
    for(const auto&item:s2){
        fg[item]=true;
    }
    string result="";
    for(const auto&item:s){
        if(!fg[item]){
            result+=item;
        }
    }
    cout<<result<<endl;
    cin.get();
    return 0;
}