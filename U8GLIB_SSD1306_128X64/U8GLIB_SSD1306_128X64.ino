#include <U8glib.h>
/*SPI协议*/
U8GLIB_SSD1306_128X64 u8g(13, 11, 10, 9); // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9 
void setup()
{
  if (u8g.getMode()==U8G_MODE_R3G3B2){
    u8g.setColorIndex(255);// white
}else if(u8g.getMode()==U8G_MODE_GRAY2BIT){
    u8g.setColorIndex(3);// max intensity
}else if(u8g.getMode()==U8G_MODE_BW){
    u8g.setColorIndex(1);// pixel on
  }
  // u8g.setFont(u8g_font_unifont);
  Serial.begin(9600);
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}
void loop()
{
  u8g.firstPage();
  do{
    u8g.drawStr(0,0,"hello world!");
  }while(u8g.nextPage());
  delay(500);
}
