class Node:
    def __init__(self, keys, par=None):
        self.keys = list([keys])
        self.parent = par
        self.child = list()

    def __lt__(self, node):
        return self.keys[0] < node.keys[0]

    def _isLeaf(self):
        return len(self.child) == 0

    """
    Função auxiliar para adicionar um novo nó ao original. 
    Extende o nó com as informações de outro nó.
    Controla o split e dimensão de um nó já existente.
    """
    def _insertIntoNode(self, new_node):
        for child in new_node.child:
            child.parent = self
        self.keys.extend(new_node.keys)
        self.keys.sort()
        self.child.extend(new_node.child)
        if len(self.child) > 1:
            self.child.sort()
        if len(self.keys) > 3:
            self._split()

    """
    FOI PEDIDO: Algoritmo para insercao de um dado na arvore 2-3-4
    Procura onde inserir um noh na árvore e o insere recursivamente.
    Esta é a função interna, usada apenas pelo TAD.
    """
    def _insert(self, new_node):
        # Caso 1 - Insercao em uma folha
        if self._isLeaf():
            self._insertIntoNode(new_node)
        # Caso 2 - Nao é uma folha - Encontra o lugar para inserir e o insere
        # com recursão
        elif new_node.keys[0] > self.keys[-1]:
            self.child[-1]._insert(new_node)
        else:
            for i in range(0, len(self.keys)):
                if new_node.keys[0] < self.keys[i]:
                    self.child[i]._insert(new_node)
                    break

    # Funcao "split". É usada quando um noh sofre overflow.
    def _split(self):
        left_child = Node(self.keys[0], self)
        right_child = Node(self.keys[2], self)
        right_child.keys.append(self.keys[3])
        if self.child:
            self.child[0].parent = left_child
            self.child[1].parent = left_child
            self.child[2].parent = right_child
            self.child[3].parent = right_child
            self.child[4].parent = right_child
            left_child.child = [self.child[0], self.child[1]]
            right_child.child = [self.child[2], self.child[3], self.child[4]]
        self.child = [left_child]
        self.child.append(right_child)
        self.keys = [self.keys[1]]
        # Adiciona o novo noh (resultado do split) ao seu node pai
        if self.parent:
            if self in self.parent.child:
                self.parent.child.remove(self)
            self.parent._insertIntoNode(self)
        else:
            left_child.parent = self
            right_child.parent = self

    """
    FOI PEDIDO: Dois tipos de percurso
    """
    def _preorder(self):
        print(self.keys)
        for child in self.child:
            child._preorder()

    def _inorder(self):
        # Verifica se o no atual possui filhos
        if self.child:
            # Se tem filhos, percorre as chaves do no atual
            for i in range(len(self.keys)):
                # Chama recursivamente o metodo _inorder para o filho a esquerda da chave
                self.child[i]._inorder()
                # Verifica se ainda ha mais chaves a serem processadas
                if i < len(self.keys):
                    print(f"[{self.keys[i]}]")
            # Apos percorrer todas as chaves e seus filhos a esquerda,
            # faz o mesmo para o filho à direita do último elemento
            self.child[-1]._inorder()
        else:
            # se for uma folha, percorre as chaves:
            for key in self.keys:
                print(f"[{key}]")

    """
    função auxiliar para ajudar a encontrar 
    e retornar o nó que contém o elemento procurado
    """
    def _find(self, key):
        i = 0

        # enquanto houver chaves e a chave procurada for maior que a chave atual
        while i < len(self.keys) and key > self.keys[i]:
            i += 1

        # se encontrar a chave na posição i, retornar o nó atual, que contém a chave procurada
        if i < len(self.keys) and key == self.keys[i]:
            return self

        # Se é uma folha, procura nas chaves dessa folha
        if self._isLeaf():
            for i in range(len(self.keys)):
                if self.keys[i] == key:
                    return self
            return None
        else:
            # Se não é folha, chama recursivamente a função _find no nó filho apropriado
            return self.child[i]._find(key) if i < len(self.child) else None


# end of Node class

