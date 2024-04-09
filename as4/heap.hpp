#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef HEAPHPP
#define HEAPHPP

#define DEFAULTHEAPSIZE 1023

template <class T>
class Heap {
 protected:
  T* _heap;
  int heap_size;
  

 public:
     Heap() { _heap = new T[DEFAULTHEAPSIZE]; heap_size = 0;}

  int size() const {
    // TODO: implement this
    return heap_size;
  }

  bool empty() const {
    // TODO: implement this
    return (heap_size==0);
  }
  void insert(const T&);
  T extractMax();
  T peekMax() const;
  void printHeapArray() const;
  void printTree() const;
  void changeKey(const T& from, const T& to);
  void deleteItem(const T&);

  ~Heap() { delete[] _heap; };

private:
    //helper functions:
    int _parent(int index);
    int _left(int index);
    int _right(int index);
    void _bubbleUp(int index);
    void _bubbleDown(int index);
    bool _isLeaf(int index);
    int _findIndex(const T& key);

};

template <class T>
int Heap<T>::_parent(int index) {
    return (floor((index - 1) / 2));
}

template <class T>
int Heap<T>::_left(int index) {
    return ((2 * index) + 1);
}

template <class T>
int Heap<T>::_right(int index) {
    return ((2 * index) + 2);
}

template <class T>
void Heap<T>::_bubbleUp(int index) {

    
    //Getting parent index:
    int parent_index = _parent(index);
    //Checking if parent index is larger:
    while (_heap[index] > _heap[parent_index]){
            //swap:
            T temp = _heap[index]; //temp storing current item
            _heap[index] = _heap[parent_index]; //replacing current item w parent
            _heap[parent_index] = temp; //replacing parent with current

        
            
            //change current to parent:
            index = parent_index;
            parent_index = _parent(index);
    }



}
template <class T>
bool Heap<T>::_isLeaf(int index) {
    //checking the index has both children with indices > heap_size:
    if (_left(index) >= heap_size && _right(index) >= heap_size) {
        return true;
    }
    else
        return false;

}

template <class T>
void Heap<T>::_bubbleDown(int index) {

    while (!_isLeaf(index)) {
        //finding left and right child:
        T left_P = _heap[_left(index)];
        T right_P = _heap[_right(index)];

        //checking for bigger child:
        int biggerChild = left_P > right_P ? _left(index) : _right(index);

        //Maintaining heap invariant:
        if (_heap[biggerChild] > _heap[index]) {

            //swap current index with bigger child:

            T temp = _heap[index]; //temp var to store current index
            _heap[index] = _heap[biggerChild]; //set current index to bigger child item
            _heap[biggerChild] = temp; //set item of bigger child index to old parent item

            //Moving down:
            index = biggerChild; 
        }
        else
            return;
    }
    



}


template <class T>
void Heap<T>::insert(const T& item) {
  // TODO: implement this
    
    //Insert the item into heap;
    _heap[heap_size] = item;

    //Maintain heap invariant:
    _bubbleUp(heap_size); //bubbleUp newly inserted item
    
    //increase the heap size:
    heap_size++;

}

template <class T>
T Heap<T>::extractMax() {
  // TODO: implement this
    if (heap_size == 0) {
        throw std::out_of_range("Heap is empty.");
    }
    else {
        T currentMax = _heap[0]; //storing current max 
        _heap[0] = _heap[heap_size-1]; //swapping root with last inserted 
        heap_size--; //decreasing heap_size
        _bubbleDown(0); // _bubbleDown the current root to maintain invariant
        

        return currentMax; //return the extracted maximum

    }
        
}

template <class T>
T Heap<T>::peekMax() const {
  // TODO: What happens if the heap is empty?
    if (heap_size == 0) {
        throw std::out_of_range("The heap is empty");
    }
    return _heap[0];
};

template <class T>
void Heap<T>::printHeapArray() const {
  for (int i = 0; i < size(); i++) {
    cout << _heap[i] << " ";
  }
  cout << endl;
}

template <class T>
int Heap<T>::_findIndex(const T& key) {

    int keyIndex = -1;
    //start from root:
    for (int i = 0; i < heap_size; i++) {
        if (_heap[i] == key) {
            keyIndex = i;
        }
    }
    //return -1 as index if key doesn't exist;
    return keyIndex;


    //while (currentIndex < heap_size) {
    //    if (_heap[currentIndex] == key) {
    //        return currentIndex;
    //    }
    //    else if (_heap[_left(currentIndex)] < key && _heap[_right(currentIndex)] < key) {//since this is a max heap, we can stop if both children < key
    //        return -1; //key does not exist in heap
    //    }
    //    else {
    //        currentIndex++; //increment through the heap
    //    }
    //}
}

template <class T>
void Heap<T>::changeKey(const T& from, const T& to) {
  // TODO: implement this
    if (heap_size >= 0) {

        //find current index
        int currentIndex = _findIndex(from);

        // maintaining invariant:
        if (currentIndex != -1) { //if key exists in heap
            //update:
            _heap[currentIndex] = to;

            if (from > to) { //key decreased => bubbledown
                _bubbleDown(currentIndex);
            }
            else if (to > from) { //key increased ==> bubbleup
                _bubbleUp(currentIndex);
            }
        }
    }
 
    
}

template <class T>
void Heap<T>::deleteItem(const T& x) {
  // TODO: implement this
    if (heap_size > 0) {

        // Find index of item to delete:
        int deleteIndex = _findIndex(x);

        //checking if the item exists:
        if (deleteIndex != -1) {

            //swap with x with last element;
            _heap[deleteIndex] = _heap[heap_size - 1];


            //maintaing invariant:
            if (_heap[deleteIndex] > x) { //if last element > x, need to bubble up
                _bubbleUp(deleteIndex);
            }
            else {
                _bubbleDown(deleteIndex);
            }

            //decreasing the size:
            heap_size--;
        }
       
    }
    
}

template <class T>
void Heap<T>::printTree() const {
  int parity = 0;
  if (size() == 0) return;
  int space = pow(2, 1 + (int)log2f(size())), i;
  int nLevel = (int)log2f(size()) + 1;
  int index = 0, endIndex;
  int tempIndex;

  for (int l = 0; l < nLevel; l++) {
    index = 1;
    parity = 0;
    for (i = 0; i < l; i++) index *= 2;
    endIndex = index * 2 - 1;
    index--;
    tempIndex = index;
    while (index < size() && index < endIndex) {
      for (i = 0; i < space - 1; i++) cout << " ";
      if (index == 0)
        cout << "|";
      else if (parity)
        cout << "\\";
      else
        cout << "/";
      parity = !parity;
      for (i = 0; i < space; i++) cout << " ";
      index++;
    }
    cout << endl;
    index = tempIndex;
    while (index < size() && index < endIndex) {
      for (i = 0; i < (space - 1 - ((int)log10(_heap[index]))); i++)
        cout << " ";
      cout << _heap[index];
      for (i = 0; i < space; i++) cout << " ";
      index++;
    }

    cout << endl;
    space /= 2;
  }
}

#endif
