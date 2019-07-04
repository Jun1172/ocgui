/**********************************************
	* @author: Jun
	* @time  : 2018/8/1
	* @brief ：实现具体功能
	* @note  ：实现GUI与用户层交互
**********************************************/
#include "ocUser.h"

//外部接口
#include "W25Q64.h"
#include "OLED12864.h"
#include "FileOperation.h"

ocUser_t ocUser;

ocFsSet_t ocFsSet;
ocPreSet_t ocPreSet;
ocMainDis_t ocMainDis;
ocEditDis_t ocEditDis;

//脚钉功能显示内容
char fsFunctionTab[5][10]=
{
	"BYPASS",
	"MUTE",
	"PATCH+",
	"PATCH-",
	"EQ ON/OFF"	
};

//预设功能显示内容
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

//预设功能显示内容
char onOffTab[2][4]={
"OFF",
"ON",
};

//VOL设置显示
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

//EQ设置显示
void preEQ(uint8_t Xpos, uint8_t Ypos)
{
	uint8_t val = HardwareParamter.PreaetParaVal[EQ_ONOFF];
	
	ocShowString(Xpos,Ypos,preFunctionTab[EQ_ONOFF+1]);
	ocShowString(81,Ypos,onOffTab[val]);
}

//LowFreq设置显示
void preLowFreq(uint8_t Xpos, uint8_t Ypos)
{
	uint16_t val = HardwareParamter.PreaetParaVal[LOW_FREQ];
	
	ocShowString(Xpos,Ypos,preFunctionTab[LOW_FREQ+1]);
	ocShowNum(81,Ypos,val,0);
	ocShowString(100,Ypos,"HZ");
}

//LowGain设置显示
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

//midFreq设置显示
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

//midGain设置显示
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

//higFreq设置显示
void preHigFreq(uint8_t Xpos, uint8_t Ypos)
{
	float val = HardwareParamter.PreaetParaVal[HIGH_FREQ]/1000;
	
	ocShowString(Xpos,Ypos,preFunctionTab[HIGH_FREQ+1]);
	ocShowNum(81,Ypos,val,1);
	ocShowString(100,Ypos,"kHZ");
}

//higGain设置显示
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

//presFreq设置显示
void presFreq(uint8_t Xpos, uint8_t Ypos)
{
	float val = HardwareParamter.PreaetParaVal[PRES_FREQ]/1000;
	
	ocShowString(Xpos,Ypos,preFunctionTab[PRES_FREQ+1]);
	ocShowNum(81,Ypos,val,1);
	ocShowString(100,Ypos,"kHZ");
}

//presGain设置显示
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

//SAVE显示
void saveShow(uint8_t Xpos, uint8_t Ypos)
{
	ocShowString(Xpos,Ypos,preFunctionTab[SAVEPAGE+1]);
}
//退出不保存显示
void quitNoSave(uint8_t Xpos, uint8_t Ypos)
{
	ocShowString(Xpos,Ypos,preFunctionTab[0]);
}

//显示方式定义
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
 * @brief ：接口初始化
 * @param : none
 * @note  ：
 * @retval: 初始化成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocGuiInit(void)
{
	/* 初始化LCD */
//	SPI_DMA_Init();
	OLED_Init();
	
	ocSetInit();
	return oc_OK;
}

