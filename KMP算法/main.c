#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_next(char *, int *);
void kmp(char *, char *);

int main(void)
{
    kmp("aaabbb", "aa");

    return 0;
}

void make_next(char *s, int *next)
{
    int i = 0, j = 0;

    next[i++] = 0;
    while (s[i]) {
        if (s[i] != s[j]) {
            if (0 == j) {
                next[i++] = 0;
            } else {
                j = next[j-1];
            }
        } else {
            next[i++] = ++j;
        }
    }
}

void kmp(char *s, char *r)
{
    int length = strlen(r);
    int *next = (int *)malloc(length * sizeof(int));
    int i = 0, j = 0;

    make_next(r, next);

    while (s[i]) {
        if (s[i] != r[j]) {
            if (0 == j) {
                ++i;
            } else {
                j = next[j-1];
            }
        } else {
            ++i;
            ++j;
            if (length == j) {
                printf("%d ", i - length);
                j = next[j - 1];
            }
        }
    }
}