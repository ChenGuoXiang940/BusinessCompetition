#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int minEditDistance(const string& word1, const string& word2) {
    int m=word1.length();
    int n=word2.length();
    // 建立一個二維陣列來儲存最小編輯距離
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    // 初始化第一列和第一行
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=n;j++){
        dp[0][j]=j;
    }
    // 填充其餘的格子
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];//字母相同，不需要操作
            }else {
                dp[i][j]=min({dp[i-1][j-1],// 替換
                                dp[i][j-1],    // 插入
                                dp[i-1][j]});  // 刪除
                dp[i][j]+=1;//執行一次操作
            }
        }
    }
    return dp[m][n];//返回最小編輯距離
}
int main () 
{
    string word1, word2;
    cin>>word1;
    cin>>word2;
    cout<< minEditDistance(word1, word2) << endl;
    system("Pause");
    return 0;
}