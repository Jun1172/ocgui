/**********************************************
	* @author: Jun
	* @time  : 2018/8/1
	* @brief �����ص����
	* @note  ��none
**********************************************/
#include "ocPixel.h"

/**********************************************
 * @brief ����ָ�����򣬻�һ���ض����ȵ�ֱ��
 * @param : Xpos:      ֱ������x����
 * @param : Ypos:      ֱ������y����
 * @param : Length:    ֱ�ߵĳ���
 * @param : Direction: ֱ�ߵķ��򣬴������һ��������
 * @note  ��none
 * @retval: ���Ƴɹ�����oc_OK��ʧ�ܷ���oc_ON
**********************************************/
uint8_t ocDrawLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint8_t Direction)
{
	uint16_t drawLength;
	if(Direction == OC_VERTICAL )
	{
		for(drawLength = 0;drawLength < Length;drawLength ++)
		{
			#if INCCOLORINFO
				ocPutDot(Xpos,Ypos+drawLength,ocFontSet.textColor);
			#else
				ocPutDot(Xpos,Ypos);
			#endif
		}
	}
	else if(Direction == OC_HORIZONTAL )
	{
		for(drawLength = 0;drawLength < Length;drawLength ++)
		{
			#if INCCOLORINFO
				ocPutDot(Xpos+drawLength,Ypos,ocFontSet.textColor);
			#else
				ocPutDot(Xpos,Ypos);
			#endif
		}
	}
	
	return oc_OK;
}

/**********************************************
	* @brief  : ʹ�� Bresenham �㷨���߶Σ��������㣩 
	* @param  : Xpos1 ���߶ε�һ���˵�X����
	* @param  : Ypos1 ���߶ε�һ���˵�Y����
	* @param  : Xpos2 ���߶ε���һ���˵�X����
	* @param  : Ypos2 ���߶ε���һ���˵�Y����
	* @note   :
	* @retval : ��
**********************************************/
void ocDrawUniLine ( uint16_t Xpos1, uint16_t Ypos1, uint16_t Xpos2, uint16_t Ypos2 )
{
	uint16_t us; 
	uint16_t usX_Current, usY_Current;
	
	int32_t lError_X = 0, lError_Y = 0, lDelta_X, lDelta_Y, lDistance; 
	int32_t lIncrease_X, lIncrease_Y; 	
	
	
	lDelta_X = Xpos2 - Xpos1; //������������ 
	lDelta_Y = Ypos2 - Ypos1; 
	
	usX_Current = Xpos1; 
	usY_Current = Ypos1; 
	
	
	if ( lDelta_X > 0 ) 
		lIncrease_X = 1; //���õ������� 
	else if ( lDelta_X == 0 ) 
		lIncrease_X = 0;//��ֱ�� 
	else 
  { 
    lIncrease_X = -1;
    lDelta_X = - lDelta_X;
  } 

	
	if ( lDelta_Y > 0 )
		lIncrease_Y = 1; 
	else if ( lDelta_Y == 0 )
		lIncrease_Y = 0;//ˮƽ�� 
	else 
  {
    lIncrease_Y = -1;
    lDelta_Y = - lDelta_Y;
  } 

	
	if (  lDelta_X > lDelta_Y )
		lDistance = lDelta_X; //ѡȡ�������������� 
	else 
		lDistance = lDelta_Y; 

	for ( us = 0; us <= lDistance + 1; us ++ )//������� 
	{  
		#if INCCOLORINFO
			ocPutDot ( usX_Current, usY_Current,ocFontSet.textColor);
		#else
			ocPutDot ( usX_Current, usY_Current );//���� 
		#endif
		
		
		lError_X += lDelta_X ; 
		lError_Y += lDelta_Y ; 
		
		if ( lError_X > lDistance ) 
		{ 
			lError_X -= lDistance; 
			usX_Current += lIncrease_X; 
		}  
		
		if ( lError_Y > lDistance ) 
		{ 
			lError_Y -= lDistance; 
			usY_Current += lIncrease_Y; 
		} 
	}  	
}   

/**********************************************
	* @brief  :���ƿ��ľ���
	* @param  :Xpos ���������ϽǶ˵�X����
	* @param  :Ypos ���������ϽǶ˵�Y����
	* @param  :Width �����ο�
	* @param  :Height �����θ�
	* @note :
	* @retval :��
**********************************************/
void ocDrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height)
{  
  uint16_t realHeight,realWidth;
  
  realHeight = OC_LCD_HEIGHT-Ypos-Height > 0 ? Height : OC_LCD_HEIGHT - Ypos;
  realWidth = OC_LCD_WIDTH-Xpos-Width > 0 ? Width : OC_LCD_WIDTH - Xpos;
  
  ocDrawLine(Xpos, Ypos, realWidth, OC_HORIZONTAL);
  ocDrawLine(Xpos, Ypos, realHeight, OC_VERTICAL);
  ocDrawLine(Xpos + realWidth - 1, Ypos, realHeight, OC_VERTICAL);
  ocDrawLine(Xpos, Ypos + realHeight - 1, realWidth, OC_HORIZONTAL);
}

