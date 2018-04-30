#include <STC15F2K60S2.H>
/* BLINKY.C - LED Flasher for the Keil MCBx51 Evaluation Board with 80C51 device*/
                  
#include <REG51F.H>

// When you have enabled the option Stop Program Execution with Serial
// Interrupt, the Monitor-51 uses the serial interrupt of the UART.
// It is therefore required to reserve the memory locations for the interrupt
// vector.  You can do this by adding one of the following code lines:

// char code reserve [3] _at_ 0x23;   // when using on-chip UART for communication
// char code reserve [3] _at_  0x3;   // when using off-chip UART for communication

void wait (void)  {                   /* wait function */
  ;                                   /* only to delay for LED flashes */
}

void main (void)  {
  unsigned int i, cycle;                     /* Delay var */
  unsigned char j;                    /* LED var */
	
	// One revolution CCW using full step mode
	for (cycle = 0; cycle < 512*4; cycle++)
	{
			P0=0x13;
			for (i = 0; i < 2000; i++)  {  /* Delay for 10000 Counts */
				wait ();                       /* call wait function */
      }
			P0=0x26;
			for (i = 0; i < 2000; i++)  {  /* Delay for 10000 Counts */
				wait ();                       /* call wait function */
      }
			P0=0x4C;
			for (i = 0; i < 2000; i++)  {  /* Delay for 10000 Counts */
				wait ();                       /* call wait function */
      }
			P0=0x89;
			for (i = 0; i < 2000; i++)  {  /* Delay for 10000 Counts */
				wait ();                       /* call wait function */
      }
	}
}
