//Insert a node using Recursive Function And also by using recursive function.
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
//Iterative Approach to Insert Nodes in a Linked List
Node* insertpos(Node* head,int position,int data,int length)
{
    Node* newNode = new Node(data);
    Node* temp=head;
    if(position==0)
    {
        head=newNode;
        newNode->next=temp;
        return(head);
    }
    else if(position>=length)
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        return(head);
    }
    else
    {
        for(int i=0;i<(position-2);i++)
        {
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        return(head);
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
// Recursive Approach of Inserting
Node* insertposrecurive(Node*head,int pos,int data)
{
    if(head==NULL || pos==0)
    {
        Node* newNode = new Node(data);
        newNode->next=head;
        head=newNode;
    }
    else
    {
        head->next = insertposrecurive(head->next,pos-1,data);
    }
     return(head);
}
int main()
{
    cout<<"--------MENU--------"<<endl;
    cout<<"1.Create Linked List"<<endl;
    cout<<"2. Print Linked List"<<endl;
    cout<<"3. Calculate Length of the Linked List"<<endl;
    cout<<"4. Insert Node using iterative Approach"<<endl;
    cout<<"5. Insert Node using Recursive Approach"<<endl;
    cout<<"6. Exit"<<endl;
    int ch,p,pos,n;
    Node* head;
    Node* ptr;
    while(true)
    {
        cout<<"\nEnter your choice : "<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1: head = Create_Linked_List();
                cout<<"Linked List is as follows : "<<endl;
                print(head);
            break;
        case 2: cout<<"Linked List is as follows : "<<endl;
                print(head);
            break;
        case 3: p = recursivelength(head);
                cout<<"Length of the Linked List is : "<<p<<endl;
                break;
        case 4: cout<<"Enter data of node to be inserted : "<<endl;
                cin>>n;
                cout<<"Enter position where node is to be inserted in the list : "<<endl;
                cin>>pos;
                p=recursivelength(head);
                ptr = insertpos(head,pos,n,p);
                cout<<"Linked List after inserting new node : "<<endl;
                print(ptr);
                break;
        case 5: cout<<"Enter data of node to be inserted : "<<endl;
                cin>>n;
                cout<<"Enter position where node is to be inserted in the list : "<<endl;
                cin>>pos;
                ptr = insertposrecurive(head,pos-1,n);
                cout<<"Linked List after inserting new node : "<<endl;
                print(ptr);
                break;
        case 6: exit(0);
                break;
        default: cout<<"Bad Choice"<<endl;
            break;
        }
    }
}
