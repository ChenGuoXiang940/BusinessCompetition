#include<iostream>
using namespace std;
#define fo(b) for(int i=0;i<b;i++)
typedef long long int ll;
int main(){
    int n,a;
    ll total=0,min=1E10;
    cin>>n;
    fo(n){
        cin>>a;
        total+=a;
        if(a%2==1&&a<min)min=a;
    }
    if(total%2==0)cout<<total;
    else cout<<total-min;
    system("Pause");
    return 0;
    //5
    //99999999 99999999 99999999 99999999 99999999
}