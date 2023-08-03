#include<iostream>
#include<sstream>
using namespace std;
struct Node
{
    int val;
    Node*left,*right;
    Node(int xx):val(xx),left(nullptr),right(nullptr){}
};
class BST
{
    private:
    Node*node;
    string s;
    Node* create(Node*root,int val){
        if(!root)return new Node(val);
        /*左子樹的鍵值均要小於樹根的鍵值*/
        if(val<root->val)root->left=create(root->left,val);
        /*右子樹的鍵值均要大於樹根的鍵值*/
        if(val>root->val)root->right=create(root->right,val);
        /*值=根*/
        return root;
    }
    void post(Node*root){
        if(!root)return;
        post(root->left);
        post(root->right);
        s+=to_string(root->val)+",";
    }
    public:
    BST():node(nullptr){}
    void insert(int val){
        node=create(node,val);
    }
    string go(){
        s="";
        post(node);
        s.erase(s.end()-1);
        return s;
    }
};

int main() {
    int n,n1,a;
    string s;
    char del;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>n1;
        cin.ignore();
        getline(cin,s);
        stringstream ss(s);
        BST*root=new BST();
        for(int j=0;j<n1;j++){
            ss>>a>>del;
            root->insert(a);
        }
        cout<<root->go()<<endl;
    }
    cin.get();
    return 0;
}