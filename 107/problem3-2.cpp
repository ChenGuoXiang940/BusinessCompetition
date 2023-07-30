#include<iostream>
#include<math.h>
using namespace std;
int solove(int v,int m){
    if(v<0){
        v=abs(v)%m;
        if(v==0)return 0;
        return m-v;
    }
    return v%m;
}
int main(){
    int n,a1,a2,b1,b2,m1,m2;
    cin>>n;
    for(int i=0;i<n;i++){
        int result=0;
        cin>>a1>>a2>>b1>>b2>>m1>>m2;
        for(int a=a1;a<=a2;a++){
            for(int b=b1;b<=b2;b++){
                for(int m=m1;m<=m2;m++){
                    if(solove(a+b,m)==solove(a-b,m)){
                        //cout<<a<<"+"<<b<<"MOD"<<m<<" "<<solove(a+b,m)<<" "<<solove(a-b,m)<<endl;
                        result++;
                    }
                }
            }
        }
        cout<<result<<endl;
    }
    system("Pause");
    return 0;
}