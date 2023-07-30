#include<iostream>
using namespace std;
int main() {
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        int r=0;
        int m=2;
        for(int j=0;j<16;j++){
            int n_new=(s[j]-'0')*m;
            r=(n_new>=10)?r+n_new-9:r+n_new;
            m=(m==2)?1:2;
        }
        if(r%10==0)cout<<"T"<<endl;
        else cout<<"F"<<endl;
    }
    cin.get();
    return 0;
}