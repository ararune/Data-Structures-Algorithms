#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	return NULL;
}

void AddNode(BSTree* bst, char* word)
{
	// Rekurzivno se trazi mjesto za novi cvor u stablu. Ako rijec postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokazivac.

	if (*bst == NULL)
	{
		(*bst) = (Node*)malloc(sizeof(Node));
		(*bst)->word = word;
		(*bst)->left = NULL;
		(*bst)->right = NULL;
	}
	else if (strcmp(word, (*bst)->word) == 0)
	{
		free(word);
		return;
	}
	else if (strcmp((*bst)->word, word) < 0)
	{
		AddNode(&(*bst)->right, word);
	}
	else if (strcmp((*bst)->word, word) > 0)
	{
		AddNode(&(*bst)->left, word);
	}			
}

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se pronašla najduža grana (visina stabla).
	if (bst == NULL)
		return;

	int leftHeight = BSTHeight(bst->left);
	int rightHeight = BSTHeight(bst->right);

	if (leftHeight > rightHeight)	
		return leftHeight + 1;
	else
		return rightHeight + 1;
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rijeci u stablu na ekran po abecednom redu.
	// In-order setnja po stablu (lijevo dijete, cvor, desno dijete)
	if (bst == NULL)
		return;

	PrintBSTree(bst->left);

	printf("%s \n", bst->word);

	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE* fd)
{
	// Snima rijec po rijec iz stabla u tekstualnu datoteku. Rijeci su odvojene razmakom.
	// Pre-order setnja po stablu (trenutni cvor pa djeca)
	if (bst == NULL)
		return;

	fprintf(fd, "%s ", bst->word);

	SaveBSTree(bst->left, fd);

	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst)
{
	// Briše stablo (string word i sam cvor) iz memorije.
	// Post-order setnja po stablu (prvo djeca pa trenutni cvor)
	if (bst == NULL)
		return;

	DeleteBSTree(bst->left);

	DeleteBSTree(bst->right);

	free(bst->word);
	free(bst);

}

BSTree LoadBSTree(FILE* fd)
{
	// Ucitava rijec po rijec iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rijec duplicirati sa strdup().
	char buffer[1024];

	BSTree bst = NewBSTree();

	while (fscanf(fd, "%s", buffer) != EOF)

	{
		AddNode(&bst, strdup(buffer));
	}

	return NULL;
}
