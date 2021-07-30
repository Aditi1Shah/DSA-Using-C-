#include<iostream>
using namespace std;
class Node{
public :
int data;
Node* next;
Node(int data)
{
    this->data = data;
    next=NULL;
}
};
void print(Node *head)
{
    Node* temp=head;
    cout<<"Inside Print function"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    //Use temp to not let head value to alter.But this only makes sense if we wanna do something more with
    //head inside this function only!like if we want to print a list two times(inside this function with two while loops)
    //then if we use head its already Null so we wont be able to do that
    //But we can do it by calling two times the print function then in that case we wont need temp as 
    //we are calling two times from main function so two times head value will be passed in this function a copy 
    //of head is made and that copy is being altered and not the original head of main.
    //see use of print2 function for understanding.
}
void print2(Node *head)
{
    cout<<"Inside Print2 function"<<endl;
     while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    cout<<"Enter values to be passed in three nodes"<<endl;
    int d1,d2,d3;
    cin>>d1>>d2>>d3;
    Node* n1 = new Node(d1);
    Node* n2 = new Node(d2);
    Node* n3 = new Node(d3);
    n1->next=n2;
    n2->next=n3;
    Node* head=n1;
    print(head);        //Notice how a pointer is passed as parameter to a function
    cout<<endl;
    print2(head);
    cout<<endl;
    print2(head);//I am able to print the list two times without temp!

}
