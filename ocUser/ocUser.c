/**********************************************
	* @author: Jun
	* @time  : 2018/8/1
	* @brief ��ʵ�־��幦��
	* @note  ��ʵ��GUI���û��㽻��
**********************************************/
#include "ocUser.h"

//�ⲿ�ӿ�
#include "W25Q64.h"
#include "OLED12864.h"
#include "FileOperation.h"

ocUser_t ocUser;

ocFsSet_t ocFsSet;
ocPreSet_t ocPreSet;
ocMainDis_t ocMainDis;
ocEditDis_t ocEditDis;

//�Ŷ�������ʾ����
char fsFunctionTab[5][10]=
{
	"BYPASS",
	"MUTE",
	"PATCH+",
	"PATCH-",
	"EQ ON/OFF"	
};

//Ԥ�蹦����ʾ����
char preFunctionTab[ALOGOR_PARA_NUM + 1][10]={
"<<<",
"PATCH VOL",
"EQ",
"LOW FREQ",
"LOW GAIN",
"MID FREQ",
"MID GAIN",
"HIGH FREQ",
"HIGH GAIN",
"PRES FREQ",
"PRES GAIN",
"SAVE"
};

//Ԥ�蹦����ʾ����
char onOffTab[2][4]={
"OFF",
"ON",
};

//VOL������ʾ
void prePatchVol(uint8_t Xpos, uint8_t Ypos)
{
	uint8_t val = HardwareParamter.PreaetParaVal[PATCH_VOL];
	ocShowString(Xpos,Ypos,preFunctionTab[PATCH_VOL+1]);
	if(val == 0)
	{
		ocShowString(81,Ypos,"0");
	}
	else
	{
		ocShowNum(81,Ypos,val,0);
	}
	
	
}

//EQ������ʾ
void preEQ(uint8_t Xpos, uint8_t Ypos)
{
	uint8_t val = HardwareParamter.PreaetParaVal[EQ_ONOFF];
	
	ocShowString(Xpos,Ypos,preFunctionTab[EQ_ONOFF+1]);
	ocShowString(81,Ypos,onOffTab[val]);
}

//LowFreq������ʾ
void preLowFreq(uint8_t Xpos, uint8_t Ypos)
{
	uint16_t val = HardwareParamter.PreaetParaVal[LOW_FREQ];
	
	ocShowString(Xpos,Ypos,preFunctionTab[LOW_FREQ+1]);
	ocShowNum(81,Ypos,val,0);
	ocShowString(100,Ypos,"HZ");
}

//LowGain������ʾ
void preLowGain(uint8_t Xpos, uint8_t Ypos)
{
	int8_t val = HardwareParamter.PreaetParaVal[LOW_GAIN];
	
	ocShowString(Xpos,Ypos,preFunctionTab[LOW_GAIN+1]);
	if(val > 0)
	{
		ocShowString(81,Ypos,"+");
	}
	else if(val < 0)
	{
		ocShowString(81,Ypos,"-");
		val = 0 - val;
	}
	else
	{
		ocShowString(81,Ypos,"0");
	}
	
	ocShowNum(96,Ypos,val,0);
}

//midFreq������ʾ
void preMidFreq(uint8_t Xpos, uint8_t Ypos)
{
	uint16_t val = HardwareParamter.PreaetParaVal[MID_FREQ];
	
	ocShowString(Xpos,Ypos,preFunctionTab[MID_FREQ+1]);
	if(val<1000)
	{
		ocShowNum(81,Ypos,val,0);
		ocShowString(100,Ypos,"HZ");
	}
	else
	{
		ocShowString(81,Ypos,"1kHZ");
	}
}

