#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

//typedef void (*printFunction)(void* data);

typedef struct listElementStruct {
	void* data;
	size_t size;
	void (*printFunction)(void* data);
	struct listElementStruct* next;
} listElement;
void printChar(void* data);
void printString(void* data);
void printInt(void* data);
void printFloat(void* data);
void printDouble(void* data);
void printLong(void* data);
//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, void* printFunction);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, size_t size, void* printFunction);

//Delete the element after the given el
void deleteAfter(listElement* after);

int length(listElement* list);

void push(listElement** list, void* data, size_t size, void* printFunction);

listElement* pop(listElement** list);

void enqueue(listElement** list, void* data, size_t size, void* printFunction);

listElement* dequeue(listElement* list);

#endif