#include<iostream>
#include<sstream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
int maxPath=0;
int dfs(TreeNode* root){
    if(root==nullptr)return 0;
    int leftd=dfs(root->left);
    int rightd=dfs(root->right);
    maxPath=max(maxPath,leftd+rightd);
    return max(leftd,rightd)+1;
}
int main(){
    int n;
    string s,data;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        s.erase(remove(s.begin(),s.end(),'['),s.end());
        s.erase(remove(s.begin(),s.end(),']'),s.end());
        stringstream ss(s);
        vector<int>num;
        while (getline(ss,data,','))
        {
            if(data=="null")num.push_back(-1);
            else num.push_back(atoi(data.c_str()));
        }      
        TreeNode*root=new TreeNode(num[0]);
        queue<TreeNode*>q;
        q.push(root);
        int j=1;
        while(!q.empty()&&j<num.size())
        {
            TreeNode* current=q.front();
            q.pop();
            if(j<num.size()&&num[j]!=-1){
                current->left=new TreeNode(num[j]);
                q.push(current->left);
            }
            j++;
            if(j<num.size()&&num[j]!=-1){
                current->right=new TreeNode(num[j]);
                q.push(current->right);
            }
            j++;
        }
        maxPath=0;
        dfs(root);
        cout<<maxPath<<endl;
    }
    system("Pause");
    return 0;
}