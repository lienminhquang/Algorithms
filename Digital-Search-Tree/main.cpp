#include <iostream>

using namespace std;

struct  Node{

    Node(int x):
        key(x),
        left(nullptr),
        right(nullptr){}

    int key;
    Node* left, *right;
};

Node* insert(int key, Node* root)
{

    if(root == nullptr)
        return new Node(key);

    Node* rs = root;

    int b = 1 << (sizeof(int) - 1);
    Node* prev = nullptr;
    while(root != nullptr)
    {
        prev = root;
        if(root->key == key) return rs;
        if(key & b)
            root = root->right;
        else
            root = root->left;
        b >>= 1;
    }

    Node* n = new Node(key);
    b <<= 1;
    if(key & b)
        prev->right = n;
    else
        prev->left = n;

    return rs;
}

Node* search(int key, Node* root)
{
    int mask = 1 << (sizeof(int) - 1);
    while(root != nullptr)
    {
        if(root->key == key)
            return root;
        if(key & mask) root = root->right;
        else root = root->left;
        mask >>= 1;
    }

    return nullptr;
}


void print_odered(Node* root)
{
    if(root == nullptr) return;
    print_odered(root->left);
    cout << root->key << " ";
    print_odered(root->right);
}


Node* delete_key(int key, Node* root)
{
    if(root == nullptr) return nullptr;
    int mask = 1 << (sizeof(int) - 1);
    Node* n = root;
    Node* prev = nullptr;
    while(n != nullptr)
    {
        if(n->key == key) break;

        prev = n;
        if(key & mask) n = n->right;
        else n = n->left;
        mask >>= 1;
    }

    if(n == nullptr) return root;
    if(n->left == nullptr && n->right == nullptr)
    {
        if(n == root)
        {
            delete root;
            return nullptr;
        }

        mask <<= 1;
        if(mask & key)
        {
            prev->right = nullptr;
        }
        else
            prev->left = nullptr;
        delete n;
        return root;
    }

    prev = nullptr;
    Node* child = n;

    while(child->left != nullptr || child->right != nullptr)
    {
        prev = child;
        if(child->left != nullptr) child = child->left;
        else child = child->right;
    }

    n->key = child->key;
    if(prev->left == child)
    {
        prev->left = nullptr;
        delete child;
    }
    else{
        prev->right = nullptr;
        delete child;
    }

    return root;
}


int main()
{
    Node* root = nullptr;
    root = insert(6,root);
    root = insert(5, root);
    root = insert(2, root);
    root = insert(7, root);
    root = insert(8, root);
    root = insert(10, root);
    root = insert(12, root);
    root = insert(11, root);
    root = insert(4, root);

    print_odered(root);

    Node* rs = search(1, root);
    cout << "Search for 1: " << (rs == nullptr ? -9999 : rs->key) << "\n";
    rs = search(2, root);
    cout << "Search for 2: " << (rs == nullptr ? -9999 : rs->key) << "\n";
    rs = search(11, root);
    cout << "Search for 11: " << (rs == nullptr ? -9999 : rs->key) << "\n";

    cout << "\nDelete---1\n";
    root = delete_key(1, root);
    print_odered(root);
    cout << "\nDelete---2\n";
    root = delete_key(2, root);
    print_odered(root);
    cout << "\nDelete---6\n";
    root = delete_key(6, root);
    print_odered(root);

    return 0;
}
