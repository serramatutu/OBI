from collections import deque

def main():
    employees_number, direct_management_number, intructions = [int(x) for x in input().split()]
    employees_age = [int(x) for x in input().split()]

    #0: 0, 1: 1...
    ids = list(range(employees_number))

    # key: employee, values: managers
    employees = {}
    for _ in range(direct_management_number):
        manager, managed = [int(x) for x in input().split()]
        manager -= 1
        managed -= 1

        if managed not in employees:
            employees[managed] = set()
        employees[managed].add(manager)

    for _ in range(intructions):
        line = input().split()

        if line[0] == 'T':
            emp1 = int(line[1]) - 1
            emp2 = int(line[2]) - 1

            employees_age[ids[emp1]], employees_age[ids[emp2]] = employees_age[ids[emp2]], employees_age[ids[emp1]]
            ids[emp1], ids[emp2] = ids[emp2], ids[emp1]
        else:
            emp = ids[int(line[1]) - 1]

            if emp not in employees:
                print("*")
            else:
                youngest = 100

                visited = set()
                toVisit = deque()

                for s in employees[emp]:
                    toVisit.append(s)

                while toVisit:
                    actual = toVisit.pop()
                    visited.add(actual)

                    if employees_age[actual] < youngest:
                        youngest = employees_age[actual]

                    if actual in employees:
                        for manager in employees[actual]:
                            if manager not in visited:
                                visited.add(manager)
                                toVisit.append(manager)

                print(youngest)

if __name__ == '__main__':
    main()