#include<iostream>
using namespace std;
int main() {
    int n;
    string s,s1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        cin>>s1;
        int num[s.size()+1][s1.size()+1];
        for(int j=0;j<=s.size();j++){
            num[j][0]=0;
        }
        for(int j=0;j<=s1.size();j++){
            num[0][j]=0;
        }
        for(int m=1;m<=s.size();m++){
            for(int n=1;n<=s1.size();n++){
                if(s[m-1]==s1[n-1]){
                    num[m][n]=num[m-1][n-1]+1;
                }
                else
                {
                    num[m][n]=max(num[m-1][n],num[m][n-1]);
                }
            }
        }
        cout<<num[s.size()][s1.size()]<<endl;
    }
    cin.get();
    return 0;
}