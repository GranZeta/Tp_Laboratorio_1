#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Menus.h"
#include "Utn.h"

Passenger* Passenger_new(void)//ME HABILITA UNA DIRECCION DE MEMORIA PARA UN NUEVO PASAJERO
{
	Passenger* pPasajeros = NULL;
	int id;
	float precio;
	int tipoPasajero;
	char nombre[50];
	char apellido[50];
	char codigoVuelo[50];
    char estadoVuelo[50];

	id=0;
	strcpy(nombre,"\0");
	strcpy(apellido,"\0");
	strcpy(codigoVuelo,"\0");
	strcpy(estadoVuelo,"\0");
	precio=0;
	tipoPasajero=0;

	pPasajeros = (Passenger*) malloc(sizeof(Passenger));

	if(pPasajeros!=NULL)
	{
		Passenger_setVerifyInt(pPasajeros,id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
	}

	return pPasajeros;
}

Passenger* Passenger_newParametros(char* idStr, char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	Passenger* pPasajerosParam = NULL;

	if(idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && precioStr!=NULL && tipoPasajeroStr!=NULL && codigoVueloStr!=NULL && estadoVueloStr!=NULL)
	{
		pPasajerosParam = Passenger_new();

		if(pPasajerosParam!=NULL)
		{
			if((Passenger_setVerifyChar(pPasajerosParam,idStr,nombreStr,apellidoStr,precioStr,codigoVueloStr,tipoPasajeroStr,estadoVueloStr))!=0)
			{
				Passenger_delete(pPasajerosParam);
			}
		}
	}

	return pPasajerosParam;
}

void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

int ObtenerMayorId (LinkedList* listaPasajeros)
{
	int mayorId=0;
	int id;
	int len;
	int i;
	Passenger* aux;

	if(listaPasajeros!=NULL)
	{
		len = ll_len(listaPasajeros);

		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				aux = (Passenger*)ll_get(listaPasajeros,i);
				Passenger_getId(aux,&id);

				if(i==0 || (mayorId<id))
				{
					mayorId=id;
				}
			}
		}
	}

	return mayorId;
}

int Passenger_printOnePassenger(Passenger* this)
{
	int isOk = -1;
	int auxiliarID;
	char auxiliarNombre[50];
	char auxiliarApellido[50];
	float auxiliarPrecio;
	int auxiliarTipoPasajero;
	char auxiliarTipoPasajeroChar[50];
	char auxiliarEstadoVuelo[50];
	char auxiliarCodigoVuelo[50];
	int ancho=-25;
	int ancho2=-7;
	int ancho3=-14;
	int ancho4=-10;
	int anchoId=-5;

	if(this!=NULL)
	{
		if(!Passenger_getVerify(this,&auxiliarID,auxiliarNombre,auxiliarApellido,&auxiliarPrecio,auxiliarCodigoVuelo,&auxiliarTipoPasajero,auxiliarEstadoVuelo))//cambio
		{

			Passenger_TipoPasajeroInt(auxiliarTipoPasajero,auxiliarTipoPasajeroChar);

			printf("|%*d|%*s|%*s|%*.0f|%*s|%*s|%*s|\n",anchoId,auxiliarID
										,ancho,auxiliarNombre
										,ancho,auxiliarApellido
										,ancho2,auxiliarPrecio
										,ancho2,auxiliarCodigoVuelo
										,ancho3,auxiliarTipoPasajeroChar
										,ancho4,auxiliarEstadoVuelo);
			isOk=0;
		}
		else
		{
			printf("Error para mostrar el pasajero");
		}
	}

	return isOk;
}

