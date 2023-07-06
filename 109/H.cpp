#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long int ll;
int main(){
    int n,n2,u,v;
    cin>>n;
    while (n--)
    {
        cin>>n2;
        unordered_map<ll,ll>mp;
        while (n2--)
        {
            cin>>u>>v;
            mp[u]=v;
        }       
        int result=0;
        int record=-1;
        for(const auto &item:mp){
            ll current=item.second;
            int count=1;
            unordered_map<int,bool>visited(false);
            visited[item.first]=true;
            while(visited[current]!=true)
            {
                visited[current]=true;
                current=mp[current];
                count++;
            }
            if((result<count)||(result==count&&record>item.first)){
                result=count;
                record=item.first;
            }
        }
        cout<<record<<endl;
    }
    system("Pause");
    return 0;
}