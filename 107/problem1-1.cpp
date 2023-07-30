#include<iostream>
#include<sstream>
using namespace std;
#define fo(b) for(int i=0;i<b;i++)
int main(){
    int n;
    string data;
    string s;
    cin>>n;
    cin.ignore();
    fo(n){
        getline(cin,s);
        stringstream ss(s);
        int word=0;
        int number=0;
        while(getline(ss,data,' '))
        {
            if(data.find("S")!=string::npos||data.find("s")!=string::npos)number++;
            word++;
        }
        cout<<word<<","<<number<<endl;
    }
    system("Pause");
    return 0;
}