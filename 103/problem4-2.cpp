#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    char del;
    string s;
    int n,m,v,k,m1,v1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        ss>>m>>del>>v>>del>>k;
        unordered_map<int,vector<int>>mp;
        for(int j=0;j<m;j++){
            vector<int>col;
            getline(cin,s);
            stringstream ss1(s);
            ss1>>m1;
            for(int l=0;l<v;l++){
                ss1>>v1;
                col.push_back(v1);
            }
            mp.insert({m1,col});
        }
        string s2="";
        for(int j=0;j<v;j++){
            int r=0;
            int k1=k;
            while(mp[k1][j]!=999){
                r++;
                k1=mp[k1][j];
            }
            s2+=to_string(r)+",";
        }
        s2.erase(s2.end()-1);
        cout<<s2<<endl;
    }
    cin.get();
    return 0;
}