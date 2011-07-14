#include<stdio.h>
#include<string.h>


void reverse(char s []);
void itoa(int num, char s []);
void itob(int num, char s [], int base);

int main()
{
	int n = 912378;
	char s [100];
	itob(n,s,16);
	printf("%s\n",s);

}

void itob(int num, char s [], int base)
{

	const char letters [] = "0123456789ABCDEFHIJKL";
	//if it's negative, make it positive
	int sign = num;
	int i = 0;
	if (sign < 0)
		num = -num;
	do
	{
		s[i++] = letters[num % base];
	} while ( (num = num /10) > 0);

	//add the sign to the end and reverse
	if (sign < 0)
		s[i] = '-';
	reverse(s);

}




void itoa(int num, char s [])
{
	//if it's negative, make it positive
	int sign = num;
	int i = 0;
	if (sign < 0)
		num = -num;
	do
	{
		s[i++] = (num % 10) + '0';
	} while ( (num = num /10) > 0);

	//add the sign to the end and reverse
	if (sign < 0)
		s[i] = '-';
	reverse(s);

}



void reverse(char s []) {
    int c, i, j;
    for ( i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
		s[i] = s[j];
		s[j] = c;
    }
}


