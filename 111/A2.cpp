#include <iostream>
using namespace std;
int main() {
    int a;
    while(cin>>a){
        if(a==0)break;
        else if(a%400==0)cout<<"a leap year\r\n";
        else if(a%100==0)cout<<"a normal year\r\n";
        else if(a%4==0)cout<<"a leap year\r\n";
        else cout<<"a normal year\r\n";
    }
    cin.get();
    return 0;
}