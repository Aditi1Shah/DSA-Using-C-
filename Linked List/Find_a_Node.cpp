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
int Find_Required_Node(Node* head, int ele)
{
    Node* temp = head;
    int i=0;
    while(temp!=NULL)
    {
        if(temp->data == ele)
        {
            return i;
        }
        temp=temp->next;
        i++;
    }
    return -1;
}
int main()
{
    Node* head = Create_Linked_List();
    cout<<"Linked List : "<<endl;
    print(head);
    int n;
    cout<<"\nEnter data of node to be found : "<<endl;
    cin>>n;
    int res = Find_Required_Node(head,n);
    if(res == -1)
    {
        cout<<"Required node is not present in the linked list."<<endl;
    }
    else
    {
        cout<<"Required Node is present at position : "<<res<<" in the Linked List."<<endl;
    }
}