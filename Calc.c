#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numErrorCheck(char * number, char type);
int dAsciiToInt(char * number);
int oAsciiToInt(char * number);
int bAsciiToInt(char * number);
int xAsciiToInt(char * number);
char * dToDecimalAscii(int number, char * result);
char * dToHexadecimalAscii(int number, char * result);
char * dToOctalAscii(int number, char * result);
char * dToBinaryAscii(int number, char * result);

int main(int argc, char ** argv) {
    int errorExists = 0;
    char errors[1500];
    strcpy(errors, "ERROR:\n");

    if(argc < 5) {
        errorExists = 1;
        printf("ERROR:\nThe number of arguments supplied is lower than expected.\n");
        exit(EXIT_SUCCESS);
    } else if (argc > 5) {
        errorExists = 1;
        printf("ERROR:\nThe number of arguments supplied is more than expected.\n");
        exit(EXIT_SUCCESS);
    }

    // error checking for first argument
    char * arg1 = argv[1];
    if(strlen(arg1) != 1) {
        errorExists = 1;
        strcat(errors, "The format is wrong for the input operand.\n");
    } else {
        if(arg1[0] != '+' && arg1[0] != '-' && arg1[0] != '*') {
            errorExists = 1;
            strcat(errors, "The operand is different from '+'/'-'/'*'.\n");
        }
    }

    // error checking for second argument
    char tempType1;
    char tempNum1[40];
    char * arg2 = argv[2];
    if(arg2[0] != '-' && arg2[0] != 'd' && arg2[0] != 'o' && arg2[0] != 'b' && arg2[0] != 'x'
    && arg2[0] != 'D' && arg2[0] != 'O' && arg2[0] != 'B' && arg2[0] != 'X') {
        errorExists = 1;
        strcat(errors, "The format is wrong for the first number.\n");
    } else {
        if(arg2[0] == '-') {
            if(arg2[1] != 'b' && arg2[1] != 'o' && arg2[1] != 'd' && arg2[1] != 'x'
            && arg2[1] != 'D' && arg2[1] != 'O' && arg2[1] != 'B' && arg2[1] != 'X') {
                errorExists = 1;
                strcat(errors, "You did not provide base indicator for first number.\n");
            } else {
                tempType1 = arg2[1];
                memcpy(tempNum1, &arg2[2], strlen(arg2)-1);

                if(numErrorCheck(tempNum1, tempType1) == 1)  {
                    errorExists = 1;
                    strcat(errors, "The first number does not match the base indicator you declared.\n");
                }
            }
        } else {
            tempType1 = arg2[0];
            memcpy(tempNum1, &arg2[1], strlen(arg2));
            if(numErrorCheck(tempNum1, tempType1) == 1)  {
                errorExists = 1;
                strcat(errors, "The first number does not match the base indicator you declared.\n");
            }
        }
    }

    // error checking for third argument
    char tempType2;
    char tempNum2[40];
    char * arg3 = argv[3];
    if(arg3[0] != '-' && arg3[0] != 'd' && arg3[0] != 'o' && arg3[0] != 'b' && arg3[0] != 'x'
    && arg3[0] != 'D' && arg3[0] != 'O' && arg3[0] != 'B' && arg3[0] != 'X') {
        errorExists = 1;
        strcat(errors, "The format is wrong for the second number.\n");
    } else {
        if(arg3[0] == '-') {
            if(arg3[1] != 'b' && arg3[1] != 'o' && arg3[1] != 'd' && arg3[1] != 'x'
            && arg3[1] != 'D' && arg3[1] != 'O' && arg3[1] != 'B' && arg3[1] != 'X') {
                errorExists = 1;
                strcat(errors, "You did not provide base indicator for second number.\n");
            } else {
                tempType2 = arg3[1];
                memcpy(tempNum2, &arg3[2], strlen(arg3)-1);

                if(numErrorCheck(tempNum2, tempType2) == 1)  {
                    errorExists = 1;
                    strcat(errors, "The second number does not match the base indicator you declared.\n");
                }
            }
        } else {
            tempType2 = arg3[0];
            memcpy(tempNum2, &arg3[1], strlen(arg3));
            if(numErrorCheck(tempNum2, tempType2) == 1)  {
                errorExists = 1;
                strcat(errors, "The second number does not match the base indicator you declared.\n");
            }
        }
    }

    // error checking for fourth argument
    char * arg4 = argv[4];
    if(strlen(arg4) != 1) {
        errorExists = 1;
        strcat(errors, "The format is wrong for the output base type.\n");
    } else {
        if(arg4[0] != 'd' && arg4[0] != 'o' && arg4[0] != 'b' && arg4[0] != 'x') {
            errorExists = 1;
            strcat(errors, "The output base type is different from 'd'/'o'/'b'/'x'.\n");
        }

    }

    if(errorExists == 1) {
        printf("%s", errors);
    } else {
        // GET ARGUMENT 1 - THE OPERAND TYPE
        char * argument1 = argv[1];
        int operand;
        if(argument1[0] == '-') {
            operand = 0;
        } else if (argument1[0] == '+') {
            operand = 1;
        } else if (argument1[0] == '*') {
            operand = 2;
        }
        // GET ARGUMENT 2 - THE FIRST NUMBER
        char * argument2 = argv[2];
        int num1Negative = 0;
        if(argument2[0] == '-') {
            num1Negative = 1;
        }
        char number1[40];
        char type1;
        if(num1Negative == 1) {
            if(argument2[1] == 'b' || argument2[1] == 'B') {
                type1 = 'b';
            } else if (argument2[1] == 'o' || argument2[1] == 'O') {
                type1 = 'o';
            } else if (argument2[1] == 'd' || argument2[1] == 'D') {
                type1 = 'd';
            } else if (argument2[1] == 'x' || argument2[1] == 'X') {
                type1 = 'x';
            } else {
                errorExists = 1;
            }
            memcpy(number1, &argument2[2], strlen(argument2)-1);
        } else {
            if(argument2[0] == 'b' || argument2[0] == 'B') {
                type1 = 'b';
            } else if (argument2[0] == 'o' || argument2[0] == 'O') {
                type1 = 'o';
            } else if (argument2[0] == 'd' || argument2[0] == 'D') {
                type1 = 'd';
            } else if (argument2[0] == 'x' || argument2[0] == 'X') {
                type1 = 'x';
            } else {
                errorExists = 1;
            }
            memcpy(number1, &argument2[1], strlen(argument2));
        }

        // GET ARGUMENT 3 - THE SECOND NUMBER
        char * argument3 = argv[3];
        int num2Negative = 0;
        if(argument3[0] == '-') {
            num2Negative = 1;
        }
        char number2[40];
        char type2;
        if(num2Negative == 1) {
            if(argument3[1] == 'b' || argument3[1] == 'B') {
                type2 = 'b';
            } else if (argument3[1] == 'o' || argument3[1] == 'O') {
                type2 = 'o';
            } else if (argument3[1] == 'd' || argument3[1] == 'D') {
                type2 = 'd';
            } else if (argument3[1] == 'x' || argument3[1] == 'X') {
                type2 = 'x';
            } else {
                errorExists = 1;
            }
            memcpy(number2, &argument3[2], strlen(argument3)-1);
        } else {
            if(argument3[0] == 'b' || argument3[0] == 'B') {
                type2 = 'b';
            } else if (argument3[0] == 'o' || argument3[0] == 'O') {
                type2 = 'o';
            } else if (argument3[0] == 'd' || argument3[0] == 'D') {
                type2 = 'd';
            } else if (argument3[0] == 'x' || argument3[0] == 'X') {
                type2 = 'x';
            } else {
                errorExists = 1;
            }
            memcpy(number2, &argument3[1], strlen(argument3));
        }

        // GET ARGUMENT 4 - OUTPUT BASE TYPE
        char * argument4 = argv[4];
        char type3;
        if(argument4[0] == 'b' || argument4[0] == 'B') {
            type3 = 'b';
        } else if (argument4[0] == 'o' || argument4[0] == 'O') {
            type3 = 'o';
        } else if (argument4[0] == 'd' || argument4[0] == 'D') {
            type3 = 'd';
        } else if (argument4[0] == 'x' || argument4[0] == 'X') {
            type3 = 'x';
        } else {
            errorExists = 1;
        }

        int num1Decimal;
        if(type1 == 'b') {
            num1Decimal = bAsciiToInt(number1);
        } else if (type1 == 'o') {
            num1Decimal = oAsciiToInt(number1);
        } else if (type1 == 'd') {
            num1Decimal = dAsciiToInt(number1);
        } else if (type1 == 'x') {
            num1Decimal = xAsciiToInt(number1);
        }
        if(num1Negative == 1) {
            num1Decimal = num1Decimal * (-1);
        }

        int num2Decimal;
        if(type2 == 'b') {
            num2Decimal = bAsciiToInt(number2);
        } else if (type2 == 'o') {
            num2Decimal = oAsciiToInt(number2);
        } else if (type2 == 'd') {
            num2Decimal = dAsciiToInt(number2);
        } else if (type2 == 'x') {
            num2Decimal = xAsciiToInt(number2);
        }
        if(num2Negative == 1) {
            num2Decimal = num2Decimal * (-1);
        }

        int result;
        if(operand == 0) {
            result = num1Decimal - num2Decimal;
        } else if (operand == 1) {
            result = num1Decimal + num2Decimal;
        } else if (operand == 2) {
            result = num1Decimal * num2Decimal;
        }

        char output[40];
        if(type3 == 'b') {
            dToBinaryAscii(result, output);
        } else if (type3 == 'o') {
            dToOctalAscii(result, output);
        } else if (type3 == 'd') {
            dToDecimalAscii(result, output);
        } else if (type3 == 'x') {
            dToHexadecimalAscii(result, output);
        }

        printf("%s\n", output);

    }
    return 0;
}

