#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main() {
    unordered_map<string,string>mp={{"-----","0"},{".----","1"},
    {"..---","2"},{"...--","3"},{"....-","4"},{".....","5"},{"-....","6"},
    {"--...","7"},{"---..","8"},{"----.","9"}};
    int n;
    string s;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        s.erase(std::remove(s.begin(), s.end(),' '), s.end());
        string r="",s1="";
        for(const char item:s){
            s1+=item;
            if(mp.count(s1)>0){
                r+=mp[s1];
                s1="";
            }
        }
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}