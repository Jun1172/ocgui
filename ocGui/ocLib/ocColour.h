/**********************************************
	* @author: Jun
	* @time  : 2018/8/1
	* @brief ����ɫ����ӿ�
	* @note  ��none
**********************************************/
#ifndef _OCCOLOUR_H_
#define _OCCOLOUR_H_

#include "ocConfig.h"

#define Bit2  0
#define Bit16 1
#define Bit24 2

//��ɫ���ƽṹ��
typedef struct
{
	uint32_t dataBit;//��ɫλ��
}ocColour_t;

extern ocColour_t ocColourSet;

#endif

