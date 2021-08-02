/* WAP to check if a Linked List is a Palindrome Linked List or not */

#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int data)
{
    this->data=data;
    next=NULL;
}
};
Node* Create_Linked_List()
{
    Node* head = NULL;
    int data;
    cout<<"\nEnter data for the node : (Enter -1 to terminate the list)"<<endl;
    cin>>data;
    while(data!=-1)
    {
        Node* newNode = new Node(data);
        if(head==NULL)
        {
            head = newNode;
        }
          else
        {
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        }
        cin>>data;
    }
    return(head);
}
void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node* Reverse_Iterative(Node* head)
{
    Node* cur=head;
    Node* prev=NULL;
    Node* temp;
    while(cur!=NULL)
    {
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    head=prev;
    return(head);
}
int Palindrome_Or_Not(Node* head)
{
    Node* reverse_ll = Reverse_Iterative(head);
    Node* temp = head;
    Node* ptr = reverse_ll;
    while(temp!=NULL)
    {
        if(temp->data != ptr->data)
        {
            return 0;
        }
        temp=temp->next;
        ptr = ptr->next;
    }   
    return 1;
}
int main()
{
    Node* head= Create_Linked_List();
    cout<<"\nLinked List is as follows : "<<endl;
    print(head);
    int result = Palindrome_Or_Not(head);
    if(result==1)
    {
    cout<<"\nTrue : Linked List is palindrome Linked List"<<endl;
    }
    else
    cout<<"\nFalse : Linked List is not a palindrome Linked list"<<endl;
}
