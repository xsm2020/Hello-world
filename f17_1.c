#include<stdio.h>

int main()
{
	int year,i,day=0;
	int date1[3],date2[3];		//表示出生和当前的年月日
	int flag=0;    //作为闰平年的标志

	//输入
	printf("请输入一个年份:");
	scanf("%d-%d-%d",&date1[0],&date1[1],&date1[2]);
	getchar();
	printf("请输入今天的日期：");
	scanf("%d-%d-%d",&date2[0],&date2[1],&date2[2]);
	
	//计算每月之前的天数
	for(i=1;i<13;i++)
	{
		month[i]=month[i-1]+month[i];
	}

	year = date1[0];
	
	//判断闰平年	
	if((!(year % 400)) || !(year % 4) && (year % 100))
	{
		flag = 1;
	}
	else
	{
		flag = 0;
	}

	day = month[12]+flag-(date1[2]+month[date1[1]-1]); //计算当前天数，并减去得到剩下的天数

	//计算出生年份到今年的年数
	for(flag = 0,year=year+1;year<date2[0];year++)
	{
		if(!(year % 400) || !(year % 4) && (year % 100))
		{
			flag = 1;
		}
		day = day + flag + month[12];
		flag = 0;    //标志初始化
	}
	
	flag = 0;
	year = date2[0];
	//计算当年已经过了的天数
	if((date2[1]>2) && (!(year % 400)) || !(year % 4) && (year % 100))
	{
		flag=1;
	}
	day = day+month[date2[1]-1]+date2[2]+flag; //得到总数

	//判断用户输入是否是同一年
	if(date1[0] == date2[0])
	{
		day = day - month[12];
		if(1 == flag)
		{
			day-=1;
		}
	}	
	
	printf("您在世界上总共生存了%d天\n",day-1);
	return 0;
}
