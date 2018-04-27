from sys import stdin
from sys import stdout
from collections import deque

def readints():
    return [int(x) for x in stdin.readline().split()]

def main():
    # Primeira linha: quantidades
    n, m, i = readints()
    
    # Segunda linha: idades
    info = readints()

    # M linhas seguintes: relações
    sup = dict()

    # Mapa de IDs para posições no vetor
    idmap = list(range(n))

    for _ in range(m):
        x, y = readints()
        x -= 1
        y -= 1

        if not y in sup:
            sup[y] = set()
            
        sup[y].add(x)

    # I linhas seguintes: instruções
    for _ in range(i):
        args = stdin.readline().split()

        op = args[0]

        if op == "T":
            a = int(args[1]) - 1
            b = int(args[2]) - 1

            info[idmap[a]], info[idmap[b]] = info[idmap[b]], info[idmap[a]]
            idmap[a], idmap[b] = idmap[b], idmap[a]
            
        elif op == "P":
            a = idmap[int(args[1]) - 1]
            
            min_age = 101
            q = deque()

            if a in sup:
                for s in sup[a]:
                    q.append(s)

            d = set()

            while q:
                a = q.pop()

                min_age = min(info[a], min_age)

                if a in sup:
                    for s in sup[a]:
                        if not s in d:
                            d.add(s)
                            q.append(s)

            if min_age > 100:
                print('*')
            else:
                print(min_age)
    
if __name__ == "__main__":
    main()