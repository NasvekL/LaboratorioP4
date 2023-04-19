# -*- coding: utf-8 -*-
import re
import sys

def prog(texto):
    match = re.findall(r'"tag": "(.*)",(?:\n| )*"patterns": \[((?:(?:\n| )*".*",)*(?:\n| )*".*")(?:\n| )*\],(?:\n| )*"responses": \[((?:(?:\n| )*".*",)*(?:\n| )*".*")', texto, re.MULTILINE)
    #                                    0(  )                        1(                                    )                                 
    
    
    #Cambiamos tag
    pattern = r'("tag": )"(.*)"'
    string = texto  
    repl = r'\1"T"'
    text = re.sub(pattern, repl, string)
    

    #Cambiamos patterns
    
    pattern = r'("patterns": \[)((\n| )*)(?:(?:\n| )*".*",)*(?:\n| )*".*"((\n| )*)(\],)((\n| )*)'
    repl = r'\1\2"P"\4\6\7'
    text = re.sub(pattern, repl, string)


    #Cambiamos responses

    pattern = r'("responses": \[)((\n| )*)((?:(?:\n| )*".*",)*(?:\n| )*".*")'
    repl = r'\1\2"R"'
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
