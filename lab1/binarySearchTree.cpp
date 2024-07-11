#include <iostream>
#include <functional>

using namespace std;

class BSTree{
    public:
    struct Node{
        int data;
        Node *left;
        Node *right;
    };

    Node *createNode(int data){
        Node *newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    Node *insert(Node *root, int data){
        if(root == NULL){
            root = createNode(data);
            return root;
        }
        if(data < root->data){
            root->left = insert(root->left, data);
        }
        else if(data > root->data){
            root->right = insert(root->right, data);
        }
        return root;
    }

    Node *search(Node *root, int data){
        if(root == NULL || root->data == data){
            return root;
        }
        if(root->data < data){
            return search(root->right, data);
        }
        return search(root->left, data);
    }

    Node *searchIterative(Node *root, int data){
        while(root != NULL && root->data != data){
            if(root->data < data){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return root;
    }
};

long long getTime(std::function<void()> f){
    auto start = clock();
    f();
    auto end = clock();
    long double duration = end - start;
    return (duration/CLOCKS_PER_SEC) * 1000000000;
}

long long getSearchTime(std::function<BSTree::Node*()> f){
    auto start = clock();
    f();
    auto end = clock();
    long double duration = end - start;
    return (duration/CLOCKS_PER_SEC) * 1000000000;
}

int main(){
    auto insertAndSearch = [&](){
        BSTree bst;
        BSTree::Node *root = NULL;
        bst.createNode(4);
        bst.insert(root, 2);
        bst.insert(root, 10);
        bst.insert(root, 1);
        bst.insert(root, 5);
        bst.insert(root, 6);
        bst.insert(root, 7);
        bst.insert(root, 8);
        BSTree::Node *search = bst.search(root, 3);
        BSTree::Node *searchIterative = bst.searchIterative(root, 3);
        searchIterative ? cout << "Element found" << endl : cout << "Element not found" << endl;

    };
    cout << "Time taken to insert 8 elements and search: \n" << getTime(insertAndSearch) << "ns" << endl;
    
}