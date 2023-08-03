#include<iostream>
using namespace std;
void solve(int m,int n,int r,int** a,int** b,int** c){
    int record=0;
    int d[m][n];
    for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
            d[j][k]=0;
            for(int l=0;l<r;l++){
                d[j][k]+=a[j][l]*b[l][k];
                if(a[j][l]==0)record=b[l][k];
                if(b[l][k]==0)record=a[j][l];
            }
            if(record!=0){
                cout<<(c[j][k]-d[j][k])/record<<endl;
                return;
            }
        }
    }     
}
int main() {
    int n1,m,r,n;
    string s;
    char del;
    cin>>n1;
    for(int i=0;i<n1;i++){
        cin>>m>>del>>r>>del>>r>>del>>n;
        int**a=new int*[m];
        int**b=new int*[r];
        int**c=new int*[m];
        for(int j=0;j<m;j++){
            a[j]=new int[r];
            for(int k=0;k<r;k++){
                cin>>a[j][k];
                if(a[j][k]==9999)a[j][k]=0;
            }
        }
        for(int j=0;j<r;j++){
            b[j]=new int[n];
            for(int k=0;k<n;k++){
                cin>>b[j][k];
                if(b[j][k]==9999)b[j][k]=0;
            }
        }
        for(int j=0;j<m;j++){
            c[j]=new int[n];
            for(int k=0;k<n;k++){
                cin>>c[j][k];
            }
        }
        solve(m,n,r,a,b,c);
    }
    cin.get();
    return 0;
}