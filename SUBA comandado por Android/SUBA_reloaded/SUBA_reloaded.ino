#include <Thread.h>
#include <ThreadController.h>
int fadeValue = 0;
// ThreadController that will controll all threads
Thread ledThread = new Thread();

ledThread.enabled = true; // Default enabled value is true
ledThread.setInterval(10); // Setts the wanted interval to be 10ms
/*
    This is useful for debugging
    (Thread Name is disabled by default, to use less memory)
    (Enable it by definint USE_THREAD_NAMES on 'Thread.h')
*/
myThread.ThreadName = "myThread tag";
// This will set the callback of the Thread: "What should I run"?
myThread.onRun(callback_function); //

ledThread.setInterval(10);
ledThread.onRun(ledFading);

void ledFading(){
	for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(10, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(10, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}

void setup()
{
	pinMode(13, OUTPUT);
	pinMode(10, OUTPUT);
	ledThread.run();
}

void loop()
 {
 	digitalWrite(13, LOW);
 	delay(500);
 	digitalWrite(13, HIGH);
 	delay(500);
 } 