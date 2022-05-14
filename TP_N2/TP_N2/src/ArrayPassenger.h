#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int statusFlight;
	int typePassenger;
	int isEmpty;
}ePassenger;


typedef struct
{
	int statusFlight;
	char descripcion[51];
}etypeVuelo;

typedef struct
{
	int typePassenger;
	char descripcionP[51];
}etypePasajero;

typedef struct
{
	int flycode;
	char descripcionC[51];
}eCodigoVuelo;



/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
 * @param listaPasajeros
 * @param tamanio
 * @return
 */
int initPassengers(ePassenger listaPasajeros [],int tamanio);


/**
 * al tomar todos estos parametros podemos dar de alta a un pasajero, esto se hace llamando a otra funcion que busca todos los campos
 * libres de nuestro array, una vez que esa funcion nos devuelva un entero con un 0 podemos entrar a nuestro if y decir que si el valor
 * es distinto a -1 podemos seguir y dar de alta a un usuario, entonces de esta forma le asicnamos el vamos 1 para darlo de alta, cada
 * ves que se da de alta a un usurio tambien se le asicna un id unico autoincrementable
 * @param listaAlbumes
 * @param tamanio
 * @param
 * @param listaDiscografica
 * @param listaArtistas
 * @param tamanioD
 * @param listaTipoArtista
 * @param tamanioDT
 * @return retornamos 1 en caso de  que se haya cumplido dicho alta y 0 si es que la lista esta llena.
 */
int altaPasajero(ePassenger listaPasajeros [],int tamanio,int);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(ePassenger listaPasajeros [],int tamanio, int id);


/**
 * nos permite dar de baja logica a un usuario que se escuente
 * en el array y si esto se logra con exito devolvemos un valor entero
 * @param listaAlbumes
 * @param tamanio
 * @return numero entero 1 si no se pudo efectuar la baja
 * y 0 si se realizo con exito
 */
int baja(ePassenger listaPasajeros [],int tamanio,etypeVuelo listaTipoVuelo[],etypePasajero listaTipoPasajero[], int tamanioT);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(ePassenger listaPasajeros [],int tamanio,int);

/**
 * \brief print the content of passengers array
 * @param listaPasajeros
 * @param tamanio
 * @param listaTipoVuelo
 * @param listaTipoPasajero
 * @param tamanioT
 */
void printPassengers(ePassenger listaPasajeros [],int tamanio, etypeVuelo listaTipoVuelo[],etypePasajero listaTipoPasajero[], int tamanioT );


/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
*/
int sortPassengersByCode(ePassenger listaPasajeros [],int tamanio,int);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger (ePassenger listaPasajeros [],int tamanio, int id);


/**
 * harcodemos con datos todos los arrays
 * @param listaTipoPasajero
 * @param tamanio
 */
void cargaTipoVuelo(etypePasajero listaTipoPasajero [],int tamanio);

/**
 * harcodemos con datos todos los arrays
 * @param listaTipoPasajeros
 * @param tamanio
 */
void cargaTipoPasajero(etypeVuelo listaTipoPasajeros [],int tamanio);

/**
 * harcodemos con datos todos los arrays
 * @param listaPasajeros
 * @param tamanio
 */
void cargaPasajeros(ePassenger listaPasajeros [],int tamanio);

/**
 * mostramos el sub menu para las modificaciones
 * @param opcion
 * @return retornamos la opcion que ingrese el usuario
 */
int mostrarMenuModificar(int opcion);

/**
 * mostramos el sub menu para el listar
 * @param opcion
 * @return retornamos la opcion que ingrese el usuario
 */
int mostrarMenuListar(int opcion);

/**
 * llamamos a las funciones que calculan el total de todos los importes ingresados
 * las cuales serian, el lavor total, el promedio de dicho total y los usurios que
 * superen ese promedio.
 * @param listaPasajeros
 * @param tamanio
 * @param contador
 *  mostramos el total, promedio y la cantidad que supera el promedio
 */
void TPS(ePassenger listaPasajeros [],int tamanio,int contador);

/**
 * Para esta funcion tenemos que pasarle todas las esturcturas que tenemos en nuestro
 * programa ya que necesita informar el contenido de casa una, contemos un switch
 * desde donde el usurio puede elejir que opcion quiere listar.
 * @param listaPasajeros
 * @param tamanio
 * @param listaTipoVuelo
 * @param listaTipoPasajero
 * @param tamanioT
 * @param contador
 */
