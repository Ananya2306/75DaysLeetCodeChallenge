#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int lastIndex[256];
    
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int left = 0, maxLen = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        char current = s[right];

        if (lastIndex[current] >= left) {
            left = lastIndex[current] + 1;
        }

        lastIndex[current] = right;

        int currLen = right - left + 1;
        if (currLen > maxLen) {
            maxLen = currLen;
        }
    }

    return maxLen;
}
