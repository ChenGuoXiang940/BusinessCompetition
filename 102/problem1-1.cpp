#include<iostream>
#include<set>
using namespace std;
int main() {
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        set<int>st;
        for(const char it:s){
            if(it>='0'&&it<='9')st.insert(it);
        }
        string r="";
        for(const char it:st){
            r+=it;
        }
        if(r=="")cout<<"N"<<endl;
        else cout<<r<<endl;
    }
    cin.get();
    return 0;
}