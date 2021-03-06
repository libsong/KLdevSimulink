/*
  *
  *   --- THIS FILE GENERATED BY S-FUNCTION BUILDER: 3.0 ---
  *
  *   This file is a wrapper S-function produced by the S-Function
  *   Builder which only recognizes certain fields.  Changes made
  *   outside these fields will be lost the next time the block is
  *   used to load, edit, and resave this file. This file will be overwritten
  *   by the S-function Builder block. If you want to edit this file by hand, 
  *   you must change it only in the area defined as:  
  *
  *        %%%-SFUNWIZ_wrapper_XXXXX_Changes_BEGIN 
  *            Your Changes go here
  *        %%%-SFUNWIZ_wrapper_XXXXXX_Changes_END
  *
  *   For better compatibility with the Simulink Coder, the
  *   "wrapper" S-function technique is used.  This is discussed
  *   in the Simulink Coder User's Manual in the Chapter titled,
  *   "Wrapper S-functions".
  *
  *   Created: Wed Aug 15 09:09:41 2018
  */


/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

#include <math.h>

uint8_T g_preHvsdata[128] = { 0 };

void HvsFormatData(uint8_T *relay, uint8_T *data);

void kl_device_ctldata_format_sfun_Start_wrapper(const real_T *u0,
                          const real_T *u1,
                          const real_T *u2,
                          const real_T *u3,
                          real_T *y0,
                          real_T *y1,
                          real_T *y2,
                          real_T *y3  , 
                          const real_T  *dev_type, const int_T  p_width0, 
                          const real_T  *p0, const int_T  p_width1, 
                          const real_T  *p1, const int_T  p_width2, 
                          const real_T  *p2, const int_T  p_width3, 
                          const real_T  *p3, const int_T  p_width4, 
                          const real_T  *p4,  const int_T p_width5,
			     const int_T y_width, const int_T u_width)
{

}

void kl_device_ctldata_format_sfun_Outputs_wrapper(const real_T *u0,
                          const real_T *u1,
                          const real_T *u2,
                          const real_T *u3,
                          real_T *y0,
                          real_T *y1,
                          real_T *y2,
                          real_T *y3  , 
                          const real_T  *dev_type, const int_T  p_width0, 
                          const real_T  *p0, const int_T  p_width1, 
                          const real_T  *p1, const int_T  p_width2, 
                          const real_T  *p2, const int_T  p_width3, 
                          const real_T  *p3, const int_T  p_width4, 
                          const real_T  *p4,  const int_T p_width5,
			     const int_T y_width, const int_T u_width)
{
	int type = (int)*dev_type;
	int i, datachange = 0;
	uint8_T tmp[128] = { 0 };
	
	if (type == 1) {
		for (i = 0; i < 128; i++) {
			if ((uint8_T)u0[i] - g_preHvsdata[i] != 0) {
				g_preHvsdata[i] = (uint8_T)u0[i];
				datachange = 1;
			}			
		}
		if (datachange == 1) {
			HvsFormatData(g_preHvsdata, tmp);
		}
		
		for (i = 0; i < 38; i++)
		{
			y0[i] = tmp[i] * 1.0;
		}
	}
}

void kl_device_ctldata_format_sfun_Terminate_wrapper(const real_T *u0,
                          const real_T *u1,
                          const real_T *u2,
                          const real_T *u3,
                          real_T *y0,
                          real_T *y1,
                          real_T *y2,
                          real_T *y3  , 
                          const real_T  *dev_type, const int_T  p_width0, 
                          const real_T  *p0, const int_T  p_width1, 
                          const real_T  *p1, const int_T  p_width2, 
                          const real_T  *p2, const int_T  p_width3, 
                          const real_T  *p3, const int_T  p_width4, 
                          const real_T  *p4,  const int_T p_width5,
			     const int_T y_width, const int_T u_width)
{

}

