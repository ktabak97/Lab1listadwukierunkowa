#include "Header.h"

int main()
{
	struct Node* head = NULL;

	addHead(&head, 3); //dodaje elementy, & przy head i ** w funkcji, poniewaz nie musze dzieki temu tworzyc konstruktora wezla
	addHead(&head, 5);
	addTail(&head, 7);
	insertNode(head->next, 8);

	displayList(head); //wyswietlam liste

	addTail(&head, 2);
	removeNode(&head, head->next); //usuwam element

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

	findKey(&head, 3); //wyszukuje po kluczu 3
	findKey(&head, 5);
	findKey(&head, 7);
	findKey(&head, 2);

	findIndex(&head, 6); //wyszukuje element o indeksie 6
	findIndex(&head, 8);
	getchar();
	return 0;
}