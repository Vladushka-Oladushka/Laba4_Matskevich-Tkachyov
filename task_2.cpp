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
void test(char* string, int answer)
{
	if (calculator(string) == answer)
		cout << "OK" << endl;
	else
		cout << "FAIL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}

int main()
{
	char string1[] = "34+21-11";
	test(string1, 44);
	char string2[] = "100-56+28-59+228";
	test(string2, 241);
	char string3[] = "1488-322-980+3";
	test(string3, 189);
	char string4[] = "42-67-89-76";
	test(string4, -190);
	char string5[] = "567+321-890+2015-1945";
	test(string5, 68);
	
