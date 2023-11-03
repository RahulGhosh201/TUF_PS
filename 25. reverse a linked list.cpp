// ip: 1->2->3->4->5->NULL
// op: 5->4->3->2->1->NULL
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    { // constructor
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    { // destructor
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is frred from " << val << endl;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data); /// new data die ekta new node create korlam
    temp->next = head;           // notun node tar next e previous head k pathalam
    head = temp;                 // ekhon notun node tai head of the linked lidt
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList(Node *&head)
{
    Node *newHead = new Node(NULL);
    while (head != NULL)
    {
        Node *temp = head->next;
        head->next = newHead;
        newHead = head;
        head = temp;
    }
    print(newHead);
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, 20);
    insertAtTail(tail, 30);
    print(head);
    reverseList(head);
}
