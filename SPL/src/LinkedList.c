#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
/******************************************************************************/
static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/******************************************************************************/
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}
/******************************************************************************/
int ll_len(LinkedList* this)
{
    int returnAux;
	returnAux = -1;
	if(this!=NULL)
	{
		returnAux = this->size;
	}
    return returnAux;
}
/******************************************************************************/
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode;
	pNode = NULL;
	if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
	{
		pNode = this->pFirstNode;
		for(int i=0;i<nodeIndex;i++)
		{
			pNode = pNode->pNextNode;
		}
	}
	return pNode;
}
/******************************************************************************/
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux;
	returnAux = -1;
	Node* nuevoNodo;
	nuevoNodo = NULL;
	Node* nodoAnterior;
	nodoAnterior = NULL;
	Node* nodoPosterior;
	nodoPosterior = NULL;
	if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
	{
		nuevoNodo = (Node*) malloc(sizeof(Node));
		if(nuevoNodo !=NULL)
		{
			nuevoNodo->pElement = pElement;
			if(nodeIndex == 0)
			{
				nuevoNodo->pNextNode = this->pFirstNode;
				this->pFirstNode = nuevoNodo;
			}
			else
			{
				nodoPosterior = getNode(this,nodeIndex);
				nuevoNodo->pNextNode = nodoPosterior;
				nodoAnterior = getNode(this, nodeIndex-1);
				nodoAnterior->pNextNode = nuevoNodo;
			}
			this->size++;
			returnAux = 0;
		}
	}
    return returnAux;
}
/******************************************************************************/
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux;
	returnAux = -1;
	if(this!=NULL)
	{
		addNode(this,ll_len(this),pElement);
		returnAux = 0;
	}
    return returnAux;
}
/******************************************************************************/
void* ll_get(LinkedList* this, int index)
{
    void* returnAux;
	returnAux = NULL;
	Node* nodoActual;
	nodoActual = NULL;

	if(this!=NULL && index >= 0 && index < ll_len(this))
	{
		nodoActual = getNode(this, index);
		returnAux = nodoActual->pElement;
	}
    return returnAux;
}
/******************************************************************************/
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux;
	returnAux = -1;
	Node* nodoActual;
	nodoActual = NULL;
	if(this!= NULL && index >= 0 && index < ll_len(this))
	{
		nodoActual = getNode(this, index);
		nodoActual->pElement = pElement;
		returnAux = 0;
	}
    return returnAux;
}
/******************************************************************************/
int ll_remove(LinkedList* this,int index)
{
    int returnAux;
	returnAux = -1;
	Node* nodo;
	nodo = NULL;
	Node* nodoAnterior;
	nodoAnterior = NULL;
	Node* nodoPosterior;
	nodoPosterior = NULL;
	if(this!=NULL && index>=0 && index<ll_len(this))
	{
		nodo = getNode(this,index);
		nodoPosterior = getNode(this,index+1);
		if(index==0)
		{
			this->pFirstNode = nodoPosterior;
		}
		else
		{
			nodoAnterior = getNode(this,index-1);
			nodoAnterior->pNextNode = nodoPosterior;
		}
		free(nodo);
		this->size--;
		returnAux = 0;
	}
    return returnAux;
}
/******************************************************************************/
int ll_clear(LinkedList* this)
{
    int returnAux;
	returnAux = -1;
	if(this!=NULL)
	{
		while(this->size!=0)
		{
			ll_remove(this,ll_len(this)-1);
		}
		returnAux = 0;
	}
    return returnAux;
}
/******************************************************************************/
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux;
	returnAux = -1;
	if(this!=NULL)
	{
		if(ll_len(this) != 0)
		{
			ll_clear(this);
			free(this);
		}
		returnAux = 0;
	}
    return returnAux;
}
/******************************************************************************/
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux;
	returnAux = -1;
	int i;
	i = 0;
	Node* nodo;
	nodo = NULL;
	if(this!=NULL)
	{
		nodo = this->pFirstNode;
		for(i=0;i<ll_len(this);i++)
		{
			if(nodo->pElement == pElement)
			{
				returnAux = i;
				break;
			}
			nodo = nodo->pNextNode;
		}
	}
    return returnAux;
}
/******************************************************************************/
int ll_isEmpty(LinkedList* this)
{
    int returnAux;
	returnAux = -1;
	if(this!=NULL)
	{
		if(ll_len(this) == 0)
		{
			returnAux = 1;
		}
		else
		{
			returnAux = 0;
		}
	}
    return returnAux;
}
/******************************************************************************/
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux;
	returnAux = -1;
	int validar;
	if(this!=NULL && index>=0 && index<=ll_len(this))
	{
		validar = addNode(this,index,pElement);
		if(validar == 0)
		{
			returnAux = 0;
		}
	}
    return returnAux;
}
/******************************************************************************/
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux;
	returnAux = NULL;
	Node* nodo;
	nodo = NULL;
	if(this != NULL && index>=0 && index<ll_len(this))
	{
		nodo = getNode(this,index);
		if(nodo != NULL)
		{
			returnAux = nodo->pElement;
			ll_remove(this,index);
		}
	}
    return returnAux;
}
/******************************************************************************/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux;
	returnAux = -1;
	int validar;
	if(this!=NULL)
	{
		validar = ll_indexOf(this,pElement);
		returnAux = 0;
		if(validar != -1)
		{
			returnAux = 1;
		}
	}
    return returnAux;
}
/******************************************************************************/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux;
	returnAux = -1;
	Node* nodo;
	nodo = NULL;
	int i;
	if(this!=NULL && this2!=NULL)
	{
		nodo = this2->pFirstNode;
		returnAux = 1;
		for(i=0;i<ll_len(this2);i++)
		{
			if(ll_contains(this,nodo->pElement) == 0)
			{
				returnAux = 0;
				break;
			}
			nodo = nodo->pNextNode;
		}
	}
    return returnAux;
}
/******************************************************************************/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray;
	cloneArray = NULL;
	int i;
	if(this!=NULL && from < ll_len(this) && from >= 0 && to <=ll_len(this))
	{
		cloneArray = ll_newLinkedList();
		for(i=from;i<to;i++)
		{
			ll_add(cloneArray,ll_get(this,i));
		}
	}
    return cloneArray;
}
/******************************************************************************/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray;
	cloneArray = NULL;
	if(this!=NULL)
	{
		cloneArray = ll_subList(this,0,ll_len(this));
	}
    return cloneArray;
}
/******************************************************************************/
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux;
	returnAux = -1;
	int i;
	int j;
	int len;
	int validar;
	void* elemento1;
	void* elemento2;
	len = ll_len(this);
	if(this!=NULL && (order == 0 || order == 1) && pFunc!=NULL)
	{
		for(i=0;i<len-1;i++)
		{

			for(j=i+1;j<len;j++)
			{
				elemento1 = ll_get(this,i);//-----------------------------
				elemento2 = ll_get(this,j);
				validar = pFunc(elemento1,elemento2);
				if((order == 1 && validar > 0) || (order == 0 && validar < 0))
				{
					ll_set(this, j, elemento1);
					ll_set(this, i, elemento2);
				}
			}
		}
		returnAux = 0;
	}
    return returnAux;
}
/******************************************************************************/
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
	 LinkedList* nuevaLinkedList;
	 nuevaLinkedList = ll_newLinkedList();
	 void* elemento;
	 int validar;
	 for(int i=0;i<ll_len(this);i++)
	 {
		 elemento = ll_get(this,i);
		 validar = fn(elemento);
		 if(validar == 1)
		 {
			 ll_add(nuevaLinkedList,elemento);
		 }
	 }
	 return nuevaLinkedList;
}
/******************************************************************************/
LinkedList* ll_map(LinkedList* this,int(*pf)(void* element))
{
	LinkedList* nuevaLinkedList;
	nuevaLinkedList = ll_newLinkedList();
	void* elemento;
	int validar;
	for(int i=0;i<ll_len(this);i++)
	{
		elemento = ll_get(this,i);
		validar = pf(elemento);
		if(validar == 1)
		{
			ll_add(nuevaLinkedList,elemento);
		}
	}
	return nuevaLinkedList;
}
