#include<iostream>
#include<bitset>
using namespace std;
int main() {
    int n;
    string s,s1,s2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        string buffer(4-s.size()%4,'0');
        s1=buffer.size()==4?s:buffer+s;
        string h="",o="";
        for(int j=s1.size();j>0;j-=4){
            bitset<4>binary(s1.substr(j-4,4));
            int decimal=static_cast<int>(binary.to_ulong());
            if(decimal>=10&&decimal<=15){
                h=(char)(decimal-10+'A')+h;
            }
            else{
                h=(char)(decimal^48)+h;
            }
        }
        string buffer1(3-s.size()%3,'0');
        s2=buffer1.size()==3?s:buffer1+s;
        for(int j=s2.size();j>0;j-=3){
            bitset<3>binary(s2.substr(j-3,3));
            int decimal=static_cast<int>(binary.to_ulong());
            o=(char)(decimal^48)+o;
        }
        cout<<h<<","<<o<<endl;
    }
    cin.get();
    return 0;
}