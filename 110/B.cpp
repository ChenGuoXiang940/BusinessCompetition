#include<iostream>
using namespace std;
int main(){
    int n,a;
    cin>>n;
    while(n--!=0){
        cin>>a;
        if(a%4!=0)cout<<"a normal year\r\n";
        else if(a%100!=0)cout<<"a leap year\r\n";
        else if(a%400!=0)cout<<"a normal year\r\n";
        else cout<<"a leap year\r\n";
    }
    system("pause");
    return 0;
}