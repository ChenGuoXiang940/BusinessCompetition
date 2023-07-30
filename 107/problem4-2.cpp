#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
struct Data
{
    int val;
    bool fg=false;
};
int main(){
    int n;
    string s,data;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        s.erase(remove(s.begin(),s.end(),'['),s.end());
        s.erase(remove(s.begin(),s.end(),']'),s.end());
        vector<int>v1;
        stringstream ss(s);
        while(getline(ss,data,','))
        {
            v1.push_back(atoi(data.c_str()));
        }
        vector<int>v2(v1.size());
        copy(v1.begin(),v1.end(),v2.begin());
        sort(v1.begin(),v1.end());
        unordered_map<int,Data>mp;
        for(int j=0;j<v2.size();j++){
            mp[v1[j]].val=v2[j];
        }
        string text="[";
        for(int j=0;j<v2.size();j++){
            if(!mp[v1[j]].fg){       
                if(v1[j]==v2[j]){
                    text+="["+to_string(v1[j])+"],";
                    mp[v1[j]].fg=true;
                    continue;
                }        
                int head=v1[j];
                string str=to_string(head)+",";
                int current=mp[v1[j]].val;
                while (head!=current)
                {
                    str+=to_string(current)+",";
                    mp[current].fg=true;
                    current=mp[current].val;
                }
                str.erase(str.size()-1,1);
                text+="["+str+"],";
            }
        }
        text.erase(text.size()-1,1);
        cout<<text<<"]"<<endl;
    }
    system("Pause");
    return 0;
}