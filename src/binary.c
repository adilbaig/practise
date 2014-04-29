/*
 * binary.c
 *
 *  Created on: 16-Apr-2014
 *      Author: adil
 */


#include <stdio.h>      /* printf */
#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */

const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

void byte_to_binary_adil(int x)
{
    int l = sizeof(x) * 8;
    char c[l+1];
    c[l] = '\0';

//    printf("Size : %d\n", l);

    while(l--) {
    	c[l] = (x & 1) ? '1' : '0';
    	x >>= 1;
    }

    printf("%s\n", c);
}

void palindrome_rotate(int x)
{
	int l = sizeof(x) * 8;
	char c[l+1];
	c[l] = '\0';

//	printf("Size : %d\n", l);

	int i = l;
	while(i--) {
		c[l - i - 1] = (x & 1) ? '1' : '0';
		x >>= 1;
	}

	printf("%s\n", c);
}

int is_palindrome(int orig)
{
	printf("Palindrome\n");
	int m = 0;

	for(int tmp = orig; tmp; tmp >>= 1) {
		printf("tmp = "); byte_to_binary_adil(tmp);
		printf("m   = "); byte_to_binary_adil(m);
		m = (m << 1) | (tmp & 1);
	}

	return ((m == orig) ? 1 : 0);
}

int main(void)
{
    {
        /* binary string to int */

        char *tmp;
        char *b = "0101";

        printf("%d\n", strtol(b, &tmp, 2));
    }

    {
        /* byte to binary string */

        printf("%s\n", byte_to_binary(5));
        byte_to_binary_adil(893189849);
        palindrome_rotate(893189849);

        byte_to_binary_adil(153);
        int i = is_palindrome(153);
        printf("Is palindrome 153 ? %d\n", i);

        byte_to_binary_adil(154);
        i = is_palindrome(154);
        printf("Is palindrome 154 ? %d\n", i);
    }

    return 0;
}
