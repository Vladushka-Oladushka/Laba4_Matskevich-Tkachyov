#include <iostream>
using namespace std;

char newString[100];
char* myString(char* origString)
{
	newString[0] = '\0';
	for (int i = 0; i < strlen(origString); i++)
	{
		if ((int)origString[i] < 58 && (int)origString[i]>47)
		{
			char number[30];
			number[0] = '\0';
			while ((int)origString[i] < 58 && (int)origString[i]>47)
			{
				char symb[2] = { origString[i],'\0' };
				strcat_s(number, symb);
				i++;
			}
			i--;
			int num = atoi(number);
			char inverted16xnumber[30];
			inverted16xnumber[0] = '\0';
			while (num >= 16)
			{
				if (num % 16 < 10)
				{
					char symb[2] = { char(num % 16 + 48), '\0' };
					strcat_s(inverted16xnumber, symb);
				}
				else
				{
					char symb[2] = { char(num % 16 + 55), '\0' };
					strcat_s(inverted16xnumber, symb);
				}
				num /= 16;
			}
			if (num < 10)
			{
				char symb[2] = { char(num + 48), '\0' };
				strcat_s(inverted16xnumber, symb);
			}
			else
			{
				char symb[2] = { char(num + 55), '\0' };
				strcat_s(inverted16xnumber, symb);
			}
			char right16xnumber[100];
			int ix;
			for (ix = 0; ix < strlen(inverted16xnumber); ix++)
				right16xnumber[ix] = inverted16xnumber[strlen(inverted16xnumber) - 1 - ix];
			right16xnumber[ix] = '\0';
			char startstring[3] = { '0','x','\0' };
			strcat_s(newString, startstring);
			strcat_s(newString, right16xnumber);
		}
		else
		{
			char symb[2] = { origString[i],'\0' };
			strcat_s(newString, symb);
		}
	}
	return newString;
}

int main()
{
	return 0;
}