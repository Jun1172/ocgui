/**********************************************
	* @author: Jun
	* @time  : 2018/8/1
	* @brief ：颜色管理接口
	* @note  ：none
**********************************************/
#ifndef _OCCOLOUR_H_
#define _OCCOLOUR_H_

#include "ocConfig.h"

#define Bit2  0
#define Bit16 1
#define Bit24 2

//颜色控制结构体
typedef struct
{
	uint32_t dataBit;//颜色位数
}ocColour_t;

extern ocColour_t ocColourSet;

#endif

