if __name__ == '__main__':
    positions = int(input())
    ufo       = int(input())
    plane     = int(input())

    value = 0
    if ufo > plane:
        value = ufo - plane
    elif ufo < plane:
        value = positions - plane + ufo

    print(value)