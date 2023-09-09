#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int nums[n];
    int amount=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        amount+=nums[i];
    }
    int dp[amount+1]={0};
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=amount;j>=nums[i];j--){
            dp[j]+=dp[j-nums[i]];
        }
    }
    int r=0;
    string s="";
    for(int i=1;i<=amount;i++){
        if(dp[i]){
            r++;
            s+=to_string(i)+" ";
        }
    }
    cout<<r<<endl<<s;
    return 0;
}