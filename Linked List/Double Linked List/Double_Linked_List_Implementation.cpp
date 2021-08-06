#include<iostream>
using namespace std;
class Node
{
public:
int data;
Node *next;
Node *prev;
Node(int data)
{
    this->data = data;
    next=NULL;
    prev=NULL;
}
};
Node* Create_Double_Linked_List()
{
   printf("Enter data in the double Linked list : -1 for termination of list\n");
   int data;
   cin>>data;
    Node* head=NULL;
    while(data!=-1)
    {
        Node* newNode = new Node(data);
        if(head==NULL)
        {
            head=newNode;
        }
        else{
            Node *temp = head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
        }
        cin>>data;
    }
    return(head);
}
void print(Node* head)
{
    cout<<"Doubly Linked List :-"<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node* insert_at_end(Node* head,int data)
{
    Node* newNode = new Node(data);
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    // No need to set  newNode->next=NULL because it will happen automatically when newNode is created
    //because of the constructor
    return(head);
}
Node* insertpos(Node* head,int pos,int data)
{
    Node* newNode = new Node(data);
    Node* temp = head;
    int i;
    if(pos==0 || pos==1)
    {
        newNode->next=head;
        head->prev = newNode;
        head=newNode;
    }
    else
    {
    for(i=0;i<pos-2;i++)
    {
        temp=temp->next;
    }
    newNode->prev=temp;
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    }
     return(head);
}
Node* Delete_end_Node(Node* head)
{
    Node* ptr;
    Node* temp = head;
    while(temp->next!=NULL)
    {
        ptr=temp;
        temp = temp->next;
    }
    ptr->next=NULL;
    temp->prev=NULL;
    free(temp);
    return(head);
}
Node* Delete_Specific_position(Node* head,int pos)
{
    Node* ptr;
    Node* temp = head;
    Node* cur;
    int i;
    if(pos == 0|| pos == 1)
    {
        temp=head;
        head=head->next;
        temp->next=NULL;
        head->prev=NULL;
        free(temp);
    }
    else
    {
        for(i=0;i<pos-1;i++)
        {
            ptr = temp;
            temp=temp->next;
        }
        cur=temp->next;
        temp->next=NULL;
        temp->prev=NULL;
        ptr->next=cur;
        cur->prev=ptr;
        free(temp);
    }
    return(head);
}
int main()
{
    int choice;
    Node* head;
    Node* ptr;
    int pos,data;
    cout<<"-------------MENU---------------"<<endl;
    cout<<"1.Create Double Linked List"<<endl;
    cout<<"2 Display"<<endl;
    cout<<"3.Insert at specific position/Insert at beginning"<<endl;
    cout<<"4.Insert at the end"<<endl;
    cout<<"5.Delete the last node"<<endl;
    cout<<"6.Delete at specific position/Delete first node"<<endl;
    cout<<"7.Exit"<<endl;
    while(1)
    {
        cout<<"\nEnter your choice from the MENU"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: head = Create_Double_Linked_List();
                    print(head);
                    break;
            case 2: print(head);
                    break;
            case 3: cout<<"\nEnter position where new Node is to be inserted : \n";
                    cin>>pos;
                    cout<<"Enter data of the new Node : \n";
                    cin>>data;
                    ptr = insertpos(head,pos,data);
                    print(ptr);
                    break;
            case 4: cout<<"Enter data of the new Node : \n";
                    cin>>data;
                    ptr = insert_at_end(head,data);
                    print(ptr);
                    break;
            case 5: ptr = Delete_end_Node(head);
                    print(head);
                    break;
            case 6: cout<<"\nEnter position where new Node is to be deleted : \n";
                    cin>>pos;
                    ptr=Delete_Specific_position(head,pos);
                    print(ptr);
                    break;
            case 7: exit(0);
                    break;
            default : cout<<"Bad Choice\n";
                      break;
        }
    }
}
