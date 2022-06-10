#ifndef MENUS_H_
#define MENUS_H_
/**
 * Menu Principal
 * @return opcion.
 */
int Menu(void);

/**
 * Submenu para las modificaciones
 * @return opcion
 */
int Passenger_menuModify(void);

/**
 * Submenu para los ordenamientos
 * @return opcion
 */
int Passenger_menuOrden(void);

/**
 * Submenu para criterio de Ordenamiento
 * @return opcion
 */
int Passenger_subMenuOrden(void);

#endif /* MENUS_H_ */
