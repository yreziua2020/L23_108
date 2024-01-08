const int8_t PIN_MP3=12; //пин статуса плеера
static uint8_t otp_kom; //отправить команду если  ноль то отправляем комаду плееру
static uint32_t myTimer_pl2;
uint16_t masiv[9];
uint8_t  f_Fold_ADVE;  //если установлен значит Fold проигрыш из папки если нет то вставкаа  с ADVE
volatile uint intFlag = false;  //для прерывания
bool pr_bip_full; //пременая для бп чтобы отказаться от задержек



void  IRAM_ATTR btnIsr(){
  intFlag++;
  //intFlag=digitalRead(12) ;
  //Serial.print("intFlag="); Serial.println(intFlag);
}