#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct address{
	char name[30];
	char street[30];
	char city[30];
	char state[30];
	char city_code[11];
	address *next;
	address *previous;
}entry_list;

address *first;
address *last;
address *find(char *);

static void enter(void);
static void search(void);
static void save(void);
static void load(void);
static void list(void);
static void delete_element(address **, address **);
static void dls_store(address* i, address** first, address** last);
static void inputs(char *, char *, int);
static void display(address *);
static int menu_select(void);
static address* find(char* nume);

void dll_main(void)
{
	first = last = NULL;

	for (;;)
	{
		switch (menu_select())
		{
			case 1: enter(); break;
			case 2: delete_element(&first, &last); break;
			case 3: list(); break;
			case 4: search(); break;
			case 5: save(); break;
			case 6: load(); break;
			case 7: exit(0);
			default: break;
		}
	}
}

static int menu_select(void)
{
	char s[80];

	int c;

	do {
		gets_s(s);
		c = atoi(s);
	} while (c < 0 || c>7);
	
	return c;
}

static void enter(void)
{
	address* info;
	for (;;)
	{
		info = (address*)malloc(sizeof(entry_list));

		if (!info)
		{
			printf("\n There is no more memory");
		}

		/*inputs("Name", info->name, 30);*/
		dls_store(info, &first, &last);
	}
}

static void inputs(char* mesaj, char* s, int numar)
{
	char p[255];

	do {
		printf(mesaj);
		gets_s(p);
		if (strlen(p) > numar) printf("To long");
	} while (strlen(p) < numar);

	strcpy(s, p);
}

static void dls_store(
	address* i,
	address** first,
	address** last
)
{
	address* old, * p;
	if (*last == NULL) {
		i->next = NULL;
		i->previous = NULL;
		*last = i;
		*first = i;
		return;
	}
	p = *first;
	old = NULL;

	while (p)
	{
		if (strcmp(p->name, i->name) < 0) {
			old = p;
			p = p->next;
		}
		else {
			if (p->previous) {
				p->previous->next = i;
				i->next = p;
				i->previous = p->previous;
				p->previous = i;
				return;
			}
			i->next = p;
			i->previous = NULL;
			p->previous = i;
			*first = i;
			return;
		}
	}

	old->next = i;
	i->next = NULL;
	i->previous = old;
	*last = i;
}

static void delete_element(
	address** first,
	address** last
)
{
	address* info;
	address* find();
	char s;

	if (info)
	{
		if (*first == info)
		{
			*first = info->next;
			if (*first) (*first)->previous = NULL;
			else *last = NULL;
		}
		else {
			info->previous->next = info->next;
			if (info != *last)
				info->next->previous = info->previous;
			else
				*last = info->previous;
		}

		free(info);
	}
}

address* find(char* nume)
{
	address* info;
	info = first;
	while (info)
	{
		if (!strcmp(nume, info->name)) return info;
		info = info->next;
	}
	return NULL;
}

static void list(void)
{
	address* info;
	info = first;

	while (info) {
		display(info);
		info = info->next;
	}
}

static void display(address* info)
{
	printf(info->name);
	printf(info->city);
	printf(info->city_code);
	printf(info->state);
}
