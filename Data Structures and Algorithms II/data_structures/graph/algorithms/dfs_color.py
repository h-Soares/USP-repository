# Deep First Search with color
 
import networkx as nx
from matplotlib import pyplot as plt


def DFSVisit(graph, node, p, time):
    # altera a cor do nó para a cor de "descoberto" (cinza) e altera o tempo de "descobrimento"
    graph.nodes[node]['color'] = 'gray'
    time['current'] += 1
    graph.nodes[node]['discovered'] = time['current']

    # aplica dfs para os vizinhos da cor branca, e adiciona o nó atual como "pai" do nó vizinho
    for neighbor in nx.neighbors(graph, node):
        if graph.nodes[neighbor]['color'] == 'white':
            p[neighbor] = node
            DFSVisit(graph, neighbor, p, time)

    graph.nodes[node]['color'] = 'black'
    graph.nodes[node]['finished'] = time['current']
    time['current'] += 1


def DFS(graph: nx.Graph):
    # inicialização de variáveis
    p = {}
    time = {'current': 0}  # usando um dicionário para permitir mutabilidade entre as recursões
    nx.set_node_attributes(graph, 'white', 'color')
    nx.set_node_attributes(graph, None, 'discovered')
    nx.set_node_attributes(graph, None, 'finished')

    # atribuição de "sem-pai" para todos os nós
    for node in graph.nodes:
        p[node] = None

    # executa dfs para os nós da cor branca
    for node in graph.nodes:
        if graph.nodes[node]['color'] == 'white':
            DFSVisit(graph, node, p, time)


G = nx.Graph()
G.add_edge(1, 2)
G.add_edge(1, 3)
G.add_edge(2, 4)
G.add_edge(3, 4)
G.add_edge(4, 5)
G.add_edge(5, 6)
G.add_edge(5, 7)
DFS(G)

# para plotar o gráfico
pos = nx.spring_layout(G)
plt.figure(figsize=(7, 6))
node_labels = {node: f"\n{node}\n\nDiscovered: {G.nodes[node]['discovered']}\nFinished: {G.nodes[node]['finished']}" for node in G.nodes}
nx.draw(G, pos, with_labels=True, labels=node_labels, node_color=[G.nodes[node]['color'] for node in G.nodes])
plt.show()

for node in G.nodes:
    print(f"node: {node} discovered: {G.nodes[node]['discovered']}")
    print(f"node: {node} finished: {G.nodes[node]['finished']}")
    print(f"node: {node} color: {G.nodes[node]['color']}")
