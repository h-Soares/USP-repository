#include "binarySearchTree.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;

    template<typename TreeEntry>
    BinarySearchTree<TreeEntry>::BinarySearchTree() {
        root = nullptr;
        totalNodes = 0;
        comparisons = 0;
    }
    template<typename TreeEntry>
    BinarySearchTree<TreeEntry>::~BinarySearchTree() {
        clear();
    }
    template<typename TreeEntry>
    bool BinarySearchTree<TreeEntry>::isEmpty() {
        return root == nullptr;
    }
    template<typename TreeEntry>
    bool BinarySearchTree<TreeEntry>::isFull() {
        try {
            TreePointer p = new TreeNode;
            delete p;
            return false;
        }catch(bad_alloc & e) {
            return true;
        }
    }
    template<typename TreeEntry>
    void BinarySearchTree<TreeEntry>::clear(TreePointer &t) {
        if(t != nullptr) {
            clear(t->leftNode);
            clear(t->rightNode);
            delete t;
        }
    }
    template<typename TreeEntry>
    void BinarySearchTree<TreeEntry>::clear() {
        clear(root);
        root = nullptr;
        totalNodes = 0;
        comparisons = 0;
    }
    template<typename TreeEntry>
    void BinarySearchTree<TreeEntry>::preOrder(TreePointer &t) {
        if(t != nullptr) {
            cout << t->data << endl;
            preOrder(t->leftNode);
            preOrder(t->rightNode);    
        }
    }
    template<typename TreeEntry>
    void BinarySearchTree<TreeEntry>::preOrder() {
        preOrder(root);
    }
    template<typename TreeEntry>
    void BinarySearchTree<TreeEntry>::inOrder(TreePointer &t) {
        if(t != nullptr) {
            inOrder(t->leftNode);
            cout << t->data << " : FREQUENCIA: " << t->count << endl;
            inOrder(t->rightNode);    
        }
    }
    template<typename TreeEntry>
    void BinarySearchTree<TreeEntry>::inOrder() {
        inOrder(root);
    }

    template<typename TreeEntry>
    void BinarySearchTree<TreeEntry>::postOrder(TreePointer &t) {
        if(t != nullptr) {
            postOrder(t->leftNode);
            postOrder(t->rightNode);  
            cout << t->data << endl;
        }
    }
    template<typename TreeEntry>
    void BinarySearchTree<TreeEntry>::postOrder() {
        postOrder(root);
    }
    template<typename TreeEntry>
    int BinarySearchTree<TreeEntry>::getNodes(TreePointer &t) {
        if(t == nullptr)
            return 0;
        else
            return 1 + getNodes(t->leftNode) + getNodes(t->rightNode);
    }
    template<typename TreeEntry>
    int BinarySearchTree<TreeEntry>::getNodes() {
        return getNodes(root);
    }
    template<typename TreeEntry>
    int BinarySearchTree<TreeEntry>::getTotalNodes() {
        return totalNodes;
    }
    template<typename TreeEntry>
    int BinarySearchTree<TreeEntry>::getHeight(TreePointer &t) {
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
    int BinarySearchTree<TreeEntry>::getHeight() {
        return getHeight(root);
    }
    template<typename TreeEntry>
    int BinarySearchTree<TreeEntry>::getComparisons() {
        return comparisons;
    }
    template<typename TreeEntry>
    double BinarySearchTree<TreeEntry>::getMinHeight() {
        return ceil(log2(getNodes() + 1) - 1);
    }
    template<typename TreeEntry>
    void BinarySearchTree<TreeEntry>::write() {
        cout << "PALAVRAS DISTINTAS: " << getNodes() << endl;
        cout << "PALAVRAS: " << getTotalNodes() << endl;
        cout << "ALTURA DA ARVORE MINIMA: " << getMinHeight() << endl;
        cout << "ALTURA: " << getHeight() << endl;
        cout << "FOLHAS: " << getLeaves() << endl;
        cout << "COMPARACOES DE PALAVRAS: " << getComparisons() << endl;
        cout << "MEDIA DE COMPARACOES POR PALAVRA: " << fixed << setprecision(2) << (double) getComparisons() / getTotalNodes() << endl;
    }
    template<typename TreeEntry>
    int BinarySearchTree<TreeEntry>::getLeaves(TreePointer &t) {
        if(t == nullptr) 
            return 0;
        else if(t->leftNode == nullptr && t->rightNode == nullptr)
            return 1;
        else
            return getLeaves(t->leftNode) + getLeaves(t->rightNode);
    }
    template<typename TreeEntry>
    int BinarySearchTree<TreeEntry>::getLeaves() {
        return getLeaves(root);
    }
    template<typename TreeEntry>
    TreeEntry BinarySearchTree<TreeEntry>::getMin() {
        if(!isEmpty()) {
            TreePointer aux = root;
            while(aux->leftNode != nullptr)
                aux = aux->leftNode;
            return aux->data;    
        }
        return INT8_MIN;
    }
    template<typename TreeEntry>
    TreeEntry BinarySearchTree<TreeEntry>::getMax() {
        if(!isEmpty()) {
            TreePointer aux = root;
            while(aux->rightNode != nullptr)
                aux = aux->rightNode;
            return aux->data;    
        }
        return INT8_MAX;
    }
    template<typename TreeEntry>
    bool BinarySearchTree<TreeEntry>::search(TreeEntry data) {
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
    void BinarySearchTree<TreeEntry>::insert(TreeEntry entry) {
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
    void BinarySearchTree<TreeEntry>::searchInsert(TreeEntry x, TreePointer &t) {
        if(t == nullptr) { // x não encontrado; inserir
            t = new TreeNode;
            t->data = x;
            t->count = 1; // primeira ocorrência de x
            totalNodes++;
        }
        else if(x < t->data) {// procurar x na subárvore esquerda
            comparisons++; 
            searchInsert( x, t->leftNode );
        }
        else if(x > t->data) {// procurar x na subárvore direita
            comparisons += 2; 
            searchInsert(x, t->rightNode);
        }
        else { // x encontrado, atualizar contador
            t->count++;
            comparisons += 2;
            totalNodes++;
        }
    }
    template<typename TreeEntry>
    void BinarySearchTree<TreeEntry>::searchInsert(TreeEntry x) {
        searchInsert(x, root);
    }
    template<typename TreeEntry>
    bool BinarySearchTree<TreeEntry>::remove(TreeEntry x, TreePointer &p) {
        if( p == NULL )
            return false; // elemento inexistente

        if(x < p->data)
            return remove(x,p->leftNode);
        else if(x > p->data)
            return remove(x,p->rightNode);
        else { // remover p->
            TreePointer q;
            q = p;
            if( q->leftNode == NULL )
            p = q->rightNode; // caso A
            else
            if( q->rightNode == NULL )
            p = q->leftNode; // caso B
            else // caso C.1
            removeMin(q, q->rightNode);
            delete q;
            return true; // elemento removido
        }
    }
    template<typename TreeEntry>
    void BinarySearchTree<TreeEntry>::removeMin(TreePointer &q, TreePointer &r) {
        if( r->leftNode != NULL )
            removeMin(q,r->leftNode);
        else { 
            q->data = r->data;
            q->count = r->count; // somente necessário se busca com inserção
            q = r;
            r = r->rightNode;
        }
    }
    template<typename TreeEntry>
    bool BinarySearchTree<TreeEntry>::remove(TreeEntry x) { 
        return remove(x, root);
    }
    //Essa parte do código foi feita com ajuda do Chat GPT.
    template<typename TreeEntry>
    //O vetor wordFreq armazena as palavras encontradas juntamente com sua contagem.
    void BinarySearchTree<TreeEntry>::findMostFrequentWords(TreePointer t, std::vector<std::pair<TreeEntry, int>>& wordFreq) {
        if (t != nullptr) {
            //Realiza uma travessia em ordem na árvore binária de busca para encontrar as palavras mais frequentes
            findMostFrequentWords(t->leftNode, wordFreq);
            wordFreq.push_back(std::make_pair(t->data, t->count));
            findMostFrequentWords(t->rightNode, wordFreq);
        }
    }

    template<typename TreeEntry>
    void BinarySearchTree<TreeEntry>::findMostFrequentWords() {
        std::vector<std::pair<TreeEntry, int>> wordFreq;
        findMostFrequentWords(root, wordFreq);

        // Ordenar as palavras por frequência em ordem decrescente
        std::sort(wordFreq.begin(), wordFreq.end(),
                [](const std::pair<TreeEntry, int>& a, const std::pair<TreeEntry, int>& b) {
                    return a.second > b.second;
                });

        // Imprimir as 10 palavras mais frequentes
        cout << endl << "10 PALAVRAS MAIS FREQUENTES: " << endl;
        int count = 0;
        for (const auto& pair : wordFreq) {
            if (count >= 10) {
                break;
            }
            std::cout << pair.first << " : FREQUENCIA: " << pair.second << std::endl;
            count++;
        }
    }