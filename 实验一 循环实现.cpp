#include<stdio.h>
int binsearch(int x, int a[], int n);
int binsearch(int x, int a[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while ( low <= high ) 
	{
        mid = (low + high) / 2;
        if(x < a[mid]){
            high = mid - 1;
        }
        else if(x > a[mid]){
            low = mid + 1;
        }
        else{
            return mid;
        }
    } 
    return -1;
}
int main()
{
    int i,key,a[100],n,y;
    printf("请输入数组的长度：");
    scanf("%d",&n);    //输入数组元素个数
    printf("请输入数组元素：");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);    //输入有序数列到数组a中
    printf("请输入要查找的元素：");
    scanf("%d",&key);    //输入要^找的关键字
    binsearch(key,a,n);    //调用自定义函数
    if((y=binsearch(key,a,n))!=0)
    	printf("该数的下标为：%d",y);
    else
    	printf("该数不存在！");
    printf("\n");
    return 0;
}
