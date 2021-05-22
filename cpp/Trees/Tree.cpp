#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data)
    {
        this->data=data;
    }

    ~TreeNode()
    {
        for(int i=0;i<children.size();i++)
        {
            delete(children[i]);
        }
    }
};

TreeNode<int>*  takeInput()
{
    int rootData;
    cout<<"Enter Data";
    cin>>rootData;

    TreeNode<int>* root= new TreeNode<int>(rootData);

    int n;
    cout<<"Enter number of children for  "<<rootData;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        TreeNode<int>* child=  takeInput();;

        root->children.push_back(child);

    }

    return root;
}


TreeNode<int>*  takeInputLevelwise()
{
    int rootData;
    cout<<"Enter Data";
    cin>>rootData;

    TreeNode<int>* root= new TreeNode<int>(rootData);
    queue <TreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode<int>* f= q.front();
        q.pop();
        int n;
        cout<<"Enter number of children for  "<<f->data;
        cin>>n;


        for(int i=1; i<=n; i++)
        {
            int childData;
            cout<<"Enter " <<i<<"th "<< "children of "<<f->data;
            cin>>childData;
            TreeNode<int>* child= new TreeNode<int>(childData);
            q.push(child);
            f->children.push_back(child);

        }



    }


    return root;
}



void printTree(TreeNode<int>* root)
{
    cout<<root->data<<": ";

    for(int i=0; i<root->children.size(); i++)
    {
        cout<<root->children[i]->data<<',';
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++)
    {
        printTree(root->children[i]);
    }


}


void printTreeLevelwise(TreeNode<int>* root)
{
    queue <TreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode<int>* f= q.front();
        q.pop();

        cout<<f->data<<": ";

        for(int i=0; i<f->children.size(); i++)
        {

           cout<<f->children[i]->data<<",";

        }
        cout<<endl;

         for(int i=0; i<f->children.size(); i++)
        {

           q.push(f->children[i]);

        }



    }



}

int countNodes(TreeNode<int>* root)
{
    int count=0;
    queue <TreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode<int>* f= q.front();
        q.pop();

       count++;

      cout<<endl;

         for(int i=0; i<f->children.size(); i++)
        {

           q.push(f->children[i]);

        }
}

return count;

}

int countNoderecursive(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=countNoderecursive(root->children[i]);
    }
    return ans;
}

int height(TreeNode<int>* root)
{
    int mx=0;
    if(root==NULL)
    {
        return 0;
    }

    for(int i=0;i<root->children.size();i++)
    {
        mx= max(mx, height(root->children[i]));
    }
    return mx+1;
}

void depthNodes(TreeNode<int>* root, int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
    }
    for(int i=0;i<root->children.size();i++)
    {
        depthNodes(root->children[i], k-1);
    }
}

int countLeafNodes1(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }

    if(root->children.size()==0)
    {
        return 1;
    }

    int ans=0;
    for(int i=0;i<root->children.size();i++)
    {
        ans+= countLeafNodes1(root->children[i]);
    }
    return ans;

}

void countLeafNodes(TreeNode<int>* root, int &ans)
{

    if(root==NULL)
    {
        return;
    }

    if(root->children.size()==0)
    {
        ans++;
    }


    for(int i=0;i<root->children.size();i++)
    {
    countLeafNodes(root->children[i],ans);
    }


}

void preorder(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    for(int i=0;i<root->children.size();i++)
    {
        postorder(root->children[i]);
    }

     cout<<root->data<<" ";
}



int main()
{
    TreeNode<int>* root= takeInputLevelwise();
   printTreeLevelwise(root);
  // cout<<"count of nodes : "<<countNoderecursive(root)<<endl;
 //  cout<<"height is : "<<height(root);
  // depthNodes(root,2);
  int ans=0;
    countLeafNodes(root,ans);
    cout<<"Total Leaf Nodes : "<<ans<<endl;

    cout<<"Preorder is:  ";
    preorder(root);

      cout<<"Postorder is:  ";
    postorder(root);

    delete root;
}
