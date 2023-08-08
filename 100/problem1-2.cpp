#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int cmp(char ch){
    if(ch=='*'||ch=='/')return 2;
    if(ch=='+'||ch=='-')return 1;
    return 0;
}
int op(int a,int b,char ch){
    if(ch=='+')return b+a;
    if(ch=='-')return b-a;
    if(ch=='*')return b*a;
    if(ch=='/')return b/a;
    return 0;
}
int figure(string s){
    stack<char>sk;
    stack<int>q;
    string d="";
    for(int i=0;i<s.size();i++){
        if(cmp(s[i])>=1){
            q.push(atoi(d.c_str()));
            d="";
            while(sk.size()>=1&&cmp(s[i])<=cmp(sk.top())){
                int a=q.top();
                q.pop();
                int b=q.top();
                q.pop();
                q.push(op(a,b,sk.top()));
                sk.pop();
            }
            sk.push(s[i]);
        }
        else{
            d+=s[i];
        }
    }
    q.push(atoi(d.c_str()));
    while(sk.size()!=0){
        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();
        q.push(op(a,b,sk.top()));
        sk.pop();
    }
    return q.top();
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