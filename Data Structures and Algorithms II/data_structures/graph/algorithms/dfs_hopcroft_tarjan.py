# Deep First Search with numbering

import networkx as nx
from matplotlib import pyplot as plt


def DFS(graph, node, num, edges, i):
    # atribui o número de i ao nó e incrementa esse i
    num[node] = i
    i += 1

    """ 
    para cada vizinho do nó, verifica se pode visitar. Se sim, adiciona a tupla (nó, vizinho) ao 
    conjunto de arestas visitadas e continua a recursão com esse vizinho
    """
    for neighbor in nx.neighbors(graph, node):
        if num[neighbor] == 0:
            edges.append((node, neighbor))
            DFS(graph, neighbor, num, edges, i)


def depthFirstSearch(graph: nx.Graph):
    # inicialização de variáveis
    num = {}
    edges = []
    i = 1

    # atribuição de número 0 para todos os nós
    for node in graph.nodes:
        num[node] = 0

    # se existe algum nó com número igual a 0, executa
    while any(num[node] == 0 for node in graph.nodes):
        # procura esse nó com número igual a 0 e aplica DFS
        dfs_node = None
        for node in graph.nodes:
            if num[node] == 0:
                dfs_node = node
                break  # se encontrar, encerra-se o for e segue para o DFS com o nó encontrado
        DFS(graph, dfs_node, num, edges, i)

    # retorna todas as arestas exploradas
    return edges


G = nx.Graph()

# primeiro subgrafo, que não será conectado com o segundo
G.add_edge(1, 2)
G.add_edge(1, 3)
G.add_edge(2, 4)
G.add_edge(3, 4)
G.add_edge(4, 5)
G.add_edge(5, 6)
G.add_edge(5, 7)
# segundo subgrafo
G.add_edge(21, 22)
G.add_edge(21, 23)
G.add_edge(22, 24)
G.add_edge(23, 24)
G.add_edge(24, 25)
G.add_edge(25, 26)
G.add_edge(25, 27)

# para plotar o grafo
pos = nx.spring_layout(G)  # definir layout para melhor visualização
nx.draw(G, pos, with_labels=True, font_weight='bold', node_size=700, node_color='skyblue', font_color='black', font_size=8)

print(depthFirstSearch(G))
# Exibir o gráfico
plt.show()
