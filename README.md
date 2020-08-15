# Space Invaders

I created a simple version of the Space Invaders game using the TM4C123 LaunchPad. I was introduced to the various features of the TM4C123 by taking an embedded systems course named "Shape The World" by Dr. Jonathan Valvano and Dr. Ramesh Yerraballi. To move the position of the player's ship, I utilized the ADC module with a sliding potentiometer. To produce sound, I created a 4-bit binary-weighted resistor DAC and programmed timer interrupts to play through an array of notes. To fire missiles, I had two pushbuttons configured as inputs on the microcontroller. Sprites were created using BMPs and the Nokia LCD driver was provided by the course. I was able to program sprite collisions via a blog post by Aleksey which I have linked below. Overall, I was really happy with the way the project turned out and I hope to continue learning more about embedded systems.

Implementing Sprite Collisions:
http://eekit.blogspot.com/2017/02/the-basics-of-arduino-game-programming_19.html
