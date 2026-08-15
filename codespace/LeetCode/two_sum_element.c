#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int head = 0, tail = numsSize - 1;

    int *result = (int *)malloc(2*sizeof(int));
    qsort(nums, numsSize, sizeof(int), compare);
    
    while(head != tail) {

        if((nums[head] + nums[tail]) == target) {
            result[0] = head;
            result[1] = tail;
            *returnSize = 2;
            return result;
        } else if ((nums[head] + nums[tail]) < target) {
            head++;
        } else {
            tail--;
        }
    }
    return result;
}