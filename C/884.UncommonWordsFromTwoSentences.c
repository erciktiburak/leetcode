#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    // Create a hashmap to store word frequencies
    int capacity = 16;
    char** words = malloc(capacity * sizeof(char*));
    int* freq = malloc(capacity * sizeof(int));
    int count = 0;

    // Helper function to check if a word is in the hashmap
    int contains(char* word) {
        for (int i = 0; i < count; i++) {
            if (strcmp(words[i], word) == 0) {
                return i;
            }
        }
        return -1;
    }

    // Tokenize s1
    char* token = strtok(s1, " ");
    while (token != NULL) {
        int index = contains(token);
        if (index == -1) {
            // Word is not in the hashmap
            if (count == capacity) {
                // Resize the arrays if needed
                capacity *= 2;
                words = realloc(words, capacity * sizeof(char*));
                freq = realloc(freq, capacity * sizeof(int));
            }
            words[count] = strdup(token);
            freq[count] = 1;
            count++;
        } else {
            // Word is already in the hashmap
            freq[index]++;
        }
        token = strtok(NULL, " ");
    }

    // Tokenize s2
    token = strtok(s2, " ");
    while (token != NULL) {
        int index = contains(token);
        if (index == -1) {
            // Word is not in the hashmap
            if (count == capacity) {
                // Resize the arrays if needed
                capacity *= 2;
                words = realloc(words, capacity * sizeof(char*));
                freq = realloc(freq, capacity * sizeof(int));
            }
            words[count] = strdup(token);
            freq[count] = 1;
            count++;
        } else {
            // Word is already in the hashmap
            freq[index]++;
        }
        token = strtok(NULL, " ");
    }

    // Collect uncommon words
    char** result = malloc(count * sizeof(char*));
    *returnSize = 0;
    for (int i = 0; i < count; i++) {
        if (freq[i] == 1) {
            result[*returnSize] = strdup(words[i]);
            (*returnSize)++;
        }
    }

    // Free memory
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);
    free(freq);

    return result;
}

int main() {
    char s1[] = "this apple is sweet";
    char s2[] = "this apple is sour";
    int returnSize;
    char** result = uncommonFromSentences(s1, s2, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    char s3[] = "apple apple";
    char s4[] = "banana";
    result = uncommonFromSentences(s3, s4, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    return 0;
}
