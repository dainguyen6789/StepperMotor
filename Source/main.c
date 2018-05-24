#include <STC15F2K60S2.H>
/* BLINKY.C - LED Flasher for the Keil MCBx51 Evaluation Board with 80C51 device*/
                  
#include <REG51F.H>
// Input IRX Frequency : 11.0592Mhz
// Work with Motor VGSM3155, VGSM2436
// uC can control by both 4-low bit and 4-high bit of PORT0.
// When you have enabled the option Stop Program Execution with Serial
// Interrupt, the Monitor-51 uses the serial interrupt of the UART.
// It is therefore required to reserve the memory locations for the interrupt
// vector.  You can do this by adding one of the following code lines:

// char code reserve [3] _at_ 0x23;   // when using on-chip UART for communication
// char code reserve [3] _at_  0x3;   // when using off-chip UART for communication

void wait (void)  {                   /* wait function */
  ;                                   /* only to delay for LED flashes */
}
void IO_Init(void);

void main (void)  {
  unsigned int i, cycle;                     /* Delay var */
  unsigned char j;                    /* LED var */
	IO_Init();
	// One revolution CCW using full step mode
	//for (cycle = 0; cycle < 512*4; cycle++)
	while(1)
	{
			P2=0x31;
			for (i = 0; i < 16000; i++)  {  /* Delay for 10000 Counts */
				wait ();                       /* call wait function */
      }
			
			P2=0x62;
			for (i = 0; i < 16000; i++)  {  /* Delay for 10000 Counts */
				wait ();                       /* call wait function */
      }
			P2=0xC4;
			for (i = 0; i < 16000; i++)  {  /* Delay for 10000 Counts */
				wait ();                      /* call wait function */
      }
			P2=0x98;
			for (i = 0; i < 16000; i++)  {  /* Delay for 10000 Counts */
				wait ();                       /* call wait function */
      }
	}
}

void IO_Init(void)
{	
	//Set P1.0 is input only.
	P2M1 =0x00;  
	P2M0 =0xFF;    
}
