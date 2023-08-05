#include<iostream>
#include<set>
using namespace std;
int main() {
    int n;
    string s,s1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        cin>>s1;
        set<char>st;
        for(const char item:s1){
            st.insert(item);
        }
        set<char>st1;
        for(const char item:s){
            if(st.count(item)){
                st1.insert(item);
            }
        }
        string r="";
        for(const char item:st1){
            r+=item;
        }
        if(r!="")cout<<r<<endl;
        else cout<<"N"<<endl;
    }
    cin.get();
    return 0;
}