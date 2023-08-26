#include <iostream>
#include <string>

void add(string pData)
{
    //Esta funcion agregaria los titulos/datos a la lista.
}

void insert(string pData, int position)
{
    //Agregar un dato en una posicion en especifico de la lista.
}

bool isEmpty()
{
    //Retorna true(o false como uno lo escoja) si la lista se encuentra vacia.
}

int listLength()
{
    //Retorna el largo actual de la lista.
}

void find(string pNoticia)
{
    //Busca una o las noticias que contengan las palabras que se brindaron.
}

void findByPosition(int position)
{
    //Buscar y imprime la noticia que se encuentra en la posicion seleccionada
    //O muestra mensaje de advertencia en caso de que no exista esa posicion.
}

int findPosition (string newsNameOrWord)
{
    //Buscar un match de nombre o palabra y devuelve la posicion en que se encuentra.
}

void deleteByName(string pData)
{
    //Elimina las noticias que tenga el nombre o palabra que se brindo.
    //Podemos brindar un nombre exacto o una palabra y la funcion buscara matchs.
}

void deleteByPosition(int position)
{
    //Elimina la noticias que se encuentre en posicion brindada.
}

void printList()
{
    //Imprime el contenido de la lista.
}

void printToFive()
{
    //Imprime las primeras cinco noticias.
}

void changePosition(int newsToRelocate, int yUp_or_yDown)
{
    //Dada la posicion de la noticia que se quiere rehubicar
    //Se mueve hacia arriba o abajo de la lista 
    //Segun la cantidad de veces indicada en el segundo parametro.
}