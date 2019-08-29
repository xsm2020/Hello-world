#include<stdio.h>
#include<string.h>

#define NUM 128

int main()
{
	char count[NUM]="";
	int num[NUM] = {0};
	int ch,i,j=0,sum = 0,max = 0;

	printf("请输入英文文本：");  

	while((ch = getchar()) != '\n')
	{
		num[ch]++;		//在ascii码表上对应的位号个数加1
		sum++;			//得到总个数
	}

	for(i = 0;i < NUM; i++)
	{
		if(num[i])
		{
			count[j++] = i;		//计算不同字符个数
			if(num[i] > num[max])
			{
				max = i;	//i表示的是第多少位的字符
			}
		}
	}
	printf("你总共输入了%d个字符，其中不同的有%d个",sum,strlen(count));
	printf("它们是：%s\n",count);
	printf("出现次数最多的字符是'%c'，它总共出现了%d次\n",max,num[max]);
	return 0;
}
