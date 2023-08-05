#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
    unordered_map<string,char>mp={{"00",'0'},{"01",'1'},{"100",'2'},{"101",'3'},
    {"1100",'4'},{"1101",'5'},{"11100",'6'},{"11101",'7'},{"111100",'8'},{"111101",'9'}};
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        string s1="",s2="";
        for(const char item:s){
            s1+=item;
            if(mp.count(s1)){
                s2+=mp[s1];
                s1="";
            }
        }
        int r=atoi(s2.c_str());
        if(r>=24)cout<<(char)('A'+r-24)<<endl;
        else cout<<(char)('D'+r-1)<<endl;
    }
    cin.get();
    return 0;
}