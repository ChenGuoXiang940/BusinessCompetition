#include<iostream>
#include<algorithm>
#include<sstream>
#include<map>
#include<vector>
using namespace std;
int main() {
    int n,n1;
    string s,s1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>n1;
        cin.ignore();
        map<string,int>mp;
        for(int j=0;j<n1;j++){
            getline(cin,s);
            auto newEnd=remove(s.begin(),s.end(),' ');
            s.erase(newEnd,s.end());
            stringstream ss(s);
            while(getline(ss,s1,',')){
                mp[s1]++;
            }
        }
        int record=-1;
        string r="";
        vector<pair<string,int>>st(mp.begin(),mp.end());
        sort(st.begin(),st.end(),[](auto a,auto b) {return a.second > b.second;});//second從大到小
        for(const auto& it:st){
            if(record!=-1&&it.second!=record)break;
            r+=it.first+",";
            record=it.second;
        }
        r.erase(r.end()-1);
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}