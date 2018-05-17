#pragma once
#include <iostream>
#include "stdio.h"


struct Node {
	Node *prev;
	Node *next;
	int key;
};

	void addHead(struct Node** head_ref, int new_key);
	void displayList(struct Node *node);
	void addTail(struct Node** head_ref, int new_key);
	void insertNode(struct Node* prev_node, int new_data);
	void removeNode(struct Node **head_ref, struct Node *remove);
	//void removeTail();
	//void removeHead();
	//void removeElement();
