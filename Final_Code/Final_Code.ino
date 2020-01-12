#include <Servo.h>
#define s0 15
#define s1 16
#define s2 17
#define s3 18
#define sout 19
// ------------------------------------------------------------------
//                P I N  D E F I N I T I O N
// ------------------------------------------------------------------
//Variables for definig line following sensor pins
// F R O N T
int MidFront = A4; int LeftFront = A5; int RightFront = A11;
// B A C K
int XRightBack = A7; int RightBack = A8; int MidBack = A9;
int LeftBack = A10;
int XLeftBack = A11;
// X T R E A M  B A C K
int BackRight = A12; int XFrontRight = A13;
// X T R E A M  M I D
int XRight = A14; int XLeft = A15;

//Encoder Pins
int Encoder_Front = 3; // LEFT MOTOR
int Encoder_Back = 2; // RIGHT MOTOR
//Motors pins
int Motor1_A = 4; int Motor1_B = 5; int Motor1_C = 6; int Motor1_D = 7;
int Motor2_A = 8; int Motor2_B = 9; int Motor2_C = 10; int Motor2_D = 11;

//Variables for defining wall following sensor pins
int Front_Right = A0;
int Front = A1;
int Right_Front = A2;
int Right_Back = A3;

int  cheq = 0;
// ------------------------------------------------------------------
//                       S E R V O  & C O L O R
// ------------------------------------------------------------------
int pos;
Servo RightServo;
Servo LeftServo;
Servo holder;
int freqR = 0;
int freqG = 0;
int freqB = 0;
int one_time = 0;

// ------------------------------------------------------------------
//                       I N T U R R U P T S
// ------------------------------------------------------------------
//ENCODER TICKS COUNTER INITIALIZATION
volatile unsigned long Front_Ticks = 0;
volatile unsigned long Back_Ticks = 0;
void Initialize_Encoders(void) {
  Front_Ticks = 0;
  Back_Ticks = 0;
}
//Front Inturrupt is not working properly
void Inturrupt_Front(void) {
  Front_Ticks++;
  //Serial.print("Front Ticks == ");
  //Serial.println(Front_Ticks);
}
void Inturrupt_Back(void) {
  Back_Ticks++;
  //Serial.print("Back Ticks == ");
  //Serial.println(Back_Ticks);
}
// ------------------------------------------------------------------
//                    O T H E R  V A R I A B L E S
// ------------------------------------------------------------------
int previous = 0;
int current = 0;
int difference = 0;
int check = 0;
int out = 0;
int potted = 0;
//Variables for definig line following Variables

bool leftback;
bool midback;
bool rightback;
bool xleftback;
bool xrightback;

bool rightfront;
bool midfront;
bool leftfront;

bool xbackright;
bool xbackleft;

bool xtreamright;
bool xtreamleft;

//Temporary variables for wall following
float mean_dis;
float volts;
float distance;
//Sensor values for wall following
float FrontRightIR = 0;
float FrontIR = 0;
float RightFrontIR = 0;
float RightBackIR = 0;
int l=0;
int r=0;
bool wall_check = HIGH;
int first = 0;
float a, b, c; //allignment variables
// ------------------------------------------------------------------
//                      S E T U P  F U N C T I O N
// ------------------------------------------------------------------
void setup() {
  // ------------------------------------------------------------------
  //                     P I N  M O D E
  // ------------------------------------------------------------------
  // S E N S O R S
  pinMode(A0, INPUT); pinMode(A1, INPUT); pinMode(A2, INPUT);
  pinMode(A3, INPUT); pinMode(A4, INPUT); pinMode(A5, INPUT);
  pinMode(A6, INPUT); pinMode(A7, INPUT); pinMode(A8, INPUT);
  pinMode(A9, INPUT); pinMode(A10, INPUT); pinMode(A11, INPUT);
  pinMode(A12, INPUT); pinMode(A13, INPUT); pinMode(A14, INPUT);
  pinMode(A15, INPUT);
  // M O T O R S
  pinMode(4, OUTPUT); pinMode(5, OUTPUT); pinMode(6, OUTPUT);
  pinMode(7, OUTPUT); pinMode(8, OUTPUT); pinMode(9, OUTPUT);
  pinMode(10, OUTPUT); pinMode(11, OUTPUT);
  // S E R V O
  RightServo.attach(39);
  LeftServo.attach(41);
  holder.attach(49);
  // initial positions
  RightServo.write(50);
  LeftServo.write(37);
  holder.write(45);
  // C O L O R  S E N S O R
  pinMode (s0, OUTPUT); pinMode (s1, OUTPUT); pinMode (s2, OUTPUT);
  pinMode (s3, OUTPUT); pinMode (sout, INPUT);
  digitalWrite(s0, LOW);
  digitalWrite(s1, HIGH);
  // E N C O D E R S
  pinMode(Encoder_Front, INPUT);
  pinMode(Encoder_Back, INPUT);
  attachInterrupt(digitalPinToInterrupt(Encoder_Front), Inturrupt_Front, RISING);
  attachInterrupt(digitalPinToInterrupt(Encoder_Back), Inturrupt_Back, RISING);
  Initialize_Encoders();
  check = 0;
  out = 0;
  potted = 0;
  cheq = 0;
  wall_check = HIGH;
  Serial.begin(9600);
  Serial.println("\t\tTICKS INITIALIZED\n");
}

// ------------------------------------------------------------------
//                    L O O P
// ------------------------------------------------------------------     ///////////////////////////////////LOOOOOOOOOOOOOOOOOOOOOOOOOOOOP/////////////////////////////////////////

