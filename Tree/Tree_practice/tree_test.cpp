#include <bits/stdc++.h>

using namespace std;

// 트리만들기 -> 노드구현
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;

        left = NULL;
        right = NULL;
    }
};

main()
{
    // cout << "hello c world";
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    //    1
    //   / \
    //  2   3
    return 0;
}