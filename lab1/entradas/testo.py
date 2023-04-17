# -*- coding: utf-8 -*- hola
import re
import sys
import os
import glob

def prog(texto):
    match = re.findall(r'(?:\n| )*"tag": "(.*)",(?:\n| )*"patterns": \[((?:(?:\n| )*".*",)*(?:(?:\n| )*)".*")', texto, re.MULTILINE)
    #                                    0(  )                        1(                                    )                                 
    diccionario = {}
    for m in match:
        patterns = re.findall(r'"(.*)"', m[1], re.MULTILINE)
        diccionario[m[0]] = len(patterns)

    resultado = "\n".join([clave + " " + str(diccionario[clave]) for clave in diccionario])
    
    return resultado


if __name__ == "__main__":
    jeison = 1
    f = open("/home/nahuel/Programacion/p4/LaboratorioP4/lab1/entradas/"+str(jeison)+".json", 'r') # abrir archivo entrada
    datos = f.read()       # leer archivo entrada
    f.close()
    prog(datos)
    print(datos)