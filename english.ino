void anglihe (){

 
  //if (f_angl &&f_govorit_fraz)  printStringWithShift(tekst[kol_fra_a+1].c_str(), 25);
   if (f_angl && !pr_bip_full && !f_govorit_fraz) {

     switch (f_angl)    
      {
       case 1:{
          if (kol_fra_a<26) {
            printStringWithShift(tekst[kol_fra_a].c_str(), 10);  //play_frazi(1 ,kol_fra_a,6); 
            play_frazi(1,6,500, kol_fra_a+1); 
            kol_fra_a++;
          } else {kol_fra_a=0;   f_angl=2; }
          //else {kol_fra_a=0;  if(f_angl) { if(f_angl++>3) { f_angl=0;};} 
        break;}
       case 2:{
          if (kol_fra_a<26) {
          printStringWithShift(tekst[kol_fra_a].c_str(), 5);  //play_frazi(1 ,kol_fra_a,6); 
            play_frazi(1,6,100, kol_fra_a+1); 
          kol_fra_a++;}
          else {kol_fra_a=0;   f_angl=3; }
          break;}
        case 3:{
          if (kol_fra_a<26) {
          printStringWithShift(tekst[kol_fra_a].c_str(), 5);  //play_frazi(1 ,kol_fra_a,6); 
            play_frazi(1,6,100, kol_fra_a+1); 
          kol_fra_a++;}
          else {kol_fra_a=0;   f_angl=4; }
          break;}
        case 4:{
          if (kol_fra_a<26) {
          printStringWithShift(tekst[kol_fra_a].c_str(), 5);  //play_frazi(1 ,kol_fra_a,6); 
            play_frazi(1,6,100, kol_fra_a+1); 
          kol_fra_a++;}
          else {kol_fra_a=0;   f_angl=5; }
          break;}
         case 5:{
          if (kol_fra_a<26) {
          printStringWithShift(tekst[kol_fra_a].c_str(), 5);  //play_frazi(1 ,kol_fra_a,6); 
            play_frazi(1,6,100, kol_fra_a+1); 
          kol_fra_a++;}
          else {kol_fra_a=0;   f_angl=0; }
          break;}
      }
    
  
 }  //if (f_angl && !pr_bip_full && !f_govorit_fraz) {


/*

 
 
  //if (f_angl &&f_govorit_fraz)  printStringWithShift(tekst[kol_fra_a+1].c_str(), 25);
   if (f_angl && !pr_bip_full && !f_govorit_fraz) {
  if (kol_fra_a<26) {
    play_frazi(1,6,2000,kol_fra_a+1); 
    printStringWithShift(tekst[kol_fra_a].c_str(), 20);  //play_frazi(1 ,kol_fra_a,6); 
    kol_fra_a++;
   } else {kol_fra_a=0;  if(f_angl) { if(f_angl++>5) { f_angl=0;};} }
  

 }

*/


}