void informar(ePassenger listaPasajeros [],int tamanio, etypeVuelo listaTipoVuelo[],etypePasajero listaTipoPasajero[],int tamanioT, int contador);

/**
 * busca en lo todas las pocisiones del array un posicion libre en este caso
 * si la posicon es igual a 0 eso quiere decir que esa posicion esta vecia
 * y devolveremos esa posicion
 * @param listaPasajeros
 * @param tamanio
 * @return en caso de encontrar una posicion en 0 le retornaremos la posicion que esta libre,
 * si no encontramos ninguna posicion libre retornamos -1, que puede ser por error o lista llena.
 */
int buscarLibre (ePassenger listaPasajeros [],int tamanio);


/**
 * con esta funciuon almacenamos el manu principal para pedirle
 * al usurio todos los datos que necetemos que nos ingrese.
 * @param listaPsajeros
 * @param tamanio
 * @param  le pediremos al usurio los datos que desemos y los guadaremos en variables
 */
void pedirDatos(ePassenger listaPsajeros [],int tamanio, int);


/**
 * llamos a esta funcion para poder mostrar al usurio el id del
 * usurio que queremos dar de baja.
 * @param listaPasajeros
 * @param tamanio
 * @return pedimos y guardamos el dato que nos pase el usurio.
 */
int mostarBaja(ePassenger listaPasajeros [],int tamanio);

/**
 * mostramos un  menu para el  menu principal
 * @param opcion
 * @return retornamos la opcion que ingrese el usuario
 */
int mostrarMenu(int opcion);


/**
 * validamos que la baja no se ingrese datos erroneos o que no esten ingresados
 * ya en nuestra lista de pasajeros
 * @param listaPasajeros
 * @param tamanio
 */
void validacionBaja(ePassenger listaPasajeros [],int tamanio);


/**
 * le pedismos que nos ingrese un id que este dado de alta al usuario en caso de que
 * sea un id que no tenga nadie dado de alta se mostrara un error, si ese id es correcto le
 * desplazaremos al usurio un sub menu para que elija las opciones que puede cambiar.
 * Esto esta dentro de un switch el cual solo acepta numeros.
 * @param listaPasajeros
 * @param tamanio
 * @param listaTipoVuelo
 * @param listaTipoPasajero
 * @param tamanioT
 * @return
 */
int modificar(ePassenger listaPasajeros [],int tamanio,etypeVuelo listaTipoVuelo[],etypePasajero listaTipoPasajero[], int tamanioT );


/**
 * nos muestar a todos los pasajeros que esten dado de alta pero de a uno, no todos juntos
 * @param listaPasajeros
 * @param tamanio
 * @param listaTipoVuelo
 * @param listaTipoPasajero
 * @param tamanioT
 * @param indice
 */
void mostrarPasajerosDeOne(ePassenger listaPasajeros [],int tamanio, etypeVuelo listaTipoVuelo[],etypePasajero listaTipoPasajero[], int tamanioT ,int indice);

/**
 * contiene un acumulador con todos los numeros que ingrese el
 * usuario
 * @param listaPasajeros
 * @param tamanio
 * @return el valor total del acumulador
 */
float Rtotal(ePassenger listaPasajeros [],int tamanio);

/**
 * sa un total y lo divide por el contador general
 * @param listaPasajeros
 * @param tamanio
 * @param cantidad
 * @return nos da el resultado de la divicion
 */
float Tpromedio(ePassenger listaPasajeros [],int tamanio, int cantidad);

/**
 * toma un numero y luego recorre el array comparando todos los numeros que contiene
 * con ese numero si se cumple esa igualacion se aumenta el contador
 * @param listaPasajeros
 * @param tamanio
 * @param cantidad
 * @return el valor entero del contador
 */
int Spromedio(ePassenger listaPasajeros [],int tamanio, int cantidad);


/**
 * nos sirve para encapsular un switch que luego le pediremos que ingrese una opcion el usuario
 * para poder acceder y modificar las partes que desee.
 * @param listaPasajeros
 * @param tamanio
 * @param i
 */
void llamadaM(ePassenger listaPasajeros [],int tamanio,int i);



#endif /* ARRAYPASSENGER_H_ */
