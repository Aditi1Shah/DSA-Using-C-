//*WAP to remove duplicate elements in the array using hashmaps
#include <iostream>
#include <vector>
#include <unordered_map>    //*For hashtable
using namespace std;
//*LOGIC : In the remove duplicate func create a hashmap with key as int and value as bool(true or false)
//* means for every element of array we will set true for seeing the element for the frst time and will push the 
//*element in a vector. For element which is a duplicate (which we have already seen and enetered in vector)
//*we wont enter it in the vector and will continue with our process and will finally return the vector. 
vector<int> remove_duplicate(int *a, int size)
{
    vector<int> output;
    unordered_map<int,bool> ourmap;
    int i;
    for(i=0;i<size;i++)
    {
        if(ourmap.count(a[i])>0)
        {
            continue;   //* If a[ith] element is already seen by us(is a duplicate) then dont add the element in the 
                        //* vector just dont do anything and continue
        }
        ourmap[a[i]] = true;    //*If seeing an element for the frst time then see and add int the vector
        output.push_back(a[i]);
    }
    return output;
}
int main()
{
    cout<<"Enter the size of the array"<<endl;
    int n;
    int i;
    cin>>n;
    int ar[n];
    cout<<"Enter elements in the array : \n";
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    vector<int> op;
    op=remove_duplicate(ar,n);
    cout<<"After removing duplicate elements are array is :\n";
    for(i=0;i<op.size();i++)
    {
        cout<<op[i]<<"\t";
    }
}