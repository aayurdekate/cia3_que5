#include <stdio.h>

#define MAX_LENGTH 1000

char text[MAX_LENGTH];  // Global variable to store the text

// Function to read the string from input
void readText() {
    printf("Enter the text: ");
    fgets(text, MAX_LENGTH, stdin);
}

// Function to return the character at position I of the string
char charAt(int i) {
    if (i >= 0 && i < MAX_LENGTH) {
        return text[i];
    }
    return '\0';  // Return null character if index is out of bounds
}

// Function to calculate the length of the string
int length() {
    int len = 0;
    while (text[len] != '\0') {
        len++;
    }
    return len - 1;  // Subtract 1 to ignore the newline character from fgets
}

// Function to count the number of white spaces in the string
int noOfWhiteSpace() {
    int count = 0;
    for (int i = 0; i < length(); i++) {
        if (text[i] == ' ' || text[i] == '\t') {
            count++;
        }
    }
    return count;
}

// Function to count the number of words in the string
int noOfWords() {
    int count = 0;
    int inWord = 0;

    for (int i = 0; i < length(); i++) {
        if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n') {
            if (!inWord) {
                inWord = 1;
                count++;
            }
        } else {
            inWord = 0;
        }
    }
    return count;
}

int main() {
    readText();

    printf("Length of the text: %d\n", length());
    printf("Character at position 5: %c\n", charAt(5));
    printf("Number of white spaces: %d\n", noOfWhiteSpace());
    printf("Number of words: %d\n", noOfWords());

    return 0;
}
