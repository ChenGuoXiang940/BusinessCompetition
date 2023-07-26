#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
    int n;
    ll x,data;
    cin>>n>>x;
    vector<ll>coins;
    for(int i=0;i<n;i++){
        cin>>data;
        coins.push_back(data);
    }
    /*動態規劃*/
    //時間複雜度是O(n*x)
    //加總要為x的組合就是要找0~x的所有組合!
    vector<int>dp(x+1,0);
    //基本情況：目標金額為0時，只有一種硬幣組合方式（都不選）
    dp[0]=1;
    for(ll coin:coins){
        for(ll i=coin;i<=x;i++){
            dp[i]+=dp[i-coin];
        }
    }
    cout<<dp[x];
    cin.get();
    return 0;
}