/**********************************************
	* @author: Jun
	* @time  : 2018/8/3
	* @brief ：图片管理处理接口
	* @note  ：none
**********************************************/
#include "ocPic.h"
#include "OLED12864.h"

ocPic_t ocPicSet;

const char gImage[12][395]=
{/*0*/
{ 0X01,0X01,0X30,0X00,0X40,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
},/*1*/
{ 0X01,0X01,0X30,0X00,0X40,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,
0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,
0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,
0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,
0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,
0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,
0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,
0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
},/*2*/
{ 0X01,0X01,0X30,0X00,0X40,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,
0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,
0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,
0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XF0,
0X0F,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XF0,
0X0F,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XF0,
0X0F,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XF0,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X00,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XF0,
0X00,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XF0,
0X00,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XF0,
0X00,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XF0,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
},/*3*/
{ 0X01,0X01,0X30,0X00,0X40,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,
0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,
0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,
0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,
0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XFF,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XFF,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XFF,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XFF,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XFF,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XFF,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XFF,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XFF,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
},/*4*/
{ 0X01,0X01,0X30,0X00,0X40,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,
0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,
0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,
0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,
0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,
0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,
0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,
0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,
0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,
0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,
0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,
0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,
0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
},/*5*/
{ 0X01,0X01,0X30,0X00,0X40,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X0F,0XFF,0XFF,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XFF,0XFF,0XF0,0X00,0X0F,0XF0,0X00,
0X0F,0XFF,0XFF,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XFF,0XFF,0XF0,0X00,0X0F,0XF0,0X00,
0X0F,0XFF,0XFF,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XFF,0XFF,0XF0,0X00,0X0F,0XF0,0X00,
0X0F,0XFF,0XFF,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XFF,0XFF,0XF0,0X00,0X0F,0XF0,0X00,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XFF,0XFF,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XFF,0XFF,0XF0,0X00,
0X0F,0XF0,0X00,0X0F,0XFF,0XFF,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XFF,0XFF,0XF0,0X00,
0X0F,0XF0,0X00,0X0F,0XFF,0XFF,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XFF,0XFF,0XF0,0X00,
0X0F,0XF0,0X00,0X0F,0XFF,0XFF,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XFF,0XFF,0XF0,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
},/*6*/
{ 0X01,0X01,0X30,0X00,0X40,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,
0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,
0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,
0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,
0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,
0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,
0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,
0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,
0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,
0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,
0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
},/*7*/
{ 0X01,0X01,0X30,0X00,0X40,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XF0,
0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XF0,
0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XF0,
0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XF0,0X0F,0XF0,0X00,0X00,0X0F,0XFF,0XFF,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X00,0X00,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,
0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X00,0X00,0X00,
0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,
0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,
0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,
0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
},/*8*/
{ 0X01,0X01,0X30,0X00,0X40,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
},/*9*/
{ 0X01,0X01,0X30,0X00,0X40,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,
0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,
0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,
0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X00,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,
0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,
0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,
0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XF0,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
},/*A*/
{ 0X01,0X01,0X30,0X00,0X40,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
},/*B*/
{ 0X01,0X01,0X30,0X00,0X40,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,0X0F,0XF0,0X00,0X0F,0XF0,0X00,0X0F,0XF0,
0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,
0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XF0,0X0F,0XFF,0XF0,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
}
};

