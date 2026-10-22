#include <iostream>
#include <string>
using namespace std;

const int MAX_PASSENGERS = 8;

struct Passenger {
    int passengerID;
    string name;
    int priority;
};

class BoardingQueue {
private:

    Passenger passengers[MAX_PASSENGERS];
    int count;

public:

    BoardingQueue() {
        count = 0;
    }

    bool isEmpty() {

        // TODO:
        // Return true if the queue is empty
        if (count == 0){
            return true;
        }

        return false;
    }

    bool isFull() {

        // TODO:
        // Return true if the queue is full
        if (count == MAX_PASSENGERS){
            return true;
        }

        return false;
    }

    void addPassenger(Passenger p) {

        // TODO:
        // 1. Check whether the queue is full.
        // 2. Find the correct position according
        //    to priority.
        // 3. Higher priority should come first.
        // 4. Shift passengers where necessary.
        // 5. Maintain arrival order for equal priorities.
        // 6. Insert the passenger.
        // 7. Increment count.
        if (isFull()) return;

        int i = count - 1;
        while (i >= 0 && passengers[i].priority < p.priority)
        {
            passengers[i + 1] = passengers[i];
            i--;
        }

        passengers[i + 1] = p;
        count++;
        

    }

    Passenger boardPassenger() {

        Passenger temp;

        // TODO:
        // 1. Check whether the queue is empty.
        if ( isEmpty()){
            return Passenger();
        }
        // 2. Store the first passenger.
        temp = passengers[0];
        // 3. Shift remaining passengers.
        for(int i=0 ; i<count-1 ; i++){
            passengers[i] = passengers[i+1];
        }
        // 4. Decrease count.
        count--;
        // 5. Return the passenger.



        return temp;
    }

    Passenger nextPassenger() {

        // TODO:
        // Return the first passenger
        return passengers[0];
    }

    void displayQueue() {

        // TODO:
        // Display all passengers
        // from highest to lowest priority.
        if (isEmpty()) {
            cout << "The Boarding Queue is Empty!" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            cout << "Passenger: " << passengers[i].name
                 << " | Priority: " << passengers[i].priority 
                 << endl;
        }

    }
};

void displayPassenger(Passenger p) {

    cout << "Passenger ID: " << p.passengerID
         << " | Name: " << p.name
         << " | Priority: " << p.priority
         << endl;
}

int main() {

    BoardingQueue boarding;

    // Passengers arriving at the boarding gate

    boarding.addPassenger({101, "Ali", 2});
    boarding.addPassenger({102, "Sara", 5});
    boarding.addPassenger({103, "Ahmed", 3});
    boarding.addPassenger({104, "Hina", 5});
    boarding.addPassenger({105, "Usman", 1});
    boarding.addPassenger({106, "Fatima", 4});

    cout << "\nCurrent Boarding Queue:\n";
    boarding.displayQueue();

    cout << "\nNext Passenger:\n";
    displayPassenger(boarding.nextPassenger());

    cout << "\nBoarding Passenger:\n";
    displayPassenger(boarding.boardPassenger());

    cout << "\nUpdated Boarding Queue:\n";
    boarding.displayQueue();

    return 0;
}