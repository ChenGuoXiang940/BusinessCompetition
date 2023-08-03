#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
char ch[6];
string s1;
vector<int>v;
int len;
void dfs(int d,bool fg[]){
    if(len==d){
        string buffer(ch,len);
        v.push_back(atoi(buffer.c_str()));
        return;
    }
    for(int i=0;i<len;i++){
        if(fg[i])continue;
        ch[d]=s1[i];
        fg[i]=true;
        dfs(d+1,fg);
        fg[i]=false;
    }
}
int main() {
    int n,a,b,c;
    string s;
    char del;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        ss>>a>>del>>b>>del>>c;
        s1=to_string(a);
        len=s1.size();
        v.clear();
        bool fg[len]={false};
        dfs(0,fg);
        cout<<v[b-1]+v[c-1]<<endl;
    }
    cin.get();
    return 0;
}