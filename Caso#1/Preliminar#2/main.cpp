#include <iostream>
#include <string>
#include "linkedList.h"


int main()
{
    linkedList testing;

    testing.addToEnd("Goku vs Vegeta");
    testing.addToEnd("Bitcoin cae por debajo de $25000");
    testing.addToEnd("Premier One Piece Live Action");
    testing.addToEnd("God Irene se casa conmigo");

    testing.print();

    cin.get();
    return 0;
}