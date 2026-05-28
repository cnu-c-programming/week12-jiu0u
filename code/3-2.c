#include <stdio.h>

int main(int argc, const char* argv[]) {

    if (argc < 2)
        return 0;

    const char* filename = argv[1];
    char buffer[10] = { 0 }; //null문자 빼고 9글자 읽음

    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
        return 0;
    fscanf(fp, "%10s", buffer); //공백 만나면 글자수 미달이어도 종료
    //fgets(buffer, sizeof buffer, fp);
    fclose(fp);

    printf("%s\n", buffer);

    return 0;
}


