#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main() {
    unordered_map<string,char>mp={{"00",'A'},{"01",'B'},{"100",'0'},{"101",'1'},
    {"1100",'2'},{"1101",'3'},{"11100",'4'},{"11101",'5'},{"111100",'6'},{"111101",'7'},
    {"111110",'8'},{"111111",'9'}};
    int n;
    string s,s1,r;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        s1="";
        r="";
        for(char it:s){
            s1+=it;
            if(mp.find(s1)!=mp.end()){
                r+=mp[s1];
                s1="";
            }
        }
        r.insert(4,",");
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}