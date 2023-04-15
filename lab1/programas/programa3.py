# -*- coding: utf-8 -*-
import re
import sys

def prog(texto):
<<<<<<< HEAD
    match = re.findall(r'(?:\n| )*"tag": "(.*)",(?:\n| )*"patterns": \[((?:(?:\n| )*".*",)*(?:(?:\n| )*)".*")', texto, re.MULTILINE)
    #                    0                 1                            2(             3    )                 4                                 
    diccionario = {}
    for m in match:
        patterns = re.findall(r'"(.*)",', m[1], re.MULTILINE)
        diccionario[m[0]] = len(patterns) + 1 #agregar el que no tiene , del final

    resultado = "\n".join([clave + " " + str(diccionario[clave]) for clave in diccionario])
    
    return resultado
=======
    
    ret = len(re.findall(r'".*?"', texto))
    #ret = len(re.findall(r'"patterns": [ "(.*)"],', texto))
    #match = re.findall(r'"tag": "(.*)",', texto)
    #ret = " ".join(match)
    
   
    return f"{ret}"
>>>>>>> 0efc050c02729eb4ef4ccc9cde1d6136f05a10ac

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
