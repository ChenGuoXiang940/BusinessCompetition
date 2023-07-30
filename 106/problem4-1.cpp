#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<algorithm>
#include<set>
using namespace std;
unordered_map<int,vector<int>>mp;
set<int>st;
set<string>result;
void dfs(int index,vector<int>record){
    for(const int& item:mp[index]){
        auto it=find(record.begin(),record.end(),item);
        if(it!=record.end()){
            if(next(it)==prev(record.end()))continue;
            size_t aim=distance(record.begin(),it);
            vector<int>buffer;
            copy(record.begin()+aim,record.end(),back_inserter(buffer));
            sort(buffer.begin(),buffer.end());
            string str="";
            for(const int&item2:buffer){
                str+=to_string(item2)+",";
            }
            str.erase(str.end()-1);
            result.insert(str);
            return;
        }
        else{
            record.push_back(item);
            st.insert(item);
            dfs(item,record);
            record.pop_back();
        }
    }    
}
int main() {
    int n,a,b;
    char del;
    string s,s1;
    vector<int>record;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        mp.clear();
        st.clear();
        record.clear();
        result.clear();
        while(getline(ss,s1,' ')){
            stringstream ss1(s1);
            ss1>>a>>del>>b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        st.insert(a);
        record.push_back(a);
        dfs(a,record);
        if(result.size()!=0){
            for(const string&item:result){
                cout<<item<<endl;
            }
            continue;
        }
        bool check=false;
        for(const auto&item:mp){
            if(st.count(item.first)==0){
                check=true;
                break;
            }
        }
        if(check)cout<<"F"<<endl;
        else cout<<"T"<<endl;
    }
/*
4
5,8 5,3 5,2 5,4 5,6 1,2 2,0
8,1 1,3 6,2 8,10 7,5 1,4 7,8 8,6 8,0
3,8 6,8 6,4 0,6 8,2 2,0 5,3
1,0 4,3 1,2

5
1,2 2,3 4,0
4,3 2,3 2,1 1,0
1,2 2,3 3,4 1,4 1,5
1,2 1,3 2,3
1,2 2,3 3,4 1,5 5,4
*/
    cin.get();
    return 0;
}