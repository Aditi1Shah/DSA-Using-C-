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
Node* deleteAlternateNodes(Node *head) {
    //Write your code here
    Node* temp=head;
    Node* ptr;
    Node* cur;
    if(head!=NULL && head->next!=NULL)
    {
    while(temp!=NULL)
    {
        cur=temp->next;
        ptr=cur;
        cur=cur->next;
        temp->next=cur;
        ptr->next=NULL;
        free(ptr);
        temp=temp->next;
    }
    }
    return head;
}
int main()
{
    Node* head = Create_Linked_List();
    print(head);
    Node* ptr = deleteAlternateNodes(head);
    cout<<"\n";
    print(ptr);

}