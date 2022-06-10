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

/**
 * Es el constructor donde pedimos espacio en la memoria dinamica.
 * @return Direccion que encontro.
 */
Passenger* Passenger_new(void);

/**
 * Añade nuevos parametros con los setters.
 * @param idStr
 * @param nombreStr
 * @param apellidoStr
 * @param precioStr
 * @param tipoPasajeroStr
 * @param codigoVueloStr
 * @param estadoVueloStr
 * @return La direccion en memoria de this.
 */
Passenger* Passenger_newParametros(char* idStr, char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr);

/**
 * Lo que hace es eliminar a un pasajero de la lista con free.
 * @param this.
 */
void Passenger_delete(Passenger* this);


//BUSCAR
/**
 * Busca el id que le pasamos por parametros.
 * @param listaPasajeros
 * @param id
 * @return Nos devuelve el id que logro encontrar.
 */
int Passenger_findID(LinkedList* listaPasajeros, int id);

/**
 * Añade un pasajero.
 * @param this
 * @return Nos retorna 0 si se realizo con exito y -1 en caso de error.
 */
int Passenger_printOnePassenger(Passenger* this);

/**
 * Nos printea la lista de pasajeros que le vamos a mostrar a el usuario
 * @param listaPasajeros
 * @return Nos retorna 0 si se realizo con exito y -1 en caso de error.
 */
int Passenger_printList(LinkedList* listaPasajeros);

//ABM
/**
 * Le pedimos al usuario todos los datos que deseamos cargar y luego
 * verificamos y guardamos dichos datos.
 * @param listaPasajeros
 * @param id
 * @return Nos retorna 0 si se realizo con exito la carga de los datos y -1 en caso de error.
 */
int Passenger_add(LinkedList* listaPasajeros, int* id);

/**
 * Eliminamos a un pasajero mediante su ID.
 * @param listaPasajeros
 * @return Nos retorna 0 si se realizo con exito la baja y -1 en caso de error.
 */
int Passenger_remove(LinkedList* listaPasajeros);

/**
 * Nos permite realizar la modificacion de los datos de un pasajero.
 * @param listaPasajeros
 * @return Nos retorna 0 si se realizo con exito la modificacion y -1 en caso de error.
 */
int Passenger_modify(LinkedList* listaPasajeros);

//---------------------------------------------VERIFICACIONES GET Y SET---------------------------------------------
/**
 * Verifica que todos los setters sean CHAR*
 * @param this
 * @param idStr
 * @param nombreStr
 * @param apellidoStr
 * @param precioStr
 * @param tipoPasajeroStr
 * @param codigoVueloStr
 * @param estadoVueloStr
 * @return Retorna 0 en caso de que la veficacion haya sido exitosa y en de error -1.
 */
int Passenger_setVerifyChar(Passenger* this, char* idStr, char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr);

/**
 * Verifica que todos los setters tengan su correspondiente asignación (CHAR*-INT-FLOAT...).
 * @param this
 * @param id
 * @param nombre
 * @param apellido
 * @param precio
 * @param codigoVuelo
 * @param tipoPasajero
 * @param estadoVuelo
 * @return Retorna 0 en caso de que la veficacion haya sido exitosa y en de error -1.
 */
int Passenger_setVerifyInt(Passenger* this, int id, char* nombre,char* apellido,float precio,char* codigoVuelo,int tipoPasajero, char* estadoVuelo);

/**
 * Verifica que todos los getters tengan su correspondiente asignación (CHAR*-INT-FLOAT...).
 * @param this
 * @param id
 * @param nombre
 * @param apellido
 * @param precio
 * @param codigoVuelo
 * @param tipoPasajero
 * @param estadoVuelo
 * @return Retorna 0 en caso de que la veficacion haya sido exitosa y en de error -1.
 */
int Passenger_getVerify(Passenger* this, int* id, char* nombre,char* apellido,float* precio,char* codigoVuelo,int* tipoPasajero, char* estadoVuelo);

//---------------------------------------------ID---------------------------------------------
/**
 * Settear el ID.
 * @param this
 * @param id
 * @return Nos retorna 0 si setteo con exito y -1 en caso de error.
 */
int Passenger_setId(Passenger* this, int id);

/**
 * Obtiene el ID.
 * @param this
 * @param id
 * @return Nos retorna 0 si encontro el ID y -1 en caso de error.
 */
int Passenger_getId(Passenger* this, int* id);

/**
 * Obtiene el id maximo de la lista
 * @param listaPasajeros
 * @return Nos retorna 0 si encontro el ID mayor y -1 en caso de error.
 */
