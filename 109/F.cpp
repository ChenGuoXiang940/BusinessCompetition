#include<iostream>
#include<sstream>
#include<vector>
typedef long long int ll;
using namespace std;
int main(){
    int n;
    string data,s;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<ll>v;
        v.push_back(0);
        getline(cin,s);
        stringstream ss(s);
        ll sum=0;
        while (getline(ss,data,' '))
        {
            sum+=(ll)stoi(data);
            v.push_back(sum);
        }
        ll total=-65535;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                total=(total>v[j]-v[i])?total:v[j]-v[i];
            }
        }
        cout<<total<<endl;
    }
    system("Pause");
    return 0;
}