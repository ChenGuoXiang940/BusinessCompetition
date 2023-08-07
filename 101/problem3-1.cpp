#include<iostream>
#include<unordered_set>
#include<sstream>
#include<algorithm>
using namespace std;
int main() {
    int letter[]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
    unordered_set<string>st;
    int n,t=0,o=0,f=0;
    char ch;
    string s,s1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        cin>>s;
        if(st.find(s)!=st.end()){
            o++;
            continue;
        }
        ch=s[0];
        s1=s.substr(1);
        if(!(s1[0]=='1'||s1[0]=='2')){
            f++;
            continue;
        }
        int r=(letter[ch-'A']/10)+(letter[ch-'A']%10)*9;
        int w=8;
        for(int j=0;j<9;j++){
            r+=w*(s1[j]^48);
            if(--w==0)w=1;
        }
        if(r%10==0){
            t++;
            st.insert(s);
        }
        else{
            f++;
        }
    }
    cout<<t<<","<<o<<","<<f<<endl;
    cin.get();
    return 0;
}