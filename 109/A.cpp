#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n;
    string str,data;
    cin>>n;
    for(int i=0;i<n;i++){
        getline(cin,str);
        stringstream ss(str);
        vector<int>v;
        while (getline(ss,data,' '))
        {
            v.push_back(atoi(data.c_str()));
        }
        sort(v.begin(),v.end(),cmp);
        cout<<v[0]<<" "<<v[1]<<endl;
    }
    system("Pause");
    return 0;
}