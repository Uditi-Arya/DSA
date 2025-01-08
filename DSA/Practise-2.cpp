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
void reverse(node * &head)
{
    if(head==NULL)
    {
        cout<<"The list is empty";
        return;
    }
    node *prev=NULL,*current=head,*next=head->next;//initially
    while(current!=NULL)
    {
        next=current->next;//incrementing
        current->next=prev;
        prev=current;//incrementing
        current=next;//incre,emting
    }
    head=prev;//updating the head
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
void deletion(node * &head, int val)
{
    if(head==NULL)
    {
        cout<<"linked list is empty, no node to delete";
        return;
    }
    if(head->data==val)// deletion at head
    {
        node *toDelete=head;
        head=head->next;
        delete toDelete;
        return;
    }
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
    cout<<"the original list is:"<<endl;
    display(head);
    cout<<endl;
    reverse(head);
    cout<<"the reversed list is:"<<endl;
    display(head);
    
    return 0;
}