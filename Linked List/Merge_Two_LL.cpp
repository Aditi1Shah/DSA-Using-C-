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
Node* Merge(Node* head1,Node* head2)
{
    Node* ptr=head1;
    Node* temp;
    temp = head1;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    return(ptr);
}
int main()
{
    cout<<"Enter Linked List one : "<<endl;
    Node* head1 = Create_Linked_List();
    cout<<"Enter Linked List two : "<<endl;
    Node* head2 = Create_Linked_List();
    Node* head = Merge(head1,head2);
    cout<<"Linked List after merging : "<<endl;
    print(head);
}