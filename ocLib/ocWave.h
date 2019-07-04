/**********************************************
	* @author: Jun
	* @time  : 2018/8/3
	* @brief ��������ʾ������
	* @note  ��none
**********************************************/
#ifndef _OCWAVE_H_
#define _OCWAVE_H_

#include "ocConfig.h"

//����ԭ���ַ
#define xWaveOrigin 100
#define yWaveOrigin 400

//���λ����С,Ҳ��������������Ͳ���
#define coMemorySize 200 

//������ʾ���ڴ�С
#define xWaveLen 500
#define yWaveLen 300

//������ʾ�ṹ��
typedef struct
{
	//������ز���
	uint16_t updatePos;//���ݸ���λ��
	uint16_t waveWrite;//����д����λ��
	uint16_t waveMaxData;//���������λ��
	
	uint8_t disAxis;//��������ʾ����
	uint8_t arrowSize;//��ͷ�ߴ�
}ocWave_t;

extern ocWave_t ocWave;

/**********************************************
	* @brief  :��ȡ��ͬ���������Ҳ�����
	* @param  :point: һ�����ڵ�ȡ������
  * @param  :maxnum: һ������������ֵ
	* @param  :table: ���ݴ��ָ��
	* @note :
	* @retval :��
**********************************************/
void ocGetSinTab(uint32_t point,int32_t *table);

/**********************************************
	* @brief  :���������ź�
	* @param  :point: һ�����ڵ�ȡ������
  * @param  :maxnum: һ������������ֵ
	* @param  :duty: ռ�ձ�
	* @param  :table: ���ݴ��ָ��
	* @note :
	* @retval :��
**********************************************/
void ocGetPwm(uint32_t point,uint8_t duty,int32_t *table);

/**********************************************
	* @brief  :�������ǲ��ź�
	* @param  :point: һ�����ڵ�ȡ������
  * @param  :maxnum: һ������������ֵ
	* @param  :duty: ռ�ձ�
	* @param  :table: ���ݴ��ָ��
	* @note :
	* @retval :��
**********************************************/
void ocGetTriangle(uint32_t point,uint8_t duty,int32_t *table);
	
/**********************************************
	* @brief  :�������Ⲩ��
	* @param  :inData ����Ҫ���Ƶ�Ŀ������
  * @param  :dataLen ����Ч���ݳ���
	* @note :
	* @retval :��
**********************************************/
uint8_t ocDrawWave(int32_t *inData,uint16_t dataLen);

/**********************************************
	* @brief  :����һ������ϵ
	* @param  :inData ����Ҫ���Ƶ�Ŀ������
  * @param  :dataLen ����Ч���ݳ���
	* @note :
	* @retval :��
**********************************************/
void ocCoordinate(int32_t *inData,uint16_t dataLen);

#endif
