#include <iostream>
using namespace std;
int main() {
    int a,b;
    while(cin>>a>>b)
    {
        if(a<b){
            cout<<b-a<<endl;
        }
        else{
            cout<<200-a+b<<endl;
        }
    }
    cin.get();
    return 0;
}