int ObtenerMayorId(LinkedList* listaPasajeros);

/**
 * Le pasamos dos aux para que compare su igualdad.
 * @param pasajero1
 * @param pasajero2
 * @return Nos retorna 0 en caso de que sean iguales, 1 en caso de que uno sea mayor
 * que el otro y -1 en caso de que uno sea menor que el otro.
 */
int Passenger_compareById(void* pasajero1, void* pasajero2);

//---------------------------------------------NOMBRE---------------------------------------------
/**
 * Settear el Nombre.
 * @param this
 * @param nombre
 * @return Nos retorna 0 si setteo con exito y -1 en caso de error.
 */
int Passenger_setNombre(Passenger* this, char* nombre);

/**
 * Obtiene el Nombre.
 * @param this
 * @param nombre
 * @return Nos retorna 0 si encontro el Nombre y -1 en caso de error.
 */
int Passenger_getNombre(Passenger* this, char* nombre);

/**
 * Nos permite modificar el Nombre, veficando que el nuevo que se ingresa
 * sea valido, esta modificaion se guarda en un auxiliar y si paso las validaciones
 * invocamos a la funcion que reliazara la modificaion que contenga nuestro auxiliar.
 * @param listaPasajeros
 * @param index
 * @param auxiliar
 * @return Si se realizo la modificacion retorna 0 en y caso de error -1.
 */
int Passenger_caseNombre(LinkedList* listaPasajeros, int index, Passenger auxiliar);

/**
 * Nos permite realizar el cambio de un dato que impactara directamente en nuestra
 * lista, por este motivo tendremos que validar muy bien el dato pasado como parametro
 * a nuestro auxNombre, ya que remplazara el dato que este contenia anteriormente.
 * @param listaPasajeros
 * @param index
 * @param auxNombre
 * @return En caso de realizar exitoxamnete la modificacion se retornara 0 y en caso
 * de error -1.
 */
int Passenger_modifyNombre(LinkedList* listaPasajeros, int index, char* auxNombre);

/**
 * Ordena por Nombre, ascendente o descendente.
 * @param pasajero1
 * @param pasajero2
 * @return Retorna 0 si se ordeno con exito y en caso de error -1.
 */
int Passenger_compareByNombre(void* pasajero1, void* pasajero2);

//---------------------------------------------APELLIDO---------------------------------------------
/**
 * Settear el Apellido.
 * @param this
 * @param apellido
 * @return Nos retorna 0 si setteo con exito y -1 en caso de error.
 */
int Passenger_setApellido(Passenger* this, char* apellido);

/**
 * Obtiene el Apellido.
 * @param this
 * @param apellido
 * @return Nos retorna 0 si encontro el Apellido y -1 en caso de error.
 */
int Passenger_getApellido(Passenger* this, char* apellido);

/**
 * Nos permite modificar el Apellido, veficando que el nuevo que se ingresa
 * sea valido, esta modificaion se guarda en un auxiliar y si paso las validaciones
 * invocamos a la funcion que reliazara la modificaion que contenga nuestro auxiliar.
 * @param listaPasajeros
 * @param index
 * @param auxiliar
 * @return Si se realizo la modificacion retorna 0 en y caso de error -1.
 */
int Passenger_caseApellido(LinkedList* listaPasajeros, int index, Passenger auxiliar);

/**
 * Nos permite realizar el cambio de un dato que impactara directamente en nuestra
 * lista, por este motivo tendremos que validar muy bien el dato pasado como parametro
 * a nuestro auxApellido, ya que remplazara el dato que este contenia anteriormente.
 * @param listaPasajeros
 * @param index
 * @param auxApellido
 * @return En caso de realizar exitoxamnete la modificacion se retornara 0 y en caso
 * de error -1.
 */
int Passenger_modifyApellido(LinkedList* listaPasajeros, int index, char* auxApellido);

/**
 * Ordena por Apellido, ascendente o descendente.
 * @param pasajero1
 * @param pasajero2
 * @return Retorna 0 si se ordeno con exito y en caso de error -1.
 */
int Passenger_compareByApellido(void* pasajero1, void* pasajero2);


//---------------------------------------------PRECIO---------------------------------------------
/**
 * Settear el precio.
 * @param this
 * @param precio
 * @return Nos retorna 0 si setteo con exito y -1 en caso de error.
 */
int Passenger_setPrecio(Passenger* this, float precio);