void HvsFormatData(uint8_T *relay,uint8_T *data)
{
	uint8_T relay_data[128] = {0};
	int i,j;
	int resZ = (int)relay[20];
	int resF = (int)relay[21];	
	
	for (i=0;i<8;i++) {
		relay_data[i] = 0xbe;
	}
	
	relay_data[8] = 0x01;
	relay_data[9] = 0xb;//len
	
	if (relay[0] == 1) {	//relay2
		relay_data[10] |= (1<<1);
	}
	if (relay[1] == 1) {	//relay3
		relay_data[10] |= (1 << 2);
	}
	if (relay[2] == 1) {	//relay5
		relay_data[10] |= (1 << 4);
	}
	if (relay[3] == 1) {	//relay8
		relay_data[10] |= (1 << 7);
	}
	if (relay[4] == 1) {	//relay11
		relay_data[11] |= (1 << 2);
	}
	if (relay[5] == 1) {	//relay18
		relay_data[12] |= (1 << 1);
	}
	if (relay[6] == 1) {	//relay19
		relay_data[12] |= (1<<2);
	}
	if (relay[7] == 1) {	//relay20
		relay_data[12] |= (1<<3);
	}
	if (relay[8] == 1) {	//relay21
		relay_data[12] |= (1<<4);
	}
	if (relay[9] == 1) {	//relay22
		relay_data[12] |= (1<<5);
	}
	if (relay[10] == 1) {	//relay23
		relay_data[12] |= (1<<6);
	}
	if (relay[11] == 1) {	//relay24
		relay_data[12] |= (1<<7);
	}
	if (relay[12] == 1) {	//relay25
		relay_data[13] |= (1<<0);
	}
	if (relay[13] == 1) {	//relay26
		relay_data[13] |= (1<<1);
	}
	if (relay[14] == 1) {	//relay28
		relay_data[13] |= (1<<3);
	}
	if (relay[15] == 1) {	//relay30
		relay_data[13] |= (1<<5);
	}
	if (relay[16] == 1) {	//relay32
		relay_data[13] |= (1<<7);
	}
	if (relay[17] == 1) {	//relay34
		relay_data[14] |= (1<<1);
	}
	if (relay[18] == 1) {	//relay36
		relay_data[14] |= (1<<3);
	}
	if (relay[19] == 1) {	//relay87
		relay_data[20] |= (1<<6);
	}
	
	if (resZ == 0)
	{
		relay_data[14]  &= ~(1 << 5); //relay38 主正总开关
	}
	if (resZ >150)
	{
		relay_data[14] |= (1 << 5);
		resZ = resZ - 150;
		resZ = resZ / 100;
		resZ = ~resZ;
	}
	if (resZ & 0x1)
	{
		relay_data[14] = relay_data[14] | (1 << 6);
	}
	if ((resZ >> 1) & 0x1)
	{
		relay_data[14] = relay_data[14] | (1 << 7);
	}

	for ( j = 0; j < 8; j++)
	{
		if ((resZ >> (j+2)) & 0x1)
		{
			relay_data[15] = relay_data[15] | (1 << j);
		}
	}
	for ( j = 0; j < 8; j++)
	{
		if ((resZ >> (j + 10)) & 0x1)
		{
			relay_data[16] = relay_data[16] | (1 << j);
		}
	}
	if ((resZ >> 18) & 0x1)
	{
		relay_data[17] = relay_data[17] | 1;
	}
	
	if (resF == 0)
	{
		relay_data[17] &= ~(1 << 1); //relay58 主负总开关
	} 
	if (resF > 150)
	{
		relay_data[17] |= (1 << 1); //relay58 主负总开关
		resF = resF - 150;
		resF = resF / 100;
		resF = ~resF;
	}
	for ( j = 0; j < 6; j++)
	{
		if ((resF >> j) & 0x1)
		{
			relay_data[17] = relay_data[17] | (1 << (j+2));
		}
	}
	for ( j = 6; j < 14; j++)
	{
		if ((resF >> j) & 0x1)
		{
			relay_data[18] = relay_data[18] | (1 << (j -6));
		}
	}
	for ( j = 14; j < 19; j++)
	{
		if ((resF >> j) & 0x1)
		{
			relay_data[19] = relay_data[19] | (1 << (j - 14));
		}
	}
	
	for (i=0;i<11;i++) {
		relay_data[21] += relay_data[i+10];
	}
	
	for ( i = 22; i < 30; i++)
	{
		relay_data[i] = 0xff;
	}
	for ( i = 30; i < 38; i++)
	{
		relay_data[i] = 0xed;
	}
	
	for (i=0;i<38;i++) {
		data[i] += relay_data[i];
	}
		
	return ;
}




