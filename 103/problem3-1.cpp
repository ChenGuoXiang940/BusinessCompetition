#include<iostream>
#include<algorithm>
#include<sstream>
#include<map>
#include<vector>
using namespace std;
int check(vector<int>num){
    for(int i=0;i<2;i++){
        int r=0;
        for(int j=i;j<5+i;j++){
            if(num[i]+(j-i)==num[j])r++;
        }
        if(r==5)return true;
    }
    return false;
}
int main() {
    int n;
    string s,s1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        vector<int>num;        
        getline(cin,s);
        stringstream ss(s);
        while(getline(ss,s1,' ')){
            num.push_back(atoi(s1.c_str()));
        }
        sort(num.begin(),num.end());
        if(check(num)){
            cout<<"7"<<endl;
            continue;
        }
        map<int,int>mp;
        for(int j=0;j<6;j++){
            num[j]=(num[j]%13==0)?13:num[j]%13;
            mp[num[j]]++;
        }
        bool fg=false,fg1=false,fg2=false,fg3=false;
        for(const pair<int,int> item:mp){
            if(item.second==4)fg=true;
            else if(item.second==3)fg1=true;
            else if(item.second==2&&!fg2)fg2=true;
            else if(item.second==2)fg3=true;
        }
        if(fg){
            cout<<"6"<<endl;
        }
        else if(fg1&&fg2){
            cout<<"5"<<endl;
        }
        else if(check(num)){
            cout<<"4"<<endl;
        }
        else if(fg1){
            cout<<"3"<<endl;
        }
        else if(fg2&&fg3){
            cout<<"2"<<endl;
        }
        else if(fg2){
            cout<<"1"<<endl;
        }
        else{
            cout<<"0"<<endl;
        }
    }
    cin.get();
    return 0;
}