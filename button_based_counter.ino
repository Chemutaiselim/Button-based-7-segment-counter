// Declaring pins connected to the 7 seg display
int a = 13; //For displaying segment "a"
int b = 12; //For displaying segment "b"
int c = 11; //For displaying segment "c"
int d = 10; //For displaying segment "d"
int e = 9; //For displaying segment "e"
int f = 8; //For displaying segment "f"
int g = 7; //For displaying segment "g"
// Declaring pins connected to push buttons
int up = 4;
int down = 3;
// A counter variable to keep track of push buttons
int counter = 0;
// Function for pin mode: output/inputs
void setup() {
 pinMode(a, OUTPUT); //A
 pinMode(b, OUTPUT); //B
 pinMode(c, OUTPUT); //C
 pinMode(d, OUTPUT); //D
 pinMode(e, OUTPUT); //E
 pinMode(f, OUTPUT); //F
 pinMode(g, OUTPUT); //G
 pinMode(up, INPUT);
 pinMode(down, INPUT);
}
// A function to display the required digit based
// on the digit input.
void displayDigit(int digit) {
 //Conditions for displaying segment a
 if (digit != 1 && digit != 4)
 digitalWrite(a, HIGH);
 //Conditions for displaying segment b
 if (digit != 5 && digit != 6)
 digitalWrite(b, HIGH);
 //Conditions for displaying segment c
 if (digit != 2)
 digitalWrite(c, HIGH);
 //Conditions for displaying segment d
 if (digit != 1 && digit != 4 && digit != 7)
 digitalWrite(d, HIGH);
 //Conditions for displaying segment e
 if (digit == 2 || digit == 6 || digit == 8 || digit == 0)
 digitalWrite(e, HIGH);
 //Conditions for displaying segment f
 if (digit != 1 && digit != 2 && digit != 3 && digit != 7)
 digitalWrite(f, HIGH);
 if (digit != 0 && digit != 1 && digit != 7)
 digitalWrite(g, HIGH);
}
// Function to turn off all the leds at once
void turnOff() {
 digitalWrite(a, LOW);
 digitalWrite(b, LOW);
 digitalWrite(c, LOW);
 digitalWrite(d, LOW);
 digitalWrite(e, LOW);
digitalWrite(f, LOW);
 digitalWrite(g, LOW);
}
// Main loop displaying the counter
void loop() {
 // Reading the input buttons
 int up_state = digitalRead(up);
 int down_state = digitalRead(down);
 // Increamenting/decrementing the counter based on input states
 if (up_state == LOW) {
 counter++;
 }
 if (down_state == LOW) {
 counter--;
 }
 if (counter > 9 || counter < 0) {
 counter = 0;
 }
 // Displaying the counter
 displayDigit(counter);
 delay(200);
 turnOff();
}
