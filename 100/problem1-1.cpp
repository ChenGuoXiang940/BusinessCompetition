#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int op(int a,int b,char ch){
    if(ch=='+')return b+a;
    if(ch=='-')return b-a;
    return 0;
}
int figure(string s){
    stack<char>sk;
    stack<int>q;
    string d="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='+'||s[i]=='-'){
            if(q.size()>=1){
                int a=atoi(d.c_str());
                d="";
                int b=q.top();
                q.pop();
                q.push(op(a,b,sk.top()));
                sk.pop();
            }
            else{
                q.push(atoi(d.c_str()));
                d="";
            }
            sk.push(s[i]);
        }
        else{
            d+=s[i];
        }
    }
    if(q.size()==0)return atoi(d.c_str());
    return op(atoi(d.c_str()),q.top(),sk.top());
}
int main() {
    string s,s1,s2;
    for(int i=0;i<4;i++){
        cin>>s;
        int aim=s.find_first_of("=");
        s1=s.substr(0,aim);
        s2=s.substr(aim+2);
        cout<<(figure(s1)==figure(s2)?"TRUE":"FALSE")<<endl;
    }
    cin.get();
    return 0;
}