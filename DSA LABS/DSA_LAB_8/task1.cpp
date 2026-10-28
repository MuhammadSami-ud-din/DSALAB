#include <iostream>
#include <string>
using namespace std;

struct Book {
    long long isbn;
    string title;
    string author;
    int copies;
};

struct Node {
    Book data;
    Node *left = nullptr, *right = nullptr;
    Node(Book b) : data(b) {}
};

class Catalog {
    Node* root = nullptr;

    // ---- Task 1 helpers ----
    Node* insert(Node* n, const Book& b) {
        if (!n) return new Node(b);
        if (b.isbn < n->data.isbn)      n->left  = insert(n->left, b);
        else if (b.isbn > n->data.isbn) n->right = insert(n->right, b);
        else                            n->data.copies += b.copies; // duplicate ISBN: add copies
        return n;
    }

    Node* find(Node* n, long long isbn) {
        if (!n || n->data.isbn == isbn) return n;
        return isbn < n->data.isbn ? find(n->left, isbn) : find(n->right, isbn);
    }

    // ---- Task 2 helper ----
    void inorder(Node* n) {
        if (!n) return;
        inorder(n->left);
        cout << n->data.isbn << " | " << n->data.title << " | "
             << n->data.author << " | copies: " << n->data.copies << "\n";
        inorder(n->right);
    }

    // ---- Task 3 helper ----
    void range(Node* n, long long lo, long long hi) {
        if (!n) return;
        if (lo < n->data.isbn) range(n->left, lo, hi);   // prune: left only if it can hold >= lo
        if (lo <= n->data.isbn && n->data.isbn <= hi)
            cout << n->data.isbn << " | " << n->data.title << " | "
                 << n->data.author << " | copies: " << n->data.copies << "\n";
        if (n->data.isbn < hi) range(n->right, lo, hi);  // prune: right only if it can hold <= hi
    }

    // ---- Task 4 helpers ----
    Node* minNode(Node* n) {
        while (n->left) n = n->left;
        return n;
    }

    Node* remove(Node* n, long long isbn, bool& removed) {
        if (!n) return nullptr;
        if (isbn < n->data.isbn)      n->left  = remove(n->left, isbn, removed);
        else if (isbn > n->data.isbn) n->right = remove(n->right, isbn, removed);
        else {
            removed = true;
            if (!n->left)  { Node* r = n->right; delete n; return r; } // 0 or 1 child (right)
            if (!n->right) { Node* l = n->left;  delete n; return l; } // 1 child (left)
            // 2 children: replace with in-order successor, then delete the successor
            Node* s = minNode(n->right);
            n->data = s->data;
            bool dummy;
            n->right = remove(n->right, s->data.isbn, dummy);
        }
        return n;
    }

    // ---- Task 5 helper ----
    int heightOf(Node* n) {
        if (!n) return 0;
        return 1 + max(heightOf(n->left), heightOf(n->right));
    }

    void destroy(Node* n) {
        if (!n) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }

public:
    ~Catalog() { destroy(root); }

    void addBook(const Book& b)        { root = insert(root, b); }                 // Task 1
    Node* findBook(long long isbn)     { return find(root, isbn); }                // Task 1
    void listAll()                     { inorder(root); }                          // Task 2
    void listRange(long long lo, long long hi) { range(root, lo, hi); }            // Task 3
    bool removeBook(long long isbn) {                                              // Task 4
        bool removed = false;
        root = remove(root, isbn, removed);
        return removed;
    }
    int height()                       { return heightOf(root); }                  // Task 5
};

int main() {
    Catalog c;
    c.addBook({500, "Book E", "Auth A", 2});
    c.addBook({300, "Book C", "Auth B", 1});
    c.addBook({700, "Book G", "Auth C", 4});
    c.addBook({200, "Book B", "Auth D", 3});
    c.addBook({400, "Book D", "Auth E", 1});
    c.addBook({600, "Book F", "Auth F", 2});

    cout << "All:\n";            c.listAll();
    cout << "\nRange 250-550:\n"; c.listRange(250, 550);
    cout << "\nFind 400: " << (c.findBook(400) ? "found" : "not found") << "\n";
    cout << "Remove 500: " << (c.removeBook(500) ? "ok" : "missing") << "\n";
    cout << "Remove 999: " << (c.removeBook(999) ? "ok" : "missing") << "\n";
    cout << "Height: " << c.height() << "\n";
}