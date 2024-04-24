
#include "mc74hc595a.h"

uint8_t lchclk = 4;
uint8_t  sftclk = 7;
uint8_t sdi = 8;

uint32_t counter;

Mc74hc595a ic(lchclk, sftclk, sdi);

const byte A = 0x11;
const byte B = 0xc1;
const byte C = 0x63;
const byte D = 0x85;
const byte E = 0x61; 
const byte F = 0x71;
const byte H = 0x91;
const byte I = 0xf3;
const byte J = 0x87;
const byte L = 0xe3;
const byte N = 0xd5;
const byte _N = 0x55;
const byte O = 0xc5;
const byte P = 0x31;
const byte R = 0xf5;
const byte S = 0x49;
const byte T = 0xe1;
const byte U = 0x83;
const byte Y = 0x89;
const byte Blank = 0xff;

byte convertCharToSegments(char c)
{
  if(c=='A')return A;
  else if(c=='B')return B;
  else if(c=='C')return C;
  else if(c=='D')return D;
  else if(c=='E')return E;
  else if(c=='F')return F;
  else if(c=='H')return H;
  else if(c=='I')return I;
  else if(c=='J')return J;
  else if(c=='L')return L;
  else if(c=='N') return N;
  else if(c=='Ñ') return _N;
  else if(c=='O') return O;
  else if(c=='P') return P;
  else if(c=='R') return R;
  else if(c=='S') return S;
  else if(c=='T') return T;
  else if(c=='U') return U;
  else if(c=='Y') return Y;
  else if(c==' ') return Blank;
  else return Blank;
}



void write(const char* text)
{
  byte c;
  uint8_t len = strlen(text);

  if(len > 4)
  {
    Serial.println("Invalid length text");
    return;
  }
  
  for(int i=0; i<len;i++)
  {
    c = convertCharToSegments(text[i]);
    ic.SendByte(c);  
    ic.SendByte(0x10 << 3-i );
    ic.End();
  }
}

void write(byte symbol, uint8_t position)
{
  ic.SendByte(symbol);  
  ic.SendByte(0x10 << position);
  ic.End();
}

void setup() 
{
  Serial.begin(115200);
}


void loop()
{
  for(int i=0;i<1500;i++)
  {
    write("HI");
  }
  for(int i=0;i<1500;i++)
  {
  write(0xfd, 3); // -
  write(0xfd, 2); // - 
  write(0x39, 1); // °
  write("   C");
  }
  
}



