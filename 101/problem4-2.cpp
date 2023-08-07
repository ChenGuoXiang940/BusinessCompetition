#include<iostream>
#include<sstream>
using namespace std;
int main() {
    int n;
    string s,s1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        int total=0;
        int a=0;
        while(getline(ss,s1,' ')){
            int val=atoi(s1.c_str())%13;
            if(val==0||val==12||val==11)total+=10;
            else if(val==1)a++;
            else total+=val;
        }
        while(a>=1&&total+10+a<21){
            total+=11;
            a--;
        }
        total+=a;
        cout<<(total>21?"F":to_string(total))<<endl;
    }
    cin.get();
    return 0;
}