
//void bip3()       {   if (digitalRead(MP3_PIN)==1) {mp3_play_file_in_fol (2,12);}}  //для громкости увиличение уменьшение
//void bip4()       {   if (digitalRead(MP3_PIN)==1) {mp3_play_file_in_fol (2,3);} }  //естли играет смкелодия то звук ненужен
//void bip()        {  mp3_set_volume (gromk);delay(100); mp3_play_file_in_fol (11,3);}   //201
//-------------------bbbbbbb--------------------------------------------------------------------------
//void bip()          {   command2_bilo(Fold,11,13); }   //201  двойное нажатие нопки


 /* 
    int cb2 = udp.parsePacket(); 
  if (cb2) 
  {  udp.read(packetBuffer2, NTP_PACKET_SIZE);   String  req2=(packetBuffer2); //char reg3=(packetBuffer2);
    if (req2.indexOf("63") != -1)   // yyyyy    Осуществляет поиск символа или подстроки в строке (req2)  -1 если 63 не найдено (можно указать и определенную позицию, с которой необходимо начать поис через запятую)
    {  
      char myStr8[10];  req2=req2.substring(2);req2.toCharArray(myStr8, req2.length()+1);t3 = atof(myStr8)/10;   //возращает значение начиная с совторо символа, можно указать и позиц символа чере запатую// копирование String в массив myStr8 //преобразуем char в флоат
      t4 = int(t3);  t5 = int(t3 * 10 * (t3 > 0 ? 1 : -1)) % 10;  
    } 
    if (req2.indexOf("64") != -1)  {  char myStr8[10];  req2=req2.substring(2);req2.toCharArray(myStr8, req2.length()+1);t1kom = atof(myStr8)/10; t2kom = int(t1kom); t3kom = int(t1kom * 10 * (t1kom > 0 ? 1 : -1)) % 10; } 
    if (req2.indexOf("65") != -1)  {  char myStr8[10];  req2=req2.substring(2);req2.toCharArray(myStr8, req2.length()+1);t1kux = atof(myStr8)/10; t2kux = int(t1kux); t3kux = int(t1kux * 10 * (t1kux > 0 ? 1 : -1)) % 10; } 
    if (req2.indexOf("60") != -1)  {  char myStr8[10];  req2=req2.substring(2);req2.toCharArray(myStr8, req2.length()+1);t1kom = atof(myStr8)/10; t2kom = int(t1kom); t3kom = int(t1kom * 10 * (t1kom > 0 ? 1 : -1)) % 10; } 
  // byte  
     memset(packetBuffer2, 0, NTP_PACKET_SIZE);  //очищаем буфер для приема следующей команды   //зполняем packetBuffer нулем(0) по размеру NTP_PACKET_SIZE
  }
  */    


//void vver(){delay(1000);  command(15,6,6);wait_play(); }
/*

//------------------------------------ говорит время при обновлении времени с веб страици---------------

void bip_v7re4()   // проговариваем время с веба
{ uint8_t wr_tmp;
  if(Serial.available()||(st_pler==0))
  { wr_tmp=answer(100);
    if ( (st_pler==0)||(wr_tmp==1))
    { 
      delay(100);
      st_pler=1;    //нужно для того чтоб включить первую мелодию не дожидаясь ответа
        switch (++caun_zv)    
            {
            case 1:{command2_bilo(15,7,212);delay(500); break;}
          //case 2:{if(wr_tmp==1) {command2_bilo(15,7,212); delay(100);}else {command2_bilo(15,7,dayOfWeek+30); delay(100);} break;}
            case 2:{if(wr_tmp==1) {command2_bilo(15,7,212);delay(500);}else {command2_bilo(15,7,dayOfWeek+30); delay(100);} break;}
            //case 2:{if(wr_tmp==1) {command2_bilo(15,7,dayOfWeek+30);delay(100);}else {command2_bilo(15,7,dayOfWeek+30); delay(100);} break;}
            case 3:{command2_bilo(15,7,day+40); delay(100); break;} 
            case 4:{command2_bilo(15,7,month+80); delay(100); break;}
            case 5:{command2_bilo(15,7,hour); delay(100);  break;}
            case 6:{command2_bilo(15,7,minute+100);delay(100);  break;}
            case 7:{caun_zv=0; pr_bip_vre3=0;st_pler=0;delay(100); break;}
            default:{  break;}
         
            }
    }
    
 }

}


 p1 = p0 / 10000;
    p2 = (p0 - p1 * 10000) / 1000;
    p3 = (p0 - p1 * 10000 - p2 * 1000) / 100;
    p4 = (p0 - p1 * 10000 - p2 * 1000 - p3 * 100) / 10;
    p5 = (p0 - p1 * 10000 - p2 * 1000 - p3 * 100 - p4 * 10);
  

  //p0 = p0/100;  //я добавил 
   p2 = (p0 - p1 * 1000) / 100;
  p3 = (p0 - p1 * 1000 - p2 * 100) / 10;
  p4 = p0 % 10;


*/










/*void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerUSBInserted:
      Serial.println("USB Inserted!");
      break;
    case DFPlayerUSBRemoved:
      Serial.println("USB Removed!");
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
  
}
*/
