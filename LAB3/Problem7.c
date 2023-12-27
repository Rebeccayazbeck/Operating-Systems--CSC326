#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[50];
    printf("Enter a string less than 50 characters:\n");
    scanf("%s", text);

    int N;
    printf("Please enter a key size between 1 and 19:\n");
    scanf("%d", &N);

    if (N <= 0 || N >= 20) {
        printf("Invalid key size. Please enter a key size between 1 and 19.\n");
        return 1;
    }

    int key[N];
    printf("Enter %d integers for the key:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &key[i]);
    }

    char cipher[50];
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++) {
        char originalChar = text[i];

        
        if (originalChar >= 'a' && originalChar <= 'z') {
            int shift = key[i % N];

           
            char encryptedChar = originalChar + shift;

            
            if (encryptedChar > 'z') {
                encryptedChar = encryptedChar - 'z' + 'a' - 1;
            }

            cipher[i] = encryptedChar;
        } else {
            
            cipher[i] = originalChar;
        }
    }

    printf("Cipher text: %s\n", cipher);

    return 0;
}
