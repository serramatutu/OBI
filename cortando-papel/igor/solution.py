def simplify(heights):
    new_heights = []
    new_heights.append([heights[0], 0])

    ascending = True if heights[0] < heights[1] else False
    for i in range(1, len(heights)):
        actual_ascending = True if heights[i - 1] < heights[i] else False
        if actual_ascending != ascending:
            new_heights.append([heights[i - 1], new_heights[-1][1] + 1])
            ascending = actual_ascending

    if heights[-2] != heights[-1]:
        new_heights.append([heights[-1], new_heights[-1][1] + 1])
    return new_heights

if __name__ == "__main__":

    # Número de retângulos
    input()

    # Alturas
    heights = simplify([int(x) for x in input().split()])

    sorted_heights = heights[:]
    sorted_heights.sort()

    start = 0 if heights[0] > heights[1] else 1
    max_count = 2
    count = 1
    for h in reversed(sorted_heights):
        if (h[1] - start) % 2 == 0:
            count += 1
        elif h != heights[0][1] and h != heights[-1]:
            count -= 1

        if count > max_count:
            max_count = count

    print(max_count)