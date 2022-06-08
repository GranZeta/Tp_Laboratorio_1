int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);//lista
int controller_loadFromTextID(char* path , LinkedList* pArrayListPassenger, int* id);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);//lista
int controller_addPassenger(LinkedList* pArrayListPassenger, int* id);//lista
int controller_editPassenger(LinkedList* pArrayListPassenger);//lista
int controller_removePassenger(LinkedList* pArrayListPassenger);//lista
int controller_ListPassenger(LinkedList* pArrayListPassenger);//lista
int controller_sortPassenger(LinkedList* pArrayListPassenger);//lista
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);//lista
int controller_saveAsTextID(char* path , LinkedList* pArrayListPassenger, int id);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);//lista

