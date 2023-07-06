#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v;
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        v.push_back(data);
    }
    sort(v.begin(),v.end());
    int total=0,sum=0;
    if(n>=1)sum=v[0];
    if(n>=2){
        for(int i=1;i<n;i++){
            sum+=v[i];
            total+=sum;
        }
    }   
    cout<<total;
    system("Pause");
    return 0;
}