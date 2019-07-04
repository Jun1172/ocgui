/**********************************************
	* @author: Jun
	* @time  : 2018/8/1
	* @brief �����ص����
	* @note  ��none
**********************************************/
#ifndef _OCPIXEL_H_
#define _OCPIXEL_H_

#include "ocConfig.h"

#define OC_HORIZONTAL       0x0
#define OC_VERTICAL         0x1

/**********************************************
 * @brief ����ָ�����򣬻�һ���ض����ȵ�ֱ��
 * @param : Xpos:      ֱ������x����
 * @param : Ypos:      ֱ������y����
 * @param : Length:    ֱ�ߵĳ���
 * @param : Direction: ֱ�ߵķ��򣬴������һ��������
 * @note  ��none
 * @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocDrawLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint8_t Direction);

/**********************************************
	* @brief  : ʹ�� Bresenham �㷨���߶Σ��������㣩 
	* @param  : Xpos1 ���߶ε�һ���˵�X����
	* @param  : Ypos1 ���߶ε�һ���˵�Y����
	* @param  : Xpos2 ���߶ε���һ���˵�X����
	* @param  : Ypos2 ���߶ε���һ���˵�Y����
	* @note  
	* @retval : ��
**********************************************/
void ocDrawUniLine ( uint16_t Xpos1, uint16_t Ypos1, uint16_t Xpos2, uint16_t Ypos2 );

/**********************************************
	* @brief  :���ƿ��ľ���
	* @param  :Xpos ���������ϽǶ˵�X����
	* @param  :Ypos ���������ϽǶ˵�Y����
	* @param  :Width �����ο�
	* @param  :Height �����θ�
	* @note :
	* @retval :��
**********************************************/
void ocDrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);

/**********************************************
	* @brief  :����ʵ�ľ���
	* @param  :Xpos ���������ϽǶ˵�X����
	* @param  :Ypos ���������ϽǶ˵�Y����
	* @param  :Width �����ο�
	* @param  :Height �����θ�
	* @note :
	* @retval :��
**********************************************/
void ocDrawFullRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);

/**********************************************
	* @brief  :���ƿ���Բ
	* @param  :Xpos �����ĵ�X����
	* @param  :Ypos �����ĵ�Y����
	* @param  :Radius ��Բ�ΰ뾶
	* @note :
	* @retval :��
**********************************************/
void ocDrawCircle(uint16_t Xpos,uint16_t Ypos,uint16_t Radius);

/**********************************************
	* @brief  :����һ��ʵ��Բ
	* @param  :Xpos: Բ��X����
	* @param  :Ypos: Բ��Y����
	* @param  ��Radius: �뾶
	* @retval ��None
**********************************************/
void ocDrawFullCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius);
	
/**********************************************
	* @brief  :����������
	* @param  :aXpos ��a��x����
	* @param  :aYpos ��a��y����
	* @param  :bXpos ��b��x����
	* @param  :bYpos ��b��y����
	* @param  :cXpos ��c��x����
	* @param  :cYpos ��c��y����
	* @note :
	* @retval :��
**********************************************/
void ocDrawTriangle(uint16_t aXpos,uint16_t aYpos,uint16_t bXpos,uint16_t bYpos,uint16_t cXpos,uint16_t cYpos);
	
/**********************************************
	* @brief  : ʹ�� Bresenham �㷨����Բ
	* @param  : Xpos1 ���߶ε�һ���˵�X����
	* @param  : Ypos1 ���߶ε�һ���˵�Y����
	* @param  : Xpos2 ���߶ε���һ���˵�X����
	* @param  : Ypos2 ���߶ε���һ���˵�Y����
	* @note  
	* @retval : ��
**********************************************/
void ocDrawEllipse (int xRadius, int yRadius, int Xpos, int Ypos);
		
#endif
