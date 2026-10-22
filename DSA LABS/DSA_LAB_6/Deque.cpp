#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 6;

struct Baggage
{
    int bagID;
    string passengerName;
    bool priority;
};

class Deque
{
private:
    Baggage bags[MAX_SIZE];

    int front;
    int rear;
    int count;

public:
    Deque()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty()
    {
        // TODO: Return true if deque is empty
        if (count == 0)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        // TODO: Return true if deque is full
        if (count == MAX_SIZE)
        {
            return true;
        }
        return false;
    }

    void insertFront(Baggage bag)
    {
        // TODO:
        // 1. Check if deque is full
        if (isFull())
        {
            cout << "The Deque is full. No Space remaining!!";
            return;
        }
        // 2. Move front circularly
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;
        // 3. Insert bag at front
        bags[front] = bag;
        // 4. Increase count
        count++;
    }

    void insertRear(Baggage bag)
    {
        // TODO:
        // 1. Check if deque is full
        if (isFull())
        {
            cout << "The Deque is full. No Space remaining!!";
            return;
        }
        // 2. Move rear circularly
        rear = (rear + 1 + MAX_SIZE) % MAX_SIZE;
        // 3. Insert bag at rear
        bags[rear] = bag;
        // 4. Increase count
        count++;
    }

    Baggage deleteFront()
    {
        Baggage temp;

        // TODO:
        // 1. Check if deque is empty
        if (isEmpty())
        {
            cout << "The Deque is Empty. No Bag remaining!!";
            return Baggage();
        }
        // 2. Store front bag
        temp = bags[front];
        // 3. Move front circularly
        front = (front + 1 + MAX_SIZE) % MAX_SIZE;
        // 4. Decrease count
        count--;
        // 5. Return removed bag

        return temp;
    }

    Baggage deleteRear()
    {
        Baggage temp;

        // TODO:
        // 1. Check if deque is empty
        if (isEmpty())
        {
            cout << "The Deque is Empty. No Bag remaining!!";
            return Baggage();
        }
        // 2. Store rear bag
        temp = bags[rear];
        // 3. Move rear circularly
        rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
        // 4. Decrease count
        count--;
        // 5. Return removed bag

        return temp;
    }

    Baggage getFront()
    {
        // TODO: Return front bag
        return bags[front];
    }

    Baggage getRear()
    {
        // TODO: Return rear bag
        return bags[rear];
    }

    void display()
    {
        // TODO:
        // Display all bags from front to rear
                if (isEmpty())
        {
            cout << "The Deque is Empty. No Bag remaining!!";
            return;
        }
        int current = front;
        for (int i = 0 ; i < count ; i++){
            cout << bags[current].passengerName << " ";
            current = (current + 1) % MAX_SIZE;
        }

    }
};

void displayBag(Baggage bag)
{
    cout << "Bag ID: " << bag.bagID
         << ", Passenger: " << bag.passengerName
         << ", Priority: "
         << (bag.priority ? "Yes" : "No")
         << endl;
}

int main()
{

    Deque airport;

    Baggage b;

    // Normal bags enter from rear
    airport.insertRear({101, "Ali", false});
    airport.insertRear({102, "Sara", false});
    airport.insertRear({103, "Ahmed", false});

    // Priority bag enters from front
    airport.insertFront({200, "Hina", true});

    cout << "\nCurrent Baggage Queue:\n";
    airport.display();

    // Process front bag
    cout << "\nProcessing Front Bag:\n";
    b = airport.deleteFront();
    displayBag(b);

    // Process rear bag
    cout << "\nProcessing Rear Bag:\n";
    b = airport.deleteRear();
    displayBag(b);

    cout << "\nUpdated Baggage Queue:\n";
    airport.display();

    return 0;
}