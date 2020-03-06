#include "RBTree.h"
#include <iostream>
using namespace std;

int main() {
    
    RBTree rbTree;
    rbTree.insertValue(7);
    rbTree.insertValue(3);
    rbTree.insertValue(18);
    rbTree.insertValue(10);
    rbTree.insertValue(22);
    rbTree.insertValue(8);
    rbTree.insertValue(11);
    rbTree.insertValue(26);
    rbTree.insertValue(2);
    rbTree.insertValue(6);
    rbTree.insertValue(13);
     cout<<"=====pre oroder ====="<<endl;
    rbTree.preOrder();
    cout<<endl;
    cout<<"=====in oroder ====="<<endl;
    rbTree.inOrder();
    cout<<endl<<"Deleting 18, 11, 3, 10, 22"<<endl; 
    rbTree.deleteValue(18);
    rbTree.deleteValue(11);
    rbTree.deleteValue(3);
    rbTree.deleteValue(10);
    rbTree.deleteValue(22);
     cout<<"444"<<endl;
    rbTree.preOrder();
    rbTree.inOrder();
     cout<<"555"<<endl;
    return 0;
}