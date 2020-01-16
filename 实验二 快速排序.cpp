#include<stdio.h>
void Swap(int arr[], int low, int high)
{
    int temp;
    temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}
int Partition(int a[], int low, int high)
{
    int x = a[low];
    while(low < high)
    {
        while(low < high && a[high] >= x)
        {
            high --;
        }
        Swap(a, low, high);
        while(low < high && a[low] <= x)
        {
            low ++;
        }
        Swap(a, low, high);
    }
    return low;
} 
void QuickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int x = Partition(a, low, high);
        QuickSort(a, low, x - 1);
        QuickSort(a, x + 1, high);
    }
} 
int main()
{
 	int a[11], i;    //定义数组及变量为基本整型
    printf("请输入10个数：\n");
    for(i=1;i<=10;i++)
        scanf("%d",&a[i]);    //从键盘中输入10个要进行排序的数
    QuickSort(a,1,10);    //调用 QuickSort()函数进行排序
    printf("排序后的顺序是：\n");
    for(i=1;i<=10;i++)
        printf("%3d",a[i]);    //输出排好序的数组
    printf("\n");
    return 0;
}
