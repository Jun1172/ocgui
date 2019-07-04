/**********************************************
	* @author: Jun
	* @time  : 2018/8/3
	* @brief ：波形显示处理方案
	* @note  ：none
**********************************************/
#ifndef _OCWAVE_H_
#define _OCWAVE_H_

#include "ocConfig.h"

//设置原点地址
#define xWaveOrigin 100
#define yWaveOrigin 400

//波形缓存大小,也代表采样点数量和步进
#define coMemorySize 200 

//设置显示窗口大小
#define xWaveLen 500
#define yWaveLen 300

//波形显示结构体
typedef struct
{
	//波形相关参数
	uint16_t updatePos;//数据更新位置
	uint16_t waveWrite;//缓存写数据位置
	uint16_t waveMaxData;//缓存读数据位置
	
	uint8_t disAxis;//坐标轴显示控制
	uint8_t arrowSize;//箭头尺寸
}ocWave_t;

extern ocWave_t ocWave;

/**********************************************
	* @brief  :获取不同点数的正弦波数据
	* @param  :point: 一周期内的取样点数
  * @param  :maxnum: 一周期内输出最大值
	* @param  :table: 数据存放指针
	* @note :
	* @retval :无
**********************************************/
void ocGetSinTab(uint32_t point,int32_t *table);

/**********************************************
	* @brief  :产生方波信号
	* @param  :point: 一周期内的取样点数
  * @param  :maxnum: 一周期内输出最大值
	* @param  :duty: 占空比
	* @param  :table: 数据存放指针
	* @note :
	* @retval :无
**********************************************/
void ocGetPwm(uint32_t point,uint8_t duty,int32_t *table);

/**********************************************
	* @brief  :产生三角波信号
	* @param  :point: 一周期内的取样点数
  * @param  :maxnum: 一周期内输出最大值
	* @param  :duty: 占空比
	* @param  :table: 数据存放指针
	* @note :
	* @retval :无
**********************************************/
void ocGetTriangle(uint32_t point,uint8_t duty,int32_t *table);
	
/**********************************************
	* @brief  :绘制任意波形
	* @param  :inData ：将要绘制的目标数据
  * @param  :dataLen ：有效数据长度
	* @note :
	* @retval :无
**********************************************/
uint8_t ocDrawWave(int32_t *inData,uint16_t dataLen);

/**********************************************
	* @brief  :绘制一个坐标系
	* @param  :inData ：将要绘制的目标数据
  * @param  :dataLen ：有效数据长度
	* @note :
	* @retval :无
**********************************************/
void ocCoordinate(int32_t *inData,uint16_t dataLen);

#endif