int Passenger_printList(LinkedList* listaPasajeros)
{
	int isOk = -1;
	int len;
	int i;
	int ancho=-25;
	int ancho2=-7;
	int ancho3=-14;
	int ancho4=-10;
	int anchoId=-5;
	Passenger* aux = NULL;

	if(listaPasajeros!=NULL)
	{
		len = ll_len(listaPasajeros);

		if(len>0)
		{
			printf("+-----+-------------------------+-------------------------+-------+-------+--------------+----------+\n");
			printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoId,"ID", ancho,"Nombre",ancho,"Apellido",ancho2,"Precio",ancho2,"Codigo",ancho3,"Tipo",ancho4,"Estado");
			printf("+-----+-------------------------+-------------------------+-------+-------+--------------+----------+\n");
			for(i=0; i<len ;i++)
			{
				aux = (Passenger*) ll_get(listaPasajeros,i);

				if(aux != NULL)
				{
					Passenger_printOnePassenger(aux);
					isOk=0;
				}
			}
			printf("+-----+-------------------------+-------------------------+-------+-------+--------------+----------+\n");
		}
	}

	return isOk;
}

int Passenger_findID(LinkedList* listaPasajeros, int id)
{
	int i;
	int len;
	int index;
	Passenger* auxiliar;

	if(listaPasajeros!=NULL)
	{
		len = ll_len(listaPasajeros);

		if(len>0)
		{
			for(i=0; i<len ;i++)
			{
				auxiliar = (Passenger*)ll_get(listaPasajeros,i);
				if(auxiliar->id==id)
				{
					index=i;
					break;
				}
			}
		}
	}

	return index;
}

