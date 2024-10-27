/*
Important Relation:
-------------------
(n1*n2*n3)%r = ((n1 % r) * (n2 % r) * (n3 % r)) % r
*/

#include <string>
// #include<iostream>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    // Parametrized Constructor
    MapNode(string key, V value)
    { // Creating this due to linked list
        this.key = key;
        this.value = value;
        next = NULL;
    }

    // Destructor
    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    /*For example: (int**a); //Pointer to a pointer to an integer value*/

    MapNode<V> **buckets; // MapNode<V>* ->Ek Linked List ka head, MapNode<V> **buckets represents L.L. ke head ka array
    // Linked List ka head is the pointer
    int count; // Total number of unique nodes
    int numBuckets;

public:
    // Default Constructor
    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
    }

    // Each element of array will have Garbage Value,so, we initialise it to NULL
    for (int i = 0; i < numBuckets; i++)
    {
        buckets[i] = NULL;
    }

    // Default Destructor
    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            // Pehle har Linked List ko delete kiya bcos agar pehle array delete krte toh LL ka address na rehta
            delete buckets[i];
        }
        delete[] buckets;
    }

    /****************************************/
    int size()
    {
        return count;
    }

    /******************************************/

    V getValue(string key)
    {
        // key ke corresponding value mil jayegi

        // Key --> will go through a HASH Function --> bucketIndex --> placing the key

        int bucketIndex = getBucketIndex(key);

        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    
    /*Time Complexity: O(1)*/

    /******************************************/

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int currentCoeff = 1; //(Think about "abc" -> a*p^3 + b*p^2 + c*p)

        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets; // Doing this bcos it will go out of range of integers very fastly
            currentCoeff *= 37;               // We prefer value of p to be a Prime number
            currentCoeff = currentCoeff % numBuckets;
        }
        return hashCode % numBuckets; // Called Compression Function
    }

public:
    void insert(string key, value V)
    {
        int bucketIndex = getBucketIndex(key);

        MapNode<V> *head = buckets[bucketIndex];

        // We are figuring out if the key that is to be inserted is present or not

        // If key is already present, we are simply updating the value

        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }

        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        // bucket array now must look at the new head instead of the previous head
        buckets[BucketIndex] = node;
        count++;
        
        double loadFactor = (1.0*count)/numBuckets;
        if(loadFactor > 0.7){
            rehash();
        }
    }

    /*
    Time Complexity:
    ---------------

    Key --> Hash function --> get the index where to be inserted

    Let n be the number of entries in our map,
    Let l be the length of the word,

    Hash Computation time will be O(l).

    It has been researched that if i have n entries and b boxes, then on an average (n/b){known as load factor} entries will be in each box.

    We therefore assume that complexity will be O(n/b). Also, n/b < 0.7(in some near range of this) means har box mein 1 entry se bhi kam anne ek Probability hai. This is insured that huge number of entries don't go to a single box.

    We can safely assume that key ke liye hash code mila and we safely put it into the desired box with complexity O(1).

    If my load on n/b tries to become greater than 0.7, then we will do Rehashing and increase the size of bucket i.e. If n increases --> increase b

    We will not do Rehashing at a frequent rate, also, load factor is small, hence T.C. will be O(1).

    */

    /******************************************/

    V remove(string key) // key will get deleted and corresponding value will be returned
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;

        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }

                else
                {
                    prev->next = head->next;
                }

                V value = head->value; // Delete krne se pehle value store karli
                head->next = NULL;     // Bcos varna aage sare elements bhi delete ho jate
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

    /*Time Complexity: O(1)*/
    -- -- -- -- -- -- -- -- -
};

/******************************************/
