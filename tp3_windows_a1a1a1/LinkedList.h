
#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//Publicas
LinkedList* ll_newLinkedList(void);//ME GENERA UNA NUEVA LISTA
int ll_len(LinkedList* this);//REVISA LA CANTIDAD QUE VA A TENER MI LISTA
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);//AGREGA EMPLEADOS A LA LISTA
void* ll_get(LinkedList* this, int index);//BUSCA EN LA LISTA POR INDEX
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);//ELIMINA UN EMPLEADO DE LA LISTA
int ll_clear(LinkedList* this);//LIMPIA LA LISTA
int ll_deleteLinkedList(LinkedList* this);//BORRA LA LISTA
int ll_indexOf(LinkedList* this, void* pElement);//ME PASA EL INDEX DEL ELEMENTO QUE LE PASO
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);//METE UN EMPLEADO ENTRE OTRO
void* ll_pop(LinkedList* this,int index);//BORRA UN EMPLEADO Y LO DEVUELVE
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
