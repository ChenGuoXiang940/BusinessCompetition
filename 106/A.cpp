#include<iostream>
#include<sstream>
using namespace std;
bool f(string&s){
    for(const char&item:s){
        if(item=='S'||item=='s')return true;
    }
    return false;
}
int main() {
    int n;
    string s,data;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        int total=0;
        while(getline(ss,data,' ')){
            if(f(data))total++;
        }
        cout<<total<<endl;
    }
    cin.get();
    return 0;
}