#include "simpletools.h" 
#include <propeller.h>
#include "SerialBuffer.h"
#include <stdio.h>

volatile struct SerialBuffer serbuf;

void start(volatile void *parptr)
{
  extern unsigned int _load_start_serial_fw_cog[];
  
  cognew(_load_start_serial_fw_cog, parptr);
}  

static void SerWrite(char* c)
{
  while(*c)
  {
    serbuf.txbuffer[serbuf.txin] = *c;
    serbuf.txin++;
    serbuf.txin &= TX_BUFFER_SIZE - 1;
    c++;
  }    
}  

int main()
{
  serbuf.txin = serbuf.txout = 0;
  serbuf.ubr = _clkfreq/115200;
  start(&serbuf);
  
  while(1)
  {
    sleep(1);
    SerWrite("HELLO ");
    sleep(1);
    SerWrite("WORLD\r\n");
  }  
}
