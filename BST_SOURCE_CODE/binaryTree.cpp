#include <iostream>
using namespace std;

//node
struct Node{
    public:
    int key;
    Node *left, *right;

    Node(){
        left = right = NULL;
    }
};

class BST{
    public:
    Node *root;

    BST(){
        root = NULL;

    }
    Node *insertRec(int newKey, Node *currentRoot)
    {
    if (currentRoot == NULL)
    {
        Node *newNode = new Node();
        newNode->key = newKey;
        return newNode;
    }
    if(newKey < currentRoot->key)
    {
        currentRoot->left = insertRec(newKey, currentRoot->left);
    } else if (newKey > currentRoot->key)
    {
        currentRoot->right = insertRec(newKey, currentRoot->right);
    }
        return currentRoot;
    }

    void insert(int newKey){
        root =  insertRec(newKey, root);
    }

    Node *preOrderRec(Node *currentRoot)
    {
        if (currentRoot != NULL)
        {
            cout << currentRoot->key <<" ";
            preOrderRec(currentRoot->left);
            preOrderRec(currentRoot->right);

        }
        return currentRoot;
    
    }
    Node *inOrderRec(Node *currentRoot)
    {
        if (currentRoot != NULL)
        {
            preOrderRec(currentRoot->left);
            cout << currentRoot->key <<" ";
            preOrderRec(currentRoot->right);

        }
        return currentRoot;
    
    }
    Node *postOrderRec(Node *currentRoot)
    {
        if (currentRoot != NULL)
        {
            preOrderRec(currentRoot->left);
            preOrderRec(currentRoot->right);
            cout << currentRoot->key <<" ";

        }
        return currentRoot;
    
    }

    void preOrderTravelsal(){
        cout <<"Pre Oder Traversal: ";
        preOrderRec(root);
        cout << endl;
    }
    void inOrderTravelsal(){
        cout << "In Oder Traversal: ";
        inOrderRec(root);
        cout << endl;
    }
    void postOrderTravelsal(){
        cout <<"Post Oder Traversal: ";
        postOrderRec(root);
        cout << endl;
    }

};

int main(int argc, char** argv){

    BST *bin1 = new BST();
    
    bin1->insert(6);
    bin1->insert(7);
    bin1->insert(4);
    bin1->insert(5);
    bin1->insert(8);
    bin1->insert(3);

    bin1->preOrderTravelsal();
    bin1->inOrderTravelsal();
    bin1->postOrderTravelsal();

    return 0;
}