//midGain������ʾ
void preMidGain(uint8_t Xpos, uint8_t Ypos)
{
	int8_t val = HardwareParamter.PreaetParaVal[MID_GAIN];
	
	ocShowString(Xpos,Ypos,preFunctionTab[MID_GAIN+1]);
	if(val > 0)
	{
		ocShowString(81,Ypos,"+");
	}
	else if(val < 0)
	{
		ocShowString(81,Ypos,"-");
		val = 0 - val;
	}
	else
	{
		ocShowString(81,Ypos,"0");
	}
	
	ocShowNum(96,Ypos,val,0);
}

//higFreq������ʾ
void preHigFreq(uint8_t Xpos, uint8_t Ypos)
{
	float val = HardwareParamter.PreaetParaVal[HIGH_FREQ]/1000;
	
	ocShowString(Xpos,Ypos,preFunctionTab[HIGH_FREQ+1]);
	ocShowNum(81,Ypos,val,1);
	ocShowString(100,Ypos,"kHZ");
}

//higGain������ʾ
void preHigGain(uint8_t Xpos, uint8_t Ypos)
{
	int8_t val = HardwareParamter.PreaetParaVal[HIGH_GAIN];
	
	ocShowString(Xpos,Ypos,preFunctionTab[HIGH_GAIN+1]);
	if(val > 0)
	{
		ocShowString(81,Ypos,"+");
	}
	else if(val < 0)
	{
		ocShowString(81,Ypos,"-");
		val = 0 - val;
	}
	else
	{
		ocShowString(81,Ypos,"0");
	}
	
	ocShowNum(96,Ypos,val,0);
}

//presFreq������ʾ
void presFreq(uint8_t Xpos, uint8_t Ypos)
{
	float val = HardwareParamter.PreaetParaVal[PRES_FREQ]/1000;
	
	ocShowString(Xpos,Ypos,preFunctionTab[PRES_FREQ+1]);
	ocShowNum(81,Ypos,val,1);
	ocShowString(100,Ypos,"kHZ");
}

//presGain������ʾ
void presGain(uint8_t Xpos, uint8_t Ypos)
{
	int8_t val = HardwareParamter.PreaetParaVal[PRES_GAIN];
	
	ocShowString(Xpos,Ypos,preFunctionTab[PRES_GAIN+1]);
	if(val > 0)
	{
		ocShowString(81,Ypos,"+");
	}
	else if(val < 0)
	{
		ocShowString(81,Ypos,"-");
		val = 0 - val;
	}
	else
	{
		ocShowString(81,Ypos,"0");
	}
	
	ocShowNum(96,Ypos,val,0);
}

//SAVE��ʾ
void saveShow(uint8_t Xpos, uint8_t Ypos)
{
	ocShowString(Xpos,Ypos,preFunctionTab[SAVEPAGE+1]);
}
//�˳���������ʾ
void quitNoSave(uint8_t Xpos, uint8_t Ypos)
{
	ocShowString(Xpos,Ypos,preFunctionTab[0]);
}

//��ʾ��ʽ����
typedef void (*preFuncTab_t) (uint8_t Xpos, uint8_t Ypos);

preFuncTab_t preFuncTab[ALOGOR_PARA_NUM + 1] = 
{
	quitNoSave,
	prePatchVol,
	preEQ,
	preLowFreq,
	preLowGain,
	preMidFreq,
	preMidGain,
	preHigFreq,
	preHigGain,
	presFreq,
	presGain,
	saveShow,	
};


static uint8_t ocSetInit(void);

/**********************************************
 * @brief ���ӿڳ�ʼ��
 * @param : none
 * @note  ��
 * @retval: ��ʼ���ɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocGuiInit(void)
{
	/* ��ʼ��LCD */
//	SPI_DMA_Init();
	OLED_Init();
	
	ocSetInit();
	return oc_OK;
}

