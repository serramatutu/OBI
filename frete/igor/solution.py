from queue import PriorityQueue

def main():
    n, m = [int(x) for x in input().split()]

    graph = dict()
    for _ in range(m):
        a, b, c = [int(x) for x in input().split()]

        if a not in graph.keys():
            graph[a] = dict()

        if b not in graph.keys():
            graph[b] = dict()

        graph[a][b] = c
        graph[b][a] = c

    # Dijkstra
    frontier = PriorityQueue()
    frontier.put(1, 0)
    
    cost_so_far = {}
    cost_so_far[1] = 0

    while not frontier.empty():
        current = frontier.get()

        if current == n:
            break
        
        if current in graph:
            for g in graph[current].keys():
                new_cost = cost_so_far[current] + graph[current][g]
                if g not in cost_so_far or new_cost < cost_so_far[g]:
                    cost_so_far[g] = new_cost
                    frontier.put(g, new_cost)

    print(cost_so_far[n])

if __name__ == '__main__':
    main()