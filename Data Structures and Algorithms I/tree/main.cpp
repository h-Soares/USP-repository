#include "binarySearchTree.h"
#include "avlTree.h"
#include <iostream>
#include <fstream>
#include <cstring> 
using namespace std;
//Hiago Soares de Araujo    Curso: BCC
int main() {
    BinarySearchTree<string> bst;
    AvlTree<string> avl;
    string word;
    ifstream theInput1("mam-na-np-lo.txt");
    // ler cada palavra do arquivo e inserir na ABB e na AVL
    while( theInput1 >> word ) { 
        bst.searchInsert(word);
        avl.searchInsert(word);
    }
    theInput1.close();
    cout << "mam: " << endl;
    cout << "ABB: " << endl;
    
    bst.write();
    cout << endl << "AVL: " << endl;
    avl.write();
    bst.findMostFrequentWords(); 

    bst.clear();
    avl.clear();

    ifstream theInput2("exame_10000-na-np-lo.txt");
    while( theInput2 >> word ) { 
        bst.searchInsert(word);
        avl.searchInsert(word);
    }
    theInput2.close();
    cout << endl << "exame: " << endl;
    cout << "ABB: " << endl;
    bst.write();
    cout << endl << "AVL: " << endl;
    avl.write(); 
    bst.findMostFrequentWords();

    bst.clear();
    avl.clear();

    ifstream theInput3("biblia-na-np-lo.txt");
    while( theInput3 >> word ) { 
        bst.searchInsert(word);
        avl.searchInsert(word);
    }
    theInput3.close();
    cout << endl << "biblia: " << endl;
    cout << "ABB: " << endl;
    bst.write();
    cout << endl << "AVL: " << endl;
    avl.write(); 
    bst.findMostFrequentWords();

    bst.clear();
    avl.clear(); 
    
    system("pause");
    return 0;
}