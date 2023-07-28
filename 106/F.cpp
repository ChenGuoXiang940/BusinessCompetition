#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<unordered_map>
using namespace std;
bool cmp(string s1,string s2){
    if(s1.size()>s2.size())return false;
    if(s1.size()<s2.size())return true;
    for(int i=0;i<s1.size();i++){
        if(s1[i]>s2[i])return false;
    }
    return true;
}
int main(){
    int n;
    size_t pos;
    string s,s1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        vector<string>v,v2;
        unordered_map<string,int>mp;
        getline(cin,s);
        auto newEnd=remove(s.begin(), s.end(),' ');
        s.erase(newEnd,s.end());
        stringstream ss(s);
        while(getline(ss,s1,',')){
            v.push_back(s1);
            v2.push_back(s1);
        }
        sort(v.begin(),v.end(),cmp);
        for(int j=0;j<v.size();j++){
            mp[v[j]]=j;
        }
        string r="";
        for(auto item:v2){
            r+=to_string(mp[item]+1)+",";
        }
        r.erase(r.end()-1);
        cout<<r<<endl;
    }
/*
4
222222222222222222222222222, 555555555555555555555555555,111111111111111,44444444444444444444444444444444444444444444444444444,33333333333333333333333333333333333333333333
123456789,123456787, 123456788
3333333333333333333333333,1111111111111111111111111,2469135802469135802469135308641975308641975308642
44444444444444444444444444444444444444444444444444444,111111111111111,222222222222222222222222222,33333333333333333333333333333333333333333333
*/
    cin.get();
    return 0;
}