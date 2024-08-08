#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    size_t bufferSize = 1;
    size_t length = 0;
    char *buffer = (char *)malloc(bufferSize * sizeof(char)); // Allocation initiale
    int ch;

    if (buffer == NULL) {
        perror("Erreur d'allocation de mémoire");
        return 1;
    }
    while (read(STDIN_FILENO, &ch, 1) > 0 && ch != '\n') {
        // Augmenter le tampon si nécessaire
        if (length + 1 >= bufferSize) {
            bufferSize *= 2;
            char *newBuffer = (char *)realloc(buffer, bufferSize * sizeof(char));
            if (newBuffer == NULL) {
                free(buffer);
                perror("Erreur de réallocation de mémoire");
                return 1;
            }
            buffer = newBuffer;
        }

        // Stocker le caractère dans le tampon
        buffer[length++] = (char)ch;
    }

    // Terminer la chaîne de caractères
    buffer[length] = '\0';

    // Réduire la mémoire allouée pour n'inclure que les caractères lus
    char *finalBuffer = (char *)realloc(buffer, (length + 1) * sizeof(char));
    if (finalBuffer == NULL) {
        free(buffer);
        perror("Erreur de réallocation finale de mémoire");
        return 1;
    }
    buffer = finalBuffer;

    printf("Vous avez entré : %s\n", buffer);

    // Libération de la mémoire
    free(buffer);
    return 0;
}