void loop() {
  //Wall_Allign();
  Backward(80);
  //Line_Follow();
  //color_new();
  //Back_Follow();
  //Serial.println(IR_Read(A1));
   //LINE();
  //extra_color();
  //Line_Sensors();
  //mine_curve();
  //Sense_Color();
  //Backward(120);
  //Forward(100);
  //Blue();
  //Yellow();
  //while(1){};
  //Green();
  //Red();
  //LeftServo.write(0);
  //RightServo.write(120);
  //while(1);
  //RightServo.write(90);
  //LeftServo.write(0);
  //Get_RGB();
  //Serial.println(IR_Read(A1));
  //WALL();
  //Wall_Allign();
  //Back_Sensors();
  //holder.write(100);
  //Allign_Line();
  //Backward(70);
  //Back_Follow();
  //Serial.println(IR_Read(A1));
  //Serial.println(analogRead(A1));
  //Wall_Sensors();
  //Back_Sensors();
  //Allign_Line();
  //Line_Follow();
  //Serial.println(digitalRead(MidFront));
  //Line_Sensors();
}

void extra_color() {
    int a12 = 0, a13 = 0, a14 = 0, diff = 0;
  for (int i = 0; i < 30; i++) {
    a12 += analogRead(A12);
    a13 += analogRead(A13);
    a14 += analogRead(A14);
  }
  a12 = a12 / 30; a13 = a13 / 30; a14 = a14 / 30;
  Serial.print(a12);Serial.print("\t");
  Serial.print(a13); Serial.print("\t");
  Serial.print(a14);Serial.print("\t");

  diff = a14 - a12;
  Serial.println(diff);
  int red, blue, green, yellow;
  red = 0; blue = 0; green = 0; yellow = 0;
  
 for (int var = 0; var < 100; var++) {
    if (a13 >= 600) {
      yellow++;
    }
    else if (  a13 <= 250 && a13 >= 100 && diff>=200&&diff<300) {
      green++;
    }
    else if (a12>500&&a12<=780&&a13>300&&a13<380  ) {
      red++;
    }
    else if (  a12 >= 500 && a12 <= 780) {
      blue++;
    }
  }
  if ((red > blue && red > green) && (red > yellow)) {
    Red();
    Serial.println("Red Potted");
  }
  else if ((green > blue && green > red) && (green > yellow)) {
    Green();
    Serial.println("Green Potted");
  }
  else if ((blue > red && blue > green) && (blue > yellow)) {
    Blue();
    Serial.println("Blue Potted");
    
  }
  else if ((yellow > blue && yellow > green) && (yellow > red)) {
    Yellow();
    Serial.println("Yellow Potted");
  }
  delay(100);
}


void color_new() {
  delay(400);
  int colorval = 0;
  for (int i = 0; i < 25; i++) {
    //delay(20);
    colorval += analogRead(A15);
  }
  colorval = colorval / 25;
  Serial.println(colorval);
  int red, blue, green, yellow;
  red = 0; blue = 0; green = 0; yellow = 0;

  for (int var = 0; var < 10; var++)
  {

    if (colorval >= 40 && colorval <= 52)
    {
      blue++;
      //blue();
    }
    if (colorval > 52 && colorval <= 90)
    {
      red++;
      //Red();
    }
    if (colorval >= 20 && colorval < 40)
    {
      green++;
      //Green();
    }
    if (colorval > 90 && colorval <= 200)
    {
      yellow++;
      //Yellow();
    }
  }

  if ((red > blue && red > green) && (red > yellow))
  {
    Red();
  }
  else if ((blue > red && blue > green) && (blue > yellow))
  {
    Blue();
  }
  else if ((green > blue && green > red) && (green > yellow))
  {
    Green();
  }
  else if ((yellow > blue && yellow > green) && (yellow > red))
  {
    Yellow();
  }
}

void Forward(int pwm) {
  analogWrite (Motor1_A, 1.7 * pwm); analogWrite (Motor1_B, 1.7 * pwm);
  analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);

  analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
  analogWrite (Motor2_C, pwm); analogWrite (Motor2_D, pwm);
}
void ForwardR(int pwm) {
  analogWrite (Motor1_A, 1.7 * pwm); analogWrite (Motor1_B, 1.7 * pwm);
  analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);

  analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
  analogWrite (Motor2_C, 0.9*pwm); analogWrite (Motor2_D, 0.9*pwm);
}
void ForwardL(int pwm) {
  analogWrite (Motor1_A, 1.7 * pwm); analogWrite (Motor1_B, 1.7 * pwm);
  analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);

  analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
  analogWrite (Motor2_C, 1.2*pwm); analogWrite (Motor2_D, 1.2*pwm);
}

void Backward(int pwm) {
  analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
  analogWrite (Motor1_C, 1.1 * pwm); analogWrite (Motor1_D, 1.1 * pwm);

  analogWrite (Motor2_A, pwm); analogWrite (Motor2_B, pwm);
  analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
}

void ForceBrakes() {
  analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 255);
  analogWrite (Motor1_C, 255); analogWrite (Motor1_D, 0);
  analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 255);
  analogWrite (Motor2_C, 255); analogWrite (Motor2_D, 0);
  delay(5);
}

