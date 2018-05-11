def main():
    # Linhas e colunas do mapa
    l, c = [int(x) for x in input().split()]

    # Mapa
    m = []

    # y: init[0]  x: init[1]
    init = -1
    for _ in range(l):
        m.append(list(input()))

        if init == -1:
            for i in range(c):
                if m[-1][i] == 'o':
                    init = [len(m) - 1, i]
                    break

    toVisit = []
    toVisit.append(init)

    actual = -1
    while len(toVisit) != 0:
        actual = toVisit.pop()

        if actual[0] != l - 1:
            nextPos = [actual[0] + 1, actual[1]]
            if m[actual[0] + 1][actual[1]] == 'H':
                m[actual[0]][actual[1]] = '.'
                toVisit.append(nextPos)

        if actual[0] != 0:
            nextPos = [actual[0] - 1, actual[1]]
            if m[actual[0] - 1][actual[1]] == 'H':
                m[actual[0]][actual[1]] = '.'
                toVisit.append(nextPos)

        if actual[1] != c - 1:
            nextPos = [actual[0], actual[1] + 1]
            if m[actual[0]][actual[1] + 1] == 'H':
                m[actual[0]][actual[1]] = '.'
                toVisit.append(nextPos)
                
        if actual[1] != 0:
            nextPos = [actual[0], actual[1] - 1]
            if m[actual[0]][actual[1] - 1] == 'H':
                m[actual[0]][actual[1]] = '.'
                toVisit.append(nextPos)

    print(str(actual[0] + 1) + " " + str(actual[1] + 1))



if __name__ == '__main__':
    main()