#include<iostream>
using namespace std;
int main(){
    int n,y1,y2,m1,m2,d1,d2;
    string data;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        d1=stoi(data.substr(0,2));
        m1=stoi(data.substr(3,2));
        y1=stoi(data.substr(6,4));
        cin>>data;
        d2=stoi(data.substr(0,2));
        m2=stoi(data.substr(3,2));
        y2=stoi(data.substr(6,4));
        int ans=y1-y2;
        if(m1<m2){
            ans-=1;
        }
        else if (m1==m2&&d1<d2)
        {
            ans-=1;
        }
        cout<<ans<<endl;
    }
    system("Pause");
    return 0;
}