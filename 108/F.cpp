#include<iostream>
#include<unordered_map>
#include<algorithm>
typedef long long ll;
using namespace std;
int main(){
    int n;
    ll A,B;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A>>B;
        string result=to_string((ll)A/B);
        if(A%B!=0){
            result+=".";
            unordered_map<ll,int>mp;
            ll record=A%B;
            int count=0;
            while(record!=0)
            {
                //如果找到循環小數
                if(mp.find(record)!=mp.end()){
                    result.insert(mp[record],"(");
                    result+=")";
                    break;
                }
                //紀錄小數在字串當前的位置 用於之後查找相同小數
                mp[record]=result.size();
                //數論:1/6=0.16 1*10/6=1 10%6=4 4*10/6=6...
                record*=10;
                result+=to_string(record/B);
                record%=B;
                //紀錄小數點後的小數長度 如果長度大於50則離開
                count++;
                if(count==50){
                    result.insert(result.find('.')+1,"(");
                    result+="...)";
                    break;
                }
            }
        }
        else{
            result+="(0)";
        }
        cout<<result<<endl;
    }
    system("Pause");
    return 0;
}