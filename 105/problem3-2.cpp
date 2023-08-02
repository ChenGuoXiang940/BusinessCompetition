#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode*left,*right;
    TreeNode(int xx):val(xx),left(nullptr),right(nullptr){}
};
TreeNode*create(const vector<int>&pre,int pref,int pres,const vector<int>&in,int inf,int ins){
    if(pref>pres||inf>ins)return nullptr;
    TreeNode*root=new TreeNode(pre[pref]);
    int index=inf;
    while(index<=ins&&in[index]!=root->val){
        index++;
    }
    root->left=create(pre,pref+1,pref+index-inf,in,inf,index-1);
    root->right=create(pre,pref+index-inf+1,pres,in,index+1,ins);
    return root;
}
string r;
void post(TreeNode*root){
    if(!root)return;
    post(root->left);
    post(root->right);
    r+=to_string(root->val)+",";
}
string s,s1;
vector<int>create2(){
    vector<int>v;
    getline(cin,s);
    stringstream ss(s);
    while(getline(ss,s1,',')){
        v.push_back(atoi(s1.c_str()));
    }
    return v;
}
int main() {
    int n;
    string pre,in;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        vector<int>in=create2();
        vector<int>pre=create2();
        TreeNode*node=create(pre,0,pre.size()-1,in,0,in.size()-1);
        r="";
        post(node);
        r.erase(r.end()-1);
        cout<<r<<endl;
    }
    cin.get();
    return 0;
}