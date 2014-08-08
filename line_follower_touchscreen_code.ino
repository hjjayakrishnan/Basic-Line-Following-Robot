int a[4],lef=0,righ=0,n,pr;

 int maxspeed=255;
void setup()
{
  pinMode(6,OUTPUT);
   pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
     pinMode(11,OUTPUT);
      pinMode(2,INPUT);
      pinMode(3,INPUT);
      pinMode(4,INPUT);
      pinMode(5,INPUT);
      pinMode(7,INPUT);
      pinMode(12,OUTPUT);
      pinMode(A5,INPUT);
      //  digitalWrite(13,HIGH);
        delay(5000);
}

void loop()
{
             // touch screen for varying, speed.

  /* while(analogRead(A5)>600)
   {
     
     digitalWrite(13,LOW);
 digitalWrite(12,LOW);
     if(digitalRead(2)==LOW&&digitalRead(3)==HIGH&&digitalRead(4)==HIGH&&digitalRead(5)==HIGH&& digitalRead(7)==HIGH)
     {
       maxspeed=maxspeed+10;
       if(maxspeed>255)
       maxspeed=255;
       digitalWrite(13,HIGH);
       delay(1000);
       digitalWrite(13,LOW);
     }
     else if(digitalRead(2)==HIGH&&digitalRead(3)==HIGH&&digitalRead(4)==HIGH&&digitalRead(5)==HIGH&& digitalRead(7)==LOW)
     {
       maxspeed=maxspeed-10;
       digitalWrite(12,HIGH);
       delay(1000);
       digitalWrite(12,LOW);
     }
    
   }*/
  
   
   
   
   
        
 //digitalWrite(13,HIGH);
// digitalWrite(12,HIGH);
   a[0]=digitalRead(2);
   a[1]=digitalRead(3);
   a[2]=digitalRead(4);
   a[3]=digitalRead(5);
   a[4]=digitalRead(7);

   for(n=0;n<5;n++)
     {
       if(a[n]==HIGH)//high for Black track------------------------------------------------------------------------------------------
       a[n]=1;
      else
        a[n]=0;   

     }
     //object______________________________________

     
     
     
     
     
     
     
     
   n=a[0]*(-2) + a[1]*(-1) + a[3]*1 + a[4]*2;

         if(n<0)
            {
              if(a[0]==1)
                go_left();   
              else
                go_sleft();
             pr=-1;
            }
         else if(n>0)
         {
             if(a[4]==1)
                go_right();
             else
                go_sright();

           pr=1;
         }
          else  
              {   

                if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0)
                {
                  if(pr==-1) go_left();
                  if(pr==1) go_right();
                }
                else
                   straight();
               }
               
   
} 
void go_bleft()
{
    stopbot();
  analogWrite(9,maxspeed);
  analogWrite(10,0);


}
void go_bright()
{
    stopbot();
  analogWrite(6,0);
  analogWrite(11,maxspeed);

}
void go_sleft()
{
    stopbot();
  analogWrite(6,maxspeed/2);
  analogWrite(10,maxspeed);


}
void go_sright()
{
    stopbot();
  analogWrite(6,maxspeed);
  analogWrite(10,maxspeed/2);

}
void go_left()
{
    stopbot();
  analogWrite(9,maxspeed/2);
  analogWrite(10,maxspeed);


}
void go_right()
{
    stopbot();
  analogWrite(6,maxspeed);
  analogWrite(11,maxspeed/2);

}
void stopbot()
{
  digitalWrite(6,LOW); //left1
  digitalWrite(9,LOW);//left2
  digitalWrite(10,LOW);//right1
  digitalWrite(11,LOW);//right2
}  
  
  
   

void straight()
{
    stopbot();
  analogWrite(6,maxspeed);
  analogWrite(10,maxspeed);
}
  



