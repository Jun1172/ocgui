/**********************************************
	* @author: Jun
	* @time  : 2018/8/3
	* @brief ��������ʾ������
	* @note  ��none
**********************************************/
#include "ocWave.h"

ocWave_t ocWave;

//�������ݻ�������
int32_t waveBuff[coMemorySize];

/**********************************************
	* @brief  :��ȡ��ͬ���������Ҳ�����
	* @param  :point: һ�����ڵ�ȡ������
  * @param  :maxnum: һ������������ֵ
	* @param  :table: ���ݴ��ָ��
	* @note :
	* @retval :��
**********************************************/
void ocGetSinTab(uint32_t point,int32_t *table)
{
	uint16_t i=0; 
	float x;   //����
	float jiao;//�Ƕ� �ֶȽ�
	jiao=360.000f/point; 

  for(i=0;i<point;i++)
	{
		x=jiao*i;    //�õ��Ƕ�ֵ
		x=x*0.01744f; //�Ƕ�ת����  ����=�Ƕ�*����/180��
		table[i]=(ocWave.waveMaxData/2)*sin(x)+(ocWave.waveMaxData/2);
	}
}

/**********************************************
	* @brief  :���������ź�
	* @param  :point: һ�����ڵ�ȡ������
  * @param  :maxnum: һ������������ֵ
	* @param  :duty: ռ�ձ�
	* @param  :table: ���ݴ��ָ��
	* @note :
	* @retval :��
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
	* @brief  :�������ǲ��ź�
	* @param  :point: һ�����ڵ�ȡ������
  * @param  :maxnum: һ������������ֵ
	* @param  :duty: ռ�ձ�
	* @param  :table: ���ݴ��ָ��
	* @note :
	* @retval :��
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
	* @brief  :�������Ⲩ��
	* @param  :inData ����Ҫ���Ƶ�Ŀ������
  * @param  :dataLen ����Ч���ݳ���
	* @note :
	* @retval :��
**********************************************/
uint8_t ocDrawWave(int32_t *inData,uint16_t dataLen)
{
	uint32_t showColor,temp,step;
	uint16_t i=0,j=0;
	
	showColor = ocFontSet.textColor;
	
	ocFontSet.textColor = OCCLEAR_COLOR;
	step = xWaveLen/coMemorySize;
	//�����ʾ��������
	for(i = 0; i < coMemorySize; i++)
	{
		ocDrawUniLine(xWaveOrigin + i*step,
									yWaveOrigin - waveBuff[i],
		              xWaveOrigin + (i+1)*step,
		              yWaveOrigin - waveBuff[i+1]);
	}
	
	ocFontSet.textColor = showColor;
	//��ʾ��������
	for(i=0;i < dataLen;i++)
	{
		//������仺��BUFF
		waveBuff[ocWave.waveWrite] = inData[i];
		ocWave.waveWrite ++;
		
		//����FIFO�Ѿ������
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
	//���ƻ�ȡ�Ĳ�������
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
	* @brief  :����һ������ϵ
	* @param  :inData ����Ҫ���Ƶ�Ŀ������
  * @param  :dataLen ����Ч���ݳ���
	* @note :
	* @retval :��
**********************************************/
void ocCoordinate(int32_t *inData,uint16_t dataLen)
{
	ocDrawWave(inData,dataLen);
		
	//���������
	if(ocWave.disAxis)
	{
		//��ʼλ��С��ԭ��
		ocDrawUniLine(xWaveOrigin,
									yWaveOrigin,
		              xWaveOrigin + xWaveLen,
		              yWaveOrigin);
		
		//���Ƽ�ͷ
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
		
		//���Ƽ�ͷ
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
