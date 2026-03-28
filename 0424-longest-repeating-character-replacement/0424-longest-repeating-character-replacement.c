#include <stdio.h>

int characterReplacement(char* s, int k) {
    int freq[26] = {0};
    int left = 0, maxFreq = 0, maxLen = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        int index = s[right] - 'A';
        freq[index]++;

        if (freq[index] > maxFreq) {
            maxFreq = freq[index];
        }

        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }

        int windowSize = right - left + 1;
        if (windowSize > maxLen) {
            maxLen = windowSize;
        }
    }

    return maxLen;
}