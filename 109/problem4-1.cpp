#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    string data,s;
    int val;
    while (getline(cin,s))
    {
        vector<int>v;
        stringstream ss(s);
        while (getline(ss,data,' '))
        {
            val=atoi(data.c_str());
            if(find(v.begin(),v.end(),val)==v.end()){
                v.push_back(val);
            }
        }
        int stand=v[0];
        v.erase(v.begin());
        int n=v.size();
        vector<int>dp(stand+1,-1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=stand;j>=v[i];j--){
                if(dp[j-v[i]]!=-1)dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
            }
        }
        int result=-1;
        for (int j=stand;j>=0;j--){
            if (dp[j]!=-1) {
                result=dp[j];
                break;
            }
        }
        cout<<result<<endl;
    }
    system("Pause");
    return 0;
}