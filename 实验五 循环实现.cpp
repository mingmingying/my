#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int c[50][50];
int b[50][50];
char x[1000];//存放X字符串
char y[1000];//存放Y字符串
void LCSLength(int m,int n,char x[],char y[],int c[][50],int b[][50])
{
    int i,j;
    for(i=1;i<=m;i++)//当j=0时，c[i][j]=0
        c[i][0]=0;
    for(j=1;j<=n;j++)//当i=0时，c[i][j]=0
        c[0][j]=0;
    for(i=1;i<=m;i++)//对最长公共子序列的长度进行记录
        for(j=1;j<=n;j++)
    {
        if(x[i]==y[j])//Xi=Yj的情况
        {
            c[i][j]=c[i-1][j-1]+1;//c[i][j]存储Xi和Yj的最长公共子序列的长度
            b[i][j]=1; //斜向上           //b[i][j]记录c[i][j]的值是由哪个子问题的解得来的
        }
        else if(c[i-1][j]>=c[i][j-1])
        {
            c[i][j]=c[i-1][j];
            b[i][j]=2;//竖直向上
        }
        else
        {
            c[i][j]=c[i][j-1];
            b[i][j]=3;//水平向左
        }
    }
}
void LCS(int i,int j,char x[], int b[][50])
{
    if(i==0||j==0)
        return;
    if(b[i][j]==1)//表示Xi和Yi的最长公共子序列是由Xi-1和Yi-1的最长公共子序列在尾部加上Xi所得到的
        {//b[i][j]==1时，表示左斜45°向上，也即这个时候对应的字母时LCS中的一个。
            LCS(i-1,j-1,x,b);
            cout<<x[i]<<" ";
        }
    else if(b[i][j]==2)//表示Xi和Yj的最长公共子序列与Xi-1和Yj的最长公共子序列相同。
            LCS(i-1,j,x,b);
    else//表示Xi和Yj的最长公共子序列与Xi和Yj-1的最长公共子序列相同。
            LCS(i,j-1,x,b);
}
int main()
{
    int xn,yn;//XY字符串的大小
    cout<<"请输入X集合的元素个数："<<endl;
    cin>>xn;
    cout<<"请输入X集合的元素："<<endl;
    int i=0;//用于循环输入X和Y的字符串
    for(i=1;i<=xn;i++)
        cin>>x[i];
    cout<<"请输入y集合的元素个数："<<endl;
    cin>>yn;
    cout<<"请输入y集合的元素："<<endl;
    for(i=1;i<=yn;i++)
        cin>>y[i];
    LCSLength(xn,yn,x,y,c,b);
	cout << "X和Y的最长公共子序列为：";
    LCS(xn,yn,x,b);
	cout << endl;	
	int j = 0;
	int m = 0;
	printf("b[i][j]中的数字：\n");
	for (i = 0; i <=xn; i++)
		for (j = 0; j <= yn; j++)
		{ 
			printf("%d ", b[i][j]);
			m++;
			if (m == xn)
			{
				m = 0;
				printf("\n");
			}		  
		}
	m = 0;
	printf("c[i][j]中的数字：\n");
	for (i = 0; i <= xn; i++)
		for (j = 0; j <=yn; j++)
		{
			printf("%d ", c[i][j]);
			m++;
			if (m == xn)
			{
				printf("\n");
				m = 0;
 
			}
				
		}	
	printf("pause");
    return 0;
}