int Passenger_add(LinkedList* listaPasajeros, int* id)
{
	int isOk = -1;
	char respuesta[4];
	int auxiliarID;
	char auxiliarNombre[50];
	char auxiliarApellido[50];
	float auxiliarPrecio;
	int auxiliarTipoPasajero;
	char auxiliarCodigoVuelo[50];
	int auxiliarCodigoVueloInt;
	char auxiliarEstadoVuelo[50];
	int auxiliarEstadoVueloInt;
	Passenger* auxPasajero = NULL;

	if(listaPasajeros!=NULL && id!=NULL)
	{
		auxPasajero = Passenger_new();

		if(auxPasajero!=NULL)
		{
			if((!(utn_getString("\nIngrese el nombre: ","\nError, reingrese: ",50,3,auxiliarNombre)) &&
				!(utn_getString("\nIngrese el apellido: ","\nError, reingrese: ",50,3,auxiliarApellido)) &&
				!(utn_getFloat("\nIngrese precio: ","\nError, reingrese: ",1,900000,3,&auxiliarPrecio)) &&
				!(utn_getInt("\n1.FirstClass\n2.ExecutiveClass\n3.EconomyClass\nIngrese tipo de pasajero: ","\nError, reingrese: ",1,3,3,&auxiliarTipoPasajero)) &&
				!(utn_getInt("\n1.IB0800A\n2.MM0987B\n3.BA2491A\n4.BR3456J\n5.FR5678G\n6.HY4567D\n7.GU2345F\n8.TU6789B\n9.HY4567D\nIngrese el codigo de vuelo: ","\nError, reingrese: ",1,9,3,&auxiliarCodigoVueloInt)) &&
				!(utn_getInt("\n1.Aterrizado\n2.En Horario\n3.Demorado\n4.En Vuelo\nIngrese tipo de pasajero: ","\nError, reingrese (1,2,3,4): ",1,4,3,&auxiliarEstadoVueloInt))))
			{

				Passenger_EstadoVueloInt(auxiliarEstadoVueloInt,auxiliarEstadoVuelo);
				Passenger_CodigoVueloInt(auxiliarCodigoVueloInt,auxiliarCodigoVuelo);

				SizeString(auxiliarNombre);
				SizeString(auxiliarApellido);
				SizeString(auxiliarCodigoVuelo);
				SizeString(auxiliarEstadoVuelo);
				auxiliarID = *id;
				auxiliarID+=1;

				if(!Passenger_setVerifyInt(auxPasajero,auxiliarID,auxiliarNombre,auxiliarApellido,auxiliarPrecio,auxiliarCodigoVuelo,auxiliarTipoPasajero,auxiliarEstadoVuelo))
				{
					Passenger_printOnePassenger(auxPasajero);
					utn_getString("\nEsta seguro que desea guardar este pasajero?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

					if(!(stricmp(respuesta,"si")))
					{
						ll_add(listaPasajeros, auxPasajero);
						*id=auxiliarID;
						isOk=0;
					}
					else
					{
						Passenger_delete(auxPasajero);
					}
				}
			}
			else
			{
				printf("\nReintente nuevamente");
			}
		}
		else
		{
			printf("No hay espacio para un nuevo pasajero");
		}
	}

	return isOk;
}

int Passenger_remove(LinkedList* listaPasajeros)
{
	int isOk = -1;
	int id;
	int index = -1;
	char respuesta[4];
	Passenger* aux = NULL;

	if(listaPasajeros!=NULL)
	{
		Passenger_printList(listaPasajeros);
		utn_getInt("Ingrese el ID para dar de baja: \n","Error, ID invalido\n",1,5000,3,&id);
		index = Passenger_findID(listaPasajeros,id);

		if(index!=-1)
		{
			aux = ll_get(listaPasajeros,index);
			Passenger_printOnePassenger(aux);
			utn_getString("\nEsta seguro que desea eliminar este pasajero?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

			if(!(stricmp(respuesta,"si")))
			{
				ll_remove(listaPasajeros,index);
				printf("Baja realizada con exito\n");
			}
			else
			{
				printf("Baja cancelada\n");
			}
		}
		else
		{
			printf("No se pudo encontrar el ID\n");
		}
	}

	return isOk;
}

int Passenger_modify(LinkedList* listaPasajeros)
{
	int isOk = -1;
	int id;
	int index = -1;
	char respuesta[4];
	char confirmar[4];
	Passenger* aux;
	Passenger auxiliar;
	strcpy(confirmar,"no");

	if(listaPasajeros!=NULL)
	{
		Passenger_printList(listaPasajeros);
		utn_getInt("Ingrese el ID para modificar: ","Error, ID invalido\n",1,5000,3,&id);
		index = Passenger_findID(listaPasajeros,id);

		if(index!=-1)
		{
			aux = (Passenger*) ll_get(listaPasajeros,index);
			auxiliar=*aux;
			Passenger_printOnePassenger(&auxiliar);
			utn_getString("\nEsta seguro que desea editar este pasajero?[si/no]: ","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

			if(!(stricmp(respuesta,"si")))
			{
				do
				{
					switch(Passenger_menuModify())
					{
						case 0:
							utn_getString("\nEsta seguro que desea salir?[si/no]: ","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
							break;
						case 1:
							Passenger_caseNombre(listaPasajeros,index,auxiliar);
							break;
						case 2:
							Passenger_caseApellido(listaPasajeros,index,auxiliar);
							break;
						case 3:
							Passenger_casePrecio(listaPasajeros,index,auxiliar);
							break;
						case 4:
							Passenger_caseTipo(listaPasajeros,index,auxiliar);
							break;
						case 5:
							Passenger_caseCodigoVuelo(listaPasajeros,index,auxiliar);
							break;
						case 6:
							Passenger_caseEstadoVuelo(listaPasajeros,index,auxiliar);
							break;
					}
				}while(stricmp(confirmar,"si"));
				printf("Modificacion realizada con exito\n");
			}
			else
			{
				printf("Modificacion cancelada\n");
			}
		}
		else
		{
			printf("No se pudo encontrar el ID\n");
		}
	}
	else
	{
		printf("Error. Imposible realizar una modificacion\n");
	}

	return isOk;
}

int Passenger_caseNombre(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int isOk = -1;
	char auxNombre[50];
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR NOMBRE****\t\n");
		utn_getString("Ingrese el nuevo nombre: ","Error, nombre invalido\n",50,3,auxNombre);
		SizeString(auxNombre);

		strcpy(auxiliar.nombre,auxNombre);
		Passenger_printOnePassenger(&auxiliar);

		utn_getInt("\nEsta seguro que desea modificarlo? [si:1/no:0]: ","\nRespuesta invalida, ingrese [si:1/no:0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modifyNombre(listaPasajeros,index,auxNombre);
			isOk=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}

	return isOk;
}

int Passenger_caseApellido(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int isOk = -1;
	char auxApellido[50];
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR APELLIDO****\t\n");
		utn_getString("Ingrese el nuevo apellido: ","Error, nombre invalido\n",50,3,auxApellido);
		SizeString(auxApellido);

		strcpy(auxiliar.apellido,auxApellido);
		Passenger_printOnePassenger(&auxiliar);

		utn_getInt("\nEsta seguro que desea modificarlo? [si:1/no:0]: ","\nRespuesta invalida, ingrese [si:1/no:0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modifyApellido(listaPasajeros,index,auxApellido);
			isOk=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}

	return isOk;
}

int Passenger_casePrecio(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int isOk = -1;
	float auxPrecio;
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR PRECIO****\t\n");
		utn_getFloat("Ingrese el nuevo precio: ","Error, cantidad invalida\n",1,100000,3,&auxPrecio);
		auxiliar.precio=auxPrecio;
		Passenger_printOnePassenger(&auxiliar);
		utn_getInt("\nEsta seguro que desea modificarlo? [si:1/no:0]: ","\nRespuesta invalida, ingrese [si:1/no:0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modifyPrecio(listaPasajeros,index,auxPrecio);
			isOk=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}
	return isOk;
}

int Passenger_caseTipo(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int isOk = -1;
	int auxTipo;
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR TIPO PASAJERO****\t\n");
		utn_getInt("\n1.FirstClass\n2.ExecutiveClass\n3.EconomyClass\nIngrese tipo de pasajero: ","\nError, reingrese: ",1,3,3,&auxTipo);
		auxiliar.tipoPasajero=auxTipo;
		Passenger_printOnePassenger(&auxiliar);
		utn_getInt("\nEsta seguro que desea modificarlo? [si:1/no:0]: ","\nRespuesta invalida, ingrese [si:1/no:0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modifyTipoPasajero(listaPasajeros,index,auxTipo);
			isOk=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}
	return isOk;
}

int Passenger_caseCodigoVuelo(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int isOk = -1;
	char auxCodigoVuelo[50];
	int auxiliarCodigoVueloInt;
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR CODIGO VUELO****\t\n");
		utn_getInt("\n1.IB0800A\n2.MM0987B\n3.BA2491A\n4.BR3456J\n5.FR5678G\n6.HY4567D\n7.GU2345F\n8.TU6789B\n9.HY4567D\nIngrese el codigo de vuelo: ","\nError, reingrese: ",1,9,3,&auxiliarCodigoVueloInt);
		Passenger_CodigoVueloInt(auxiliarCodigoVueloInt,auxCodigoVuelo);
		SizeString(auxCodigoVuelo);

		strcpy(auxiliar.codigoVuelo,auxCodigoVuelo);
		Passenger_printOnePassenger(&auxiliar);

		utn_getInt("\nEsta seguro que desea modificarlo? [si:1/no:0]: ","\nRespuesta invalida, ingrese [si:1/no:0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modifyCodigoVuelo(listaPasajeros,index,auxCodigoVuelo);
			isOk=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}

	return isOk;
}

int Passenger_caseEstadoVuelo(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int isOk = -1;
	char auxEstadoVuelo[50];
	int auxiliarEstadoVueloInt;
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR ESTADO DE VUELO****\t\n");
		utn_getInt("\n1.Aterrizado\n2.En Horario\n3.Demorado\n4.En Vuelo\nIngrese tipo de pasajero: ","\nError, reingrese (1,2,3,4): ",1,4,3,&auxiliarEstadoVueloInt);
		Passenger_EstadoVueloInt(auxiliarEstadoVueloInt,auxEstadoVuelo);
		SizeString(auxEstadoVuelo);

		strcpy(auxiliar.estadoVuelo,auxEstadoVuelo);
		Passenger_printOnePassenger(&auxiliar);

		utn_getInt("\nEsta seguro que desea modificarlo? [si:1/no:0]: ","\nRespuesta invalida, ingrese [si:1/no:0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modifyCodigoVuelo(listaPasajeros,index,auxEstadoVuelo);
			isOk=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}

	return isOk;
}

int Passenger_setVerifyChar(Passenger* this, char* idStr, char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	int isOk = -1;

	if(idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && precioStr!=NULL && tipoPasajeroStr!=NULL && codigoVueloStr!=NULL && estadoVueloStr!=NULL)
	{
		if((!(Passenger_setId(this,atoi(idStr))) &&
		!(Passenger_setNombre(this,nombreStr)) &&
		!(Passenger_setApellido(this,apellidoStr)) &&
		!(Passenger_setPrecio(this,atof(precioStr))) &&
		!(Passenger_setCodigoVuelo(this,codigoVueloStr)) &&
		!(Passenger_setTipoPasajero(this,Passenger_TipoPasajeroStr(tipoPasajeroStr))) &&
		!(Passenger_setEstadoVuelo(this,estadoVueloStr))))
		{
			isOk=0;
		}
	}

	return isOk;
}

int Passenger_setVerifyInt(Passenger* this, int id, char* nombre,char* apellido,float precio,char* codigoVuelo,int tipoPasajero, char* estadoVuelo)
{
	int isOk = -1;

	if(this!=NULL && id>0 && nombre!=NULL && apellido!=NULL && precio>0 && codigoVuelo!=NULL && estadoVuelo!=NULL)
	{
		if((!(Passenger_setId(this,id)) &&
		!(Passenger_setNombre(this,nombre)) &&
		!(Passenger_setApellido(this,apellido)) &&
		!(Passenger_setPrecio(this,precio)) &&
		!(Passenger_setCodigoVuelo(this,codigoVuelo)) &&
		!(Passenger_setTipoPasajero(this,tipoPasajero)) &&
		!(Passenger_setEstadoVuelo(this,estadoVuelo))))
		{
			isOk=0;
		}
	}

	return isOk;
}

int Passenger_getVerify(Passenger* this, int* id, char* nombre,char* apellido,float* precio,char* codigoVuelo,int* tipoPasajero, char* estadoVuelo)
{
	int isOk = -1;

	if(this!=NULL && id!=NULL && nombre!=NULL && apellido!=NULL && precio!=NULL && tipoPasajero!=NULL && codigoVuelo!=NULL && estadoVuelo!=NULL)
	{
		if((!(Passenger_getId(this,id)) &&
		!(Passenger_getNombre(this,nombre)) &&
		!(Passenger_getApellido(this,apellido)) &&
		!(Passenger_getPrecio(this,precio)) &&
		!(Passenger_getCodigoVuelo(this,codigoVuelo)) &&
		!(Passenger_getTipoPasajero(this,tipoPasajero)) &&
		!(Passenger_getEstadoVuelo(this,estadoVuelo))))
		{
			isOk=0;
		}
	}

	return isOk;
}

//---------------------------------------------SETTERS---------------------------------------------

int Passenger_setId(Passenger* this, int id)
{
	int isOk = -1;

	if(this!=NULL && id>0)
	{
		this->id = id;
		isOk=0;
	}

	return isOk;
}

int Passenger_setNombre(Passenger* this, char* nombre)
{
	int isOk = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		isOk=0;
	}

	return isOk;
}

int Passenger_setApellido(Passenger* this, char* apellido)
{
	int isOk = -1;

	if(this!=NULL && apellido!=NULL)
	{
		strcpy(this->apellido,apellido);
		isOk=0;
	}

	return isOk;
}

int Passenger_setPrecio(Passenger* this, float precio)
{
	int isOk = -1;

	if(this!=NULL && precio>0)
	{
		this->precio = precio;
		isOk=0;
	}

	return isOk;
}

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero)
{
	int isOk = -1;

	if(this!=NULL && tipoPasajero>0)
	{
		this->tipoPasajero = tipoPasajero;
		isOk=0;
	}

	return isOk;
}

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int isOk = -1;

	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		isOk=0;
	}

	return isOk;
}

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int isOk = -1;

	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		isOk=0;
	}

	return isOk;
}

