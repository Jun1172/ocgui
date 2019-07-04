/**********************************************
	* @author: Jun
	* @time  : 2018/8/3
	* @brief ��ͼƬ������ӿ�
	* @note  ��none
**********************************************/
#ifndef _OCPIC_H_
#define _OCPIC_H_

#include "ocConfig.h"

#define Bit2  0
#define Bit16 1
#define Bit24 2

//��ɫ���ƽṹ��
typedef struct
{
	uint32_t dataBit;//��ɫλ��
	uint32_t antiFlag;//��ɫ����
}ocPic_t;

extern ocPic_t ocPicSet;

//BMP�ļ�ͷ
typedef struct 
{ 
uint16_t bfType;        //2Bytes������Ϊ"BM"����0x424D ����Windowsλͼ�ļ�
uint32_t bfSize;        //4Bytes������BMP�ļ��Ĵ�С
uint16_t bfReserved1;   //2Bytes��������Ϊ0
uint16_t bfReserved2;   //2Bytes��������Ϊ0
uint32_t bfOffBits;     //4Bytes���ļ���ʼλ�õ�ͼ���������ݵ��ֽ�ƫ����
} ocBmpHeard_t;

//BMP��Ϣͷ
typedef struct 
{
uint32_t  biSize;          //4Bytes��INFOHEADER�ṹ���С�����������汾I NFOHEADER����������
uint32_t   biWidth;        //4Bytes��ͼ���ȣ�������Ϊ��λ��
uint32_t   biHeight;       //4Bytes��ͼ��߶ȣ�+��ͼ��洢˳��ΪBottom2Top��-��Top2Bottom
uint8_t   biPlanes;        //2Bytes��ͼ������ƽ�棬BMP�洢RGB���ݣ������Ϊ1
uint8_t   biBitCount;      //2Bytes��ͼ������λ��
uint32_t  biCompression;   //4Bytes��0����ѹ����1��RLE8��2��RLE4
uint32_t  biSizeImage;     //4Bytes��4�ֽڶ����ͼ�����ݴ�С
uint32_t   biXPelsPerMeter;//4Bytes��������/�ױ�ʾ��ˮƽ�ֱ���
uint32_t   biYPelsPerMeter;//4Bytes��������/�ױ�ʾ�Ĵ�ֱ�ֱ���
uint32_t  biClrUsed;       //4Bytes��ʵ��ʹ�õĵ�ɫ����������0��ʹ�����еĵ�ɫ������
uint32_t biClrImportant;   //4Bytes����Ҫ�ĵ�ɫ����������0�����еĵ�ɫ����������Ҫ
}ocBmpInforHeard_t;

//BMP��ɫ��
//typedef struct 
//{
//BYTE  rgbBlue;       //ָ����ɫǿ��
//BYTE  rgbGreen;      //ָ����ɫǿ��
//BYTE  rgbRed;        //ָ����ɫǿ��
//BYTE  rgbReserved;  //����������Ϊ0
//} ocBmpRGBQuad_t;

/**********************************************
 * @brief ����ʾһ������ͼ������
 * @param : Xpos:      ͼƬ��ʾ���Ͻ�X��λ��
 * @param : Ypos:      ͼƬ��ʾ���Ͻ�Y��λ��
 * @param : pic:       ͼ������
 * @note  ��ʹ��IMG2LCD���ת��,Ҫ����ͼ��ͷ����
 * @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocDrawImg2lcd(uint16_t Xpos, uint16_t Ypos,const char *pic);

/**********************************************
 * @brief ����ʾBMPͼƬ�������鷽ʽ���ļ���ʽ��Ҫ��ȡ�������ļ�
 * @param : Xpos:      ͼƬ��ʾ���Ͻ�X��λ��
 * @param : Ypos:      ͼƬ��ʾ���Ͻ�Y��λ��
 * @param : pic:       ͼ������
 * @note  ��ֱ��ת��BMPԭʼ����
 * @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocDrawBmp(uint16_t Xpos, uint16_t Ypos,const char *pic);

/**********************************************
 * @brief ��OLED12864��ʾһ��ͼƬ
 * @param : Xpos:      ͼƬ��ʾ���Ͻ�X��λ��
 * @param : Ypos:      ͼƬ��ʾ���Ͻ�Y��λ��
 * @param : pic:       ��ʾ������
 * @note  ��
 * @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocDrawImg2Num(uint16_t Xpos, uint16_t Ypos,uint8_t pic);

/**********************************************
 * @brief ��OLED12864��ʾPATCH���
 * @param : Xpos:      ͼƬ��ʾ���Ͻ�X��λ��
 * @param : Ypos:      ͼƬ��ʾ���Ͻ�Y��λ��
 * @param : pic:       ��ʾ������
 * @note  ��
 * @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocDrawPatch(uint16_t Xpos, uint16_t Ypos,uint8_t patch);

#endif

