#include <iostream>
#include "stdio.h"
#include "Header.h"

using namespace std;

void addHead(struct Node** head_ref, int new_key)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->key = new_key;

	new_node->next = (*head_ref);
	new_node->prev = NULL;

	if ((*head_ref) != NULL) 
	{
		(*head_ref)->prev = new_node;
	}

	(*head_ref) = new_node;

	cout << "Dodano glowe o indeksie " << new_key << endl;
}

void addTail(struct Node** head_ref, int new_key)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *head_ref;
	new_node->key = new_key;
	new_node->next = NULL;

	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL) 
	{
		last = last->next;
	}
	

	last->next = new_node;
	new_node->prev = last;

	cout << "Dodano ogon o indeksie " << new_key << endl;
}

void insertNode(struct Node* prev_node, int new_key)
{
	if (prev_node == NULL)
	{
		printf("Podany poprzedni element musi istniec");
		return;
	}

	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	
	new_node->key = new_key;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	new_node->prev = prev_node;

	if (new_node->next != NULL)
	{
		new_node->next->prev = new_node;
	}

	cout << "Dodano element o indeksie " << new_key << endl;
}


void removeNode(struct Node **head_ref, struct Node *remove)
{
	if (*head_ref == NULL || remove == NULL)
	{
		cout << "Nie da sie usunac, bo element nie istnieje" << endl;
		return;
	}
	
	if (*head_ref == remove)
	{
		*head_ref = remove->next;
	}

	if (remove->next != NULL)
	{
		remove->next->prev = remove->prev;
	}
	
	if (remove->prev != NULL)
	{
		remove->prev->next = remove->next;
	}

	cout << "Usunieto element o indeksie " << remove->key << endl;
	free(remove);

	return;
}

void removeHead(struct Node **head_ref) 
{
	struct Node *remove = *head_ref;
	*head_ref = remove->next;

	cout << "Usunieto glowe o indeksie " << remove->key << endl;
	free(remove);
	return;
}

void removeTail(struct Node **head_ref)
{
	struct Node *remove = *head_ref;

	while (remove->next != NULL)
	{
		remove = remove->next;
	}
	remove->prev->next = NULL;

	cout << "Usunieto ogon o indeksie " << remove->key << endl;	
	free(remove);
	return;
}

void findKey(struct Node **head_ref, int seeknumber)
{
	struct Node *find = *head_ref;
	int licznik = 0;
	while (find->next != NULL)
	{
		if (find->key == seeknumber)
		{
			licznik++;
		}
		find = find->next;
		
	}
	
	cout << "Element o indeksie " << seeknumber<< " pojawil sie " << licznik << " razy." << endl;
	return;
}

void findIndex(struct Node **head_ref, int seekindex)
{
	struct Node *find = *head_ref;

	//for ();
	while (find->next != NULL)
	{
		if (find->key == seekindex)
		{
			
		}
		find = find->next;

	}

	cout << "Element o indeksie " << seekindex << " to " << find << endl;
	return;
}

void displayList(struct Node *node)
{
	struct Node *last;
	cout << endl << "Wypisuje liste: " << endl;
	while (node != NULL)
	{
		cout << node->key << " ";
		last = node;
		node = node->next;
	}
	cout << endl << endl;

}

