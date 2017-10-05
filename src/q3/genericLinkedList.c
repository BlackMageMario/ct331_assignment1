#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

listElement* createEl(void* data, size_t size, void* printFunction) {
	listElement* e = malloc(sizeof(listElement));
	if (e == NULL) {
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}
	void* dataPointer = malloc(size);//i had a more complicated function for this but allocating based on the size makes sense
	if (dataPointer == NULL) {
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	memmove(dataPointer, data, size);//I did not have this for a long time - moves the data into the data pointer
	e->data = dataPointer;
	e->size = size;
	e->printFunction = printFunction;
	e->next = NULL;
	return e;
}

//Prints out each element in the list
void traverse(listElement* start) {
	listElement* current = start;
	while (current != NULL) {
		current->printFunction(current->data);//prints out our data
		current = current->next;
	}
}

void printChar(void* data)
{
	printf("%c\n", *(char*)data);
}
void printString(void* data)
{
	printf("%s\n", (char*)data);
}
void printInt(void* data)
{
	printf("%d\n", *(int*) data);
}
void printFloat(void* data)
{
	printf("%f\n", *(float*) data);
}
void printDouble(void* data)
{
	printf("%f\n", *(double*)data);
}
void printLong(void* data)
{
	printf("%ld\n", *(long*)data);
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size, void* printFunction) {
	listElement* newEl = createEl(data, size, printFunction);
	listElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after) {
	listElement* delete = after->next;
	listElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}

int length(listElement* list)
{
	listElement* current = list;
	int num = 0;
	while (current != NULL)
	{
		num++;
		current = current->next;
	}
	return num;
}

void push(listElement** list, void* data, size_t size, void* printFunction)
{
	listElement* newElement = createEl(data, size, printFunction);
	newElement->next = *list;
	*list = newElement;
}

listElement* pop(listElement** list)
{
	listElement* temp = *list;
	*list = (*list)->next;
	return temp;
}

void enqueue(listElement** list, void* data, size_t size, void* printFunction)
{
	listElement* newElement = createEl(data, size, printFunction);
	newElement->next = *list;
	*list = newElement;
}

listElement* dequeue(listElement* list)
{
	listElement* current = list;
	while ((current->next)->next != NULL)
	{
		current = current->next;
	}
	listElement* temp = current->next;
	current->next=NULL;
	return temp;
}