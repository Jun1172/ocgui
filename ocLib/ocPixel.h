/**********************************************
	* @author: Jun
	* @time  : 2018/8/1
	* @brief ：像素点操作
	* @note  ：none
**********************************************/
#ifndef _OCPIXEL_H_
#define _OCPIXEL_H_

#include "ocConfig.h"

#define OC_HORIZONTAL       0x0
#define OC_VERTICAL         0x1

/**********************************************
 * @brief ：向指定方向，画一条特定长度的直线
 * @param : Xpos:      直线起点的x坐标
 * @param : Ypos:      直线起点的y坐标
 * @param : Length:    直线的长度
 * @param : Direction: 直线的方向，从左往右或从上至下
 * @note  ：none
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocDrawLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint8_t Direction);

/**********************************************
	* @brief  : 使用 Bresenham 算法画线段（基于两点） 
	* @param  : Xpos1 ：线段的一个端点X坐标
	* @param  : Ypos1 ：线段的一个端点Y坐标
	* @param  : Xpos2 ：线段的另一个端点X坐标
	* @param  : Ypos2 ：线段的另一个端点Y坐标
	* @note  
	* @retval : 无
**********************************************/
void ocDrawUniLine ( uint16_t Xpos1, uint16_t Ypos1, uint16_t Xpos2, uint16_t Ypos2 );

/**********************************************
	* @brief  :绘制空心矩形
	* @param  :Xpos ：矩形左上角端点X坐标
	* @param  :Ypos ：矩形左上角端点Y坐标
	* @param  :Width ：矩形宽
	* @param  :Height ：矩形高
	* @note :
	* @retval :无
**********************************************/
void ocDrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);

/**********************************************
	* @brief  :绘制实心矩形
	* @param  :Xpos ：矩形左上角端点X坐标
	* @param  :Ypos ：矩形左上角端点Y坐标
	* @param  :Width ：矩形宽
	* @param  :Height ：矩形高
	* @note :
	* @retval :无
**********************************************/
void ocDrawFullRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);

/**********************************************
	* @brief  :绘制空心圆
	* @param  :Xpos ：中心点X坐标
	* @param  :Ypos ：中心点Y坐标
	* @param  :Radius ：圆形半径
	* @note :
	* @retval :无
**********************************************/
void ocDrawCircle(uint16_t Xpos,uint16_t Ypos,uint16_t Radius);

/**********************************************
	* @brief  :绘制一个实心圆
	* @param  :Xpos: 圆心X坐标
	* @param  :Ypos: 圆心Y坐标
	* @param  ：Radius: 半径
	* @retval ：None
**********************************************/
void ocDrawFullCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius);
	
/**********************************************
	* @brief  :绘制三角形
	* @param  :aXpos ：a点x坐标
	* @param  :aYpos ：a点y坐标
	* @param  :bXpos ：b点x坐标
	* @param  :bYpos ：b点y坐标
	* @param  :cXpos ：c点x坐标
	* @param  :cYpos ：c点y坐标
	* @note :
	* @retval :无
**********************************************/
void ocDrawTriangle(uint16_t aXpos,uint16_t aYpos,uint16_t bXpos,uint16_t bYpos,uint16_t cXpos,uint16_t cYpos);
	
/**********************************************
	* @brief  : 使用 Bresenham 算法画椭圆
	* @param  : Xpos1 ：线段的一个端点X坐标
	* @param  : Ypos1 ：线段的一个端点Y坐标
	* @param  : Xpos2 ：线段的另一个端点X坐标
	* @param  : Ypos2 ：线段的另一个端点Y坐标
	* @note  
	* @retval : 无
**********************************************/
void ocDrawEllipse (int xRadius, int yRadius, int Xpos, int Ypos);
		
#endif
