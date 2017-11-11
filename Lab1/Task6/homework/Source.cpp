#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int countSubString(char* s, char* s1)
{
	int count = 0;
	int index = 0;
	int len2 = 0;
	int index2;
	bool flag;

	while (s1[len2] != '\0')
		len2++;

	while (s[index] != '\0')
	{
		if (s[index] != s1[0])
			index++;
		else
		{
			index2 = 0;
			flag = true;
			while (s[index + index2] != '\0' && s1[index2] != '\0')
			{
				flag &= s[index + index2] == s1[index2];
				index2++;
			}
			if (flag && index2 == len2)
			{
				++count;
				index += len2;
			}
			else
			{
				++index;
			}
		}
	}
	return count;
}

int main()
{
	char s[100];
	char s1[100];
	gets_s(s);
	gets_s(s1);

	printf("count subs = %d\n", countSubString(s, s1));

	system("PAUSE");
	return 0;
}