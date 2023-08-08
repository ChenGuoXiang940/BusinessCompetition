#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<sstream>
using namespace std;
typedef pair<string,int> psi;
bool cmp(psi a,psi b){
    if(a.second/100>b.second/100)return true;
    else if(a.second/100<b.second/100)return false;
    int m=a.second%100;
    int n=b.second%100;
    int m1=m%13==1?14:m%13;
    int n1=n%13==1?14:m%13;
    if(m1>n1)return true;
    else if(m1<n1)return false;
    if(m<n)return true;
    return false;
}
int main() {
    string suit="SHDC";
    int n;
    string s,s1;
    vector<psi>v;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        int num[5]={0};
        int num1[5]={0};
        int index=0;
        unordered_map<int,int>mp;
        while(getline(ss,s1,' ')){
            int val=atoi(s1.substr(1).c_str());
            num[index]=val;
            num1[index++]=val+suit.find(s1[0])*13;
            mp[val]++;
        }
        sort(num,num+5);
        sort(num1,num1+5);
        bool fg=false,fg1=false,fg2=false,fg3=false;
        int max1=0;
        for(const auto it:mp){
            if(max1==0)max1=it.first;
            if(it.second==4)fg=true;
            else if(it.second==3)fg1=true;
            else if(it.second==2&&!fg2)fg2=true;
            else if(it.second==2)fg3=true;
        }
        int* aim=find(begin(num),end(num),max1);
        int item=num1[distance(begin(num),aim)];
        if(num[0]+1==num[1]&&num[1]+1==num[2]&&num[2]+1==num[3]&&num[3]+1==num[4]){
            v.push_back({s,700+item});
        }
        else if(fg){
            v.push_back({s,600+item});
        }
        else if(fg1&&fg2){
            v.push_back({s,500+item});
        }
        else if(num1[0]+1==num1[1]&&num1[1]+1==num1[2]&&num1[2]+1==num1[3]&&num1[3]+1==num1[4]){
            v.push_back({s,400+item});
        }
        else if(fg1){
            v.push_back({s,300+item});
        }
        else if(fg2&&fg3){
            v.push_back({s,200+item});
        }
        else if(fg2){
            v.push_back({s,100+item});
        }
        else{
            v.push_back({s,item});
        }
    }
    sort(v.begin(),v.end(),cmp);
    cout<<v[0].first<<endl;
    cout<<v[v.size()-1].first<<endl;
    cin.get();
    return 0;
}