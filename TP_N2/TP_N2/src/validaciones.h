/*
 * validaciones.h
 *
 *  Created on: 10 may 2022
 *      Author: marti
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/**
 * la llamamos cuando queremos hacer ua confirmacion ganeral
 * si el usurio preciosa si sera 1[true]y no sera 0[false]
 * @return numero entero
 */
int confirmacion();

/**
 * validamos que no se supere la cantida maximo del array esta cantidad
 * se la pedimos que la ingresen.
 * @param mensaje
 * @param mensajeError
 * @param cadena
 */
void validarCadenaCaracteres(char mensaje[],char mensajeError[], char cadena[]);

/**
 * nos valida que el caracter ingresado sea un numero y no una letra
 * en caso contrario nos devolvera el mensaje de error
 * @param numero
 * @return numero entero
 */
int ValidarNumero(char numero[]);


/**
 * Pasarle dos cadenas de caracteres uno con lo que deseamos validar y
 * el otro con un mensaje de error  ingresamos en un while y hasta no
 * poner un numero entero no podemos salir ya que nos devuelve el mensaje de error
 * @param mensaje
 * @param mensajeError
 * @return retorno un numero entero
 */
int PedirEntero(char mensaje[],char mensajeError[]);

/**
 * validamos que el largo de la cadena no se pase de un maximo
 * @param letra
 * @return retornamos la cantidad de caracteres que contiene la cadena
 */

int validarCadena(char letra[]);

/**
 * validamos que todos los caracteres sean letras mayusculas o minusculas, pero si o si
 * todos caracteres tienen que ser letras sino entraremos en un while que no nos dejara seguir
 * hasta ingresar una cadena de solo letras.
 * @param nombre
 * @return
 */
int ValidarLetra(char nombre[]);

/**
 * pedimos al usurio que nos inrgese una cadena de solo letras, si llega a tener algun numero o un caracter que no
 * sea una letra esto nos mostrara el mensaje de error o tambien puede tirar error si se supera la cantidad de
 * caracteres maximos, si todos estos requesitos se cumplen mandaremos lo ingresado por el usuario a la variable deseada.
 * @param mensaje
 * @param mensajeError
 * @param destino
 */
void PedirLetras(char mensaje[],char mensajeError[], char destino[] );

/**
 * le tenemos que pasar dos mensajes uno para lo que queres que ingrese el usurio y el otro
 * de error esto que ingrese va a estar en un while y hasta no poner el vamos deseado que se
 * escuentre entre el max y min
 * @param mensaje
 * @param mensajeError
 * @param min
 * @param max
 * @return no saldra de ahi en caso de que esto no ocuura solo nos mostrata
 * el msj de error ya antes mencionado y si pine bien el numero devolvera ese valor
 * flotante
 */
float PedirFlotante(char mensaje[],char mensajeError[], int min, int max);


/**
 * le pedimos un mensaje para mostrarle al usuario si inrgresa algo que esta fuera del rango
 * indicado entre el max y min nos mostrara el mensaje de error o si ingresamos una letra o caracter
 * distinto a numero.
 * @param mensaje
 * @param mensajeError
 * @param min
 * @param max
 * @return
 */
int minMax(char mensaje[],char mensajeError[],int min, int max);




#endif /* VALIDACIONES_H_ */
