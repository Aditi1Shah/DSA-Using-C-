#include<iostream>
#include<string.h>
using namespace std;
template<typename V>
class MapNode
{
    public:
    string key;
    V value;
    MapNode* next;
    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next=NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};
template<typename V>
class ourmap{
    MapNode<V>** buckets;       //*Buckets is an array with each index having address of first node of each linked list
    int size;
    int count;
    int numBuckets;
    public:
    ourmap()
    {
        count=0;
        size=0;
        numBuckets=5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i =0;i<numBuckets;i++){
        buckets[i] = NULL;
        }
    }
    ~ourmap()
    {
        for(int i =0;i<numBuckets;i++){
        delete buckets[i];
        }
        delete [] buckets;
    }
    int size_Value()
    {
        return count;
    }
    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head!=NULL)
        {
            if(head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    private:
    int getBucketIndex(string key)      //*returns index of bucket array where value of key is to be stored
    {
        int hashCode=0;
        int CurrCoeff = 1;
        for(int i=key.length()-1;i>=0;i--)
        {
            hashCode += key[i] * CurrCoeff;
            hashCode = hashCode % numBuckets;       //*Compressing hashCode
            CurrCoeff *= 37;
            CurrCoeff = CurrCoeff%numBuckets;       //*Compressing current coefficient
        }
        return hashCode%numBuckets;
    }
    public:
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
//*Checks whether the value corresponding to the key is already there in the array or not if yes then just update 
//*the value at that key and not create another node for that bcz one node for one key
        while(head!=NULL)
        {
            if(head->key == key)
            {
                head->value = value;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key,value);
        node->next=head;
        buckets[bucketIndex] = node;
        count++;
    }
    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        while (head!=NULL)
        {
            if(head->key == key)
            {
            if(prev==NULL)  //*Delete the first node
            {
                buckets[bucketIndex] = head->next;  //*bucket index will have address of second ele of linked list as head
            }
            else{
            prev->next = head->next;
            }
            V value = head->value;
            head->next=NULL;
            delete head;
            count--;
            return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;   //*invalid value
    }
};
int main()
{
    ourmap<int> ob;
    ob.insert("abc",1);
    ob.insert("efg",2);
    ob.insert("hij",3);
    ob.insert("klm",4);
    int n = ob.size_Value();
    cout<<"\nSize : "<<n<<endl;
    int val = ob.getValue("abc");
    cout<<"Value : "<<val<<endl;
    ob.insert("abc",14);
     int va = ob.getValue("abc");
    cout<<"Value : "<<va<<endl;
    int m = ob.size_Value();
    cout<<"\nSize : "<<m<<endl;
    int b = ob.remove("efg");
    cout<<"Removed Value : "<<b<<endl;
}