#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int c[50][50];
int b[50][50];
char x[1000];//���X�ַ���
char y[1000];//���Y�ַ���
void LCSLength(int m,int n,char x[],char y[],int c[][50],int b[][50])
{
    int i,j;
    for(i=1;i<=m;i++)//��j=0ʱ��c[i][j]=0
        c[i][0]=0;
    for(j=1;j<=n;j++)//��i=0ʱ��c[i][j]=0
        c[0][j]=0;
    for(i=1;i<=m;i++)//������������еĳ��Ƚ��м�¼
        for(j=1;j<=n;j++)
    {
        if(x[i]==y[j])//Xi=Yj�����
        {
            c[i][j]=c[i-1][j-1]+1;//c[i][j]�洢Xi��Yj������������еĳ���
            b[i][j]=1; //б����           //b[i][j]��¼c[i][j]��ֵ�����ĸ�������Ľ������
        }
        else if(c[i-1][j]>=c[i][j-1])
        {
            c[i][j]=c[i-1][j];
            b[i][j]=2;//��ֱ����
        }
        else
        {
            c[i][j]=c[i][j-1];
            b[i][j]=3;//ˮƽ����
        }
    }
}
void LCS(int i,int j,char x[], int b[][50])
{
    if(i==0||j==0)
        return;
    if(b[i][j]==1)//��ʾXi��Yi�����������������Xi-1��Yi-1���������������β������Xi���õ���
        {//b[i][j]==1ʱ����ʾ��б45�����ϣ�Ҳ�����ʱ���Ӧ����ĸʱLCS�е�һ����
            LCS(i-1,j-1,x,b);
            cout<<x[i]<<" ";
        }
    else if(b[i][j]==2)//��ʾXi��Yj���������������Xi-1��Yj���������������ͬ��
            LCS(i-1,j,x,b);
    else//��ʾXi��Yj���������������Xi��Yj-1���������������ͬ��
            LCS(i,j-1,x,b);
}
int main()
{
    int xn,yn;//XY�ַ����Ĵ�С
    cout<<"������X���ϵ�Ԫ�ظ�����"<<endl;
    cin>>xn;
    cout<<"������X���ϵ�Ԫ�أ�"<<endl;
    int i=0;//����ѭ������X��Y���ַ���
    for(i=1;i<=xn;i++)
        cin>>x[i];
    cout<<"������y���ϵ�Ԫ�ظ�����"<<endl;
    cin>>yn;
    cout<<"������y���ϵ�Ԫ�أ�"<<endl;
    for(i=1;i<=yn;i++)
        cin>>y[i];
    LCSLength(xn,yn,x,y,c,b);
	cout << "X��Y�������������Ϊ��";
    LCS(xn,yn,x,b);
	cout << endl;	
	int j = 0;
	int m = 0;
	printf("b[i][j]�е����֣�\n");
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
	printf("c[i][j]�е����֣�\n");
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
