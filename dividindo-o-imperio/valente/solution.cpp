#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int N, minDiff;
vector<unordered_set<int>> graph;

unordered_set<int> visited;
int dfs(int from, int to) {
    int count = 1; // quantos nós abaixo existem (inclusive)

    visited.insert(from);

    for (int neighbor : graph[from]) {
        if (visited.count(neighbor) <= 0) { // se não foi visitado
            count += dfs(neighbor, from);
        }
    }

    int diff = abs(N - 2*count); // (N - count) - count
    if (diff < minDiff)
        minDiff = diff;

    return count;
}

int main() {
    cin >> N;
    minDiff = N;
    graph.resize(N);

    for (int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    dfs(0, -1);
    cout << minDiff << endl;

    return 0;
}