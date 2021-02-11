#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct address {
	char nume[40];
	char strada[40];
	char oras[20];
	char stat[3];
	char cod_postal[11];
	struct address* urm;
}info;

void slstore(struct address* i, struct address** ultim)
{
	if (!*ultim) { /* First element of the list*/
		*ultim = i;
	}
	else
	{
		(*ultim)->urm = i;
	}

	i->urm = NULL;
	*ultim = i;
}

void sls_store(struct address* i, /* New element to be inserted*/
	struct address** prim, /*  First element of the list*/
	struct address** ultim) /* Last element of the list*/
{
	struct address* vechi, * p;

	if (!*ultim) {
		/* First element in the list*/

		i->urm = NULL;
		*ultim = i;
		*prim = i;

		return;
	}
	vechi = NULL;
	while (p)
	{
		if (strcmp(p->nume, i->nume) < 0)
		{
			vechi = p;
			p = p->urm;
		}
		else
			if (vechi)
			{
				vechi->urm = i;
				i->urm = p;
				return;
			}

		i->urm = p;
		*prim = i;
		return;
	}

	(*ultim)->urm = i;
	i->urm = NULL;
	*ultim = i;
}

void display(struct address* prim)
{
	while (prim)
	{
		printf("Name is %s", prim->nume);
		prim = prim->urm;
	}
}

struct address* search(struct address* prim, char* n)
{
	while (prim)
	{
		if (!strcmp(n, prim->nume)) return prim;
		prim = prim->urm;
	}
	return NULL;
}

void sdelete(
	struct address* p,
	struct address* a,
	struct address** prim,
	struct address** ultim)
{
	if (p) p->urm = a->urm;
	else *prim = a->urm;

	if (p == *ultim && p) *ultim = p;
} 