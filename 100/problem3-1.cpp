#include<iostream>
using namespace std;
int main() {
    int letter[]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        int w=8;
        int r=0;
        for(int j=0;j<9;j++){
            r+=w*(s[j]^48);
            if(--w==0)w=1;
        }
        string s1="";
        for(int j=0;j<26;j++){
            if((letter[j]/10+letter[j]%10*9+r)%10==0){
                s1+=(char)('A'+j);
            }
        }
        cout<<s1<<endl;
    }
    cin.get();
    return 0;
}