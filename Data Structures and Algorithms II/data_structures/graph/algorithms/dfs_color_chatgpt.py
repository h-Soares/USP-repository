# Deep First Search with color (ChatGPT version)

import networkx as nx
import matplotlib.pyplot as plt


def DFS(G):
    # Inicialização
    for v in G.nodes:
        G.nodes[v]['cor'] = 'branco'

    p = {}  # Dicionário para armazenar os predecessores

    # Chamada do DFS para todos os vértices
    for v in G.nodes:
        if G.nodes[v]['cor'] == 'branco':
            DFS_visita(G, v, p)

    return p


def DFS_visita(G, v, p):
    G.nodes[v]['cor'] = 'cinza'

    for u in G.neighbors(v):
        if G.nodes[u]['cor'] == 'branco':
            p[u] = v
            DFS_visita(G, u, p)

    G.nodes[v]['cor'] = 'preto'


# Criando um grafo de exemplo
G = nx.Graph()
G.add_edges_from([(1, 2), (1, 3), (2, 4), (3, 5)])

# Executando o algoritmo DFS
predecessores = DFS(G)

# Imprimindo o percurso utilizando o dicionário p
for v, predecessor in predecessores.items():
    print(f'Nó {v}: Predecessor={predecessor}')

# Plotando o grafo
pos = nx.spring_layout(G)  # Posicionamento dos nós
nx.draw(G, pos, with_labels=True, font_weight='bold', node_color='lightgray', font_color='black', node_size=700)

# Destacando as arestas do percurso
edges_percurso = [(predecessores[v], v) for v in G.nodes if v in predecessores and predecessores[v] is not None]
nx.draw_networkx_edges(G, pos, edgelist=edges_percurso, edge_color='red', width=2)

# Exibindo o gráfico
plt.show()
