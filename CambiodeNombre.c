#include <stdio.h>
#include <stdlib.h>

int main()
{
    int codigoProducto[3], stockProducto[3], i = 0, cod, cant, k , x, j=0, aux,pmv[3];
    char tipoOperacion;

    for(i = 0; i < 3; i++)
    {
        printf("Ingrese el codigo del producto: ");
        scanf("%d", &codigoProducto[i]);
        printf("Ingrese el stock de ese producto: ");
        scanf("%d", &stockProducto[i]);
    }


    //ordenamiento
    k=0;
    x=3;
    while(k==0)
    {
        x--;
        k=1;
        for(i=0;i<x;i++)
        {
            if(codigoProducto[i]>codigoProducto[i+1])
            {
                aux = codigoProducto[i];
                codigoProducto[i] = codigoProducto[i+1];
                codigoProducto[i+1] = aux;

                aux = stockProducto[i];
                stockProducto[i] = stockProducto[i+1];
                stockProducto[i+1] = aux;

                k=0;
            }
        }
    }

    //busqueda y actualizacion
    printf("Ingrese el codigo de producto a trabajar (0 para finalizar): ");
    scanf("%d", &cod);

    while(cod != 0)
    {
        int pos;
        int verificacion = 0;
        for(i = 0; i < 3; i++)
        {
            if(codigoProducto[i] == cod)
            {
                pos = i;
                verificacion = 1;
            }
        }

        if(verificacion == 0)
        {
            printf("Codigo no encontrado, ");
        }
        else
        {
            printf("Ingrese el tipo de operacion (e para entrada, s para salida): ");
            fflush(stdin);
            scanf("%c", &tipoOperacion);
            printf("Ingrese la cantidad a trabajar: ");
            scanf("%d", &cant);

            switch(tipoOperacion)
            {
            case 'e':
                stockProducto[pos] += cant;
                break;
            case 's':
                stockProducto[pos] -= cant;
                break;
            default:
                printf("Tipo de operacion erronea, ingrese otra: ");
                fflush(stdin);
                scanf("%c", &tipoOperacion);
                break;
            }
        }

        printf("Ingrese el codigo de producto a trabajar (0 para finalizar): ");
        scanf("%d", &cod);
    }
   //Creacion de un vector a partir de otro
    for(i=0;i<3;i++)
    {
        if(stockProducto[i]>=20)
        {
            pmv[j] = codigoProducto[i];
            j++;
        }
    }
    //salida de datos

    for(i = 0; i < 3; i++)
    {
        printf("Codigo: %d ", codigoProducto[i]);
        printf("Stock: %d \n", stockProducto[i]);
    }
    for(i=0;i<j;i++)
    {
        printf("Los productos con mas de 20 de stock son: %d \n", pmv[i]);
    }

    return 0;
}
