#include<stdio.h>
int BinarySearch(int key,int low,int high);
int a[11]={1,2,3,4,5,6,7,8,9,10,11};
int BinarySearch(int key,int low,int high)
{
	int mid;mid=(low+high)/2;
	if(a[mid]>key)
	{
		BinarySearch(key,low,mid-1); 		                      
	}
	else if(a[mid]<key)
	{
		BinarySearch(key,mid+1,high); //middle+1同上 
	}
	else if(a[mid]==key)
	{
		return mid;
	}
}

int main()
{
	int key,y;
	printf("请输入要查找的数：");
	scanf("%d",&key);
	y = BinarySearch(key,0,11);
	if(y == 0)
		printf("该数不存在");
	else 
		printf("查找成功,下标为%d",y);
	return 0;
}