//---------------------------------------------GETTERS---------------------------------------------
int Passenger_getId(Passenger* this, int* id)
{
	int isOk = -1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		isOk=0;
	}

	return isOk;
}
int Passenger_getNombre(Passenger* this, char* nombre)
{
	int isOk = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		isOk=0;
	}

	return isOk;
}
int Passenger_getApellido(Passenger* this, char* apellido)
{
	int isOk = -1;

	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido,this->apellido);
		isOk=0;
	}

	return isOk;
}
int Passenger_getPrecio(Passenger* this, float* precio)
{
	int isOk = -1;

	if(this!=NULL && precio!=NULL)
	{
		*precio = this->precio;
		isOk=0;
	}

	return isOk;
}
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero)
{
	int isOk = -1;

	if(this!=NULL && tipoPasajero!=NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		isOk=0;
	}

	return isOk;
}
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int isOk = -1;

	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		isOk=0;
	}

	return isOk;
}
int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int isOk = -1;

	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		isOk=0;
	}

	return isOk;
}


//-------------------------------------------MODIFICADORES-------------------------------------------
int Passenger_modifyNombre(LinkedList* listaPasajeros, int index, char* auxNombre)
{
	int isOk = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxNombre!=NULL)
	{
		aux = (Passenger*) ll_get(listaPasajeros,index);
		SizeString(auxNombre);

		if(aux!=NULL)
		{
			if(!Passenger_setNombre(aux,auxNombre))
			{
				printf("Se cargo correctamente el nuevo nombre\n");
			}
			else
			{
				printf("No se pudo modificar el nombre\n");
			}
			isOk=0;
		}
	}

	return isOk;
}

