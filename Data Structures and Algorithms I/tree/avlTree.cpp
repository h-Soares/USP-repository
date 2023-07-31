#include "avlTree.h"
#include <iostream>
#include <math.h>
using namespace std;

template<typename TreeEntry>
    AvlTree<TreeEntry>::AvlTree() {
        root = nullptr;
        totalNodes = 0;
        comparisons = 0;
        rotations = 0;
    }
    template<typename TreeEntry>
    AvlTree<TreeEntry>::~AvlTree() {
        clear();
    }
    template<typename TreeEntry>
    bool AvlTree<TreeEntry>::isEmpty() {
        return root == nullptr;
    }
    template<typename TreeEntry>
    bool AvlTree<TreeEntry>::isFull() {
        try {
            TreePointer p = new TreeNode;
            delete p;
            return false;
        }catch(bad_alloc & e) {
            return true;
        }
    }
    template<typename TreeEntry>
    void AvlTree<TreeEntry>::clear(TreePointer &t) {
        if(t != nullptr) {
            clear(t->leftNode);
            clear(t->rightNode);
            delete t;
        }
    }
    template<typename TreeEntry>
    void AvlTree<TreeEntry>::clear() {
        clear(root);
        root = nullptr;
        totalNodes = 0;
        comparisons = 0;
        rotations = 0;
    }
    template<typename TreeEntry>
    void AvlTree<TreeEntry>::preOrder(TreePointer &t) {
        if(t != nullptr) {
            cout << t->data << endl;
            preOrder(t->leftNode);
            preOrder(t->rightNode);    
        }
    }
    template<typename TreeEntry>
    void AvlTree<TreeEntry>::preOrder() {
        preOrder(root);
    }
    template<typename TreeEntry>
    void AvlTree<TreeEntry>::inOrder(TreePointer &t) {
        if(t != nullptr) {
            inOrder(t->leftNode);
            cout << t->data << " ";
            inOrder(t->rightNode);    
        }
    }
    template<typename TreeEntry>
    void AvlTree<TreeEntry>::inOrder() {
        inOrder(root);
    }
    template<typename TreeEntry>
    void AvlTree<TreeEntry>::postOrder(TreePointer &t) {
        if(t != nullptr) {
            postOrder(t->leftNode);
            postOrder(t->rightNode);  
            cout << t->data << endl;
        }
    }
    template<typename TreeEntry>
    void AvlTree<TreeEntry>::postOrder() {
        postOrder(root);
    }
    template<typename TreeEntry>
    int AvlTree<TreeEntry>::getNodes(TreePointer &t) {
        if(t == nullptr)
            return 0;
        else
            return 1 + getNodes(t->leftNode) + getNodes(t->rightNode);
    }
    template<typename TreeEntry>
    int AvlTree<TreeEntry>::getNodes() {
        return getNodes(root);
    }
    template<typename TreeEntry>
    int AvlTree<TreeEntry>::getTotalNodes() {
        return totalNodes;
    }
    template<typename TreeEntry>
    int AvlTree<TreeEntry>::getHeight(TreePointer &t) {
        if(t == NULL)
            return -1;
        else { 
            int L,R;
            L = getHeight(t->leftNode);
            R = getHeight(t->rightNode);
            if(L>R) 
                return L+1; 
            else 
                return R+1;
        }
    }
    template<typename TreeEntry>
    int AvlTree<TreeEntry>::getHeight() {
        return getHeight(root);
    }
    template<typename TreeEntry>
    int AvlTree<TreeEntry>::getComparisons() {
        return comparisons;
    }
    template<typename TreeEntry>
    int AvlTree<TreeEntry>::getRotations() {
        return rotations;
    }
    template<typename TreeEntry>
    double AvlTree<TreeEntry>::getMinHeight() {
        return ceil(log2(getNodes() + 1) - 1);
    }
    template<typename TreeEntry>
    void AvlTree<TreeEntry>::write() {
        cout << "ALTURA: " << getHeight() << endl;
        cout << "FOLHAS: " << getLeaves() << endl;
        cout << "COMPARACOES DE PALAVRAS: " << getComparisons() << endl;
        cout << "ROTACOES: " << getRotations() << endl;
        cout << "MEDIA DE COMPARACOES POR PALAVRA: " << fixed << setprecision(2) << (double) getComparisons() / getTotalNodes() << endl;
        cout << "MEDIA DE ROTACOES POR PALAVRA DISTINTA: " << fixed << setprecision(2) << (double) getRotations() / getNodes() << endl;
    }
    template<typename TreeEntry>
    int AvlTree<TreeEntry>::getLeaves(TreePointer &t) {
        if(t == nullptr) 
            return 0;
        else if(t->leftNode == nullptr && t->rightNode == nullptr)
            return 1;
        else
            return getLeaves(t->leftNode) + getLeaves(t->rightNode);
    }
    template<typename TreeEntry>
    int AvlTree<TreeEntry>::getLeaves() {
        return getLeaves(root);
    }
    template<typename TreeEntry>
    TreeEntry AvlTree<TreeEntry>::getMin() {
        if(!isEmpty()) {
            TreePointer aux = root;
            while(aux->leftNode != nullptr)
                aux = aux->leftNode;
            return aux->data;    
        }
        return INT8_MIN;
    }
    template<typename TreeEntry>
    TreeEntry AvlTree<TreeEntry>::getMax() {
        if(!isEmpty()) {
            TreePointer aux = root;
            while(aux->rightNode != nullptr)
                aux = aux->rightNode;
            return aux->data;    
        }
        return INT8_MAX;
    }
    template<typename TreeEntry>
    bool AvlTree<TreeEntry>::search(TreeEntry data) {
        if(!isEmpty()) {
            TreePointer aux = root;
            while(aux != nullptr) {
                if(data < aux->data)
                    aux = aux->leftNode;
                else if(data > aux->data)
                    aux = aux->rightNode;
                else
                    return true;
            }    
        return false; //não encontrado
        }
        exit(EXIT_FAILURE);
    }
    template<typename TreeEntry>
    void AvlTree<TreeEntry>::insert(TreeEntry entry) {
        if(!isFull()) {
            TreePointer p = nullptr, q = root;
            while(q != nullptr) {
                p = q; //p é o pai de q
                if(entry < q->data)
                    q = q->leftNode;
                else
                    q = q->rightNode;
            }
            q = new TreeNode; //reaproveita o ponteiro q, que está nulo
            q->data = entry;
            if(p == nullptr) //árvore vazia. Ou: isEmpty(). Usei para reaproveitar o p.
                root = q;
            else if(entry < p->data)
                p->leftNode = q;
            else
                p->rightNode = q;   
        }
    }
    template<typename TreeEntry>
    void AvlTree<TreeEntry>::searchInsert(TreeEntry x, TreePointer &pA, bool &h) {
        TreePointer pB, pC;

        if(pA == NULL) { // inserir
            pA = new TreeNode;
            h = true;
            pA->data = x;
            pA->count = 1;
            pA->leftNode = pA->rightNode = NULL;
            pA->bal = 0;
            totalNodes++;
        }
        else if(x < pA->data) { 
                comparisons++;
                searchInsert(x, pA->leftNode, h);
                if(h) { // subárvore esquerda cresceu
                    switch (pA->bal) { 
                        case -1: pA->bal = 0; h = false; break;
                        case 0: pA->bal = +1; break;
                        case +1: 
                            pB = pA->leftNode;
                            if(pB->bal == +1) { // rotação LL
                                rotations++;
                                pA->leftNode = pB->rightNode; pB->rightNode = pA;
                                pA->bal = 0; pA = pB;
                            }
                            else { // rotação LR  
                                rotations++;
                                pC = pB->rightNode; pB->rightNode = pC->leftNode;
                                pC->leftNode = pB; pA->leftNode = pC->rightNode;
                                pC->rightNode = pA;
                                if(pC->bal == +1) 
                                    pA->bal = -1; 
                                else 
                                    pA->bal = 0;
                                if(pC->bal == -1) 
                                    pB->bal = +1; 
                                else 
                                    pB->bal = 0;
                                pA = pC;
                            }
                            pA->bal = 0; 
                            h = false;
                    } // switch
                }
        }
        else if(x > pA->data) { 
            comparisons += 2;
            searchInsert(x, pA->rightNode, h);
            if(h) { // subárvore direita cresceu
                switch (pA->bal) { 
                    case +1: pA->bal = 0; h = false; break;
                    case 0: pA->bal = -1; break;
                    case -1: pB = pA->rightNode;
                    if(pB->bal == -1) { // rotação RR
                        rotations++;
                        pA->rightNode = pB->leftNode; pB->leftNode = pA;
                        pA->bal = 0; pA = pB;
                    }
                    else { // rotação RL
                        rotations++;
                        pC = pB->leftNode; pB->leftNode = pC->rightNode;
                        pC->rightNode = pB; pA->rightNode = pC->leftNode;
                        pC->leftNode = pA;
                        if(pC->bal == -1) 
                            pA->bal = +1; 
                        else 
                            pA->bal = 0;
                        if(pC->bal == +1) 
                            pB->bal = -1; 
                        else 
                            pB->bal = 0;
                        pA = pC;
                    }
                    pA->bal = 0; h = false;
                } // switch
            }
        }
        else { // elemento encontrado
            pA->count++;
            comparisons += 2;
            totalNodes++;
        }
    }
    template<typename TreeEntry>
    void AvlTree<TreeEntry>::searchInsert(TreeEntry x) {
        bool h = false;
        searchInsert(x, root, h);
    }