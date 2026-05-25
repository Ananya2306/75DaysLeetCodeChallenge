class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] freq = new int[26];

        for (char c : tasks) {
            freq[c - 'A']++;
        }

        int maxFreq = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
            }
        }

        int maxCount = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == maxFreq) {
                maxCount++;
            }
        }

        int intervals = (maxFreq - 1) * (n + 1) + maxCount;

        return Math.max(tasks.length, intervals);
    }
}