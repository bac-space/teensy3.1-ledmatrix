/*
  Teensy 3.1 and LED Matrix
 */

const int MAXCOLS = 5;
const int MAXROWS = 7;

const int rowleds[MAXROWS] =  {
  14, 15, 16, 17, 18, 19, 20
};

const int colleds[MAXCOLS] =  {
  2, 3, 4, 6, 11
};

void setup() {  
      
  // initialize the columns pins as an output.
  for (int thisPin = 0; thisPin < MAXCOLS; thisPin++) {
    // initialize the pins as output:
    pinMode(colleds[thisPin], OUTPUT);    
    // take the col pins (i.e. the cathodes) high to ensure that
    // the LEDS are off:
    digitalWrite(colleds[thisPin], HIGH);
  }

  // initialize the row pins as an output
  for (int thisPin = 0; thisPin < MAXROWS; thisPin++) {
    pinMode(rowleds[thisPin], OUTPUT);
  }

}

void loop() {
  // for each column, turn on and off an LED in each row
  for (int col = 0; col < MAXCOLS; col++) {
    digitalWrite(colleds[col], LOW);

    for (int row = 0; row < MAXROWS; row++) {
      digitalWrite(rowleds[row], HIGH);
      delay(500);
      digitalWrite(rowleds[row], LOW);
    }
    digitalWrite(colleds[col], HIGH);
  }

}
