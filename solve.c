#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *inputF = fopen("input_2.txt", "r");
    FILE *keyF = fopen("key.txt", "r");

    if (inputF == NULL) {
        printf("Unable to read file!\n");
        exit(0);
    }
    if (keyF == NULL) {
        printf("Unable to read \'key.txt\'\n");
        exit(0);
    }

    char alphaKey[26];
    char alpha;
    int index = 0;
    while (fscanf(keyF, "%c", &alpha) != EOF) {
        if (alpha != '\n') {
            alphaKey[index] = alpha;
            // printf("%c", alpha);
            index++;
        }
    }

    int num;
    while (fscanf(inputF, "%d", &num) != EOF) {
        // printf("%d\n", num);
        if (num < 27) {
            printf("%c", alphaKey[num - 1]);
        }
        else {
            printf("%c", num);
        }
    }
    printf("\n");

    fclose(inputF);
    fclose(keyF);

    return 0;
}