/**
 * Obtiene el Precio.
 * @param this
 * @param precio
 * @return Nos retorna 0 si encontro el Precio y -1 en caso de error.
 */
int Passenger_getPrecio(Passenger* this, float* precio);

/**
 * Nos permite modificar el Precio, veficando que el nuevo que se ingresa
 * sea valido, esta modificaion se guarda en un auxiliar y si paso las validaciones
 * invocamos a la funcion que reliazara la modificaion que contenga nuestro auxiliar.
 * @param listaPasajeros
 * @param index
 * @param auxiliar
 * @return Si se realizo la modificacion retorna 0 en y caso de error -1.
 */
int Passenger_casePrecio(LinkedList* listaPasajeros, int index, Passenger auxiliar);

/**
 * Nos permite realizar el cambio de un dato que impactara directamente en nuestra
 * lista, por este motivo tendremos que validar muy bien el dato pasado como parametro
 * a nuestro auxPrecio, ya que remplazara el dato que este contenia anteriormente.
 * @param listaPasajeros
 * @param index
 * @param auxPrecio
 * @return En caso de realizar exitoxamnete la modificacion se retornara 0 y en caso
 * de error -1.
 */
int Passenger_modifyPrecio(LinkedList* listaPasajeros, int index, float auxPrecio);

/**
 * Ordena por Precio, ascendente o descendente.
 * @param pasajero1
 * @param pasajero2
 * @return Retorna 0 si se ordeno con exito y en caso de error -1.
 */
int Passenger_compareByPrecio(void* pasajero1, void* pasajero2);

//---------------------------------------------TIPO PASAJERO---------------------------------------------
/**
 * Settear el Tipo de Pasajero.
 * @param this
 * @param tipoPasajero
 * @return Nos retorna 0 si setteo con exito y -1 en caso de error.
 */
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);

/**
 * Obtiene el Tipo Pasajero.
 * @param this
 * @param tipoPasajero
 * @return Nos retorna 0 si encontro el Tipo Pasajero y -1 en caso de error.
 */
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);

/**
 * Nos permite modificar el Tipo Pasajero, veficando que el nuevo que se ingresa
 * sea valido, esta modificaion se guarda en un auxiliar y si paso las validaciones
 * invocamos a la funcion que reliazara la modificaion que contenga nuestro auxiliar.
 * @param listaPasajeros
 * @param index
 * @param auxiliar
 * @return Si se realizo la modificacion retorna 0 en y caso de error -1.
 */
int Passenger_caseTipo(LinkedList* listaPasajeros, int index, Passenger auxiliar);

/**
 * Nos permite realizar el cambio de un dato que impactara directamente en nuestra
 * lista, por este motivo tendremos que validar muy bien el dato pasado como parametro
 * a nuestro auxTipo, ya que remplazara el dato que este contenia anteriormente.
 * @param listaPasajeros
 * @param index
 * @param auxTipo
 * @return En caso de realizar exitoxamnete la modificacion se retornara 0 y en caso
 * de error -1.
 */
int Passenger_modifyTipoPasajero(LinkedList* listaPasajeros, int index, int auxTipo);

/**
 * Ordena por TipoPasajero, ascendente o descendente.
 * @param pasajero1
 * @param pasajero2
 * @return Retorna 0 si se ordeno con exito y en caso de error -1.
 */
int Passenger_compareByTipoPasajero(void* pasajero1, void* pasajero2);

//---------------------------------------------CODIGO DE VUELO---------------------------------------------
/**
 * Settear el Codigo de Vuelo
 * @param this
 * @param codigoVuelo
 * @return Nos retorna 0 si setteo con exito y -1 en caso de error.
 */
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);

/**
 * Obtiene el Codigo Vuelo.
 * @param this
 * @param codigoVuelo
 * @return Nos retorna 0 si encontro el Codigo Vuelo y -1 en caso de error.
 */
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

/**
 * Nos permite modificar el Codigo de Vuelo, veficando que el nuevo que se ingresa
 * sea valido, esta modificaion se guarda en un auxiliar y si paso las validaciones
 * invocamos a la funcion que reliazara la modificaion que contenga nuestro auxiliar.
 * @param listaPasajeros
 * @param index
 * @param auxiliar
 * @return Si se realizo la modificacion retorna 0 en y caso de error -1.
 */
int Passenger_caseCodigoVuelo(LinkedList* listaPasajeros, int index, Passenger auxiliar);

