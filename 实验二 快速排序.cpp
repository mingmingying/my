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
 	int a[11], i;    //�������鼰����Ϊ��������
    printf("������10������\n");
    for(i=1;i<=10;i++)
        scanf("%d",&a[i]);    //�Ӽ���������10��Ҫ�����������
    QuickSort(a,1,10);    //���� QuickSort()������������
    printf("������˳���ǣ�\n");
    for(i=1;i<=10;i++)
        printf("%3d",a[i]);    //����ź��������
    printf("\n");
    return 0;
}
