#include<iostream>
#include<sstream>
#include<vector>
#include<bitset>
#include<unordered_map>
using namespace std;
unordered_map<char,string>hexToBinaryMap={{'0', "0000"},{'1', "0001"},{'2', "0010"},
{'3', "0011"},{'4', "0100"},{'5', "0101"},{'6', "0110"},{'7', "0111"},{'8', "1000"},
{'9', "1001"},{'A', "1010"},{'a', "1010"},{'B', "1011"},{'b', "1011"},{'C', "1100"},
{'c', "1100"},{'D', "1101"},{'d', "1101"},{'E', "1110"},{'e', "1110"},
{'F', "1111"},{'f', "1111"}
};
string decimalToBinary(int decimal){
    bitset<5>bit(decimal);
    string r=bit.to_string();
    string buffer(5-r.size(),'0');
    return buffer+r;
}
int main() {
    int num[]={1,2,4,8,16};
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        string s1="";
        for(int j=0;j<4;j++){
            s1+=hexToBinaryMap[s[j]];
        }
        int index=0;
        vector<string>v;
        for(int j=1;j<=21;j++){
            if(num[index]==j){
                index++;
                continue;
            }
            if(s1[j-index-1]=='1'){
                v.push_back(decimalToBinary(j));
            }
        }
        int rd[5]={0};
        for(int j=0;j<v.size();j++){
            for(int k=0;k<5;k++){
                rd[k]+=v[j][k]=='1'?1:0;
            }
        }
        string r="";
        for(int j=0;j<5;j++){
            r=(rd[j]%2==0?'0':'1')+r;
        }
        cout<<r<<"\n";
    }
    cin.get();
    return 0;
}