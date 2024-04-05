#include "LS.h"
#include "Queue.h"

using namespace std;

int main() {

  // Loading the queue with some elements
  queue<int> Q;
  Q.push(7);
  Q.push(9);
  Q.push(19);
  Q.push(49);
  Q.push(31);
  Q.push(22);
  Q.push(67);
  Q.push(27);
  Q.push(69);
  Q.push(32);

  cout << "\nPrinted Queue: " << endl;
  // Printing the elements of the queue
  while (!Q.empty()) {
    cout << Q.front() << endl;
    Q.pop();
  }

  // Initializing an example vector
  vector<int> vec = {1, 2, 3, 4, 5, 2, 5, 6};
  cout << "\nLast occurrence of 2 in [1,2,3,4,5,2,5,6]: index ";
  // Finding the last occurrence of '2' in the vector using linear search
  cout << linear_search(vec, 2, vec.size() - 1);

  cout << "\n\nUnsorted List:" << endl;
  // Creating an unsorted linked list and adding elements to it
  linkedList list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  list.push_back(2);
  list.push_back(5);
  list.push_back(6);
  list.print(); // Printing the unsorted list

  cout << "\n\nSorted List: " << endl;
  // Sorting the linked list using insertion sort algorithm
  list.insertionSort();
  list.print(); // Printing the sorted list
  return 0;
}
