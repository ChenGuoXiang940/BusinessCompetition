#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int gcd(int a,int b){
    if(a==1)return b;
    else return a%b==0?b:gcd(b,a%b);
}
int main() {
    int n;
    string s,s1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        vector<int>v;
        while(getline(ss,s1,',')){
            v.push_back(atoi(s1.c_str()));
        }
        int r=0;
        for(int m=0;m<v.size();m++){
            for(int n=0;n<m;n++){
                r=max(r,gcd(v[m],v[n]));
            }
        }
        cout<<to_string(r)<<endl;
    }
    cin.get();
    return 0;
}