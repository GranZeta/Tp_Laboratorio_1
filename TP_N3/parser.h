#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/**
 * Parsea los id los datos de los pasajeros desde el archivo id.csv (modo texto).
 * @param pFile
 * @param pArrayListPassenger
 * @param id
 * @return int
 */
int parser_IdFromText(FILE* pFile , LinkedList* pArrayListPassenger, int* id);

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

#endif /* PARSER_H_ */

