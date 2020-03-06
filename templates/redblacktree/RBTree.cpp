
#include "RBTree.h"
#include <iostream>
using namespace std;

Node::Node(int val){
    this->data=val;
    this->color =RED;
    this->left=this->right=this->parent=nullptr;
}

RBTree::RBTree():root(nullptr){}

int RBTree::getColor(Node *&node){
    if(node==nullptr) return BLACK;
    return node->color;
}

void RBTree::setColor(Node *&node,int color){
    if(node==nullptr) return;
    node->color=color;
}

Node* RBTree::insertBST(Node *&root,Node *&node){
    if(root==nullptr) return node;
    if(node ==nullptr) return root;
    if(node->data<root->data){
        root->left = insertBST(root->left,node);
        root->left->parent = root;
    }else if(node->data>root->data){
        root->right=insertBST(root->right,node);
        root->right->parent=root;
    }
    return root;
}

void RBTree::insertValue(const int& v){
    Node* node =new Node(v);
    root = insertBST(root,node);
    fixInsertRBTree(root);
}

void RBTree::rotateLeft(Node *&node){
    Node* right_child =node->right;
    node->right = right_child->left;
    if(node->right) node->right->parent =node;
    
    if(node->parent==nullptr) root = right_child;
    else if( node ==node->parent->left)
        right_child = node->parent->left;
    else 
        right_child = node->parent->right;
    
    right_child->parent= node->parent;
    right_child->left = node;
    node->parent = right_child;
}

void RBTree::rotateRight(Node *& node){
    Node *left_child = node->left;
    node->left = left_child->right;
    if(node->left) node->left->parent =node;

    if(node->parent==nullptr) root=left_child;
    else if(node->parent->left==node)
        node->parent->left=left_child;
    else 
        node->parent->right=left_child;
    left_child->parent = node->parent;
    left_child->right = node;
    node->parent =left_child;
}

void RBTree::fixInsertRBTree(Node *&node){
    Node *parent = nullptr;
    Node *grandParent =nullptr;
    while(node!=root&&getColor(node)==RED&&getColor(node->parent)==RED){
        parent = node->parent;
        grandParent = parent->parent;
        if(parent==grandParent->left){
            //left side
            Node *uncle = grandParent->right;
            if(getColor(uncle)==RED){
                //uncle is red
                //1.Change color of parent and uncle as BLACK.
                //2.color of grand parent as RED.
                //3.Change x = x’s grandparent, repeat steps 2 and 3 for new x.
                setColor(parent,BLACK);
                setColor(uncle,BLACK);
                setColor(grandParent,RED);
                node=grandParent;
            }else{
                //uncle is black
                if(node==parent->right){
                    //node is at the left-right side of his grandparent
                    //then left rotate hist parent
                    rotateLeft(parent);
                    node=parent;
                    parent=node->parent;
                }
                // node is at the left-left side of his grandparent
                //common operation on left-right and left-left
                rotateRight(parent);
                swap(parent->color,grandParent->color);
                node=parent;
            }
        }else{
            //right side
            Node *uncle =grandParent->left;
            if(getColor(uncle)==RED){
                setColor(grandParent,RED);
                setColor(uncle,BLACK);
                setColor(parent,BLACK);
                node= grandParent;
            }else{
                //uncle is black
                if(parent==grandParent->left){
                    rotateRight(parent);
                    node=parent;
                    parent=node->parent;
                }
                //right-right
                rotateLeft(parent);
                swap(parent->color,grandParent->color);
                node=parent;
            }
        }
    }
    setColor(root,BLACK);
}

