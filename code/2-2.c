#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


typedef struct student {
    char name[64];
    int score;
} Student;


int main(int argc, const char* argv[]) 
{
    FILE* fp = fopen("student.txt", "r");
    int count = 0;
    Student student[64];

    while (count < 64) {
        fscanf(fp, "%s %d", student[count].name, &student[count].score);

        if (feof(fp))
            break;

        count++;
    }

    int max = 0;
    float avg = 0;

    int sum = 0;
    max = student[0].score;

    for (int i = 0; i < count; i++) {
        sum += student[i].score;
        if (max < student[i].score)
            max = student[i].score;
    }
    avg = (float)sum / count;

    printf("max: %d\n", max);
    printf("avg: %.2f\n", avg);
    
    fclose(fp);

    return 0;
}
