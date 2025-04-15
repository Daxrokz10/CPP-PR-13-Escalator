#include<iostream>
using namespace std;

// Stack class definition
class Stack {
    public:
        int data;       // Data to be stored in the stack
        int top;        // Index of the top element
        int capacity;   // Maximum capacity of the stack
        int* arr;       // Dynamic array to store stack elements

    // Constructor to initialize the stack
    Stack(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1; // Stack is initially empty
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Function declarations
    bool isFull();
    bool isEmpty();
    void push(int data);
    void pop();
    void peek();
    void display();
};

// Function to push an element onto the stack
void Stack::push(int data) {
    if (isFull()) {
        cout << "Stack Overflow." << endl;
    } else {
        arr[++top] = data; // Increment top first, then assign the value
    }
}

// Function to pop an element from the stack
void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is Empty." << endl;
    } else {
        top--; // Decrement top to remove the top element
    }
}

// Function to display all elements in the stack
void Stack::display() {
    cout << "The elements of the stack are: " << endl;
    for (int i = 0; i <= top; i++) {
        cout << "Stack[" << i << "] :" << arr[i] << endl;
    }
}

// Function to display the top element of the stack
void Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is Empty." << endl;
    } else {
        cout << "The top element in the stack is: " << arr[top] << endl;
    }
}

// Function to check if the stack is full
bool Stack::isFull() {
    return (top == capacity - 1);
}

// Function to check if the stack is empty
bool Stack::isEmpty() {
    return (top == -1);
}

// Main function
int main() {
    int choice;    // Variable to store user choice
    int capacity;  // Variable to store stack capacity

    // Prompt user to enter the capacity of the stack
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;

    // Create a stack object with the given capacity
    Stack s(capacity);

    // Menu-driven program
    do {
        // Display menu options
        cout << "\nChoose an option from the menu below:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Check if Empty" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform actions based on user choice
        switch (choice) {
            case 1: {
                // Push an element onto the stack
                int data;
                cout << "Enter the element to be pushed: ";
                cin >> data;
                s.push(data);
                break;
            }
            case 2:
                // Pop an element from the stack
                s.pop();
                break;
            case 3:
                // Display the top element of the stack
                s.peek();
                break;
            case 4:
                // Display all elements in the stack
                s.display();
                break;
            case 5:
                // Check if the stack is full
                if (s.isFull()) {
                    cout << "The stack is full." << endl;
                } else {
                    cout << "The stack is not full." << endl;
                }
                break;
            case 6:
                // Check if the stack is empty
                if (s.isEmpty()) {
                    cout << "The stack is empty." << endl;
                } else {
                    cout << "The stack is not empty." << endl;
                }
                break;
            case 0:
                // Exit the program
                cout << "Exiting..." << endl;
                break;
            default:
                // Handle invalid input
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0); // Repeat until the user chooses to exit

    return 0;
}