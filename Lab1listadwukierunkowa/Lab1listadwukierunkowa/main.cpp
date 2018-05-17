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

	removeHead(&head);
	displayList(head);

	addHead(&head, 1);
	addHead(&head, 9);
	displayList(head);
	removeTail(&head);
	displayList(head);

	addTail(&head, 7);
	displayList(head);

	addHead(&head, 3);
	addHead(&head, 5);
	addHead(&head, 3);
	addHead(&head, 3);
	addHead(&head, 3);
	addHead(&head, 3);
	addTail(&head, 2);


	displayList(head);

	findKey(&head, 3);
	findKey(&head, 5);
	findKey(&head, 7);


	getchar();
	return 0;
}