//************************************************************************************************************************************************************************************
void b_time_full_ad()  //Вызываеться один раз когда сбрасываються все флаги будильника
{     //unsigned long t_tmp = millis() ;  


    if(otp_kom2==0)    //если otp_kom истина отправляем комаду
    {   // Serial.println("");
        intFlag=0;////для прерывания
        
        if (caun_zv2==masiv[0]) {Serial.println("");Serial.print("cmd");Serial.print(caun_zv2);Serial.print(" ");caun_zv2=0; pr_bip_full=0; f_kuku=0; pr_bip_vre3=0;  return;}
         caun_zv2++;
        Serial.println();Serial.print("cmd");Serial.print(caun_zv2);Serial.print(" ");
        if (caun_zv2 ==1) { if (digitalRead(PIN_MP3))  {Serial.println("Input hide"); f_Fold_ADVE=1; }  else  {f_Fold_ADVE=0; Serial.println("Input low");} } //если вход истина значит не чего не играет запускаем проигаш из папки если игрпет то в вставка из  ADVE
    
         if (f_Fold_ADVE) { Serial.print("старт_F");  Serial.print(masiv[caun_zv2]); command2(Fold,7,masiv[caun_zv2]); } else  {Serial.print("старт_A="); Serial.print(masiv[caun_zv2]); command2(ADVE,0,masiv[caun_zv2]); }
          
        
        //command2(masiv[caun_zv][0],masiv[caun_zv][1],masiv[caun_zv][2]);     
        
        
        //t_adve= millis() ; 
        myTimer_pl2= millis(); //запускаем отсчет ели вдруг не будет ответа чтобы не стопорить а все обновить
        otp_kom2=1; 
     } 
      else
      {
        if (millis() - myTimer_pl2 >= 5000) {  
          otp_kom2=0;
          Serial.println("Привышенно время ожидания ответа для команды");
        } // Serial.println("Привышенно время ожидания ответа для команды"); для того чтобы обнолить если вдруг не прийдет ответ, чтобы следующая команда выполнилась, а также повторно с работала    
        
      }        //if(otp_


    //if ( pr_bip_full) obrabotka_inp_A(); else obrabotka_inp_A_adv();

  if ( f_Fold_ADVE){  if(intFlag>0){ otp_kom2=0; Serial.print("завершено_F"); }}  else { if(intFlag>1){ otp_kom2=0; Serial.print("завершено_A");} }
  //if ( pr_bip_adve){  if(intFlag>1){ otp_kom=0; Serial.print("завершено_A"); }}

}

void play_frazi(int kol_fraz, int fraz1 ){
    masiv[0] =kol_fraz; masiv[1] =fraz1;
    pr_bip_full=1;

  }

void play_frazi(int kol_fraz, int fraz1 , int fraz2){
    masiv[0] =kol_fraz; masiv[1] =fraz1; masiv[2] =fraz2;
     pr_bip_full=1; 
  }

void play_frazi(int kol_fraz, int fraz1 , int fraz2 , int fraz3){
    masiv[0] =kol_fraz; masiv[1] =fraz1;masiv[2] =fraz2;masiv[3] =fraz3;
    pr_bip_full=1; 
  }

void play_frazi(int kol_fraz, int fraz1 , int fraz2 , int fraz3, int fraz4){
    masiv[0] =kol_fraz; masiv[1] =fraz1;masiv[2] =fraz2;masiv[3] =fraz3;masiv[4] =fraz4;
    pr_bip_full=1; 
  }
void play_frazi(int kol_fraz, int fraz1 , int fraz2 , int fraz3, int fraz4 , int fraz5){
    masiv[0] =kol_fraz; masiv[1] =fraz1;masiv[2] =fraz2;masiv[3] =fraz3;masiv[4] =fraz4; masiv[5] =fraz5;
    pr_bip_full=1; 
  }

void play_frazi(int kol_fraz, int fraz1 , int fraz2 , int fraz3, int fraz4 , int fraz5 , int fraz6){
    masiv[0] =kol_fraz; masiv[1] =fraz1;masiv[2] =fraz2;masiv[3] =fraz3;masiv[4] =fraz4; masiv[5] =fraz5; masiv[6] =fraz6;
    pr_bip_full=1; 
  }

void play_frazi(int kol_fraz, int fraz1 , int fraz2 , int fraz3, int fraz4 , int fraz5 , int fraz6 , int fraz7){
    masiv[0] =kol_fraz; masiv[1] =fraz1;masiv[2] =fraz2;masiv[3] =fraz3;masiv[4] =fraz4; masiv[5] =fraz5; masiv[6] =fraz6; masiv[7] =fraz7;
    pr_bip_full=1; 
  }
void play_frazi(int kol_fraz, int fraz1 , int fraz2 , int fraz3, int fraz4 , int fraz5 , int fraz6 , int fraz7 , int fraz8){
    masiv[0] =kol_fraz; masiv[1] =fraz1;masiv[2] =fraz2;masiv[3] =fraz3;masiv[4] =fraz4; masiv[5] =fraz5; masiv[6] =fraz6; masiv[7] =fraz7; masiv[8] =fraz8;
    pr_bip_full=1; 
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
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
void byte2hex(uint8_t b_dan){ /*Serial.print("0x");*/  
        if (b_dan < 16) Serial.print("0"); 
         
        Serial.print(b_dan, HEX);
        Serial.print(" "); 
        }