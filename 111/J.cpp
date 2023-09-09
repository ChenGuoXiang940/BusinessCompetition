#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    int a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vector<bool>isprime(b+1, true);
        isprime[0]=isprime[1]=false;
        for(int j=2;j*j<=b;j++){
            if(isprime[j]){
                for(int k=j*j;k<=b;k+=j){
                    isprime[k]=false;
                }
            }
        }
        for(int j=a;j<=b;j++){
            if(isprime[j])cout<<j<<endl;
        }
    }
    cin.get();
    return 0;
}