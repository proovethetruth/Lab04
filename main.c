
// Ввести строку и слово. Вывести строку, удалив из него все вхождения слова.

#include <stdio.h>

int is_ch(char ch)
{
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

int match(int *str, int *word, int i)
{
	int current = 0;
	while (is_ch(str[i]))
	{
		if (str[i] != word[current])
			return -1;
		i++;
		current++;
	}
	while (!is_ch(str[i]))
		i++;
	return i;
}

int main() 
{
	int a[100], b[10];
	int i = 0, j = 0, pos = 0;

	printf("\n Input string: ");
	while ((a[i] = getchar()) != '\n')
	{
		i++;
	}
	a[i] = '\0';

	printf(" Input word: ");
	while ((b[j] = getchar()) != '\n')
	{
		j++;
	}
	b[j] = '\0';

	printf("\n -----------------------------------------------------\n Result: ");

	i = 0;

	// Если слова совпадают, функция должна вернуть целое j и записать в переменную pos

	while (a[i] != '\0')
	{
		if ((pos = match(&a, &b, i)) < i)
		{
			while (is_ch(a[i]))
			{
				printf("%c", a[i]);
				i++;
			}
			while (!is_ch(a[i]) && a[i] != '\0')
			{
				printf("%c", a[i]);
				i++;
			}
		}
		else
		{
			i = pos;
			while (!is_ch(a[i]))
			{
				printf("%c", a[i]);
				i++;
			}
		}
			
	}
	printf("\n");
}