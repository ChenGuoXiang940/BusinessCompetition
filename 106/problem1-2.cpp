#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
    int n;
    string s;
    unordered_map<char,int>mp{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        int r=0;
        for(int j=0;j<s.size();j++){
            if(j+1<s.size()&&mp[s[j]]<mp[s[j+1]]){
                r-=mp[s[j]];
            }
            else{
                r+=mp[s[j]];
            }         
        }
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}