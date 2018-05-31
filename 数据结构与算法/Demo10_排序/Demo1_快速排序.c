#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 8


void quickSort(int * arr, int left, int right);                         // 快速排序
int partition(int arr[], int left, int right);                          // 返回一趟快速排序后基准在数组中的位置，此时已经小的元素放在基准左侧，大的元素右侧

int main()
{
    int i;
    int arr[MAXSIZE] = {70, 75, 69, 32, 88, 18, 16, 58};
    quickSort(arr, 0, MAXSIZE - 1);

    printf("快速排序后：\n");
    for (i = 0; i < MAXSIZE; ++i)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}

/*
 *  快速排序
      基本思想： 任选排序序列中的一个元素(通常选取的是第一个元素)作为基准(也叫枢轴privot),按照基准的大小将待排序列分成左右两个子序列(以基准为参考)
               比基准小的数均放在基准左边，比基准大的数，均放在基准右边，然后递归对这两个子序列递归用类似的方法进行排序。
      具体做法：
           设待排序元素的下界和上界分别为left、right，arr[left]是枢轴元素(这里我选取的是第一个元素)，快速排序过程如下
        1.	首先将arr[keft]中的元素保存到pivot变量中
        2.	从right向左找(从右往左)，如果arr[right]大于等于基准则right-1 直到 arr[right]<基准,将其复制到left所在位置，然后left+1 即arr[left] = arr[right] ; left++
        3.	从left开始向右找(从左往右)，arr[left]小于等于基准则left + 1 直到 arr[left] > 基准,将其复制到right所在位置，然后right-1 即arr[right] = arr[left] ; right--
        4.	重复步骤2、3直到left == right为止(也就是两指针相遇)，此时将pivot中的值放回到left或right所处的位置，一趟快速排序完成
 */

void quickSort(int * arr, int left, int right)
{
    static  int num = 0;                                         // 记录躺数
    int privotPosition, i;                                       // 基准在数组中的位置(索引)
    if (left < right)
    {
        // 调用partition()返回基准的位置并且在返回时已经通过该函数将小的元素放在基准左侧，大的元素右侧
        privotPosition = partition(arr, left, right);
        // 打印第1-n趟快速排序的结果
        printf("第%d趟快速排序结果:\n", ++num);
        for (i = 0; i < MAXSIZE; ++i)
        {
            printf("%d  ", arr[i]);
        }
        printf("\n");

        quickSort(arr, left, privotPosition-1);                 // 对左子序列递归进行快速排序
        quickSort(arr, privotPosition + 1, right);              // 对右子序列递归进行快速排序
    }
}

// 返回一趟快速排序后基准在数组中的位置，此时已经小的元素放在基准左侧，大的元素右侧
int partition(int arr[], int left, int right)
{
    int privot = arr[left];                                             // 这里我选取的是以每一个序列的第一个元素作为基准 最佳选取:取 第一个元素 中间一个元素 最后一个元素的中位数
    while (left < right)
    {
        // 从right向左找(从右往左)，如果arr[right]大于等于基准则right-1
        while (left < right && arr[right] >= privot)
        {
            right--;
        }
        // 直到 arr[right]<基准,将其复制到left所在位置，然后left+1 即arr[left] = arr[right] ; left++
        if (left < right)
        {
            arr[left++] = arr[right];
        }

        // 从left开始向右找(从左往右)，arr[left]小于等于基准则left + 1
        while (left < right && arr[left] <= privot)
        {
            left++;
        }
        // 直到 arr[left] > 基准,将其复制到right所在位置，然后right-1 即arr[right] = arr[left] ; right--
        if (left < right )
        {
            arr[right--] = arr[left];
        }
    }
    // 重复步骤2、3直到left == right为止(也就是两指针相遇)，此时将pivot中的值放回到left或right所处的位置，一趟快速排序完成
    arr[left] = privot;
    return left;
}