void Brakes() {
  analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
  analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
  analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
  analogWrite (Motor2_C, 255); analogWrite (Motor2_D, 0);
  delay(5);
}
// ------------------------------------------------------------------
//                 S E N S O R  R E A D
// ------------------------------------------------------------------
void Line_Sensors() {
  Serial.print(digitalRead(LeftFront));
  Serial.print(digitalRead(MidFront));
  Serial.println(digitalRead(RightFront));
}
void Back_Sensors() {
  Serial.print(digitalRead(XLeftBack));
  Serial.print(digitalRead(LeftBack));
  Serial.print(digitalRead(MidBack));
  Serial.print(digitalRead(RightBack));
  Serial.println(digitalRead(XRightBack));
}
void Wall_Sensors() {
  Serial.print("Front Long Range Sensor == ");
  Serial.println(IR_Read(Front));
  /*
    Serial.print("Front Right Short Range Sensor == ");
    Serial.println(IR_Read(Front_Right));
    Serial.print("Right Side Front Sensor == ");
    Serial.println(IR_Read(Right_Front));
    Serial.print("Right Side Back Sensor == ");
    Serial.println(IR_Read(Right_Back));
  */
  delay(100);
}
// ------------------------------------------------------------------
//                 L I N E  F O L L O W I N G
// ------------------------------------------------------------------
void Line_Follow() {
 
  if (digitalRead(RightFront) == HIGH) {
  
    T_Left(80);
  }
  else if (digitalRead(LeftFront) == HIGH) {
 
    T_Right(80);
  }
  else if (digitalRead(MidFront) == HIGH) {
    if(digitalRead(RightFront) == HIGH)
    {
    T_Left(80);
    delay(50);}
    
    if(digitalRead(LeftFront) == HIGH)
    {
      T_Right(80);
      delay(50);
      }
    if(digitalRead(MidBack) == HIGH)
    {
    Forward(75);
  }
  }
}

void line_all(){
  int a,b;
  while(1){
      ForceBrakes(); delay(100);
      a=digitalRead(RightFront);
      b=digitalRead(LeftFront);
      if(a==HIGH){
      //Serial.println("W left");
      W_Left(140);
      delay(60);}
      else if(b==HIGH){
      W_Right(140);
      //Serial.println("W Right");
       delay(60);}
      else 
      break;  
    }
  }

void Back_Follow() {
  if (digitalRead(RightBack) == HIGH) {
    B_Left(100);
  }
  else if (digitalRead(LeftBack) == HIGH) {
    B_Right(100);
  }
  else if (digitalRead(MidBack) == HIGH) {
    Backward(90);
  }
}
void Curve_Follow() {
  if (digitalRead(RightBack) == HIGH) {
    B_Left(50);
  }
  else if (digitalRead(LeftBack) == HIGH) {
    B_Right(50);
  }
  else if (digitalRead(XLeftBack) == HIGH) {
    C_Right(100);
  }
  else if (digitalRead(XRightBack) == HIGH) {
    C_Left(100);
  }
  else if (digitalRead(MidBack) == HIGH) {
    Backward(50);
  }
}
void Slow_Follow() {
  if (digitalRead(RightBack) == HIGH) {
    B_Left(50);
  }
  else if (digitalRead(LeftBack) == HIGH) {
    B_Right(60);
  }
  else if (digitalRead(MidBack) == HIGH) {
    Backward(60);
  }
}


void RotateRightwithtick(int pwm, int ticks) {
  Brakes();
  Back_Ticks = 0;
  while (Back_Ticks <= ticks) {
    analogWrite (Motor1_A, 2.5 * pwm); analogWrite (Motor1_B, 2.5 * pwm);
    analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
    analogWrite (Motor2_A, 1.5 * pwm); analogWrite (Motor2_B, 1.5 * pwm);
    analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
  }
}


void RotateLefttwithtick(int pwm, int ticks) {
  Brakes();
  Back_Ticks = 0;
  while (Back_Ticks <= ticks) {
    analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
    analogWrite (Motor1_C, 2 * pwm); analogWrite (Motor1_D, 2 * pwm);
    analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
    analogWrite (Motor2_C, 1.5 * pwm); analogWrite (Motor2_D, 1.5 * pwm);
  }
}
void mine_curve()
{
  Backward(80); delay(900);
  ForceBrakes(); delay(100);
  RotateLefttwithtick(70, 210);
  ForceBrakes(); delay(200);
  /*int val1=IR_Read(A1);
    Serial.println(val1);
    while(val1>33){
    val1=IR_Read(A1);
    Backward(70);
    }
  */
  ForceBrakes(); delay(200);
  //Brakes();delay(400);1
  while (1);
}

