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


/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(ePassenger listaPasajeros [], int tamanio, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
 * @param listaPasajeros
 * @param tamanio
 * @return
 */
int initPassengers(ePassenger listaPasajeros [],int tamanio);

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
int printPassengers(ePassenger listaPasajeros [],int tamanio, etypeVuelo listaTipoVuelo[],etypePasajero listaTipoPasajero[], int tamanioT );


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





#endif /* ARRAYPASSENGER_H_ */
