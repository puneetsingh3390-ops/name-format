#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void formatName(char *name) {
    char *words[10];  // Array to store pointers to words
    int wordCount = 0;
    char temp[100];
    
    // Copy the input string to temp to avoid modifying original
    strcpy(temp, name);
    
    // Tokenize the string by spaces
    char *token = strtok(temp, " ");
    while (token != NULL && wordCount < 10) {
        words[wordCount] = (char *)malloc(strlen(token) + 1);
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, " ");
    }
    
    // Print formatted name
    // Print first letters of all words except the last one
    for (int i = 0; i < wordCount - 1; i++) {
        printf("%c. ", toupper(words[i][0]));
    }
    
    // Print the last word as it is
    if (wordCount > 0) {
        printf("%s", words[wordCount - 1]);
    }
    printf("\n");
    
    // Free allocated memory
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
}

int main() {
    char name[100];
    
    printf("Enter a person's name: ");
    fgets(name, sizeof(name), stdin);
    
    // Remove trailing newline if present
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }
    
    printf("Formatted name: ");
    formatName(name);
    
    return 0;
}
