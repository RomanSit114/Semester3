#include <string.h>
int srtConteins(char* a, char* str)
{
	int v = strlen(str) - strlen(a);
	int z = 0;
	while (z != v + 1)
	{
	for (int i = 0; i < strlen(a); i++)
	{
	if (a[i] != str[z + i]) {
		break;}
	else
			{
	if (i == strlen(a) - 1) {
		return z;
	}
		}
	}
	z++;
	}
	return -1;
}