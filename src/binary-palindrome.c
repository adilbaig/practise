/*
 *  Created on: 16-Apr-2014
 *      Author: adil
 */


#include <stdio.h>      /* printf */
#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */

void byte_to_binary_adil(int x)
{
    int l = sizeof(x) * 8;
    char c[l + 1];
    c[l] = '\0';

    while(l--) {
    	c[l] = (x & 1) ? '1' : '0';
    	x >>= 1;
    }

    printf("%s\n", c);
}

int is_palindrome(int orig)
{
	int m = 0;

	// 4. Now push bit by one to right
	for(int tmp = orig; tmp > 0; tmp >>= 1) {
		// 1. Extract right most bit
		int extract = (tmp & 1);

		// 2. Push m to left by 1 bit
		m = (m << 1);

		// 3. Now add the extracted bit
		m = m | extract;

		printf("tmp = "); byte_to_binary_adil(tmp);
		printf("m   = "); byte_to_binary_adil(m);
//		m = (m << 1) | (tmp & 1);
	}

	return ((m == orig) ? 1 : 0);
}

int main(void)
{
	byte_to_binary_adil(153);
	int i = is_palindrome(153);
	printf("Is palindrome 153 ? %d\n", i);

	byte_to_binary_adil(154);
	i = is_palindrome(154);
	printf("Is palindrome 154 ? %d\n", i);

    return 0;
}
