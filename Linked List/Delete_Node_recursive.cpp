//Program to delete a node from entered position.
#include<iostream>
using namespace std;
class Node
{
public:
int data;
Node* next;
Node(int data)
{
    this->data=data;
    next=NULL;
}
};
//Create Linked List
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
Node* deletepos(Node* head,int pos)
{
    if(head==NULL)
    {
        return(NULL);
    }
    else if(pos == 0 || pos==1)
    {
         Node* temp= head->next;
        free(head);
         return(temp);
    }
    else{
        head->next = deletepos(head->next,pos-1);
         return(head);
    }
   
}
void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    Node* head = Create_Linked_List();
    cout<<"Linked List is as follows : "<<endl;
    print(head);
    cout<<"\nEnter position from which Node is to be deleted from the List :-"<<endl;
    int p;
    cin>>p;
    Node *ptr = deletepos(head,p);
    cout<<"List after Deleting Node from position "<<p<<endl;
    print(ptr);
}
