from collections import defaultdict
import networkx as nx
import matplotlib.pyplot as plt
from heapdict import heapdict


class Graph:
    def __init__(self):
        self.nodes = set()
        self.edges = defaultdict(dict)

    def add_node(self, node):
        self.nodes.add(node)

    def add_edge(self, node_one, node_two, weight=1):
        for node in [node_one, node_two]:
            if node not in self.nodes:
                self.add_node(node)
        self.edges[node_one][node_two] = weight
        self.edges[node_two][node_one] = weight

    def get_edges_sorted_by_weight(self):
        sorted_edges = []
        for node in self.nodes:
            for neighbor, weight in self.edges[node].items():
                sorted_edges.append((node, neighbor, weight))

        sorted_edges = sorted(sorted_edges, key=lambda x: x[2])
        return sorted_edges

    def visualize(self):
        g = nx.Graph()

        for node in self.nodes:
            g.add_node(node)

        for node_one, neighbors_dict in self.edges.items():
            for node_two, weight in neighbors_dict.items():
                g.add_edge(node_one, node_two, weight=weight)

        pos = nx.spring_layout(g)

        labels = nx.get_edge_attributes(g, 'weight')
        nx.draw(g, pos, with_labels=True, font_weight='normal', node_size=700, node_color='skyblue')
        nx.draw_networkx_edge_labels(g, pos, edge_labels=labels, font_size=12)

        plt.figure(figsize=(7, 6))
        plt.show()

    def _depth_first_search(self, start, goal, visited, path):
        visited.add(start)
        path.append(start)

        if start == goal:
            return path

        for neighbor in self.edges[start]:
            if neighbor not in visited:
                print(f"Visiting {neighbor}")
                new_path = self._depth_first_search(neighbor, goal, visited, path[:])
                if new_path is not None:
                    return new_path

        return None

    def depth_first_search(self, start, goal):
        print(f"Visiting {start}")
        result = self._depth_first_search(start, goal, visited=set(), path=list())

        if result is None:
            return "Path not found"
        return result

    def breadth_first_search(self, start, goal):
        visited = set()
        queue = list()
        predecessors = {}

        visited.add(start)
        queue.append(start)

        print(f"Visiting {start}")
        while queue:
            node = queue.pop(0)

            if node == goal:
                path = [node]
                while node != start:
                    node = predecessors[node]  # Vai pegando o predecessor do predecessor...
                    path.insert(0, node)
                return path

            for neighbor in self.edges[node]:
                if neighbor not in visited:
                    print(f"Visiting {neighbor}")
                    visited.add(neighbor)
                    predecessors[neighbor] = node  # Rastreando o predecessor

                    queue.append(neighbor)

        return None

    def dijkstra(self, start, end):
        if start not in self.nodes or end not in self.nodes:
            raise Exception("Start and end nodes must be in the graph")

        visited = []
        predecessors = {}
        distance_from_start = heapdict()
        for node in self.nodes:
            distance_from_start[node] = float('inf')
        distance_from_start[start] = 0

        while bool(distance_from_start):  # while is not empty
            node_distance_from_start = distance_from_start.peekitem()[1]
            node = distance_from_start.popitem()[0]
            visited.append(node)

            if node == end:
                path = [node]
                while node != start:
                    node = predecessors[node]
                    path.insert(0, node)
                return path

            for neighbor in self.edges[node]:
                if neighbor not in visited:
                    node_to_neighbor_distance = node_distance_from_start + self.edges[node][neighbor]
                    if node_to_neighbor_distance < distance_from_start[neighbor]:
                        distance_from_start[neighbor] = node_to_neighbor_distance
                        predecessors[neighbor] = node
