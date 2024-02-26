

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
//String tekst [] ={"A ei эй","B bi би","C si си","D di ди","E i и","F_ef_эф","G dʒi джи","H eitʃ эйч","I ai aй","J dʒei джей","K kei кей","L el эл","M em эм","N en эн","O əʊ оу","P pi пи","Q kju кью","R a а","S es эс" ,"T ti ти","U ju ю","V vi ви","W 'dʌblju дабылю","X eks экс" ,"Y wai вай","Z zed зэд"};
//String tekst [] ={"  A ei  ","  B bi ","  C si  ","  D di  ","  E i и ","  F ef  ","  G dʒi"," H eitʃ","  I ai  "," J dʒei"," K kei  "," L el  "," M em  "," N en  "," O оу  "," P pi  "," Q kju ","  R a  "," S es " ,"  T ti  "," U ju  "," V vi "," W 'dʌblju"," X eks " ," Y wai "," Z zed "};
//String tekst [] ={" a\222ei\223эй"," B\222bi\222би"," C\222si\222си"," D\222di\223ди","  E [i] и","   F [ef] ","  G d\227i "," H eit\226","  I\222ai\222ай\223"," J d\227ei","  K [kei]","  L\222el\222эл"," M [em]"," N [en]"," O\223\224\225\223оу"," P\222pi\222пи"," Q [kju]","  R [a] а"," S\222es\223эс" ,"  T\222ti\222ти","  U ju\222ю"," V\222vi\222ви"," W\223dлblju"," X eks " ," Y [wai]","  Z zed\222"};
#ifdef d_102 
String tekst [] ={" A\222ei\223эй"," B\222bi\222би"," C\222si\222си"," D\222di\223ди","  E [i] и","   F [ef]\223","  G d\227i "," H eit\226","  I\222ai\222ай\223"," J d\227ei","  K [kei]","  L [el]"," M [em]"," N [en]"," O\223\224\225\223оу"," P\222pi\222пи"," Q\222[kju]","  R [a] а"," S\222es\223эс" ,"  T\222ti\222ти","  U ju\222ю"," V\222vi\222ви"," W\223dлblju"," X eks " ," Y\222[wai]","  Z zed\222"};
#endif 

#ifdef d_103 
String tekst [] ={" A\222ei\223эй"," B\222bi\222би"," C\222si\222си"," D\222di\223ди","  E [i] и","   F [ef]\223","  G d\227i "," H eit\226","  I\222ai\222ай\223"," J d\227ei","  K [kei]","  L [el]"," M [em]"," N [en]"," O\223\224\225\223оу"," P\222pi\222пи"," Q\222[kju]","  R [a] а"," S\222es\223эс" ,"  T\222ti\222ти","  U ju\222ю"," V\222vi\222ви"," W\223dлblju"," X eks " ," Y\222[wai]","  Z zed\222"};
#endif 

#ifdef d_104 
String tekst [] ={"   Aa [ei][эй] "," B [bi:][би:]","  Cc [si:][си:] ","  Dd [di:][ди:] ","    Ee [i:][и:] ","   Ff [ef][эф] ","  Gg [d\227i:]джи:","  Hh[eit\226] эйч","    Ii [ai][ай] "," Jj [d\227ei][джей]","   Kk [kei][кей]","  Ll  [el][эл] " ," Mm  [em][эм] "," Nn  [en][эн] ","  Oo [\224\225][оу]","  Pp [pi:][пи:] "," Qq [kju:]кью:","    Rr [a:][а:] ","  Ss [es][эс] " ,"  Tt [ti:][ти:] ","  Uu [ju:][ю:]","   Vv [vi][ви] "," W[dлblju:]даблью","  Xx [eks] экс" ,"  Yy [wai] уай","  Zz [zed] зед"};
#endif 
bool f_angl;
uint8_t kol_fra_a;  //количество фраз англиских

void  IRAM_ATTR btnIsr(){
  intFlag++;
  //intFlag=digitalRead(12) ;
  //Serial.print("intFlag="); Serial.println(intFlag);
}