//�˵����
/**********************************************
	* @brief ��omni���˵�
	* @param : patch: ��ǰʹ�õ�patch
	* @param : name:��ǰpatch�µ�ir��
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oMainMenu(void)
{
	uint8_t x0,y0;
	uint8_t i = 0,j = 0,k = 0,m = 0;
	static char *AlgorithmName;
	char	AlgorithmNameStr[15] = {0};
	char	AlgorithmNameChar[3][5] = {0},AlgorithmNameLength[3] = {0};
	static float oldname = -1;
	
	OLEDClear();
	/**************************************************************************/
	/*****************************��ʾ��д��PATCH*******************************/
	/**************************************************************************/
	if(ocMainDis.antiFlag)
	{
		ocFontSet.textColor = 0;
	}
	ocDrawPatch(ocMainDis.pXpos,ocMainDis.pYpos,HardwareParamter.PresetNum);
	ocFontSet.textColor = 1;
	
	/**************************************************************************/
	/********************************�㷨���Ʒ���*******************************/
	/**************************************************************************/
	x0 = ocMainDis.nXpos;//	X����ʼλ��
	y0 = ocMainDis.nYpos;// Y����ʼλ�� 
	ocFontSet.fontForm = acsMin;

  if(oldname != HardwareParamter.PreaetParaVal[IR_NUM_PARA])
	{
		//��ȡIR�㷨�ļ���
		AlgorithmName = GetWavFileName(HardwareParamter.PreaetParaVal[IR_NUM_PARA]);//"12a5 bc 12ba";//�����ļ����ӿں���
		oldname = HardwareParamter.PreaetParaVal[IR_NUM_PARA];
	}
	
	
	for(i=0;i<strlen(AlgorithmName) - 1;i++)//Сд�ַ�ת��д�ַ�
	{
		AlgorithmNameStr[i] = AlgorithmName[i];//ͨ��ָ���ȡ�ļ���
		if(AlgorithmNameStr[i] >= 'a' && AlgorithmNameStr[i] <='z')
			AlgorithmNameStr[i] = AlgorithmNameStr[i] - 32/*a-A*/;
	}
	
	//����ȡ�����ļ������浽����
	for(i=0;i<3;i++)
	{
		m = 0;
		for(j=0;j<ocMainDis.nNum;j++)//������������ȡ��Ч�ַ�������ʾ
		{
			if(AlgorithmNameStr[k] == '.') continue;
			if(AlgorithmNameStr[k] > ' ')
			{
				AlgorithmNameChar[i][m] = AlgorithmNameStr[k];
				m++;
				AlgorithmNameLength[i] = m;
			}
			else
				j = ocMainDis.nNum;
			k++;
		}
	}
	
	/**************************************************************************/
	/********************************�㷨���ƾ�����ʾ*******************************/
	/**************************************************************************/
	
	
	if(HardwareParamter.antiIR)
	{ 
		ocDrawFullRect(x0,y0 - 2,29,35);
		ocFontSet.textColor = 0;
	} 
	ocShowString(x0 + (ocMainDis.nNum - AlgorithmNameLength[0])*(ocMainDis.nXWid/2),y0,AlgorithmNameChar[0]);
	ocShowString(x0 + (ocMainDis.nNum - AlgorithmNameLength[1])*(ocMainDis.nXWid/2),y0 + ocMainDis.nXHig,AlgorithmNameChar[1]);
	ocShowString(x0 + (ocMainDis.nNum - AlgorithmNameLength[2])*(ocMainDis.nXWid/2),y0 + (ocMainDis.nXHig * 2),AlgorithmNameChar[2]);
	ocFontSet.textColor = 1;
	
	if(HardwareParamter.PreaetParaVal[EQ_ONOFF] == 1)
	{
		ocShowString(x0 + 10,y0 + (ocMainDis.nXHig * 3) + 8,"EQ"); 
 
		ocDrawRect(x0 + 10 - 2,y0 + (ocMainDis.nXHig * 3) + 8 - 2, 15, 11);
	}
	
	return oc_OK;
}

