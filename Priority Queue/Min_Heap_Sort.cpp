#include<iostream>
#include<vector>
using namespace std;
class PriorityQueue
{
    vector<int> pq;
    public:
    PriorityQueue(){

    }
    bool isEmpty()
    {
        return pq.size()==0;
    }
    int getSize()
    {
        return pq.size();
    }
    int getMin()
    {
        if(isEmpty())
        return 0;

        return pq[0];       //*Minimum element of a min heap is the root element
    }
    void insert(int element)
    {
        pq.push_back(element);
        int Child_Index = pq.size()-1;
        while(Child_Index > 0)
        {
        int Parent_Index = (Child_Index-1)/2;
        if(pq[Child_Index] < pq[Parent_Index])
        {
            int temp = pq[Child_Index];
            pq[Child_Index] = pq[Parent_Index];
            pq[Parent_Index] = temp;
        }
        else{
            break;
        }
        Child_Index =  Parent_Index;
        }
    }
    void print()
    {
        int i;
        for(i=0;i<pq.size();i++)
        {
            cout<<pq[i]<<" ";
        }
        cout<<endl;
    }
  int Remove_Min()
    {
        if(isEmpty())
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];     //*Swapping Minimum(root) ele with last child as then only we can delte as per 
                                    //*the rules of a BST 
        pq.pop_back();  //*Delete the last element of the vector which is the root node.The one we wanted to delete.

    //* Deletion of req element is done but now we want to check that after swapping root with the last child whether 
    //*the tree is still a min heap or not
    int parentIndex = 0;
    int LeftChildIndex = 2*parentIndex+1;
    int RightChildIndex = 2*parentIndex+2;
    while(LeftChildIndex < pq.size())   //*When left child is reached right is reached too
    {
        int minIndex = parentIndex;
        if(pq[minIndex] > pq[LeftChildIndex])
        minIndex = LeftChildIndex;
        if(RightChildIndex < pq.size() && pq[minIndex] > pq[RightChildIndex])
        minIndex = RightChildIndex;
        if(minIndex == parentIndex)
        {
            break;
        }
        int temp = pq[minIndex];
        pq[minIndex] = pq[parentIndex];
        pq[parentIndex] = temp;

        parentIndex = minIndex;
        LeftChildIndex = 2*parentIndex+1;
        RightChildIndex = 2*parentIndex+2;
    }
    return ans;
    }
};
int main()
{
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);
    cout<<"Heap : "<<endl;
    p.print();
    cout<<"Size : "<<p.getSize()<<endl;
    cout<<"Minimum Element : "<<p.getMin()<<endl;
    while(!p.isEmpty())
    {
    int y = p.Remove_Min();
    cout<<y<<" ";
    }
    //*Notice this gives you the sorted array!
    //*Time Complexity Of Heap_Sort : n*O(logn)+n*O(logn) = O(nlogn)
    //*Space Complexity = O(n)
}
