#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define ARR_SIZE 10


/*Read user input and puts it in transmitted array by dividing into words
 *@param array array with user-entered words
 *@param size size of word's array
 */
void ReadAndPutWordToArray(int* array, int size);


/*Count size of each word from transmitted message and print vertical bar histogram 
 *@param array array with user-entered words
 *@param size size of word's array
 */
void PrintHorizontalBarGraf(int* array, int size);


/*Count size of each word from transmitted message and print horizintal bar histogram
 *@param array array with user-entered words
 *@param size size of word's array
 */
void PrintVerticalBarGraf(int* array, int size);


/*Count sum length all of words in transmitted array
 *@param array array with user-entered words
 *@param size size of word's array
 */
int CountSumElementsArray(int* array, int size);




int main()
{
	int array[ARR_SIZE] = {};

	printf("Write text with a maximum of ten words. If you want less words press \"Ctrl + Z\" and \"Enter\" then on a new line\n");
	ReadAndPutWordToArray(array, ARR_SIZE);
	char command[11] = {};
	printf("What kind of bar graf do you want to view?\nWrite \"horizontal\" or \"vertical\"\n");
	scanf("%s", command);

	if (!strcmp(command, "horizontal"))
	{
		PrintHorizontalBarGraf(array, ARR_SIZE);
	}
	else if (!strcmp(command, "vertical"))
	{
		PrintVerticalBarGraf(array, ARR_SIZE);
	}

}

void PrintHorizontalBarGraf(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == 0)
		{
			break;
		}
		for (int k = 0; k < array[i]; k++)
		{
			printf("%c", '*');
		}
		printf("\n");
	}
}

void PrintVerticalBarGraf(int* array, int size)
{
	int sum = CountSumElementsArray(array, size);

	for (int i = 0; i < size; i++)
	{
		if (sum == 0)
		{
			break;
		}
		else if (i == size - 1)
		{
			i = -1;
			printf("\n");
		}
		else if (array[i] != 0)
		{
			printf("*");
			array[i]--;
			sum--;
		}
		else
		{
			printf(" ");
		}
	}
}

void ReadAndPutWordToArray(int* array, int size)
{
	int previous_symbol = 0;
	int symbol = 0;
	int n_word = 0;
	while ((symbol = getchar()) != EOF && (n_word < size))
	{
		if ((symbol != ' ') && (symbol != '\n'))
		{
			array[n_word]++;
		}
		else if (((symbol == ' ') || (symbol == '\n')) &&
			((previous_symbol != ' ') && (previous_symbol != '\n')))
		{
			n_word++;
		}
		previous_symbol = symbol;
	}
}

int CountSumElementsArray(int* array, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += array[i];
	}
	return sum;
}

