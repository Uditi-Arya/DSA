#include<iostream>
using namespace std;
class node{
    public:
       int data;
       node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insertAtEnd(node * &head,int data)
{
    node * newNode=new node(data);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}
void insertAtStart(node* &head,int data)
{
    node *newNode=new node(data);
    if(head==NULL)
    {
        head==newNode;
        return;
    }
    node *temp=head;
    head=newNode;
    newNode->next=temp;
}
void display(node *head)
{
    node *temp=head;
    if(head==NULL)
    {
        cout<<"The list is empty";
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<" "; 
        temp=temp->next;   
    }
}
bool searchKey(node *head,int key)
{
    node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void deletion(node * &head, int val)
{
    node *temp=head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node *toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
}
int main()
{
    node *head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtStart(head,4);
    display(head);
    // int key;
    // cout<<"Enter key to search:";
    // cin>>key;
    // cout<<searchKey(head,key);
    int val;
    cout<<"Enter the value of the node to delete:";
    cin>>val;
    deletion(head,val);
     display(head);
    return 0;
}