//菜单设计
/**********************************************
	* @brief ：omni主菜单
	* @param : patch: 当前使用的patch
	* @param : name:当前patch下的ir名
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
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
	/*****************************显示大写的PATCH*******************************/
	/**************************************************************************/
	if(ocMainDis.antiFlag)
	{
		ocFontSet.textColor = 0;
	}
	ocDrawPatch(ocMainDis.pXpos,ocMainDis.pYpos,HardwareParamter.PresetNum);
	ocFontSet.textColor = 1;
	
	/**************************************************************************/
	/********************************算法名称分离*******************************/
	/**************************************************************************/
	x0 = ocMainDis.nXpos;//	X轴起始位置
	y0 = ocMainDis.nYpos;// Y轴起始位置 
	ocFontSet.fontForm = acsMin;

  if(oldname != HardwareParamter.PreaetParaVal[IR_NUM_PARA])
	{
		//读取IR算法文件名
		AlgorithmName = GetWavFileName(HardwareParamter.PreaetParaVal[IR_NUM_PARA]);//"12a5 bc 12ba";//调用文件名接口函数
		oldname = HardwareParamter.PreaetParaVal[IR_NUM_PARA];
	}
	
	
	for(i=0;i<strlen(AlgorithmName) - 1;i++)//小写字符转大写字符
	{
		AlgorithmNameStr[i] = AlgorithmName[i];//通过指针读取文件名
		if(AlgorithmNameStr[i] >= 'a' && AlgorithmNameStr[i] <='z')
			AlgorithmNameStr[i] = AlgorithmNameStr[i] - 32/*a-A*/;
	}
	
	//将读取到的文件名保存到数组
	for(i=0;i<3;i++)
	{
		m = 0;
		for(j=0;j<ocMainDis.nNum;j++)//从数组里面提取有效字符用于显示
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
	/********************************算法名称居中显示*******************************/
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
	* @brief ：MUTE界面
	* @param :  
	* @param :  
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
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
	* @brief ：BYPASS界面
	* @param :  
	* @param :  
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
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
	* @brief ：omni保存界面
	* @param : patch: 当前使用的patch
	* @param : name:当前patch下的ir名
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t oSaveInterface(void)
{
	if(ocMainDis.antiFlag)
	{
		ocFontSet.textColor = 0;
	}
	/**************************************************************************/
	/*****************************显示大写的PATCH*******************************/
	/**************************************************************************/
	ocDrawPatch(ocMainDis.pXpos,ocMainDis.pYpos,HardwareParamter.PresetNum);
	ocFontSet.textColor = 1;
	ocFontSet.fontForm = acsMin;
	
	/**************************************************************************/
	/*****************************显示固定字符串********************************/
	/**************************************************************************/
	ocShowString(ocMainDis.nXpos,28,"SAVE");
	ocShowString(ocMainDis.nXpos+6,36,"TO");

	return oc_OK;
}

/**********************************************
	* @brief ：U盘格式化界面界面
	* @param : patch: 当前使用的patch
	* @param : name:当前patch下的ir名
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
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
	* @brief ：文件加载界面
	* @param : patch: 当前使用的patch
	* @param : name:当前patch下的ir名
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
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
	* @brief ：脚钉功能设置
	* @param : 
	* @param : 
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t oFsSeting(void)
{
	ocFontSet.fontForm = acsMin;
	//清除矩形显示
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
	/*****************************没有选定目标**********************************/
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
	/********************************操作方式被选定*****************************/
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
	* @brief ：预设功能设置
	* @param : 
	* @param : 
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t oPreSeting(void)
{
	ocFontSet.fontForm = acsMin;
	
	//清空显示
	OLEDClear();
	
	ocDrawFullRect(124, ocPreSet.choice * 5, 2, 9);//显示进度条
	ocDrawRect(123,0, 4, 64);//进度条外框
	
	/**************************************************************************/
	/********************************选定对象是前三个***************************/
	/**************************************************************************/
	if(ocPreSet.choice < 4)
	{
//		ocShowString(ocPreSet.cXpos,ocPreSet.cYpos,"<<<");
		
		//显示设置对象
		preFuncTab[0](ocPreSet.cXpos,ocPreSet.cYpos);
		preFuncTab[1](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig));
		preFuncTab[2](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 2));
		preFuncTab[3](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 3));
		preFuncTab[4](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 4));
		
		//目标被选择，需要反色
		if(ocPreSet.choiceEnable)
		{
			//反色控制
			ocDrawFullRect(ocPreSet.cXpos - 2,
							       ocPreSet.cYpos + (ocPreSet.yHig * (ocPreSet.choice)) - 2, 
			               123, ocPreSet.yHig);
			
			ocFontSet.textColor = 0x0;
			
			//显示调节参数
			preFuncTab[ocPreSet.choice]
			          (ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * (ocPreSet.choice)));
		}
		else//没有需要设置的参数
		{
			ocDrawRect(ocPreSet.cXpos - 2,
							   ocPreSet.cYpos + (ocPreSet.yHig * (ocPreSet.choice)) - 2, 123, ocPreSet.yHig);
		}
	}
	/**************************************************************************/
	/*******************************选定对象不是前三个**************************/
	/**************************************************************************/
	else
	{
		//显示设置对象
		preFuncTab[ocPreSet.choice-4](ocPreSet.cXpos,ocPreSet.cYpos);
		preFuncTab[ocPreSet.choice-3](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 1));
		preFuncTab[ocPreSet.choice-2](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 2));
		preFuncTab[ocPreSet.choice-1](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 3));
		preFuncTab[ocPreSet.choice](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 4));
		
		/**************************************************************************/
		/*******************************选定对象需要被设置**************************/
		/**************************************************************************/
		if(ocPreSet.choiceEnable)
		{
			//反色控制
			ocDrawFullRect(ocPreSet.cXpos - 2,
							       ocPreSet.cYpos + (ocPreSet.yHig * 4) - 2, 
			               123, ocPreSet.yHig);
			
			ocFontSet.textColor = 0x0;
			//显示调节参数
			preFuncTab[ocPreSet.choice](ocPreSet.cXpos,ocPreSet.cYpos + (ocPreSet.yHig * 4));
		}
		/**************************************************************************/
		/******************************选定对象不需要被设置*************************/
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
	* @brief ：omni二级菜单
	* @param : none
	* @param : none
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t oEditMenu(void)
{
	ocFontSet.fontForm = acsMin;
	
	ocShowString(ocEditDis.cXpos,ocEditDis.cYpos,"FS FUNCTION      >>>");
	ocShowString(ocEditDis.cXpos,ocEditDis.cYpos + ocEditDis.yHig,"EDIT PATCH       >>>");
	ocShowString(ocEditDis.cXpos,ocEditDis.cYpos + (ocEditDis.yHig * 2),"EXIT");
	ocShowString(ocEditDis.cXpos,ocEditDis.cYpos + (ocEditDis.yHig * 5),"VERSIONS        V1.01");
	
	//清除矩形框
	ocFontSet.textColor = 0x0;
	ocDrawRect(ocEditDis.cXpos - 2,
	           ocEditDis.cYpos - 2, 125, ocEditDis.yHig);
	
	ocDrawRect(ocEditDis.cXpos - 2,
	           ocEditDis.cYpos + ocEditDis.yHig - 2, 125, ocEditDis.yHig);
	
	ocDrawRect(ocEditDis.cXpos - 2,
	           ocEditDis.cYpos + (ocEditDis.yHig * 2) - 2, 125, ocEditDis.yHig);
	
	ocFontSet.textColor = 0x1;
	
	//绘制矩形选择框
	ocDrawRect(ocEditDis.cXpos - 2,
	           ocEditDis.cYpos + (ocEditDis.yHig * ocEditDis.choice) - 2, 125, ocEditDis.yHig);
	return oc_OK;
}

