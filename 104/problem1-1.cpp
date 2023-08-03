#include<iostream>
#include<sstream>
using namespace std;
int main() {
    int n,n1,a,b;
    string s;
    char del;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>n1;
        cin.ignore();
        getline(cin,s);
        stringstream ss(s);
        int r=0;
        for(int j=0;j<n1;j++){
            if(j>=1)b=a;
            ss>>a>>del;
            if(j>=1){
                (a>b)?r+=(a-b)*20:r+=(b-a)*10;
            }
        }   
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}