#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

struct PrintJob
{
    int jobID;
    string userName;
    string documentName;
    int pages;
};

class PrintQueue
{

private:
    PrintJob jobs[MAX_SIZE];

    int front;
    int rear;

public:
    // Constructor
    PrintQueue()
    {
        front = -1;
        rear = -1;
    }

    // Add a new print job
    void enqueue(PrintJob job)
    {

        // TODO:
        // 1. Check whether queue is full.
        if (isFull())
        {
            cout << "\nQueue is full! Cannot add job.";
            return;
        }
        // 2. Handle the first insertion.
        if (isEmpty())
        {
            front = 0;
        }
        // 3. Increment rear.
        rear = (rear + 1) % MAX_SIZE;
        // 4. Store the job.
        jobs[rear] = job;
        cout << "\nJob added.";
    }

    // Process the next print job
    PrintJob dequeue()
    {

        PrintJob job;

        // TODO:
        // 1. Check whether queue is empty.
        if (isEmpty())
        {
            cout << "\nQueue is empty! No job to process.";
            return job;
        }
        // 2. Store the job at front.
        job = jobs[front];
        // 3. Increment front.
        // 4. Reset front and rear if queue becomes empty.
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        // 5. Return the removed job.
        return job;
    }

    // View the next print job
    PrintJob getFront()
    {

        PrintJob job;

        // TODO:
        // 1. Check whether queue is empty.
        if (isEmpty())
        {
            cout << "\nQueue is empty! No next job.";
            return job;
        }
        // 2. Return the job at front.
        job = jobs[front];
        return job;
    }

    // Check whether queue is empty
    bool isEmpty()
    {

        // TODO:
        // Return true if queue contains no jobs.
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Check whether queue is full
    bool isFull()
    {

        // TODO:
        // Return true if queue has reached MAX_SIZE.
        if ((rear + 1) % MAX_SIZE == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Display all pending jobs
    void display()
    {

        // TODO:
        // 1. Check whether queue is empty.
        if (isEmpty())
        {
            cout << "\nNo pending jobs.";
            return;
        }
        // 2. Traverse from front to rear.
        // 3. Display details of every print job.
        int i = front;
        while (true)
        {
            cout << "\nJob ID: " << jobs[i].jobID
                 << " | User: " << jobs[i].userName
                 << " | Document: " << jobs[i].documentName
                 << " | Pages: " << jobs[i].pages;
            if (i == rear)
            {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
    }

    // Calculate total pages waiting to be printed
    int totalPages()
    {

        int total = 0;

        // TODO:
        // Traverse all jobs from front to rear.
        // Add the number of pages of each job.
        if (isEmpty())
        {
            return 0;
        }
        int i = front;
        while (true)
        {
            total += jobs[i].pages;
            if (i == rear)
            {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }

        return total;
    }

    void cancelJob(int jobID)
    {
        if (isEmpty())
        {
            cout << "\nQueue is empty! Nothing to cancel.";
            return;
        }

        int i = front;
        bool found = false;
        while (true)
        {
            if (jobs[i].jobID == jobID)
            {
                found = true;
                break;
            }
            if (i == rear)
            {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }

        if (!found)
        {
            cout << "\nJob not found.";
            return;
        }

        while (i != rear)
        {
            int next = (i + 1) % MAX_SIZE;
            jobs[i] = jobs[next];
            i = next;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
        }
        cout << "\nJob cancelled.";
    }
};

int main()
{

    PrintQueue queue;

    int choice;

    do
    {

        cout << "\n======================================";
        cout << "\n      UNIVERSITY PRINTING SYSTEM";
        cout << "\n======================================";

        cout << "\n1. Add Print Job";
        cout << "\n2. Process Next Job";
        cout << "\n3. View Next Job";
        cout << "\n4. Display Pending Jobs";
        cout << "\n5. Display Total Pages";
        cout << "\n6. Check Queue Status";
        cout << "\n7. Exit";
        cout << "\n8. Cancel Job";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {

            PrintJob job;

            cout << "\nEnter Job ID: ";
            cin >> job.jobID;

            cout << "Enter User Name: ";
            cin >> job.userName;

            cout << "Enter Document Name: ";
            cin >> job.documentName;

            cout << "Enter Number of Pages: ";
            cin >> job.pages;

            // TODO:
            // Call enqueue(job)
            queue.enqueue(job);

            break;
        }

        case 2:
        {

            // TODO:
            // Call dequeue()
            // Display the processed job.
            if (queue.isEmpty())
            {
                cout << "\nQueue is empty! No job to process.";
            }
            else
            {
                PrintJob job = queue.dequeue();
                cout << "\nProcessed -> Job ID: " << job.jobID
                     << " | User: " << job.userName
                     << " | Document: " << job.documentName
                     << " | Pages: " << job.pages;
            }

            break;
        }

        case 3:
        {

            // TODO:
            // Call getFront()
            // Display the next job.
            if (queue.isEmpty())
            {
                cout << "\nQueue is empty! No next job.";
            }
            else
            {
                PrintJob job = queue.getFront();
                cout << "\nNext -> Job ID: " << job.jobID
                     << " | User: " << job.userName
                     << " | Document: " << job.documentName
                     << " | Pages: " << job.pages;
            }

            break;
        }

        case 4:

            // TODO:
            // Call display()
            queue.display();

            break;

        case 5:

            // TODO:
            // Call totalPages()
            // Display the result.
            cout << "\nTotal pages waiting: " << queue.totalPages();

            break;

        case 6:

            // TODO:
            // Display whether queue is:
            // Empty
            // Partially occupied
            // Full
            if (queue.isEmpty())
            {
                cout << "\nQueue is Empty";
            }
            else if (queue.isFull())
            {
                cout << "\nQueue is Full";
            }
            else
            {
                cout << "\nQueue is Partially occupied";
            }

            break;

        case 7:

            cout << "\nExiting Printing System...";

            break;

        case 8:
        {

            int id;
            cout << "\nEnter Job ID to cancel: ";
            cin >> id;
            queue.cancelJob(id);

            break;
        }

        default:

            cout << "\nInvalid choice!";
        }

    } while (choice != 7);

    return 0;
}