#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
struct Node
{
    int name;
    int val;
    Node*left,*right;
    Node(int ss,int xx):name(ss),val(xx),left(nullptr),right(nullptr){}
};
struct cmp
{
    bool operator()(Node*a,Node*b){
        return a->val>b->val;
    }
};
Node*create(vector<int>v){
    priority_queue<Node*,vector<Node*>,cmp>pq;
    for(int item:v){
        pq.push(new Node(item,item));
    }
    while(pq.size()>1){
        Node*l=pq.top();
        pq.pop();
        Node*r=pq.top();
        pq.pop();
        Node*root=new Node(-1,l->val+r->val);
        root->left=l;
        root->right=r;
        pq.push(root);
    }
    return pq.top();
}
unordered_map<int,int>mp;
void go(Node* root,int total){
    if(!root)return;
    if(root->name!=-1)mp[root->name]=total;
    go(root->left,total+1);
    go(root->right,total+1);
}
int main() {
    int n;
    string s,s1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        vector<int>v;
        while(getline(ss,s1,',')){
            v.push_back(atoi(s1.c_str()));
        }
        Node*node=create(v);
        mp.clear();
        go(node,0);
        string r="";
        for(const int item:v){
            r+=to_string(mp[item])+",";
        }
        r.erase(r.end()-1);
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}