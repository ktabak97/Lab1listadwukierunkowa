#pragma once
#include <iostream>
#include "stdio.h"
using namespace std;

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
void removeTail(struct Node **head_ref);
void removeHead(struct Node **head_ref);
void findKey(struct Node **head_ref, int seeknumber);
void findIndex(struct Node **head_ref, int seekindex);