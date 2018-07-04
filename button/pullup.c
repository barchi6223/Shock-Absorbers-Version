#include <HT66F70A.h>
#define		SEG_Port	_pc			//PC
#define		SEG_PortC	_pcc		//PCC
#define		SW0		   	_pe0		//PE0
#define		SW0C		_pec0		//PEC0
#define		SW0PU		_pepu0		//PEPU0
typedef	unsigned char	u8;
typedef	char			s8;
typedef	unsigned short	u16;
typedef	short			s16;
typedef	unsigned long	u32;
typedef	long			s32;
const u8 SEG_TAB[] = { 							//�C�q��ܾ���ܽX(�@��)
				0x3F,0x06,0x5B,0x4F,0x66,
				0x6D,0x7D,0x07,0x7F,0x67};
void Delay100us(u16);							//�禡�쫬�ŧi
void main()
{	u8 i=0;
	_wdtc=0b10101111;							//�����ݭ̪��p�ɾ�
	SEG_PortC=0x00;								//�W��SEG_Port����X�Ҧ�
	SW0C=1; SW0PU=1;                      		//�W��SW0���}����J�ñҥδ��ɹq��
	while(1)
	{	SEG_Port=SEG_TAB[i++];					//�d��
		wait:
		while(SW0);						        //���ݫ��U����
		Delay100us(1200);						//���� 120 mSec
		if(SW0) goto wait; 		            	//�P�_�u���O�_����
		if(i>9) i=0;							//�Y�w��ܦ�9�h����i�k�s
	}
}
void Delay100us(u16 del)						//����del*200���O�g��
{	u16 i,j;									//@fSYS=8MH,����del*100us
	for(i=0;i<del;i++)
		for(j=0;j<=25;j++) GCC_NOP();
}