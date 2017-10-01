#include <stdio.h>
#include "genericLinkedList.h"

void runTests(){
	printf("Tests running...\n");
	listElement* l = createEl(1, sizeof(int), &printInt);
	//printf("%s\n%p\n", l->data, l->next);
	//Test create and traverse
	traverse(l);
	printf("\n");

	//Test insert after
	listElement* l2 = insertAfter(l, 2, sizeof(int), &printInt);
	insertAfter(l2, 3, sizeof(int), &printInt);
	traverse(l);
	printf("\n");

	// Test delete after
	deleteAfter(l);
	traverse(l);
	printf("\n");
	push(&l, 4, sizeof(int), &printInt);
	//traverse(l);
	listElement* element = pop(&l);

	//printf("%s\n\n", element->data);
	traverse(l);
	printf("\n");
	enqueue(&l, 5, sizeof(int), &printInt);
	element = dequeue(l);
	printf("GOD SAVE US");
	//printf("%s\n\n", element->data);
	traverse(l);
	printf("\nTests complete.\n");
}
