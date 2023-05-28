#include <bits/stdc++.h>
using namespace std;
#define ll long long

class tree
{
public:
    tree *left;
    tree *right;
    int data;
    tree(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

class threaded_tree
{
public:
    int data;
    bool left_child;
    bool right_child;
    threaded_tree *left;
    threaded_tree *right;
    threaded_tree(int data)
    {
        this->data = data;
        this->left_child = false;
        this->right_child = false;
        this->left = NULL;
        this->right = NULL;
    }
};

threaded_tree *enter_threaded_tree()
{
    ll n;
    cin >> n;
    vector<ll> store(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        ll mem;
        cin >> mem;
        store[i] = (mem);
    }
    threaded_tree *my_tree = new threaded_tree(store[1]);
    for (ll i = 1; i <= n; i++)
    {
        threaded_tree *temp_tree = my_tree;
        ll temp = i;
        stack<ll> direction;
        while (temp != 1)
        {
            if (temp % 2 == 0)
            {
                direction.push(0);
                temp = temp / 2;
            }
            else
            {
                direction.push(1);
                temp = (temp - 1) / 2;
            }
        }
        while (!direction.empty())
        {
            if (direction.top() == 0)
            {
                temp_tree = temp_tree->left;
            }
            else
            {
                temp_tree = temp_tree->right;
            }
            direction.pop();
        }
        if (2 * (i) <= n)
        {
            temp_tree->left = new threaded_tree(store[2 * i]);
            temp_tree->left_child = true;
        }
        else
        {
            temp_tree->left_child = false;
        }
        if ((2 * (i)) + 1 <= n)
        {
            temp_tree->right = new threaded_tree(store[(2 * i) + 1]);
            temp_tree->right_child = true;
        }
        else
        {
            temp_tree->right_child = false;
        }
    }
    return my_tree;
}

tree *enter_tree()
{
    ll n;
    cin >> n;
    vector<ll> store(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        ll mem;
        cin >> mem;
        store[i] = (mem);
    }
    tree *my_tree = new tree(store[1]);
    for (ll i = 1; i <= n; i++)
    {
        tree *temp_tree = my_tree;
        ll temp = i;
        stack<ll> direction;
        while (temp != 1)
        {
            if (temp % 2 == 0)
            {
                direction.push(0);
                temp = temp / 2;
            }
            else
            {
                direction.push(1);
                temp = (temp - 1) / 2;
            }
        }
        while (!direction.empty())
        {
            if (direction.top() == 0)
            {
                temp_tree = temp_tree->left;
            }
            else
            {
                temp_tree = temp_tree->right;
            }
            direction.pop();
        }
        if (2 * (i) <= n)
        {
            temp_tree->left = new tree(store[2 * i]);
        }
        if ((2 * (i)) + 1 <= n)
        {
            temp_tree->right = new tree(store[(2 * i) + 1]);
        }
    }
    return my_tree;
}

void print_tree(tree *main_tree)
{
    if (main_tree == NULL)
    {
        return;
    }
    print_tree(main_tree->left);
    cout << main_tree->data << " ";
    print_tree(main_tree->right);
}

void iterative_print_tree(tree *main_tree)
{
    stack<tree *> order;
    tree *curr = main_tree;
    while (curr != NULL || !order.empty())
    {
        while (curr != NULL)
        {
            order.push(curr);
            curr = curr->left;
        }
        curr = order.top();
        order.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void level_order_print_tree(tree *main_tree)
{
    queue<tree *> order;
    tree *curr = main_tree;
    order.push(main_tree);
    while (!order.empty())
    {
        ll size = order.size();
        while (size--)
        {
            cout << order.front()->data << " ";
            if (order.front()->left != NULL)
                order.push(order.front()->left);
            if (order.front()->right != NULL)
                order.push(order.front()->right);
            order.pop();
        }
    }
}

tree *copy_my_tree(tree *main_tree)
{
    queue<tree *> order;
    tree *curr = main_tree;
    order.push(main_tree);
    vector<ll> store;
    store.push_back(0);
    while (!order.empty())
    {
        ll size = order.size();
        while (size--)
        {
            store.push_back(order.front()->data);
            if (order.front()->left != NULL)
                order.push(order.front()->left);
            if (order.front()->right != NULL)
                order.push(order.front()->right);
            order.pop();
        }
    }
    ll n = store.size() - 1;
    tree *my_tree = new tree(store[1]);
    for (ll i = 1; i <= n; i++)
    {
        tree *temp_tree = my_tree;
        ll temp = i;
        stack<ll> direction;
        while (temp != 1)
        {
            if (temp % 2 == 0)
            {
                direction.push(0);
                temp = temp / 2;
            }
            else
            {
                direction.push(1);
                temp = (temp - 1) / 2;
            }
        }
        while (!direction.empty())
        {
            if (direction.top() == 0)
            {
                temp_tree = temp_tree->left;
            }
            else
            {
                temp_tree = temp_tree->right;
            }
            direction.pop();
        }
        if (2 * (i) <= n)
        {
            temp_tree->left = new tree(store[2 * i]);
        }
        if ((2 * (i)) + 1 <= n)
        {
            temp_tree->right = new tree(store[(2 * i) + 1]);
        }
    }
    return my_tree;
}

bool are_my_trees_equal(tree *first_tree, tree *second_tree)
{
    return ((!first_tree && !second_tree) || (first_tree && second_tree && (first_tree->data == second_tree->data) && are_my_trees_equal(first_tree->left, second_tree->left) && are_my_trees_equal(first_tree->right, second_tree->right)));
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
}

tree *max_heap()
{
    ll n;
    cin >> n;
    int store[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        ll mem;
        cin >> mem;
        store[i] = (mem);
    }
    heapsort(store, n + 1);
    tree *my_tree = new tree(store[1]);
    for (ll i = 1; i <= n; i++)
    {
        tree *temp_tree = my_tree;
        ll temp = i;
        stack<ll> direction;
        while (temp != 1)
        {
            if (temp % 2 == 0)
            {
                direction.push(0);
                temp = temp / 2;
            }
            else
            {
                direction.push(1);
                temp = (temp - 1) / 2;
            }
        }
        while (!direction.empty())
        {
            if (direction.top() == 0)
            {
                temp_tree = temp_tree->left;
            }
            else
            {
                temp_tree = temp_tree->right;
            }
            direction.pop();
        }
        if (2 * (i) <= n)
        {
            temp_tree->left = new tree(store[2 * i]);
        }
        if ((2 * (i)) + 1 <= n)
        {
            temp_tree->right = new tree(store[(2 * i) + 1]);
        }
    }
    return my_tree;
}

tree *find_node(tree *main_tree)
{
    cout << "enter the element nigaaaa !!!!! " << endl;
    ll x;
    cin >> x;
    tree *temp_tree = main_tree;
    while (temp_tree != NULL)
    {
        if (x > temp_tree->data)
        {
            temp_tree = temp_tree->right;
        }
        else if (x < temp_tree->data)
        {
            temp_tree = temp_tree->left;
        }
        else if (x == temp_tree->data)
        {
            break;
        }
    }
    return temp_tree;
}

tree *insertIntoBST(tree *root, int val)
{
    tree *temp_node = root;
    if (root == NULL)
    {
        tree *newNode = new tree(val);
        root = newNode;
        return root;
    }
    while (true)
    {
        if (temp_node->data < val)
        {
            if (temp_node->right == NULL)
            {
                break;
            }
            else
            {
                temp_node = temp_node->right;
            }
        }
        else if (temp_node->data > val)
        {
            if (temp_node->left == NULL)
            {
                break;
            }
            else
            {
                temp_node = temp_node->left;
            }
        }
    }
    tree *newNode = new tree(val);
    if (val > temp_node->data)
    {
        temp_node->right = newNode;
    }
    else
    {
        temp_node->left = newNode;
    }
    return root;
}

tree *deleteNode_from_BST(tree *root, int key)
{
    tree *temp = root;
    tree *parent = root;
    while (temp != NULL)
    {
        if (temp->data > key)
        {
            temp = temp->left;
        }
        else if (temp->data < key)
        {
            temp = temp->right;
        }
        else if (temp->data == key)
        {
            break;
        }
    }
    if (temp == NULL)
    {
        return root;
    }
    else
    {
        if (parent == temp)
        {
            if (temp->right == NULL && temp->left == NULL)
            {
                return NULL;
            }
            else if (temp->right == NULL && temp->left != NULL)
            {
                return temp->left;
            }
            else if (temp->right != NULL && temp->left == NULL)
            {
                return temp->right;
            }
            else if (temp->right != NULL && temp->left != NULL)
            {
                tree *traverse = temp->right;
                while (traverse->left != NULL)
                {
                    traverse = traverse->left;
                }
                traverse->left = temp->left;
                return temp->right;
            }
        }
        while (parent != NULL)
        {
            if (parent->right == temp || parent->left == temp)
            {
                break;
            }
            else if (parent->data < temp->data)
            {
                parent = parent->right;
            }
            else if (parent->data > temp->data)
            {
                parent = parent->left;
            }
        }
        if (parent->left == temp)
        {
            if (temp->right == NULL)
            {
                parent->left = temp->left;
            }
            else
            {
                parent->left = temp->right;
                tree *traverse = temp->right;
                while (traverse->left != NULL)
                {
                    traverse = traverse->left;
                }
                traverse->left = temp->left;
            }
        }
        else if (parent->right == temp)
        {
            if (temp->left == NULL)
            {
                parent->right = temp->right;
            }
            else
            {
                parent->right = temp->left;
                tree *traverse = temp->left;
                while (traverse->right != NULL)
                {
                    traverse = traverse->right;
                }
                traverse->right = temp->right;
            }
        }
        return root;
    }
}

int main()
{
    tree *main_tree;
    main_tree = enter_tree();
    // print_tree(main_tree);
    // cout << endl;
    // iterative_print_tree(main_tree);
    // cout << endl;
    // level_order_print_tree(main_tree);
    // cout << endl;
    // tree *copy_tree = copy_my_tree(main_tree);
    // print_tree(copy_tree);
    // cout << endl;
    // if (are_my_trees_equal(main_tree, copy_tree))
    // {
    // cout << "TRUE" << endl;
    // }
    // else
    // {
    // cout << "FALSE" << endl;
    // }
    // main_tree = max_heap();
    // to insert or delete, simply insert/delete that element from the heap and then heapify it.
    // print_tree(main_tree);
    // cout << endl;
    // tree *my_node = find_node(main_tree);
    // if (my_node == NULL)
    // {
    //     cout << "data not found !!" << endl;
    // }
    // else
    // {
    //     cout << my_node->data << endl;
    // }
}