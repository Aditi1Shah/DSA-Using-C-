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
int length(Node* head)
{
    int len=0;
    while(head!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;
}
void deletebegin(Node* head)
{
    head=head->next;
    cout<<"\nLinked List after deletion of first node"<<endl;
    print(head);
}
Node* deleteend(Node* head)
{
    Node *prev=head,*cur=NULL;
    cur=prev->next;
        if(prev==NULL)
        {
            free(prev);
            return(head);
        }
        else
        {
             while(cur->next!=NULL)
                {
                    prev=cur;
                    cur=cur->next;
                }
                prev->next=NULL;
                free(cur);
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
Node* deletepos(Node*head,int pos,int l)
{
    if(pos>=l)
    {
        return(head);
    }
    else
    {
        Node *prev=head,*cur=prev->next;
        for(int i=0;i<(pos-2);i++)
        {
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        free(cur);
        return(head);
    }
}
int main()
{
    Node* head = createlinkedlist();
    cout<<"Linked List Created using function is as follows : "<<endl;
    print(head);
    cout<<"\nLength of the linked list found iteratively is :-"<<endl;
    int lengt = length(head);
    cout<<lengt<<endl;
    deletebegin(head);
   /* Node *ptr = deleteend(head);
    cout<<"\nAfter Deleting last node :-"<<endl;
    print(ptr);
    cout<<"\nEnter the position from which you want to delete a node :-"<<endl;
    int p;
    cin>>p;
    Node* temp = deletepos(head,p,lengt);
    cout<<"\nLinked List after deleteing node from "<<p<<" position :-"<<endl;
    print(temp);*/
    int ll=recursivelength(head);
    cout<<"\nLength of Linked List found Recursively :-"<<endl<<ll<<endl;
}
