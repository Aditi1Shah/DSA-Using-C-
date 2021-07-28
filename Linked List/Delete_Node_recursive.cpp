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
//create Linked List
Node* create()
{
    Node *head = NULL;
    cout<<"Do you want to enter more Nodes? :- y for yes and n for no  :- "<<endl;
    char ch;
    cin>>ch;
    int d1;
    while(ch=='y'|| ch == 'Y')
    {
         cout<<"Enter data for the node :-"<<endl;
            cin>>d1;
            Node* newNode = new Node(d1);
        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Node* temp = head;
           while(temp->next!=NULL)
           {
            temp=temp->next;
           }
           temp->next=newNode;
        }
         cout<<"Do you want to enter a Node?"<<endl;
         cin>>ch;
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
    Node* head = create();
    print(head);
    cout<<"\nEnter position from which Node is to be deleted from the List :-"<<endl;
    int p;
    cin>>p;
    Node *ptr = deletepos(head,p);
    cout<<"List after Deleting Node from position "<<p-1<<endl;
    print(ptr);
}