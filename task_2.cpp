#include <iostream>

using namespace std;

int calculator(char *str)
{
	int size = strlen(str), sum = 0, k = 0;
	while (k < size)
	{
		int j = k;
		char *number = new char[100];
		while (isdigit(str[j]))
		{
			j++;
		}
		for (int a = 0; a < j - k; a++)
		{
			number[a] = str[k + a];
		}
		if (str[k - 1] == '-') sum -= atoi(number);
		else sum += atoi(number);
		k += j - k + 1;
		delete[] number;
	}
	return sum;
}
