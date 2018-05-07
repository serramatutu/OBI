#include <iostream>
#include <unordered_map>
#include <vector>
#include <forward_list>
#include <unordered_set>
#include <limits>

using namespace std;

struct GraphPath  {
    int totalCost;
    forward_list<int> path;

    GraphPath(int totalCost, const forward_list<int>& path) : totalCost(totalCost), path(path) {};
};

struct GraphNode {
    // location, cost
    unordered_map<int, int> neighbors;
};

class Graph {
    protected:
        unordered_map<int, GraphNode> nodes; // nodes têm ID

    public:
        void addEdge(int cost, int from, int to);

        GraphPath shortestPath(int start, int end);
};

// Jà adiciona o node caso ele não exista
void Graph::addEdge(int cost, int from, int to) {
    this->nodes[from].neighbors[to] = cost;
    this->nodes[to].neighbors[from] = cost;
}
// dijkstra ftw
GraphPath Graph::shortestPath(int start, int end) {
    // melhor caminho, custo
    unordered_map<int, int> d; // distância
    unordered_map<int, int> p; // anterior
    
    unordered_set<int> notVisited;
    notVisited.reserve(this->nodes.size());

    for (auto it=this->nodes.cbegin(); it!=this->nodes.cend(); it++) {
        d.insert({it->first, numeric_limits<int>::max()}); // inicializa todos com distância infinita
        notVisited.insert(it->first); // marca todos como não visitados
    }
    d[start] = 0; // Distância do começo até ele mesmo é 0;

    int currentNode, minDistance;
    while (notVisited.size() > 0) {
        // busca o nó com a menor distância para que seja o atual
        minDistance = numeric_limits<int>::max();
        for (auto it=notVisited.cbegin(); it!=notVisited.cend(); it++) {
            if (d[*it] <= minDistance) {
                currentNode = *it;
                minDistance = d[*it];
            }
        }
        notVisited.erase(currentNode); // marca o nó atual como visitado

        // itera pelos vizinhos do nó atual
        for (auto neighbor = this->nodes[currentNode].neighbors.cbegin(); neighbor != this->nodes[currentNode].neighbors.cend(); neighbor++) {
            if (d.at(neighbor->first) > d.at(currentNode) + neighbor->second) { // se o custo pelo nó atual é menor
                // distância é a distância do vizinho + o caminho até ele
                d.at(neighbor->first) = d.at(currentNode) + neighbor->second;
                // não pode ser at porque não foi inicializado ainda
                p[neighbor->first] = currentNode; // Chega-se pelo vizinho
            }
        }
    }

    forward_list<int> path;

    int currentId = end;
    while (currentId != start) {
        path.push_front(currentId);
        currentId = p[currentId];
    }
    path.push_front(start);

    return GraphPath(d[end], path);
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    Graph graph;

    int from, to, cost;
    for (int i=0; i<edges; i++) {
        cin >> from >> to >> cost;
        graph.addEdge(cost, from, to);
    }

    cout << graph.shortestPath(1, nodes).totalCost;

    return 0;
}