#include <stdio.h>


int main(int argc, const char* argv[]) 
{
    if (argc < 2)
        return 0;

    FILE* fp = fopen(argv[1], "r");
    
    int alphabet[26] = { 0 };
    int ch;

    // a = 97, b = 98 .. (아스키코드)
    while ((ch = fgetc(fp)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            ch += ('a' - 'A'); //대문자를 소문자로 아스키값...
        }

        if (ch >= 'a' && ch <= 'z') {
            ch -= 'a'; //a --> 0
            alphabet[ch]++;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, alphabet[i]);
    }
    

    fclose(fp);

    return 0;
}