int Passenger_modifyApellido(LinkedList* listaPasajeros, int index, char* auxApellido)
{
	int isOk = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxApellido!=NULL)
	{
		aux = (Passenger*) ll_get(listaPasajeros,index);
		SizeString(auxApellido);

		if(aux!=NULL)
		{
			if(!Passenger_setApellido(aux,auxApellido))
			{
				printf("Se cargo correctamente el nuevo apellido\n");
			}
			else
			{
				printf("No se pudo modificar el apellido\n");
			}
			isOk=0;
		}
	}

	return isOk;
}

int Passenger_modifyPrecio(LinkedList* listaPasajeros, int index, float auxPrecio)
{
	int isOk = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxPrecio>0)
	{

		aux = (Passenger*) ll_get(listaPasajeros,index);

		if(aux!=NULL)
		{
			if(!Passenger_setPrecio(aux,auxPrecio))
			{
				printf("Se cargo correctamente el nuevo precio\n");
			}
			else
			{
				printf("No se pudo modificar el precio\n");
			}
			isOk=0;
		}
	}
	return isOk;
}

int Passenger_modifyTipoPasajero(LinkedList* listaPasajeros, int index, int auxTipo)
{
	int isOk = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxTipo > 0)
	{
		aux = (Passenger*) ll_get(listaPasajeros,index);

		if(aux!=NULL)
		{
			if(!Passenger_setTipoPasajero(aux,auxTipo))
			{
				printf("Se cargo correctamente el nuevo tipo de pasajero\n");
			}
			else
			{
				printf("No se pudo modificar el tipo de pasajero\n");
			}
			isOk=0;
		}
	}

	return isOk;
}

