#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXCHAR 256

void preprocessPattern(char *pattern, int patternLength, int *shiftTable) {
    for (int i = 0; i < MAXCHAR; i++) {
        shiftTable[i] = patternLength;
    }
    for (int i = 0; i < patternLength - 1; i++) {
        shiftTable[(int)pattern[i]] = patternLength - 1 - i;
    }
}

void horspool(char *text, int textLength, char *pattern, int patternLength) {
    int shiftTable[MAXCHAR];
    preprocessPattern(pattern, patternLength, shiftTable);

    int i = patternLength - 1;
    while (i < textLength) {
        int j = 0;
        while (j < patternLength && pattern[patternLength - 1 - j] == text[i - j]) {
            j++;
        }
        if (j == patternLength) {
            printf("Pattern found at index %d\n", i - patternLength + 1);
        }
        i += shiftTable[(int)text[i]];
    }
}

int main() {
    char text[] = "ACGTAGCATCAGTAUCGATCACTACGU";
    char pattern[] = "ACGU";
    
    clock_t start, end;
    
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    
    start = clock();
    horspool(text, textLength, pattern, patternLength);
    end = clock();
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to find pattern: %f seconds\n", time_taken);
    
    return 0;
}