#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_set>
#include<unordered_map>
using namespace std;
typedef pair<bool,vector<int>> pr;
void dfs(int index,unordered_map<int,pr>&mp){
    mp[index].first=true;
    for(const auto it:mp[index].second){
        if(!mp[it].first)dfs(it,mp);
    }
}
bool check(int index,unordered_map<int,pr>&mp){
    dfs(index,mp);
    for(const auto it:mp){
        if(!it.second.first)return false;//如果有沒被走訪的點代表不是樹
    }
    return true;
}
int main() {
    /*無向圖的2個整數A-B或B-A(題目1<=A、B<=60)因為A!=B可以自己假設A>B所以A*100+B不會有重複情形*/
    /*樹的條件：任意點可以走遍且不會轉圈圈*/
    int n,n1,a,b;
    string s,s1;
    char del;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>n1;
        cin.ignore();
        unordered_set<int>st; //紀錄A*100+B
        unordered_set<int>st1;//紀錄內部節點
        bool fg=true;
        for(int j=0;j<n1;j++){
            unordered_map<int,pr>mp;//紀錄邊的連接關係
            getline(cin,s);
            stringstream ss(s);
            while(getline(ss,s1,' ')){
                stringstream ss1(s1);
                ss1>>a>>del>>b;
                int val=(a>b?a*100+b:b*100+a);
                if(st.find(val)!=st.end())fg=false;
                mp[a].second.push_back(b);
                mp[b].second.push_back(a);
                mp[a].first=mp[b].first=false;
                st.insert(val);
            }
            if(!fg||!check(a,mp)){
                fg=false;
                continue;
            }
            for(const auto it:mp){
                if(it.second.second.size()!=1){
                    if(st1.find(it.first)!=st1.end()){
                        fg=false;
                        break;
                    }
                    st1.insert(it.first);
                }
            }
        }     
        cout<<(fg?"T":"F")<<endl;
    }
    cin.get();
    return 0;
}