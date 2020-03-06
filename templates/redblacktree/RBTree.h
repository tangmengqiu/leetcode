#ifndef RBTREE_H_
#define RBTREE_H_

enum color{RED,BLACK,DOUBLE_BLACK};

struct Node {
    int data;
    int color;
    Node *left,*right,*parent;

    explicit Node(int val);
};

class RBTree{
public:
    RBTree();
    void insertValue(const int& v);
    void deleteValue(const int& v);
    void merge(RBTree& rbt);
    void inOrder();
    void preOrder();

protected:
    void rotateLeft(Node *& node);
    void rotateRight(Node *& node);
    void fixInsertRBTree(Node *& node);
    void fixDeleteRBTree(Node *& node);
    void inOrderBST( Node *& node);
    void preOrderBST( Node *& node);
    int getColor(Node *& node);
    void setColor(Node *& node,int color);
    Node* minValueNode( Node *& node);
    Node* maxValueNode( Node *& node);
    Node* insertBST(Node *&root,Node *& node);
    Node* deleteBST(Node *&root ,const int& v);
    int getBlackHeight(Node * node);

private:
    Node *root;
};

#endif