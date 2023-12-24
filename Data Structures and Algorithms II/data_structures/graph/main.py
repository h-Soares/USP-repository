from Graph import Graph
from algorithms.kruskal import Kruskal
from algorithms.prim import Prim

graph = Graph()

# Do slide AED II (Evandro) estava errado!
# graph.add_edge(3, 1, 4)
# graph.add_edge(3, 6, 5)
# graph.add_edge(3, 4, 2)
# graph.add_edge(1, 4, 1)
# graph.add_edge(1, 2, 2)
# graph.add_edge(4, 6, 8)
# graph.add_edge(4, 7, 4)
# graph.add_edge(4, 5, 7)
# graph.add_edge(4, 2, 3)
# graph.add_edge(6, 7, 5)
# graph.add_edge(7, 5, 6)
# graph.add_edge(5, 2, 10)

graph.add_edge('B', 'A', 2)
graph.add_edge('B', 'C', 4)
graph.add_edge('B', 'E', 3)
graph.add_edge('A', 'C', 3)
graph.add_edge('A', 'D', 3)
graph.add_edge('D', 'C', 5)
graph.add_edge('D', 'F', 7)
graph.add_edge('E', 'C', 1)
graph.add_edge('F', 'C', 6)
graph.add_edge('F', 'E', 8)
graph.add_edge('F', 'G', 9)

graph.visualize()

kruskal = Kruskal(graph)
print(kruskal.kruskal())

prim = Prim(graph)
print(prim.prim())


print(graph.depth_first_search("A", "F"))
print()
print(graph.breadth_first_search("A", "F"))

#
# print(graph.nodes)
# print(graph.edges.items())
# print(graph.edges[1])
# print(graph.edges[1].items())
# print()
#
# for node in graph.nodes:
#     for neighbor, weight in graph.edges[node].items():
#         print(f"Node: {node} Neighbor: {neighbor}, Weight: {weight}")
#
# print()
#
# for node, neighbors_dict in graph.edges.items():
#     for neighbor, weight in neighbors_dict.items():
#         print(f"Node: {node}, Neighbor: {neighbor}, Weight: {weight}")
#
# print()
# for neighbor, weight in graph.edges[1].items():
#     print(f"Neighbor: {neighbor}, Weight: {weight}")
#
# print()
# for neighbor in graph.edges[1]:
#     print(f"Neighbor for node 1: {neighbor}")
#
# print(graph.get_edges_sorted_by_weight())
