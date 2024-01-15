/**
 * author: Mark Jerald Santiago
 *
 * description: bitmap.c does all the byte processing for main.c
 * */

#include <stdlib.h>
#include <stdio.h>
#include "bitmap.h"

/**
 * allocates memory to byte array
 * */
unsigned long long * bitmap_new(int size)
{
    return calloc(size, sizeof(int) * 8);
}

/**
 * this function does all the byte unpacking for A2
 * */
void unpackInt(unsigned long long * hexaDec, int line, int size)
{
    //loops through all the bits stored in the byte array
    int currentIndex = 0;
    int integer = 0;
    while(1)
    {
        unsigned int processedInteger = 0;

        //end loop if we don't have enough bits for an integer unpack
        if (((size * 8) - currentIndex) <= 5) break;
        int numberLength = 0;
        int counter = 0;

        //loop through the first 5 bits of the packed integer
        for (int i = currentIndex; i < currentIndex + 5; i++)
        {
            numberLength <<= 1;
            //stores the unsigned length bits into numberLength, modulo operator is lit
            numberLength |= (hexaDec[i >> 3] & (1 << ( 7 - (i % 8) ) )) != 0;
        }
        //if the numberLength is 0 then end unpack
        if (numberLength == 0) break;
        integer++; //keeps track which integer we are processing for each given line
        currentIndex += 5; //moves current index by 5 because of numberLength
        //check the sign bit
        int sign = (hexaDec[currentIndex >> 3] & (1 << ( 7 - (currentIndex % 8) ))) != 0;
        //loops through all the bits currently stored in byte array
        for (int i = currentIndex; i < currentIndex + numberLength; i++)
        {
            processedInteger <<= 1;
            //if sign bit is negative invert all the bits else print as is
            if (sign) processedInteger |= (~hexaDec[i >> 3] & (1 << ( 7 - (i % 8) ))) != 0;
            else processedInteger |= (hexaDec[i >> 3] & (1 << ( 7 - (i % 8) ))) != 0;
            //keeps track how many bits we checked
            counter++;
        }
        currentIndex += counter; //add the bits processed to the currentIndex
        printf("Line %d, integer %d: ", line + 1, integer);
        //add - to the front of negative numbers and add 1 bcs two's complement, else print as is
        if (sign) printf("-%d\n", processedInteger + 1);
        else printf("%d\n", processedInteger);
    }
}
