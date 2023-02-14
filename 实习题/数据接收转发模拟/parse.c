#include<stdio.h>
#include "parse.h"

//函数声明
void parseAudio();
void parseVidio();

static int parsechannel;

void parse(int channel) {

	printf("开始频道 %d 解析...\n",channel);
	parsechannel = channel;

	parseAudio();
	parseVidio();

	show(parsechannel);
}
static void parseAudio() {

	printf("开始频道 %d 的音频解析...\n", parsechannel);



}

static void parseVidio() {

	printf("开始频道 %d 的视频解析...\n", parsechannel);


}