///////////////////////////////////L I N E//////////////////////////////////////////
void LINE() {
  EncFor(70, 140);
  ForceBrakes(); delay(100);
  RotateRightwithtick(70, 50);
  EncFor(70, 30);
  while (check == 0) {
    if (digitalRead(MidFront) == HIGH) {
      ForceBrakes(); delay(400);
      EncBack(70, 20);
      ForceBrakes(); delay(400);
      RotateRightwithtick(70, 82);
      Brakes(); delay(400);
      EncFor(70, 20);
      check++;
    }
    else
      Forward(80);
  }

  int val1 = 0;
  while (check == 1) {
    val1 = IR_Read(A1);
    if (val1 < 28) {
      //Forward(40);
      //delay(50);
      ForceBrakes(); delay(800);
      extra_color();
      EncBack(70,15);
      Back_Ticks = 0;
      while (Back_Ticks < 240) {
        Back_Follow();
      }
      Brakes(); delay(400);
      RotateLefttwithtick(70, 60);
      ForceBrakes(); delay(50);
      EncFor(70, 60);
      check++;
    }
    else
      Line_Follow();
  }
  while (check == 2) {
    if (digitalRead(MidFront) == HIGH) {
      ForceBrakes(); delay(400);
      EncBack(70, 25);
      ForceBrakes(); delay(400);
      RotateRightwithtick(70, 85);
      //Allign_Line();
      EncFor(70, 10);
      //Brakes(); delay(400);
      check++;
    }
    else
      Forward(80);
  }

  val1 = 0;
  while (check == 3) {
    val1 = IR_Read(A1);
    if (val1 < 28) {
      //Forward(40);
      //delay(50);
      ForceBrakes(); delay(800);
      extra_color();
      EncBack(70, 20);
      Back_Ticks = 0;
      while (Back_Ticks < 700) {
        Back_Follow();
      }
      ForceBrakes(); delay(400);
      RotateRight90Ticks(70, 170);
      ForceBrakes(); delay(50);
      EncFor(70, 20);
      check++;
    }
    else
      Line_Follow();
  }

  while (check == 4) {
    if (digitalRead(MidFront) == HIGH) {
      //ForceBrakes();delay(400);
      EncFor(70, 65);
      check++;
    }
    else
      Forward(70);
  }
  while (check == 5) {
    if (digitalRead(MidFront) == HIGH) {
      Forward(40);
      delay(10);
      ForceBrakes(); delay(800);
      EncBack1(70,15);
      RotateRight90Line(70);
      Allign_Line();
      check++;
    }
    else
      Forward(70);
  }

  while (check == 6) {
    if (digitalRead(LeftBack) == HIGH && digitalRead(XRightBack) == HIGH) {
      ForceBrakes(); delay(400);
      EncBack1(70, 40);
      check++;
    }
    else
      Back_Follow();
  }

  while (check == 7) {
    if (digitalRead(LeftBack) == HIGH && digitalRead(XRightBack) == HIGH) {
      ForceBrakes(); delay(400);
      EncFor(70,20); ForceBrakes(); delay(80);
      holder.write(120);
      EncBack1(70, 25);
      Brakes(); delay(100);
      EncFor(70, 40);
      Brakes(); delay(100);
      EncBack(85,450);
      check++;
    }
    else
      Back_Follow();
  }
  while (check == 8) {
    if (digitalRead(LeftBack) == HIGH && digitalRead(XRightBack) == HIGH) {
      //Brakes();delay(800);
      EncBack(60, 50);
      //Brakes();delay(400);
      check++;
    }
    else
      Backward(60);
  }
  while (check == 9) {
    if (digitalRead(LeftBack) == HIGH && digitalRead(XRightBack) == HIGH) {
      ForceBrakes(); delay(800);
      EncBack1(70,40);
      ForceBrakes(); delay(400);
      check++;
    }
    else
      Slow_Follow();
  }
  RotateRightwithtick(70,205);
  ForceBrakes(); delay(400);
  EncFor(80, 10);
  while (check == 10) {
    val1 = IR_Read(A1);
    if (val1 < 40) {
      //Forward(50);
      //delay(50);
      ForceBrakes(); delay(800);
      EncBack(80, 10);
      ForceBrakes(); delay(400);
      RotateLefttwithtick(70,120);
      ForceBrakes(); delay(400);
      EncFor(80, 90);
      Wall_Allign();
      check++;
    }
    else
      Forward(80);
  }
  while (check == 11) {
    Wall_Following_code();
  }
  Brakes(); delay(10);
  while (1);
  /*while (check == 0){
    if (digitalRead(XRight) == HIGH){
    ForceBrakes();delay(400);
    EncBack(70,15);
    ForceBrakes();delay(5);
    RotateRight90Ticks(70,180);
    //RotateRight90Line3(70);
    ForceBrakes();delay(100);
    //EncFor(70,15);
    // EncFor(70,20);
    //Allign_Line();
    check++;
    }
    else
    Line_Follow();
    }
    while (check == 1){
    //val1=IR_Read(A1);
    if(val1<35){
      ForceBrakes();delay(50);
      EncFor(70,30);
      ForceBrakes();delay(50);
      Sense_Color();
      EncBack1(70,100);
    ForceBrakes();delay(800);
    Back_Ticks=0;
    while(Back_Ticks<200){
     Back_Follow();}
     Brakes();delay(400);
    RotateLeft90Ticks(70,130);
    Forward(80);
    delay(100);
     check++;
      }
      else
      Line_Follow();
    }
    potted=0;
    while (check == 2){
    if(digitalRead(RightFront)==HIGH && digitalRead(MidFront)==HIGH){
    ForceBrakes();delay(400);
    EncBack(70,10);
    ForceBrakes();delay(400);
    EncBack(70,5);
    ForceBrakes();delay(400);
    RotateRight90Line1(70);
    Brakes();delay(400);
    Allign_Line();
    check++;
    }
    else
    Forward(80);
    }
    while (check == 3){
    val1=IR_Read(A1);
         if(val1<35){
      ForceBrakes();delay(50);
      EncFor(70,50);
      ForceBrakes();delay(50);
      Sense_Color();
      EncBack1(70,100);
    ForceBrakes();delay(800);
    Back_Ticks=0;
    while(Back_Ticks<200){
     Back_Follow();}
     Brakes();delay(400);
    RotateLeft90Ticks(70,130);
    Forward(80);
    delay(100);
     check++;
      }
      else
      Line_Follow();
    }
    potted=0;
    while (check ==4){
    if(digitalRead(RightFront)==HIGH && digitalRead(MidFront)==HIGH){
     ForceBrakes();delay(400);
    EncFor(70,50);
    check++;
    }
    else
    Forward(70);
    }
    while (check ==5){
    if(digitalRead(MidFront)==HIGH){
     ForceBrakes();delay(800);
    EncBack1(70,10);
    RotateRight90Line(70);
    Allign_Line();
    check++;
    }
    else
    Forward(70);
    }
    while (check ==6){
    if(digitalRead(XLeftBack)==HIGH && digitalRead(XRightBack)==HIGH){
     ForceBrakes();delay(400);
    EncBack1(70,40);
    check++;
    }
    else
    Back_Follow();
    }
     while (check==7){
    if(digitalRead(XLeftBack)==HIGH && digitalRead(XRightBack)==HIGH){
    ForceBrakes();delay(400);
    EncFor(70,15);ForceBrakes();delay(80);
    holder.write(120);
    EncBack1(70,25);
    Brakes();delay(100);
    EncFor(70,40);
    Brakes();delay(100);
    EncBack1(70,400);
    check++;
    }
    else
    Back_Follow();
    }
    while (check ==8){
    if(digitalRead(XLeftBack)==HIGH && digitalRead(XRightBack)==HIGH){
    ForceBrakes();delay(800);
    EncBack1(50,40);
    ForceBrakes();delay(400);
    check++;
    }
    else
    Back_Follow();
    }
     while (check ==9){
    if(digitalRead(XLeftBack)==HIGH && digitalRead(XRightBack)==HIGH){
    ForceBrakes();delay(800);
    EncBack1(70,20);
    ForceBrakes();delay(400);
    check++;
    }
    else
    Slow_Follow();
    }
     while (check ==10){
    if(digitalRead(XLeftBack)==HIGH && digitalRead(XRightBack)==HIGH){
    ForceBrakes();delay(100);
    EncFor(70,30);
    ForceBrakes();delay(100);
    RotateRight90Line(70);
    ForceBrakes();delay(100);
    EncFor(70,110);
    ForceBrakes();delay(500);
    RotateRight90Ticks(70,105);
    ForceBrakes();delay(500);
    EncFor(70,320);
    ForceBrakes();delay(600);
    Wall_Allign();
    check++;
    }
    else
    Curve_Follow();
    }
    while (check ==11){
      Wall_Following_code();
      }
    // Back_Follow();
    //Brakes();delay(400);
  */
}
void Wall_Following_code() {
  int val1 = 0;
  val1 = IR_Read(A1);
  if (val1 < 25) {
    ForceBrakes(); delay(100);
    //EncFor(40, 10);
    extra_color();
    ForceBrakes(); delay(100);
    EncBack1(70, 115);
    Backward(50);
    delay(50);
    ForceBrakes(); delay(400);
    RotateLeft90Line5(150);
    ForceBrakes(); delay(100);
    EncFor(80, 210);
    ForceBrakes(); delay(400);
    RotateRightwithtick(70, 80);
    ForceBrakes(); delay(400);
    EncFor(80, 80);
    ForceBrakes(); delay(400);
    RotateRightwithtick(70, 35);
    ForceBrakes(); delay(400);
    EncFor(80, 220);
    //EncFor(70,150); ForceBrakes(); delay(400);

    //EncLeft(110,70); ForceBrakes(); delay(400);
    //EncLeft(110,60); ForceBrakes(); delay(400);
    //EncLeft(120,25); ForceBrakes(); delay(400);
    //EncFor(70,80); ForceBrakes(); delay(100);
    Wall_Allign();
    potted = 0;
    while (IR_Read(Right_Front) < 60) {
      Forward(80);
    }
    ForceBrakes(); delay(100);
    EncFor(70, 50); ForceBrakes(); delay(100);
    RotateRight90Line4(70);
    EncFor(70, 225); ForceBrakes(); delay(100);
    RotateRight90Line4(70);
    EncFor(70, 310); ForceBrakes(); delay(100);
    //EncRight(70,100);ForceBrakes();delay(100);
    Wall_Allign();
    while (1) {
      val1 = IR_Read(A1);
      if (IR_Read(A1) < 25) {
        ForceBrakes(); delay(100);
        //EncFor(40,20);
        ForceBrakes(); delay(100);
        //Sense_Color();
        extra_color();
        ForceBrakes(); delay(100);
        EncBack1(70, 100);
        ForceBrakes(); delay(400);
        while (1);
        break;
      }
      else {
        Forward(80);
      }
    }
  }
  else
    Forward(80);
}
void WALL() {
  if (IR_Read(Right_Front) < 36) {
    T_Right(90);
  }
  else if (IR_Read(Right_Front) > 44) {
    T_Left(90);
  }
  else {
    Wall_Allign();
    while (IR_Read(Right_Front) >= 36 && IR_Read(Right_Front) <= 44) {
      Forward(70);
    }
  }
}

