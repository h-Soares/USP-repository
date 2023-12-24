import networkx as nx
import matplotlib.pyplot as plt


class Prim:
    def __init__(self, graph):
        self.graph = graph

    def prim(self, plot=True):
        start_node = next(iter(self.graph.nodes))
        key = {}
        parent = {}

        for node in self.graph.nodes:
            key[node] = float('inf')
            parent[node] = None
        key[start_node] = 0
        Q = set(self.graph.nodes)
        mst_edges = []

        while Q:
            u = min(Q, key=lambda node: key[node])
            Q.remove(u)

            if parent[u] is not None:
                mst_edges.append((parent[u], u, key[u]))

            for v in self.graph.edges[u]:
                if v in Q and self.graph.edges[u][v] < key[v]:
                    parent[v] = u
                    key[v] = self.graph.edges[u][v]

        if plot:
            self.plot_mst(mst_edges)

        return mst_edges

    def plot_mst(self, mst):
        # Cria um grafo não direcionado para representar a árvore mínima
        mst_graph = nx.Graph()

        # Adiciona nós e arestas à árvore mínima
        for edge in mst:
            mst_graph.add_edge(edge[0], edge[1], weight=edge[2])

        # Obtém as posições dos nós para o layout do gráfico
        pos = nx.spring_layout(mst_graph)

        # Desenha o grafo da árvore mínima
        nx.draw(mst_graph, pos, with_labels=True, font_weight='bold', node_size=700, node_color='skyblue', font_size=10,
                font_color='black')

        # Adiciona etiquetas de peso nas arestas
        edge_labels = {(edge[0], edge[1]): edge[2] for edge in mst}
        nx.draw_networkx_edge_labels(mst_graph, pos, edge_labels=edge_labels)

        # Adiciona título
        plt.title('Minimum Spanning Tree')

        # Exibe o gráfico
        plt.show()
