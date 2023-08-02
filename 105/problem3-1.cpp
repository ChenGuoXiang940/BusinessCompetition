#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode*left,*right;
    TreeNode(int xx):val(xx),left(nullptr),right(nullptr){}
};
bool b(TreeNode* root){
    if(!root)return true;
    if(root->left&&root->left->val>=root->val)return false;
    if(root->right&&root->right->val<=root->val)return false;
    return b(root->left)&&b(root->right);
}
bool hmax(TreeNode*root){
    if(!root)return true;
    if(root->left&&root->left->val>=root->val)return false;
    if(root->right&&root->right->val>=root->val)return false;
    return hmax(root->left)&&hmax(root->right);
}

bool hmin(TreeNode*root){
    if(!root)return true;//root==nullptr
    if(root->left&&root->left->val<=root->val)return false;//root!=nullptr
    if(root->right&&root->right->val<=root->val)return false;
    return hmin(root->left)&&hmin(root->right);
}
int main() {
    int n;
    string s,s1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        int len,k=1;
        vector<int>v;
        while(getline(ss,s1,',')){
            v.push_back(atoi(s1.c_str()));
        }
        TreeNode*node=new TreeNode(v[0]);
        queue<TreeNode*>q;
        q.push(node);
        while((len=q.size())!=0){
            for(int j=0;j<len;j++){
                TreeNode* root=q.front();
                q.pop();
                if(k<v.size()){
                    root->left=new TreeNode(v[k++]);
                    q.push(root->left);
                }
                if(k<v.size()){
                    root->right=new TreeNode(v[k++]);
                    q.push(root->right);
                }
            }
        }
        if(hmax(node)||hmin(node))cout<<"H"<<endl;
        else if(b(node))cout<<"B"<<endl;
        else cout<<"F"<<endl;
    }
    cin.get();
    return 0;
}