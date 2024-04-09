#ifndef TREE_H
#define TREE_H

#include <algorithm>
#include <cassert>
#include <functional>
#include <string>

using std::string;

template <typename T>
std::string my_to_string(const T& t) {
  return std::to_string(t);
}

template <>
std::string my_to_string(const std::string& t) {
  return "\"" + t + "\"";
}

template <typename T> struct Node {
  T element;
  int height;
  Node<T> *left;
  Node<T> *right;

  Node(T element)
      : element{element}, height{0}, left{nullptr}, right{nullptr} {}
  Node(T element, int height)
      : element{element}, height{height}, left{nullptr}, right{nullptr} {}

};

template <typename T> class Tree {
private:
  size_t m_size;
  Node<T> *m_root;

public:
  // Constructor
  Tree();

  // Rule of three:
  // If a class requires a user-defined destructor, a user-defined copy
  // constructor, or a user-defined copy assignment operator, it almost
  // certainly requires all three.

  // Destructor
  ~Tree();

  // Returns a pointer to the root
  Node<T>* root();

  // Checks whether the tree is empty
  bool empty() const;

  // Returns the number of elements
  size_t size() const;

  // Returns the height of the tree
  int height() const;

  // Inserts the specified element
  void insert(T element);

  // Checks whether the container contains the specified element
  bool contains(T element) const;

  // Returns the maximum element
  T max() const;

  // Returns the minimum element
  T min() const;

  // Returns the successor of the specified element
  T successor(T element);

  // Convert each element in the tree to string in pre-order.
  string pre_order();

  // Convert each element in the tree to string in order.
  string in_order();

  // Convert each element in the tree to string in post-order.
  string post_order();

  // Returns a string equivalent of the tree
  string to_string(bool with_height = true) const {
    return m_to_string(with_height, m_root, 0);
  }

private:
  string m_to_string(bool with_height, Node<T> *node, int ident) const {
    string res;
    if (node == nullptr) {
      return res;
    }
    if (node->right != nullptr) {
      res += m_to_string(with_height, node->right, ident + 2);
    }
    for (int i = 0; i < ident; i++) {
      res += " ";
    }
    res += my_to_string(node->element);
    if (with_height) {
      res += "(h=" + my_to_string(node->height) + ")";
    }
    res += "\n";
    if (node->left != nullptr) {
      res += m_to_string(with_height, node->left, ident + 2);
    }
    return res;
  }

  // Feel free to declare helper functions here, if necessary
   Node<T>* _insert(Node<T>* current, T element);  //to implement helper function for insert()
   string _in_order(Node<T>* current); //to implement helper function for in_order()
   string _post_order(Node<T>* current); //to implement helper function for post_order()

   void _treeExplode(Node<T>* current); //tree destoryer for deconstructor

   //Balancing helper functions:

   void _updateHeight(Node<T>* current); //updates the height of current node

   int _balanceFactor(Node<T>* current); //returns the balance factor of the current node

   Node<T>* _rotateLeft(Node<T>* current); //performs left rotation on current node

   Node<T>* _rotateRight(Node<T>* current); //performs right rotation on current node

   int _getHeight(Node<T>* current); //returns the height of the current node.
  };

// Constructor
 template <typename T> Tree<T>::Tree() { m_root = NULL;  m_size = 0; }

//Tree Destoryer
template <typename T>
void Tree<T>::_treeExplode(Node<T>* current) {

    //delete nodes if current != null
    if (current != nullptr) {

        _treeExplode(current->left); //destory subtrees first
        _treeExplode(current->right);
        delete current;
    }
}

// Destructor
template <typename T> Tree<T>::~Tree() {
  //call _treeExplode on root:
    _treeExplode(m_root);
}


// Returns a pointer to the root
template <typename T> Node<T> *Tree<T>::root() {
    return m_root;
}

// Checks whether the tree is empty
template <typename T> bool Tree<T>::empty() const {
  // TODO: Implement this method
    return (m_size == 0);
}

// Returns the number of elements
template <typename T> size_t Tree<T>::size() const {
  // TODO: Implement this method
    return m_size;
}

