def main():
    # Número de elementos
    input()

    # Sequência
    a = [int(x) for x in input().split()]

    biggest = 1
    count   = 1
    for i in range(1, len(a)):
        if abs(a[i - 1] - a[i]) > 2:
            biggest = max(biggest, count)
            count = 1
        else:
            count += 1
            

    print(biggest)

if __name__ == '__main__':
    main()