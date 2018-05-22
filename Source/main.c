#include <STC15F2K60S2.H>
/* BLINKY.C - LED Flasher for the Keil MCBx51 Evaluation Board with 80C51 device*/
                  
#include <REG51F.H>


///////////////////////////////////////////////////////
// ISP Setting:
// Input IRC frequency : 18.432MHZ
///////////////////////////////////////////////////////



// When you have enabled the option Stop Program Execution with Serial
// Interrupt, the Monitor-51 uses the serial interrupt of the UART.
// It is therefore required to reserve the memory locations for the interrupt
// vector.  You can do this by adding one of the following code lines:

// char code reserve [3] _at_ 0x23;   // when using on-chip UART for communication
// char code reserve [3] _at_  0x3;   // when using off-chip UART for communication
void Wait_ms(int ms);

void wait (void)  {                   /* wait function */
  ;                                   /* only to delay for LED flashes */
}

void main (void)  {
  unsigned int i, cycle;                     /* Delay var */
  unsigned char j;                    /* LED var */
	int num_of_round=4;
	//int Gear_Ratio=64;
	//float Step_angle=11.25;
	// One revolution CCW using full step mode
	for (cycle = 0; cycle < 372*num_of_round; cycle++)
	{
			P0=0x13;
			Wait_ms(4);
			P0=0x26;
			Wait_ms(4);
			P0=0x4C;
			Wait_ms(4);
			P0=0x89;
			Wait_ms(4);
	}
}

void Wait_ms(int ms)
{
  unsigned int De_Cnt;
  while( (ms--) != 0)
  {
    for(De_Cnt = 0; De_Cnt < 600; De_Cnt++); 
  }  	
}
