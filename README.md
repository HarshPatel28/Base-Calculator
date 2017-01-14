# Base-Calculator

## What is Base Calculator? ##
  This program is a calculator that can take in two inputs of different bases and do addition, subtraction, and multiplication with them and then output the result in any base. The different bases acceptable include binary(base 2), octal(base 8), decimal(base 10), and hexadecimal(base 16). The two inputs do not necessarily have to be in the same base and the output result can also be an entirely different base than the inputs. This program will handle the calculations regardless of what base the inputs are in and only give the result in whatever base the user desires.

## How to Use ##
  To use the program, enter the inputs in the following format: (op) (b/o/d/x number1) (b/o/d/x number2) (output base) . For (op), write the sign of the arithmetic operation you want to perform, such as "+", "-" or "\\\*". Make sure to write "\\\*" for multiplication. For the (b/o/d/x number1) and (b/o/d/x number2) inputs, the "b/o/d/x" stand for what base the input is in, such as "b"inary,"o"tal,"d"ecimal, and he"x"adecimal. Unlike in the examples, make sure there isn't a space between the base type and the actual number itself, and the form should be b/o/d/xNUMBER. If you want to make the number negative, add the "-" sign before the base type, such as -b/o/d/xNUMBER. Finally, for (output base), just write the base type you want the result in, from "b/o/d/x". The output will be in the output base type specified, and will have the output base type before the actual number. Some examples:
  
### Examples ###
  1. $ ./calc + b1101 b1 d    (Addition of binary number 1101 and binarry number 1, give result in decimal form)                        
     d14                      (Result is decimal-14)
  2. $ ./calc - d587 x22 b    (Subtraction of decimal number 587 and hexadecimal number 22, give result in binary form)                 
     b1000101001              (Result is binary-1000101001)
  3. $ ./calc \* d10 d10 x    (Multiplication of decimal number 10 and decimal number 10, give result in hexadecimal form)              
    x64                       (Result is hexadecimal-64)
  4. $ ./calc + -d80 d88 o    (Addition of decimal number -80 and decimal number 88, give result in octal form)                         
    o10                       (Result is octal-10)

## Why Base Calculator ##
  This program was a great practice for getting used to C and how everything works, such as reading in an input, how pointers work, how and when to access a memory location, get accustomed to different bases(especially binary and hexadecimal, which are heavily used in several aspects of C), and how bit shifting works. 
  
## Problems/Struggles ##
  Since C does not have a string type, working with strings was done through pointers. Reading in the single input and breaking it into four different things required the use of string.h functions. No special function was used in order to convert a number from one base type to another, and every conversion was done by my own functions. I also wrote my own functions in order to convert the string number into integer form and vice versa. Creating the result was another problem, as unlike in Java, I couldn't just declare a blank string and write the result into it. I had to allocate memory for a char array, and use functions such as memcpy and strcat in order to create the result. Ultimately, I also included extensive error checking to see if the inputs were in the correct format or not and tell the user the cause of an error if there is one.
