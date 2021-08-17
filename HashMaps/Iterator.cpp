#include <iostream>
#include <vector>
#include <unordered_map>    //*For hashtable
#include<map>
using namespace std;
int main()
{
    unordered_map<string,int> ourmap;
    ourmap["abc"] = 1;
    ourmap["def"] = 2;
    ourmap["ghi"] = 3;
    //*Iterator will have the address of key and value of hashmap
    cout<<"USING ITERATOR FOR UNORDERED MAP : \n";
    unordered_map<string,int> :: iterator it;
    it = ourmap.begin();
    while(it!=ourmap.end())
    {
        cout<<"Key : "<<it->first<<" Value : "<<it->second<<endl;   //*As it is having address of key and value
        it++;                                                       //*arrow is used. In pair we use dot operator bcz
    }   
    
    //*We got result in any order not in any particular order but if we use map we will get output in sorted manner                                                            //*there we have value of key and value
    cout<<"USING ITERATOR FOR ORDERED MAP : \n";
    map<string,int> omap;
    omap["abc"] = 1;
    omap["def"] = 2;
    omap["ghi"] = 3;
    map<string,int> :: iterator itt;
    itt = omap.begin();
    while(itt!=omap.end())
    {
        cout<<"Key : "<<itt->first<<" Value : "<<itt->second<<endl;   
        itt++;                                                       
    }     
    cout<<"USING ITERATOR FOR VECTOR: \n";
    vector<int> vect;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
     vector<int> :: iterator t;
    t = vect.begin();
    while(t!=vect.end())
    {
       cout<<"Value : "<<*t<<endl;      //*t contins address of the value so *t contains value
        t++;                                                       
    }     
}