#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Passenger.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int isOk = -1;
	char id[50];
	char name[50];
	char lastname[50];
	char price[50];
	char flycode[50];
	char typePassenger[50];
	char statusFlight[50];
	int cantidad = 0;
	Passenger* auxiliar = NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,name,lastname,price,flycode,typePassenger,statusFlight);
		do
		{
			cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,name,lastname,price,flycode,typePassenger,statusFlight);

			if(cantidad==7)
			{
				auxiliar = Passenger_newParametros(id,name,lastname,price,flycode,typePassenger,statusFlight);

				if(auxiliar!=NULL)
				{
					ll_add(pArrayListPassenger, auxiliar);
					isOk=0;
				}
				else
				{
					Passenger_delete(auxiliar);
				}
			}

		}
		while(!feof(pFile));
	}

	return isOk;
}

int parser_IdFromText(FILE* pFile , LinkedList* pArrayListPassenger, int* id)
{
	int isOk = -1;
	char idTxt[128];
	int idInt;
	int cantidad = 0;
	int header=1;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		do
		{
			cantidad = fscanf(pFile,"%[^\n]\n",idTxt);

			if((cantidad==1) && (header!=1))
			{
				isOk = 0;
				idInt = atoi(idTxt);

				if(idInt>*id)
				{
					*id=idInt;
				}
			}
			else
			{
				header=0;
			}
		}
		while(!feof(pFile));
	}

    return isOk;
}


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int isOk = -1;
	Passenger* auxiliar = NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		do
		{
			auxiliar = Passenger_new();

			if(auxiliar!=NULL)
			{
				if(fread(auxiliar,sizeof(Passenger),1,pFile))
				{
					ll_add(pArrayListPassenger,auxiliar);
					isOk=0;
				}
				else
				{
					Passenger_delete(auxiliar);
				}
			}
		}while(!feof(pFile));
	}

    return isOk;
}
