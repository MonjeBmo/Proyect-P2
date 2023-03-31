#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// struct reference pila
struct nodoPila
{
    int d;
    struct nodoPila *ptrS;
};

typedef nodoPila NodoPila;
typedef NodoPila *ptrNodoPila;

// prototypes functions pila
void push(ptrNodoPila *ptr, int value);
char pop(ptrNodoPila *ptr);
int isEmptyPila(ptrNodoPila ptr);
void printPila(ptrNodoPila ptr);
void printInversePila(ptrNodoPila ptr);
void modifyLastValue(ptrNodoPila ptr);
void deletePila(ptrNodoPila *ptr);

// All app
void generateData(int cant, ptrNodoPila *ptrP);
void instructions();

int main()
{
    ptrNodoPila ptrPila = NULL;
    int op;
    int value;
    instructions();
    printf("\n Que desea realizar?");
    scanf("%d", &op);
    while (op != 5)
    {
        system("clear");
        switch (op)
        {
        case 1:
        {
            int c = 0;

            cout << endl;
            cout << "Ingrese la cantidad de caracteres: ";
            cin >> c;
            while (c >= 50)
            {
                cout << endl
                     << "Error - No mayor a 50" << endl;
                cout << "Ingrese la cantidad de caracteres: ";
                cin >> c;
            }
            generateData(c, &ptrPila);
            break;

            break;
        }

        case 3:
        {
            cout << "Mostrar Pila" << endl
                 << endl;
            cout << "<----------------Pila---------------->" << endl;
            printPila(ptrPila);
            break;
        }
        case 6:
        {
            deletePila(&ptrPila);
            cout << "Pila destruida." << endl;
            break;
        }
        case 7:
        {
            cout << "ADIOS!!!" << endl;
            break;
        }

        default:
        {
            cout << "Error - opcion no valida!";
            break;
        }
        }
        instructions();
        cout << "Que desea realizar? ";
        cin >> op;
    }
}

void generateData(int cant, ptrNodoPila *ptrP)
{
    int data[cant];
    // generate data
    srand(time(NULL));
    for (int i = 0; i <= cant; i++)
    {
        data[i] = 1 + rand() % (50 - 1 + 1);
    }
    cout << endl
         << "Llenando Pila! ..." << endl;
    for (int i = 0; i <= cant; i++)
    {
        push(ptrP, data[i]);
    }
}

void instructions()
{
    cout << endl
         << "<-- Proyecto P2 -->" << endl
         << endl;
    cout << "1 - Ingreso - PUSH" << endl;
    cout << "2 - Eliminar Nodo - POP" << endl;
    cout << "3 - Imprimir" << endl;
    cout << "4 - Imprimir Inverso" << endl;
    cout << "5 - Modificar ultimo elemento" << endl;
    cout << "6 - Destruir Pila" << endl;
    cout << "7 - Salir" << endl;
}

// functions pila
void push(ptrNodoPila *ptr, int value)
{
    ptrNodoPila ptrNuevo;
    ptrNuevo = (NodoPila *)malloc(sizeof(nodoPila));

    if (ptrNuevo != NULL)
    {
        ptrNuevo->d = value;
        ptrNuevo->ptrS = *ptr;
        *ptr = ptrNuevo;
    }
    else
    {
        printf("%d no se inserto", value);
    }
}

char pop(ptrNodoPila *ptr)
{
    ptrNodoPila ptrTemp;
    char valueDelete;
    ptrTemp = *ptr;
    valueDelete = (*ptr)->d;
    *ptr = (*ptr)->ptrS;
    free(ptrTemp);
    return valueDelete;
}

int isEmptyPila(ptrNodoPila ptr)
{
    return ptr == NULL;
}

void printPila(ptrNodoPila ptr)
{
    if (isEmptyPila(ptr))
    {
        printf("La pila esta vacia\n");
    }
    else
    {
        printf("La pila es: \n");
        while (ptr != NULL)
        {
            cout << "| " << ptr->d << " |\n";
            ptr = ptr->ptrS;
        }
        printf("NULL\n\n");
    }
}

void deletePila(ptrNodoPila *ptr)
{
    ptrNodoPila actual = *ptr;
    ptrNodoPila siguiente;

    while (actual != NULL)
    {
        siguiente = actual->ptrS;
        free(actual);
        actual = siguiente;
    }

    *ptr = NULL;
}

void printInversePila(ptrNodoPila ptr) {}

void modifyLastValue(ptrNodoPila ptr) {}