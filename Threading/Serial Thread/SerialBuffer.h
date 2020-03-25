//These should both be powers of 2
#define RX_BUFFER_SIZE   32
#define TX_BUFFER_SIZE   32

#define TX_PIN  30

struct SerialBuffer
{
  volatile char rxbuffer[RX_BUFFER_SIZE];
  volatile char txbuffer[TX_BUFFER_SIZE];
  
  volatile unsigned char rxin, rxout;
  volatile unsigned char txin, txout;
  
  volatile unsigned int ubr;
};