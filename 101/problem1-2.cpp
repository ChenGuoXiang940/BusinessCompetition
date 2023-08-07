#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
string low(string& s){
    for(char &c:s){
       c=tolower(c);
    }
}
int main() {
    unordered_map<string,int>mp;
    string s,s1;
    while(true){
        getline(cin,s);
        if(s=="EOF")break;
        stringstream ss(s);
        while(getline(ss,s1,' ')){
            low(s1);
            mp[s1]++;
        }
    }
    vector<pair<string,int>>v(mp.begin(),mp.end());
    sort(v.begin(),v.end(),[](auto a,auto b) {return a.second > b.second;});
    int c=0;
    string r="";
    for(auto it:v){
        r+=to_string(it.second)+",";
        if(++c==3)break;
    }
    r.erase(r.end()-1);
    cout<<r<<endl;
    cin.get();
    return 0;
}