// Returns the height of the tree
template <typename T> int Tree<T>::height() const {
  // TODO: Implement this method
    if (m_root == NULL) {
        return -1; //height of empty root = -1
    }
    else {
        return (m_root->height);
    }
    
}

//get node height:
template <typename T>
int Tree<T>::_getHeight(Node<T>* current) {

    return current == nullptr ? -1 : current->height;
    
}

//Update height of node
template <typename T>
void Tree<T>::_updateHeight(Node<T>* current) {
    
    

    ; //updates the current node height;
    int leftHeight = _getHeight(current->left);
    int rightHeight = _getHeight(current->right);

    if (leftHeight >= rightHeight) {
        current->height = leftHeight + 1;
    }
    else {
        current->height = rightHeight + 1;
    }

}

//Balance Factor checks the difference between left and right sub-tree heights
template <typename T>
int Tree<T>::_balanceFactor(Node<T>* current) {
    
    int leftHeight = _getHeight(current->left);
    int rightHeight = _getHeight(current->right);

    return (leftHeight - rightHeight);
    
}




// Inserts an element
template <typename T> void Tree<T>::insert(T element) {
    
    if (m_root != nullptr) { //if tree is not empty
        m_root = _insert(m_root, element); //calls _insert function on root
    }
    else {
        m_root = new Node<T>(element);
        _updateHeight(m_root);
        m_size++; //increment size by 1 for new root
    }
        
}

// Insert helper function:
template <typename T> 
Node<T>* Tree<T>::_insert(Node<T>* current, T element) {

    if (element > current->element) { // if the current node element is smaller larger than element being inserted

        //have to check right sub-tree
        if (current->right != nullptr) {// if right child exists
            current->right = _insert(current->right, element); //tries to insert element into right sub-tree
        }
        else {
            current->right = new Node<T>(element); //points the right child ptr to a new node with new element
            m_size++; //increases the size of tree;

        }
    }
    else if (current->element > element) { //if current node element is larger than element being inserted
        //check left sub-tree
        if (current->left != nullptr) {//if left child exists
            current->left = _insert(current->left, element); //tries to insert into left sub-tree

        }
        else {
            current->left = new Node<T>(element); //points the left child ptr to new node with new element
            m_size++; //increments size
        }
    }
    else
        return current;

    //Update height for each call of _insert() on the branch nodes;
    _updateHeight(current);
    

    //Balancing:

    //checking balance factor of node after insertion:
    int balanceFac = _balanceFactor(current);

    //case1: Node is left heavy:

    if (balanceFac > 1) {

        //subcase1 : checking if it's left child is right heavy or not:
        if (element > current->left->element) {

            //need to rotate the left child left first then rotate current
            current->left = _rotateLeft(current->left);
            current = _rotateRight(current);

        }
        //if left child is balanced or left heavy > rotate right
        else if (element < current->left->element) {
            current = _rotateRight(current); //just rotate right
        }
    }
 

    //case2 : Node is right heavy:
    
    else if (balanceFac < -1) {


        //subcase1: checking if right child is left heavy or not:
        if (element < current->right->element) {
            //need to right rotate right child
            current->right = _rotateRight(current->right);
            current = _rotateLeft(current);
        }
        else if (element > current->right->element) { //else if right child is balanced or right heavy
            current = _rotateLeft(current); //just rotate left 
        }
    }

    return current;
}

// rotation helper functions

template <typename T>
Node<T>* Tree<T>::_rotateLeft(Node<T>* current){
    //Since input is already the "parent" pointer, we can just do the rotation
    
    Node<T>* newRoot = current->right; //ptr to keep track of right child
    Node<T>* Temp = newRoot->left; //ptr to keep track of left child of new root;
    newRoot->left = current;//old root becomes left child of new root
    current->right = Temp; //set right child of old root as left child of new root

    _updateHeight(current); //update height of old root
    _updateHeight(newRoot); //update heights of new root

    return newRoot;

}
   


template <typename T>
Node<T>* Tree<T>::_rotateRight(Node<T>* current) {
    
    Node<T>* newRoot = current->left; //ptr to keep track of left child
    Node<T>* Temp = newRoot->right; //ptr to keep track of right child of new root;
    newRoot->right = current;//old root becomes right child of new root
    current->left = Temp; //set left child of old root as right child of new root
   
    _updateHeight(current); //update height of old root
    _updateHeight(newRoot); //update heights of new root

    return newRoot;

}

