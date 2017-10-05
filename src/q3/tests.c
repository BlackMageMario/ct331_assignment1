#include <stdio.h>
#include "genericLinkedList.h"

void runIntTests(){
	printf("\nInt tests running...\n");
	int array[30] = {1, 2, 3, 4, 5};
	listElement* l = createEl(&array[0], sizeof(int), &printInt);
	printf("Linked List after creation.\n");
	traverse(l);
	printf("\n");
	listElement* l2 = insertAfter(l, &array[1], sizeof(int), &printInt);
	insertAfter(l2, &array[2], sizeof(int), &printInt);
	printf("Linked List after insertAfter\n");
	traverse(l);
	printf("\n");
	deleteAfter(l);
	printf("Linked List after deletion\n");
	traverse(l);
	printf("\n");
	push(&l, &array[3], sizeof(int), &printInt);
	printf("Linked List after push\n");
	traverse(l);
	printf("\n");
	listElement* element = pop(&l);
	printf("Linked List after pop\n");
	traverse(l);
	printf("\n");
	enqueue(&l, &array[4], sizeof(int), &printInt);
	printf("Linked List after enqueue\n");
	traverse(l);
	printf("\n");
	element = dequeue(l);
	printf("Linked List after dequeue\n");
	traverse(l);
	printf("\n");
	enqueue(&l, element->data, element->size, element->printFunction);
	printf("Linked List after enqueue\n");
	traverse(l);
	printf("\nInt tests complete.\n");
	
}
void runStringTests()
{
	char *stringArray[10] = {"1", "2", "3", "4", "5"};
	printf("\nString tests running...\n");
	listElement* l = createEl(stringArray[0], sizeof(char*), &printString);
	printf("Linked List after creation.\n");
	traverse(l);
	printf("\n");
	listElement* l2 = insertAfter(l, stringArray[1], sizeof(char*), &printString);
	insertAfter(l2, stringArray[2], sizeof(char*), &printString);
	printf("Linked List after insertAfter\n");
	traverse(l);
	printf("\n");
	deleteAfter(l);
	printf("Linked List after deletion\n");
	traverse(l);
	printf("\n");
	push(&l, stringArray[3], sizeof(char*), &printString);
	printf("Linked List after push\n");
	traverse(l);
	printf("\n");
	listElement* element = pop(&l);
	printf("Linked List after pop\n");
	traverse(l);
	printf("\n");
	enqueue(&l, stringArray[4], sizeof(char*), &printString);
	printf("Linked List after enqueue\n");
	traverse(l);
	printf("\n");
	element = dequeue(l);
	printf("Linked List after dequeue\n");
	traverse(l);
	printf("\n");
	enqueue(&l, element->data, element->size, element->printFunction);
	printf("Linked List after enqueue\n");
	traverse(l);
	printf("\nString tests complete.\n");
}

void runTests()
{
	runIntTests();
	runStringTests();
}
