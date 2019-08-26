#include<stdio.h>
#include<math.h>

int main()
{
	long long num,i,j,k,l;
	_Bool flag = 1;
	
	printf("请输入一个数字: ");
	scanf("%lld",&num);

	for(i = 2, j = num / i; flag !=0 ; i++,j = num / i,flag = 1)
	{
		if(i * j == num)
		{
			for(l = 2; l <= sqrt(j); l++)  //增加l
			{
				if(j % l == 0)
				{
					flag = 0;
				   	break;	//判断j是否为质数
				}
			}
			if(1 == flag)
			{
				break;
			}
		}
			

	}
	
	printf("最大的质数因子是 %lld \n",j);
	return 0;	
}
