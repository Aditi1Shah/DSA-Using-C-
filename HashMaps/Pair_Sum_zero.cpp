//*Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
//*Note: Array A can contain duplicate elements as well.
#include <iostream>
#include <vector>
#include <unordered_map>    //*For hashtable
using namespace std;
unordered_map<int,int> Pair_Sum_Is_Zero(int *ar,int n)
{
    unordered_map<int,int> ourmap;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ar[i] + ar[j] == 0)
            {
                pair<int,int> ele(ar[i],ar[j]);
                ourmap.insert(ele);
            }
        }
    }
return ourmap;
}
int main()
{
    unordered_map<int,int> p;
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
    p = Pair_Sum_Is_Zero(ar,n);
    cout<<"Pairs in the array with sum equal to zero : "<<endl;
    for(auto const &pair : p)
    {
        cout<<pair.first <<" "<<pair.second<<endl;
    }
}