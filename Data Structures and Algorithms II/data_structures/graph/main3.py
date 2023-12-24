from algorithms.erdos_renyi import ErdosRenyi

erdos_renyi = ErdosRenyi()

graph = erdos_renyi.erdos_renyi(15, 0.2)

graph.visualize()
print(len(graph.nodes))
