int pinI1=8;//定义 I1 接口
int pinI2=9;//定义 I2 接口
int speedpin=5;//定义 EA(PWM 调速)接口
int pinI3=10;//定义 I3 接口
int pinI4=11;//定义 I4 接口
int speedpin1=6;//定义 EB(PWM 调速)接口
void setup()
{
pinMode(pinI1,OUTPUT);
pinMode(pinI2,OUTPUT);
pinMode(speedpin,OUTPUT);
pinMode(pinI3,OUTPUT);
pinMode(pinI4,OUTPUT);
pinMode(speedpin1,OUTPUT);
}
void loop()
{
//直走
analogWrite(speedpin,98);//输入模拟值进行设定速度
 analogWrite(speedpin1,100);
 digitalWrite(pinI4,LOW);//使直流电机（右）逆时针转
 digitalWrite(pinI3,HIGH);
 digitalWrite(pinI1,HIGH);//使直流电机（左）顺时针转
 digitalWrite(pinI2,LOW);
delay(2000);


//後退
analogWrite(speedpin,98);//输入模拟值进行设定速度
 analogWrite(speedpin1,100);
 digitalWrite(pinI4,HIGH);//使直流电机（右）顺时针转
 digitalWrite(pinI3,LOW);
 digitalWrite(pinI1,LOW);//使直流电机（左）逆时针转
 digitalWrite(pinI2,HIGH);
delay(2000);

}
