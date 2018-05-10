def main():
    # Número de rodadas
    n = int(input())

    d_points, x_points = [0, 0]
    for _ in range(n):
        d, x = [int(x) for x in input().split()]

        if x == (d + 1) % 5 or x == (d + 2) % 5:
            d_points += 1
        else:
            x_points += 1

    print('dario' if d_points > x_points else 'xerxes')

if __name__ == '__main__':
    main()