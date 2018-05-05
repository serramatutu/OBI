from sys import stdin

class Graph:
    """Classe para representação de um grafo"""

    def __init__(self, n):
        """Inicializa um grafo com N nós"""

        self.__size = n
        self.__edges = set()

    def add_edge(self, a, b, value):
        """Adiciona uma ligação entre nós"""

        self.__edges.add((a, b, value))

    def edges(self, n):
        """Obtém as saídas de um nó"""

        return dict(
            [(b, weight) for (a, b, weight) in self.__edges if a == n]
            + [(a, weight) for (a, b, weight) in self.__edges if b == n]
        )

    def min_dist(self, a, b):
        """Calcula a menor distância entre A e B usando o algoritmo de Dijkstra"""

        # Distância mínima para cada vértice a partir de A.
        # Começa em Infinito.
        minimum_distance = [float("inf")] * self.__size
        minimum_distance[a] = 0 # A -> A = 0

        # Conjunto de vértices ainda não percorridos.
        # Não testa o mesmo vértice duas vezes.
        not_visited = list(range(self.__size))

        # Enquanto existem vértices ainda não percorridos,
        # perrcorre procurando caminhos menores
        while len(not_visited) > 0:

            # Pega o nó com a menor distância prevista para ser o atual
            closest = 0
            for i in range(1, len(not_visited)):
                if minimum_distance[not_visited[i]] < minimum_distance[not_visited[closest]]:
                    closest = i
            current = not_visited.pop(closest)  # Marca ele como visitado

            # Se o atual é B, pode parar de procurar
            if current == b:
                break

            # Agora, para cada nó adjacente (que tem uma aresta
            # ligando) ao atual, atualiza a distância mínima:
            #
            # Se o mínimo do nó atual mais o custo do percurso do ajacente
            # para o atual for menor que o custo mínimo previsto para o 
            # adjacente, então muda o trajeto para passar pelo atual, 
            # diminuindo a distância (assim conseguindo uma nova distância
            # mínima)
            for k, v in self.edges(current).items():
                if not k in not_visited:
                    continue

                if minimum_distance[k] > minimum_distance[current] + v:
                    minimum_distance[k] = minimum_distance[current] + v

        # Retorna a distância mínima calculada para o ponto B
        return minimum_distance[b]

if __name__ == "__main__":

    # Número de cidades e ligações
    n, m = [int(x) for x in stdin.readline().split()]

    # Cria as ligações
    graph = Graph(n)

    for _ in range(m):
        a, b, c = [int(x) for x in stdin.readline().split()]

        graph.add_edge(a - 1, b - 1, c)

    # Calcula o caminho mínimo entre 1 e N
    print(graph.min_dist(0, n - 1))