int IR_Read(int SenSor) {
  mean_dis = 0;
  float valueofSensor = 0;
  for (int i = 0; i < 50; i++) {
    volts = analogRead(SenSor) * 0.0048828125;
    distance = 65 * pow(volts, -1.10);
    if (distance > 255)
    {
      distance = 0;
      i--;
    }
    mean_dis = mean_dis + distance;
  }
  mean_dis = mean_dis / 50;
  valueofSensor = map (mean_dis, 255, 0, 300, 0);

  return int(valueofSensor);
}

void Wall_Allign() {
  int count = 0;
  while (1) {
    a = 0; b = 0; c = 0;
    while (1) {
      ForceBrakes(); delay(5);
      for (int i = 0; i < 10; i++) {
        a += IR_Read(Right_Front);
        b += IR_Read(Right_Back);
      }
      a = a / 10;
      b = b / 10;
      c = a - b;
      //Serial.print(a); Serial.print("    "); Serial.print(b); Serial.print("    "); Serial.println(c);
      if (c > -1.6 && c < 1.6) {
        //Serial.println("Alligned");
        //ForceBrakes(); delay(5);
        //while(1);
        break;
      }
      else if (c > 1.6 && c < 30) {
        //Serial.println("Turn Right");
        W_Left(140);
        delay(60);
      }
      else if (c < -1.6 && c > -30 ) {
        //Serial.println("Turn Left");
        W_Right(140);
        delay(60);
      }
    }
    //ForceBrakes(); delay(5);
    count++;
    if (count == 2) {
      break;
    }
  }
}

