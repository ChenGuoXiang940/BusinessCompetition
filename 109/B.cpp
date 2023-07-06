#include<iostream>
using namespace std;
int main(){
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        int a=0,b=0,m=1;
        while (data!=0)
        {
            if(data%10==4){
                a+=m*3;
                b+=m;
            }
            else
            {
                a+=m*(data%10);
            }
            m*=10;
            data/=10;
        }
        cout<<a<<" "<<b<<endl;
    }
    system("Pause");
    return 0;
}