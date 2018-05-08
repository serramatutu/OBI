if __name__ == '__main__':
    boots = {}
    for _ in range(int(input())):
        size, side = input().split()

        size = int(size)
        if size not in boots:
            boots.setdefault(size, { 'E': 0, 'D': 0 })

        boots[size][side] += 1

    count = 0
    for size in boots.values():
        count += size['E'] if size['E'] < size['D'] else size['D']

    print(count)