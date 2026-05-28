#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    char line[32];
    int sum = 0;
    int num = 0;

    while (fgets(line, sizeof line, fp)) {
        if (sscanf(line, "%d", &num) == 1) {
            sum += num;
        }
        else {
            fprintf(stderr, "invalid input: %s\n", line);
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