int numErrorCheck(char * number, char type) {
    int i;
    if(type == 'b') {
        for(i = 0; i < strlen(number); i++) {
            if(number[i] != '0' && number[i] != '1') {
                return 1;
            }
        }
        return 0;
    } else if (type == 'o') {
        for(i = 0; i < strlen(number); i++) {
            if(number[i] != '0' && number[i] != '1' && number[i] != '2' && number[i] != '3' && number[i] != '4' &&
            number[i] != '5' && number[i] != '6' && number[i] != '7') {
                return 1;
            }
        }
        return 0;
    } else if (type == 'd') {
        for(i = 0; i < strlen(number); i++) {
            if(number[i] != '0' && number[i] != '1' && number[i] != '2' && number[i] != '3' && number[i] != '4' &&
            number[i] != '5' && number[i] != '6' && number[i] != '7' && number[i] != '8' && number[i] != '9') {

                return 1;
            }
        }
        return 0;
    } else if (type == 'x') {
        for(i = 0; i < strlen(number); i++) {
            if(number[i] != '0' && number[i] != '1' && number[i] != '2' && number[i] != '3' && number[i] != '4' &&
            number[i] != '5' && number[i] != '6' && number[i] != '7' && number[i] != '8' && number[i] != '9' &&
            number[i] != 'A' && number[i] != 'B' && number[i] != 'C' && number[i] != 'D' && number[i] != 'E' && number[i] != 'F' &&
            number[i] != 'a' && number[i] != 'b' && number[i] != 'c' && number[i] != 'd' && number[i] != 'e' && number[i] != 'f') {
                return 1;
            }
        }
        return 0;
    }
    return -1;
}


