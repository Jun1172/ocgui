/**********************************************
	* @author: Jun
	* @time  : 2018/8/1
	* @brief ：字体管理接口
	* @note  ：none
**********************************************/
#ifndef _OCFONT_H_
#define _OCFONT_H_

#include "ocConfig.h"
#include "math.h"
#include "stdio.h"
#include "string.h"

#define acsMin  5
#define acsMid  10

//颜色控制结构体
typedef struct
{
	uint8_t fontForm;//字符类型
	uint32_t textColor;//字体颜色
	uint32_t textBackColor;//字体背景色
}ocFont_t;

extern ocFont_t ocFontSet;

/**********************************************
 * @brief ：在指定位置显示一个字符
 * @param : Xpos: x起始坐标
 * @param : Ypos: y起始坐标
 * @param : acsii: 字符
 * @note  ：none
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
void ocShowChar(uint16_t Xpos, uint16_t Ypos,char acsii);

/**********************************************
 * @brief ：显示字符串
 * @param : Xpos: x起始坐标
 * @param : Ypos: y起始坐标
 * @param : *p:字符串起始地址	
 * @note  ：none
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
void ocShowString(uint16_t Xpos,uint16_t Ypos,char *Str);

/**********************************************
 * @brief ：显示数值
 * @param : Xpos: x起始坐标
 * @param : Ypos: y起始坐标
 * @param : num:要显示的数值
 * @param : acc:精确到小数点后几位
 * @note  ：none
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
void ocShowNum(uint16_t Xpos,uint16_t Ypos,float num,uint8_t acc);
	
#endif
