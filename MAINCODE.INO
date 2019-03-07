//==============
//INITIALIZATION
//==============
//Pin numbers:
int a=2;
int b=3;
int c=4;
int d=5;
int e=6;
int f=7;
int g=8;
int buzzer=11;
int button=10;
int led_win=52;
int led[]={22,24,26,28,30,34,36,38,40};

//Other variables:
char buttonstate=0;
int timedelay;
int i=0;
int state=0;

//IF YOU WANNA CHEAT:
int level=0;                                      //Adjust for starting level
int t[]={100,80,70,60,50,40,35,30,25,20,15};      //Adjust for speed

void setup() {
  pinMode (a,OUTPUT);
  pinMode (b,OUTPUT);
  pinMode (c,OUTPUT);
  pinMode (d,OUTPUT);
  pinMode (e,OUTPUT);
  pinMode (f,OUTPUT);
  pinMode (g,OUTPUT);
  pinMode (buzzer,OUTPUT);
  pinMode (button,INPUT);
  pinMode (led_menang,OUTPUT);
  for (int i=0;i<8;i++) 
  {
  pinMode (led[i],OUTPUT);
  }
}


//================
//FUNCTIONS BELOW
//================
void loop ()
{
  timedelay=t[level];
  lampu();
  pencet();
  tingkat();
}

void lampu()
{
  switch(state){
    case 0:                       //(0) FORWARD SHIFTING
    i++;
    digitalWrite(led[i],HIGH);
    digitalWrite(led[i-1],LOW);
    delay(timedelay);
    if (i==7) {
    state=1;
    }
    break;
    
    case 1:                       //(1) BACKWARD SHIFTING
    i--;
    digitalWrite(led[i],HIGH);
    digitalWrite(led[i+1],LOW);
    delay(timedelay);
    if (i==0) {
    state=0;
    }
    break;
    
    case 2:                       //(2) STOP: LEVEL CLEAR
    digitalWrite(led[i],HIGH);
    delay(200);
    digitalWrite(led[i],LOW);
    delay(200);
    digitalWrite(led[i],HIGH);
    delay(200);
    digitalWrite(led[i],LOW);
    delay(200);
    digitalWrite(led[i],HIGH);
    delay(200);
    digitalWrite(led[i],LOW);
    delay(200);
    if (level<=9) {
      level++;
      i=0;
      state=0;
    }
    else {
      state=4;
    }
    break;
    
    case 3:                       //(3)STOP: LEVEL FAIL
    digitalWrite(buzzer,HIGH);
    delay(2000);
    digitalWrite(buzzer,LOW);
    level=0;
    state=0;
    break;

    case 4:                       //(4)STOP: ALL LEVELS CLEAR
    digitalWrite(buzzer,HIGH);
    delay(50);
    digitalWrite(buzzer,LOW);
    delay(100);
    break;
  }
}

void pencet()
{
  buttonstate=digitalRead(button);
  if ((buttonstate==HIGH)&&((i==3)||(i==4))) {      //Pressed when in CENTER (CLEAR)
    state=2;
    delay(10);
  }
  else if ((buttonstate==HIGH)&&((i<3)||(i>4))) {   //Pressed when OFF CENTER (FAIL)
    state=3;
    delay(10);
  }
}



//===================================
//CONNECT SEVEN SEGMENT TO EACH LEVEL
//===================================
void tingkat()
{
  if (level==0) {
    ss0();}
  else if (level==1) {
    ss1();}
  else if (level==2) {
    ss2();}
  else if (level==3) {
    ss3();}
  else if (level==4) {
    ss4();}
  else if (level==5) {
    ss5();}
  else if (level==6) {
    ss6();}
  else if (level==7) {
    ss7();}
  else if (level==8) {
    ss8();}
  else if (level==9) {
    ss9();}
}
//=============================
//SEVEN SEGMENT CODES DOWN HERE
//=============================
void ss0 (){
  digitalWrite (2,0);
  digitalWrite (3,0);
  digitalWrite (4,0);
  digitalWrite (5,0);
  digitalWrite (6,0);
  digitalWrite (7,0);
  digitalWrite (8,1);}
void ss1 (){
  digitalWrite (2,1);
  digitalWrite (3,0);
  digitalWrite (4,0);
  digitalWrite (5,1);
  digitalWrite (6,1);
  digitalWrite (7,1);
  digitalWrite (8,1);}
void ss2 (){
  digitalWrite (2,0);
  digitalWrite (3,0);
  digitalWrite (4,1);
  digitalWrite (5,0);
  digitalWrite (6,0);
  digitalWrite (7,1);
  digitalWrite (8,0);}
void ss3(){
  digitalWrite (2,0);
  digitalWrite (3,0);
  digitalWrite (4,0);
  digitalWrite (5,0);
  digitalWrite (6,1);
  digitalWrite (7,1);
  digitalWrite (8,0);}
void ss4(){
  digitalWrite (2,1);
  digitalWrite (3,0);
  digitalWrite (4,0);
  digitalWrite (5,1);
  digitalWrite (6,1);
  digitalWrite (7,0);
  digitalWrite (8,0);}
void ss5 (){
  digitalWrite (2,0);
  digitalWrite (3,1);
  digitalWrite (4,0);
  digitalWrite (5,0);
  digitalWrite (6,1);
  digitalWrite (7,0);
  digitalWrite (8,0);}
void ss6 (){
  digitalWrite (2,0);
  digitalWrite (3,1);
  digitalWrite (4,0);
  digitalWrite (5,0);
  digitalWrite (6,0);
  digitalWrite (7,0);
  digitalWrite (8,0);}
void ss7 (){
  digitalWrite (2,0);
  digitalWrite (3,0);
  digitalWrite (4,0);
  digitalWrite (5,1);
  digitalWrite (6,1);
  digitalWrite (7,1);
  digitalWrite (8,1);}
void ss8 (){
  digitalWrite (2,0);
  digitalWrite (3,0);
  digitalWrite (4,0);
  digitalWrite (5,0);
  digitalWrite (6,0);
  digitalWrite (7,0);
  digitalWrite (8,0);}
void ss9 (){
  digitalWrite (2,0);
  digitalWrite (3,0);
  digitalWrite (4,0);
  digitalWrite (5,0);
  digitalWrite (6,1);
  digitalWrite (7,0);
  digitalWrite (8,0);}
void ssOFF (){
  digitalWrite (2,1);
  digitalWrite (3,1);
  digitalWrite (4,1);
  digitalWrite (5,1);
  digitalWrite (6,1);
  digitalWrite (7,1);
  digitalWrite (8,1);}