/**********************************************
	* @brief ：GUI基础设置初始化
	* @param : none
	* @note  ：
	* @retval: 初始化成功返回oc_OK，失败返回oc_ON
**********************************************/
static uint8_t ocSetInit(void)
{
	//用户配置信息
	ocUser.direction = HIGH_LOW_LEFT_RIGHT;
	ocUser.fastDraw = oc_Disable;
	(void)ocUser;
	
	//字体设置
	ocFontSet.fontForm = acsMin;
	ocFontSet.textColor = 0x1;
	(void)ocFontSet;
	
	//主界面配置
	ocMainDis.antiFlag = 0;
	
	ocMainDis.nNum = 5;
	ocMainDis.nXWid = 6;
	ocMainDis.nXHig = 12;
	ocMainDis.nXpos = 94;
	ocMainDis.nYpos = 6;
	
	ocMainDis.pXpos = 0;
	ocMainDis.pYpos = 0;
	
	//二级菜单配置
	ocEditDis.cXpos = 2;
	ocEditDis.cYpos = 2;
	ocEditDis.xWid = 6;
	ocEditDis.yHig = 11;
	ocEditDis.choice = 0;
	
	//脚钉功能设置
	ocFsSet.choice = 0;
	ocFsSet.choiceEnable = 0;
	ocFsSet.choiceFunc = 3;
	ocFsSet.cXpos = 2;
	ocFsSet.cYpos = 2;
	ocFsSet.xWid = 6;
	ocFsSet.yHig = 11;
	
	//预设功能设置
	ocPreSet.choice = 0;
	ocPreSet.choiceEnable = 0;
	ocPreSet.cXpos = 2;
	ocPreSet.cYpos = 2;
	ocPreSet.xWid = 6;
	ocPreSet.yHig = 11;
	
	return oc_OK;
}

/**********************************************
	* @brief ：设置字体颜色
	* @param : Color: 颜色
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocSetColor(uint32_t Color)
{
	
	return oc_OK;
}

/**********************************************
	* @brief ：在指定的位置绘制一个像素点
	* @param : Xpos: x坐标
	* @param : Ypos: y坐标
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
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
	* @brief ：输出整个屏幕的数据
	* @note  ：方便快速显示
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocDrawFull(void)
{
	
	return oc_OK;
}

/**********************************************
	* @brief ：以当前背景颜色清除整个屏幕
	* @param : Color: 颜色
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocClear(uint32_t Color)
{
	OLEDClear();
	return oc_OK;
}

/**********************************************
	* @brief ：背光控制
	* @param : onOff: 开关背光 1：打开  0：关闭
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocBackLight(uint32_t onOff)
{
	
	return oc_OK;
}

