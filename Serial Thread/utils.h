#define _BV(bit)        (1 << bit)
#define sbi(reg, bit)   (reg |= _BV(bit))
#define cbi(reg, bit)   (reg &= ~_BV(bit))