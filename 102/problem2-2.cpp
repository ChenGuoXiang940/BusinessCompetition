#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
char ch[6];
string s;
int len;
vector<string>v;
void f(int c,bool fg[]){
    if(c==len){
        string buffer(ch,len);
        v.push_back(buffer);
        return;
    }
    for(int i=0;i<len;i++){
        if(fg[i])continue;
        fg[i]=true;
        ch[c]=s[i];
        f(c+1,fg);
        fg[i]=false;
    }
}
int gcd(int a,int b){
    if(a==1)return b;
    else return a%b==0?b:gcd(b,a%b);
}
int main() {
    int n,a,b,c;
    char del;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        auto newend=remove(s.begin(),s.end(),' ');
        s.erase(newend,s.end());
        stringstream ss(s);
        ss>>a>>del>>b>>del>>c;
        s=to_string(a);
        len=s.size();
        bool fg[len]={false};
        v.clear();
        f(0,fg);
        cout<<gcd(atoi(v[b-1].c_str()),atoi(v[c-1].c_str()))<<endl;
    }
    cin.get();
    return 0;
}