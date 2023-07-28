#include<iostream>
#include<set>
using namespace std;
int main() {
    int n,data;
    cin>>n;
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>data;
        s.insert(data);
    }
    for(const int& item:s){
        cout<<item<<endl;
    }
    cin.get();
    return 0;
}