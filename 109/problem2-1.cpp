#include<iostream>
#include<sstream>
using namespace std;
string s;
char del;
struct Data
{
    int y,m,d;
    Data(){
        getline(cin,s);
        stringstream ss(s);
        ss>>d>>del>>m>>del>>y>>del;
    }
};
int main(){
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        Data a=Data();
        Data b=Data();
        int ans=a.y-b.y;
        if(a.m<b.m)ans-=1;
        else if(a.m==b.m&&a.d<b.d)ans-=1;
        cout<<ans<<endl;
    }
/*
5
01/01/2012 
10/02/2007 
09/06/2007 
28/02/1971 
12/11/2007 
01/01/1984 
28/02/2005 
29/02/2004 
12/11/2020 
01/01/1974 
*/
    system("Pause");
    return 0;
}