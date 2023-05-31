# -*- coding: utf-8 -*- hola
import re
import sys
import os
import glob

def prog(texto):
    match = re.findall(r'"tag": "(.*)",(?:\n| )*"patterns": \[((?:(?:\n| )*".*",)*(?:\n| )*".*")(?:\n| )*\],(?:\n| )*"responses": \[((?:(?:\n| )*".*",)*(?:\n| )*".*")', texto, re.MULTILINE)
    #                                    0(  )                        1(                                    )                                 
    
    

    #Cambiamos patterns
    
    pattern = r'("patterns": \[)(\n| )*(".*"),(\n| )*(?:(?:\n| )*".*",)*(?:\n| )*".*"((\n| )*)(\])'
    #          1(              )         (2   )                                     )(5 )

    repl = r'\1\2\3'
    text = re.sub(pattern, repl, texto, re.MULTILINE)


    #Cambiamos responses

    pattern = r'("responses": \[)((\n| )*)((?:(?:\n| )*".*",)*(?:\n| )*".*")'
    repl = r'\1\2"R"'
    text = re.sub(pattern, repl, text)





    
    
      
    return text


if __name__ == "__main__":
    jeison = 0
    f = open("/home/nahuel/Programacion/p4/LaboratorioP4/lab1/entradas/"+str(jeison)+".json", 'r') # abrir archivo entrada
    datos = f.read()       # leer archivo entrada
    f.close()
    prog(datos)
    print(datos)