void EncFor(int pwm, int enc) {
  Back_Ticks = 0;
  while (Back_Ticks < enc) {
    analogWrite (Motor1_A, 1.7 * pwm); analogWrite (Motor1_B, 1.7 * pwm);
    analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);

    analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
    analogWrite (Motor2_C, pwm); analogWrite (Motor2_D, pwm);
    delay(60);
  }
}


void EncBack(int pwm, int enc) {
  Back_Ticks = 0;
  while (Back_Ticks < enc) {
    analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
    analogWrite (Motor1_C, 1.1 * pwm); analogWrite (Motor1_D, 1.1 * pwm);

    analogWrite (Motor2_A, pwm); analogWrite (Motor2_B, pwm);
    analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
  }
}
void EncBack1(int pwm, int enc) {
  Back_Ticks = 0;
  while (Back_Ticks < enc) {
    analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
    analogWrite (Motor1_C, 1.15 * pwm); analogWrite (Motor1_D, 1.15 * pwm);

    analogWrite (Motor2_A, pwm); analogWrite (Motor2_B, pwm);
    analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
  }
}

/////////////////////////////////////////////////////////////////////////
////////////   COLOR SENSOR AND SERVO //////////////////////////////////
////////////////////////////////////////////////////////////////////////

void Sense_Color() {
  int R, G, B;
  int RedC = 0;
  int BlueC = 0;
  int GreenC = 0;
  int YellowC = 0;
  int sum = 0;
  R = 0; G = 0; B = 0;
  // delay(2000);
  for (int i = 0; i < 20; i++) {
    Get_RGB();
    R = R + freqR;
    G = G + freqG;
    B = B + freqB;
  }
  R = abs(R / 20); G = abs(G / 20); B = abs(B / 20);

  Serial.print(R); Serial.print("\t");
  Serial.print(G); Serial.print("\t");
  Serial.print(B); Serial.println("\t");

  if (R >= 700 && R <= 800 && G <= 200 && G >= 50 && B >= 250 && B <= 350) {
    Blue();
    BlueC++;
    //Serial.println("Blue Potted");
    //potted=1;
  }

  /*
    //New
    for (int i=0;i<8;i++){
      if(R>=115 && R<=160 && G<=220 && G>=110 && B>=190 && B<=320){
        //Yellow();
        YellowC++;
        //Serial.println("Yellow Potted");
        potted=1;
      }
      else if(R>=200 && R<=290 && G<=610 && G>=350 && B>=230 && B<=470){
       //Red();
       RedC++;
       //Serial.println("Red Potted");
       potted=1;
      }
      else if (R>=600 && R<=750 && G<=600 && G>=350 && B>=200 && B<=370){
        //Blue();
        BlueC++;
        //Serial.println("Blue Potted");
        potted=1;
        }
     else if(R>=600 && R<=750 && G<=620 && G>=350 && B>=380 && B<=700){
       // Green();
       GreenC++;
        //Serial.println("Green Potted");
        potted=1;
      }
    }
    if (YellowC>RedC && YellowC>BlueC && YellowC>GreenC)
    {Yellow();
    //Serial.println("Yellow Potted");
    }

    if (RedC>YellowC && RedC>BlueC && RedC>GreenC)
    {Red();
    //Serial.println("Red Potted");
    }
    if (BlueC>YellowC && BlueC>RedC && BlueC>GreenC)
    {Blue();
    //Serial.println("Blue Potted");
    }
    if (GreenC>YellowC && GreenC>RedC && GreenC>BlueC)
    {Green();
    //Serial.println("Green Potted");
    }

  */
  /*
     if(R>=50 && R<=150 && G<=200 && G>=70 && B>=200 && B<=350){
    Yellow();
    //Serial.println("Yellow Potted");
    potted=1;
    }
    else if(R>=150 && R<=250 && G<=750 && G>=500 && B>=400 && B<=750){
    Red();
    //Serial.println("Red Potted");
    potted=1;
    }
    else if (R>=500 && R<=650 && G<=450 && G>=350 && B>=170 && B<=250){
    Blue();
    //Serial.println("Blue Potted");
    potted=1;
    }
    else if(R>=800 && R<=1000 && G<=600 && G>=400 && B>=580 && B<=760){
    Green();
    //Serial.println("Green Potted");
    potted=1;
    }



    if(R>=70 && R<=150 && G<=10 && G>=0 && B>=5 && B<=50){
    Yellow();
    Serial.println("Yellow Potted");
    potted=1;
    }
    else if(R>=70 && R<=250 && G<=500 && G>=15 && B>=10 && B<=70){
    Red();
    Serial.println("Red Potted");
    potted=1;
    }
    else if (R>=600 && R<=800 && G<=28 && G>=10 && B>=2 && B<=15){
    Blue();
    Serial.println("Blue Potted");
    potted=1;
    }
    else if(R>=800 && R<=1200 && G<=30 && G>=10 && B>=15 && B<=30){
    Green();
    Serial.println("Green Potted");
    potted=1;
    }*/
}
void Get_RGB() {
  digitalWrite(s2, LOW); digitalWrite(s3, HIGH);
  freqB = pulseIn(sout, LOW);
  //Serial.print(freqB);Serial.print("\t");
  delay(25);
  digitalWrite(s2, LOW); digitalWrite(s3, LOW);
  freqR = pulseIn(sout, LOW);
  //Serial.print(freqR);Serial.print("\t");
  delay(25);
  digitalWrite(s2, HIGH); digitalWrite(s3, HIGH);
  freqG = pulseIn(sout, LOW);
  //Serial.println(freqG);
  delay(25);
}

