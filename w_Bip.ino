
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
     
     {command2(Volu,0,gromk);delay(200);command2(Fold,7,210); } //20wait_play();if (Wiat_otv(100)) {delay(100);command2_bilo(Fold,7,210);} else {command2_bilo(Fold,7,218);}
     
     else 
     if (hour>=kuOn+4 && hour<kuOff)
     {command2(Volu,0,gromk);delay(200);command2(Fold,7,210); }
    
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
uint8_t trek_=random(1,54); 
  String disp_l= " L " + String (trek_);
  printStringWithShift(disp_l.c_str(), 20);  
  command2(Volu,0,gromk);delay(200);    command2(Fold,1,trek_);  //проиграть файль trek из папки 1 

#endif
}  //199 -зарядки оружея/211- типа типа пилинг подводной лодки

void bip_UP()  { 
#ifdef _ZVUK   
  printStringWithShift(" Верх", 5);  command2(Stop,0,0);delay(1000);
#endif
}  //199 -зарядки оружея/211- типа типа пилинг подводной лодки

void bip_DOW()  { 
#ifdef _ZVUK   
 f_angl=1;
 // printStringWithShift(" Низ", 5);  play_frazi(6 ,212,dayOfWeek+30,  day+40, month+80, hour , minute+100);  delay(500);

#endif
}  //199 -зарядки оружея/211- типа типа пилинг подводной лодк

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------праздники напоминаия---------------------------------------------
void bip_prazn()  { Serial.println ("влет в праздники ");  /* command2(Volu,0,gromk); delay(100);**/ /*command2(Fold,7,198);*/  delay(1000); play_frazi(3,7 ,198, day+40, month+80);}   //11
//--------------------------------будильник
void bip_bud_end()  //Вызываеться один раз когда сбрасываються все флаги будильника
{    
//Serial.println ("end будильник ");
play_frazi(3,7,100,212, hour , minute+100);  //delay(500);

}
//----------------------------------------------------------------------------------------------------------------
void bip_budil_start() ///срабатывание будильника
 { 
#ifdef _ZVUK

      if(fl_bud_mp==0)      //чтобы сработола только один раз   обнулим при обнулении alarm_stat
      {   uint8_t trek=random(1,54); 
          String disp_l= " L " + String (trek);
          printStringWithShift(disp_l.c_str(), 20);        
        //if  ((gromk-15) >0) voll=(gromk-15); else  voll=10;
           if  (voll>zad_vool) voll=zad_vool;
           command2(Volu,0,voll);   delay(200);
           //trek= random(1,54);  //случайное  число в таких приделах
          command2(Fold,1,trek);  //проиграть файль trek из папки 7 
          fl_bud_mp=1; 
      } 
      else  {   if (voll++<gromk) { Serial.println ("громкость ");delay(100); command2(Volu,0,voll); } }  //использую else чтобы в первый раз не менять громкость а только включить трек //для плаввнго включения громкости //17
#endif 
}


