//*Question : Find which element has maximum number of occurances in the given array in which elements are NOT
//*sorted.
#include <iostream>
#include <vector>
#include <unordered_map>    //*For hashtable
using namespace std;
//*LOGIC : We will create two hasmaps: ourmap for storing bool value for every element of array.If ar[i] element
//*is seen for the frst time we will set the bool value for ar[i] = true, AND output hashmap for storing array 
//*element along with number of occurances of the eleor simply count.Initially when element is seen for the 1st time
//*We will set ourmap[ar[i]]=true and also add the element along with count=1 in output.
//*Then on i++ we will reach to next ele in the array ar, to check whether this ele is already seen or not we will
//*use if(output.count(ar[i]) > 0 ) if yes(bool = 1) means ele is seen already so we will just increase the count
//*in output map for that ele and also apply condition to check if its count is max or not.
pair<int,int> Max_Frequency_Of_Occurance(int *ar,int size)
{
    unordered_map<int,bool> ourmap;
    unordered_map<int,int> output;
    int i,max = 1,ele_of_max;
    for(i=0;i<size;i++)
    {
        if(ourmap.count(ar[i])>0)   //* if this condition holds it means ar[i] element is already seen by us so we have to 
                                    //*increase its corresponding count value
        {
            output[ar[i]]++;         //*increasing count value of the ar[i] th element
            if(output[ar[i]] > max) //*if count or ar[i]th element > max then max is count of ar[i] element 
                                    //*and ele_of_max = element whose count = max.
            {
            max = output[ar[i]];
            ele_of_max=ar[i];
            }                    
        }
        ourmap[ar[i]] = true;        //*If seeing an element for the frst time then add true for ar[i] and add the element 
                                     //*in output hashmap with count = 1 as it has been seen for the frst time for now
                                     //* so no of appearances,i.e count = 1
        pair<int,int> p(ar[i],1);    //*pair class bcz we r inserting two int values in hashmap simultaneously
        output.insert(p);
    }
pair<int,int> result;
result.first = ele_of_max;
result.second = max;
return result;  
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
    pair<int,int> res;
    res = Max_Frequency_Of_Occurance(ar,n);
    cout<<"Element with maximum frequencies : "<<res.first<<endl;
    cout<<"No of occurances of "<<res.first<<" element : "<<res.second<<endl;;
}
