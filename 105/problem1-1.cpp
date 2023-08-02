#include<iostream>
#include<sstream>
using namespace std;
int main() {
    int n;
    string s,s1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        int r=0;
        while(getline(ss,s1,' ')){
            r++;
        }
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}