/*
 * bibliotecaPersonal.h
 *
 *  Created on: 14 may 2022
 *      Author: marti
 */

#ifndef BIBLIOTECAPERSONAL_H_
#define BIBLIOTECAPERSONAL_H_

/**
 * ordena por codigo , seria por una cadena de por un entero
 * con la variable orden podemos hacer que sea de mayor a menor o viseversa el ordenamiento
 * @param listaPasajeros
 * @param tamanio
 * @param orden
 * @returns i se ordeno correctamente un 0 su hubo error un -1
 */
int ordenamientoCodigo(ePassenger listaPasajeros [],int tamanio, int orden);


/**
 * ordena por apellido y tipo de pasajero, seria por una cadena de caracteres y por un entero
 * con la variable orden podemos hacer que sea de mayor a menor o viseversa el ordenamiento
 * @param listaPasajeros
 * @param tamanio
 * @param orden
 * @return si se ordeno correctamente un 0 su hubo error un -1
 */
int ordenarApellidoYTipo(ePassenger listaPasajeros [],int tamanio, int orden);


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

/**
 * nos permite dar de baja logica a un usuario que se escuente
 * en el array y si esto se logra con exito devolvemos un valor entero
 * @param listaAlbumes
 * @param tamanio
 * @return numero entero 1 si no se pudo efectuar la baja
 * y 0 si se realizo con exito
 */
int baja(ePassenger listaPasajeros [],int tamanio,etypeVuelo listaTipoVuelo[],etypePasajero listaTipoPasajero[], int tamanioT);

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


#endif /* BIBLIOTECAPERSONAL_H_ */
