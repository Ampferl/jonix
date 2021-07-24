#include <string.h>

void itoa(unsigned int n, char *s, unsigned int base)
{
	char st[33];
	unsigned int i = 0;
	
	do
	{
		unsigned int t = n % base;
		if (t < 10)st[i++] = t + '0';
		else st[i++] = (t - 10) + 'A';
	} while((n /= base) > 0);
	st[i] = '\0';
	
	unsigned int y = 0;
	for (;i > 0;i--)
	{
		s[y] = st[i-1];
		y++;
	}
	s[y] = '\0';
}
