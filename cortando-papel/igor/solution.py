def simplify(heights):
    new_heights = []
    new_heights.append(heights[0])

    ascending = True if heights[0] < heights[1] else False
    for i in range(1, len(heights)):
        actual_ascending = True if heights[i - 1] < heights[i] else False
        if actual_ascending != ascending:
            new_heights.append(heights[i - 1])
            ascending = actual_ascending

    if heights[-2] != heights[-1]:
        new_heights.append(heights[-1])
    return new_heights

if __name__ == "__main__":

    # Número de retângulos
    input()

    # Alturas
    heights = simplify([int(x) for x in input().split()])

    highests = []
    start = 0 if heights[0] > heights[1] else 1
    for i in range(start, len(heights), 2):
        highests.append(heights[i])
    highests.sort()

    highest_low = 0
    start = 0 if start == 1 else 1
    for i in range(start, len(heights), 2):
        if heights[i] > highest_low:
            highest_low = heights[i]

    max_count = 0
    for h in highests:
    #for i in range(start, len(heights), 2):
        count = 0
        valley = True
        for n in range(len(heights)):
            #if heights[n] >= heights[i]:
            if heights[n] >= h:
                if valley:
                    count += 1
                    valley = False
            else:
                valley = True
        count += 1

        if count >= max_count:
            max_count = count
        elif h > highest_low:
            break

    print(max_count)