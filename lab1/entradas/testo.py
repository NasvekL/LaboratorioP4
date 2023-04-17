# -*- coding: utf-8 -*- hola
import re
import sys
import os
import glob

def prog(texto):
    match = re.findall(r'(?:\n| )*"tag": "(.*)",(?:\n| )*"patterns": \[((?:(?:\n| )*".*",)*(?:(?:\n| )*)".*")', texto, re.MULTILINE)
    
    return resultado


if __name__ == "__main__":
    jeison = 7
    f = open("/home/nahuel/Programacion/p4/LaboratorioP4/lab1/entradas/"+str(jeison)+".json", 'r') # abrir archivo entrada
    datos = f.read()       # leer archivo entrada
    f.close()
    prog(datos)
    print(datos)