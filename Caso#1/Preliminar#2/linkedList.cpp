#include "linkedList.h"

linkedList::linkedList()
{
    primero = actual = NULL;
}

int linkedList::listLength()
{
    int cont = 0;

    nodeList aux;
    aux = primero;

    if(isEmpty())
    {
        return cont;
    }
    else
    {
        while(aux != NULL)
        {
            aux = aux->siguiente;
            cont++;
        }
    }
    return cont;
}

void linkedList::addToEnd(string nTitle)
{
    if(isEmpty())
    {
        primero = new node(nTitle);
        primero->anterior = NULL;
    }
    else
    {
        nodeList aux = primero;
        while(aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = new node(nTitle);
        aux->siguiente->anterior = aux;
    }
}

void linkedList::addToStart(string newsTitle)
{
    if(isEmpty())
    {
        primero = new node(newsTitle);
        primero->anterior = NULL;
    }
    else
    {
        nodeList nuevo = new node(newsTitle);
        nuevo->siguiente = primero;
        primero->anterior = nuevo;
        primero = nuevo;
    }
}

void linkedList::insert(string newsTitle, int pos)
{
    if (isEmpty())
    {
        primero = new node(newsTitle);
        primero->anterior = NULL;
    }
    else
    {
        if(pos > listLength())
        {
            cout << "Posicion deseada de insercion mayor al largo de lista, se inserta al final" << endl;
            addToEnd(newsTitle);
        }
        else
        {
            if(pos <=1)
            {
                addToStart(newsTitle);
            }
            else
            {
                nodeList aux = primero;
                int posActual = 1;
                while(aux->siguiente != NULL && posActual < pos-1)
                {
                    aux = aux->siguiente;
                    posActual++;
                }
                nodeList nuevo = new node(newsTitle);
                nuevo->siguiente = aux->siguiente;
                nuevo->anterior = aux;
                aux->siguiente = nuevo;
                nuevo->siguiente->anterior = nuevo;

            }
        }
    }
}

node* linkedList::findByWord(string newsTitle)
{
    if(isEmpty())
    {
        cout << "Lista se encuentra vacia." << endl;
        return nullptr;
    }
    else
    {
        nodeList actual = primero;
        int cont = 1;
        while (actual != NULL)
        {
            if(actual->newsTitle == newsTitle)
            {
                cout << "Headline encontrado en la posicion " << cont << ": \nTitulo:  " << actual->newsTitle << endl << endl;
                return actual;
            }
            else
                actual = actual->siguiente;
                cont++;
        }
    }
    cout << "No match." << endl;
    return nullptr;
}

node* linkedList::findByPosition(int position)
{
    if(isEmpty())
    {
        cout << "Lista se encuentra vacia." << endl;
        return nullptr;
    }

    else
    {
        if (position > listLength())
        {
            cout << "Posicion no existe." << endl;
        }
        else
        {
            if(position <=1)
            {
                cout << "Headline encontrado en la posicion " << position << ": \nTitulo:  " << primero->newsTitle << endl << endl;
                return primero;
            }
            else
            {
                nodeList aux = primero;
                int posActual = 1;
                while(aux != NULL && posActual < position)
                {
                    aux = aux->siguiente;
                    posActual++;
                }
                cout << "Headline encontrado en la posicion " << posActual << ": \nTitulo:  " << aux->newsTitle << endl << endl;
                return aux;
            }

        }
    }
    cout << "No match." << endl;
    return nullptr;
}

int linkedList::findPositionOf(string newsTitle)
{
    if(isEmpty())
    {
        cout << "Lista se encuentra vacia." << endl;
        return 0;
    }

    else
    {
        int cont = 1;
        nodeList aux = primero;

        do
        {
            if(aux->newsTitle == newsTitle)
            {
                cout << "Headline encontrado en la posicion " << cont << ": \nTitulo:  " << aux->newsTitle << endl << endl;
                return cont;
            }
            else
            {
                cont++;
                aux= aux->siguiente;
            }
        } while (aux != NULL);
        
    }
    cout << "No match." << endl;
    return 0;
}

void linkedList::deleteLast()
{
    if(isEmpty())
    {
        cout << "Lista vacia." << endl << endl;
    }
    else
    {
        if(primero->siguiente == NULL)
        {
            nodeList temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            nodeList aux = primero;
            while(aux->siguiente->siguiente != NULL)
            {
                aux = aux->siguiente;
            }

            nodeList temp = aux->siguiente;
            aux->siguiente = NULL;
            delete temp;
        }
    }
}
void linkedList::deleteByTitle(string newsTitle)
{
    if (isEmpty())
    {
        cout << "La lista se encuentra vacia." << endl << endl;
    }
    else
    {
        nodeList actual = primero;

        while (actual != NULL)
        {
            if (actual == primero && actual->newsTitle == newsTitle)
            {
                cout << "--------------------------------------" << endl;
                cout << "Titulo: " << actual->newsTitle << endl;
                cout << "Eliminado." << endl << endl;
                nodeList temp = primero;
                primero = primero->siguiente;
                delete temp;
                actual = primero; // Advance to the next node
            }
            else if (actual->siguiente != NULL)
            {
                if (actual->siguiente->newsTitle == newsTitle)
                {
                    nodeList temp = actual->siguiente;
                    cout << "--------------------------------------" << endl;
                    cout << "Titulo: " << temp->newsTitle << endl;
                    cout << "Eliminado." << endl << endl;
                    actual->siguiente = actual->siguiente->siguiente;
                    if (actual->siguiente != NULL) // Check if it's not the last node
                    {
                        actual->siguiente->anterior = actual;
                    }
                    delete temp;
                }
                else
                {
                    actual = actual->siguiente; // Advance to the next node
                }
            }
            else if (actual->siguiente == NULL && actual->newsTitle == newsTitle)
            {
                delete actual;
                actual = NULL; // Set to NULL to exit the loop
            }
            else
            {
                //cout << "No match." << endl;
                actual = NULL; // Set to NULL to exit the loop
            }
        }
    }
}

void linkedList::deleteByPosition(int position)
{
    if (isEmpty())
    {
        cout << "La lista se encuentra vacia." << endl << endl;
    }
    else
    {
        if (position > listLength())
        {
            cout << "Posicion " << position << " no existe." << endl << endl;
        }
        else
        {
            if(position <=1)
            {
                nodeList temp = primero;
                cout << "--------------------------------------" << endl;
                cout << "Titulo: " << primero->newsTitle << endl;
                cout << "Eliminado." << endl;
                primero = primero->siguiente;
                delete temp;
                
            }
            else
            {
                nodeList aux = primero;
                int posActual = 1;
                while(aux != NULL && posActual < position)
                {
                    aux = aux->siguiente;
                    posActual++;
                }
                cout << "--------------------------------------" << endl;
                cout << "Titulo: " << aux->newsTitle << endl;
                cout << "Eliminado." << endl << endl;
                aux->siguiente->anterior = aux->anterior;
                aux->anterior->siguiente = aux->siguiente;
                delete aux;
            }
        }
    }
}

void linkedList::print()
{
    nodeList aux = primero;

    int cont = 1;
    while(aux != NULL)
    {
        cout << cont << " .Titulo: " << aux->newsTitle << endl;
        aux = aux->siguiente;
        cont++;
    }
    cout << endl;
}

void linkedList::printTopFive()
{
    nodeList aux = primero;

    if (listLength() < 5)
    {
        while(aux != NULL)
        {
            cout << "Titulo: " << aux->newsTitle << endl;
            aux = aux->siguiente;
        }
        cout << endl;
    }

    else
    {
        int i = 0;
        cout << "\t\tTOP FIVE" << endl;
        while(i < 5)
        {
            cout << (i + 1) << " .Titulo: " << aux->newsTitle << endl;
            aux = aux->siguiente;
            i++;
        }
        cout << endl;
    }
}

void linkedList::relocate(string newsTitle, int movement)
{
    int location = findPositionOf(newsTitle);
    if (location = 0)
    {
        cout << "No se encuentra la noticia." << endl;
    }
    else
    {
        if (movement > 0)
        {
            location = location + movement;
            deleteByTitle(newsTitle);
            insert(newsTitle, location);
            
        }
        else
        {
            location = location - movement;
            deleteByTitle(newsTitle);
            insert(newsTitle, location);
        }
    }
            
}
