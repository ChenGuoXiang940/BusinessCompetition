#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n,data;
    cin>>n;
    vector<int>v;
    vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        cin>>data;
        v.push_back(data);
    }
    /*動態規劃DP*/
    //假設如果a>b a=dp[i](用來記錄b在前面所比較而得的個數)+1(b算一個)
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i]>v[j])dp[i]=max(dp[i],dp[j]+1);
            cout<<dp[i]<<" ";
        }
        cout<<"\n";
    }
    int result=0;
    for(int item:dp){
        result=max(result,item);
    }
    cout<<result<<endl;
    cin.get();
    return 0;
}