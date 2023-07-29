#include<iostream>
#include<sstream>
#include<map>
using namespace std;
int main(){
    map<string,string>mp;
    string s,s1,s2;
    cin.ignore();
    while(getline(cin,s)){
        stringstream ss(s);
        if(ss.str().empty())break;
        ss>>s1>>s2;
        mp[s1]=s2;
        mp[s2]=s1;
    }
    while(cin>>s){
        if(mp.find(s)!=mp.end())cout<<mp[s]<<endl;
        else cout<<"eh\r\n";
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