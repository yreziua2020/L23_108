//-------------------------------------------------------------------------------------
void command_Ot2(int8_t cmd, int8_t Para_MSB, int8_t Para_LSB)  //вроде с ответом   cmdbuf[4] = 0x01; данный байт 
{   //будет отправляться ответ сразуже после получение даных -- подтверждение приема
  cmdbuf[0] = 0x7e;
  cmdbuf[1] = 0xFF;
  cmdbuf[2] = 0x06;
  cmdbuf[3] = cmd;
  cmdbuf[4] = 0x01;
  cmdbuf[5] = Para_MSB;
  cmdbuf[6] = Para_LSB;
  cmdbuf[7] = 0xef;
  for (uint8_t i = 0; i < 8; i++) {  Serial.write(cmdbuf[i]);   }
 
}

///-------------------------------------------------------- ПРИВЕТ --------------------------------------
void bip_privet()  {
#ifdef _ZVUK  
  //int8_t pov_grom;  //для повышения громкости еслине максимум
    ////if (gromk<25 ) {pov_grom=gromk+3;} else pov_grom=30; //если громкость меньше 25 то увеличиваем на 5 если бельше то прото увиличиваем на максимум
     if ((hour>=kuOn  && hour<kuOff)&& dayOfWeek!=7&&dayOfWeek!=1) {command2(Volu,0,gromk);delay(200);command2(Fold,7,216); }//command2_bilo(Fold,7,216);}   //216if (Wiat_otv(100)) {delay(100);command2_bilo(Fold,7,216);} else {command2_bilo(Fold,7,218);}
     else if (hour>=kuOn+4 && hour<kuOff){                          command2(Volu,0,gromk);delay(200);command2(Fold,7,216); }  //play_frazi(1 ,216 ); }//command2_bilo(Fold,7,216);} //if (Wiat_otv(100)) {delay(100);command2_bilo(Fold,7,216);} else {command2_bilo(Fold,7,218);}
#endif  
}  
//--------------------------------------------------  Вайфай ------------------------------------------
void bip_Wi_Fi() { 
#ifdef _ZVUK  
     if ((hour>=kuOn  && hour<kuOff)&& dayOfWeek!=7&&dayOfWeek!=1)    
     //{command2(Volu,0,gromk);delay(200);command2(Fold,7,210); } //20wait_play();if (Wiat_otv(100)) {delay(100);command2_bilo(Fold,7,210);} else {command2_bilo(Fold,7,218);}
     {command2(Volu,0,gromk);delay(200);command2(Fold,7,210); } //20wait_play();if (Wiat_otv(100)) {delay(100);command2_bilo(Fold,7,210);} else {command2_bilo(Fold,7,218);}
     //{command2(Volu,0,gromk);delay(200);play_frazi(1 ,210 ); Serial.print("komada"); while(pr_bip_full) { delay(1); b_time_full_ad();}  } //20wait_play();if (Wiat_otv(100)) {delay(100);command2_bilo(Fold,7,210);} else {command2_bilo(Fold,7,218);}
     else 
     if (hour>=kuOn+4 && hour<kuOff)
     {command2(Volu,0,gromk);delay(200);command2(Fold,7,210); }
    // command2(Volu,0,gromk);delay(200);play_frazi(1 ,210 ); Serial.print("komada2"); while(pr_bip_full) {delay(1);b_time_full_ad();}}     //20wait_play();if (Wiat_otv(100)) {delay(100);command2_bilo(Fold,7,210);} else {command2_bilo(Fold,7,218);}
#endif  
 }  //звук аськи при соединии с файфаем
//---------------------------------------------------------------------------------------------------------
void bip2()  {     //при внисения изминеий на странице
#ifdef _ZVUK   
  command2(Volu,0,gromk);delay(100); command2(Fold,7,218);  Serial.println("внисение изминений на странице") ;
#endif  
} 
void bip_restart() {  //211- типа завершения
#ifdef _ZVUK
  printStringWithShift(" R_Web", 25); command2(Volu,0,gromk);delay(200);command2(Fold,7,211);delay(3400);
#endif
}  
void bip_restart_up(){ 
#ifdef _ZVUK  
  printStringWithShift(" R_Upd", 25); command2(Volu,0,gromk);delay(200);command2(Fold,7,219);
#endif  
}                                    //тмпа зарчдки оружия
void bip_restart2()  { 
#ifdef _ZVUK   
  printStringWithShift("Resta", 15);  command2(Volu,0,gromk);delay(200);command2(Fold,7,218);delay(3400);
#endif
}  //199 -зарядки оружея/211- типа типа пилинг подводной лодки
void bip_RIGHT()  { 
#ifdef _ZVUK   //меньше быстрее прокрутка текста
  printStringWithShift(" Право", 5);  command2(Volu,0,gromk);delay(200);command2(3,0,3);
  //command2_bilo(Fold,7,235);delay(1000);
#endif
}  //199 -зарядки оружея/211- типа типа пилинг подводной лодки

void bip_LEFT()  { 
#ifdef _ZVUK   
  printStringWithShift(" Лево", 5);  command2(Volu,0,gromk);delay(200);command2(Fold,7,236);delay(1000);
#endif
}  //199 -зарядки оружея/211- типа типа пилинг подводной лодки

void bip_UP()  { 
#ifdef _ZVUK   
  printStringWithShift(" Верх", 5);  command2(Stop,0,0);delay(1000);
#endif
}  //199 -зарядки оружея/211- типа типа пилинг подводной лодки

void bip_DOW()  { 
#ifdef _ZVUK   
  printStringWithShift(" Низ", 5);  play_frazi(6 ,212,dayOfWeek+30,  day+40, month+80, hour , minute+100);  delay(500);
#endif
}  //199 -зарядки оружея/211- типа типа пилинг подводной лодк

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------праздники напоминаия---------------------------------------------
void bip_prazn()  { Serial.println ("влет в праздники ");  /* command2(Volu,0,gromk); delay(100);**/ /*command2(Fold,7,198);*/  delay(1000); play_frazi(3 ,198, day+40, month+80);}   //11
//--------------------------------будильник
void bip_bud_end()  //Вызываеться один раз когда сбрасываються все флаги будильника
{    
//Serial.println ("end будильник ");
play_frazi(3 ,212, hour , minute+100);  //delay(500);

}
//----------------------------------------------------------------------------------------------------------------
void bip_budil_start() ///срабатывание будильника
 { 
#ifdef _ZVUK
      if(fl_bud_mp==0)      //чтобы сработола только один раз   обнулим при обнулении alarm_stat
      {   
        //if  ((gromk-15) >0) voll=(gromk-15); else  voll=10;
           if  (voll>zad_vool) voll=zad_vool;
           command2(Volu,0,voll);   delay(200);
           trek= random(222,242);  //случайное  число в таких приделах
          command2(Fold,7,trek);  //проиграть файль trek из папки 7 
          fl_bud_mp=1; 
      } 
      else  {   if (voll++<gromk) { Serial.println ("громкость ");delay(100); command2(Volu,0,voll); } }  //использую else чтобы в первый раз не менять громкость а только включить трек //для плаввнго включения громкости //17
#endif 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------


 
String sbyte2hex(uint8_t b)
{
  String shex;

  shex = "0x";

  if (b < 16) shex += "0";
  shex += String(b, HEX);
  shex += " ";
  return shex;
}
 
