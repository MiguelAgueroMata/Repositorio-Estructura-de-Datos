#include "linkedList.h"

linkedList::linkedList()
{
    primero = actual = NULL;
}

bool linkedList::isEmpty()
{
    return primero = NULL;
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

void linkedList::addToEnd(string newsTitle)
{
    if(isEmpty())
    {
        primero = new node(newsTitle);
        primero->anterior = NULL;
    }
    else
    {
        nodeList aux;
        while(aux->siguiente = NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = new node(newsTitle);
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

        while (actual != NULL)
        {
            if(actual->newsTitle == newsTitle)
            {
                cout << "Titulo:  " << actual->newsTitle << endl;
                return actual;
            }
            else
                actual = actual->siguiente;
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
                cout << "Titulo: " << primero->newsTitle << endl;
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
                cout << "Titulo: " << aux->newsTitle << endl;
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
                cout << "Titulo: " << aux->newsTitle << endl;
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

void linkedList::deleteByTitle(string newsTitle)
{
    if (isEmpty())
    {
        cout << "La lista se encuentra vacia." << endl;
    }
    else
    {
        nodeList actual = primero;

        while (actual!= NULL)
        {
            if(actual->newsTitle == newsTitle && actual->siguiente != NULL)
            {
                cout << "Titulo:  " << actual->newsTitle << endl;
                cout << "Eliminado de la lista." << endl;
                actual->siguiente->anterior = actual->anterior;
                actual->anterior->siguiente = actual->siguiente;
                
            }
            else
                if(actual->siguiente == NULL)
                    delete actual;    

            actual = actual->siguiente;           
        }
    }
    cout << "No match." << endl;
}

void linkedList::deleteByPosition(int position)
{
    if (isEmpty())
    {
        cout << "La lista se encuentra vacia." << endl;
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
                nodeList temp = primero;
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
                cout << "Titulo: " << aux->newsTitle << endl;
                cout << "Eliminado." << endl;
                aux->siguiente->anterior = aux->anterior;
                aux->anterior->siguiente = aux->siguiente;
                delete aux;
            }
        }
    }
    cout << "No match." << endl;
}

void linkedList::print()
{
    nodeList aux = primero;

    while(aux != NULL)
    {
        cout << "Titulo: " << aux->newsTitle << endl;
        aux = aux->siguiente;
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
        while(i < 5)
        {
            cout << "Titulo: " << aux->newsTitle << endl;
            aux = aux->siguiente;
        }
        cout << endl;
    }
}