/**********************************************
 * @brief ：显示一个输入图形数组
 * @param : Xpos:      图片显示左上角X轴位置
 * @param : Ypos:      图片显示左上角Y轴位置
 * @param : pic:       图像数组
 * @note  ：使用IMG2LCD软件转换,要包含图像头数据
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocDrawImg2lcd(uint16_t Xpos, uint16_t Ypos,const char *pic)
{
	uint32_t picW=0,picH=0,showW = 0,showH = 0;//图片尺寸信息
	uint32_t arrayLen,showLen = 6;
	uint8_t dataBit,i,t1,temp,x0,y0;
	
	//数组协议，前八个数据包含数据信息
	//bit0:
		//0:0水平扫描，1垂直扫描
		//4:字序 0 高位在后 1 高位在前
		//6：垂直方向 0 顶-->底 1 顶<-- 底
	  //7：水平方向 0 左到右  1 右到左
	//bit1:0x04--16灰，0x10--16位真彩色，0x12--18位真彩色，0x18--24位真彩色，0x20--32位真彩色；
	//bit2~bit5:
		//第3~6个字节表示宽和高，假设图片数组BMP_BUF[],高位在前时
		//bmp_withd=BMP_BUF[2]|BMP_BUF[3]<<8
		//bmp_lenth=BMP_BUF[4]|BMP_BUF[5]<<8
		//数组大小 =  bmp_withd x bmp_lenth x (位数/8) + [ 8(包含头信息时)]
	//bit6:代表颜色数据的排列方式： 0 --- 565； 1 – 555; (16位真色彩)
	picW = pic[2] | (pic[3]<<8);//获取图片宽度
	picH = pic[4] | (pic[5]<<8);//获取图片高度
	if(pic[1]>8)
		dataBit = pic[1]/8;//计算数据位数
	else
		dataBit = pic[1];
	arrayLen = picW*picH*dataBit;
	
	if(!pic[0])//水平扫描方式
	{
		while(showLen < arrayLen)
		{
			ocFontSet.textColor = 0;
			for(i=0;i<dataBit;i++)
			{
				ocFontSet.textColor = ocFontSet.textColor | 
				                      (pic[showLen+i]&0x000000ff) << (8*i);
			}
			#if INCCOLORINFO
				ocPutDot(showW + Xpos,showH + Ypos,ocFontSet.textColor);
			#else
				ocPutDot(showW + Xpos,showH + Ypos);
			#endif
			
			showW++;
			if(showW >= picW)
			{
				showW = 0;
				showH++;
			}
			showLen += dataBit;
		}
	}
	else//垂直扫描方式
	{
		while(showLen < arrayLen/8)
		{
			x0 = showW+Xpos;
			y0 = (showH+Ypos)*8;
			
			temp = pic[showLen];
			for(t1=0;t1<8;t1++)
			{
				if(temp&0x80)	
				{
						ocPutDot(x0,y0,ocFontSet.textColor);
				} 
				else
				{
					ocPutDot(x0,y0,!ocFontSet.textColor);
				}	
				y0++;	
				temp<<=1;
			}
			
			showLen++;
			showH++;
			if(showH>=8)
			{
				showH = 0;
				showW++;
			}
			
//			
//			ocFontSet.textColor = 0;
//			ocFontSet.textColor = ocFontSet.textColor | 
//				                      (pic[showLen+i]&0x000000ff) << (8*i);
//			
//			ocPutDot(showW + Xpos,showH + Ypos,ocFontSet.textColor);
//			showH++;
//			if(showH >= picH)
//			{
//				showH = 0;
//				showW++;
//			}
//			showLen += dataBit;
		}
	}
		
	return oc_OK;
}

/**********************************************
 * @brief ：显示BMP图片，以数组方式，文件形式需要读取二进制文件
 * @param : Xpos:      图片显示左上角X轴位置
 * @param : Ypos:      图片显示左上角Y轴位置
 * @param : pic:       图像数组
 * @note  ：直接转换BMP原始数据
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocDrawBmp(uint16_t Xpos, uint16_t Ypos,const char *pic)
{
	ocBmpHeard_t ocBmpHeard;
	ocBmpInforHeard_t ocBmpInforHeard;
	
	uint32_t showLen,showW = 0,showH = 0;
	uint8_t dataBit,i;
	
	//获取BMP图像数据信息
	//BMP文件头
	ocBmpHeard.bfType = pic[0x00] << 8 | pic[0x01];//文件标识符，必须为"BM"，即0x424D 才是Windows位图文件
	ocBmpHeard.bfSize = (pic[0x05] << 24 |
	                    pic[0x04] << 16 |
	                    pic[0x03] << 8 |
	                    pic[0x02] << 0)/1024;//整个BMP文件的大小（以位B为单位）
	ocBmpHeard.bfOffBits = pic[0x0a];//说明从文件头0000h开始到图像像素数据的字节偏移量（以字节Bytes为单位），以为位图的调色板长度根据位图格式不同而变化，可以用这个偏移量快速从文件中读取图像数据
	
	//BMP信息头
	ocBmpInforHeard.biSize = pic[0x0e];//BNP信息头即BMP_INFOHEADER结构体所需要的字节数（以字节为单位）
	ocBmpInforHeard.biWidth = pic[0x15] << 24 |
														pic[0x14] << 16 |
														pic[0x13] << 8 |
														pic[0x12] << 0;//说明图像的宽度（以像素为单位）
	ocBmpInforHeard.biHeight =  pic[0x19] << 24 |
															pic[0x18] << 16 |
															pic[0x17] << 8 |
															pic[0x16] << 0;//说明图像的高度（以像素为单位）。这个值还有一个用处，指明图像是正向的位图还是倒向的位图，该值是正数说明图像是倒向的即图像存储是由下到上；该值是负数说明图像是倒向的即图像存储是由上到下。大多数BMP位图是倒向的位图，所以此值是正值。
	ocBmpInforHeard.biPlanes = pic[0x1a] | pic[0x1b] << 8;//为目标设备说明位面数，其值总设置为1
	ocBmpInforHeard.biBitCount = pic[0x1c] | pic[0x1d] << 8;//说明一个像素点占几位（以比特位/像素位单位），其值可为1,4,8,16,24或32
	ocBmpInforHeard.biCompression = pic[0x21] << 24 |
																	pic[0x20] << 16 |
																	pic[0x1f] << 8  |
																	pic[0x1e] << 0; //说明图像数据的压缩类型，取值范围为：
																									//0         BI_RGB 不压缩（最常用）
																									//1         BI_RLE8 8比特游程编码（BLE），只用于8位位图
																									//2         BI_RLE4 4比特游程编码（BLE），只用于4位位图
																									//3         BI_BITFIELDS比特域（BLE），只用于16/32位位图
	ocBmpInforHeard.biSizeImage = pic[0x25] << 24 |
																pic[0x24] << 16 |
																pic[0x23] << 8 |
																pic[0x22] << 0;//说明图像的大小，以字节为单位。当用BI_RGB格式时，总设置为0
	ocBmpInforHeard.biXPelsPerMeter = pic[0x29] << 24 |
																pic[0x28] << 16 |
																pic[0x27] << 8 |
																pic[0x26] << 0;//说明水平分辨率，用像素/米表示，有符号整数
	ocBmpInforHeard.biYPelsPerMeter = pic[0x2d] << 24 |
																pic[0x2c] << 16 |
																pic[0x2b] << 8 |
																pic[0x2a] << 0;//说明垂直分辨率，用像素/米表示，有符号整数
	ocBmpInforHeard.biClrUsed = pic[0x31] << 24 |
																pic[0x30] << 16 |
																pic[0x2f] << 8 |
																pic[0x2e] << 0;//实际使用的调色板索引数，0：使用所有的调色板索引
	ocBmpInforHeard.biClrImportant = pic[0x35] << 24 |
																pic[0x34] << 16 |
																pic[0x33] << 8 |
																pic[0x32] << 0;//说明对图像显示有重要影响的颜色索引的数目，如果是0，表示都重要。
	
	//解析BMP图像信息
	if(ocBmpHeard.bfType == 0x424D)
	{//判断是不是BMP图像
		showLen = ocBmpHeard.bfOffBits;
		dataBit = ocBmpInforHeard.biBitCount / 8;
		while(showLen < ocBmpInforHeard.biSizeImage)
		{
			ocFontSet.textColor = 0;
			for(i=0;i<dataBit;i++)
			{
				ocFontSet.textColor = ocFontSet.textColor | 
				                      (pic[showLen+i]&0x000000ff) << (8*i);
			}
			
			//图片显示从左到右，从下到上
			#if INCCOLORINFO
				ocPutDot(Xpos + showW,Ypos + ocBmpInforHeard.biHeight - showH,ocFontSet.textColor);
			#else
				ocPutDot(Xpos + showW,Ypos + ocBmpInforHeard.biHeight - showH);
			#endif
			
			showW++;
			if(showW >= ocBmpInforHeard.biWidth)
			{
				showW = 0;
				showH++;
			}
			showLen += dataBit;
		}
	}
	
	return oc_OK;
}

/**********************************************
 * @brief ：OLED12864显示一个图片
 * @param : Xpos:      图片显示左上角X轴位置
 * @param : Ypos:      图片显示左上角Y轴位置
 * @param : pic:       显示的数据
 * @note  ：
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocDrawImg2Num(uint16_t Xpos, uint16_t Ypos,uint8_t pic)
{
	
	ocDrawImg2lcd(Xpos,Ypos,gImage[pic]);
	return oc_OK;
}

/**********************************************
 * @brief ：OLED12864显示PATCH编号
 * @param : Xpos:      图片显示左上角X轴位置
 * @param : Ypos:      图片显示左上角Y轴位置
 * @param : pic:       显示的数据
 * @note  ：
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocDrawPatch(uint16_t Xpos, uint16_t Ypos,uint8_t patch)
{
	uint8_t width;
	
	ocDrawImg2lcd(Xpos,Ypos,gImage[patch/10]);
	
	width = gImage[patch%10][2] | (gImage[patch%10][3]<<8);//说明图像的宽度（以像素为单位）
	
	ocDrawImg2lcd(Xpos + width - 4  ,Ypos,gImage[patch%10]);

	return oc_OK;
}
	