/**********************************************
	* @brief  :����ʵ�ľ���
	* @param  :Xpos ���������ϽǶ˵�X����
	* @param  :Ypos ���������ϽǶ˵�Y����
	* @param  :Width �����ο�
	* @param  :Height �����θ�
	* @note :
	* @retval :��
**********************************************/
void ocDrawFullRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height)
{  
  uint16_t realHeight,realWidth;
	uint16_t i;
  
  realHeight = OC_LCD_HEIGHT-Ypos-Height > 0 ? Height : OC_LCD_HEIGHT - Ypos;
  realWidth = OC_LCD_WIDTH-Xpos-Width > 0 ? Width : OC_LCD_WIDTH - Xpos;
  
  ocDrawLine(Xpos, Ypos, realWidth, OC_HORIZONTAL);
  ocDrawLine(Xpos, Ypos, realHeight, OC_VERTICAL);
  ocDrawLine(Xpos + realWidth - 1, Ypos, realHeight, OC_VERTICAL);
  ocDrawLine(Xpos, Ypos + realHeight - 1, realWidth, OC_HORIZONTAL);
	
	for(i = 0;i < realHeight;i++)
	{
		ocDrawLine(Xpos, Ypos + i, realWidth, OC_HORIZONTAL);
	}
}

/**********************************************
	* @brief  :���ƿ���Բ
	* @param  :Xpos �����ĵ�X����
	* @param  :Ypos �����ĵ�Y����
	* @param  :Radius ��Բ�ΰ뾶
	* @note :
	* @retval :��
**********************************************/
void ocDrawCircle(uint16_t Xpos,uint16_t Ypos,uint16_t Radius)
{
	int16_t mx=Xpos,my=Ypos,x=0,y=Radius;
	int16_t d=1-Radius;
	while(y>x)
	{
		#if INCCOLORINFO
			ocPutDot(x+mx,y+my,ocFontSet.textColor);
			ocPutDot(-x+mx,y+my,ocFontSet.textColor);
			ocPutDot(-x+mx,-y+my,ocFontSet.textColor);
			ocPutDot(x+mx,-y+my,ocFontSet.textColor);
			ocPutDot(y+mx,x+my,ocFontSet.textColor);
			ocPutDot(-y+mx,x+my,ocFontSet.textColor);
			ocPutDot(y+mx,-x+my,ocFontSet.textColor);
			ocPutDot(-y+mx,-x+my,ocFontSet.textColor);
		#else
			ocPutDot(x+mx,y+my);
			ocPutDot(-x+mx,y+my);
			ocPutDot(-x+mx,-y+my);
			ocPutDot(x+mx,-y+my);
			ocPutDot(y+mx,x+my);
			ocPutDot(-y+mx,x+my);
			ocPutDot(y+mx,-x+my);
			ocPutDot(-y+mx,-x+my);
		#endif
		
		if(d<0)
		{
			d += 2*x+3;
		}
		else
		{
			d += 2*(x-y)+5;
			y--;
		}
		x++;
	}
}

/**********************************************
	* @brief  :����һ��ʵ��Բ
	* @param  :Xpos: Բ��X����
	* @param  :Ypos: Բ��Y����
	* @param  ��Radius: �뾶
	* @retval ��None
**********************************************/
void ocDrawFullCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius)
{  
  /* ����ʵ��Բ��Ҫ���ӵĲ��� */
   int32_t  D;    /* Decision Variable */
   uint32_t  CurX;/* Current X Value */
   uint32_t  CurY;/* Current Y Value */

   D = 3 - (Radius << 1);

   CurX = 0;
   CurY = Radius;

   while (CurX <= CurY)
   {
     if(CurY > 0)
     {
       ocDrawLine(Xpos - CurX, Ypos - CurY, 2*CurY, OC_VERTICAL);
       ocDrawLine(Xpos + CurX, Ypos - CurY, 2*CurY, OC_VERTICAL);
     }

     if(CurX > 0)
     {
       ocDrawLine(Xpos - CurY, Ypos - CurX, 2*CurX, OC_VERTICAL);
       ocDrawLine(Xpos + CurY, Ypos - CurX, 2*CurX, OC_VERTICAL);
     }
     if (D < 0)
     {
       D += (CurX << 2) + 6;
     }
     else
     {
       D += ((CurX - CurY) << 2) + 10;
       CurY--;
     }
     CurX++; 
    }
 
   ocDrawCircle(Xpos, Ypos, Radius);

}

