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
Node* createlinkedlist()    //returns head pointer
{
    cout<<"Do you want to enter a Node?"<<endl;
    int data;
    char c;
    cin>>c;
    Node* head=NULL;
    while(c=='y'||c=='Y')
    {   
        cout<<"Enter data :-"<<endl;
        cin>>data;
        Node *newNode = new Node(data);
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
        cout<<"Do you want to enter a Node?"<<endl;
        cin>>c;
    }
    return head;
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
    Node* head = createlinkedlist();
    cout<<"Linked List Created using function is as follows : "<<endl;
    print(head);
    cout<<"\nLength of the linked list found iteratively is :-"<<endl;
    int lengt = recursivelength(head);
    cout<<lengt<<endl;
   /* cout<<"Enter the data of new node to be inserted :-"<<endl;
    int d2;
    cin>>d2;
    cout<<"Enter the position where node is to be inserted :-"<<endl;
    int p;
    cin>>p;
    Node *ptr = insertpos(head,p,d2,lengt);
    cout<<"New List:-"<<endl;
    print(ptr);*/
    cout<<"\nEnter data for new node for recursive insertion :-"<<endl;
    int d3;
    cin>>d3;
    cout<<"Enter the position where node is to be inserted :-"<<endl;
    int p;
    cin>>p;
    Node* ptr2 = insertposrecurive(head,p-1,d3);
    cout<<"New List :-"<<endl;
    print(ptr2);
}