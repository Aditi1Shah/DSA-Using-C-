//Reverse Linked List Using Iterative and Recursive Approach
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
Node* Reverse_Iterative(Node* head)
{
    Node* cur=head;
    Node* prev=NULL;
    Node* temp;
    while(cur!=NULL)
    {
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    head=prev;
    return(head);
}
Node* Reverse_Recursive(Node* head)
{
    if(head==NULL || head->next==NULL) //* If there is no node i.e head==NULL 
    {                              //*or if there is only one node i.e head->next == NULL
        return head;
    }
    Node* temphead = Reverse_Recursive(head->next);
    Node* temp = temphead;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return temphead;
}
int main()
{
    Node* head;
    Node* ptr;
    int ch;
    cout<<"1. Create Linked List"<<endl;
    cout<<"2. Print Linked List"<<endl;
    cout<<"3. Reverse Linked List using Iterative Approach"<<endl;
    cout<<"4. Reverse Linked List using Recursive Approach"<<endl;
    cout<<"5. Exit"<<endl;
    while(1)
    {
    cout<<"\nEnter your choice : "<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1: head = Create_Linked_List();
                cout<<"Linked List is as follows : "<<endl;
                print(head);
                break;
    case 2: cout<<"Linked List is as follows : "<<endl;
                print(head);
                break;
    case 3: ptr = Reverse_Iterative(head);
            cout<<"Linked List After Reversing : "<<endl;
            print(ptr);
                break;
    case 4: ptr = Reverse_Recursive(head);
            cout<<"Linked List After Reversing : "<<endl;
            print(ptr);
                break;
    case 5: exit(0);
                break;
    default : cout<<"Bad Choice\n";
                break;
    }
    
    }

}
