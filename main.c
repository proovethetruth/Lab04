
// The idea is that if two words match each other, function match() should skip matching word,
// returning posititon of the following word

#include <stdio.h>


int is_ch(char ch)
{
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

int match(int* str, int* word, int i)
{
	int current = 0;
	while (is_ch(str[i]))
	{
		if (str[i] != word[current])
			return -1;							// doesn't match
		i++;
		current++;
	}
	while (!is_ch(str[i]) && (str[i] != '\0'))
		i++;
	return i;									// returning position of the following word
}

int main()
{
	int a[100], b[10];
	int i = 0, pos = 0;

	printf("\n Input string: ");
	while ((a[i] = getchar()) != '\n')
	{
		i++;
		if (i == 100)
		{
			printf("\n ERROR: You entered too many characters.\n");
			return -1;
		}
	}
	a[i] = '\0';
	i = 0;

	printf(" Input word: ");
	while ((b[i] = getchar()) != '\n')
	{
		i++;
		if (i == 10)
		{
			printf("\n ERROR: You entered too many characters.\n");
			return -1;
		}
		if (!is_ch(b[i-1]))
		{
			printf("\n ERROR: Input one word, using letters.\n");
			return -2;
		}
	}
	b[i] = '\0';
	i = 0;

	printf("\n -----------------------------------------------------\n Result: ");

	while (a[i] != '\0')
	{
		if ((pos = match(&a, &b, i)) < i)			// if words don't match
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
			while (!is_ch(a[i]) && a[i] != '\0')
			{
				printf("%c", a[i]);
				i++;
			}
		}

	}
	printf("\n");
}
