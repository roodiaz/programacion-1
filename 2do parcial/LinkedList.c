#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this= (LinkedList *)malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->size= 0; //inicializo valores de linkedlist en vacio
        this->pFirstNode= NULL;//inicializo valores de linkedlist en vacio
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux= -1;

    if(this != NULL)
        returnAux= this->size;

    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    if(this != NULL)
    {
        int longitud= ll_len(this);

        if(nodeIndex >= 0 && nodeIndex < longitud)
        {
            pNode= this->pFirstNode;

            while (nodeIndex > 0)
            {
                pNode= pNode->pNextNode;
                nodeIndex -- ;
            }
        }
    }

    return pNode;
}


Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux= -1;

    Node* pNewNode= (Node*)malloc(sizeof(Node));
    Node* pAuxNode;
    Node* pOldNode;
    int longitud = ll_len(this);



    if( (this != NULL) && (pNewNode != NULL) && (nodeIndex >= 0) && (nodeIndex <= longitud))
    {
            if(nodeIndex == 0)//Se realiza el add en el primer lugar, estando vacio o no
            {
                pAuxNode=this->pFirstNode;//Se copia el primer nodo en variable auxiliar
                this->pFirstNode = pNewNode;//Se enlaza NUEVO NODO al comienzo de la LinkedList

                pNewNode->pNextNode=pAuxNode;//Se enlaza el viejo primer nodo al next del nuevo nodo
                pNewNode->pElement=pElement;

                returnAux = 0;
            }
            else if((this->pFirstNode != NULL || this->pFirstNode == NULL)
                    && (nodeIndex > 0 && nodeIndex <= ll_len(this)))//Se realiza el add en el index
            {
                pOldNode=getNode(this,nodeIndex);  //Get del NODO a reemplazar
                pAuxNode=getNode(this,nodeIndex-1); //Get del NODO anterior al que reemplazo

                pNewNode->pNextNode=pOldNode; //Muevo el NODO del INDICE al siguiente del NUEVO NODO
                pNewNode->pElement=pElement;   //Asigno elemento
                pAuxNode->pNextNode = pNewNode;//Asigno al NODO ANTERIOR el NUEVO NODO como siguiente

                returnAux= 0;
            }

            this->size++;
    }

    return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux= -1;

    if(this != NULL)
    {
        addNode(this,ll_len(this),pElement);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado.
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode=NULL;

    if(this != NULL)
    {
        if(index >= 0 && index < ll_len(this))
        {
            pNode = getNode(this, index);
            returnAux = pNode->pElement;
        }
    }

    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode=NULL;

    if(this != NULL)
    {
        if(index >= 0 && index < ll_len(this))
        {
            pNode = getNode(this, index);
            pNode->pElement = pElement;

            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux= -1;
    Node* pPrevNode = NULL;
    Node* pNextNode = NULL;
    Node* pAuxNode = NULL;

    if(this!= NULL && index>=0 && index< ll_len(this))
    {
        pAuxNode=getNode(this,index);//obtengo el nodo a eliminar

        if(pAuxNode != NULL)//verificar que el nodo en el indice existe
        {
            if(index == 0)//si el nodo a remover esta en el primer indice
            {
                this->pFirstNode=pAuxNode->pNextNode;//Se enlaza NODO DEL INDICE 1 al comienzo de la LinkedList
                free(pAuxNode);

                returnAux=0;
            }
            else//si el nodo no esta en el primer indice
            {
                pPrevNode = getNode(this,(index -1));//copio nodo previo al nodo a eliminar
                pNextNode = getNode(this,(index +1));//copio nodo siguiente al nodo a eliminar

                pPrevNode->pNextNode = pNextNode;//uno el nodo previo y el siguiente del eliminado
                free(pAuxNode);

                 returnAux=0;
            }


        this->size--;//reduzco tamanio de la linkedlist

        }
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        for(int i=0; i<ll_len(this); i++)
            ll_remove(this, i);

        returnAux = 0;
    }

    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        int borrado = ll_clear(this);

        if(borrado == 0)
        {
            free(this);
            returnAux = 0;
        }
    }

    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        Node* pNode = NULL;

        for(int i=0; i < ll_len(this); i++)
        {
            pNode = getNode(this, i);

            if(pNode->pElement == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}

int ll_isEmpty(LinkedList* this)
{
    int returnAux= -1;

    if(this != NULL)
    {
        if(ll_len(this) == 0)
            returnAux= 1;
        else
            returnAux= 0;
    }

    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux= -1;

    if(this != NULL)
    {
        int longitud = ll_len(this);

        if( (index >= 0) && (index <= longitud) )
            returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL)
    {
        int longitud = ll_len(this);

        if( (index >= 0) && (index <= longitud) )
        {
            returnAux = ll_get(this, index);
            ll_remove(this, index);
        }
    }

    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux= -1;

    if(this != NULL)
    {
        if (ll_indexOf(this, pElement) == -1)
            returnAux= 0;
        else
            returnAux= 1;
    }

    return returnAux;
}

int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int returnAux = -1;

    if( (this != NULL) && (this2 != NULL) )
    {
        int longitudLista1 = ll_len(this);
        int longitudLista2 = ll_len(this2);

        returnAux = 0;

        if(longitudLista1 >= longitudLista2)
        {
            Node* pNode = NULL;

            for(int i=0; i< longitudLista2; i++)
            {
                pNode = getNode(this, i);

                if( (ll_contains(this, pNode->pElement)) == 1 )
                    returnAux = 1;
            }
        }
    }

    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    Node* ptr_AuxNode = NULL;

    if (this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();

        for (i = from ; i <= to ; i++)
        {
            ptr_AuxNode = ll_get(this,i);
            ll_add(cloneArray,ptr_AuxNode);
        }
    }

    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
        cloneArray = ll_subList(this, 0, this->size);

    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int i = 0;
    void* pAux;
    int j= 0;

    if( this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        for(i=0; i< (ll_len(this)-1) ; i++)
        {
            for(j= i+1; j < ll_len(this); j++)
            {
                if(order == 1 && pFunc(ll_get(this,i), ll_get(this,j)) > 0)
                {
                    pAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAux);
                }
                else if(order == 0 && pFunc(ll_get(this,i), ll_get(this,j)) < 0)
                {
                    pAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAux);
                }
            }
        }

        returnAux = 0;
    }
    return returnAux;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* newList = NULL;

    if ( (this != NULL) && (pFunc != NULL) )
    {
        newList = ll_newLinkedList();

        void* aux = NULL;
        int i;

        for (i=0;i<ll_len(this);i++)
        {
            aux = ll_get(this,i);

            if (pFunc(aux)==1)
                ll_add(newList,aux);

            aux = NULL;
        }
    }

    return newList;
}

