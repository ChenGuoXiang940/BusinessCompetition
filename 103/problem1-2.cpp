#include<iostream>
using namespace std;
int main() {
    int n,a,b,c,d;
    char del;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>del>>b>>del>>c>>del>>d;
        for(int j=0;j<=a;j++){
            if(b*(a-j)+c*j==d){
                cout<<(a-j)<<","<<j<<endl;
                break;
            }
        }
    }
    cin.get();
    return 0;
}