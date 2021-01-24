#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 5
#define M 5

void water(int b[N+2][M+2],int i,int j);


int main(void)
{
	int a[N][M],b[N+2][M+2]={0,0,0,0,0,0,0,
							 0,0,0,0,0,0,0,
							 0,0,0,0,0,0,0,
							 0,0,0,0,0,0,0,
							 0,0,0,0,0,0,0,
							 0,0,0,0,0,0,0,
							 0,0,0,0,0,0,0,};
	int i=0,j=0,k=0;
	int n = 0,g=0;
	int count=0;
	int buy = 0;
	int need_number=0;
	int sum = 0;
	int water_sum = 0;

	srand(time(NULL));

	for(i = 0 ;i < N*M ;i++)
	{
		//scanf("%d",&a[i/M][i%M]);
		a[i/M][i%M] = rand()%2;      //生成随机水坑1
	}


	
	for(i = 0;i < N*M;i++)
	{
		printf("  %d\t",a[i/M][i%M]);//打印水坑数组
		if((i+1) % M == 0)
		{
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
		}
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	for(i = 1;i < N+1;i++)				//在水坑数组外面包一个大数组
	{
		for(j = 1;j < M+1;j++)
		{
			b[i][j] = a[i-1][j-1];
		}
	}

	for(i = 0;i < (N+2)*(M+2);i++)
	{
		printf("  %d\t",b[i/(M+2)][i%(M+2)]);  //打印观察包好后的数组
		if((i+1) % (M+2) == 0)
		{
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
		}
	}

	for(i = 1;i < N+1;i++)				//开始数水坑的数量
	{
		for(j = 1;j < M+1;j++)
		{
			if(b[i][j] == 1)
			{
				water_sum++;         //当发现有水坑的时候，
									//计数并对周围进行扫描
				water(b,i,j);
			}
			
		}
	}

	printf("水坑有%d个\n",water_sum);

	return 0;
}

void water(int b[N+2][M+2],int i,int j)
{
	if(b[i][j] == 1)
	{
		b[i][j] = 0;				//计数后把扫描到的水坑置零
		water(b,i+1,j);				//直到四周没有水坑为止
		water(b,i-1,j);
		water(b,i,j+1);
		water(b,i,j-1);
		//water(b,i+1,j+1);
		//water(b,i-1,j+1);
		//water(b,i-1,j-1);
		//water(b,i+1,j-1);
	}
}


