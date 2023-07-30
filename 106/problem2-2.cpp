#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
vector<string>v;
int len;
string s;
char ch[6];
void all(const int c,bool fg[]){
    if(c==len){
        string data(ch,len);
        v.push_back(data);
        return;
    }
    for(int i=0;i<len;i++){
        if(fg[i])continue;
        fg[i]=true;
        ch[c]=s[i];
        all(c+1,fg);
        fg[i]=false;
    }
}
int main() {
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        istringstream ss(s);
        getline(ss, s, ',');
        char delimiter;//用來接收逗號的緩衝
        ss >>a>>delimiter>>b>>delimiter;
        v.clear();
        len=s.size();
        bool fg[len]={false};
        all(0,fg);
        string a1=v[a-1];
        string b1=v[b-1];
        int A=0,B=0;
        for(int j=0;j<len;j++){
            if(a1[j]==b1[j])A++;
            else if(b1.find(a1[j])!=string::npos)B++;
        }
        cout<<A<<"A"<<B<<"B"<<endl;
    }
    cin.get();
    return 0;
}