#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int>coins(N);
    for(int i=0;i<N;i++){
        cin>>coins[i];
    }
    //set容器儲存不重複的數字
    set<int>sums;
    sums.insert(0);
    for (int coin:coins) {
        set<int>tempSums=sums;//複製目前的總和集合
        for (int sum:tempSums) {
            sums.insert(sum+coin); //將新的總和加入集合
        }
    }
    sums.erase(0);
    cout<<sums.size()<<endl;
    for (int sum:sums) {
        cout << sum << " ";
    }
    system("Pause");
    //1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
    return 0;
}