#include<iostream>
using namespace std;
char check(const char num[3][3]){
    for(int j=0;j<3;j++){
        if(num[0][j]==num[1][j]&&num[1][j]==num[2][j])return num[0][j];
        if(num[j][0]==num[j][1]&&num[j][1]==num[j][2])return num[j][0];
    }
    if(num[0][0]==num[1][1]&&num[1][1]==num[2][2])return num[0][0];
    if(num[0][2]==num[1][1]&&num[1][1]==num[2][0])return num[0][2];
    return '3';
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char num[3][3];
        for(int j=0;j<3;j++){
            cin.ignore();
            for(int k=0;k<3;k++){                
                num[j][k]=getchar();
            }
        }
        char ans=check(num);
        if(ans=='1'||ans=='2')cout<<ans<<endl;
        else cout<<"3"<<endl;
    }
    system("Pause");
    return 0;
}