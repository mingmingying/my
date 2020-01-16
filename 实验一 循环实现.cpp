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
    printf("����������ĳ��ȣ�");
    scanf("%d",&n);    //��������Ԫ�ظ���
    printf("����������Ԫ�أ�");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);    //�����������е�����a��
    printf("������Ҫ���ҵ�Ԫ�أ�");
    scanf("%d",&key);    //����Ҫ^�ҵĹؼ���
    binsearch(key,a,n);    //�����Զ��庯��
    if((y=binsearch(key,a,n))!=0)
    	printf("�������±�Ϊ��%d",y);
    else
    	printf("���������ڣ�");
    printf("\n");
    return 0;
}
