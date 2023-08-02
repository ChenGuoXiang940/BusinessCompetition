#include<iostream>
#include<sstream>
using namespace std;
char del;
struct Data
{
    int num[4];
    Data(stringstream& ss){
        for(int i=0;i<4;i++){
            ss>>num[i]>>del;
        }
    }
};
void solve(Data* a,Data* b){
    string r="";
    for(int i=0;i<4;i++){
        r+=to_string(a->num[i]&b->num[i])+".";
    }
    r.erase(r.end()-1);
    cout<<r<<endl;
}
int main() {
    int n;
    string s;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        Data*a=new Data(ss);
        Data*b=new Data(ss);
        solve(a,b);
    }
    cin.get();
    return 0;
}