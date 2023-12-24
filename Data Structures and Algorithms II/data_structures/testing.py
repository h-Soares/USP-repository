from data_structures.graph.Graph import Graph

my_graph = Graph()

my_graph.add_edge("A", "C", 3)
my_graph.add_edge("A", "B", 4)
my_graph.add_edge("B", "C", 5)
my_graph.add_edge("B", "D", 2)
my_graph.add_edge("C", "D", 1)
my_graph.add_edge("C", "E", 3)
my_graph.add_edge("D", "E", 4)

print(my_graph.dijkstra("A", "D"))
