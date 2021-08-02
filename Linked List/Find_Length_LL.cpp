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
int recursivelength(Node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    else{
        return 1+recursivelength(head->next);
    }
}
int main()
{
    Node* head = Create_Linked_List();
    cout<<"Linked List : "<<endl;
    print(head);
    int length = recursivelength(head);
    cout<<"\nLength of the Linked List : "<<length<<endl;
}