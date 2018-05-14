def main():
    # Número de postes
    input()

    # Contagem de trocados e de consertados
    changed  = 0
    repaired = 0

    # Postes
    x = input().split()
    for p in x:
        if int(p) < 50:
            changed += 1
        elif int(p) < 85:
            repaired += 1

    print(str(changed) + " " + str(repaired))

if __name__ == '__main__':
    main()