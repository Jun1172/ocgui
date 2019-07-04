/**********************************************
	* @author: Jun
	* @time  : 2018/8/3
	* @brief ：图片管理处理接口
	* @note  ：none
**********************************************/
#ifndef _OCPIC_H_
#define _OCPIC_H_

#include "ocConfig.h"

#define Bit2  0
#define Bit16 1
#define Bit24 2

//颜色控制结构体
typedef struct
{
	uint32_t dataBit;//颜色位数
	uint32_t antiFlag;//反色控制
}ocPic_t;

extern ocPic_t ocPicSet;

//BMP文件头
typedef struct 
{ 
uint16_t bfType;        //2Bytes，必须为"BM"，即0x424D 才是Windows位图文件
uint32_t bfSize;        //4Bytes，整个BMP文件的大小
uint16_t bfReserved1;   //2Bytes，保留，为0
uint16_t bfReserved2;   //2Bytes，保留，为0
uint32_t bfOffBits;     //4Bytes，文件起始位置到图像像素数据的字节偏移量
} ocBmpHeard_t;

//BMP信息头
typedef struct 
{
uint32_t  biSize;          //4Bytes，INFOHEADER结构体大小，存在其他版本I NFOHEADER，用作区分
uint32_t   biWidth;        //4Bytes，图像宽度（以像素为单位）
uint32_t   biHeight;       //4Bytes，图像高度，+：图像存储顺序为Bottom2Top，-：Top2Bottom
uint8_t   biPlanes;        //2Bytes，图像数据平面，BMP存储RGB数据，因此总为1
uint8_t   biBitCount;      //2Bytes，图像像素位数
uint32_t  biCompression;   //4Bytes，0：不压缩，1：RLE8，2：RLE4
uint32_t  biSizeImage;     //4Bytes，4字节对齐的图像数据大小
uint32_t   biXPelsPerMeter;//4Bytes，用象素/米表示的水平分辨率
uint32_t   biYPelsPerMeter;//4Bytes，用象素/米表示的垂直分辨率
uint32_t  biClrUsed;       //4Bytes，实际使用的调色板索引数，0：使用所有的调色板索引
uint32_t biClrImportant;   //4Bytes，重要的调色板索引数，0：所有的调色板索引都重要
}ocBmpInforHeard_t;

//BMP调色板
//typedef struct 
//{
//BYTE  rgbBlue;       //指定蓝色强度
//BYTE  rgbGreen;      //指定绿色强度
//BYTE  rgbRed;        //指定红色强度
//BYTE  rgbReserved;  //保留，设置为0
//} ocBmpRGBQuad_t;

/**********************************************
 * @brief ：显示一个输入图形数组
 * @param : Xpos:      图片显示左上角X轴位置
 * @param : Ypos:      图片显示左上角Y轴位置
 * @param : pic:       图像数组
 * @note  ：使用IMG2LCD软件转换,要包含图像头数据
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocDrawImg2lcd(uint16_t Xpos, uint16_t Ypos,const char *pic);

/**********************************************
 * @brief ：显示BMP图片，以数组方式，文件形式需要读取二进制文件
 * @param : Xpos:      图片显示左上角X轴位置
 * @param : Ypos:      图片显示左上角Y轴位置
 * @param : pic:       图像数组
 * @note  ：直接转换BMP原始数据
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocDrawBmp(uint16_t Xpos, uint16_t Ypos,const char *pic);

/**********************************************
 * @brief ：OLED12864显示一个图片
 * @param : Xpos:      图片显示左上角X轴位置
 * @param : Ypos:      图片显示左上角Y轴位置
 * @param : pic:       显示的数据
 * @note  ：
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocDrawImg2Num(uint16_t Xpos, uint16_t Ypos,uint8_t pic);

/**********************************************
 * @brief ：OLED12864显示PATCH编号
 * @param : Xpos:      图片显示左上角X轴位置
 * @param : Ypos:      图片显示左上角Y轴位置
 * @param : pic:       显示的数据
 * @note  ：
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocDrawPatch(uint16_t Xpos, uint16_t Ypos,uint8_t patch);

#endif