void RBTree::fixDeleteRBTree(Node *&node){
    if(node==nullptr) return;
    if(node==root){
        root=nullptr;
        return;
    }
    //node that delete node is either a leaf node or an node has only one child

    if(getColor(node)==RED||getColor(node->left)==RED||getColor(node->left)==RED){
        // one is red and one is black
        Node* child = node->left!=nullptr?node->left:node->right;
        if(node==node->parent->left){
            node->parent->left = child;
            if(child) child->parent=node->parent;
            setColor(child,BLACK);
            delete(node);
        }else{
            node->parent->right=child;
            if(child) child->parent=node->parent;
            setColor(child,BLACK);
            delete(node);
        }
    }else{
        // u=black,v=black
        Node* sibling =nullptr;
        Node* parent =nullptr;
        Node* ptr=node;
        setColor(ptr,DOUBLE_BLACK);
        while(ptr!=root&&getColor(ptr)==DOUBLE_BLACK){
            parent =ptr->parent;
            if(parent->left==ptr){
                //delete node at left side
                sibling =parent->right;
                if(getColor(sibling)==RED){
                    //right side sibling is red
                    setColor(sibling,BLACK);
                    setColor(parent,RED);
                    rotateLeft(parent);
                }else{
                    if(getColor(sibling->left)==BLACK&&getColor(sibling->right)==BLACK){
                        // two nephews are black;
                        setColor(sibling,RED);
                        if(getColor(parent)==RED)
                            setColor(parent,BLACK);
                        else
                            setColor(parent,DOUBLE_BLACK);
                        ptr=parent;
                    }else{
                        // at least newphew is red
                        if(getColor(sibling->right)==BLACK){
                            //right-left(sibling) case
                            setColor(sibling->left,BLACK);
                            setColor(sibling,RED);
                            rotateRight(sibling);
                            sibling=parent->right;
                        }
                        //right-right(sibling) case
                        setColor(sibling,parent->color);
                        setColor(parent,BLACK);
                        setColor(sibling->right,BLACK);
                        rotateLeft(parent);
                        break;
                    }
                }
            }else{
                //delete node at right side,sibling at left
                sibling =parent->left;
                if(getColor(sibling)==RED){
                    //sibling is red
                    setColor(sibling,BLACK);
                    setColor(parent,RED);
                    rotateRight(parent);
                }else{
                    //sibling is black
                    if(getColor(sibling->right)==BLACK&&getColor(sibling->left)==BLACK){
                        //both newphew is black
                        setColor(sibling,BLACK);
                        if(getColor(parent)==RED)
                            setColor(parent,BLACK);
                        else 
                            setColor(parent,DOUBLE_BLACK);
                        ptr=parent;
                    }else{
                        //at least one nephew is red
                        if(getColor(sibling->left)==BLACK){
                            //left-right(sibling) case
                            setColor(sibling->right,RED);
                            setColor(sibling,RED);
                            rotateLeft(sibling);
                            sibling=sibling->left;
                        }
                        //left-left(sibling) case
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->left, BLACK);
                        rotateRight(parent);
                        break;
                    }
                }
            }
        }
        //delete node
        if(node==node->parent->left) node->parent->left=nullptr;
        else
            node->parent->right=nullptr;
        delete(node);
        setColor(root,BLACK);
    }//else u=black,v=black
}//func

Node* RBTree::deleteBST(Node *&root,const int& data){
    if(!root) return nullptr;
    if(data<root->data)
        return deleteBST(root->left,data);
    if(data>root->data)
        return deleteBST(root->right,data);
    // if target node is leaf node
    if(root->left==nullptr||root->right==nullptr)
        return root;
    // find the node in the right subtree with min value
    //repalce delete node value with the min value
    Node *temp=minValueNode(root->right);
    root->data=temp->data;
    // and the delete the min value in the right subtree
    return deleteBST(root->right,temp->data);

}

void RBTree::deleteValue(const int& data){
    cout<<"aaa"<<endl;
    Node *deleteNode = deleteBST(root,data);
    cout<<"bbb"<<endl;
    fixDeleteRBTree(deleteNode);
    cout<<"ccc"<<endl;
}

void RBTree::inOrderBST(Node *& root){
    if(!root) return;
    inOrderBST(root->left);
    cout<< "[ "<<root->data<<" "<<root->color<<" ] ";
    inOrderBST(root->right);
}
void RBTree::inOrder(){
    inOrderBST(root);
}
void RBTree::preOrderBST( Node *& root){
    if(!root) return;
    cout<< "[ "<<root->data<<" "<<root->color<<" ] ";
    preOrderBST(root->left);
    preOrderBST(root->right);
}

void RBTree::preOrder(){
    preOrderBST(root);
}

Node* RBTree::minValueNode(Node *& node){
    Node* ptr=node;
    while(ptr->left) ptr=ptr->left;
    return ptr;
}

Node* RBTree::maxValueNode(Node *& node){
    Node* ptr=node;
    while(ptr->right) ptr=ptr->right;
    return ptr;
}

int RBTree::getBlackHeight(Node *node){
    int blackheight = 0;
    while (node != nullptr) {
        if (getColor(node) == BLACK)
            blackheight++;
        node = node->left;
    }
    return blackheight;
}