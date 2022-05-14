#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "validaciones.h"


int initPassengers (ePassenger listaPasajeros [],int tamanio)
{
	int i;
	int retorno=-1;

	if(tamanio > 0 && listaPasajeros!= NULL)
	{
		retorno=0;
		for(i=0;i<tamanio;i++)
		{
			listaPasajeros[i].isEmpty = 0;
		}
	}

	return retorno;
}

int altaPasajero(ePassenger listaPasajeros [],int tamanio, int contador)
{
	int indice;
	int retorno;

	indice = buscarLibre(listaPasajeros,tamanio);

	if(indice != -1)
	{
        pedirDatos(listaPasajeros,tamanio,indice);
		listaPasajeros[indice].isEmpty = 1;
		listaPasajeros[indice].id=contador;
		retorno=1;
	}
	return retorno;
}

int findPassengerById(ePassenger listaPasajeros [],int tamanio, int id)
{
	int retorno=-1;
	int i;

	if(tamanio > 0 && listaPasajeros!= NULL)
	{
		for(i=0;i<tamanio;i++)
		{
			if(listaPasajeros[i].isEmpty == 1 && id == listaPasajeros[i].id)
			{
				retorno=i;
				break;
			}
		}
	}

	return retorno;
}


int baja(ePassenger listaPasajeros [],int tamanio,etypeVuelo listaTipoVuelo[],etypePasajero listaTipoPasajero[], int tamanioT)
{
	int i;
	int bajaCode;
	int confirm;
	int retorno=-1;

	printPassengers(listaPasajeros,tamanio,listaTipoVuelo,listaTipoPasajero,tamanioT);
	bajaCode = mostarBaja(listaPasajeros,tamanio);
	confirm = confirmacion();

	if(confirm == 1)
	{
		for(i=0;i<tamanio;i++)
		{
			if(listaPasajeros[i].isEmpty == 1 && bajaCode == listaPasajeros[i].id)
			{
				listaPasajeros[i].isEmpty = -1;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int removePassenger (ePassenger listaPasajeros [],int tamanio, int id)
{
	int retorno=-1;
	int pasajero;

	pasajero=findPassengerById(listaPasajeros,tamanio,id);

	listaPasajeros[pasajero].isEmpty = -1;
	retorno=0;


	return retorno;
}


int sortPassengers(ePassenger listaPasajeros [],int tamanio, int orden)
{
	int retorno=-1;
	int i, j;
	ePassenger aux;


	for(i=0;i<tamanio-1;i++)
		{
			for(j=i+1;j<tamanio;j++)
			{
				if(strcmp(listaPasajeros[i].lastname, listaPasajeros[j].lastname)>0)
				{
					aux = listaPasajeros[i];
					listaPasajeros[i] = listaPasajeros[j];
					listaPasajeros[j] = aux;
				}
				else
				{
					if(strcmp(listaPasajeros[i].lastname, listaPasajeros[j].lastname)==0)
					{
						if(listaPasajeros[i].typePassenger> listaPasajeros[j].typePassenger)
						{
							aux = listaPasajeros[i];
							listaPasajeros[i] = listaPasajeros[j];
							listaPasajeros[j] = aux;
							retorno=0;
						}

					}

				}
			}

		}

	return retorno;
}

void printPassengers(ePassenger listaPasajeros [],int tamanio, etypeVuelo listaTipoVuelo[],etypePasajero listaTipoPasajero[], int tamanioT )
{
	int i;
	int j;
int k;
	int ancho=-25;
	int anchoId=-10;
	printf("+----------+-------------------------+-------------------------+-------------------------+----------+----------+----------+\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoId,"ID", ancho,"Nombre",ancho,"Apellido",ancho,"Precio",anchoId,"Codigo",anchoId,"Tipo",anchoId,"Estado");
	printf("+----------+-------------------------+-------------------------+-------------------------+----------+----------+----------+\n");
	for(i=0;i<tamanio;i++)
	{
		if(listaPasajeros[i].isEmpty==1)
		{
			for(j=0;j<tamanioT;j++)
			{
				if(listaPasajeros[i].statusFlight == listaTipoVuelo[j].statusFlight)
				{
					for(k=0;k<tamanioT;k++)
					{
						if(listaPasajeros[i].typePassenger == listaTipoPasajero[k].typePassenger)
						{
							printf("|%*d|%*s|%*s|%*.2f|%*s|%*s|%*s|\n",anchoId,listaPasajeros[i].id,ancho,listaPasajeros[i].name,ancho,listaPasajeros[i].lastname,ancho,listaPasajeros[i].price,anchoId,listaPasajeros[i].flycode,anchoId,listaTipoPasajero[k].descripcionP,anchoId,listaTipoVuelo[j].descripcion);
						}
					}
				}
			}
		}
	}
	printf("+----------+-------------------------+-------------------------+-------------------------+----------+----------+----------+\n");

}

int sortPassengersByCode(ePassenger listaPasajeros [],int tamanio, int orden)
{
	int retorno=-1;
	int i, j;
	ePassenger aux;

	for(i=0;i<tamanio-1;i++)
	{
		for(j=i+1;j<tamanio;j++)
		{
			if(strcmp (listaPasajeros[i].flycode, listaPasajeros[j].flycode)>0)
			{
				aux=listaPasajeros[i];
				listaPasajeros[i]=listaPasajeros[j];
				listaPasajeros[j]=aux;
				retorno=1;
			}
		}
	}
	return retorno;
}


void cargaPasajeros(ePassenger listaPasajeros [],int tamanio)
{
	int i;
	int ide []={1,2,3,4,5};
	char nombre[][51]={"Martin", "Pablo", "Alberto", "Luis", "Maxi"};
	char apellido[][51]={"Romero", "Cruzero", "Ramirez", "Claro", "Gonzalez"};
	int precio []={200,300,100,50,500};
	char codigo[][51]={"AEP", "EZE", "JNI","LPG", "VAD5", "VDH2"};
	int estado []={1,2,3,2,1};
	int tipo []={1,2,3,2,1};



	for(i=0;i<tamanio;i++)
	{
		listaPasajeros[i].id = ide[i];
		strcpy(listaPasajeros[i].name,nombre[i]);
		strcpy(listaPasajeros[i].lastname,apellido[i]);
		listaPasajeros[i].price = precio[i];
		strcpy(listaPasajeros[i].flycode,codigo[i]);
		listaPasajeros[i].typePassenger = tipo[i];
		listaPasajeros[i].statusFlight = estado[i];
		listaPasajeros[i].isEmpty = 1;
	}
}

void cargaTipoPasajero(etypeVuelo listaTipoVuelo [],int tamanio)
{
	int i;
	int codigo []={1,2,3};
	char nombre[][51]={"Activo", "Demorado", "Cancelado"};

	for(i=0;i<tamanio;i++)
	{
		listaTipoVuelo[i].statusFlight = codigo[i];
		strcpy(listaTipoVuelo[i].descripcion,nombre[i]);
	}
}

void cargaTipoVuelo(etypePasajero listaTipoPasajero [],int tamanio)
{
	int i;
	int codigo []={1,2,3};
	char nombre[][51]={"Niño", "Adolecente", "Anciano"};

	for(i=0;i<tamanio;i++)
	{
		listaTipoPasajero[i].typePassenger = codigo[i];
		strcpy(listaTipoPasajero[i].descripcionP,nombre[i]);
	}
}


int buscarLibre (ePassenger listaPasajeros [],int tamanio)
{

	int index = -1;
	int i;

	for(i=0;i<tamanio;i++) //1
	{
		if(listaPasajeros[i].isEmpty == 0)
		{
			index = i;//1
			break;
		}

	}
	return index;
}


void mostrarPasajerosDeOne(ePassenger listaPasajeros [],int tamanio, etypeVuelo listaTipoVuelo[],etypePasajero listaTipoPasajero[], int tamanioT ,int indice)
{

	int ancho=-25;
	int anchoId=-10;
	int k;
	int j;

	if(listaPasajeros[indice].isEmpty==1)
	{
		for(j=0;j<tamanioT;j++)
		{
			if(listaPasajeros[indice].statusFlight == listaTipoVuelo[j].statusFlight)
			{
				for(k=0;k<tamanioT;k++)
				{
					if(listaPasajeros[indice].typePassenger == listaTipoPasajero[k].typePassenger)
					{
						printf("|%*d|%*s|%*s|%*.2f|%*s|%*s|%*s|\n",anchoId,listaPasajeros[indice].id,ancho,listaPasajeros[indice].name,ancho,listaPasajeros[indice].lastname,ancho,listaPasajeros[indice].price,anchoId,listaPasajeros[indice].flycode,anchoId,listaTipoPasajero[k].descripcionP,anchoId,listaTipoVuelo[j].descripcion);
					}
				}
			}
		}
	}

}

void pedirDatos(ePassenger listaPasajeros [],int tamanio, int indice)
{
	printf("\n=====================================\n\n");

	PedirLetras("Ingrese su Nombre: ","Error, vuelva a ingresar su Nombre\n",  listaPasajeros[indice].name);
	PedirLetras("Ingrese su Apellido: ","Error, vuelva a ingresar su Apellido\n",listaPasajeros[indice].lastname);


	listaPasajeros[indice].price= PedirFlotante("Ingrese Precio de Vuelo: ", "Error solo se pueden ingresar Numeros\n", 1,90000);

	validarCadenaCaracteres("Ingrese Codigo de Vuelo: ","Error, no puede tener mas de 10 caracteres...\n",listaPasajeros[indice].flycode);


	listaPasajeros[indice].typePassenger=minMax("Ingrese Tipo de Pasajero:\n1-Niño.\n2-Adolecente.\n3-Adulto.\nSeleccione: ", "Error, solo puede seleccionar los numeros indicados\n",1,3);

	listaPasajeros[indice].statusFlight=minMax("Ingrese el estado del Vuelo:\n1-Activo.\n2-Demorado.\n3-Cancelado.\nSeleccione: ", "Error, solo puede seleccionar los numeros indicados\n",1,3);


	printf("\n=====================================\n");

}

void llamadaM(ePassenger listaPasajeros [],int tamanio,int i)
{
	int opcion;
	do{
		opcion=mostrarMenuModificar (opcion);

		switch( opcion )
		{
		case 1:
			PedirLetras("Ingrese su Nombre: ","Error, vuelva a ingresar su Nombre\n",  listaPasajeros[i].name);
			break;

		case 2:
			PedirLetras("Ingrese su Apellido: ","Error, vuelva a ingresar su Apellido\n",listaPasajeros[i].lastname);
			break;

		case 3:
			listaPasajeros[i].price= PedirFlotante("Ingrese Precio de Vuelo: ", "Error solo se pueden ingresar Numeros\n", 1,90000);
			break;

		case 4:
			validarCadenaCaracteres("Ingrese Codigo de Vuelo: ","Error, no puede tener mas de 10 caracteres...\n",listaPasajeros[i].flycode);
			break;

		case 5:
			listaPasajeros[i].typePassenger=minMax("Ingrese Tipo de Pasajero:\n1-Niño.\n2-Adolecente.\n3-Adulto.\nSeleccione: ", "Error, solo puede seleccionar los numeros indicados\n",1,3);
			break;

		case 6:
			printf("\nSaliendo de modificar...\n\n");
			break;

		default:
			printf("La opcion ingresada es incorrecta..");
			break;
		}
	}while( opcion != 6 );

}

void informar(ePassenger listaPasajeros [],int tamanio, etypeVuelo listaTipoVuelo[],etypePasajero listaTipoPasajero[],int tamanioT, int contador)
{


	int opcion;
	int ancho=-25;
	int anchoId=-10;


do{
	opcion=mostrarMenuListar(opcion);
	switch(opcion)
	{

	case 1:
		sortPassengers(listaPasajeros,tamanio,1);
		printPassengers(listaPasajeros,tamanio,listaTipoVuelo,listaTipoPasajero,tamanioT);
		break;

	case 2:
		TPS(listaPasajeros,tamanio,contador);
		break;

	case 3:
		sortPassengersByCode(listaPasajeros,tamanio,1);
		printf("+----------+-------------------------+-------------------------+-------------------------+----------+----------+----------+\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoId,"ID", ancho,"Nombre",ancho,"Apellido",ancho,"Precio",anchoId,"Codigo",anchoId,"Tipo",anchoId,"Estado");
		printf("+----------+-------------------------+-------------------------+-------------------------+----------+----------+----------+	\n");
		for(int i=0;i<tamanio;i++)
		{
			if(listaPasajeros[i].statusFlight == 1)
			{
				mostrarPasajerosDeOne(listaPasajeros,tamanio,listaTipoVuelo,listaTipoPasajero,tamanioT,i);
			}

		}
		printf("+----------+-------------------------+-------------------------+-------------------------+----------+----------+----------+\n");
		break;

	case 4:
		printf("\nSalindo de Informar...\n\n");
		break;
	}
	}while(opcion != 4);
}




int mostarBaja(ePassenger listaPasajeros [],int tamanio)
{
	int bajaCode;

	printf("Ingrese ID: ");
	scanf("%d", &bajaCode);

	return bajaCode;
}


int mostrarMenu(int opcion)
{
	opcion =PedirEntero("\n1-Alta\n2-Modificar\n3-Baja\n4-Informar\n5-Salir\nOpcion:","\nError tiene que ingresar una numero\n");

	return opcion;
}

int mostrarMenuListar(int opcion)
{
	opcion =PedirEntero("\n1-Lista ordenada por Apellido y Tipo pasajero.\n2-Total, Promedio y Cantidad que no superan el Promedio.\n3-Lista de los pasajeros por Codigo y Estado.\n4-Salir.\nOpcion: ", "\nError ingrese un numero\n");

	return opcion;
}


int mostrarMenuModificar(int opcion)
{
	opcion =PedirEntero("\n1-Cambiar Nombre.\n2-Cambiar Apellido\n3-Cambiar Precio\n4-Cambiar Codigo\n5-Cambiar Tipo\n6-Salir\nOpcion: ", "\nError ingrese un numero\n");

	return opcion;
}


int modificar(ePassenger listaPasajeros [],int tamanio,etypeVuelo listaTipoVuelo[],etypePasajero listaTipoPasajero[], int tamanioT )
{
	int i;
	int mis;
	int retorno=-1;
	char confirm;
	printPassengers(listaPasajeros,tamanio,listaTipoVuelo,listaTipoPasajero,tamanioT);
	printf("Ingrese ID: ");
	scanf("%d", &mis);

	for(i=0;i<tamanio;i++)
	{
		if(listaPasajeros[i].isEmpty == 1 && mis == listaPasajeros[i].id)
		{
			retorno=1;
			confirm= confirmacion();
			if(confirm==1)
			{
				llamadaM(listaPasajeros,tamanio,i);
			}
		}
	}
	return retorno;
}




float Rtotal(ePassenger listaPasajeros [],int tamanio)
{
	float retorno=0;
	int i;

	for(i=0;i<tamanio;i++)
	{
		if(listaPasajeros[i].isEmpty == 1){
		retorno=retorno+listaPasajeros[i].price;
		}
	}
	return retorno;
}

float Tpromedio(ePassenger listaPasajeros [],int tamanio, int cantidad)
{

	float retorno;
	float can;

	can=Rtotal(listaPasajeros,tamanio);

	retorno=can/cantidad;

	return retorno;
}

int Spromedio(ePassenger listaPasajeros [],int tamanio, int cantidad)
{
	int retorno=0;
	int acumulador=0;
	float retur;
	int i;

	retur= Tpromedio(listaPasajeros,tamanio,cantidad);

	for(i=0;i<tamanio;i++)
	{
		if(listaPasajeros[i].isEmpty == 1)
		{
			if (listaPasajeros[i].price > retur)
			{
				acumulador++;
				retorno=acumulador;
			}
		}
	}

	return retorno;
}



void TPS(ePassenger listaPasajeros [],int tamanio,int contador)
{
	int prom;
	float total;
	float promedio;

	total=Rtotal(listaPasajeros,tamanio);
	promedio=Tpromedio(listaPasajeros,tamanio,contador);
	prom=Spromedio(listaPasajeros,tamanio,contador);

	printf("\nTotal: $%.2f\n", total);
	printf("Promedio: $%.2f\n", promedio);
	printf("Cantidad con mayor promedio: %d\n\n", prom);
}

