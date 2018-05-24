#include "Header.h"


void addHead(struct Node** head_ref, int new_key) // dodawanie glowy
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	new_node->key = new_key;
	
	if ((*head_ref) != NULL)
	{
		(*head_ref)->prev = new_node; 
	}

	(*head_ref) = new_node;

	cout << "Dodano glowe o indeksie " << new_key << endl;
}

void addTail(struct Node** head_ref, int new_key) //dodawanie ogona
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

void insertNode(struct Node* prev_node, int new_key) //dodawanie elementu jako nastepnego po podanym elemencie
{
	if (prev_node == NULL)
	{
		printf("Podany poprzedni element nie istnieje");
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


void removeNode(struct Node **head_ref, struct Node *remove) //usuwanie konkretnego elementu
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

void removeHead(struct Node **head_ref) //usuwanie glowy
{
	struct Node *remove = *head_ref;
	*head_ref = remove->next;

	cout << "Usunieto glowe o indeksie " << remove->key << endl;
	free(remove);
	return;
}

void removeTail(struct Node **head_ref) //usuwanie ogona
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

void findKey(Node **head_ref, int seeknumber) //wyszukiwanie ile razy powtorzyl sie dany klucz w liscie
{
	struct Node *find = *head_ref;
	int licznik = 0;
	if (find->key == seeknumber)
	{
		licznik++;
	}
	while (find->next != NULL)
	{
		find = find->next;
		if (find->key == seeknumber)
		{
			licznik++;
		}
	}

	cout << "Element o indeksie " << seeknumber << " pojawil sie " << licznik << " razy." << endl;
	return;
}

void findIndex(struct Node **head_ref, int seekindex) //wyszukiwanie jaki element znajduje sie pod podanym indeksem
{
	struct Node *find = *head_ref;

	for (int i = 0; i < seekindex; i++)
	{
		find = find->next;
	}

	cout << "Element o indeksie " << seekindex << " to " << find->key << endl;
	return;
}

void displayList(struct Node *node) // wyswietlanie listy
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