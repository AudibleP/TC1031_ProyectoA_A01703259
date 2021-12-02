# Biblioteca de Steam fuera de Steam...
***¿Por qué usarla? Nadie lo sabe*** (qué buen slogan)

Este proyecto busca hacer una biblioteca de tus juegos en steam y todas sus características e información. 

#Competencias de la entrega final.
##SICT0301B: Evalúa los componentes.
###Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa
Dentro de casos.cpp se encontrara un main que funcionara como los casos de prueba implementados por nuestro maestro Benjamin y dira si los .h del proyecto funcionan con datos fuera del proyecto.

##SICT0303B: Implementa acciones científicas
###Implementa mecanismos para consultar información de las estructras correctos
Dentro de test.cpp en la parte de sorts y arboles, la tercera opcion siendo "Consulta informacion de un juego" te deja buscar por nombre cualquier juego dentro del vector y te dice cuanto tiempo tienes jugando.

###Implementa mecanismos de escritura de archivos correctos
Dentro de test.cpp en la parte de sorts y arboles, la segunda opcion aparte de ordenarte los valores por nombre u horas, tambien hara un archivo .txt de tus juegos ordenados.

# Avance 1 (Competencias).
Este avance enseña la libreria sólo con dos datos: el nombre y el tiempo de juego en horas y ordena por orden alfabetico.

## SICT0303B: Implementa acciones científicas
### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa.
Para lograr leer los juegos en esta entrega se creó un archivo llamado ***Steam.csv*** los cuales se ordenan por orden alfabético.

## SICT0302B: Toma decisiones
### Selecciona un algoritmo de ordenamiento adecuado al problema
Se trabajó con **MERGE** sort ya que su nivel de complejidad y rapidez ayudan a este tipo de ejercicios, aparte de que se buscará en siguientes entregas que el usuario pueda decidir qué ordenar y no sólo ordenar el nombre.

## SICT0301B: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para todo el programa y sus componetes.
En este avance sólo tengo una cosa para analizar y en este caso es un ***MERGE SORT*** el cual tiene una complejidad de *O(n log(n))* y para el espacio simplemente es *O(n)*

# Avance 2 (Competencias).
Este avance rompio el merge sort (xd), pero se le pueden añadir nombres a la lista, borrar nombres y consultar la lista completa.

## SICT0301B: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para todo el programa y sus componetes.
Se uso una linkedList simple, lo cual quiere decir que  en su peor de los casos es un O(n) y sus funciones como insertion son O(1).

# Avance 3 (Competencias).
En este avance se arreglo y mejoro todo lo que tiene que ver con sorts, ya que ahora se puede acomodar de distintas formas y por falta de tiempo los arboles solo muestran los valores de horas. (Tambien se elimino lo de listas).

## SICT0301B: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes.
Mergesort tiene una complejidad de O(n log(n)) para todos sus casos con una complejidad unica de O(n).
El uso de un Árbol de Búsqueda Binaria posee una complejidad de O(n) para los peores casos en inserción de datos, el acceso al árbol y la búsqueda de valores.
### Casos de prueba
Al momento de iniciar el programa saldra un menu el cual mostrara tres opciones, si presionas el boton 1 te desplegara la base de datos de los juegos en desorden, si presionas 2 mostrara un segundo menu que preguntara como se quiere ordenar: si presionas 1 lo ordenara por nombre y si presionas 2 lo ordenara por hora y regresando al primer menu, si presionas 3 te enseñara las 4 maneras diferentes de impresion del bst en el siguiente ordenÑ preOrder, inOrder, postOrder y levelbyLevel.

##SICT0302B: Toma decisiones
###Usa un árbol adecuado para resolver un problema.
Se uso un arbol bst que se encuentra en su respectivo archivo y lo que fue implementado de este fue su manera de agregar y consultar los datos que se habian agregado a este, apaerte de almacenarlos de distintas maneras.


Ricardo Nunez Alanis  A01703259
