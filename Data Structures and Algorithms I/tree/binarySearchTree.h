#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <vector>

template <typename TreeEntry>
class BinarySearchTree { 
    public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool isEmpty();
    bool isFull();
    int getNodes(); //ou fazer com um int numNodes
    int getTotalNodes();
    int getHeight();
    int getComparisons();
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
    bool remove(TreeEntry x);
    void findMostFrequentWords();
    private:
    struct TreeNode; // estrutura TreeNode definida abaixo no código
    typedef TreeNode* TreePointer; 
    struct TreeNode { 
        TreeEntry data; 
        TreePointer leftNode = nullptr; // subárvore esquerda
        TreePointer rightNode = nullptr; // subárvore direita
        int count = 0; //frequência de cada node
    };
    // declaração de campos
    TreePointer root;
    int totalNodes; //soma das frequências de todos os nodes da árvore. Para não percorrer a árvore toda.
    int comparisons;
    // métodos privados
    int getNodes(TreePointer &t);
    void clear(TreePointer &t);
    void preOrder(TreePointer &t);
    void inOrder(TreePointer &t);
    void postOrder(TreePointer &t);
    int getLeaves(TreePointer &t);
    int getHeight(TreePointer &t);
    void searchInsert(TreeEntry x, TreePointer &t);
    bool remove(TreeEntry x, TreePointer &p);
    void removeMin(TreePointer &q, TreePointer &r);
    void findMostFrequentWords(TreePointer t, std::vector<std::pair<TreeEntry, int>>& wordFreq);
};
#include "binarySearchTree.cpp"
#endif