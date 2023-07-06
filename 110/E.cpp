#include<iostream>
#include<sstream>
#include<map>
#include<vector>
using namespace std;
int main(){
    map<string,string>mp;
    string str,data;
    cin.ignore();
    while(getline(cin,str)){
        stringstream ss(str);
        vector<string>v;
        while(getline(ss,data,' ')){
            v.push_back(data);
        }
        if(v.size()!=2)break;
        mp[v[0]]=v[1];
        mp[v[1]]=v[0];
    }
    while(cin>>str){
        if(mp.find(str)!=mp.end())cout<<mp[str]<<endl;//找到了
        else cout<<"eh\r\n";//找不到
    }
    system("Pause");
/*
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay
*/
    return 0;
}