#include<iostream>
using namespace std;

class Queue{
private:
    int *arr;
    int capacity;
    int front;
    int rear;
    int size;
public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    ~Queue(){
        delete[] arr;
    }
    void enqueue(int data);
    void dequeue();
    void display();
    bool isFull();
    bool isEmpty();
    int getFront();
    int getRear();

};

void Queue::enqueue(int data){
    if(isFull()){
        cout << "Queue Overflow." << endl;
    }else{; 
        arr[++rear] = data;
        size++;
    }
}

void Queue::dequeue(){
    if (isEmpty()) {
        cout << "Queue Underflow." << endl;
    } else {
        cout << "Dequeued element: " << arr[front] << endl;
        front++; 
        size--; 
    }
}

void Queue::display(){
    cout << "The elements of the queue are: " << endl;
    for(int i = 0; i < size; i++){
        cout << "Queue[" << i << "] :" <<arr[i]<< endl;
    }
}

bool Queue::isFull(){
    return (size == capacity);
}

bool Queue::isEmpty(){
    return (size == 0);
}

int Queue::getFront(){
    if(isEmpty()){
        cout << "Queue is Empty." << endl;
        return -1; 
    }else{
        return arr[front];
    }
}

int Queue::getRear(){
    if(isEmpty()){
        cout << "Queue is Empty." << endl;
        return -1; 
    }else{
        return arr[rear];
    }
}



int main()
{
    int capacity, choice;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;
    
    Queue q(capacity);

    do{
        cout<<"\nChoose an option from the menu below:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Get Front" << endl;
        cout << "7. Get Rear" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                int data;
                cout << "Enter the element to enqueue: ";
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                if(q.isFull()){
                    cout << "Queue is Full." << endl;
                }else{
                    cout << "Queue is not Full." << endl;
                }
                break;
            case 5:
                if(q.isEmpty()){
                    cout << "Queue is Empty." << endl;
                }else{
                    cout << "Queue is not Empty." << endl;
                }
                break;
            case 6:
                cout << "Front element: " << q.getFront() << endl;
                break;
            case 7:
                cout << "Rear element: " << q.getRear() << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }while(choice != 0);
    return 0;
}