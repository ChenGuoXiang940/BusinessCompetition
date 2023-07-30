#include<iostream>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s;
        int sum=0,m=1;
        for(const char&item:s){
            switch (item)
            {
            case 'O':
                sum+=m;
                m++;
                break;
            case 'X':
                m=1;
                break;;
            default:        
                break;
            }
        }
        cout<<sum<<endl;
    }
    system("Pause");
    return 0;
}