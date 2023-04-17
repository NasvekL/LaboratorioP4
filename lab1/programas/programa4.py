# -*- coding: utf-8 -*-
import re
import sys

def prog(texto):
    match = re.findall(r'"tag": "(.*)",(?:\n| )*"patterns": \[((?:(?:\n| )*".*",)*(?:\n| )*".*")(?:\n| )*\],(?:\n| )*"responses": \[((?:(?:\n| )*".*",)*(?:\n| )*".*")', texto, re.MULTILINE)
    #                                    0(  )                        1(                                    )                                 
    diccionario1 = {}
    dic2 = {}
    for m in match:
        patterns = re.findall(r'"(.*)"', m[1], re.MULTILINE)
        responses = re.findall(r'"(.*)"',m[2],re.MULTILINE)
        diccionario1[m[0]] = len(patterns)
        dic2[m[0]]= len(responses)
    resultado = "\n".join([clave + " " + str(diccionario1[clave]) + " " + str(dic2[clave]) for clave in diccionario1])
    return resultado

if __name__ == '__main__':
    entrada = sys.argv[1]  # archivo entrada (param)
    salida = sys.argv[2]   # archivo salida (param)  jkhkjhjk
    
    f = open(entrada, 'r') # abrir archivo entrada
    datos = f.read()       # leer archivo entrada
    f.close()              # cerrar archivo entrada
    
    ret = prog(datos)      # ejecutar er
    
    f = open(salida, 'w')  # abrir archivo salida
    f.write(ret)           # escribir archivo salida
    f.close()              # cerrar archivo salida
