/*********************************************
 *  First script
 * *******************************************/
int is_in(char *s, char c)
{
    while (*s) //it shall run until the end of time, there is no end condition
    {
        if (*s == c)
            return 1;
        else
            s++;
    }

    return 0;
}

int main()
{
    char test[5] = {'A', 'B', 'C', 'D', 'E'};

    is_in(test, 'F');
}

/*********************************************
 *  2
 * *******************************************/

void sp_in_linie(const char *str);

int main(void)
{
    sp_in_linie("Acesta este un test");
}

void sp_in_linie(const char *str)
{
    while(*str)
    {
        if(*str == ' ') printf("%c",'-');
        else printf("%c",*str);
        str++;
    }
}