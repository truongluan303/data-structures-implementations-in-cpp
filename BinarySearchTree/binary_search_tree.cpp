#include <vector>
#include <queue>

using namespace std;


template <typename T>
class BinarySearchTree
{
private:

    struct Node
    {
        T value;
        Node* left;
        Node* right;
    }

    Node* head;

    int size;

    void delete_subtree(Node* root);

    vector<T> preorder_helper(Node* root, vector<T> result);

    vector<T> inorder_helper(Node* root, vector<T> result);

    vector<T> postorder_helper(Node* root, vector<T> result);


public:

    BinarySearchTree();

    ~BinarySearchTree();

    void add(T value);

    bool remove(T value);

    bool contains(T value);

    vector<vector<T>> level_order_traversal();

    vector<T> preorder_traversal();

    vector<T> inorder_traversal();

    vector<T> postorder_traversal();
}



template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    head = NULL;
    size = 0;
}



template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    delete_subtree(root);
}



template <typename T>
void BinarySearchTree::delete_subtree(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    delete_subtree(root->left);
    delete_subtree(root->right);
    
    delete root;
}



template <typename T>
void BinarySearchTree<T>::add(T value)
{
    Node* new_node = new Node();
    new_node->value = value;

    if (root == NULL)
    {
        root = new_node;
    }
    else
    {
        Node* current = root;
        while (true)
        {
            if (value <= current->value)
            {
                if (current->left == NULL)
                {
                    current->left = new_node;
                    break;
                }
                current = current->left;
            }
            else
            {
                if (current->right == NULL)
                {
                    current->right = new_node;
                    break;
                }
                current = current->right;
            }
        }
    }
    size++;
}



template <typename T>
void BinarySearchTree<T>::remove(T value)
{

}


template <typename T>
bool BinarySearchTree<T>::contains(T value)
{
    Node* current = root;
    while (current != NULL)
    {
        if (value < current->value)
        {
            current = current->left;
        }
        else if (value > current->value)
        {
            current = current->right;
        }
        else
        {
            return true;
        }
    }
    return false;
}



template <typename T>
vector<vector<T>> BinarySearchTree<T>::level_order_traversal()
{
    vector<vector<T>> result;
    queue<Node*> q;

    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<T> level(size);

        for (int i = 0; i < size; i++)
        {
            Node* current = q.pop();
            level[i] = current->value;

            if (current->left != NULL)
            {
                q.push(current->left);
            }            
            if (current->right != NULL)
            {
                q.push(current->right);
            }
        }
        result.push_back(level);
    }
    return result;
}


template <typename T>
vector<T> BinarySearchTree<T>::preorder_traversal()
{
    vector<T> result;
    preorder_helper(root, result);
    return result;
}


template <typename T>
vector<T> BinarySearchTree<T>::preorder_helper(Node* root, vector<T> result)
{
    result.push_back(root->value);
    preorder_helper(root->left, result);
    preorder_helper(root->right, result);
}
