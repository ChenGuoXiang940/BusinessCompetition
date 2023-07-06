#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int main(){
    int n;
    string text;
    cin>>n;
    cin.ignore();
    while (getline(cin,text))
    {
        int a=0,b=0;
        switch (text[0])
        {
            case 'o':
                a++;
                break;
            case 't':
                b++;
                break;
        }
        switch (text[1])
        {
            case 'n':
                a++;
                break;
            case 'o':
                b++;
                break;
        }
        switch (text[2])
        {
            case 'e':
                a++;
                break;
            case 'w':
                b++;
                break;
        }
        cout<<(a>=2&&text.size()==3?"1":b>=2&&text.size()==3?"2":"3")<<endl;
    }
    system("Pause");
    return 0;
}