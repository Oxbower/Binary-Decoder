# Introduction
Built as part of Systems Programming Class decodes hexadecimal strings into integer format

# How to use
1. Give how many lines are to be decoded  
2. Give how many hexadecimal strings are in current line
3. Write the hexadecimal strings equal to the amount given up top

The first 5 bits of a hex string dictates how long the integer value is, when we exhaust this and there's still a bunch of hex left we again count the next 5 bits which dictates the length of another integer in the same line, if theres less than 5 bits then the remaining bits are ignored

![image](https://github.com/Oxbower/Binary-Decoder/assets/83982029/7e8813d0-71b1-429e-8274-da5e27d18b35)

i.e.  
4  
2 0x08 0x30  
4 0x12 0x28 0x6c 0x70  
8 0x43 0xdb 0x13 0x4b 0x2b 0xc6 0x14 0xe0  
9 0xfb 0xff 0xff 0xff 0xff 0xc0 0x00 0x00 0x01  

Should return  
Line 1, integer 1: 0  
Line 1, integer 2: -1  
Line 2, integer 1: 1  
Line 2, integer 2: -2  
Line 2, integer 3: 3  
Line 2, integer 4: -4  
Line 3, integer 1: 123  
Line 3, integer 2: 1234  
Line 3, integer 3: 12345678  
