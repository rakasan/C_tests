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
	struct address* preced;
}info;

void dlstore(struct address* i, struct address** ultim)
{
	if (!*ultim) *ultim = i;
	else (*ultim)->urm = i;

	i->urm = NULL;
	i->preced = *ultim;
	*ultim = i;
}

void dls_store(
	struct address *i,
	struct address **prim,
	struct address **ultim
)
{
	struct address* old, * p;
	if (*ultim == NULL)
	{
		i->urm = NULL;
		i->preced = NULL;
		*ultim = i;
		*prim = i;
		return;
	}
	p = *prim; /* Start at the beginning of the list */

	old = NULL;

	while (p)
	{
		if (strcmp(p->nume, i->nume) < 0)
		{
			old = p;
			p = p->urm;
		}
		else
		{
			if (p->preced)
			{
				p->preced->urm = i;
				i->urm = p;
				i->preced = p->preced;
				p->preced = i;
				return;
			}
			i->urm = p;
			i->preced = NULL;
			p->preced = i;
			*prim = i;
			return;
		}
		old->urm = i;
		i->urm = NULL;
		i->preced = old;
		*ultim = i;
	}
}

void dl_delete(
	struct address *a,
	struct address **prim,
	struct address **ultim)
{
	if (a->preced)
	{
		a->preced -> urm = a->urm;
	}
	else
	{
		*prim = a->urm;
		if (prim) 
		{
			(*prim)->preced = NULL;
		}
	}

	if (a->urm) a->urm->preced = a->preced;
	else *ultim = a->preced;
}