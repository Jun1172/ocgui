/**********************************************
	* @author: Jun
	* @time  : 2018/8/1
	* @brief ���������ӿ�
	* @note  ��none
**********************************************/
#ifndef _OCFONT_H_
#define _OCFONT_H_

#include "ocConfig.h"
#include "math.h"
#include "stdio.h"
#include "string.h"

#define acsMin  5
#define acsMid  10

//��ɫ���ƽṹ��
typedef struct
{
	uint8_t fontForm;//�ַ�����
	uint32_t textColor;//������ɫ
	uint32_t textBackColor;//���屳��ɫ
}ocFont_t;

extern ocFont_t ocFontSet;

/**********************************************
 * @brief ����ָ��λ����ʾһ���ַ�
 * @param : Xpos: x��ʼ����
 * @param : Ypos: y��ʼ����
 * @param : acsii: �ַ�
 * @note  ��none
 * @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
void ocShowChar(uint16_t Xpos, uint16_t Ypos,char acsii);

/**********************************************
 * @brief ����ʾ�ַ���
 * @param : Xpos: x��ʼ����
 * @param : Ypos: y��ʼ����
 * @param : *p:�ַ�����ʼ��ַ	
 * @note  ��none
 * @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
void ocShowString(uint16_t Xpos,uint16_t Ypos,char *Str);

/**********************************************
 * @brief ����ʾ��ֵ
 * @param : Xpos: x��ʼ����
 * @param : Ypos: y��ʼ����
 * @param : num:Ҫ��ʾ����ֵ
 * @param : acc:��ȷ��С�����λ
 * @note  ��none
 * @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
void ocShowNum(uint16_t Xpos,uint16_t Ypos,float num,uint8_t acc);
	
#endif
