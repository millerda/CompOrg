//**************
//IR receive demo v1.0
//Connect the IR sent pins to A4 for this demo
//By:http://www.seeedstudio.com/
//******************************
#include <IRSendRev.h>
//#include <IRSendRevInt.h>

void setup()
{  
    Serial.begin(38400);
    IR.Init(A4);
    Serial.println("Startin' shit.");
    int count = 0;
}

unsigned char dta[20];
unsigned char instruction[16];
    int pc = 0;
    boolean dvar = true;
    
    int bLed = 7;
    int rLed = 5;
    int gLed = 4;

void loop()
{
    if(IR.IsDta())
    {
        int length= IR.Recv(dta);
      
        for(int i=0;i<length;i++)
        {
            instruction[i] = dta[i];
            Serial.print(dta[i]);
        }
        Serial.println();
    }
    
    if(instruction[13]==1)
        digitalWrite(bLed, HIGH);
    else if(instruction[13]==0)
        digitalWrite(bLed, LOW);

    if(instruction[14]==1)
        digitalWrite(rLed, HIGH);
    else if(instruction[14]==0)
        digitalWrite(rLed, LOW);   
     
    if(instruction[15]==1)
        digitalWrite(gLed, HIGH);
    else if(instruction[15]==0)
        digitalWrite(gLed, LOW);
      
    //delay(1000);  
}
