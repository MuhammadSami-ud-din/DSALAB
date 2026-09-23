#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void InsertAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void InsertAtPosition(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *current = head;

        if (pos < 0)
            return;

        if (pos == 0)
        {
            InsertAtHead(val);
            return;
        }

        for (int i = 0; i < pos - 2; i++)
        {
            if (current == nullptr)
            {
                cout << "Position out of bounds!!" << endl;
                return;
            }
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Position out of bounds!!" << endl;
            return;
        }

        Node *temp = current->next;
        current->next = newNode;
        newNode->next = temp;
    }

    void Delete()
    {

        if (!head)
        {
            cout << "Nothing to delete, List is already empty!!" << endl;
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *current = head;
        Node *prev = nullptr;
        while (current->next != nullptr)
        {
            prev = current;
            current = current->next;
        }
        prev->next = nullptr;
        delete current;
    }

    void DeleteAtNode(int val)
    {

        if (!head)
        {
            cout << "Nothing to delete, List is already empty!!" << endl;
            return;
        }

        if (head->data == val)
        {
            Node* temp = head;
            head = temp->next;
            delete temp;
            return;
        }

        Node *current = head;
        Node *prev = nullptr;
        while (current!= nullptr && current->data != val  )
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr){ 
            cout << "Value " << val << " not found in the list!" << endl;
            return;
        }
        prev->next = current->next;
        delete current;
    }

    void printList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void count()
    {
        Node *current = head;
        int count = 0;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }

        cout << "Total No. of Nodes are: " << count << endl;
    }
};

int main()
{
    LinkedList list;
    int choice, val, pos;

    do
    {
        cout << "\n-------------------MENU-------------------\n";
        cout << "1. Insert At Head\n";
        cout << "2. Insert At Position\n";
        cout << "3. Delete Last Node\n";
        cout << "4. Delete At Node (By Value)\n";
        cout << "5. Print List\n";
        cout << "6. Count Nodes\n";
        cout << "7. Exit\n";
        cout << "------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.InsertAtHead(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            cout << "Enter position: ";
            cin >> pos;
            list.InsertAtPosition(val, pos);
            break;

        case 3:
            list.Delete();
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> val;
            list.DeleteAtNode(val);
            break;

        case 5:
            list.printList();
            break;

        case 6:
            list.count();
            break;

        case 7:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!!" << endl;
        }

    } while (choice != 7);

    return 0;
}