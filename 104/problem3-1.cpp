#include<iostream>
using namespace std;
int main() {
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        int r=0;
        while(a>0){
            r++;
            a&=(a-1);
        }
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}