#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        int t=0;
        char aim='X';
        vector<int>v;
        for(int j=0;j<s.size();j++){
            if(s[j]=='-'||s[j]=='X')continue;
            v.push_back(s[j]-'0');
        }
        if(v.size()>=12){
            if(v.size()==13)aim=(char)(v[12]+'0');
            int m=1;
            for(int j=0;j<12;j++){
                t+=v[j]*m;
                m=(m==1)?3:1;
            }
            int N=10-(t%10);
            char ch=N<=9?(char)('0'+N):'0';
            cout<<(ch==aim?"T":"F")<<endl;
        }
        else if(v.size()>=9){
            if(v.size()==10)aim=(char)(v[9]+'0');
            for(int j=0;j<9;j++){
                t+=v[j]*(10-j);
            }           
            int N=11-(t%11);
            char ch=N<=9?(char)('0'+N):N==10?'X':'0';
            cout<<(ch==aim?"T":"F")<<endl;
        }
    }
    cin.get();
    return 0;
}