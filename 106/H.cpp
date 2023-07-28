#include<iostream>
#include<sstream>
#include<stack>
using namespace std;
int oper(string op,int a,int b){
    if(op=="+")return b+a;
    if(op=="-")return b-a;
    if(op=="*")return b*a;
    if(op=="/")return b/a;
    return 0;
}
int main() {
    int n;
    string s,s1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        stack<int>sk;
        while(getline(ss,s1,' ')){
            if(s1=="+"||s1=="-"||s1=="*"||s1=="/"){
                int num1=sk.top();
                sk.pop();
                int num2=sk.top();
                sk.pop();
                sk.push(oper(s1,num1,num2));
            }
            else{
                sk.push(atoi(s1.c_str()));
            }           
        }
        cout<<sk.top()<<endl;
    }
/*
3
3 5 +
9 2 3 5 + * +
6 3 / 1 4 - * 3 + 8 -

3
2 3 + 4 *
2 3 4 + * 5 *
2 123 -
*/
    cin.get();
    return 0;
}