// Checks whether the container contains the specified element
template <typename T> bool Tree<T>::contains(T element) const {
  //start from the root:
    Node<T>* temp = m_root;

    while (temp != nullptr) { //going through sub-tree nodes
        if (temp->element == element) { //if root == element
            return true;
        }
        else if (element > temp->element) { //move down the right sub-tree if element > current node element;
            temp = temp->right;
        }
        else {
            temp = temp->left; //move down the left sub-tree otherwise
        }
    }
    return false; //return false if can't find element after navigating nodes.
}

// Returns the maximum element
template <typename T> T Tree<T>::max() const {
    if (m_size != 0) {
        //max element should be right most leaf:
        Node<T>* temp = m_root; // start from root
        while (temp->right != nullptr) {
            temp = temp->right; //go down right most branch
        }
        return temp->element;

    }
    throw std::out_of_range("Tree is empty");
  
}

// Returns the minimum element
template <typename T> T Tree<T>::min() const {
    if (m_size != 0) {
        //max element should be left most leaf:
        Node<T>* temp = m_root; //start from root
        while (temp->left != nullptr) {
            temp = temp->left; //go down left most branch
        }
        return temp->element;
    }
    throw std::out_of_range("Tree is empty");
}

// Returns the successor of the specified element
template <typename T> T Tree<T>::successor(T element) {
  // Need to find element first, and keep track of the last parent that went left if element node has no right child.
    Node<T>* temp = m_root; //start from root;
    Node<T>* output; //parent ptr to keep track of last right parent.

    //successor of max element doesnt exist;
    if (element == this->max()) {
        throw std::out_of_range("Max element does not have a successor");
    }

    while (temp != NULL) {

        //Searching for element in tree:
        if (temp->element == element && temp->right != nullptr) { //if current node = element -> check for right child
            //return smallest element of right sub-tree;
            temp = temp->right; //move right
            //find min of right sub-tree:
            while (temp != nullptr) {
                output = temp;
                temp = temp->left;
            }
        }

        else if (temp->element > element) { // if current node > element,
            //need to move left , plus take note of current node as last right parent
            output = temp;
            temp = temp->left; //moving left
        }

        else //(temp->element < element) { //element > current node 
            temp = temp->right; //search the right sub-tree
       

    }
    return output->element; //returns the last right parent if the element node has no right child;
}

template <typename T>
string _pre_order(Node<T> *node) {
  return my_to_string(node->element)
    + (node->left == nullptr ? "" : " " + _pre_order(node->left))
    + (node->right == nullptr ? "" : " " + _pre_order(node->right));
}

template <typename T>
string Tree<T>::pre_order() {
  if (m_root == nullptr) {
    return "";
  }
  return _pre_order(m_root);
}

template <typename T>
string Tree<T>::in_order() {
  // In order = left -> node - > right
    //call helper function on the root if the tree is not empty;
    if (m_root == nullptr) {
        return "";
    }
    string orderedStr = _in_order(m_root);
    //need to slice off last space
    string output = orderedStr.substr(0, orderedStr.size()-1);
    return output;
    
}

template <typename T>
string Tree<T>::_in_order(Node<T>* current) { //helper function for in_order
    //we need to print left subtree -> current -> right subtree
    return (current->left == nullptr ? "" : _in_order(current->left))
        + my_to_string(current->element) + " "
        + (current->right == nullptr ? "" : "" + _in_order(current->right));
}

template <typename T>
string Tree<T>::_post_order(Node<T>* current) {
    return (current->left == nullptr ? "" : _post_order(current->left))
        + (current->right == nullptr ? "" : _post_order(current->right)) + " "
        + my_to_string(current->element);
}

template <typename T>
string Tree<T>::post_order() {
  //left sub-tree -> right sub_tree -> current node
  
    if (m_root == nullptr) {
        return "";
    }
    //need to slice off first space
    string postStr = _post_order(m_root); //calling helper function on root
    string output = postStr.substr(1, postStr.size());
    return output;
}

#endif
