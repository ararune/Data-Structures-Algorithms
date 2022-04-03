#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable* NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokaziva�a)
	HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
	newTable->size = size;
	newTable->load = 0;
	newTable->table = (Bin**)malloc(sizeof(Bin*) * size);
	for (int i = 0; i < size; i++)
		newTable->table[i] = NULL;
	return newTable;
}
unsigned int hash(char* word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while (*word != '\0')
	{
		key = key * HCONST + *word;
		word++;
	}
	return key;
}
void Insert(HashTable* ht, char* word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu
	Bin** table = ht->table;
	unsigned int index = hash(word) % ht->size;
	Bin* item = table[index];

	Bin* newItem = (Bin*)malloc(sizeof(Bin));
	newItem->next = NULL;
	newItem->word = word;

	Bin* temp = item;
	item = newItem;
	newItem->next = temp;
	ht->load++;
}

int Get(HashTable* ht, char* word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	Bin** table = ht->table;
	unsigned int index = hash(word) % ht->size;
	Bin* item = table[index];
	
	while (item != NULL)
	{
		if (strcmp(item->word, word) == 0) return 1;
		item = item->next;
	}
	return 0;
}

void DeleteTable(HashTable* ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	for (int i = 0; i < ht->size; i++) {
		Bin* item = ht->table[i];
		while (item != NULL) {
			Bin* del = item;
			item = item->next;
			free(del->word);
			free(del);
		}
	}
	free(ht->table);
	free(ht);
}