int Passenger_modifyCodigoVuelo(LinkedList* listaPasajeros, int index, char* auxCodigoVuelo)
{
	int isOk = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxCodigoVuelo!=NULL)
	{
		aux = (Passenger*) ll_get(listaPasajeros,index);
		SizeString(auxCodigoVuelo);

		if(aux!=NULL)
		{
			if(!Passenger_getEstadoVuelo(aux,auxCodigoVuelo))
			{
				printf("Se cargo correctamente el nuevo codigo de vuelo\n");
			}
			else
			{
				printf("No se pudo modificar el codigo de vuelo\n");
			}
			isOk=0;
		}
	}

	return isOk;
}

int Passenger_modifyEstadoVuelo(LinkedList* listaPasajeros, int index, char* auxEstadoVuelo)
{
	int isOk = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxEstadoVuelo!=NULL)
	{
		aux = (Passenger*) ll_get(listaPasajeros,index);
		SizeString(auxEstadoVuelo);

		if(aux!=NULL)
		{
			if(!Passenger_getEstadoVuelo(aux,auxEstadoVuelo))
			{
				printf("Se cargo correctamente el nuevo estado de vuelo\n");
			}
			else
			{
				printf("No se pudo modificar el estado de vuelo\n");
			}
			isOk=0;
		}
	}

	return isOk;
}

