/**********************************************
 * @author：Jun
 * @time  ：2018/8/1
 * @brief ：实现具体功能
 * @note  ：实现GUI与用户层交互
**********************************************/
#ifndef _OCUSER_H_
#define _OCUSER_H_

#include "ocConfig.h"

//屏幕刷写方向
#define HIGH_LOW_LEFT_RIGHT 0//从上到下从左到右
#define HIGH_LOW_RIGHT_LEFT 1//从上到下从右到左
#define LOW_HIGH_LEFT_RIGHT 2//从下到上从左到右
#define LOW_HIGH_RIGHT_LEFT 3//从下到上从右到左
#define LEFT_RIGHT_HIGH_LOW 4//从左到右从上到下
#define LEFT_RIGHT_LOW_HIGH 5//从左到右从下到上
#define RIGHT_LEFT_HIGH_LOW 6//从右到左从上到下
#define RIGHT_LEFT_LOW_HIGH 7//从右到左从下到上

#define OCCLEAR_COLOR 0

//打点函数包含颜色信息
#define INCCOLORINFO 1

//二级菜单选择项
#define FS_FUNCTION 0
#define EDIT_PATCH  1
#define EXIT        2

//踩钉功能设置
#define FS_TAP   0
#define FS_HOLD  1

#define FS_BYPASS    0
#define FS_MUTE      1
#define FS_PATCHADD  2
#define FS_PATCHSUB  3
#define FS_EQ_ONOFF  4

#define SAVEPAGE  10

//用户配置信息
typedef struct
{
	uint8_t direction;
	uint8_t fastDraw;
}ocUser_t;

//主界面配置
typedef struct
{
	uint8_t antiFlag;//主界面反色控制
	
	uint8_t pXpos;//patch显示X轴起始位置
	uint8_t pYpos;//patch显示Y轴起始位置
	
	uint8_t nNum;//name一行显示字符数量
	uint8_t nXWid;//name单个字符占的宽度
	uint8_t nXHig;//name单个字符占的高度
	uint8_t nXpos;//name显示X轴起始位置
	uint8_t nYpos;//name显示Y轴起始位置
}ocMainDis_t;

//二级菜单配置
typedef struct
{
	uint8_t choice;//当前选中的对象
	
	uint8_t cXpos;//首字X轴位置
	uint8_t cYpos;//首字Y轴位置
	uint8_t xWid;//单个字符所占宽度
	uint8_t yHig;//单个字符所占高度
}ocEditDis_t;

//踩钉功能设置
typedef struct
{
	uint8_t choice;//当前选中的对象
	uint8_t choiceEnable;//当前选中的对象需要被设置
	uint8_t choiceFunc;//当前选中的功能
	
	uint8_t cXpos;//首字X轴位置
	uint8_t cYpos;//首字Y轴位置
	uint8_t xWid;//单个字符所占宽度
	uint8_t yHig;//单个字符所占高度
}ocFsSet_t;

//预设功能设置
typedef struct
{
	uint8_t choice;//当前选中的对象
	uint8_t choiceEnable;//当前选中的对象需要被设置

	uint8_t cXpos;//首字X轴位置
	uint8_t cYpos;//首字Y轴位置
	uint8_t xWid;//单个字符所占宽度
	uint8_t yHig;//单个字符所占高度
}ocPreSet_t;

extern ocFsSet_t ocFsSet;
extern ocEditDis_t ocEditDis;
extern ocMainDis_t ocMainDis;
extern ocPreSet_t ocPreSet;

/**********************************************
 * @brief ：GUI初始化
 * @param : none
 * @note  ：
 * @retval: 初始化成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocGuiInit(void);
	
/**********************************************
 * @brief ：在指定的位置绘制一个像素点
 * @param : Xpos: x坐标
 * @param : Ypos: y坐标
 * @note  ：初始化成功返回oc_OK，失败返回oc_ON
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
#if INCCOLORINFO
uint8_t ocPutDot(uint16_t Xpos, uint16_t Ypos, uint32_t color);
#else
uint8_t ocPutDot(uint16_t Xpos, uint16_t Ypos);
#endif

/**********************************************
 * @brief ：设置字体颜色
 * @param : Color: 颜色
 * @note  ：none
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocSetColor(uint32_t Color);

/**********************************************
 * @brief ：以当前背景颜色清除整个屏幕
 * @param : Color: 颜色
 * @note  ：none
 * @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t ocClear(uint32_t Color);

/**********************************************
	* @brief ：omni主菜单
	* @param : patch: 当前使用的patch
	* @param : name:当前patch下的ir名
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t oMainMenu(void);
/**********************************************
	* @brief ：MUTE界面
	* @param :  
	* @param :  
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t onMUTEMenu(void);
/**********************************************
	* @brief ：BYPASS界面
	* @param : patch: 当前使用的patch
	* @param : name:当前patch下的ir名
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t onBYPASSMenu(void);
/**********************************************
	* @brief ：omni二级菜单
	* @param : patch: 当前使用的patch
	* @param : name:当前patch下的ir名
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t oEditMenu(void);

/**********************************************
	* @brief ：预设功能设置
	* @param : 
	* @param : 
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t oPreSeting(void);

/**********************************************
	* @brief ：脚钉功能设置
	* @param : 
	* @param : 
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t oFsSeting(void);

/**********************************************
	* @brief ：omni保存界面
	* @param : patch: 当前使用的patch
	* @param : name:当前patch下的ir名
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t oSaveInterface(void);
/**********************************************
	* @brief ：U盘格式化界面
	* @param : patch: 当前使用的patch
	* @param : name:当前patch下的ir名
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t oFileWarning(void);
/**********************************************
	* @brief ：文件加载界面
	* @param : patch: 当前使用的patch
	* @param : name:当前patch下的ir名
	* @note  ：none
	* @retval: 绘制成功返回oc_OK，失败返回oc_ON
**********************************************/
uint8_t oFileLoad(void);


#endif

