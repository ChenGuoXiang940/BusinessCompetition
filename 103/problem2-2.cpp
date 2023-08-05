#include<iostream>
#include<sstream>
#include<unordered_set>
using namespace std;
int main() {
    int n;
    string s,s1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        unordered_set<int>st;
        while(getline(ss,s1,' ')){
            st.insert(atoi(s1.c_str()));
        }
        getline(cin,s);
        stringstream ss1(s);
        int r=0;
        while(getline(ss1,s1,' ')){
            if(st.count(atoi(s1.c_str())))r++;
        }
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}