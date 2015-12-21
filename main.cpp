#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;

public:
    node() {};
    void setData(int cData) {data = cData;};
    void setNext(node *cNext) {next = cNext;};
    int Data() {return data;};
    node* Next() { return next;};
};

class List {
    node *head;
public:
    List() {head = NULL;};
    void Print();
    void Append(int data);
    void Delete(int data);
    void Size();
    void Reverse();
    void Add(node *a, node*b, List *c);
};

/*
 * Print a list.
 */
void List::Print() {
    node *temp = head;

    if (temp == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (temp->Next() == NULL) {
        cout << temp->Data() << "->" << "NULL" << endl;
    }
    else {
        do {
            cout << temp->Data() << "->";
            temp = temp->Next();
        }
        while (temp != NULL);
        cout << "NULL" << endl;
    }
}

/*
 * Append to a list.
 */
void List::Append(int data) {
    node *newNode = new node();
    newNode->setData(data);
    newNode->setNext(NULL);

    node *temp = head;
    if (temp != NULL) {
        while (temp->Next() != NULL) {
            temp = temp->Next();
        }
        temp->setNext(newNode);
    } else {
        head = newNode;
    }
}

/*
 * Delete node from
 * a list.
 */
void List::Delete(int data) {
    node *temp = head;
    if (temp == NULL) {
        return;
    }
    if (temp->Next() == NULL) {
        delete temp;
        head = NULL;
    } else {
        node *prev;
        do {
            if (temp->Data() == data) {
                break;
            }
            prev = temp;
            temp = temp->Next();
        } while (temp != NULL);
        prev->setNext(temp->Next());
        delete temp;
    }
}

/*
 * Size of a list.
 */
void List::Size() {
    node *temp = head;
    if (temp == NULL) {
        cout << 0;
    }
    if (temp->Next() == NULL) {
        cout << 1;
    } else {
        int i = 0;
        while (temp != NULL) {
            temp = temp->Next();
            i++;
        }
        cout << i << endl;
    }
}

/*
 * Reverse a list.
 */
void List::Reverse() {
    node *prev = NULL;
    node *next;
    node *temp = head;
    while (temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}

/*
 * TODO: Implement
 * Take as input two lists, then
 * add the values stored in the lists.
 * Return result as a new list.
 */
void List::Add(node *a, node *b, List *c){
    int carry;
    if (!a && !b) {
        return;
    }
    int aVal = a ? a->data : 0;
    int bVal = b ? b->data : 0;
    int sumAB = aVal + bVal + carry;
    carry = sumAB / 10;
    sumAB %= 10;

    c->Append(sumAB);
    c->Append(carry);
}

class Queue {
    node *head;
public:
    Queue() {head = NULL;};
    void Dequeue();
    void Enqueue(int data);
    void Empty();
    bool Full();
    void Front();
    void Print();
    int Size();
};

/*
 * Add to the Queue.
 */
void Queue::Enqueue(int data) {
    node *newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    node *temp = head;
    if (temp != NULL && !Size() <= 6) {
        while (temp->next != NULL) {
            if (Full()){
                return;
            } else {
                temp = temp->next;
            }
        }
        temp->next = newNode;
    } else {
        head = newNode;
    }
}

/*
 * Boolean return to determine
 * if the Queue is full based
 * on a preset value.
 */
bool Queue::Full() {
    if (Size() >= 6) {
        cout << "Queue is Full" << endl;
        return true;
    } else {
        return false;
    }
}

/*
 * Print the front of the
 * Queue and then delete
 * the front node.
 */
void Queue::Dequeue() {
    node *temp = head;
    if (head == NULL) {
        cout << "Queue is empty" << endl;
    } else {
        head = head->next;
        cout << "Dequeuing " << temp->Data() << endl;
        delete temp;
    }
}

/*
 * Print the front of
 * the Queue.
 */
void Queue::Front() {
    node *temp = head;
    if (temp == NULL) {
        cout << "Queue is empty" << endl;
    } else {
        cout << temp->Data() << endl;
    }
}

/*
 * Empty the Queue
 */
void Queue::Empty() {
    node *temp = NULL;
    if (head != NULL) {
        head = temp;
        delete temp;
    } else {
        cout << "Queue already empty" << endl;
    }
}

/*
 * Print the Queue.
 */
void Queue::Print() {
    node *temp = head;

    if (temp == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    if (temp->Next() == NULL) {
        cout << temp->Data() << "->" << "NULL" << endl;
    }
    else {
        do {
            cout << temp->Data() << "->";
            temp = temp->Next();
        }
        while (temp != NULL);
        cout << "NULL" << endl;
    }
}

/*
 * Return Queue's size.
 */
int Queue::Size() {
    node *temp = head;
    if (temp == NULL) {
        return 0;
    }
    if (temp->Next() == NULL) {
        return 1;
    } else {
        int i = 0;
        while (temp != NULL) {
            temp = temp->Next();
            i++;
        }
        return i;
    }
}

int main() {

    cout << "Queue Testing" << endl;
    Queue q1;
    q1.Front();
    q1.Enqueue(3);
    q1.Front();
    q1.Enqueue(7);
    q1.Enqueue(8);
    q1.Print();
    q1.Enqueue(9);
    q1.Print();
    cout << "Size: " << q1.Size() << endl;
    q1.Enqueue(10);
    q1.Print();
    q1.Enqueue(11);
    q1.Print();
    q1.Full();
    q1.Enqueue(12);
    q1.Enqueue(13);
    q1.Front();
    q1.Print();
    q1.Dequeue();
    q1.Print();
    q1.Front();
    q1.Empty();
    q1.Front();
    cout << endl;

    cout << "List Testing" << endl;
    List test;
    test.Append(1);
    test.Print();
    test.Append(23);
    test.Print();
    test.Size();
    test.Append(97);
    test.Print();
    test.Delete(23);
    test.Print();
    test.Reverse();
    test.Print();
    test.Append(96);
    test.Append(92);
    test.Append(99);
    test.Append(34);
    test.Append(973);
    test.Print();
    test.Reverse();
    test.Print();
    test.Size();

    return 0;
}