/**
 * Nos permite realizar el cambio de un dato que impactara directamente en nuestra
 * lista, por este motivo tendremos que validar muy bien el dato pasado como parametro
 * a nuestro auxCodigoVuelo, ya que remplazara el dato que este contenia anteriormente.
 * @param listaPasajeros
 * @param index
 * @param auxCodigoVuelo
 * @return En caso de realizar exitoxamnete la modificacion se retornara 0 y en caso
 * de error -1.
 */
int Passenger_modifyCodigoVuelo(LinkedList* listaPasajeros, int index, char* auxCodigoVuelo);

/**
 * Ordena por Codigo de Vuelo, ascendente o descendente.
 * @param pasajero1
 * @param pasajero2
 * @return Retorna 0 si se ordeno con exito y en caso de error -1.
 */
int Passenger_compareByCodigoVuelo(void* pasajero1, void* pasajero2);

//---------------------------------------------ESTADO DE VUELO---------------------------------------------
/**
 * Settear el Estado de Vuelo.
 * @param this
 * @param estadoVuelo
 * @return Nos retorna 0 si setteo con exito y -1 en caso de error.
 */
int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo);

/**
 * Obtiene el Estado de Vuelo.
 * @param this
 * @param estadoVuelo
 * @return Nos retorna 0 si encontro el Estado de Vuelo y -1 en caso de error.
 */
int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo);

/**
 * Nos permite modificar el Estado de Vuelo, veficando que el nuevo que se ingresa
 * sea valido, esta modificaion se guarda en un auxiliar y si paso las validaciones
 * invocamos a la funcion que reliazara la modificaion que contenga nuestro auxiliar.
 * @param listaPasajeros
 * @param index
 * @param auxiliar
 * @return Si se realizo la modificacion retorna 0 en y caso de error -1.
 */
int Passenger_caseEstadoVuelo(LinkedList* listaPasajeros, int index, Passenger auxiliar);

/**
 * Nos permite realizar el cambio de un dato que impactara directamente en nuestra
 * lista, por este motivo tendremos que validar muy bien el dato pasado como parametro
 * a nuestro auxEstadoVuelo, ya que remplazara el dato que este contenia anteriormente.
 * @param listaPasajeros
 * @param index
 * @param auxEstadoVuelo
 * @return En caso de realizar exitoxamnete la modificacion se retornara 0 y en caso
 * de error -1.
 */
int Passenger_modifyEstadoVuelo(LinkedList* listaPasajeros, int index, char* auxEstadoVuelo);

/**
 * Ordena por Estado de Vuelo, ascendente o descendente.
 * @param pasajero1
 * @param pasajero2
 * @return Retorna 0 si se ordeno con exito y en caso de error -1.
 */
int Passenger_compareByEstadoVuelo(void* pasajero1, void* pasajero2);

//---------------------------------------------PASAJE---------------------------------------------
/**
 * Recibe como parametro un char y nos devuelve
 * la opcion en tipo entero a la que pertenece ese char.
 * Nos convierte la cadena de caracteres a un entero predeterminada.
 * @param tipoStr
 * @return Retorna el entero que le pertenece a esa cadena de caracteres y
 * en caso de error -1.
 */
int Passenger_TipoPasajeroStr(char* tipoStr);

/**
 * Recibe como parametro un entero y un char que va a ser donde almacenaremos
 * ese entero ya convertido con el strcpy.
 * Nos convierte el entero a una cadena de caracteres predeterminada.
 * @param tipo
 * @param tipoStr
 * @return Retorna la cadena de caracteres que le pertenecia a ese entero y
 * en caso de error -1.
 */
int Passenger_TipoPasajeroInt(int tipo,char* tipoStr);

/**
 * Recibe como parametro un entero y un char que va a ser donde almacenaremos
 * ese entero ya convertido con el strcpy.
 * Nos convierte el entero a una cadena de caracteres predeterminada.
 * @param status
 * @param statusStr
 * @return Retorna la cadena de caracteres que le pertenecia a ese entero y
 * en caso de error -1.
 */
int Passenger_EstadoVueloInt(int status,char* statusStr);

/**
 * Recibe como parametro un entero y un char que va a ser donde almacenaremos
 * ese entero ya convertido con el strcpy.
 * Nos convierte el entero a una cadena de caracteres predeterminada.
 * @param codigoVuelo
 * @param codigoVueloStr
 * @return Retorna la cadena de caracteres que le pertenecia a ese entero y
 * en caso de error -1.
 */
int Passenger_CodigoVueloInt(int codigoVuelo,char* codigoVueloStr);

#endif // Passenger_H_INCLUDED

