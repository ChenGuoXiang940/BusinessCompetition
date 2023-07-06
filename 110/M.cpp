#include<iostream>
using namespace std;
int main(){      
    //克羅內克積 mxn pxq
    int m,n,p,q;//mp × nq矩陣
    while(cin>>m>>n>>p>>q){
        int num1[m][n],num2[p][q],ans[m*n][p*q];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>num1[i][j];
            }
        }
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                cin>>num2[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<p;k++){
                    for(int l=0;l<q;l++){
                        ans[i * p + k][j * q + l] = num1[i][j] * num2[k][l];
                    }
                }
            }
        }
        for(int i=0;i<m*n;i++){
            for(int j=0;j<p*q;j++){
                cout<<to_string(ans[i][j])<<" ";
            }
            cout<<"\r\n";
        }
    }
    system("Pause");
    return 0;
}
