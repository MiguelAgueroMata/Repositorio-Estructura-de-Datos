#include <iostream>
#include <string>
#include "linkedList.h"
#include "news.cpp"


int main()
{
    linkedList testing;

    testing.addToEnd("Goku vs Vegeta");
    testing.addToEnd("Bitcoin cae por debajo de $25000");
    testing.addToEnd("Premier One Piece Live Action");
    testing.addToEnd("Eliminar");
    testing.addToEnd("God Irene se casa conmigo");
    testing.addToStart("primero");
    testing.insert("posicion", 14);
    testing.addToStart("segundo");
    testing.addToStart("tercero");
    testing.addToStart("cuarto");


    /*testing.findByWord("primero");
    testing.findByWord("posicion");
    testing.findByWord("Eliminar");
    testing.findByPosition(6);
    testing.findByPosition(1);
    testing.findPositionOf("Premier One Piece Live Action");*/

    //testing .deleteByPosition(2);
    //testing .deleteByPosition(15);


    //testing.print();

    //testing.deleteByTitle("posicion");
    //testing.deleteByTitle("primero");
    //testing.deleteByTitle("prifgasdgasg");

    testing.print();

    testing.relocate("segundo", 4);

    testing.print();
    //testing.printTopFive();

    cin.get();
    return 0;
}