import random

from data_structures.graph.Graph import Graph


class ErdosRenyi:
    def __init__(self):
        self.graph = Graph()

    def erdos_renyi(self, nodes, probability):
        for i in range(nodes):
            self.graph.add_node(i)

        for i in range(nodes):
            for j in range(i + 1, nodes):
                if random.random() < probability:
                    self.graph.add_edge(i, j)

        return self.graph
