#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    pair<int, int> data;
    Node *next;
    Node *pre;

    Node(int key, int value)
    {
        data.first = key;
        data.second = value;
        next = NULL;
        pre = NULL;
    }
};

class DLL // This Doubly linked List arrangement behaves like LRU Cache.
{
private:
    int size = 0;
    int capacity; //  > 0
    Node *head = NULL;
    Node *tail = NULL;
    //unordered_map<pair<int, int>, Node*> mp;  // Throws Error
    unordered_map<int, unordered_map<int, Node *>> mp;

    void insertAtBeginning(int x, int y);
    void deleteAtEnd(); // This function will automatically get called when it is needed.
    bool IsFull();

public:
    DLL(int x)
    {
        if (x > 0)
            capacity = x;
        else
            capacity = 1;
    }
    void add(int x, int y);
    void get(int x, int y);
    void EmptyCache();
    void Print();
};

bool DLL::IsFull()
{
    if (size == capacity)
        return true;
    else
        return false;
}

void DLL::insertAtBeginning(int x, int y)
{
    if (IsFull())
    {
        deleteAtEnd();
    }
    // Check for duplication
    if(mp.find(x) != mp.end() && mp[x].find(y) != mp[x].end())
    {
        cout<<"Duplicate elements are not allowed\n";
        return;
    }

    // Create new node
    Node *t = new Node(x, y);
    // TODO Put data in map
    mp[x][y] = t;

    if (head == NULL)
    {
        head = t;
        tail = t;
    }
    else
    {
        t->next = head;
        head->pre = t;
        head = t;
    }
    if (!IsFull())
        size++;
}

void DLL::deleteAtEnd()
{
    if (head == NULL)
        return;

    // Remove data from map also
    int x = tail->data.first;
    int y = tail->data.second;
    mp[x].erase(y);
    mp.erase(x);
    //mp.erase(mp[x][y]); Wrong

    if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        Node *t = tail->pre;
        t->next = NULL;
        delete tail;
        tail = t;
    }
}

void DLL::Print()
{
    if (head == NULL)
    {
        cout << "DLL empty.";
    }
    else
    {
        Node *t = head;
        cout << "\nElements are : ";
        while (t)
        {
            cout << "\nKey : " << t->data.first << "  Value : " << t->data.second << endl;
            t = t->next;
        }
    }
}

void DLL::add(int x, int y)
{
    insertAtBeginning(x, y);
}

void DLL::get(int x, int y)
{
    // find address from map then fetch data from DLL.
    // First of all find x
    /* Method 1
    if (mp.find(x) && mp[x].find(y))
    {
        // Code
    }
    */

    // Method 2
    auto got1 = mp.find(x);
    if (got1 != mp.end())
    {
        auto got = mp[x].find(y);
        if (got != mp[x].end())
        {
            cout<<"Element Found\n";
            // Key is present in map.
            Node *t = mp[x][y];
            if(t == head) return;   // Do nothing
            else if(t == tail)      // Update head and tail
            {
                tail = tail->pre;
                tail->next = NULL;

                t->pre = NULL;
                t->next = head;
                head->pre = t;
                head = t;
            }
            else                    // Update head
            {
                // code
                Node *x, *y, *z;
                x = t->pre;
                y = t;
                z = t->next;
                // Breaking links b/w y then joining x and z
                y->pre = y->next = NULL;
                x->next = z;
                z->pre = x;
                // Updating Head
                y->next = head;
                head->pre = y;
                head = y;
            }
        }else
        {
            cout<<"Element Not Found\n";
        }
    }else
    {
        cout<<"Element Not Found\n";
    }
}

void DLL::EmptyCache()
{
    if (head)
    {
        Node *t;
        while (head)
        {
            t = head;
            head = head->next;
            delete t;
        }
        head = NULL;
        tail = NULL;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    DLL dll(-1);
    dll.add(12, 54);
    dll.add(32, 65);
    dll.add(33, 76);
    dll.get(12,54);
    // dll.Print();
    dll.add(345, 676);
    dll.add(343, 12);
    dll.get(1,5);
    dll.add(7887, 2332);
    dll.add(345, 8778);
    dll.Print();
    return 0;
}

/*                          Important Points
map<pair<int, int>, int> mp;                    // Works

unordered_map<pair<int, int>, int> mp;          // Don't Work

If using pair is not a strict requirement, you can simply use map twice.

                            Solution 1 (From StackOverflow) Use it as a 2D matrix
#include <unordered_map>
using namespace std;
using Unordered_map = unordered_map<string, unordered_map<string, int>>;

Unordered_map um;
um["Region1"]["Candidate1"] = 10;
cout << um["Region1"]["Candidate1"];
*/