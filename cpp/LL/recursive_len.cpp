#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;

    Node (int data)
    {
        this->data=data;
        next=NULL;
    }

};
Node* input()
{
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1)
    {
        Node *n= new Node(data);
        if(head==NULL)
        {
            head=n;
            tail=n;
        }
        else{
            tail->next=n;
            tail=n;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
bool search(Node *head,int x)
{
    Node *temp= head;
    while(temp!=NULL && temp->next!=NULL)
    {
        if(temp->data==x)
        {
            return true;
        }
       temp=temp->next;
    }
    return false;
}
bool search2(Node *head, int x)
{if(head==NULL)
    {
        return false;
    }
    Node *temp=head;
if(temp->data==x) return true;
    return search2(temp->next,x);
}
int main()
{
    Node *head=input();
    print(head);
    int mid= middle(head);
   cout<<endl<<ans;
}
