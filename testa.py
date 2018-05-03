# -*- coding: UTF-8 -*-

from glob import glob
from argparse import ArgumentParser

import os
import re
import shutil

def get_os_command(program_invoke, input_file_name):
    if os.name == 'nt':
        return "%s < %s" % (program_invoke, input_file_name)
    elif os.name == 'posix':
        return "cat %s | %s" % (input_file_name, program_invoke)
    else:
        return ""

def teste(program_invoke, args):
    all_testcases_ok = True

    program_invoke = (program_invoke) % (args.folder)

    for teste in glob('%s/teste*.txt' % (args.folder)):
        print('-' * 80)
        print('Caso de teste: `%s`' % (teste))
        print('-' * 80)
        print('Saída:')

        # r = re.split("\r?\n", os.popen((program_invoke + ' < %s') % (args.folder, teste)).read())
        r = re.split("\r?\n", os.popen(get_os_command(program_invoke, teste)).read())
        
        expected = open("%s/resposta%s" % (args.folder, re.search('(?<=teste).*', teste).group(0)), "r")

        testcase_ok = True

        for i in range(len(r)):
            line = expected.readline().strip()

            print('\t', end='')

            if line != r[i]:
                print(r[i], " <= Incorreto, esperado: ", line)
                testcase_ok = False
                all_testcases_ok = False
            else:
                print(r[i])

        print()

        if testcase_ok:
            print("Resultado: OK!")

        else:
            print("Resultado: Falhou")

        print()

    if all_testcases_ok:
        print("Todos os casos de teste foram bem sucedidos!")
    else:
        print("Alguns casos de teste falharam, reveja seu código e tente novamente")

if __name__ == "__main__":
    parser = ArgumentParser(description='Testa uma solução para um problema.')

    parser.add_argument(
        dest='language', 
        type=str,
        help='Linguagem (py|cpp)'
    )

    parser.add_argument(
        dest='folder',
        type=str,
        help='Nome da pasta da solução'
    )

    args = parser.parse_args()

    print('OS: %s' % (os.name))

    if args.language == 'py':

        teste('python3 %s/solution.py', args)

    elif args.language == 'cpp':

        if not os.path.exists('temp'):
            os.makedirs('temp')

        os.popen('g++ -std=c++11 -lm -o "temp/%s.exe" %s/solution.cpp' % (args.folder, args.folder)).read()

        teste('temp/%s.exe', args)

        shutil.rmtree('temp', ignore_errors=True)

    else:
        print('Linguagem `%s` não disponível: ' % (args.language))