//-----------------------------------------ORDENADORES-----------------------------------------
int Passenger_compareById(void* pasajero1, void* pasajero2)
{
	int resultado = 0;//si son iguales
	Passenger* psj1 = NULL;
	Passenger* psj2 = NULL;
	int id1;
	int id2;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		psj1 = (Passenger*) pasajero1;
		psj2 = (Passenger*) pasajero2;

		if((!Passenger_getId(psj1,&id1)) && (!Passenger_getId(psj2,&id2)))
		{
			if(id1 > id2)//mayores
			{
				resultado = 1;
			}
			else
			{
				if(id1 < id2)//menores
				{
					resultado = -1;
				}
			}
		}
	}

	return resultado;
}
int Passenger_compareByNombre(void* pasajero1, void* pasajero2)
{
	int resultado = -1;
	Passenger* psj1 = NULL;
	Passenger* psj2 = NULL;
	char nombre1[128];
	char nombre2[128];

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		psj1 = (Passenger*) pasajero1;
		psj2 = (Passenger*) pasajero2;

		if((!Passenger_getNombre(psj1,nombre1)) && (!Passenger_getNombre(psj2,nombre2)))
		{
			resultado = strcmp(nombre1,nombre2);
		}
	}

	return resultado;
}

int Passenger_compareByApellido(void* pasajero1, void* pasajero2)
{
	int resultado = -1;
	Passenger* psj1 = NULL;
	Passenger* psj2 = NULL;
	char nombre1[128];
	char nombre2[128];

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		psj1 = (Passenger*) pasajero1;
		psj2 = (Passenger*) pasajero2;

		if((!Passenger_getApellido(psj1,nombre1)) && (!Passenger_getApellido(psj2,nombre2)))
		{
			resultado = strcmp(nombre1,nombre2);
		}
	}

	return resultado;
}

int Passenger_compareByPrecio(void* pasajero1, void* pasajero2)
{
	int resultado = 0;//si son iguales
	Passenger* psj1 = NULL;
	Passenger* psj2 = NULL;
	float precio1;
	float precio2;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		psj1 = (Passenger*) pasajero1;
		psj2 = (Passenger*) pasajero2;

		if((!Passenger_getPrecio(psj1,&precio1)) && (!Passenger_getPrecio(psj2,&precio2)))
		{
			if(precio1 > precio2)//mayores
			{
				resultado=1;
			}
			else
			{
				if(precio1 < precio2)//menores
				{
					resultado=-1;
				}
			}
		}
	}

	return resultado;
}

int Passenger_compareByTipoPasajero(void* pasajero1, void* pasajero2)
{
	int resultado = 0;//si son iguales
	Passenger* psj1 = NULL;
	Passenger* psj2 = NULL;
	int sueldo1;
	int sueldo2;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		psj1 = (Passenger*) pasajero1;
		psj2 = (Passenger*) pasajero2;

		if((!Passenger_getTipoPasajero(psj1,&sueldo1)) && (!Passenger_getTipoPasajero(psj2,&sueldo2)))
		{
			if(sueldo1 > sueldo2)//mayores
			{
				resultado=1;
			}
			else
			{
				if(sueldo1 < sueldo2)//menores
				{
					resultado=-1;
				}
			}
		}
	}

	return resultado;
}

