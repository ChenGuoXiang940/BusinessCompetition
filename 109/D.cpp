#include<iostream>
using namespace std;
int main(){
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        int m=9;
        string s="";
        while (m!=1)
        {
            if(data%m==0){
                data/=m;
                s=to_string(m)+s;
            }
            else m--;
        }
        if(data!=1)cout<<"-1"<<endl;
        else cout<<s<<endl;
    }
    system("Pause");
    return 0;
}