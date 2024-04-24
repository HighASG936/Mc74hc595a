
#include "mc74hc595a.h"

/**
 * @brief Construct a new Mc74hc595a:: Mc74hc595a object
 * 
 * @param lchclk 
 * @param sftclk 
 * @param sdi 
 * @param _reset 
 */
Mc74hc595a::Mc74hc595a(uint8_t lchclk, uint8_t sftclk, uint8_t sdi, uint8_t _reset, uint8_t _oe):
	lchclk(lchclk),
	sftclk(sftclk),
	sdi(sdi),
	_reset(_reset),
	_oe(_oe)
{
	if(_reset != 0)
	{
		pinMode(_reset, OUTPUT);
		Set();
	}

	if(_oe != 0)
	{
		pinMode(_reset, OUTPUT);
		Enable();
	}	

	pinMode(sftclk, OUTPUT);
	pinMode(lchclk, OUTPUT);
  pinMode(sdi, OUTPUT);
}


/**
 * @brief 
 * 
 */
void Mc74hc595a::Clk()
{
  digitalWrite(sftclk,LOW);
  digitalWrite(sftclk,HIGH);
}


 void Mc74hc595a::Sendbit(bool value)
 {
    digitalWrite(sdi,value);
    Clk();
 }


/**
 * @brief 
 * 
 * @param data 
 */
void Mc74hc595a::SendByte(byte data)
{
  bool bit;

	for(uint8_t i=0;i<8;i++)
  {
    bit = (data >> i) & 0x01;
    Sendbit(bit);
  }
}





/**
 * @brief 
 * 
 */
void Mc74hc595a::End()
{
  digitalWrite(lchclk,LOW);
  digitalWrite(lchclk,HIGH);
}


/**
 * @brief 
 * 
 */
void Mc74hc595a::Reset()
{
	digitalWrite(_reset,LOW);
}


/**
 * @brief 
 * 
 */
void Mc74hc595a::Set()
{
	digitalWrite(_reset,HIGH);
}

/**
 * @brief 
 * 
 */
void Mc74hc595a::Enable()
{
	digitalWrite(_oe, LOW);
}

/**
 * @brief 
 * 
 */
void Mc74hc595a::Disable()
{
	digitalWrite(_oe, HIGH);
}
