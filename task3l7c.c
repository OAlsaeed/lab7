#include <stdio.h>

int main() {
    FILE *inputFile = fopen("bitstream1.bit", "r");
    FILE *outputFile = fopen("bitstream1.hex", "w");

    if (inputFile == NULL || outputFile == NULL) {
        return 1;
    }

    int currentBit, bitCount = 0;
    unsigned char currentByte = 0;

    while ((currentBit = fgetc(inputFile)) != EOF) {
     if (currentBit == '0' || currentBit == '1') {
     if (currentBit == '1') {
       currentByte |= (1 << bitCount);
           }
       bitCount++;

       if (bitCount == 8) {
       fprintf(outputFile, "%02X\n", currentByte);
       bitCount = 0;
       currentByte = 0;
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