int dAsciiToInt(char * number) {
    int value, start;
    value = 0;
    for(start = 0; start < strlen(number); start++) {
        value = (value*10) + number[start] -'0';
    }
    return value;
}

int oAsciiToInt(char * number) {
    int length = strlen(number);
    length--;
    int counter = 0;
    int counter2 = 0;
    int value = 0;
    int pow;
    while(counter2 <= length) {
        pow = 8 * counter;
        if(pow == 0) {
            pow = 1;
        }
        value = value + (pow * (number[length-counter2]-'0'));

        if (counter == 0) {
            counter = 1;
        } else {
            counter *= 8;
        }
        counter2++;
    }
    return value;
}

int bAsciiToInt(char * number) {
    int value, start;

    value = 0;
    for(start = 0; start < 32; start++) {
        switch (number[start]) {
            case '0': value = (value << 1); break;
            case '1': value = (value << 1) + 1; break;
        }
    }
    return value;
}

int xAsciiToInt(char * number) {
    int value, start;
    value = 0;

    for(start = 0; start < 32; start++) {
        switch(number[start]) {
            case '0': value = (value << 4); break;
            case '1': value = (value << 4) + 1; break;
            case '2': value = (value << 4) + 2; break;
            case '3': value = (value << 4) + 3; break;
            case '4': value = (value << 4) + 4; break;
            case '5': value = (value << 4) + 5; break;
            case '6': value = (value << 4) + 6; break;
            case '7': value = (value << 4) + 7; break;
            case '8': value = (value << 4) + 8; break;
            case '9': value = (value << 4) + 9; break;
            case 'A': value = (value << 4) + 10; break;
            case 'B': value = (value << 4) + 11; break;
            case 'C': value = (value << 4) + 12; break;
            case 'D': value = (value << 4) + 13; break;
            case 'E': value = (value << 4) + 14; break;
            case 'F': value = (value << 4) + 15; break;
            case 'a': value = (value << 4) + 10; break;
            case 'b': value = (value << 4) + 11; break;
            case 'c': value = (value << 4) + 12; break;
            case 'd': value = (value << 4) + 13; break;
            case 'e': value = (value << 4) + 14; break;
            case 'f': value = (value << 4) + 15; break;

        }
    }
    return value;
}


// DELETE THIS:
/*
char out[200];
anotherpointer = dToDecimalAscii(number, out); // out is modified
// pointer to out

print out: Hello
*/

