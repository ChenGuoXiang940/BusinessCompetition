#include<iostream>
#include<set>
using namespace std;
int main() {
    string s;
    string s2;
    getline(cin,s);
    getline(cin,s2);
    set<char>st;
    for(const char&item:s2){
        st.insert(item);
    }
    string result="";
    for(const char&item:s){
        if(!st.count(item)){
            result+=item;
        }
    }
    cout<<result<<endl;
    cin.get();
    return 0;
}