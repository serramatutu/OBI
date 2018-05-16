def main():
    ia, ib, fa, fb = [int(x) for x in input().split()]

    count = 0
    if ib != fb:
        count += 1
        
        if ia == fa:
            count += 1
    elif ia != fa:
        count += 1

    print(count)

if __name__ == '__main__':
    main()