/**********************************************
	* @brief ��MUTE����
	* @param :  
	* @param :  
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t onMUTEMenu(void)
{
	uint8_t x0 ,y0;
	x0 = 40;
	y0 = 22;
	ocFontSet.fontForm = acsMid;
	ocShowString(x0,y0,"MUTE");
	return oc_OK;
}

/**********************************************
	* @brief ��BYPASS����
	* @param :  
	* @param :  
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t onBYPASSMenu(void)
{
	uint8_t x0 ,y0;
	x0 = 30;
	y0 = 22;
	ocFontSet.fontForm = acsMid;
	ocShowString(x0,y0,"BYPASS");
	return oc_OK;
}

/**********************************************
	* @brief ��omni�������
	* @param : patch: ��ǰʹ�õ�patch
	* @param : name:��ǰpatch�µ�ir��
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oSaveInterface(void)
{
	if(ocMainDis.antiFlag)
	{
		ocFontSet.textColor = 0;
	}
	/**************************************************************************/
	/*****************************��ʾ��д��PATCH*******************************/
	/**************************************************************************/
	ocDrawPatch(ocMainDis.pXpos,ocMainDis.pYpos,HardwareParamter.PresetNum);
	ocFontSet.textColor = 1;
	ocFontSet.fontForm = acsMin;
	
	/**************************************************************************/
	/*****************************��ʾ�̶��ַ���********************************/
	/**************************************************************************/
	ocShowString(ocMainDis.nXpos,28,"SAVE");
	ocShowString(ocMainDis.nXpos+6,36,"TO");

	return oc_OK;
}

