#include<stdio.h>
#include "parse.h"

//��������
void parseAudio();
void parseVidio();

static int parsechannel;

void parse(int channel) {

	printf("��ʼƵ�� %d ����...\n",channel);
	parsechannel = channel;

	parseAudio();
	parseVidio();

	show(parsechannel);
}
static void parseAudio() {

	printf("��ʼƵ�� %d ����Ƶ����...\n", parsechannel);



}

static void parseVidio() {

	printf("��ʼƵ�� %d ����Ƶ����...\n", parsechannel);


}




