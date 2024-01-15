/**
 * Name: Mark Jerald Santiago
 * B00: 918622
 * dal.ca: mark.s@dal.ca
 *
 * description: main runner file for assignment_2 takes in all input
 *              and processes it in bitmap.c
 * */

#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

int main()
{
    unsigned long long * byte;

    int length = 0;
    scanf("%d", &length);

    //loop to take input
    for (int i = 0; i < length; i++)
    {
        int size = 0;
        scanf("%d", &size);

        //allocates memory
        byte = bitmap_new(size);
        if (size == 0) continue;

        //stores bytes into byte arrayS
        for (int j = 0; j < size; j++)
        {
            unsigned int inputByte;
            scanf("%x", &inputByte);
            byte[j] = inputByte;
        }

        //unpacks bytes check bitmap.c
        unpackInt(byte, i, size);

        //free up allocated memory
        free(byte);
    }
}
