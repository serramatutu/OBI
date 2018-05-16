def main():
    n, d = [int(x) for x in input().split()]

    c = [int(x) for x in input().split()]

    sum = 0
    count = 0
    i = 0
    while i < n:
        sum += c[i]

        remaining = d - sum
        j = n - 1
        while j > i and remaining > 0:
            remaining -= c[j]

            if remaining == 0:
                count += 1

            j -= 1

        if sum == d:
           count += 1
           break
        elif sum > d:
            break
            
        i += 1

    sum = 0
    i = n - 1
    while i > 0:
        sum += c[i]

        if sum == d:
           count += 1
           break
        elif sum > d:
            break
            
        i -= 1

    print(count)

if __name__ == '__main__':
    main()