/**********************************************
	* @brief ��U�̸�ʽ���������
	* @param : patch: ��ǰʹ�õ�patch
	* @param : name:��ǰpatch�µ�ir��
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oFileWarning(void)
{
	uint8_t x0 ,y0;
	x0 = 34;
	y0 = 34;
	ocFontSet.fontForm = acsMin;
	ocShowString(x0,y0,"CLEANING...");
	return oc_OK;
}
/**********************************************
	* @brief ���ļ����ؽ���
	* @param : patch: ��ǰʹ�õ�patch
	* @param : name:��ǰpatch�µ�ir��
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oFileLoad(void)
{
	uint8_t x0 ,y0;
	x0 = 35;
	y0 = 34;
	ocFontSet.fontForm = acsMin;
	ocShowString(x0,y0,"LOADING...");
	return oc_OK;
}
/**********************************************
	* @brief ���Ŷ���������
	* @param : 
	* @param : 
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oFsSeting(void)
{
	ocFontSet.fontForm = acsMin;
	//���������ʾ
	ocFontSet.textColor = 0x0;
	
	ocDrawRect(ocFsSet.cXpos - 2,
							 ocFsSet.cYpos + (ocFsSet.yHig * 0) - 2, 125, ocFsSet.yHig);
	
	ocDrawRect(ocFsSet.cXpos - 2,
							 ocFsSet.cYpos + (ocFsSet.yHig * 1) - 2, 125, ocFsSet.yHig);
	
	ocDrawRect(ocFsSet.cXpos - 2,
							 ocFsSet.cYpos + (ocFsSet.yHig * 2) - 2, 125, ocFsSet.yHig);
	
	ocDrawFullRect(ocFsSet.cXpos - 2,
									 ocFsSet.cYpos + (ocFsSet.yHig * ocFsSet.choice) - 2, 125, ocFsSet.yHig);
	ocFontSet.textColor = 0x1;
	
	/**************************************************************************/
	/*****************************û��ѡ��Ŀ��**********************************/
	/**************************************************************************/
	if(ocFsSet.choiceEnable != 1)
	{
		ocFontSet.fontForm = acsMin;
	
		ocShowString(ocFsSet.cXpos,ocFsSet.cYpos,"FS TAP");
		ocShowString(ocFsSet.cXpos+70,ocFsSet.cYpos,fsFunctionTab[HardwareParamter.KeyTap]);
		ocShowString(ocFsSet.cXpos,ocFsSet.cYpos + ocFsSet.yHig,"FS HOLD");
		ocShowString(ocFsSet.cXpos+70,ocFsSet.cYpos + ocFsSet.yHig,fsFunctionTab[HardwareParamter.KeyHold]);
		ocShowString(ocFsSet.cXpos,ocFsSet.cYpos + (ocFsSet.yHig * 2),"EXIT");
		
		ocDrawRect(ocFsSet.cXpos - 2,
							 ocFsSet.cYpos + (ocFsSet.yHig * ocFsSet.choice) - 2, 125, ocFsSet.yHig);
	}
	/**************************************************************************/
	/********************************������ʽ��ѡ��*****************************/
	/**************************************************************************/
	else
	{
		if(ocFsSet.choice == FS_TAP)
		{
			HardwareParamter.KeyTap = ocFsSet.choiceFunc;
			ocDrawFullRect(ocFsSet.cXpos - 2,
									 ocFsSet.cYpos + (ocFsSet.yHig * ocFsSet.choice) - 2, 125, ocFsSet.yHig);
		
			ocShowString(ocFsSet.cXpos,ocFsSet.cYpos + ocFsSet.yHig,"FS HOLD");
			ocShowString(ocFsSet.cXpos+70,ocFsSet.cYpos + ocFsSet.yHig,fsFunctionTab[HardwareParamter.KeyHold]);
			ocShowString(ocFsSet.cXpos,ocFsSet.cYpos + (ocFsSet.yHig * 2),"EXIT");
			ocFontSet.textColor = 0x0;
			ocShowString(ocFsSet.cXpos,ocFsSet.cYpos,"FS TAP");
			ocShowString(ocFsSet.cXpos + 70,ocFsSet.cYpos,fsFunctionTab[HardwareParamter.KeyTap]);
		}
		else if(ocFsSet.choice == FS_HOLD)
		{
			HardwareParamter.KeyHold = ocFsSet.choiceFunc;
			ocDrawFullRect(ocFsSet.cXpos - 2,
									 ocFsSet.cYpos + (ocFsSet.yHig * ocFsSet.choice) - 2, 125, ocFsSet.yHig);
		
			ocShowString(ocFsSet.cXpos,ocFsSet.cYpos,"FS TAP");
			ocShowString(ocFsSet.cXpos+70,ocFsSet.cYpos,fsFunctionTab[HardwareParamter.KeyTap]);
			ocShowString(ocFsSet.cXpos,ocFsSet.cYpos + (ocFsSet.yHig * 2),"EXIT");
			ocFontSet.textColor = 0x0;
			ocShowString(ocFsSet.cXpos,ocFsSet.cYpos + ocFsSet.yHig,"FS HOLD");
			ocShowString(ocFsSet.cXpos + 70,ocFsSet.cYpos + ocFsSet.yHig,fsFunctionTab[HardwareParamter.KeyHold]);	
		}
		else
		{
			ocShowString(ocFsSet.cXpos,ocFsSet.cYpos,"FS TAP");
			ocShowString(ocFsSet.cXpos+70,ocFsSet.cYpos,fsFunctionTab[HardwareParamter.KeyTap]);
			ocShowString(ocFsSet.cXpos,ocFsSet.cYpos + ocFsSet.yHig,"FS HOLD");
			ocShowString(ocFsSet.cXpos+70,ocFsSet.cYpos + ocFsSet.yHig,fsFunctionTab[HardwareParamter.KeyHold]);
			ocShowString(ocFsSet.cXpos,ocFsSet.cYpos + (ocFsSet.yHig * 2),"EXIT");
			
			ocDrawRect(ocFsSet.cXpos - 2,
								 ocFsSet.cYpos + (ocFsSet.yHig * ocFsSet.choice) - 2, 125, ocFsSet.yHig);
		}
		
		ocFontSet.textColor = 0x1;
	}
	
	return oc_OK;
}

