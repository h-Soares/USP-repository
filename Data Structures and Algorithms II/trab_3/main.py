# Work on complex networks

from statistics import mean
from matplotlib import pyplot as plt
import pandas as pd
import networkx as nx
import json


def initGraph():
    # Carregar o arquivo de nos
    nodes_df = pd.read_csv('deezer_europe/deezer_europe_target.csv')
    nodes = nodes_df['id'].tolist()
    target = nodes_df['target'].tolist()

    # Criar um grafo nao direcionado
    G = nx.Graph()

    # Adicionar nos ao grafo com atributo target que representa o genero
    for node, target in zip(nodes, target):
        G.add_node(node, target=target)

    # Carregar e atribuir informacoes de forca dos nos do arquivo JSON
    with open('deezer_europe/deezer_europe_features.json', 'r') as json_file:
        node_features = json.load(json_file)
    for node, features in node_features.items():
        # Considerando a forca de um no como a soma de suas features, calcular e atribuir
        strength = sum(features)
        G.nodes[int(node)]['strength'] = strength

    # Carregar o arquivo de arestas
    edges_df = pd.read_csv('deezer_europe/deezer_europe_edges.csv')
    edges = [(row['node_1'], row['node_2']) for index, row in edges_df.iterrows()]

    # Adicionar arestas ao grafo
    G.add_edges_from(edges)

    return G


def challengeOne(G: nx.Graph):
    # (1) Elaborar um histograma dos graus dos nos (para grafos direcionados somar k-in e k-out);
    # (muitos nos com grau baixo e poucos nos com grau alto) A escala pode nao estar muito boa.
    degree_hist = nx.degree_histogram(G)
    degrees = range(len(degree_hist))
    plt.hist(degrees, bins=len(degree_hist), weights=degree_hist, color='b')  # para facilitar a visualizacao: log=True
    plt.title('Histogram of node degrees')
    plt.xlabel('Node degree')
    plt.ylabel('Frequency')
    plt.show()
    # (2) Descobrir e mostrar os vertices com grau maximo e mınimo como tambem mostrar o grau medio entre os nos;
    degrees = dict(G.degree())
    max_degree = max(degrees.values())
    min_degree = min(degrees.values())
    max_degree_nodes = [node for node, degree in degrees.items() if degree == max_degree]
    min_degree_nodes = [node for node, degree in degrees.items() if degree == min_degree]
    average_degree = mean(degrees.values())
    print(f"Nodes with max degree ({max_degree}): {max_degree_nodes}")
    print(f"Nodes with min degree ({min_degree}): {min_degree_nodes}")
    print(f"Average degree: {average_degree}")
    # (3) Fazer uma histograma da forca dos nos. Elencar os 5 nos ‘mais fortes’;
    # A escala pode nao estar muito boa.
    node_strength = {node: G.nodes[node]['strength'] for node in G.nodes}
    plt.hist(node_strength.values(), bins=40, color='b')  # para facilitar a visualizacao: log=True
    plt.title('Histogram of node strength')
    plt.xlabel('Node strength')
    plt.ylabel('Frequency')
    plt.ticklabel_format(style='plain', axis='x')
    plt.xlim(0, 23000000)
    plt.show()
    top_five_Snodes = sorted(node_strength.items(), key=lambda x: x[1], reverse=True)[:5]
    print("Top 5 strongest nodes: ", end='')
    for node, strength in top_five_Snodes:
        print(f"(node: {node}, strength: {strength}), ", end='')
    # (4) Elaborar uma comparacao entre o grau dos nos e a sua forca;
    # Irei comparar o maior grau com a maior força
    print(f"\nMax degree: {max_degree}, Max strength: {top_five_Snodes[0][1]}")
    # (5) Elucidar os 5 vertices de maior centralidade de intermediacao (betweenness centrality);
    # Aqui foi utilizado 70 nos para realizar uma estimativa, haja vista que a execucao do algoritmo e demorada
    betweenness_centrality = nx.betweenness_centrality(G, k=70)
    top_five_Cnodes = sorted(betweenness_centrality, key=betweenness_centrality.get, reverse=True)[:5]
    print(f"Top 5 betweenness centrality nodes: {top_five_Cnodes}")
    # (6) Calcular o PageRank dos tres vertices mais citados em cada grafo.
    page_rank = nx.pagerank(G)
    top_three_PRnodes = sorted(page_rank, key=page_rank.get, reverse=True)[:3]
    print(f"Top 3 nodes with PageRank: {top_three_PRnodes}")
    print()


def challengeTwo(G: nx.Graph):
    # (1) Descrever o numero de nos e arestas da rede;
    print(f"Number of nodes: {G.number_of_nodes()}, number of edges: {G.number_of_edges()}")
    # (2) Mostrar densidade da rede;
    print(f"Density: {format(nx.density(G), '.4f')}")
    # (3) Descrever o numero de componentes conexos (fortes e fracos), alem do numero de nos e arestas para o maior destes componentes;
    # como o grafo nao e direcionado, irei considerar apenas os componentes conectados.
    number_connected_components = nx.number_connected_components(G)
    greater_component = max(nx.connected_components(G), key=len)
    greater_component_subgraph = G.subgraph(greater_component)
    print(f"Number of connected components: {number_connected_components}, Greater component: {greater_component_subgraph}")
    # (4) Baseado na estatistica de distribuicao dos nos, explique qual modelo esta rede segue;
    """
    De acordo com o grafico da distribuicao de grau dos nos, percebe-se que a maioria dos nos tem grau baixo,
    enquanto poucos nos tem um grau elevado. Tal comportamento e caracteristico do modelo de redes complexas
    chamado Rede Livre de Escala.
    """
    # (5) Mostrar o diametro da rede e o average path length;
    # IMPORTANTE: essa parte pode consumir muito tempo de execucao !
    diameter = nx.diameter(G)
    average_shortest_path_length = nx.average_shortest_path_length(G)
    print(f"Diameter: {diameter}, average path length: {average_shortest_path_length}")
    # (6) Calcular a transitividade da rede.
    transitivity = nx.transitivity(G)
    print(f"Transitivity: {format(transitivity, '.4f')}")


def challengeThree(G: nx.Graph):
    # irei realizar testes removendo os nos de maior grau do grafo
    degrees = dict(G.degree())
    max_degree = max(degrees.values())
    max_degree_nodes = [node for node, degree in degrees.items() if degree == max_degree]
    for node in max_degree_nodes:
        G.remove_node(node)
    print(f"\nAfter removing the highest degree nodes: ")
    number_connected_components = nx.number_connected_components(G)
    greater_component = max(nx.connected_components(G), key=len)
    greater_component_subgraph = G.subgraph(greater_component)
    print(f"Number of nodes: {G.number_of_nodes()}, number of edges: {G.number_of_edges()}")
    print(f"Number of connected components: {number_connected_components}, Greater component: {greater_component_subgraph}")
    print(f"Density: {format(nx.density(G), '.4f')}")
    print(f"Transitivity: {format(nx.transitivity(G), '.4f')}")
    print(f"Is connected: {nx.is_connected(G)}")


# ----- main ----- #
G = initGraph()
challengeOne(G)
challengeTwo(G)
challengeThree(G)
