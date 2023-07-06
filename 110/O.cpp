#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int maxComSubSeqLen(const string& word1, const string& word2, const string& word3){
    int len1=word1.length();
    int len2=word2.length();
    int len3=word3.length();
    vector<vector<vector<int>>>dp(len1+1,vector<vector<int>>(len2+1,vector<int>(len3+1,0)));
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            for(int k=1;k<=len3;k++){
                if(word1[i-1]==word2[j-1]&&word1[i-1]==word3[k-1]){
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                }
                else{
                    dp[i][j][k]=max({dp[i - 1][j][k],dp[i][j - 1][k],dp[i][j][k - 1]});
                }
            }
        }
    }
    return dp[len1][len2][len3];
}
int main(){
    string word1,word2,word3;
    cin>>word1;
    cin>>word2;
    cin>>word3;
    cout<<maxComSubSeqLen(word1, word2,word3)<<endl;
    system("Pause");
    return 0;
}