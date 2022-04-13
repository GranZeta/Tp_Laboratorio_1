
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/// @param a Pidimos el total
/// luego lo multiplicamos para encontrar su descuento.
/// @return nos retorna el total con descuento.
int descuento(int);

/// @param a Pidimos el total
/// luego multiplicamos por interes que querramos
/// @return nos retorna el total con intereses.
int interes(int);

/// @param a Pidimos un monto en pesos
/// luego hacemos una convercion,
/// esto lo hacemos con valores ya predeterminados.
/// Convetimos solo el monto del usuario a otro valor.
/// @return retornamos el valor ya convertido en otra moneda.
float conversiones(float);

/// @param a Tomamos el monto total del vuelo
/// @param b Tomamos los kilometros totales del vuelo
/// Los dividimos para sacar el precio por cada klm.
/// @return Precio por cada kilometro
float precioKilometro(int, int);

/// @param a Precio total x
/// @param b Precio total y
/// Se valida mediante if cual es el mayor y luego restamos
/// para obtener el la diferencia entre ambos.
/// @return Diferencia que tienen entre uno y el otro.
int diferencia(int, int);


/// @param a Pedimos los precios de vuelo.
/// @param b Pedimos los precios de kilometro.
/// Contenemos los datos que le mostramos al usuario
/// por pantalla al momento de ejecutar.
void ingresarDatos(int, int);

/// @param a En esta variable guardamos cualquier numero para validar si es positivo
/// en caso que no ingrese un positivo no podra salir de este ciclo.
/// @return Un valor positivo o un mensaje de error para volver a ingresar.
int numerosPositivo(int);


#endif /* FUNCIONES_H_ */
