#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests() {
	printf("Tests running...\n");
	listElement* l = createEl("Test String (1).", 30);
	//printf("%s\n%p\n", l->data, l->next);
	//Test create and traverse
	traverse(l);
	printf("\n");

	//Test insert after
	listElement* l2 = insertAfter(l, "another string (2)", 30);
	insertAfter(l2, "a final string (3)", 30);
	traverse(l);
	printf("\n");

	// Test delete after
	deleteAfter(l);
	traverse(l);
	printf("\n");
	push(&l, "4", 30);
	//traverse(l);
	listElement* element = pop(&l);

	printf("%s\n\n", element->data);
	traverse(l);
	printf("\n");
	enqueue(&l, "5", 30);
	element = dequeue(l);
	printf("%s\n\n", element->data);
	traverse(l);
	printf("\nTests complete.\n");
}
