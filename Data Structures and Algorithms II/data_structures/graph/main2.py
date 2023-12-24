# graph using NetworkX

import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()

G.add_edge(0, 1, cost=2)
G.add_edge(1, 2, cost=3)
G.add_edge(1, 10, cost=2)
G.add_edge(10, 3, cost=1)
G.add_edge(2, 4, cost=7)
G.add_edge(4, 1, cost=5)
G.add_edge(2, 3, cost=8)
G.add_edge(5, 9, cost=8)
G.add_edge(4, 9, cost=1)
G.add_edge(4, 7, cost=5)
G.add_edge(9, 7, cost=1)
G.add_edge(0, 7, cost=2)

print("Neighbors of node 1:")
for neigh in G.neighbors(1):
    print(neigh, end=" ")

print(f"\nDegree of node with value 1: {G.degree[1]}")

dictio = nx.get_edge_attributes(G, "cost")
for node, cost in dictio.items():
    print(f"{node}: {cost}")

print(G.edges.data())

for a in nx.dfs_edges(G, 1):
    print(a)

#   BUSCA EM PROFUNDIDADE
# Escolha um nó de partida e um nó de destino
start_node = 1
target_node = 3
# Encontre os predecessores usando DFS
predecessors = nx.dfs_predecessors(G, source=start_node)
# Reconstrua o caminho a partir dos predecessores
path = [target_node]
current_node = target_node
while current_node != start_node:
    current_node = predecessors[current_node]
    path.insert(0, current_node)
print(f"Caminho de {start_node} até {target_node}: {path}")

# CAMINHO MAIS CURTO COM BASE NO CUSTO. Usa Dijkstra
print(nx.shortest_paths.shortest_path(G, 1, 3, weight="cost"))

pos = nx.spring_layout(G)  # Define a posição dos nós
nx.draw_networkx(G, pos=pos, with_labels=True)  # Desenha o grafo
nx.draw_networkx_edge_labels(G, pos=pos, edge_labels=dictio) # Adiciona os rótulos das arestas com os pesos

plt.show()