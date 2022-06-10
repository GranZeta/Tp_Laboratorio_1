
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/**
 * Carga los Ids de los pasajeros desde el archivo id.csv (modo texto).
 * @param path
 * @param pArrayListPassenger
 * @param id
 * @return int
 */
int controller_loadFromTextID(char* path , LinkedList* pArrayListPassenger, int* id);

/**
 * Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 * @param path
 * @param pArrayListPassenger
 * @return int
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/**
 * Alta de pasajero
 * @param pArrayListPassenger
 * @param id
 * @return int
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* id);

/**
 * Modificar datos de pasajero
 * @param pArrayListPassenger
 * @return int
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/**
 * Baja de pasajero
 * @param pArrayListPassenger
 * @return int
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/**
 * Listar pasajeros
 * @param pArrayListPassenger
 * @return int
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/**
 * Ordenar pasajeros
 * @param pArrayListPassenger
 * @return int
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/**
 * Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 * @param path
 * @param pArrayListPassenger
 * @return int
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/**
 * Guarda los datos de los pasajeros en el archivo id.bin (modo binario).
 * @param path
 * @param pArrayListPassenger
 * @param id
 * @return int
 */
int controller_saveAsTextID(char* path , LinkedList* pArrayListPassenger, int id);

/**
 * Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 * @param path
 * @param pArrayListPassenger
 * @return Retorna 0 si pudo y en caso de error -1.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