/**********************************************
	* @brief  :���ƿ���������
	* @param  :aXpos ��a��x����
	* @param  :aYpos ��a��y����
	* @param  :bXpos ��b��x����
	* @param  :bYpos ��b��y����
	* @param  :cXpos ��c��x����
	* @param  :cYpos ��c��y����
	* @note :
	* @retval :��
**********************************************/
void ocDrawTriangle(uint16_t aXpos,uint16_t aYpos,uint16_t bXpos,uint16_t bYpos,uint16_t cXpos,uint16_t cYpos)
{
	ocDrawUniLine ( aXpos, aYpos, bXpos, bYpos);
	ocDrawUniLine ( bXpos, bYpos, cXpos, cYpos);
	ocDrawUniLine ( cXpos, cYpos, aXpos, aYpos);
}

/**********************************************
	* @brief  :����ʵ��������
	* @param  :aXpos ��a��x����
	* @param  :aYpos ��a��y����
	* @param  :bXpos ��b��x����
	* @param  :bYpos ��b��y����
	* @param  :cXpos ��c��x����
	* @param  :cYpos ��c��y����
	* @note :
	* @retval :��
**********************************************/
void ocDrawFullTriangle(uint16_t aXpos,uint16_t aYpos,uint16_t bXpos,uint16_t bYpos,uint16_t cXpos,uint16_t cYpos)
{
	ocDrawUniLine ( aXpos, aYpos, bXpos, bYpos);
	ocDrawUniLine ( bXpos, bYpos, cXpos, cYpos);
	ocDrawUniLine ( cXpos, cYpos, aXpos, aYpos);
	
	
}

/**********************************************
	* @brief  : ʹ�� Bresenham �㷨����Բ
	* @param  : Xpos1 ���߶ε�һ���˵�X����
	* @param  : Ypos1 ���߶ε�һ���˵�Y����
	* @param  : Xpos2 ���߶ε���һ���˵�X����
	* @param  : Ypos2 ���߶ε���һ���˵�Y����
	* @note  
	* @retval : ��
**********************************************/
void ocDrawEllipse (int xRadius, int yRadius, int Xpos, int Ypos)
{
	int x,y;
	float d1,d2;
	x = 0;y = yRadius;
	d1=yRadius*yRadius+xRadius*xRadius*(-yRadius+0.25);

	#if INCCOLORINFO
		ocPutDot(Xpos+x,Ypos+y,ocFontSet.textColor);
		ocPutDot(Xpos-x,Ypos-y,ocFontSet.textColor);
		ocPutDot(Xpos-x,Ypos+y,ocFontSet.textColor);
		ocPutDot(Xpos+x,Ypos-y,ocFontSet.textColor);
	#else
		ocPutDot(Xpos+x,Ypos+y);
		ocPutDot(Xpos-x,Ypos-y);
		ocPutDot(Xpos-x,Ypos+y);
		ocPutDot(Xpos+x,Ypos-y);
	#endif
	

  while(yRadius*yRadius*(x+1) < xRadius*xRadius*(y-0.5))
	{
		if(d1<=0)
		{
			d1+=yRadius*yRadius*(2*x+3);
			x++;
		}
		else
		{
			d1+=yRadius*yRadius*(2*x+3)+xRadius*xRadius*(-2*y+2);
			x++;
			y--;
		}
		#if INCCOLORINFO
			ocPutDot(Xpos+x,Ypos+y,ocFontSet.textColor);
			ocPutDot(Xpos-x,Ypos-y,ocFontSet.textColor);
			ocPutDot(Xpos-x,Ypos+y,ocFontSet.textColor);
			ocPutDot(Xpos+x,Ypos-y,ocFontSet.textColor);
		#else
			ocPutDot(Xpos+x,Ypos+y);
			ocPutDot(Xpos-x,Ypos-y);
			ocPutDot(Xpos-x,Ypos+y);
			ocPutDot(Xpos+x,Ypos-y);
		#endif
  }//while�ϰ벿��
  d2=yRadius*yRadius*(x+0.5)*(x+0.5)+xRadius*xRadius*(y-1)*(y-1)-xRadius*xRadius*yRadius*yRadius;
	while(y>0)
	{
		if(d2<=0)
		{
			d2+=yRadius*yRadius*(2*x+2)+xRadius*xRadius*(-2*y+3);
			x++,y--;
		}
		else
		{
			d2+=xRadius*xRadius*(-2*y+3);
			y--;
		}
    #if INCCOLORINFO
			ocPutDot(Xpos+x,Ypos+y,ocFontSet.textColor);
			ocPutDot(Xpos-x,Ypos-y,ocFontSet.textColor);
			ocPutDot(Xpos-x,Ypos+y,ocFontSet.textColor);
			ocPutDot(Xpos+x,Ypos-y,ocFontSet.textColor);
		#else
			ocPutDot(Xpos+x,Ypos+y);
			ocPutDot(Xpos-x,Ypos-y);
			ocPutDot(Xpos-x,Ypos+y);
			ocPutDot(Xpos+x,Ypos-y);
		#endif
  }
}

