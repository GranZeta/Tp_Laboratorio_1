#include <stdio.h>
#include <stdlib.h>

int descuento(int a)
{
	float resultado;
	float descuento=0.90;

	resultado= a * descuento;

	return resultado;
}

int interes(int a)
{
	float resultado;
	float interesTotal;
	float interes=0.25;

	interesTotal= a * interes;
	resultado=interesTotal+a;

	return resultado;
}

float conversiones(float a)
{
	float conversion;
	float peso=4606954.55;
	float btc=1;

	conversion= (a * btc) / peso;

	return conversion;
}

float precioKilometro(int a, int b)
{
	float precioKilometro;

	precioKilometro=a/b;

	return precioKilometro;
}

int diferencia(int a, int b)
{
	int resultado;
	if(a > b)
	{
		resultado=a-b;
	}
	else
	{
		resultado=b-a;
	}

	return resultado;
}

void ingresarDatos(int a, int b)
{
	int totalDescuento;
	int totalInteres;
	float conversion;
	int precioK;


	totalDescuento= descuento(a);
	printf("a)El descuento es: $%d \n", totalDescuento);

	totalInteres= interes(a);
	printf("b)El interes es: $%d \n", totalInteres);

	conversion= conversiones(a);
	printf("c)La conversion es: %f BTC \n", conversion);

	precioK = precioKilometro(a,b);
	printf("d)Mostrar precio unitario: $%d \n\n", precioK);

}

int numerosPositivo(int a)
{
    scanf("%d", &a);
    while(a < 0)
    {
        printf("Error, ingrese un numero positivo:");
        scanf("%d", &a);
    }
    return a;
}
