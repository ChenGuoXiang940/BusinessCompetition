#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
string mult(string a,string b){
    int n1=a.size();
    int n2=b.size();
    string result(n1+n2,'0');
    for(int i=n1-1;i>=0;i--){
        int cy=0;
        for(int j=n2-1;j>=0;j--){
            int sum=(a[i]-'0')*(b[j]-'0')+(result[i+j+1]-'0')+cy;
            cy=sum/10;
            result[i+j+1]=(sum%10)+'0';
        }
        result[i]+=cy;
    }
    size_t pos=result.find_first_not_of('0');
    if(pos!=string::npos)return result.substr(pos);
    return "0";
}
string fastpow(string a,int b){
    if(b==0)return "1";
    string result="1";
    while(b!=0)
    {
        if((b&1)==1)result=mult(result,a);
        a=mult(a,a);
        b>>=1;
    }
    return result;
}
int main(){
    int a,b,n;
    string s;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        replace(s.begin(),s.end(),',',' ');
        stringstream ss(s);
        ss>>a>>b;
        string ans=fastpow(to_string(a),b);
        cout<<ans.size()<<endl;
    }
    system("Pause");
    return 0;
}