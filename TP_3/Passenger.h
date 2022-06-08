#ifndef Passenger_H_INCLUDED
#define Passenger_H_INCLUDED
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[50];
    char estadoVuelo[50];
}Passenger;

Passenger* Passenger_new(void);
Passenger* Passenger_newParametros(char* idStr, char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr);
void Passenger_delete(Passenger* this);


//BUSCAR
int Passenger_findID(LinkedList* listaPasajeros, int id);
int Passenger_printOnePassenger(Passenger* this);
int Passenger_printList(LinkedList* listaPasajeros);

//ABM
int Passenger_add(LinkedList* listaPasajeros, int* id);
int Passenger_remove(LinkedList* listaPasajeros);
int Passenger_modify(LinkedList* listaPasajeros);

//VERIFICACIONES GET Y SET
int Passenger_setVerifyChar(Passenger* this, char* idStr, char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr);
int Passenger_setVerifyInt(Passenger* this, int id, char* nombre,char* apellido,float precio,char* codigoVuelo,int tipoPasajero, char* estadoVuelo);
int Passenger_getVerify(Passenger* this, int* id, char* nombre,char* apellido,float* precio,char* codigoVuelo,int* tipoPasajero, char* estadoVuelo);

//ID
int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int* id);
int ObtenerMayorId(LinkedList* listaPasajeros);
int Passenger_compareById(void* pasajero1, void* pasajero2);

//NOMBRE
int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_getNombre(Passenger* this, char* nombre);
int Passenger_caseNombre(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_modifyNombre(LinkedList* listaPasajeros, int index, char* auxNombre);
int Passenger_compareByNombre(void* pasajero1, void* pasajero2);

//APELLIDO
int Passenger_setApellido(Passenger* this, char* apellido);
int Passenger_getApellido(Passenger* this, char* apellido);
int Passenger_caseApellido(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_modifyApellido(LinkedList* listaPasajeros, int index, char* auxApellido);
int Passenger_compareByApellido(void* pasajero1, void* pasajero2);

//PRECIO
int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float* precio);
int Passenger_casePrecio(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_modifyPrecio(LinkedList* listaPasajeros, int index, float auxPrecio);
int Passenger_compareByPrecio(void* pasajero1, void* pasajero2);

//TIPO PASAJERO
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);
int Passenger_caseTipo(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_modifyTipoPasajero(LinkedList* listaPasajeros, int index, int auxTipo);
int Passenger_compareByTipoPasajero(void* pasajero1, void* pasajero2);

//CODIGO DE VUELO
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_caseCodigoVuelo(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_modifyCodigoVuelo(LinkedList* listaPasajeros, int index, char* auxCodigoVuelo);
int Passenger_compareByCodigoVuelo(void* pasajero1, void* pasajero2);

//ESTADO DE VUELO
int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo);
int Passenger_caseEstadoVuelo(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_modifyEstadoVuelo(LinkedList* listaPasajeros, int index, char* auxEstadoVuelo);
int Passenger_compareByEstadoVuelo(void* pasajero1, void* pasajero2);

//PASAJE
int Passenger_TipoPasajeroStr(char* tipoStr);
int Passenger_TipoPasajeroInt(int tipo,char* tipoStr);
int Passenger_EstadoVueloInt(int status,char* statusStr);
int Passenger_CodigoVueloInt(int codigoVuelo,char* codigoVueloStr);

#endif // Passenger_H_INCLUDED

