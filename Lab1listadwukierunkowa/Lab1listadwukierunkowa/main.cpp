#include <iostream>
#include "stdio.h"
#include "Header.h"

int main()
{
	struct Node* head = NULL;

	addHead(&head, 3);
	addHead(&head, 5);
	addTail(&head, 7);
	insertNode(head->next, 8);

	displayList(head);

	addTail(&head, 2);
	removeNode(&head, head->next);

	displayList(head);

	getchar();
	return 0;
}