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
    ourmap["jkl"] = 4;
    ourmap["mno"] = 5;
    ourmap["pqr"] = 6;
    unordered_map<string,int> :: iterator it;
   it = ourmap.find("abc");
   cout<<"Value : "<<it->second<<endl;

   //*Uisng iterators to delete a value at certain key
   unordered_map<string,int> :: iterator itt;
   it = ourmap.find("abc");
   ourmap.erase(it);
   it = ourmap.begin();
    while(it!=ourmap.end())
    {
        cout<<"Key : "<<it->first<<" Value : "<<it->second<<endl;   //*As it is having address of key and value
        it++;                                                       //*arrow is used. In pair we use dot operator bcz
    }   
    //* abc wont be printed bcz its deleted

    vector<int> vect;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(5);
    vector<int> :: iterator t;
    t=vect.begin();
    vect.erase(t,t+2);
    t = vect.begin();
    while(t!=vect.end())
    {
       cout<<"Value : "<<*t<<endl;      //*t contins address of the value so *t contains value
        t++;                                                       
    }     
    //*1st to 3rd elements are deleted
}