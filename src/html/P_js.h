const char P_js[] PROGMEM = R"=====(
var xmlHttp=createXmlHttpObject();
function createXmlHttpObject(){
  if(window.XMLHttpRequest){
    xmlHttp=new XMLHttpRequest();
  }else{
    xmlHttp=new ActiveXObject('Microsoft.XMLHTTP');
  }
  return xmlHttp;
}
function load(){
  if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
    xmlHttp.open('GET','/configs.json',true);
    xmlHttp.send(null);
    xmlHttp.onload = function(e) {
      jsonResponse=JSON.parse(xmlHttp.responseText);
      loadBlock(xmlHttp.onload);
    }
  }
}
function load_wifi(){
  if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
    xmlHttp.open('GET','/configs_wifi.json',true);
    xmlHttp.send(null);
    xmlHttp.onload = function(e) {
      jsonResponse=JSON.parse(xmlHttp.responseText);
      loadBlock(xmlHttp.onload);
    }
  }
}
function load_times(){
  if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
    xmlHttp.open('GET','/configs_time.json',true);
    xmlHttp.send(null);
    xmlHttp.onload = function(e) {
      jsonResponse=JSON.parse(xmlHttp.responseText);
      loadBlock(xmlHttp.onload);
    }
  }
}
function load_mqtt(){
  if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
    xmlHttp.open('GET','/configs_mqtt.json',true);
    xmlHttp.send(null);
    xmlHttp.onload = function(e) {
      jsonResponse=JSON.parse(xmlHttp.responseText);
      loadBlock(xmlHttp.onload);
    }
  }
}
function load_weath(){
  if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
    xmlHttp.open('GET','/configs_weath.json',true);
    xmlHttp.send(null);
    xmlHttp.onload = function(e) {
      jsonResponse=JSON.parse(xmlHttp.responseText);
      loadBlock(xmlHttp.onload);
    }
  }
}
function load_setup(){
  if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
    xmlHttp.open('GET','/configs_setup.json',true);
    xmlHttp.send(null);
    xmlHttp.onload = function(e) {
      jsonResponse=JSON.parse(xmlHttp.responseText);
      loadBlock(xmlHttp.onload);
    }
  }
}
function loadBlock() {


  var data2 = JSON.parse(xmlHttp.responseText);
  data = document.getElementsByTagName('body')[0].innerHTML;
  var new_string;
  for (var key in data2) {
    new_string = data.replace(new RegExp('{{'+key+'}}', 'g'), data2[key]);
    data = new_string;
  }
  document.getElementsByTagName('body')[0].innerHTML = new_string;
  var inputs = document.getElementsByTagName("input");
  var selects = document.getElementsByTagName("select");
  for (var key in data2) {
    if(data2[key] == 'checked'){
       for (var i = 0; i < inputs.length; i++) {
         if (inputs[i].id === key) {
           inputs[i].checked = "true";
         }
       }
    }
    for (var i = 0; i < selects.length; i++) {
      if (selects[i].id === key) {
        document.getElementById(key).value = data2[key];
      }
    }
  }
  handleServerResponse();
}
function val(id){
  var v = document.getElementById(id).value;
  return v;
}
function val_sw(nameSwitch) {
  switchOn = document.getElementById(nameSwitch);
  if (switchOn.checked){
    return 1;
  }
  return 0;
}
function send_request(submit,server){
  request = new XMLHttpRequest();
  request.open("GET", server, true);
  request.send();
  save_status(submit,request);
}
function send_request2(submit,server){
  request = new XMLHttpRequest();
  request.open("GET", server, true);
  request.send();
 }
function save_status(submit,request){
  old_submit = submit.value;
  request.onreadystatechange = function() {
    if (request.readyState != 4) return;
    submit.value = request.responseText;
    setTimeout(function(){
      submit.value=old_submit;
      submit_disabled(false);
    }, 1000);
  }
  submit.value = 'Зачекайте...';
  submit_disabled(true);
}
function submit_disabled(request){
  var inputs = document.getElementsByTagName("input");
  for (var i = 0; i < inputs.length; i++) {
    if (inputs[i].type === 'submit') {inputs[i].disabled = request;}
  }
}
function toggle(target) {
  var curVal = document.getElementById(target).className;
  document.getElementById(target).className = (curVal === 'hidden') ? 'show' : 'hidden';
}
function restart(submit, texts) {
  if (confirm(texts)) {
    server = "/restart?device=ok";
    send_request(submit, server);
    return true;
  } else {
    return false;
  }
}
var set_real_time;
function handleServerResponse(){
    clearTimeout(set_real_time);
    var res = jsonResponse.time.split(":");
    real_time(hours=res[0],min=res[1],sec=res[2]);
    document.body.style.backgroundColor="rgb("+jsonResponse.rgb+")";
}
function real_time(hours,min,sec){
    sec=Number(sec)+1;
    if (sec>=60){min=Number(min)+1;sec=0;}
    if (min>=60){hours=Number(hours)+1;min=0;}
    if (hours>=24){hours=0};
    document.getElementById("time").innerHTML = hours+":"+(min<10?"0":"")+min+":"+(sec<10?"0":"")+sec;
    set_real_time = setTimeout("real_time("+hours+","+min+","+sec+");", 1000);
}
function load_time(submit){
    server = "/Time";
    send_request(submit,server);
    load();
}
function knopki(submit){
    server = "/knopki";
    console.log('submit='+submit);
    send_request2(submit,server);
   // load();
}
)=====";