int Passenger_compareByCodigoVuelo(void* pasajero1, void* pasajero2)
{
	int resultado = -1;
	Passenger* psj1 = NULL;
	Passenger* psj2 = NULL;
	char codigo1[128];
	char codigo2[128];

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		psj1 = (Passenger*) pasajero1;
		psj2 = (Passenger*) pasajero2;

		if((!Passenger_getCodigoVuelo(psj1,codigo1)) && (!Passenger_getCodigoVuelo(psj2,codigo2)))
		{
			resultado = strcmp(codigo1,codigo2);
		}
	}

	return resultado;
}

int Passenger_compareByEstadoVuelo(void* pasajero1, void* pasajero2)
{
	int resultado = -1;
	Passenger* psj1 = NULL;
	Passenger* psj2 = NULL;
	char estado1[128];
	char estado2[128];

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		psj1 = (Passenger*) pasajero1;
		psj2 = (Passenger*) pasajero2;

		if((!Passenger_getEstadoVuelo(psj1,estado1)) && (!Passenger_getEstadoVuelo(psj2,estado2)))
		{
			resultado = strcmp(estado1,estado2);
		}
	}

	return resultado;
}

//-----------------------------------------PASAJE DE CHAR A INT O INT A CHAR-----------------------------------------

int Passenger_TipoPasajeroStr(char* tipoStr)
{
	int retorno = -1;

	if(tipoStr !=NULL)
	{
		if(strcmp(tipoStr,"FirstClass") == 0)
		{
			retorno = 1;
		}
		else
		{
			if(strcmp(tipoStr,"ExecutiveClass") == 0)
			{
				retorno = 2;
			}
			else
			{
				if(strcmp(tipoStr,"EconomyClass") == 0)
				{
					retorno = 3;
				}
			}
		}
	}

	return retorno;
}


int Passenger_TipoPasajeroInt(int tipo,char* tipoStr)
{
	int retorno = -1;

	if(tipoStr != NULL)
	{
		switch(tipo)
		{
		case 1:
			strcpy(tipoStr,"FirstClass");
		break;

		case 2:
			strcpy(tipoStr,"ExecutiveClass");
		break;

		case 3:
			strcpy(tipoStr,"EconomyClass");
		break;
		}
	}
	return retorno;
}

int Passenger_CodigoVueloInt(int codigoVuelo,char* codigoVueloStr)
{
	int retorno = -1;

	if(codigoVueloStr != NULL)
	{
		switch(codigoVuelo)
		{
		case 1:
			strcpy(codigoVueloStr,"IB0800A");
		break;
		case 2:
			strcpy(codigoVueloStr,"MM0987B");
		break;
		case 3:
			strcpy(codigoVueloStr,"BA2491A");
		break;
		case 4:
			strcpy(codigoVueloStr,"BR3456J");
		break;
		case 5:
			strcpy(codigoVueloStr,"FR5678G");
		break;
		case 6:
			strcpy(codigoVueloStr,"HY4567D");
		break;
		case 7:
			strcpy(codigoVueloStr,"GU2345F");
		break;
		case 8:
			strcpy(codigoVueloStr,"TU6789B");
		break;
		case 9:
			strcpy(codigoVueloStr,"HY4567D");
		break;
		default:
			printf("error");
		break;
		}
	}
	return retorno;
}

int Passenger_EstadoVueloInt(int estadoVuelo,char* estadoVueloStr)
{
	int retorno = -1;

	if(estadoVueloStr != NULL)
	{
		switch(estadoVuelo)
		{
		case 1:
			strcpy(estadoVueloStr,"Aterrizado");
		break;
		case 2:
			strcpy(estadoVueloStr,"En Horario");
		break;
		case 3:
			strcpy(estadoVueloStr,"Demorado");
		break;
		case 4:
			strcpy(estadoVueloStr,"En Vuelo");
		break;
		default:
			printf("error");
		break;
		}
	}
	return retorno;
}

