/**********************************************
	* @author: Jun
	* @time  : 2018/8/3
	* @brief ：波形显示处理方案
	* @note  ：none
**********************************************/
#include "ocWave.h"

ocWave_t ocWave;

//波形数据缓存区域
int32_t waveBuff[coMemorySize];

/**********************************************
	* @brief  :获取不同点数的正弦波数据
	* @param  :point: 一周期内的取样点数
  * @param  :maxnum: 一周期内输出最大值
	* @param  :table: 数据存放指针
	* @note :
	* @retval :无
**********************************************/
void ocGetSinTab(uint32_t point,int32_t *table)
{
	uint16_t i=0; 
	float x;   //弧度
	float jiao;//角度 分度角
	jiao=360.000f/point; 

  for(i=0;i<point;i++)
	{
		x=jiao*i;    //得到角度值
		x=x*0.01744f; //角度转弧度  弧度=角度*（π/180）
		table[i]=(ocWave.waveMaxData/2)*sin(x)+(ocWave.waveMaxData/2);
	}
}

/**********************************************
	* @brief  :产生方波信号
	* @param  :point: 一周期内的取样点数
  * @param  :maxnum: 一周期内输出最大值
	* @param  :duty: 占空比
	* @param  :table: 数据存放指针
	* @note :
	* @retval :无
**********************************************/
void ocGetPwm(uint32_t point,uint8_t duty,int32_t *table)
{
	uint16_t i=0,temp; 

	temp = duty * point / 100;
	
  for(i=0;i<temp;i++)
	{
		table[i] = ocWave.waveMaxData;
	}
	
	for(i=0;i<point - temp;i++)
	{
		table[i+temp]=0;
	}
}

/**********************************************
	* @brief  :产生三角波信号
	* @param  :point: 一周期内的取样点数
  * @param  :maxnum: 一周期内输出最大值
	* @param  :duty: 占空比
	* @param  :table: 数据存放指针
	* @note :
	* @retval :无
**********************************************/
void ocGetTriangle(uint32_t point,uint8_t duty,int32_t *table)
{
	uint16_t i=0,temp,midPoint; 

	midPoint = duty*point/100;
	
	for(i=0; i < midPoint;i++)
	{
		table[i] = ocWave.waveMaxData * i / midPoint;
	}
	
	temp = point - midPoint;
	for(i=midPoint; i < point;i++)
	{
		table[i] = ocWave.waveMaxData * (point - i) / temp;
	}
}

/**********************************************
	* @brief  :绘制任意波形
	* @param  :inData ：将要绘制的目标数据
  * @param  :dataLen ：有效数据长度
	* @note :
	* @retval :无
**********************************************/
uint8_t ocDrawWave(int32_t *inData,uint16_t dataLen)
{
	uint32_t showColor,temp,step;
	uint16_t i=0,j=0;
	
	showColor = ocFontSet.textColor;
	
	ocFontSet.textColor = OCCLEAR_COLOR;
	step = xWaveLen/coMemorySize;
	//清除显示窗口数据
	for(i = 0; i < coMemorySize; i++)
	{
		ocDrawUniLine(xWaveOrigin + i*step,
									yWaveOrigin - waveBuff[i],
		              xWaveOrigin + (i+1)*step,
		              yWaveOrigin - waveBuff[i+1]);
	}
	
	ocFontSet.textColor = showColor;
	//显示数据整理
	for(i=0;i < dataLen;i++)
	{
		//数据填充缓存BUFF
		waveBuff[ocWave.waveWrite] = inData[i];
		ocWave.waveWrite ++;
		
		//缓存FIFO已经填充满
		if(ocWave.waveWrite > coMemorySize)
		{
			temp = ocWave.updatePos - (dataLen - i);
			for(j = 0;j < temp;j++)
			{
				waveBuff[j] = waveBuff[j + coMemorySize - temp];
			}
			ocWave.waveWrite = temp;
		}
	}
	
	temp = xWaveLen/coMemorySize;
	//绘制获取的波形数据
	for(i = 0; i < ocWave.waveWrite - 1; i++)
	{
		ocDrawUniLine(xWaveOrigin + i*step,
									yWaveOrigin - waveBuff[i],
		              xWaveOrigin + (i+1)*step,
		              yWaveOrigin - waveBuff[i+1]);
	}

	return oc_OK;
}

/**********************************************
	* @brief  :绘制一个坐标系
	* @param  :inData ：将要绘制的目标数据
  * @param  :dataLen ：有效数据长度
	* @note :
	* @retval :无
**********************************************/
void ocCoordinate(int32_t *inData,uint16_t dataLen)
{
	ocDrawWave(inData,dataLen);
		
	//坐标轴绘制
	if(ocWave.disAxis)
	{
		//起始位置小于原点
		ocDrawUniLine(xWaveOrigin,
									yWaveOrigin,
		              xWaveOrigin + xWaveLen,
		              yWaveOrigin);
		
		//绘制箭头
		ocDrawUniLine(xWaveOrigin + xWaveLen,
		              yWaveOrigin,
		              xWaveOrigin + xWaveLen - ocWave.arrowSize,
		              yWaveOrigin + ocWave.arrowSize);
		
		ocDrawUniLine(xWaveOrigin + xWaveLen,
		              yWaveOrigin,
		              xWaveOrigin + xWaveLen - ocWave.arrowSize,
		              yWaveOrigin - ocWave.arrowSize);
		
		ocDrawUniLine(xWaveOrigin,
		              yWaveOrigin,
									xWaveOrigin,
		              yWaveOrigin - yWaveLen);
		
		//绘制箭头
		ocDrawUniLine(xWaveOrigin,
		              yWaveOrigin - yWaveLen,
		              xWaveOrigin + ocWave.arrowSize,
		              yWaveOrigin - yWaveLen + ocWave.arrowSize);
		
		ocDrawUniLine(xWaveOrigin,
		              yWaveOrigin - yWaveLen,
		              xWaveOrigin - ocWave.arrowSize,
		              yWaveOrigin - yWaveLen + ocWave.arrowSize);
	}
}