/**********************************************
	* @brief ��Ԥ�蹦������
	* @param : 
	* @param : 
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oPreSeting(void)
{
	ocFontSet.fontForm = acsMin;
	
	//�����ʾ
	OLEDClear();
	
	ocDrawFullRect(124, ocPreSet.choice * 5, 2, 9);//��ʾ������
	ocDrawRect(123,0, 4, 64);//���������
	
	/**************************************************************************/
	/********************************ѡ��������ǰ����***************************/
	/**************************************************************************/
	if(ocPreSet.choice < 4)
	{
//		ocShowString(ocPreSet.cXpos,ocPreSet.cYpos,"<<<");
		
		//��ʾ���ö���
		preFuncTab[0](ocPreSet.cXpos,ocPreSet.cYpos);
		preFuncTab[1](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig));
		preFuncTab[2](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 2));
		preFuncTab[3](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 3));
		preFuncTab[4](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 4));
		
		//Ŀ�걻ѡ����Ҫ��ɫ
		if(ocPreSet.choiceEnable)
		{
			//��ɫ����
			ocDrawFullRect(ocPreSet.cXpos - 2,
							       ocPreSet.cYpos + (ocPreSet.yHig * (ocPreSet.choice)) - 2, 
			               123, ocPreSet.yHig);
			
			ocFontSet.textColor = 0x0;
			
			//��ʾ���ڲ���
			preFuncTab[ocPreSet.choice]
			          (ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * (ocPreSet.choice)));
		}
		else//û����Ҫ���õĲ���
		{
			ocDrawRect(ocPreSet.cXpos - 2,
							   ocPreSet.cYpos + (ocPreSet.yHig * (ocPreSet.choice)) - 2, 123, ocPreSet.yHig);
		}
	}
	/**************************************************************************/
	/*******************************ѡ��������ǰ����**************************/
	/**************************************************************************/
	else
	{
		//��ʾ���ö���
		preFuncTab[ocPreSet.choice-4](ocPreSet.cXpos,ocPreSet.cYpos);
		preFuncTab[ocPreSet.choice-3](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 1));
		preFuncTab[ocPreSet.choice-2](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 2));
		preFuncTab[ocPreSet.choice-1](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 3));
		preFuncTab[ocPreSet.choice](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 4));
		
		/**************************************************************************/
		/*******************************ѡ��������Ҫ������**************************/
		/**************************************************************************/
		if(ocPreSet.choiceEnable)
		{
			//��ɫ����
			ocDrawFullRect(ocPreSet.cXpos - 2,
							       ocPreSet.cYpos + (ocPreSet.yHig * 4) - 2, 
			               123, ocPreSet.yHig);
			
			ocFontSet.textColor = 0x0;
			//��ʾ���ڲ���
			preFuncTab[ocPreSet.choice](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 4));
		}
		/**************************************************************************/
		/******************************ѡ��������Ҫ������*************************/
		/**************************************************************************/
		else
		{
			ocDrawRect(ocPreSet.cXpos - 2,
	               ocPreSet.cYpos + (ocPreSet.yHig * 4) - 2, 123, ocPreSet.yHig);
		}
	}
	
	ocFontSet.textColor = 0x1;
	return oc_OK;
}

