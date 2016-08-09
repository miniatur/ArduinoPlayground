int n, i = 3, count, c;
String inString = "";
void setup() {
 
Serial.begin(9600);
}

void loop() {

   Serial.println("Enter the number of prime numbers required\n");
   while(Serial.available() == 0){}
   //-----------Start insert -----------


   
   
   //----------end instert------------------
   
   n = Serial.parseInt();
 
   if ( n >= 1 )
   {
      Serial.print("First "); Serial.print(n); Serial.println(" prime numbers are");
      Serial.println("2");
   }
 
   for ( count = 2 ; count <= n ;  )
   {
      for ( c = 2 ; c <= i - 1 ; c++ )
      {
         if ( i%c == 0 )
            break;
      }
      if ( c == i )
      {
         Serial.println(i);
         count++;
      }
      i++;
   }
 
   return 0;

}


