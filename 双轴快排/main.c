#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int a, int b);
void sort(int *arr, int left, int right);

int main(void)
{
    int nums[] = {3423,4,124,2,34,23,453,5,2134};

    sort(nums, 0, 9);

    return 0;
}

void swap(int *arr, int a, int b)
{
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

void sort(int *arr, int left, int right)
{
    int l = left, r = right-1, k = left+1;

    if (l >= r) {
        return ;
    }

    if (arr[l] > arr[r]) {
        swap(arr, l, r);
    }
    for (;k <= r;) {
        if (arr[k] <= arr[l]) {
            if (k > l+1)
                swap(arr, l, l+1);
            swap(arr, k++, l++);
        } else if (arr[k] >= arr[r]) {
            if (k < r-1)
                swap(arr, r, r-1);
            swap(arr, k, r--);
        } else {
            ++k;
        }
    }

    sort(arr, left, l);
    sort(arr, l+1, r);
    sort(arr, r+1, right);
}