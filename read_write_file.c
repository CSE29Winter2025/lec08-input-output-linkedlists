#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }
    int number;
    char line[100];
    while (fgets(line, sizeof(line), input_file)) {
        number = atoi(line);
        fprintf(output_file, "%d\n", number);
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}
