#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define pin 14
#define pinTWO 13

int x;
int z;

boolean y = false;

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.clear();


  pinMode(pin, INPUT);
  pinMode(pinTWO, INPUT);
}
void loop() { 
  

  x = digitalRead(pin);
  z = digitalRead(pinTWO);

  Serial.println(x);
  
  if(x == HIGH){
    lcd.setCursor(0,0);
    lcd.print("Compra efectuada"); 
    lcd.setCursor (0,1);
    lcd.print("Valor 1.5 euros");
    y = true;
  } 
  
  if(z == HIGH){
    lcd.setCursor(0,0);
    lcd.print("Compra falhada.."); 
    lcd.setCursor (0,1);
    lcd.print("Valor 1.5 euros");
    
    y = true;
  }
  
  if(y == true){
    lcd.display();
    delay(500);
    lcd.noDisplay();
    delay(500);
    lcd.display();
    delay(500);
    lcd.noDisplay();
    delay(500);
    lcd.display();
    delay(10000);
    lcd.noDisplay();
    y = false;
  }
}
