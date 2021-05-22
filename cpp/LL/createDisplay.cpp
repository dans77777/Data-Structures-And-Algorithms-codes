#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
Node* input()
{
    int data;
    cin>>data;
    Node *head= NULL;
    Node *tail=NULL;

    while(data!=-1)
    {
        Node *n= new Node(data);
        if(head==NULL)
        {
        head=n;
        tail=n;
        }
        else
      { n->next=head;
      head=n;

    }
cin>>data;
    }
return head;


}
int length( Node *head)
{
     int cnt=0;
    Node *temp= head;
    while(temp!=NULL)
    {
       cnt++;
       temp=temp->next;
    }
    return cnt;
}
void print(Node *head)
{
    Node *temp= head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

void print2(Node *head, int i)
{
    int counter=1;
    if(i<0)
    {
        return;
    }
    Node *temp= head;

    while (counter<=i &&temp!=NULL)
    {
        temp=temp->next;
        counter++;
    }
    if(temp)
    {
        cout<<endl<<temp->data;
    }
    else{
        cout<<-1;
    }

   // cout<<"NULL";
}

int main()
{
    Node *head= input();
    print(head);
    cout<<endl;
      print2(head,7);

    int ans= length(head);
    cout<<endl<<"length of LL  : "<<ans;
}
