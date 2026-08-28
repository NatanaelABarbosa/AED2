#include <stdio.h>
#include <string.h>

void intercalar (char * str1, char * str2, char * strf) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = 0;
    int j = 0;
    int k = 0;

    if (len1 < len2) {
        for(i = 0; i < len1*2; i++) {
            if (i % 2 == 0) { strf[i] = str1[j]; j++; } 
            else { strf[i] = str2[k]; k++; } 
        }

        for (j = len1; j < len2; j++) { strf[i] = str2[j]; i++; }
    } else if (len1 > len2) {
        for(i = 0; i < len2*2; i++) {
            if (i % 2 == 0) { strf[i] = str1[j]; j++; } 
            else { strf[i] = str2[k]; k++; } 
        }

        for (j = len2; j < len1; j++) { strf[i] = str1[j]; i++; }
    } else {
        for(i = 0; i < len2*2; i++) {
            if (i % 2 == 0) { strf[i] = str1[j]; j++; } 
            else { strf[i] = str2[k]; k++; } 
        }
    }
    strf[i] = '\0';
}

int main (void) {
    char str1 [200] = "";
    char str2 [200] = "";
    char strf [400] = "";

    while (scanf("%s %s", str1, str2) == 2) {
        intercalar(str1, str2, strf);
        
        printf("%s\n", strf);
    }

    return 0;
}
