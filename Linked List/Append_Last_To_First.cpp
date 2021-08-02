
/*You have been given a singly linked list of integers along with an integer 'N'
Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.*/
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
int Check_Length(Node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    else
    return 1+Check_Length(head->next);
}
Node* Append_last_to_first(Node* head,int n)
{
    Node* temp=head;
    Node* cur;
    Node* prev=NULL;
    int i;
    int len = Check_Length(head);
    for(i=0;i<len-n;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    cur=temp;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    head=cur;
    return(head);
}

int main()
{
    int n;
    Node*head;
    cout<<"Enter number of trials you wanna perform"<<endl;
    int trials;
    cin>>trials;
    int i;
    for(i=0;i<trials;i++)
    {
    head = Create_Linked_List();
    cout<<"\nLinked List : \n";
    print(head);
    cout<<"\nEnter value of n :"<<endl;
     cin>>n;
     Node* he =  Append_last_to_first(head,n);
    cout<<"\nList after appending last to first\n";
    print(he);
    }
}
