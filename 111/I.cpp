#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if(a.second<b.second)return true;
    if(a.second>b.second)return false;
    return a.first>b.first;
}
int main() {
    string s;
    while(cin>>s){
        map<int,int>mp;
        vector<pair<int,int>>v;
        for(char item:s){
            mp[(int)item]++;
        }
        for(const auto&item:mp){
            v.push_back({item.first,item.second});
        }
        sort(v.begin(),v.end(),cmp);
        for(const auto&item:v){
            cout<<item.first<<" "<<item.second<<endl;
        }
    }
    cin.get();
    return 0;
}