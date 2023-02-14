#include<stdio.h>
#include"parse.h"
//假设一个之前的变量
//static int globalchannel;


void acceptControl() {

	//假设一个之前的变量
	do
	{
		static int globalchannel;
		int channel = 0;

		printf("请输入遥控器的频道\n");
		scanf_s("%d", &channel);
		if (globalchannel != channel) {
			globalchannel = channel;
			printf("切台%d频道\n", globalchannel);

			parse(globalchannel);
			//show(globalchannel);

		}
		//printf("切台%d\n频道", channel);

	} while (1);
}