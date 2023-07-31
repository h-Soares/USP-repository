#ifndef AVLTREE_H
#define AVLTREE_H

template <typename TreeEntry>
class AvlTree { 
    public:
    AvlTree();
    ~AvlTree();
    bool isEmpty();
    bool isFull();
    int getNodes(); //ou fazer com um int numNodes
    int getTotalNodes();
    int getHeight();
    int getComparisons();
    int getRotations();
    double getMinHeight();
    void write();
    void clear(); //em pós - ordem
    void preOrder();
    void inOrder();
    void postOrder();
    int getLeaves();
    TreeEntry getMin();
    TreeEntry getMax();
    void insert(TreeEntry entry);
    bool search(TreeEntry data);
    void searchInsert(TreeEntry x);
    private:
    struct TreeNode; // estrutura TreeNode definida abaixo no código
    typedef TreeNode* TreePointer; 
    struct TreeNode { 
        TreeEntry data; 
        TreePointer leftNode = nullptr; // subárvore esquerda
        TreePointer rightNode = nullptr; // subárvore direita
        int count = 0; //frequência de cada node
        int bal; // -1, 0, +1
    };
    // declaração de campos
    TreePointer root;
    int totalNodes; //soma das frequências de todos os nodes da árvore. Para não percorrer a árvore toda.
    int comparisons;
    int rotations;
    // métodos privados
    int getNodes(TreePointer &t);
    void clear(TreePointer &t);
    void preOrder(TreePointer &t);
    void inOrder(TreePointer &t);
    void postOrder(TreePointer &t);
    int getLeaves(TreePointer &t);
    int getHeight(TreePointer &t);
    void searchInsert(TreeEntry x, TreePointer &pA, bool &h);
};
#include "avlTree.cpp"
#endif