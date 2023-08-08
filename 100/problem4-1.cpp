#include<iostream>
using namespace std;
int main() {
    int num[]={50,20,10,5,1};
    int n,a;
    cin>>n;
    int r[5]={0};
    for(int i=0;i<n;i++){
        cin>>a;
        a=100-a;
        for(int j=0;j<5;j++){
            if(a>=num[j]){
                r[j]+=(a/num[j]);
                a%=num[j];
            }
        }
    }
    for(int i=0;i<5;i++){
        cout<<num[i]<<","<<r[i]<<" ";
    }
    cin.get();
    return 0;
}