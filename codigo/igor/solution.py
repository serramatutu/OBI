def main():
    # Número de sequências
    n = int(input())

    # Combinaões
    c = set()

    # Sequências
    s = []
    for _ in range(n):
        actual = input()

        for comb in c:
            if actual in comb:
                print(actual)
                return

        s.append(actual)
        for i in range(len(s) - 1):
            c.add(s[i] + actual)
            c.add(actual + s[i])

        c.add(actual * 2)
    
    print("ok")

if __name__ == '__main__':
    main()