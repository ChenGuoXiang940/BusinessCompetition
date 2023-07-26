#include <iostream>
#include<map>
using namespace std;
int main() {
    int n,data;
    cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>data;
        mp[data]++;
    }
    for(const auto&item:mp){
        cout<<item.first<<" "<<item.second<<endl;
    }
    cin.get();
    return 0;
}