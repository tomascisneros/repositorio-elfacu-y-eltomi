#include <stdio.h>
#include <stdlib.h>

int main()
{
    int codigoVendedor[3], vendedoresMax[3], i, j = 0, k, x, j2 = 0;

    float cantVentaDinero[3], cantDinero[3];

    for(i = 0; i < 3; i++)
    {
        printf("Ingrese codigo de vendedor: ");
        scanf("%d", &codigoVendedor[i]);

        printf("Ingrese la cantidad de dinero de ese vendedor: ");
        scanf("%f", &cantDinero[i]);
    }

    int cod;
    printf("Ingrese el codigo de vendedor a trabajar: ");
    scanf("%d", &cod);

    while(cod != 0)
    {
        float precioProducto, cantPlata = 0;
        int cantidadVendida;

        printf("Ingrese el precio unitario del producto: ");
        scanf("%f", &precioProducto);

        printf("Ingrese la cantidad vendida de ese producto: ");
        scanf("%d", &cantidadVendida);

        cantPlata = cantidadVendida * precioProducto;

        for(i = 0; i < 3; i++)
        {
            if(codigoVendedor[i] == cod)
            {
                cantVentaDinero[j2] = cantPlata;
                j2++;

                if(cantidadVendida > 300)
                {
                    vendedoresMax[j] = cod;
                    j++;
                }

                i = 3;

            }
        }

        printf("Ingrese el codigo de vendedor a trabajar: ");
        scanf("%d", &cod);
    }

    k=0;
    x=3;

    int aux;
    float auxF;

    while(k==0)
    {
        x--;
        k=1;
        for(i=0;i<x;i++)
        {
            if(cantVentaDinero[i]<cantVentaDinero[i+1])
            {


                auxF = cantDinero[i];
                cantDinero[i] = cantDinero[i+1];
                cantDinero[i+1] = auxF;

                aux = codigoVendedor[i];
                codigoVendedor[i] = codigoVendedor[i+1];
                codigoVendedor[i+1] = aux;

                auxF = cantVentaDinero[i];
                cantVentaDinero[i] = cantVentaDinero[i+1];
                cantVentaDinero[i+1] = auxF;

                k=0;
            }
        }
    }


    //Print
    for(i = 0; i < 3; i++)
    {
        printf("cod: %d \n", codigoVendedor[i]);
        printf("dinero vendido: %f \n", cantVentaDinero[i]);
        printf("cantidad de dinero inicial: %f \n", cantDinero[i]);

    }

    printf("vendio mas de 300: ");

    for(i = 0; i < j; i++)
    {
        printf("%d \n", vendedoresMax[i]);
    }

    return 0;
}
