# -*- coding: utf-8 -*-
import re
import sys

def prog(texto):
    #Cambiamos patterns
        
    string = texto
    pattern = r'("patterns": \[)((\n| )*)(".*"),(?:(?:\n| )*".*",)*(?:\n| )*".*"((\n| )*)(\],)((\n| )*)'
    repl = r'\1\2\4\5\7\8'
    text = re.sub(pattern, repl, string)

    #Cambiamos responses

    pattern = r'("responses": \[)((\n| )*)(".*"),((?:(?:\n| )*".*",)*(?:\n| )*".*")'
    repl = r'\1\2\4'
    text = re.sub(pattern, repl, text)
    return text

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
