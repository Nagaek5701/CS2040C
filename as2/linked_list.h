#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <initializer_list>
#include <string>
template <typename T> struct Node {
    T element;
    Node<T>* next;
    Node(T element) : element{ element }, next{ nullptr } {}
    Node(T element, Node<T>* next) : element{ element }, next{ next } {}
};
template <typename T> class List {
private:
    size_t m_size;
    Node<T>* m_head;
    // Feel free to add helper functions here, if necessary
public:
    // Constructs an empty container
    List() : m_size{ 0 }, m_head{ nullptr } {}
    // Constructs the container with the contents of the initializer list
    List(std::initializer_list<T> init_list) : m_size{ 0 }, m_head{ nullptr } {
        auto it = init_list.end();
        while (--it != init_list.begin()) {
            push_head(*it);
        }
        push_head(*it);
    }
    // Rule of three:
    // If a class requires a user-defined destructor, a user-defined copy
    // constructor, or a user-defined copy assignment operator, it almost
    // certainly requires all three.
    // Destructor
    ~List() {
        // TODO: (Optional) Implement this method
    }
    // Copy constructor
    List(const List<T>& other) {
        // TODO: (Optional) Implement this method
    }
    // Copy assignment
    List<T>& operator=(const List<T>& other) {
        // TODO: (Optional) Implement this method
    }
    // Returns the contents of the head node
    const T& head() {
        if (m_size <= 0) {
            throw std::out_of_range("List is empty");
        }
        return m_head->element;
    }
    // Checks whether the container is empty
    bool empty() const { return m_size == 0; }
    // Returns the number of elements
    size_t size() const { return m_size; }
    // Inserts an element to the head
    void push_head(const T& element) {
        Node<T>* node = new Node<T>{ element, m_head };
        m_head = node;
        m_size++;
    }
    // Removes the head element
    void pop_head() {
        if (m_size <= 0) {
            throw std::out_of_range("List is empty");
        }
        Node<T>* node = m_head;
        m_head = m_head->next;
        delete node;
        m_size--;
    }
    // Checks whether the container contains the specified element
    bool contains(const T& element) const {
        if (m_size > 0) {
            Node<T>* temp = m_head; //temp node pointer that points to the head
            while (temp != nullptr) {
                if (temp->element != element) {
                    temp = temp->next; //iterating through the nodes
                }
                else if (temp->element == element) { //checking if element is in list
                    return true;
                }
            }
        }
        else
            return false; //return false if the element is not in list
    }
    // Extracts the maximum element from the container
    T extract_max() {
        if (m_size > 0) {
            Node<T>* temp = m_head; //temp head pointer
            Node<T>* output = m_head; //output pointer that points to the node with the max element
            Node<T>* prev = nullptr; //to keep track of the prev node
            while (temp != nullptr) {
                if (output->element < temp->element) {
                    output = temp; // changes output to point at the node before current max element node.
                    //Previous should not move here since it should still be pointing to the node before the max node.
                    temp = temp->next; //iterate to next node
                }
                else
                    prev = temp; // iterates the previous temp
                    temp = temp->next;
            }
            T max = output->element; //stores the max element in variable
            prev->next = output->next; //points the prev node to the node after max.
            delete output; //removes the node
            return max; //returns the max element
        }
        else {
            throw std::out_of_range("List is empty");
        }

    }
    // Reverse the container
    void reverse() {
        if (m_size > 0) {
            //Node<T>* head = m_head; //node pointer that points to the old head, to keep track;
            Node<T>* next = nullptr; //next pointer to keep track of the next node
            Node<T>* current = m_head;//current pointer that starts from the head;
            Node<T>* previous = nullptr;
            while (current != nullptr) {
                next = current->next; //point the next pointer to the next node;
                current->next = previous; //flips the current node's next pointer to point in reverse.
                previous = current; //moves the previous pointer s.t old current node = previous node.
                current = next; //sets the next node as the current node
            }
            //still need to assign the old tail node as the new head node using the head pointer from eariler:
            m_head = previous; //point the old head pointer to the new head ( old tail );
        }
        return;

    }
    // Returns a std::string equivalent of the container
    std::string to_string() const {
        std::string output = "{";
        if (m_size > 0) {
            Node<T>* temp = m_head; //temp node pointer that points to head
            while (temp->next != nullptr) { //iterating through list
                output += std::to_string(temp->element) + ", "; //coverting <T> to string and adding to output
                temp = temp->next;
            }
            output += std::to_string(temp->element); //adding element of last node;
            return (output + "}");
        }
        else
            return "{}";
    }
};
template <> inline //specialized to_string() to handle char linked lists
std::string List<std::string>::to_string() const {
    std::string output = "{";
    if (m_size > 0) {
        Node<std::string>* temp = m_head; //temp node pointer that points to head
        while (temp->next != nullptr) { //iterating through list
            output += "\"" + (temp->element) + "\", "; //concat strings and adding to output
            temp = temp->next;
        }
        output += "\"" + (temp->element) + "\""; //adding element of last node;
        return (output + "}");
    }
    else
        return "{}";
}
#endif