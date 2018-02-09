// Calculate a + b and output the sum in standard format -- that is, 
// the digits must be separated into groups of three by commas 
// (unless there are less than four digits).

// Input
// Each input file contains one test case. Each case contains 
// a pair of integers a and b where -1000000 <= a, b <= 1000000. 
// The numbers are separated by a space.

// Output
// For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

// Sample Input
// -1000000 9
// Sample Output
// -999,991
#include <stdio.h>

int main(void)
{
    int a, b, i, idx, tag;
    int sum;
    char num[20];
    while ((scanf("%d %d", &a, &b)) != EOF) {
        sum = a + b;
        if (sum < 0) {
            i = 0;
            sum = -sum;
        } else {
            i = 1;
        }
        idx = 0;
        tag = 0;
        while (sum != 0) {
            idx++;
            tag++;
            num[20 - idx] = sum % 10 + '0';
            sum = sum / 10;
            if (tag % 3 == 0) {
                if (sum == 0) 
                    break;
                idx++;
                num[20 - idx] = ',';
                tag = 0;
            }
        }
        if (i == 0) {
            printf("-");
        }
        for (i = 20 - idx; i < 20; i++) {
            printf("%c", num[i]);
        }
        printf("\n");
    }

}