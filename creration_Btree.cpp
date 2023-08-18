#include<iostream>
#include<queue>
using namespace std;
class node
{
    public:
        int data;
        node*left;
        node*right;
    node(int d)
        {
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }

};
// building a tree
node*Buildertree(node*root)
{
    cout<<"Entre the data:"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)
    {
        return NULL;
    }
    cout<<"Entre the data for left "<<endl;
    root->left=Buildertree(root->left);
    cout<<"Entre the data for right "<<endl;
    root->right=Buildertree(root->right);
    return root;
}

// level order tree
void levelorder(node*root)
{
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node*temp=q.front();
        cout<<temp->data<<endl;
        q.pop();
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
}
// inorder-traversal
void inorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);

}

// preorder

void preorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);

}

// post order

void postorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<endl;
    postorder(root->right);
    postorder(root->left);

}
int main()
{
    node*root=NULL;
    root=Buildertree(root);
    // level-order
    levelorder(root);
    preorder(root);
    postorder(root);
    return 0;
}