class Tree234:
    def __init__(self):
        self.root = None

    def _isEmpty(self):
        return self.root is None

    def insert(self, elem):
        print("Inserindo: " + str(elem))
        if self._isEmpty():
            self.root = Node(elem)
        else:
            self.root._insert(Node(elem))
            while self.root.parent:
                self.root = self.root.parent
        return True

    def preorder(self):
        if self._isEmpty():
            raise Exception("Arvore vazia. Nao eh possivel imprimir em pre-ordem")

        print('\n Impressao em pre-ordem\n')
        self.root._preorder()

    def inorder(self):
        if self._isEmpty():
            raise Exception("Arvore vazia. Nao eh possivel imprimir em em-ordem")

        print('\n Impressao em em-ordem\n')
        self.root._inorder()

    """
    FOI PEDIDO: uma forma de visualizacao de modo que seja possiıvel avaliar as insercoes e remocoes neste TAD
    """
    def visualize(self):
        if self._isEmpty():
            raise Exception("Arvore vazia. Nao eh possivel visualizar")

        print('\nEstrutura de arvore (visual em largura)')
        this_level = [self.root]
        while this_level:
            next_level = list()
            print('\n')
            for n in this_level:
                print(str(n.keys), end=' ')
                for child in n.child:
                    next_level.append(child)
                this_level = next_level

    """
    Função para encontrar o nó que contém o elemento
    """
    def _find_node(self, elem):
        return self.root._find(elem)

    """
    FOI PEDIDO: Um algoritmo remover um dado neste mesmo TAD.
    Se necessário, reroganiza a árvore.
    Deleção foi separada em casos.
    """
    def delete(self, elem):
        if self._isEmpty():
            raise Exception("Arvore vazia. Nao eh possivel deletar")

        print("\n\nDeletando: " + str(elem))
        node = self._find_node(elem)

        if node is None:
            raise Exception("Elemento não encontrado.")

        # Caso 1: O elemento está em um nó folha
        if node._isLeaf():
            node.keys.remove(elem)

            # Se o nó não violar as propriedades da árvore 2-3-4, termina a deleção
            if 1 <= len(node.keys) <= 3:
                return True

            # Caso contrário, tem-se que reorganizar a árvore
            while node is not self.root and len(node.keys) < 1:
                parent = node.parent
                index = parent.child.index(node)

                # emprestar uma chave do irmão esquerdo
                if index > 0 and len(parent.child[index - 1].keys) >= 2:
                    node.keys.append(parent.keys[index - 1])
                    parent.keys[index - 1] = parent.child[index - 1].keys.pop(-1)
                    if parent.child[index - 1].child:  # Atualiza os filhos, se houver
                        node.child.insert(0, parent.child[index - 1].child.pop(-1))
                    return True

                # Emprestar uma chave do irmão direito
                elif index < len(parent.child) - 1 and len(parent.child[index + 1].keys) >= 2:
                    node.keys.append(parent.keys[index])
                    parent.keys[index] = parent.child[index + 1].keys.pop(0)
                    if parent.child[index + 1].child:  # Atualiza os filhos, se houver
                        node.child.append(parent.child[index + 1].child.pop(0))
                    return True

                # Fusão com irmão esquerdo
                elif index > 0:
                    left = parent.child[index - 1]
                    left.keys.extend(node.keys)
                    left.child.extend(node.child)
                    left.keys.append(parent.keys.pop(index - 1))
                    parent.child.pop(index)
                    node = parent

                # Fusão com irmão direito
                elif index < len(parent.child) - 1:
                    right = parent.child[index + 1]
                    node.keys.extend(right.keys)
                    node.child.extend(right.child)
                    node.keys.append(parent.keys.pop(index))
                    parent.child.pop(index + 1)

            # Arvore ficou vazia. Exclui a raiz
            if len(self.root.keys) == 0 and len(self.root.child) == 0:
                self.root = None
                return True

            # se a raiz for reduzida para uma única chave, atualiza raiz
            if len(self.root.keys) == 0:
                self.root = self.root.child[0]
                self.root.parent = None

            return True

        # Caso 2: O elemento está em um nó interno
        index = node.keys.index(elem)
        pred = node.child[index]
        while not pred._isLeaf():
            pred = pred.child[-1]
        pred_key = pred.keys[-1]
        node.keys[index] = pred_key
        pred.keys.pop()

        # Reorganiza a árvore se necessário
        while pred is not self.root and len(pred.keys) < 1:
            parent = pred.parent
            index = parent.child.index(pred)

            # Emprestar uma chave do irmão esquerdo
            if index > 0 and len(parent.child[index - 1].keys) >= 2:
                pred.keys.insert(0, parent.keys[index - 1])
                parent.keys[index - 1] = parent.child[index - 1].keys.pop(-1)
                if parent.child[index - 1].child:  # Atualiza os filhos, se houver
                    pred.child.insert(0, parent.child[index - 1].child.pop(-1))
                return True

            # Emprestar uma chave do irmão direito
            elif index < len(parent.child) - 1 and len(parent.child[index + 1].keys) >= 2:
                pred.keys.append(parent.keys[index])
                parent.keys[index] = parent.child[index + 1].keys.pop(0)
                if parent.child[index + 1].child:  # Atualiza os filhos, se houver
                    pred.child.append(parent.child[index + 1].child.pop(0))
                return True

            # Fusão com irmão esquerdo
            elif index > 0:
                left = parent.child[index - 1]
                left.keys.extend(pred.keys)
                left.child.extend(pred.child)
                left.keys.append(parent.keys.pop(index - 1))
                parent.child.pop(index)
                pred = parent.child[index - 1]

            # Fusão com irmão direito
            else:
                right = parent.child[index + 1]
                pred.keys.extend(right.keys)
                pred.child.extend(right.child)
                pred.keys.append(parent.keys.pop(index))
                parent.child.pop(index + 1)

        return True


# end of Tree class
"""
FOI PEDIDO: Uma funcao que demostre os algoritmos de insercao e remocao deste TAD.
Adicionei, tambem, para que mostre os dois percursos pedidos.
"""


def main():
    tree = Tree234()
    for i in range(0, 7):
        tree.insert(i)

    tree.preorder()
    tree.inorder()

    tree.visualize()
    tree.delete(4)
    tree.visualize()
    tree.delete(0)
    tree.visualize()
    tree.delete(1)
    tree.visualize()
    tree.delete(2)
    tree.visualize()
    tree.delete(6)
    tree.visualize()
    tree.delete(3)
    tree.visualize()
    tree.delete(5)

    # Ocorre erro de arvore vazia:
    # tree.visualize()


main()
