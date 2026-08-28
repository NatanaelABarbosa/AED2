#include <stdio.h>
#include <string.h>

int main () {
    char s1 [10000] = "";
    char s2 [10000] = "";
    
    scanf("%[^\n]", s1); getchar();
    while (strcmp(s1, "FIM") != 0) {
        int len = strlen(s1);
        for (int i = 0; i < len; i++) {
            s2[i] = s1[len-i-1];
        }
        s2[len] = '\0';

        if (strcmp(s1, s2) == 0) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        
        scanf("%[^\n]", s1); getchar();
    }

    return 0;
}
