#include <iostream>
#include <string>
using namespace std;

struct Node {
    string keyword, meaning;
    Node* left;
    Node* right;
    int height;

    Node(string key, string meaning) {
        this->keyword = key;
        this->meaning = meaning;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return root->height;
    }
}
Node* rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    
    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

void displayAscending(Node* root) {
    if (root) {
        displayAscending(root->left);
        cout << root->keyword << ": " << root->meaning << endl;
        displayAscending(root->right);
    }
}

void displayDescending(Node* root) {
    if (root) {
        displayDescending(root->right);
        cout << root->keyword << ": " << root->meaning << endl;
        displayDescending(root->left);
    }
}

bool search(Node* root, string key) {
    while (root != nullptr) {
        if (key == root->keyword) {
            cout << "FOUND: " << root->keyword << " → " << root->meaning << endl;
            return true;
        }
        if (key < root->keyword) {
            root = root->left;
        } else { 
            root = root->right;
        }
    }
    cout << "NOT FOUND: " << key << endl;
    return false;
}

int maxComparisons(Node* root) {
    return getHeight(root);
}

int main() {
    Node* root = new Node("Book", "A collection of pages");
    root->left = new Node("Apple", "A fruit");
    root->right = new Node("Dog", "An animal");
    root->right->right = new Node("Zoo", "A place with animals");

    cout << "Dictionary in ascending order:\n";
    displayAscending(root);

    cout << "\nDictionary in descending order:\n";
    displayDescending(root);

    string keyword = "Dog";
    cout << "\nSearching for '" << keyword << "': ";
    search(root, keyword);

    cout << "\nMaximum comparisons required for finding a keyword: " 
         << maxComparisons(root) << endl;

    return 0;
}
