#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int result=0;
void f(int amount,const vector<int>&coins,vector<int>&current){
    if(amount==0){
        result++;
        return;
    }
    for(int coin:coins){
        if(coin<=amount){
            current.push_back(coin);
            f(amount-coin,coins,current);
            current.pop_back();
        }
    }
}
int main() {
    int n;
    ll x,data;
    cin>>n>>x;
    vector<int>coins;
    for(int i=0;i<n;i++){
        cin>>data;
        coins.push_back(data);
    }
    vector<int>current;
    f(x,coins,current);
    cout<<result<<endl;
    cin.get();
    return 0;
}