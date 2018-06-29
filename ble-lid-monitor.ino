#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "BluefruitConfig.h"

#define FACTORYRESET_ENABLE      1

// Create BLE object
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);

void setup() {
  Serial.println(F("BLE lid monitor"));
  Serial.println(F("-------------------------------------"));

  // Initialise the module
  Serial.print(F("Initialising the Bluefruit LE module: "));

  if ( !ble.begin(VERBOSE_MODE) )
  {
    Serial.println(F("Couldn't find Bluefruit, make sure it's in command mode & check wiring?"));
  }
  Serial.println( F("OK!") );

  if ( FACTORYRESET_ENABLE )
  {
    // Perform a factory reset to make sure everything is in a known state
    Serial.println(F("Performing a factory reset: "));
    if ( ! ble.factoryReset() ){
      Serial.println(F("Couldn't factory reset"));
    }
  }

  // Disable command echo from Bluefruit
  ble.echo(false);

  // initialize digital pin 5 as input.
  pinMode(5, INPUT);
}

void loop() {
  static uint8_t result(0);
  uint8_t temp = digitalRead(5);
  
  if(result != temp){
    result = temp;
    
    ble.print("AT+BLEUARTTX=");
    
    if(result){
      ble.println("LID open");
    }
    else{
      ble.println("LID closed");
    }

    // Check response status
    ble.waitForOK();
  }
  delay(32); // Wait for it
}
