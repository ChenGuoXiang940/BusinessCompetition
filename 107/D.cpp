#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
int len;
vector<int>v;
vector<string>ans;
char ch[5];
bool cmp(string a,string b){
    return atoi(a.c_str())<atoi(b.c_str());
}
void all(const int c,bool fg[]){
    if(c==len){
        string s(ch,len);
        ans.push_back(s);
        return;
    }
    for(int i=0;i<len;i++){
        if(fg[i])continue;
        fg[i]=true;
        ch[c]=(char)(v[i]+'0');
        all(c+1,fg);
        fg[i]=false;
    }
}
int main(){
    int n;
    string s,data;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        v.clear();
        while(getline(ss,data,','))
        {
            v.push_back(atoi(data.c_str()));
        } 
        v.erase(v.begin());//移除最前面元素
        int k=v[v.size()-1];
        v.erase(v.end()-1);//移除最後面元素
        ans.clear();
        len=v.size();
        bool fg[len]={false};
        all(0,fg);
        sort(ans.begin(),ans.end(),cmp);
        cout<<ans[k-1]<<endl;
    }
    system("Pause");
    return 0;
}