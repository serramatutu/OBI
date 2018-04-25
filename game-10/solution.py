from sys import stdin
from sys import stdout

def main():

    # Leitura da entrada
    n = int(stdin.readline())
    d = int(stdin.readline())
    a = int(stdin.readline())

    # Saída
    if d < a:
        print(n + d - a)
    else:
        print(d - a)
    
if __name__ == "__main__":
    main()