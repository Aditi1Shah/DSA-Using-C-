//* Hashmaps are similar to arrays. In arrays we can only have int type data as the key(within square brackets of array)
//!string ar[n]=u;
//*here n is key and u is value. Value can be of any data type (here string) but n is int always
//* In hashmaps we can have different keys and values both and it helps reducing time complexity to a great extent
//*We will perform 3 operations using hastables :- Insert,Delete and search
//* There are two types of inbuilt hashmaps in C++ namely : (i)Map - Implemented using BST all 3 operations give O(logn)
//* (ii) Unordered Maps - Implemented using HashTables give O(1) time complexity which is why we will use this one.
#include <iostream>
#include <string>
#include <unordered_map>    //*For hashtable
using namespace std;

int main()
{
    unordered_map<string,int> Ourmap;
    //* Insert
    //* Method-1
    pair<string,int> p("abc",1);
    Ourmap.insert(p);
    //* Methode-2
    Ourmap["def"]=2;

    //*If a key is already present in the hastable and u happen to insert a new value with the same key 
    //* The value just gets updated in the same key and does not add anther value with the same key as all keys
    //* are unique


    //* Find/Access Element
    cout<<"Element :"<<Ourmap["abc"]<<endl; //*Accessing element at key abc it will give value= 1 as output
    //* Method-2 : Using at
    cout<<"Element : "<<Ourmap.at("abc")<<endl;
    //* Problem comes when the KEY doesn't exists : Both methods for finding element works in diff ways
    //* Method-1 Works like this
    cout<<"Element : "<<Ourmap["gfh"]<<endl;
    //*It inserts default value,i.e 0  in the hashtable and returns 0 which is weird!
    //*Method-2 works like this:
    //TODO : cout<<"Element : "<<Ourmap.at("ghi")<<endl;
    //* Will throw an error 

    //*Now this is a problem. If i wanna check for some key that its there in the hastable or not how will
    //*I do that? If i use [] it will insert 0 and return that and if i use at it will throw error and abort the
    //* program. I will use count which returns 0 or 1 value, Like this:
    if(Ourmap.count("gfh") > 0)
    {
        cout<<"gfh is Present"<<endl;
    } 
    //*O/p will be : gfh is present : bcz we used [] to access it so it inserted 0 in hashtable for the key gfh

    //*Check Size of Hashtable
    cout<<"Size of HashTable : "<<Ourmap.size()<<endl;

    //*Erase an element
    Ourmap.erase("gfh");
    cout<<"Size of HashTable : "<<Ourmap.size()<<endl;
    if(Ourmap.count("gfh") > 0)
    {
        cout<<"gfh is Present"<<endl;
    } 
    else
    {
        cout<<"gfh is not present";
    }
}
