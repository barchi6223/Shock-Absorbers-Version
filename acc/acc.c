// PROGRAM	: 2-4.c								2014.0101
// FUNCTION	: STM PWM Servo Control with 		By Steven
#include <HT66F70A.h>
#define	 SW_DutyUpPU	_pepu6		//PEPU.6
#define	 SW_DutyUp		_pe6		//PE.6
#define	 SW_DutyUpC		_pec6		//PEC.6
#define	 SW_DutyDnPU	_pepu7		//PEPU.7
#define	 SW_DutyDn		_pe7		//PE.7
#define	 SW_DutyDnC		_pec7		//PEC.7
typedef	unsigned char	u8;
typedef	char			s8;
typedef	unsigned short	u16;
typedef	short			s16;
typedef	unsigned long	u32;
typedef	long			s32;
u8 *ptr,ScanCode,Buffer[4];	
void Delay100us(u16);							//�禡�쫬�ŧi		 
void main()
{	s16 temp,Index=100;
	_wdtc=0b10101111;							//�����ݭ̪��p�ɾ�
	SW_DutyUpC=1; SW_DutyUpPU=1;			   	//�W������}�쬰��J�ݩʨñҥδ��ɹq��
	SW_DutyDnC=1; SW_DutyDnPU=1;		   	
	_psc0=0x01; _tbc0=0x85;_tb0e=1;				//fTB=fSYS/4,�g��=8192*fTB,�P��TB0���_	
	_pcs1=0x10; _pcs2=0x01;						//�]�wPC3/PC4��TP2�\��
	_tm2c0=0b00000000;							//fINT=fSYS(8MHz)/4 (0.5us)
	_tm2c1=0b10101000;							//PWM/Active High/TM2R����g��
	_tm2rp=160;									//�g��=256*160*0.5us=20.48ms
	_t2on=1; _emi=1;							//�_�lTM1�p�ƨíP��EMI
	while(1)
	{	temp=Index*20+500;						//�ഫ�����Ť�Ѽ�
		_tm2al=temp%256;						//�]�w���Ť�Ѽ�
		_tm2ah=temp/256;					
		temp>>=1;								//�ഫ��Ton�ɶ�
		Delay100us(12);						//����120ms
		while(1)
		{	if(!SW_DutyUp)
			{	Index=200;		//�Y���U���W��,���л��W(�W��200) 
				break;   	
			}
			if(!SW_DutyDn) 						//�Y���U������,���л���(�U��0) 
			{	Index=0;
				break;   	
			}
		}
	}
}
void Delay100us(u16 del)						//����del*200���O�g��
{	u16 i,j;									//@fSYS=8MH,����del*100us



	for(i=0;i<del;i++)
		for(j=0;j<=25;j++) GCC_NOP();
}