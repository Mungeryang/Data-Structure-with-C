#include<stdio.h>
#include"parse.h"
//����һ��֮ǰ�ı���
//static int globalchannel;


void acceptControl() {

	//����һ��֮ǰ�ı���
	do
	{
		static int globalchannel;
		int channel = 0;

		printf("������ң������Ƶ��\n");
		scanf_s("%d", &channel);
		if (globalchannel != channel) {
			globalchannel = channel;
			printf("��̨%dƵ��\n", globalchannel);

			parse(globalchannel);
			//show(globalchannel);

		}
		//printf("��̨%d\nƵ��", channel);

	} while (1);
}