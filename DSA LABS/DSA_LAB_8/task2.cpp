#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Order {
    double price;      // key
    int quantity;
    int orderId;
};

struct AVLNode {
    Order data;
    int height = 1;
    AVLNode *left = nullptr, *right = nullptr;
    AVLNode(Order o) : data(o) {}
};

class OrderBook {
    AVLNode* root = nullptr;
    int rotationCount = 0;

    int h(AVLNode* n) { return n ? n->height : 0; }
    int balance(AVLNode* n) { return n ? h(n->left) - h(n->right) : 0; }
    void update(AVLNode* n) { n->height = 1 + max(h(n->left), h(n->right)); }

    AVLNode* rotateRight(AVLNode* y) {             // Task 1
        AVLNode* x = y->left;
        AVLNode* t2 = x->right;
        x->right = y;
        y->left = t2;
        update(y);
        update(x);
        rotationCount++;
        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {              // Task 1
        AVLNode* y = x->right;
        AVLNode* t2 = y->left;
        y->left = x;
        x->right = t2;
        update(x);
        update(y);
        rotationCount++;
        return y;
    }

    AVLNode* rebalance(AVLNode* n) {               // Task 2
        update(n);
        int b = balance(n);
        if (b > 1) {
            if (balance(n->left) < 0)
                n->left = rotateLeft(n->left);
            return rotateRight(n);
        }
        if (b < -1) {
            if (balance(n->right) > 0)
                n->right = rotateRight(n->right);
            return rotateLeft(n);
        }
        return n;
    }

    AVLNode* insert(AVLNode* n, Order o) {         // Task 2
        if (!n) return new AVLNode(o);
        if (o.price < n->data.price)      n->left  = insert(n->left, o);
        else if (o.price > n->data.price) n->right = insert(n->right, o);
        else { n->data.quantity += o.quantity; return n; }
        return rebalance(n);
    }

    AVLNode* minNode(AVLNode* n) {
        while (n->left) n = n->left;
        return n;
    }

    AVLNode* remove(AVLNode* n, double price) {    // Task 4
        if (!n) return nullptr;
        if (price < n->data.price)      n->left  = remove(n->left, price);
        else if (price > n->data.price) n->right = remove(n->right, price);
        else {
            if (!n->left)  { AVLNode* r = n->right; delete n; return r; }
            if (!n->right) { AVLNode* l = n->left;  delete n; return l; }
            AVLNode* s = minNode(n->right);
            n->data = s->data;
            n->right = remove(n->right, s->data.price);
        }
        return rebalance(n);
    }

    void destroy(AVLNode* n) {
        if (!n) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }

public:
    ~OrderBook() { destroy(root); }

    void placeOrder(Order o)   { root = insert(root, o); }
    void cancelOrder(double p) { root = remove(root, p); }

    Order bestBid() {                              // Task 3: highest price
        if (!root) return {0, 0, -1};
        AVLNode* n = root;
        while (n->right) n = n->right;
        return n->data;
    }

    Order bestAsk() {                              // Task 3: lowest price
        if (!root) return {0, 0, -1};
        return minNode(root)->data;
    }

    int height()    { return h(root); }
    int rotations() { return rotationCount; }

    void printLevels() {                           // Task 5
        if (!root) { cout << "(empty)\n"; return; }
        queue<AVLNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            cout << "Level " << level++ << ": ";
            for (int i = 0; i < sz; i++) {
                AVLNode* n = q.front(); q.pop();
                cout << n->data.price << "(q" << n->data.quantity << ") ";
                if (n->left)  q.push(n->left);
                if (n->right) q.push(n->right);
            }
            cout << "\n";
        }
    }
};

int main() {
    OrderBook ob;
    double prices[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++)
        ob.placeOrder({prices[i], 100 + i, i + 1});

    ob.printLevels();
    cout << "Height: " << ob.height() << ", rotations: " << ob.rotations() << "\n";
    cout << "Best bid: " << ob.bestBid().price << "\n";
    cout << "Best ask: " << ob.bestAsk().price << "\n";

    ob.cancelOrder(30);
    cout << "\nAfter cancelling 30:\n";
    ob.printLevels();
}