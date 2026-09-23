#include <iostream>
#include <string>
using namespace std;

// ============================================
// Node Definition
// ============================================

struct Node
{
    int patientID;
    string name;
    int age;
    string problem;

    Node *next;
};

// ============================================
// Function 1: Register Normal Patient
// Insert a new patient at the END
// ============================================

void addPatient(Node *&head)
{
    // Step 1: Create a new node dynamically
    Node *newNode = new Node();

    // Step 2: Get patient information from user

    cout << "Enter Patient ID :";
    cin >> newNode->patientID;
    cin.ignore();

    cout << "Enter patient Name: ";
    getline(cin, newNode->name);

    cout << "Enter Patient Age :";
    cin >> newNode->age;
    cin.ignore();

    cout << "Enter Patient Problem/Diagnosis: ";
    getline(cin, newNode->problem);

    // Step 3: Set next pointer to NULL
    newNode->next = nullptr;

    // Step 4: Check whether the list is empty
    if (!head)
    {
        head = newNode;
        cout << "Patient added successfully at the end of the queue.\n";
        return;
    }

    // Step 5: If list is not empty,
    //         traverse to the last node

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    // Step 6: Connect the last node to newNode
    current->next = newNode;
    cout << "Patient added successfully at the end of the queue.\n";
}

// ============================================
// Function 2: Register Emergency Patient
// Insert a new patient at the BEGINNING
// ============================================

void addEmergencyPatient(Node *&head)
{
    // Step 1: Create a new node
    Node *newNode = new Node();

    // Step 2: Get patient information
    cout << "Enter Patient ID :";
    cin >> newNode->patientID;
    cin.ignore();

    cout << "Enter patient Name: ";
    getline(cin, newNode->name);

    cout << "Enter Patient Age :";
    cin >> newNode->age;
    cin.ignore();

    cout << "Enter Patient Problem/Diagnosis: ";
    getline(cin, newNode->problem);

    // Step 3: Make newNode point to current head

    newNode->next = head;

    // Step 4: Update head
    head = newNode;
    cout << "EMERGENCY patient added successfully to the front of the queue!\n";
}

// ============================================
// Function 3: Serve Next Patient
// Delete the FIRST node
// ============================================

void servePatient(Node *&head)
{
    // Step 1: Check whether the list is empty
    if (head == nullptr)
    {
        cout << "No Patients listed!!";
        return;
    }

    // Step 2: Store the current head in a temporary pointer

    Node *temp = head;

    // Step 3: Display patient information
    cout << "\n-------------Patient's Information:---------------------------- \n";
    cout << "Patient ID: " << temp->patientID << endl;
    cout << "Name: " << temp->name << endl;
    cout << "Age: " << temp->age << endl;
    cout << "Problem/Diagnosis: " << temp->problem << endl;

    // Step 4: Move head to the next node
    head = head->next;

    // Step 5: Delete the old first node
    delete temp;
}

// ============================================
// Function 3: Delete Appointment
// Delete the node
// ============================================

void cancelAppointment(Node *&head, int id)
{

    if (!head)
    {
        cout << "Nothing to delete, List is already empty!!";
        return;
    }

    if (head->patientID == id)
    {
        Node *temp = head;
        head = temp->next;
        delete temp;
        return;
    }

    Node *current = head;
    Node *prev = nullptr;
    while (current != nullptr && current->patientID != id)
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Value " << id << " not found in the list!" << endl;
        return;
    }
    prev->next = current->next;
    delete current;
    cout << "Appointment of Patient ID: " << id << " Cancelled!!";
}

// ============================================
// Function 4: Display Waiting Patients
// Traverse the complete list
// ============================================

void displayPatients(Node *head)
{
    // Step 1: Check whether the list is empty
    if (head == nullptr)
    {
        cout << "No Patients listed!!";
        return;
    }

    // Step 2: Create a traversal pointer
    Node *current = head;

    // Step 3: Traverse until current becomes NULL
    while (current != nullptr)
    {
        // Step 4: Display patient information
        cout << "\n-------------Patient's Information:---------------------------- \n";
        cout << "Patient ID: " << current->patientID << endl;
        cout << "Name: " << current->name << endl;
        cout << "Age: " << current->age << endl;
        cout << "Problem/Diagnosis: " << current->problem << endl;

        // Step 5: Move current to the next node
        current = current->next;
    }
}

// ============================================
// Function 5: Search Patient
// Search using Patient ID
// ============================================

void searchPatient(Node *head, int id)
{
    // Step 1: Start traversal from head
    Node *current = head;

    // Step 2: Compare current patient's ID with id
    while (current != nullptr && current->patientID != id)
    {
        current = current->next;
    }

    // Step 3: If found, display patient inforc
    if (current != nullptr)
    {
        cout << "\n-------------Patient's Information:---------------------------- \n";
        cout << "Patient ID: " << current->patientID << endl;
        cout << "Name: " << current->name << endl;
        cout << "Age: " << current->age << endl;
        cout << "Problem/Diagnosis: " << current->problem << endl;
    }
    else
    {
        cout << "Patient Not found!!";
    }
}

// ===============================================================
// Function 8: clearing the list before exiting the function
// ===============================================================
void clearList(Node *&head)
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

int main()
{
    Node *head = nullptr;
    int choice = 0;

    do
    {
        cout << "\n============================================\n";
        cout << "       PATIENT MANAGEMENT SYSTEM MENU\n";
        cout << "============================================\n";
        cout << "1. Register Normal Patient (Insert at End)\n";
        cout << "2. Register Emergency Patient (Insert at Head)\n";
        cout << "3. Serve Next Patient (Remove First Node)\n";
        cout << "4. Display Waiting Patients\n";
        cout << "5. Search Patient\n";
        cout << "6. Cancel Patient Appointment\n";
        cout << "7. Count Waiting Patients\n";
        cout << "8. Exit\n";
        cout << "--------------------------------------------\n";
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid input! Please enter a number from 1 to 8.\n";
            continue;
        }

        cin.ignore();

        switch (choice)
        {
        case 1:
            addPatient(head);
            break;

        case 2:
            addEmergencyPatient(head);
            break;

        case 3:
            servePatient(head);
            break;

        case 4:
            displayPatients(head);
            break;

        case 5:
        {
            if (head == nullptr)
            {
                cout << "\nThe queue is empty.\n";
            }
            else
            {
                int id;
                cout << "Enter Patient ID to search: ";
                cin >> id;
                searchPatient(head, id);
            }
            break;
        }

        case 6:
        {
            if (head == nullptr)
            {
                cout << "\nThe queue is empty.\n";
            }
            else
            {
                int id;
                cout << "Enter Patient ID to cancel: ";
                cin >> id;
                cancelAppointment(head, id);
            }
            break;
        }

        case 7:
        {
            int count = 0;
            Node *current = head;
            while (current != nullptr)
            {
                count++;
                current = current->next;
            }
            cout << "\nTotal waiting patients: " << count << "\n";
            break;
        }

        case 8:
            // Free memory before exiting program
            clearList(head);
            cout << "\nExiting system. All allocated memory cleaned up. Goodbye!\n";
            break;

        default:
            cout << "\nInvalid choice! Please select a valid option from 1 to 8.\n";
        }

    } while (choice != 8);

    return 0;
}