#include <bits/stdc++.h>
using namespace std;

class BST{
    int data;
    BST *left,*right;
    
    public:
        BST();
        BST(int);
        BST* insert(BST*,int);
        void preorder(BST*);
        void inorder(BST*);
        void postorder(BST*);
};

BST::BST(){
    data=0;
    left=right=NULL;
}

BST::BST(int value){
    data=value;
    left=right=NULL;
}

BST* BST::insert(BST* root, int value){
    if(!root){
        return new BST(value);
    }
    if(value>root->data){
        root->right=insert(root->right,value);
    }
    else if(value<root->data){
        root->left=insert(root->left,value);
    }
    return root;
}

void BST::preorder(BST* root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void BST::inorder(BST* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void BST::postorder(BST* root){
    if(!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n,num;
    cin>>n;
    BST b,*root=NULL;
    for(int i=0;i<n;i++){
        cin>>num;
        if(i==0){
            root=b.insert(root,num);
            continue;
        }
        b.insert(root,num);
    }
    b.preorder(root);
    cout<<endl;
    b.inorder(root);
    cout<<endl;
    b.postorder(root);
    cout<<endl;
    return 0;
}