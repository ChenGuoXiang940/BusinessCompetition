#include<iostream>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    int n,len,n2;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>n2>>len;
        unordered_map<int,unordered_map<char,int>>mp;
        for(int j=0;j<n2;j++){
            cin>>s;
            for(int k=0;k<len;k++){
                mp[k][s[k]]++;
            }
        }
        map<int, char> maxkey2map;
        for(const auto& pair1:mp){
            char maxkey2='\0';
            int maxval = 0;
            for(const auto& pair2:pair1.second){
                if(pair2.second>maxval) {
                    maxval=pair2.second;
                    maxkey2=pair2.first;
                }
                else if(pair2.second==maxval&&(int)maxkey2>(int)pair2.first)
                {
                    maxval=pair2.second;
                    maxkey2=pair2.first;
                }         
            }
            //cout<<pair1.first<<" "<<maxkey2<<endl;//unordered_map是無序(順序亂) map有序(按first值小到大)
            maxkey2map[pair1.first]=maxkey2;
        }
        for(const auto& pair:maxkey2map) {
            cout<<pair.second;
        }
        cout<<"\r\n";
    }
    system("Pause");
    return 0;
}