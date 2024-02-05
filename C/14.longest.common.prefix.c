#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    // Check for empty input
    if (strs == NULL || strsSize == 0) {
        char* result = (char*)malloc(1);
        result[0] = '\0';
        return result;
    }

    // Sort the array of strings
    qsort(strs, strsSize, sizeof(char*), compareStrings);

    // Take the first and last strings after sorting
    char* first = strs[0];
    char* last = strs[strsSize - 1];

    // Find the common prefix between the first and last strings
    int minLength = strlen(first) < strlen(last) ? strlen(first) : strlen(last);
    int commonPrefixLength = 0;

    for (int i = 0; i < minLength; i++) {
        if (first[i] == last[i]) {
            commonPrefixLength++;
        } else {
            break;
        }
    }

    // Allocate memory for the result
    char* result = (char*)malloc(commonPrefixLength + 1);

    // Copy the common prefix to the result
    strncpy(result, first, commonPrefixLength);
    result[commonPrefixLength] = '\0';

    return result;
}

// Helper function to compare strings for qsort
int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    char* strs[] = {"flower", "flow", "flight"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);

    char* result = longestCommonPrefix(strs, strsSize);

    printf("Longest Common Prefix: %s\n", result);

    // Don't forget to free the allocated memory
    free(result);

    return 0;
}