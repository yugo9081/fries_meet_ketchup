#include <iostream>
#include <string>

#ifndef HEAP_HPP
#define HEAP_HPP

using namespace std;

struct Node
{
  string restaurant;
  double rating;
  int key; //count ++

};

struct Node2
{
  string name;
  string face;
  string job;
  string gender;
  string age;
  string interset1;
  string interset2;
  string city;
  string realAge;

};

class Heap {
private:
  Node* priorityQueue; //pointer to the array used to implement priority queue
  int currentQueueSize;
  int maxQueueSize;

  void repairUpward(int);
  void repairDownward(int);

public:
  Heap(int queueSize);
  ~Heap();
  void enqueue(string,double);
  void dequeue();
  Node peek();
  bool isFull();
  bool isEmpty();
  void printArray(int n);



};

#endif
