/**********************************************
 * @author��Jun
 * @time  ��2018/8/1
 * @brief ��ʵ�־��幦��
 * @note  ��ʵ��GUI���û��㽻��
**********************************************/
#ifndef _OCUSER_H_
#define _OCUSER_H_

#include "ocConfig.h"

//��Ļˢд����
#define HIGH_LOW_LEFT_RIGHT 0//���ϵ��´�����
#define HIGH_LOW_RIGHT_LEFT 1//���ϵ��´��ҵ���
#define LOW_HIGH_LEFT_RIGHT 2//���µ��ϴ�����
#define LOW_HIGH_RIGHT_LEFT 3//���µ��ϴ��ҵ���
#define LEFT_RIGHT_HIGH_LOW 4//�����Ҵ��ϵ���
#define LEFT_RIGHT_LOW_HIGH 5//�����Ҵ��µ���
#define RIGHT_LEFT_HIGH_LOW 6//���ҵ�����ϵ���
#define RIGHT_LEFT_LOW_HIGH 7//���ҵ�����µ���

#define OCCLEAR_COLOR 0

//��㺯��������ɫ��Ϣ
#define INCCOLORINFO 1

//�����˵�ѡ����
#define FS_FUNCTION 0
#define EDIT_PATCH  1
#define EXIT        2

//�ȶ���������
#define FS_TAP   0
#define FS_HOLD  1

#define FS_BYPASS    0
#define FS_MUTE      1
#define FS_PATCHADD  2
#define FS_PATCHSUB  3
#define FS_EQ_ONOFF  4

#define SAVEPAGE  10

//�û�������Ϣ
typedef struct
{
	uint8_t direction;
	uint8_t fastDraw;
}ocUser_t;

//����������
typedef struct
{
	uint8_t antiFlag;//�����淴ɫ����
	
	uint8_t pXpos;//patch��ʾX����ʼλ��
	uint8_t pYpos;//patch��ʾY����ʼλ��
	
	uint8_t nNum;//nameһ����ʾ�ַ�����
	uint8_t nXWid;//name�����ַ�ռ�Ŀ��
	uint8_t nXHig;//name�����ַ�ռ�ĸ߶�
	uint8_t nXpos;//name��ʾX����ʼλ��
	uint8_t nYpos;//name��ʾY����ʼλ��
}ocMainDis_t;

//�����˵�����
typedef struct
{
	uint8_t choice;//��ǰѡ�еĶ���
	
	uint8_t cXpos;//����X��λ��
	uint8_t cYpos;//����Y��λ��
	uint8_t xWid;//�����ַ���ռ���
	uint8_t yHig;//�����ַ���ռ�߶�
}ocEditDis_t;

//�ȶ���������
typedef struct
{
	uint8_t choice;//��ǰѡ�еĶ���
	uint8_t choiceEnable;//��ǰѡ�еĶ�����Ҫ������
	uint8_t choiceFunc;//��ǰѡ�еĹ���
	
	uint8_t cXpos;//����X��λ��
	uint8_t cYpos;//����Y��λ��
	uint8_t xWid;//�����ַ���ռ���
	uint8_t yHig;//�����ַ���ռ�߶�
}ocFsSet_t;

//Ԥ�蹦������
typedef struct
{
	uint8_t choice;//��ǰѡ�еĶ���
	uint8_t choiceEnable;//��ǰѡ�еĶ�����Ҫ������

	uint8_t cXpos;//����X��λ��
	uint8_t cYpos;//����Y��λ��
	uint8_t xWid;//�����ַ���ռ���
	uint8_t yHig;//�����ַ���ռ�߶�
}ocPreSet_t;

extern ocFsSet_t ocFsSet;
extern ocEditDis_t ocEditDis;
extern ocMainDis_t ocMainDis;
extern ocPreSet_t ocPreSet;

/**********************************************
 * @brief ��GUI��ʼ��
 * @param : none
 * @note  ��
 * @retval: ��ʼ���ɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocGuiInit(void);
	
/**********************************************
 * @brief ����ָ����λ�û���һ�����ص�
 * @param : Xpos: x����
 * @param : Ypos: y����
 * @note  ����ʼ���ɹ�����oc_OK��ʧ�ܷ���oc_ON
 * @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
#if INCCOLORINFO
uint8_t ocPutDot(uint16_t Xpos, uint16_t Ypos, uint32_t color);
#else
uint8_t ocPutDot(uint16_t Xpos, uint16_t Ypos);
#endif

/**********************************************
 * @brief ������������ɫ
 * @param : Color: ��ɫ
 * @note  ��none
 * @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocSetColor(uint32_t Color);

/**********************************************
 * @brief ���Ե�ǰ������ɫ���������Ļ
 * @param : Color: ��ɫ
 * @note  ��none
 * @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocClear(uint32_t Color);

/**********************************************
	* @brief ��omni���˵�
	* @param : patch: ��ǰʹ�õ�patch
	* @param : name:��ǰpatch�µ�ir��
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oMainMenu(void);
/**********************************************
	* @brief ��MUTE����
	* @param :  
	* @param :  
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t onMUTEMenu(void);
/**********************************************
	* @brief ��BYPASS����
	* @param : patch: ��ǰʹ�õ�patch
	* @param : name:��ǰpatch�µ�ir��
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t onBYPASSMenu(void);
/**********************************************
	* @brief ��omni�����˵�
	* @param : patch: ��ǰʹ�õ�patch
	* @param : name:��ǰpatch�µ�ir��
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oEditMenu(void);

/**********************************************
	* @brief ��Ԥ�蹦������
	* @param : 
	* @param : 
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oPreSeting(void);

/**********************************************
	* @brief ���Ŷ���������
	* @param : 
	* @param : 
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oFsSeting(void);

/**********************************************
	* @brief ��omni�������
	* @param : patch: ��ǰʹ�õ�patch
	* @param : name:��ǰpatch�µ�ir��
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oSaveInterface(void);
/**********************************************
	* @brief ��U�̸�ʽ������
	* @param : patch: ��ǰʹ�õ�patch
	* @param : name:��ǰpatch�µ�ir��
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oFileWarning(void);
/**********************************************
	* @brief ���ļ����ؽ���
	* @param : patch: ��ǰʹ�õ�patch
	* @param : name:��ǰpatch�µ�ir��
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oFileLoad(void);


#endif

