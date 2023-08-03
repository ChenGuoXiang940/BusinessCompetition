#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main() {
    int n,a;
    string s;
    char del;
    cin>>n;
    cin.ignore();
    getline(cin,s);
    stringstream ss(s);
    vector<int>v;
    for(int i=0;i<5;i++){
        ss>>a>>del;
        v.push_back(a);
    }
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss1(s);
        map<int,int>mp;
        int total=0;
        int num[6]={0};
        for(int j=0;j<6;j++){
            ss1>>a>>del;
            if(find(v.begin(),v.end(),a)!=v.end()){
                num[j]=1;
                total++;
            }
        }
        for(const int item:num){
            mp[total-item]++;
        }
        string r="";
        for(int j=2;j<6;j++){
            r+=to_string(mp[j])+",";
        }
        r.erase(r.end()-1);
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}