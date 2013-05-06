#include "system.h"
#define PIC0_ICW1		0x0020
#define PIC0_OCW2		0x0020
#define PIC0_IMR		0x0021
#define PIC0_ICW2		0x0021
#define PIC0_ICW3		0x0021
#define PIC0_ICW4		0x0021
#define PIC1_ICW1		0x00a0
#define PIC1_OCW2		0x00a0
#define PIC1_IMR		0x00a1
#define PIC1_ICW2		0x00a1
#define PIC1_ICW3		0x00a1
#define PIC1_ICW4		0x00a1


void init_pic(void)
{
	io_out8(PIC0_IMR,  0xff  );//������pic�ж�
	io_out8(PIC1_IMR,  0xff  ); //���ô�pic�ж�

	io_out8(PIC0_ICW1, 0x11  ); //���ش���ģʽ
	io_out8(PIC0_ICW2, 0x20  ); //irq0-7��0x20-0x27����
	io_out8(PIC0_ICW3, 1 << 2); //pic1��IRQ2����
	io_out8(PIC0_ICW4, 0x01  ); //�޻�����ģʽ

	io_out8(PIC1_ICW1, 0x11  ); //���ش���ģʽ
	io_out8(PIC1_ICW2, 0x28  ); //IRQ����
	io_out8(PIC1_ICW3, 2     ); //pic1��IRQ2����
	io_out8(PIC1_ICW4, 0x01  ); //

	io_out8(PIC0_IMR,  0xfb  ); //pic1�����ȫ����ֹ
	io_out8(PIC1_IMR,  0xff  ); //ȫ����ֹ

	return;
}


void inthandler27(int *esp)
{
	io_out8(PIC0_OCW2, 0x67); 
	return;
}