/**********************************************
	* @brief ��omni�����˵�
	* @param : none
	* @param : none
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t oEditMenu(void)
{
	ocFontSet.fontForm = acsMin;
	
	ocShowString(ocEditDis.cXpos,ocEditDis.cYpos,"FS FUNCTION      >>>");
	ocShowString(ocEditDis.cXpos,ocEditDis.cYpos + ocEditDis.yHig,"EDIT PATCH       >>>");
	ocShowString(ocEditDis.cXpos,ocEditDis.cYpos + (ocEditDis.yHig * 2),"EXIT");
	ocShowString(ocEditDis.cXpos,ocEditDis.cYpos + (ocEditDis.yHig * 5),"VERSIONS        V1.01");
	
	//������ο�
	ocFontSet.textColor = 0x0;
	ocDrawRect(ocEditDis.cXpos - 2,
	           ocEditDis.cYpos - 2, 125, ocEditDis.yHig);
	
	ocDrawRect(ocEditDis.cXpos - 2,
	           ocEditDis.cYpos + ocEditDis.yHig - 2, 125, ocEditDis.yHig);
	
	ocDrawRect(ocEditDis.cXpos - 2,
	           ocEditDis.cYpos + (ocEditDis.yHig * 2) - 2, 125, ocEditDis.yHig);
	
	ocFontSet.textColor = 0x1;
	
	//���ƾ���ѡ���
	ocDrawRect(ocEditDis.cXpos - 2,
	           ocEditDis.cYpos + (ocEditDis.yHig * ocEditDis.choice) - 2, 125, ocEditDis.yHig);
	return oc_OK;
}

/**********************************************
	* @brief ��GUI�������ó�ʼ��
	* @param : none
	* @note  ��
	* @retval: ��ʼ���ɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
static uint8_t ocSetInit(void)
{
	//�û�������Ϣ
	ocUser.direction = HIGH_LOW_LEFT_RIGHT;
	ocUser.fastDraw = oc_Disable;
	(void)ocUser;
	
	//��������
	ocFontSet.fontForm = acsMin;
	ocFontSet.textColor = 0x1;
	(void)ocFontSet;
	
	//����������
	ocMainDis.antiFlag = 0;
	
	ocMainDis.nNum = 5;
	ocMainDis.nXWid = 6;
	ocMainDis.nXHig = 12;
	ocMainDis.nXpos = 94;
	ocMainDis.nYpos = 6;
	
	ocMainDis.pXpos = 0;
	ocMainDis.pYpos = 0;
	
	//�����˵�����
	ocEditDis.cXpos = 2;
	ocEditDis.cYpos = 2;
	ocEditDis.xWid = 6;
	ocEditDis.yHig = 11;
	ocEditDis.choice = 0;
	
	//�Ŷ���������
	ocFsSet.choice = 0;
	ocFsSet.choiceEnable = 0;
	ocFsSet.choiceFunc = 3;
	ocFsSet.cXpos = 2;
	ocFsSet.cYpos = 2;
	ocFsSet.xWid = 6;
	ocFsSet.yHig = 11;
	
	//Ԥ�蹦������
	ocPreSet.choice = 0;
	ocPreSet.choiceEnable = 0;
	ocPreSet.cXpos = 2;
	ocPreSet.cYpos = 2;
	ocPreSet.xWid = 6;
	ocPreSet.yHig = 11;
	
	return oc_OK;
}

/**********************************************
	* @brief ������������ɫ
	* @param : Color: ��ɫ
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocSetColor(uint32_t Color)
{
	
	return oc_OK;
}

/**********************************************
	* @brief ����ָ����λ�û���һ�����ص�
	* @param : Xpos: x����
	* @param : Ypos: y����
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
#if INCCOLORINFO
uint8_t ocPutDot(uint16_t Xpos, uint16_t Ypos, uint32_t color)
#else
uint8_t ocPutDot(uint16_t Xpos, uint16_t Ypos)
#endif
{
	Oled_Dot(Xpos,Ypos,color);
	return oc_OK;
}

/**********************************************
	* @brief �����������Ļ������
	* @note  �����������ʾ
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocDrawFull(void)
{
	
	return oc_OK;
}

/**********************************************
	* @brief ���Ե�ǰ������ɫ���������Ļ
	* @param : Color: ��ɫ
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocClear(uint32_t Color)
{
	OLEDClear();
	return oc_OK;
}

/**********************************************
	* @brief ���������
	* @param : onOff: ���ر��� 1����  0���ر�
	* @note  ��none
	* @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocBackLight(uint32_t onOff)
{
	
	return oc_OK;
}

