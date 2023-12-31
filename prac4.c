#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 256

int my_head() {
    char arxiu[MAX_LINE_LENGTH];
    int num_lines;

    printf("Introdueix el nom de l'arxiu: ");
    scanf("%s", arxiu);

    printf("Introdueix el nombre de línies a mostrar: ");
    scanf("%d", &num_lines);

    int fd = open(arxiu, O_RDONLY);
    if (fd == -1) {
        perror("Error en obrir l'arxiu");
        return 1;
    }

    char buffer[MAX_LINE_LENGTH];
    ssize_t bytes_read;
    int lines_read = 0;

    while ((bytes_read = read(fd, buffer, MAX_LINE_LENGTH)) > 0 && lines_read < $
        for (ssize_t i = 0; i < bytes_read && lines_read < num_lines; ++i)
{
            if (buffer[i] == '\n') {
                ++lines_read;
            }
            printf("%c", buffer[i]);
        }
    }

    if (close(fd) == -1) {
        perror("Error en tancar l'arxiu");
        return 1;
    }

    return 0;
}

int my_mv() {
    char arxiu[256], dest[256];
    printf("Introdueix un arxiu: ");
    scanf("%s", arxiu);

    printf("Introdueix un nom: ");
    scanf("%s", dest);

    int source_file = open(arxiu, O_RDONLY);
    if (source_file == -1) {
        printf("Error: l'arxiu no existeix, sortint del programa.\n");
        exit(EXIT_FAILURE);
    }

    int dest_file = open(dest, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (dest_file == -1) {
        perror("Error en crear l'arxiu destí");
        close(source_file);
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    ssize_t bytesRead;

    while ((bytesRead = read(source_file, buffer, sizeof(buffer))) > 0) {
        write(dest_file, buffer, bytesRead);
    }

    if (close(source_file) == -1 || close(dest_file) == -1) {
        perror("Error en tancar els arxius");
        exit(EXIT_FAILURE);
    }

    if (unlink(arxiu) == -1) {
        perror("Error en esborrar l'arxiu d'origen");
        exit(EXIT_FAILURE);
    }

    return 0;
}
int main() {
    int opcio;
    printf("Selecciona una opció:\n");
    printf("1. my_head\n");
    printf("2. my_mv\n");
    scanf("%d", &opcio);

    switch (opcio) {
        case 1:
            my_head();
            break;
        case 2:
            my_mv();
            break;
        default:
            printf("Opció no vàlida\n");
            break;
    }

    return 0;
}
