#include <stdio.h>
#include <string.h>


int main(int argc, const char* argv[]) 
{
    if (argc < 3)
        return 0;

    FILE* fp = fopen(argv[1], "r");
    const char* target_str = argv[2];
    
    char line[128];
    while (fgets(line, sizeof line, fp)) {
        if (strstr(line, argv[2])) { //포함하면
            printf("%s", line); //출력
        }
    }

    fclose(fp);

    return 0;
}
