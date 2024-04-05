#include <iostream>

using namespace std;

// Structure for a node in the linked list
template<typename T>
struct node{
    T data; 
    node* next; 
    node(T d){
        data = d;
        next = nullptr; 
    }
};

// Template class for implementing a queue
template <typename T>
class queue {
private:
    int currSize = 0; 
    node<T>* head = nullptr; 
    node<T>* tail = nullptr; 
public:
    void push(T); 
    void pop(); 
    T front() { return head->data;} 
    int size() { return currSize;} 
    bool empty(){return currSize == 0;} 
    void moveToRear(); 
};

// Class for implementing a linked list
class linkedList {
private:
    node<int>* headPtr; 
    node<int>* tailPtr; 
    int size = 0; 
public:
    linkedList(); 
    void insertionSort(); 
    void push_back(int); 
    void print();
    bool empty(); 
};

// Function to push an element into the queue
template <typename T>
void queue<T>::push(T value){
    if(head == nullptr){ // If the queue is empty
        head = new node<T>(value); 
        tail = head;
    }
    else{
        node<T>* temp = new node<T>(value); 
        tail->next = temp; 
        tail = temp; 
    }
    currSize += 1; 
}

// Function to pop an element from the queue
template<typename T>
void queue<T>::pop() {
    node<T>* temp = head->next;
    delete head; 
    head = temp;
    currSize -= 1; 
}

// Function to move the front element to the rear of the queue
template<typename T>
void queue<T>::moveToRear() {
    push(front()); 
    pop(); 
}

// Constructor for the linked list
linkedList::linkedList(){
    headPtr = nullptr; 
    tailPtr = nullptr; 
    size = 0; 
}

// Function to add an element at the end of the linked list
void linkedList::push_back(int value){
    node<int>* temp = new node<int>(value); 
    temp->data = value; 
    if(headPtr != nullptr){
        tailPtr->next = temp;
        temp->next = nullptr; 
        tailPtr = temp;
    }
    else{
        headPtr = temp; 
        tailPtr = temp;
    }
    size++; 
}

// Function to print the elements of the linked list
void linkedList::print(){
    node<int>* temp = headPtr; 
    while(temp != nullptr){ 
        cout << temp->data << " "; 
        temp = temp->next; 
    }
}

// Function to check if the linked list is empty
bool linkedList::empty() {
    if(headPtr == nullptr) // If head pointer is nullptr, list is empty
        return true;
    else
        return false;
}

// Function to perform insertion sort on the linked list
void linkedList::insertionSort() {
    node<int>* start = new node<int>(-1); 
    start->next = headPtr; 
    node<int>* cur = headPtr; 
    node<int>* prev = start; 

    while (cur) { // Loop until end of the list
        if (cur->next && cur->next->data < cur->data) { 
            while (prev->next && prev->next->data < cur->next->data) {
                prev = prev->next; 
            }
            node<int>* temp = prev->next;
            prev->next = cur->next; 
            cur->next = cur->next->next;
            prev->next->next = temp;

            prev = start; 
        } else {
            cur = cur->next; 
        }
    }
}
