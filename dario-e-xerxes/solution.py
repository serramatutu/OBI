from sys import stdin

def dario_ganha(d, x):
    """Determina se Dário ganha de Xerxes dados D (mão de dário) e 
    X (mão de xerxes).
    
    D ganha de X se X for exatamente uma ou duas posições à frente de 
    D no sentido horário num círculo de 5 posições."""

    return x == (d + 1) % 5 or x == (d + 2) % 5

if __name__ == "__main__":

    # Número de rodadas
    n = int(stdin.readline())

    # Rodadas...
    dario = 0       # Vitórias de Dário
    xerxes = 0      # Vitórias de Xerxes

    for _ in range(n):
        d, x = [int(x) for x in stdin.readline().split()]

        if dario_ganha(d, x):
            dario += 1
        else:   # Não tem empate
            xerxes += 1

    if dario > xerxes:
        print('dario')
    else:   # Sem empates
        print('xerxes')