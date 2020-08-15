#ifndef SPRITES_H
#define SPRITES_H

#include "Nokia5110.h"
#include "..//tm4c123gh6pm.h"
#include "Sound.h"

#define TOPROW 1
#define MIDDLEROW 2
#define BOTTOMROW 3

struct sprite{ // holds one frame
	unsigned char x;
	unsigned char y;
	const unsigned char* image;
	long life;
};

struct sprite2{ // holds two frames
	unsigned char x;
	unsigned char y;
	const unsigned char* image[2];
	long life;
};

struct sprite3{ // holds three frames
	unsigned char x;
	unsigned char y;
	const unsigned char* image[3];
	long life;
};


typedef struct sprite Sprite;
typedef struct sprite2 Sprite2;
typedef struct sprite3 Sprite3;

extern unsigned char direction; // global direction of enemy sprite (0 = left, 1 = right)
extern unsigned char directionBonus; // global direction of enemy sprite (0 = left, 1 = right)

/**
 * Convert ADC value to x coordinate.
 */
unsigned long ADCtoX(unsigned long ADC);

/**
 * Check if collision occurred based on positions of two sprites
 * Return 1 if collision occurs. Otherwise, return 0.
 */
unsigned char checkCollision(unsigned char xa, unsigned char ya, unsigned char widtha, unsigned char heighta,
								unsigned char xb, unsigned char yb, unsigned char widthb, unsigned char heightb);

/**
 *  Move sprite based on current position and direction.
 *  direction = 0 means to go left
 *  direction = 1 means to go right
 *  
 */								
void moveSprite (Sprite2 *Enemy, unsigned char numOfEnemies, unsigned char width);

/**
 * Returns row # where 1 corresponds to top row (Enemy1). Otherwise, returns 0 if no enemies in column.
 */
unsigned char checkColForEnemy(Sprite2 *Enemy1, Sprite2 *Enemy2, Sprite2 *Enemy3, unsigned char col);

/**
 *  Creates missile on given column
 */
void createEnemyMissile(Sprite *Missile, Sprite2 *Enemy, unsigned char col);


/**
 *  Creates missile for bonus enemy
 */
void createEnemyMissileBonus(Sprite *Missile, Sprite2 *EnemyBonus, unsigned char numOfMissiles, const unsigned char* img);

/**
 *  Move bonus enemy based on global direction variable and boundary conditions
 */
void moveBonusEnemy(Sprite2 *Bonus, unsigned char width);

/**
 * Either move bonus missiles or destroy bonus missiles
 */
void moveBonusMissile(Sprite *Missile, unsigned char numOfMissiles, unsigned char height);

#endif

