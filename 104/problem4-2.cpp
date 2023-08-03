#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class edge
{
    public:
    char u,v;
    int w;
    edge(char xx,char yy,int zz):u(xx),v(yy),w(zz){}
};
bool cmp(const edge* a,const edge* b){
    return a->w<b->w;
}
int main() {
    int n,w;
    char u,v,del;
    string s,s1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        vector<edge*>path;
        while(getline(ss,s1,' ')){
            stringstream ss1(s1);
            ss1>>u>>del>>v>>del>>w;
            path.emplace_back(new edge(u,v,w));
        }
        sort(path.begin(),path.end(),cmp);
        unordered_set<int>st;
        int cost=0;
        for(const edge* item:path){
            if(st.find(item->u)!=st.end()&&st.find(item->v)!=st.end())continue;
            cost+=item->w;
            st.insert(item->u);
            st.insert(item->v);
        }
        cout<<cost<<endl;
    }
    cin.get();
    return 0;
}