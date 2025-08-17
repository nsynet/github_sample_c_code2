/* BEGIN: FEATURE enable/disable */
#define TERM_BAUD_RATE            (74880)  //esp8266 will output firmware print at 74880
#define TERM_BAUD_RATE_9600       (9600)   //For 3.3v 8Mhz Arduino mini,9600 is highly compatible
int debug=1;
/* END: FEATURE enable/disable */
/* step debug mechanism */
#define BP(x) { \
if(debug) { char wtbuf[1000];    delay(1);\
          sprintf(wtbuf,"\r\n******断点位于函数 %s()",__FUNCTION__ );\
          Serial.print(wtbuf);Serial.print("\r\n=>");sprintf(wtbuf,"第%03d行    ",__LINE__);\
          Serial.print(wtbuf);Serial.print(#x);Serial.println("     <==== (已经进入断点,请按回车继续执行)");    \
          while(!Serial.available()) delay(1);if(Serial.parseInt()==999) debug=0;Serial.read();}} x

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])
#endif


int printMemoryInfo() 
{
#if defined (ARDUINO_AVR_UNO)
  extern int __heap_start, *__brkval; 
  int stack_top; 

  Serial.print("Free RAM (Bytes): ");
  Serial.println((int)&stack_top - (__brkval == 0 ? (int)&__heap_start : (int)__brkval));
#elif defined (ESP8266)
  uint32_t freeHeap = ESP.getFreeHeap();  
  
  Serial.print("\nfreeHeap(Bytes)=");
  Serial.println(freeHeap);
#elif defined (ESP32)
  Serial.print("PSRAM: "); Serial.print(ESP.getFreePsram());
#elif defined (ARDUINO_RASPBERRY_PI_PICO)
  Serial.printf("ERROR:freeRam() not support this chip!\n");
#else
  Serial.printf("ERROR:freeRam() not support this chip!!\n");
#endif
  return 0;
}


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(TERM_BAUD_RATE);
  printMemoryInfo(); 
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  BP(digitalWrite(LED_BUILTIN, HIGH);)  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  BP(digitalWrite(LED_BUILTIN, LOW);)   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
