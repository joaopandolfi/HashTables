# HashTables
Hash tables implementadas em C.
 >Três tipos
 
 ~~Apenas dois terminados ainda~~

#Tipos de Hash

 > Tipo 1: Hash sem colisão de elementos

 > Tipo 2: Hash que trata as colisões em forma de uma lista encadeada, ou seja, cada colisão é adicionada a lista para ser percorrida na hora da busca

 > Tipo 3: Hash de hash, cada colisão cria uma subhash e adicona os elementos colididos mudando a semente de cálculo para a hash

#Como usar

Pela linha de comando, chame o programa compilado com os seguintes parametros:

> <executavel> <arquivo de entrada> <buscas> <arquivo de saida>

Exemplo:

> TPAHash.exe entrada2.txt buscas.txt resultados.txt

#Compilar

No Windows: Utilize a IDE DEV C++ e abra o arquivo TPAHash.dev, logo em seguida aperte a tecla F11

No Linux e OSX: gcc -o <nome do executavel> main.c hash1.c hash2.c hash3.c node.c