//************************************************************************************************************************************************************************************
void   b_time_full_ad() //Вызываеться один раз когда сбрасываються все флаги будильника
{     //unsigned long t_tmp = millis() ;  


    if(otp_kom==0)    //если otp_kom истина отправляем комаду
    {   // Serial.println("");
        intFlag=0;////для прерывания
        f_govorit_fraz=1;
        if (caun_zv==masiv[0]) {//Serial.println("");Serial.print("cmd");Serial.print(caun_zv);Serial.print(" "); 
                                  //если количество фраз произнесененных станет равным нулевому элементу масива то оканчиваем возпроизвидение
                                 caun_zv=0; f_govorit_fraz=0; pr_bip_full=0; f_kuku=0; pr_bip_vre3=0; 
                                  return;}
         caun_zv++;
        //Serial.println();Serial.print("cmd");Serial.print(caun_zv);Serial.print(" ");
        if (caun_zv ==1) { if (digitalRead(PIN_MP3))  {f_Fold=1; /*Serial.println("Input hide");*/  }  
                           else                       {f_Fold=0; /*Serial.println("Input low");*/} } //если вход истина значит не чего не играет запускаем проигаш из папки если игрпет то в вставка из  ADVE

        if (f_Fold) {command2(Fold,masiv[1],masiv[caun_zv+2]);/*Serial.print("старт_F="); Serial.println(masiv[caun_zv+1]);*/ } 
          else      {command2(ADVE,0,masiv[caun_zv+2]);       /*Serial.print("старт_A="); Serial.println(masiv[caun_zv+1]);*/ }

        myTimer_pl= millis(); //запускаем отсчет ели вдруг не будет ответа чтобы не стопорить а все обновить
        otp_kom=1; 
     } 
      else
      {
        if (millis() - myTimer_pl >= 5000) {  
          otp_kom=0;
          if (digitalRead(PIN_MP3))   {  otp_kom=0;  Serial.println("Привышенно время ожидания ответа для команды"); } //если плее не играет(если вход истина значит не чего не играет), а ожидание превышено то пробуем отправлять следующюю команду
          else   {myTimer_pl= millis(); Serial.print("p");}
          return;
        } // Serial.println("Привышенно время ожидания ответа для команды"); для того чтобы обнолить если вдруг не прийдет ответ, чтобы следующая команда выполнилась, а также повторно с работала    
        
      }        //if(otp_

          if ( f_Fold){         
                  if(intFlag)  {
                                 if (millis() - Timer_puaz_ang >= masiv[2]) {  //задержка поле проиграша
                                  otp_kom=0; 
                                }
                  } else {Timer_puaz_ang=millis();}
          }  
          else {  //когда играет реклама то ждем прерывания второго так как первое возникнет при остановке музыки а второе после проиграша рекламы
                  if(intFlag>1){ 
                             if (millis() - Timer_puaz_ang >= 100) { 
                                  otp_kom=0; //delay(100); 
                               }
                  } else {Timer_puaz_ang=millis();}
          }

}
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
void command2(int8_t cmd, int8_t Para_MSB, int8_t Para_LSB)   //без ответа о файле вроде
{
 // f_otv=1;
    //7EFF060F0007D4EF
  cmdbuf[0] = 0x7e;
  cmdbuf[1] = 0xFF;
  cmdbuf[2] = 0x06;
  cmdbuf[3] = cmd;
  cmdbuf[4] = 0x00;
  cmdbuf[5] = Para_MSB;
  cmdbuf[6] = Para_LSB;
  cmdbuf[7] = 0xef;
  for (uint8_t i = 0; i < 8; i++) {   Serial.write(cmdbuf[i]);  delay(1);   }
}
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
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
void byte2hex(uint8_t b_dan){ /*Serial.print("0x");*/  
        if (b_dan < 16) Serial.print("0"); 
         
        Serial.print(b_dan, HEX);
        Serial.print(" "); 
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

//---------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------
//на ноль часов нет фразы  //
//0-элемент определяет количество  фраз //1-скакой папки протговать//2-сколько хзадежки после фразы
//полседний определяет с какой папки играть
void play_frazi(int kol_fraz, int folder ,  int time_zad , int fraz1 , int fraz2 , int fraz3 , int fraz4 , int fraz5 , int fraz6 , int fraz7 , int fraz8 , int fraz9, int fraz10 ){
   if (!pr_bip_full){
    masiv[0] =kol_fraz; masiv[1] = folder;  masiv[2] = time_zad; masiv[3] =fraz1;masiv[4] =fraz2;masiv[5] =fraz3;masiv[6] =fraz4; masiv[7] =fraz5; masiv[8] =fraz6; masiv[9] =fraz7; masiv[10] =fraz8;masiv[11] =fraz9;masiv[12] =fraz10;
    pr_bip_full=1; 
   b_time_full_ad();
    }
  }
 
