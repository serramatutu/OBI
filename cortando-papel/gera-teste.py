from random import randrange, seed
import uuid

if __name__ == "__main__":
    
    seed()

    uid = uuid.uuid4()
    testcase = open('teste%s.txt' % uid, 'w')

    n = randrange(1, 25)
    testcase.write(str(n) + "\n")

    for i in range(n):
        ai = randrange(1, 10e9 + 1)
        testcase.write(str(ai) + (" " if i < n - 1 else ""))

    testcase.write("\n")
    testcase.close()

    solution = open('resposta%s.txt' % uid, 'w')
    solution.close()