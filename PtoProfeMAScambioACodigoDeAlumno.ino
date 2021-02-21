int buttonState;  
void setup() {
 
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, INPUT);
   
}

void loop() {

p();
buttonState=digitalRead(12);
delay(20);
boton();
delay(300);
u();    
boton();
delay(300);
t();    
boton();
delay(300);
lo();    
boton();
delay(300);
nada();   
boton();
delay(300);
p();    
boton();
delay(300);
r();    
boton();
delay(300);
lo();    
boton();
delay(300);
f();    
boton();
delay(300);
e();    
boton();
delay(300);
nada();
delay(300);

  
  

}
////LetraP
void p() {
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  delay(200);

}
////Letra U
void u() {
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  delay(200);

}
////Letra T
void t() {
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  delay(200);

}
////Letra O
void lo() {
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  delay(200);

}
////Letra R
void r() {
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  delay(200);

}
////Letra F
void f() {
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  delay(200);

}
////Letra E
void e() {
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  delay(200);

}
////Numero 1
void n1() {
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  delay(800);

}
////Numero 2
void n2() {
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(800);

}
////Numero 3
void n3() {
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(800);

}
////Numero 6
void n6() {
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  delay(800);

}

////Numero 5
void n5() {
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  delay(800);

}
////Numero 7
void n7() {
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  delay(800);

}
void nada() {
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  delay(200);

}
void codigo() {
  n2();
  n1();
  n3();
  n6();
  lo();delay(200);
  n5();
  n5();
  n7();
  n2();

}
void boton() {
  buttonState=digitalRead(12);
  delay(20);
  
  if(buttonState==LOW){
    codigo();
    }
    
}
