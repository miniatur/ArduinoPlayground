/*TODO 
	Show Ring aprox of bat value on boot
	standardize voltage devider
	autoestimate cellcount
	init procedure and stores vaues to eprom
*/
//Includes
#include <Adafruit_NeoPixel.h>


//Defines
#define PIN 13
#define LOWV 830
#define MEDV 801
#define HI

//Init Neo Pixel
Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);

//Global Vars Init
	double y;
	int batMode;
	int cellcountd

	
void setup() {
	//Start Neo Pixel
	strip.begin();
	strip.show();

	//debug Serial
	Serial.begin(9600);}

	
	
//begin program
void loop() {

//int BatV with RAW read - CheckBat normalizes all following readings 
	y=analogRead(0);
//TODO 1

//mainLoop
while(1){

batMode=checkBatV();
colDir();

}}

//pixel ring animations
		void scanCW(){
		  for(int x=0; x<16; x++){
			strip.setPixelColor((15+x)%16,0,0,0);
			strip.setPixelColor((16+x)%16,  0,0,50);
			strip.show();
			delay(100);
		   }
		  
		  }

		void scanCWCCW(){
		  for(int x=0; x<16; x++){
			strip.setPixelColor((15+x)%16,0,0,0);
			strip.setPixelColor((16+x)%16,  0,0,50);
			strip.setPixelColor((15-x)%16,0,0,50);
			strip.setPixelColor((16-x)%16,  0,0,0);
			strip.show();
			delay(100);
		   }
		  
		  }

		void scanhalfCWCCW(){
		  strip.setPixelColor(7,0,0,0);
		  strip.setPixelColor(8,0,0,0);
		  for(int x=0; x<8; x++){
			strip.setPixelColor((15+x)%16,0,0,0);
			strip.setPixelColor((16+x)%16,  0,0,50);
			strip.setPixelColor((15-x)%16,0,0,50);
			strip.setPixelColor((16-x)%16,  0,0,0);
			strip.show();
			delay(100);
		   }
		  
		  }

void colDir(){
    
    
    strip.setPixelColor(7,0,0,0);
    strip.setPixelColor(8,0,0,0);
  if(batMode==1){
  for(int x=0; x<8;x++){
    if(x<=0){
      strip.setPixelColor(0 , 255,255,255);
      strip.setPixelColor(15 , 255,255,255);}
    //if(x>=1&&x<3){
    if(x>=1){
      strip.setPixelColor((15+x)%16,0,0,0);
      strip.setPixelColor((16+x)%16,0,25,0);
      strip.setPixelColor((15-x)%16,0,25,0);
      strip.setPixelColor((16-x)%16,0,0,0);}
     
    /*if(x>=3&&x<6){
      strip.setPixelColor((15+x)%16,0,0,0);
      strip.setPixelColor((16+x)%16,0,0,25);
      strip.setPixelColor((15-x)%16,0,0,25);
      strip.setPixelColor((16-x)%16,0,0,0);
     }*/
    if(x>=6){
      strip.setPixelColor((15+x)%16,0,0,0);
      strip.setPixelColor((16+x)%16,25,0,0);
      strip.setPixelColor((15-x)%16,25,0,0);
      strip.setPixelColor((16-x)%16,0,0,0);
    }

    //Stay permanent on
    strip.setPixelColor(0 , 50,50,50);
    strip.setPixelColor(15 , 50,50,50);
    strip.setPixelColor(7 , 100,0,0);
    strip.setPixelColor(8 , 100,0,0);
    strip.show();
    delay(30);
   
  }}

//BAT LOW Mode Animation
  if(batMode==0){
  for(int x=0; x<8;x++){
    if(x<=0){
      strip.setPixelColor(0 , 255,255,255);
      strip.setPixelColor(15 , 255,255,255);}
    //if(x>=1&&x<3){
    if(x>=1){
      strip.setPixelColor((15+x)%16,0,0,0);
      strip.setPixelColor((16+x)%16,25,25,0);
      strip.setPixelColor((15-x)%16,25,25,0);
      strip.setPixelColor((16-x)%16,0,0,0);}
     
    /*if(x>=3&&x<6){
      strip.setPixelColor((15+x)%16,0,0,0);
      strip.setPixelColor((16+x)%16,0,0,25);
      strip.setPixelColor((15-x)%16,0,0,25);
      strip.setPixelColor((16-x)%16,0,0,0);
     }*/
    if(x>=6){
      strip.setPixelColor((15+x)%16,0,0,0);
      strip.setPixelColor((16+x)%16,25,0,0);
      strip.setPixelColor((15-x)%16,25,0,0);
      strip.setPixelColor((16-x)%16,0,0,0);
    }

    //Stay permanent on
    strip.setPixelColor(0 , 50,50,50);
    strip.setPixelColor(15 , 50,50,50);
    strip.setPixelColor(7 , 100,0,0);
    strip.setPixelColor(8 , 100,0,0);
    //Update Pixels 
    strip.show();
    delay(30);
   
  }}

 
  } 

//void colInit(){;}

int checkBatV(){return checkBatV(0);
	//redirect to checkBatV(int cellcount) so it can get called with standart cellcount or autoEstimate
	//todo autoestimate (change average weight, standartize voltage devider)
	}
//cellcount not in use
int checkBatV(int cellcount){
  //average out raw voltage devider input pin
  y=0.01*analogRead(0)+0.99*y;
  Serial.println(y);
  
  //Check if Bat LOW
  if(y<LOWV){return 0;}
  if(y>LOWV){return 1;}
  }
