#include <iostream>
#include <string>
using namespace std;

class BrowserStack
{
private:
    string history[10];
    int top;

public:
    BrowserStack()
    {
        top = -1;
    }

    // Add a webpage to browser history
    void push(string url)
    {
        // TODO: Check for stack overflow
        if (top == 9)
        {
            cout << "Stack history is full!!!";
            return;
        }

        // TODO: Add url to the stack
        // TODO: Update top
        history[++top] = url;
        cout << "Visited: " << url << endl;
    }

    // Go back to previous webpage
    string pop()
    {
        // TODO: Check for stack underflow
        if (isEmpty())
        {
            cout << "Stack history is Empty!!! No previous Page!";
            return " ";
        }
        // TODO: Store current webpage
        string page = history[top];
        // TODO: Decrease top
        top--;
        // TODO: Return webpage
        return page;
    }

    // Display current webpage
    string peek()
    {
        // TODO: Check whether stack is empty
        if (isEmpty())
        {
            cout << "Stack history is Empty!!!";
            return "";
        }
        // TODO: Return the top webpage

        return history[top];
    }

    // Check whether stack is empty
    bool isEmpty()
    {
        // TODO: Return true if stack is empty
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Display browsing history
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack history is Empty!!!";
            return;
        }
        // TODO: Display webpages from top to bottom
        cout << "\n-------------------WebBrowsing History----------------------------\n";
        for (int i = 9; i >= 0; i--)
        {
            if (history[i] == "")
        {
            continue; 
        }
            cout << "URL: " << history[i] << endl;
        }
        cout << "\n-------------------WebBrowsing History----------------------------\n";
    }
};

int main()
{
    BrowserStack browser;

    int choice;
    string url;

    do
    {
        cout << "\n===== Browser History =====\n";
        cout << "1. Visit New Webpage\n";
        cout << "2. Go Back\n";
        cout << "3. Current Webpage\n";
        cout << "4. Display History\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter webpage URL: ";
            cin >> url;

            // TODO: Call push()
            browser.push(url);
            break;

        case 2:
            // TODO: Call pop()
            cout << "Popped: " << browser.pop();
            break;

        case 3:
            // TODO: Call peek()
            cout << "Current Page: " << browser.peek() << endl;
            break;

        case 4:
            // TODO: Call display()
            browser.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
} 