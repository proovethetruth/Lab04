
// Ввести строку и слово. Вывести строку, удалив из него все вхождения слова.

#include <stdio.h>

int is_ch(char ch)
{
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

int main() {

	int a[100], b[10];
	int i = 0, j = 0, length = 0;

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

	// "never gonna give you up\0"
	// "gonna\0"

	for (i = 0, j = 0; a[i] != '\0'; i++)
	{
		if (b[j] != '\0')
		{
			if (a[i] == b[j])
				j++;
			else
			{
				while (is_ch(a[i]))
				{
					i++;
				}
				j = 0;
			}
		}
		else
		{
			printf("\n MATCH!\n");
			break;
		}

	}
}