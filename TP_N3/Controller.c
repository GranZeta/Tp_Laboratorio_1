#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Utn.h"
#include "Menus.h"
#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int isOk = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!= NULL)
		{
			if(!parser_PassengerFromText(pArchivo, pArrayListPassenger))
			{
				printf("Se cargo con exito\n");
				isOk=0;
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
	}

    return isOk;
}

int controller_loadFromTextID(char* path , LinkedList* pArrayListPassenger, int* id)
{
	int isOk = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!= NULL)
		{
			if(!parser_IdFromText(pArchivo,pArrayListPassenger,id))
			{
				isOk = 0;
			}
		}
		fclose(pArchivo);
	}

    return isOk;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int isOk = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"rb");

		if(pArchivo!= NULL)
		{
			if(!parser_PassengerFromBinary(pArchivo, pArrayListPassenger))
			{
				printf("Se cargo con exito\n");
				isOk=0;
			}
			fclose(pArchivo);
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
	}

    return isOk;
}

int controller_addPassenger(LinkedList* pArrayListPassenger, int* id)
{
	int isOk = -1;
	int opcion;
	int auxId;
	int i=0;

	if(pArrayListPassenger!=NULL && id!=NULL)
	{

		controller_loadFromTextID("id.csv", pArrayListPassenger, id);

		auxId=*id;

		printf("ALTA DE PASAJEROS\n");
		utn_getInt("\n¿Cuantos pasajeros desea dar de alta?: ","\nError, reingrese: ",1,10,3,&opcion);
		do
		{
			if(!Passenger_add(pArrayListPassenger,&auxId))
			{
				*id=auxId;
				isOk=0;
			}
			i++;
		}while(opcion!=i);

		if(!isOk)
		{
			printf("Se ha dado de alta correctamente");
		}
		else
		{
			printf("No se ha dado de alta un nuevo pasajero");
		}
	}
    return isOk;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int isOk = -1;

	if(pArrayListPassenger!=NULL)
	{
		printf("MODIFICACION DE PASAJEROS\n");
		if(!Passenger_modify(pArrayListPassenger))
		{
			printf("Se ha modificado con exito");
		}
		else
		{
			printf("No se han podido actualizar los datos");
		}
	}
	return isOk;
}

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int isOk = -1;
	int opcion;
	int i=0;

	if(pArrayListPassenger!=NULL)
	{
		printf("BAJA DE PASAJEROS\n");
		utn_getInt("\nï¿½Cuantos pasajeros desea dar de baja?: ","\nError, reingrese: ",1,10,3,&opcion);

		do
		{
			if(!Passenger_remove(pArrayListPassenger))
			{
				isOk=0;
			}
			i++;
		}while(opcion!=i);
	}

    return isOk;
}


int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int isOk = -1;

	if(pArrayListPassenger!=NULL)
	{
		printf("LISTA DE PASAJEROS\n");
		if(Passenger_printList(pArrayListPassenger)!=0)
		{
			printf("No hay pasajeros para mostrar");
			isOk=0;
		}
	}

    return isOk;
}


