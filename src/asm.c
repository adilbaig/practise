/*
 * asm.c
 *
 * Created on: 27-Jan-2015
 *      Author: adil
 *
 * COMPILE WITH `gcc -S asm.c`
 *
 * After that, try `gcc -O -c -g -Wa,-ahl=asm.s asm.c`. Check the asm.o file with objdump
 *
 */

#include <stdio.h>

main()
{
  puts("Hello World.");
  return(0);
}
