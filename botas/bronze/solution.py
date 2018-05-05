from sys import stdin
from sys import stdout

def main():

    # Leitura da entrada
    n = int(stdin.readline())
    botas = []
    
    for _ in range(0, n):
        m, l = stdin.readline().split()
        m = int(m)
        
        botas.append((m, l))

    # Lista de botas sem par percorridos
    percorridas = []

    # Número de pares formados
    r = 0

    # Determina o número de pares que podem ser formados
    for m, l in botas:

        # Par de botas complementar
        comp = (m, 'E' if l == 'D' else 'D')

        # Se já viu o complementar, soma um e tira
        # os dois pares da lista
        if comp in percorridas:
            percorridas.remove(comp)
            r += 1

        # Adiciona o pé atual na lista
        else:
            percorridas.append((m, l))

    print(r)

if __name__ == "__main__":
    main()
