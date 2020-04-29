#include <stddef.h>
#include "List.h"
#include <stdlib.h>
#include <stdio.h>


/*creates a list and returns a pointer to it*/
list_p list_create() {
	list_p _newList = calloc(sizeof(List), 1);
	if (_newList != NULL)
	{
		_newList->numberOfItems = 0;
		_newList->head = NULL;
	}
	/*else
	{
		return LIST_NULL;
	}*/
	return _newList;
}
/*creates a node and returns a pointer to it*/
node_p node_create(void* data)
{
	node_p _newNode = calloc(sizeof(Node), 1);
	if (_newNode != NULL)
	{
		_newNode->item = data;
		_newNode->nextNode = NULL;
	}
	else
	{
		_newNode = NULL;
		return _newNode;
	}
	return _newNode;
}
/*de-allocates the memory the list occupies*/
list_ReturnCode_t list_destroy(list_p self)
{

	if (self != NULL)
	{
		free(self);
		return LIST_OK;
	}

	return LIST_NULL;

}
/*Adds an item to the list */
list_ReturnCode_t list_addItem(list_p self, void* item)
{

	Node* node = node_create(item);

	if (self != NULL)
	{

		if (self->head == NULL)
		{
			self->head = node;
			node->nextNode = NULL;
		}
		else
		{
			Node* current = self->head;
			while (current->nextNode != NULL)
			{
				current = current->nextNode;
			}
			current->nextNode = node;
		}


		self->numberOfItems++;
		return LIST_OK;
	}
	else
	{
		return LIST_ERROR;
	}


}/*Overrides the pointer given to point to the value at the given index*/
list_ReturnCode_t list_getItem(list_p self, void** item, uint16_t index)
{
	if (self != NULL)
	{
		Node* pointerCurrent = self->head;
		for (uint16_t i = 0; i <= index; i++)
		{
			if (i == index)
			{
				*item = pointerCurrent->item;
				return LIST_OK;
			}
			pointerCurrent = pointerCurrent->nextNode;
		}
	}


	return LIST_NOT_FOUND;


}
/*list removeItem -> removes item should the currentNode->item=item,
before it get's removed it assigns the next node of the previous node(the one before currentNode) to the nextNode of the current Node
previousNode->nextNode=currentnode->NextNode*/
list_ReturnCode_t list_removeItem(list_p self, void* item)
{
	if (self != NULL)
	{
		Node* currentNode = self->head;
		Node* previous = self->head;
		int count = 0;
		for (int i = 0; i < self->numberOfItems; i++)
		{
			if (currentNode->item == item)
			{
				for (int i = 0; i < (count - 1); i++)
				{
					previous = previous->nextNode;
				}
				previous->nextNode = currentNode->nextNode;
				free(currentNode);
				self->numberOfItems--;
				return LIST_OK;
			}
			else
			{
				currentNode = currentNode->nextNode;
				count++;
			}
		}
	}

	return LIST_NULL;

}
uint16_t list_noOfItems(list_p self)
{
	if (self != NULL)
	{
		int number = 0;
		for (int i = 0; i < self->numberOfItems; i++)
		{
			number++;
		}
		return number;
	}
	else
	{
		return LIST_NULL;
	}
}
