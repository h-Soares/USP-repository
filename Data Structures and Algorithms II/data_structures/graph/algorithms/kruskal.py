import networkx as nx
import matplotlib.pyplot as plt


class Kruskal:
    def __init__(self, graph):
        self.graph = graph
        self.parent = {}

    def _make_set(self, node):
        self.parent[node] = node

    def _find_set(self, node):
        if self.parent[node] != node:
            self.parent[node] = self._find_set(self.parent[node])
        return self.parent[node]

    def _union_sets(self, node1, node2):
        root1 = self._find_set(node1)
        root2 = self._find_set(node2)

        if root1 != root2:
            self.parent[root2] = root1

    def kruskal(self, plot=True):
        mst = []
        for node in self.graph.nodes:
            self._make_set(node)
        sorted_edges = self._get_edges_sorted_by_weight()
        for edge in sorted_edges:
            node1, node2, weight = edge
            if self._find_set(node1) != self._find_set(node2):
                mst.append(edge)
                self._union_sets(node1, node2)

        if plot:
            self._plot_mst(mst)

        self.parent = {}
        return mst

    def _get_edges_sorted_by_weight(self):
        sorted_edges = []
        for node in self.graph.nodes:
            for neighbor, weight in self.graph.edges[node].items():
                sorted_edges.append((node, neighbor, weight))

        sorted_edges = sorted(sorted_edges, key=lambda x: x[2])
        return sorted_edges

    def _plot_mst(self, mst):
        g = nx.Graph()
        g.add_weighted_edges_from(mst)

        pos = nx.spring_layout(g)  # Define a posição dos nós para layout

        nx.draw(g, pos, with_labels=True, font_weight='bold', node_size=700, node_color='skyblue', font_size=10,
                font_color='black')
        nx.draw_networkx_edge_labels(g, pos, edge_labels={(edge[0], edge[1]): edge[2] for edge in mst})

        plt.title('Minimum Spanning Tree (Kruskal)')
        plt.show()