int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int isOk = -1;
	int criterio;
	int opcion;
	char confirmar[4];
	strcpy(confirmar,"no");
	LinkedList* clon;
	if(pArrayListPassenger!=NULL)
	{
		clon = ll_clone(pArrayListPassenger);

		if(clon!=NULL)
		{
			do
			{
				opcion = Passenger_menuOrden();
				if(opcion!=0 && opcion!=8)
				{
					criterio = Passenger_subMenuOrden();
				}
				switch(opcion)
				{
					case 0:
						utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
						ll_deleteLinkedList(clon);
						break;

					case 1:
						if(!ll_sort(clon,Passenger_compareById,criterio))
						{
							if(criterio)
							{
								printf("Se ha ordenado la lista por id ascendente");
							}
							else
							{
								if(!criterio)
								{
									printf("Se ha ordenado la lista por id descendente");
								}
							}
						}
						break;
					case 2:
						ll_sort(clon,Passenger_compareByNombre,criterio);
						if(criterio)
						{
							printf("Se ha ordenado la lista por nombre de A-Z");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por nombre de Z-A");
							}
						}
						break;
					case 3:
						ll_sort(clon,Passenger_compareByApellido,criterio);
						if(criterio)
						{
							printf("Se ha ordenado la lista por nombre de A-Z");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por nombre de Z-A");
							}
						}
						break;
					case 4:
						ll_sort(clon,Passenger_compareByPrecio,criterio);
						if(criterio)
						{
							printf("Se ha ordenado la lista por precio ascendente");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por precio descendente");
							}
						}
						break;
					case 5:
						ll_sort(clon,Passenger_compareByTipoPasajero,criterio);
						if(criterio)
						{
							printf("Se ha ordenado la lista por tipo ascendente");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por tipo descendente");
							}
						}
						break;
					case 6:
						ll_sort(clon,Passenger_compareByCodigoVuelo,criterio);
						if(criterio)
						{
							printf("Se ha ordenado la lista por codigo de A-Z");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por codigo de Z-A");
							}
						}
						break;
					case 7:
						ll_sort(clon,Passenger_compareByEstadoVuelo,criterio);
						if(criterio)
						{
							printf("Se ha ordenado la lista por estado de A-Z");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por estado de Z-A");
							}
						}
						break;
					case 8:
							controller_ListPassenger(clon);
						break;
				}
			}while(stricmp(confirmar,"si"));
		}
	}

    return isOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int isOk = -1;
	int i;
	int len;
	int auxiliarID;
	char auxiliarNombre[50];
	char auxiliarApellido[50];
	float auxiliarPrecio;
	int auxiliarTipoPasajero;
	char auxiliarCodigoVuelo[50];
	char auxiliarEstadoVuelo[50];
	FILE* pArchivo;
	Passenger* aux = NULL;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"w");

		len = ll_len(pArrayListPassenger);

		if(pArchivo!= NULL && len>0)
		{
			fprintf(pArchivo,"id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo\n");
			for(i=0; i<len ;i++)
			{
				aux = (Passenger*) ll_get(pArrayListPassenger,i);
				if(aux!=NULL)
				{
					if(!Passenger_getVerify(aux,&auxiliarID,auxiliarNombre,auxiliarApellido,&auxiliarPrecio,auxiliarCodigoVuelo,&auxiliarTipoPasajero,auxiliarEstadoVuelo))
					{
						fprintf(pArchivo,"%d,%s,%s,%f,%s,%d,%s\n",auxiliarID,auxiliarNombre,auxiliarApellido,auxiliarPrecio,auxiliarCodigoVuelo,auxiliarTipoPasajero,auxiliarEstadoVuelo);
						isOk=0;
					}
					else
					{
						Passenger_delete(aux);
						printf("No se pudo guardar el archivo\n");
					}
				}
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
	}

	if(!isOk)
	{
		printf("El archivo fue guardado con exito!\n");
	}
	return isOk;
}

int controller_saveAsTextID(char* path , LinkedList* pArrayListPassenger, int id)
{
	int isOk = -1;
	int idMayor = 0;
	FILE* pArchivo;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		if(id==1000)
		{
			idMayor = id;
			isOk=0;
		}
		else
		{
			idMayor = ObtenerMayorId(pArrayListPassenger);
		}

		pArchivo = fopen(path,"w");

		if(pArchivo!= NULL)
		{
			fprintf(pArchivo,"Siguiente ID:\n");
			fprintf(pArchivo,"%d\n",idMayor);
			isOk=0;
		}

		fclose(pArchivo);
	}

	return isOk;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int isOk = -1;
	int i;
	int len;
	FILE* pArchivo;
	Passenger* aux = NULL;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		len = ll_len(pArrayListPassenger);

		pArchivo = fopen(path,"wb");

		if(pArchivo!= NULL && len>0)
		{
			for(i=0; i<len ;i++)
			{
				aux = (Passenger*) ll_get(pArrayListPassenger,i);

				if(aux!=NULL)
				{
					fwrite(aux,sizeof(Passenger),1,pArchivo);
					isOk=0;
				}
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
		if(!isOk)
		{
			printf("Se guardo con exito\n");
		}
	}

    return isOk;
}

