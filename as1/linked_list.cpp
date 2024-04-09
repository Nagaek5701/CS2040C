#include "linked_list.h"
#include <stdexcept>

// Returns the value at head
int List::head() {
	if (m_head != nullptr) {
		return m_head->element;
	}
	else
		throw std::out_of_range("List is empty!");
}
 
// Checks whether the container is empty
bool List::empty() const {
	return m_head == nullptr;
}

// Returns the number of elements
size_t List::size() const {
  // TODO: Implement this method
	return m_size;
}
 
// Inserts an element to the head
void List::push_head(int element) {
	Node* temp = new Node(element,m_head); //creating a new node and allocating memory using 'new' and point it to first node
	m_head = temp;//point the head to the new node
	m_size++;//increment the size of the LL by 1
}

// Removes the head element and returns it
int List::pop_head() {
	if (m_size > 0) {  //checking if there is even anything to pop or not
		Node* temp = m_head;//creating a temp pointer to the first node
		int output = temp->element;//retrieving the element first
		m_head = m_head->next;//pointing the head to the 2nd node (skipping the one that we're deleting)
		delete temp; //destroying the first node to free up the memory
		m_size--;//decreasing the size of LL by 1
		return output;
	}
	else
		return NULL; //not sure if returning NULL works here, have to throw an exception here.

}

// Checks whether the container contains the specified element
bool List::contains(int element) const {
	Node* temp = m_head;//create a temp pointer that points to first node
	while (temp != nullptr) { //making sure there is a next node to traverse to
		if (temp->element != element) { //checking if current node contains element
			temp = temp->next;//point to the next node!
		}
		else if (temp->element == element) { // returns true if element is contained within LL
			return true;
		}
	}
	return false; //returns false if after traversing entire LL, element not inside  
}

// Returns a std::string equivalent of the container
std::string List::to_string() const {
	std::string output = "{"; //creating an empty string as output first
	if (m_size > 0) { //checking if there even are any elements to output
		Node* temp = m_head; //temp pointer that points to head
		while (temp->next != nullptr) { //while not at last node
				output += std::to_string(temp->element) + ", "; //converting each node element to string and appending to output with ", "
				temp = temp->next; //point to the next 
		}
		output += std::to_string(temp->element); //adding the element of the last node
		return output + "}"; //return final output  
	}
	return "{}"; //returns an empty list "{}" if there are no nodes at all
}

//Copy constructor :
List::List(const List& obj) {

	this->m_size = obj.m_size;
	

	if (obj.m_head != nullptr) { //checking if copied list is empty

		Node* temp = new Node(obj.m_head->element);
		while (temp != nullptr) {
			push_head(temp->element);
			temp = temp->next;
		}

	}
	else {
		this->m_head = nullptr;
	}
	

}

//Destructor :
List::~List() {

	Node* temp = m_head; //temp ptr that points to the first node

	while (temp != nullptr) {
		Node* deleteDis = temp; //create a pointer that points to node that we want to delete
		temp = temp->next; //point to next node
		delete deleteDis; //blow up the train carrage
	}
	

}