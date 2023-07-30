#include<iostream>
using namespace std;
int main(){
    int n,X,Y,M;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>X>>Y>>M;
        int R=1;
        while (Y!=0)
        {
            if((Y&1)==1)R=R*X%M;
            Y>>=1;
            X=X*X%M;
        }
        cout<<R<<endl;
    }
    system("Pause");
    return 0;
}