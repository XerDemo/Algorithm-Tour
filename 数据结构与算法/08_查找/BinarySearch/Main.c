#include "BinarySearch1.h"
#include "BinarySearch2.h"
#include "BinarySearchRecursive.h"

int main(void)
{
    int n = pow(10, 7);
    int *arr1 = generateOrderArray(n);
    int *arr2 = generateOrderArray(n);
    int *arr3 = generateOrderArray(n);
    testSearch("BinarySearch1", binarySearch1, arr1, n);
    testSearch("BinarySearch2", binarySearch2, arr2, n);
    testSearch("BinarySearchRecursive", BinarySearchRecursive, arr3, n);
    return 0;
}