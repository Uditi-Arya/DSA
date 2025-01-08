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
node *reverseRecursive(node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node *newHead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
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
int main()
{
    node *head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    cout<<"the original list is:"<<endl;
    display(head);
    cout<<endl;
    node *newHead=reverseRecursive(head);
    cout<<"the reversed list is:"<<endl;
    display(newHead);
    
    return 0;
}