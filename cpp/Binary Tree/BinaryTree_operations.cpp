#include<iostream>
#include<queue>
using namespace std;
template<typename T>

class BTNode
{
public:
    T data;
    BTNode *left;
    BTNode *right;

    BTNode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~BTNode()
    {
        delete left;
        delete right;
    }
};

BTNode<int>* takeInputLevelwise()
{
    int rootData;
    cout<<"Enter Rootdata :";
    cin>>rootData;
    BTNode<int>* root= new BTNode<int>(rootData);

    queue<BTNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        BTNode<int>* f= q.front();
        q.pop();

        int leftChildData;
        cout<<"Enter left child of "<<f->data;
        cin>>leftChildData;
        if(leftChildData!=-1)
        {
            BTNode<int>* leftChild= new BTNode<int>(leftChildData);
            q.push(leftChild);
            f->left=leftChild;
        }
        int rightChildData;
        cout<<"Enter right child of "<<f->data;
        cin>>rightChildData;
        if(rightChildData!=-1)
        {
            BTNode<int>* rightChild= new BTNode<int>(rightChildData);
            q.push(rightChild);
            f->right=rightChild;
        }


    }

    return root;

}

BTNode<int>* takeInputRecursive()
{
    int rootData;
    cin>>rootData;
    if(rootData==-1)
    {
        return NULL;
    }

    BTNode<int>* root= new BTNode<int>(rootData);
    BTNode<int>* leftchild= takeInputRecursive();
    BTNode<int>* rightchild= takeInputRecursive();

    root->left=leftchild;
    root->right=rightchild;

    return root;

}
void printRecursive(BTNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" :";
    if(root->left!=NULL)
    {
        cout<<"L->"<<root->left->data<<" ";
    }
    if(root->right!=NULL)
    {
        cout<<"R->"<<root->right->data;
    }
    cout<<endl;
    printRecursive(root->left);
    printRecursive(root->right);

}
void printLevelWise(BTNode<int>* root)
{
    cout<<root->data<<endl;
    queue<BTNode<int>*>q;
    q.push(root);
    q.push(NULL);





    while(!q.empty())
    {
         BTNode<int>* f= q.front();
                 q.pop();
        if(f==NULL)
        {


            cout<<endl;
            if(!q.empty())
            {
                 q.push(NULL);
            }

        }



        else
        {


            if(f->left)
            {
                q.push(f->left);
                cout<<f->left->data<<" ";
            }
            if(f->right)
            {
                q.push(f->right);
                cout<<f->right->data<<" ";
            }

        }

    }
}

int countNodes(BTNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }

      return countNodes(root->left)+countNodes(root->right)+1;


}
int minVlaue(BTNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int ans= root->data;

    return min(ans,  minVlaue(root->left),minVlaue(root->right));



}

int main()
{
    BTNode<int>* root=takeInputRecursive();
    printLevelWise(root);
    int ans=countNodes(root);
    cout<<"Total nodes are "<<ans;
     cout<<endl;
cout<<"minimum val node is :"<<minVlaue(root);

}

//1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
