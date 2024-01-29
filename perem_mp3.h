const int8_t PIN_MP3=12; //пин статуса плеера
static uint8_t otp_kom2; //отправить команду если  ноль то отправляем комаду плееру
static uint32_t myTimer_pl2;
uint16_t masiv[9];
uint8_t  f_Fold_ADVE;  //если установлен значит Fold проигрыш из папки если нет то вставкаа  с ADVE
volatile uint intFlag = false;  //для прерывания
bool pr_bip_full; //пременая для бп чтобы отказаться от задержек

uint8_t caun_zv2;
//static uint8_t otp_kom2; //отправить команду если  ноль то отправляем комаду плееру

bool f_govorit_fraz; //флаг говориться фраза , чтобы не выполнять все тормозящиие запросы

void play_frazi(int kol_fraz=0, int fraz1 =0 , int fraz2 =0, int fraz3 =0, int fraz4=0 , int fraz5=0 , int fraz6=0 , int fraz7=0 , int fraz8=0 , int fraz9=0);
String tekst [] ={"sss0","sss1","sss2","sss3","sss4","sss5","sss6","sss7","sss8","sss9","sss10","sss11","sss12","sss13","sss14","sss15","sss16","sss17","sss18" ,"sss19","sss20","sss21","sss22","sss23"};

bool f_angl;
uint8_t kol_fra_a;  //количество фраз англиских

void  IRAM_ATTR btnIsr(){
  intFlag++;
  //intFlag=digitalRead(12) ;
  //Serial.print("intFlag="); Serial.println(intFlag);
}