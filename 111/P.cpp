#include<iostream>
using namespace std;
struct TreeNode
{
    char val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(char xx):val(xx),left(nullptr),right(nullptr){}
};
TreeNode*create(const string&pre,int pref,int pres,const string&in,int inf,int ins){
    if(pref>pres||inf>ins)return nullptr;
    TreeNode* root=new TreeNode(pre[pref]);
    int index=inf;
    while(index<=ins&&in[index]!=root->val){
        index++;
    }
    root->left=create(pre,pref+1,pref+index-inf,in,inf,index-1);
    root->right=create(pre,pref+index-inf+1,pres,in,index+1,ins);
    return root;
}
void post(TreeNode*root){
    if(root==nullptr)return;
    post(root->left);
    post(root->right);
    cout<<root->val;
}
int main() {
    string a,b;
    while(cin>>a>>b){
        TreeNode*node=create(a,0,a.size()-1,b,0,b.size()-1);
        post(node);
    }
    cin.get();
    return 0;
}