void Red() {
  RightServo.write(50);
  //above
  for (pos = 50; pos >= 20; pos -= 1) // goes from 180 degrees to 0 degrees
  {
    RightServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  RightServo.write(50);
}

void Green() {
  RightServo.write(50);
  for (pos = 50; pos <= 85; pos += 1) // goes from 180 degrees to 0 degrees
  {
    RightServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  RightServo.write(50);
}
void Yellow() {
  LeftServo.write(37);
  //below
  for (pos = 37; pos >= 15; pos -= 1) // goes from 180 degrees to 0 degrees
  {
    LeftServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  LeftServo.write(37);
}
void Blue() {
  LeftServo.write(37);
  for (pos = 37; pos <= 68; pos += 1) // goes from 180 degrees to 0 degrees
  {
    LeftServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  LeftServo.write(37);
}

void Allign_Line() {
  while (1) {
    if (digitalRead(MidFront) == HIGH) {
      //EncFor(70,10);
      //ForceBrakes();
      break;
    }
    else if (digitalRead(LeftFront) == HIGH) {
      E_Right(100);
    }
    else if (digitalRead(RightFront) == HIGH) {
      E_Left(100);
    }
  }
}
void EncLeft(int pwm, int ticks) {
  Back_Ticks = 0;
  while (Back_Ticks <= ticks) {
    analogWrite (Motor1_A, 2 * pwm); analogWrite (Motor1_B, 2 * pwm);
    analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
    analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
    analogWrite (Motor2_C, 0.5 * pwm); analogWrite (Motor2_D, 0.5 * pwm);
  }
}
void EncRight(int pwm, int ticks) {
  Back_Ticks = 0;
  while (Back_Ticks <= ticks) {
    analogWrite (Motor1_A, 2 * 0.5 * pwm); analogWrite (Motor1_B, 2 * 0.5 * pwm);
    analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
    analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
    analogWrite (Motor2_C, pwm); analogWrite (Motor2_D, pwm);
  }
}
void T_Left(int pwm) {
  analogWrite (Motor1_A, 1.7 * pwm); analogWrite (Motor1_B, 1.7 * pwm);
  analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
  analogWrite (Motor2_A,0); analogWrite (Motor2_B,0);
  analogWrite (Motor2_C,0.1*pwm); analogWrite (Motor2_D,0.1*pwm);
}
void T_Right(int pwm) {
  analogWrite (Motor1_A,1.8*pwm*0.53); analogWrite (Motor1_B,1.8*pwm*0.53);
  analogWrite (Motor1_C,0); analogWrite (Motor1_D,0);
  analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
  analogWrite (Motor2_C, 1.2*pwm); analogWrite (Motor2_D, 1.2*pwm);
}
void B_Left(int pwm) {
  analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
  analogWrite (Motor1_C, 1.1 * pwm); analogWrite (Motor1_D, 1.1 * pwm);
  analogWrite (Motor2_A, 0.5 * pwm); analogWrite (Motor2_B, 0.5 * pwm);
  analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
}
void B_Right(int pwm) {
  analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
  analogWrite (Motor1_C, 1.1 * 0.5 * pwm); analogWrite (Motor1_D, 1.1 * 0.5 * pwm);
  analogWrite (Motor2_A, pwm); analogWrite (Motor2_B, pwm);
  analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
}
void C_Left(int pwm) {
  analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
  analogWrite (Motor1_C, 1.15 * pwm); analogWrite (Motor1_D, 1.15 * pwm);
  analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
  analogWrite (Motor2_C, pwm); analogWrite (Motor2_D, pwm);
}
void C_Right(int pwm) {
  analogWrite (Motor1_A, 2 * pwm); analogWrite (Motor1_B, 2 * pwm);
  analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
  analogWrite (Motor2_A, pwm); analogWrite (Motor2_B, pwm);
  analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
}
void W_Left(int pwm) {
  analogWrite (Motor1_A, 1.5 * pwm); analogWrite (Motor1_B, 1.5 * pwm);
  analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
  analogWrite (Motor2_A, pwm); analogWrite (Motor2_B, pwm);
  analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
}
void W_Right(int pwm) {
  analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
  analogWrite (Motor1_C, 1.15 * pwm); analogWrite (Motor1_D, 1.15 * pwm);
  analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
  analogWrite (Motor2_C, pwm); analogWrite (Motor2_D, pwm);
}
void E_Left(int pwm) {
  analogWrite (Motor1_A, 1.53 * pwm); analogWrite (Motor1_B, 1.53 * pwm);
  analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
  analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
  analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
}
void E_Right(int pwm) {
  analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
  analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
  analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
  analogWrite (Motor2_C, pwm); analogWrite (Motor2_D, pwm);
}

void RotateLeft90Line5(int pwm) {
  //Works with 70 pwm
  Brakes();
  Back_Ticks = 0;
  while (Back_Ticks <= 320) {
    analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
    analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
    analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
    analogWrite (Motor2_C, 1.5 * pwm); analogWrite (Motor2_D, 1.5 * pwm);
  }
}


void RotateLeft90Line(int pwm) {
  //Works with 70 pwm
  Brakes();
  Back_Ticks = 0;
  while (Back_Ticks <= 120) {
    analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
    analogWrite (Motor1_C, 2 * pwm); analogWrite (Motor1_D, 2 * pwm);
    analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
    analogWrite (Motor2_C, 1.5 * pwm); analogWrite (Motor2_D, 1.5 * pwm);
  }
}

void RotateRight90Ticks(int pwm, int ticks) {
  //Works with 70 pwm
  Brakes();
  Back_Ticks = 0;
  while (Back_Ticks <= ticks) {
    analogWrite (Motor1_A, 2.5 * pwm); analogWrite (Motor1_B, 2.5 * pwm);
    analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
    analogWrite (Motor2_A, 1.5 * pwm); analogWrite (Motor2_B, 1.5 * pwm);
    analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
  }
}
void RotateLeft90Ticks(int pwm, int ticks) {
  //Works with 70 pwm
  Brakes();
  Back_Ticks = 0;
  while (Back_Ticks <= ticks) {
    analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
    analogWrite (Motor1_C, 2 * pwm); analogWrite (Motor1_D, 2 * pwm);
    analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
    analogWrite (Motor2_C, 1.5 * pwm); analogWrite (Motor2_D, 1.5 * pwm);
  }
}

void RotateRight90Line(int pwm) {
  //Works with 70 pwm
  Brakes();
  Back_Ticks = 0;
  while (Back_Ticks <= 150) {
    analogWrite (Motor1_A, 2.5 * pwm); analogWrite (Motor1_B, 2.5 * pwm);
    analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
    analogWrite (Motor2_A, 1.5 * pwm); analogWrite (Motor2_B, 1.5 * pwm);
    analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
  }
}
void RotateRight90Line1(int pwm) {
  //Works with 70 pwm
  Brakes();
  Back_Ticks = 0;
  while (Back_Ticks <= 160) {
    analogWrite (Motor1_A, 2.5 * pwm); analogWrite (Motor1_B, 2.5 * pwm);
    analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
    analogWrite (Motor2_A, 1.5 * pwm); analogWrite (Motor2_B, 1.5 * pwm);
    analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
  }
}

void RotateRight90Line2(int pwm) {
  //Works with 70 pwm
  Brakes();
  Back_Ticks = 0;
  while (Back_Ticks <= 130) {
    analogWrite (Motor1_A, 2.5 * pwm); analogWrite (Motor1_B, 2.5 * pwm);
    analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
    analogWrite (Motor2_A, 1.5 * pwm); analogWrite (Motor2_B, 1.5 * pwm);
    analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
  }
}

void RotateRight90Line3(int pwm) {
  //Works with 70 pwm
  Brakes();
  Back_Ticks = 0;
  while (Back_Ticks <= 200) {
    analogWrite (Motor1_A, 2.5 * pwm); analogWrite (Motor1_B, 2.5 * pwm);
    analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
    analogWrite (Motor2_A, 1.5 * pwm); analogWrite (Motor2_B, 1.5 * pwm);
    analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
  }
}

void RotateRight90Line4(int pwm) {
  //Works with 70 pwm
  Brakes();
  Back_Ticks = 0;
  while (Back_Ticks <= 120) {
    analogWrite (Motor1_A, 2.5 * pwm); analogWrite (Motor1_B, 2.5 * pwm);
    analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
    analogWrite (Motor2_A, 1.5 * pwm); analogWrite (Motor2_B, 1.5 * pwm);
    analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
  }
}


void RotateLeft90(int pwm) {
  //Works with 70 pwm
  Brakes();
  Back_Ticks = 0;
  while (Back_Ticks <= 160) {
    analogWrite (Motor1_A, 0); analogWrite (Motor1_B, 0);
    analogWrite (Motor1_C, 2 * pwm); analogWrite (Motor1_D, 2 * pwm);
    analogWrite (Motor2_A, 0); analogWrite (Motor2_B, 0);
    analogWrite (Motor2_C, 1.5 * pwm); analogWrite (Motor2_D, 1.5 * pwm);
  }
}

void RotateRight90(int pwm) {
  //Works with 70 pwm
  Brakes();
  Back_Ticks = 0;
  while (Back_Ticks <= 210) {
    analogWrite (Motor1_A, 2.2 * pwm); analogWrite (Motor1_B, 2.2 * pwm);
    analogWrite (Motor1_C, 0); analogWrite (Motor1_D, 0);
    analogWrite (Motor2_A, 1.5 * pwm); analogWrite (Motor2_B, 1.5 * pwm);
    analogWrite (Motor2_C, 0); analogWrite (Motor2_D, 0);
  }
}

