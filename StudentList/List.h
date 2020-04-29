#pragma once
#include <stdint.h>
typedef struct Node
{
	void* item;
	struct Node* nextNode;
}Node;
typedef struct Node* node_p;
typedef struct List
{
	uint16_t numberOfItems;
	node_p head;
}List;
typedef struct List* list_p;

typedef enum list_ReturnCode_t {
	LIST_OK, LIST_EMPTY, LIST_NOT_FOUND, LIST_NULL,
	LIST_ERROR
}list_ReturnCode_t;
list_p list_create();
node_p node_create(void* item);
list_ReturnCode_t list_destroy(list_p self);
list_ReturnCode_t list_addItem(list_p self, void* item);
list_ReturnCode_t list_getItem(list_p self, void** item, uint16_t index);
list_ReturnCode_t list_removeItem(list_p self, void* item);
uint16_t list_noOfItems(list_p self);