char * dToDecimalAscii(int number, char * result) {
    int isMinus = 0;
    if(number < 0) {
        isMinus = 1;
        number = number * (-1);
    }
    result[0] = '\0';
    if(number == 0) {
      strcat(result, "0");
    }
    while(number != 0) {
        char c = (number % 10) + '0';
        char tempStr[2];
        tempStr[0] = c;
        tempStr[1] = '\0';
        strcat(result, tempStr);

        number /= 10;
    }
    if(isMinus == 1) {
        strcat(result, "d-");
    } else {
        strcat(result, "d");
    }

    int i;
    char temp;
    for(i = 0; i < strlen(result)/2; i++) {
        temp = result[i];
        result[i] = result[strlen(result)-1-i];
        result[strlen(result)-1-i] = temp;
    }
    return result;

}

char * dToHexadecimalAscii(int number, char * result) {
    int isMinus = 0;
    if(number < 0) {
        isMinus = 1;
        number = number * (-1);
    }

    result[0] = '\0';
    if(number == 0) {
      strcat(result, "0");
    }
    while(number != 0) {
        char c;
        if(number%16 > 9 ) {
          switch (number%16) {
            case (10): c = 'A'; break;
            case (11): c = 'B'; break;
            case (12): c = 'C'; break;
            case (13): c = 'D'; break;
            case (14): c = 'E'; break;
            case (15): c = 'F'; break;
          }
        } else {
          c = (number % 16) + '0';
        }
          char tempStr[2];
          tempStr[0] = c;
          tempStr[1] = '\0';
          strcat(result, tempStr);
          number /= 16;
    }
    if(isMinus == 1) {
        strcat(result, "x-");
    } else {
        strcat(result, "x");
    }
    int i;
    char temp;
    for(i = 0; i < strlen(result)/2; i++) {
        temp = result[i];
        result[i] = result[strlen(result)-1-i];
        result[strlen(result)-1-i] = temp;
    }
    return result;
    /*
    int i, n;
    char * hexchar = "0123456789ABCDEF";
    char tempChar[2];
    result[0] = '\0';
    for(i = 0; i < 8; i++) {
        n = number >> 28;
        tempChar[0] = hexchar[n];
        tempChar[1] = '\0';
        strcat(result, tempChar);
        number = number << 4;
    }
    char tempStr[3];
    if(isMinus == 1) {
        strcpy(tempStr, "-h");
        strcat(tempStr, result);
        result = tempStr;
    } else {
        strcpy(tempStr, "h");
        strcat(tempStr, result);
        result = tempStr;
    }
    return result;
    */
}

char * dToOctalAscii(int number, char * result) {
    int isMinus = 0;
    if(number < 0) {
        isMinus = 1;
        number = number * (-1);
    }
    result[0] = '\0';
    if(number == 0) {
      strcat(result, "0");
    }
    while(number != 0) {
        char c = (number % 8) + '0';
        char tempStr[2];
        tempStr[0] = c;
        tempStr[1] = '\0';
        strcat(result, tempStr);
        number /= 8;
    }
    if(isMinus == 1) {
        strcat(result, "o-");
    } else {
        strcat(result, "o");
    }
    int i;
    char temp;
    for(i = 0; i < strlen(result)/2; i++) {
        temp = result[i];
        result[i] = result[strlen(result)-1-i];
        result[strlen(result)-1-i] = temp;
    }
    return result;
}

char * dToBinaryAscii(int number, char * result) {
    int isMinus = 0;
    if(number < 0) {
        isMinus = 1;
        number = number * (-1);
    }

    result[0] = '\0';
    if(number == 0) {
      strcat(result, "0");
    }
    while(number != 0) {
        char c = (number % 2) + '0';
        char tempStr[2];
        tempStr[0] = c;
        tempStr[1] = '\0';
        strcat(result, tempStr);
        number /= 2;
    }
    if(isMinus == 1) {
        strcat(result, "b-");
    } else {
        strcat(result, "b");
    }
    int i;
    char temp;
    for(i = 0; i < strlen(result)/2; i++) {
        temp = result[i];
        result[i] = result[strlen(result)-1-i];
        result[strlen(result)-1-i] = temp;
    }
    return result;

    /*
    int i, n;
    char tempChar[2];
    result[0] = '\0';
    for(i = 0; i < 32; i++) {
        n = number >> 31;
        tempChar[0] = '0' + n;
        tempChar[1] = '\0';
        strcat(result, tempChar);
        number = number << 1;
    }

    char tempStr[3];
    if(isMinus == 1) {
      strcpy(tempStr, "-b");
      strcat(tempStr, result);
      result = tempStr;
    } else {
        strcpy(tempStr, "b");
        strcat(tempStr, result);
        result = tempStr;
    }
    return result;
    */

}
