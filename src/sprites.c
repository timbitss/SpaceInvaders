#include "sprites.h"

unsigned char direction = 0; // 0 = left, 1 = right
unsigned char directionBonus = 0;

/**
 * Convert ADC value to x coordinate.
 */
unsigned long ADCtoX(unsigned long ADC){
    return (ADC*16) >> 10; // m = 16/1024, b = 0
}

/**
 * Check if collision occurred based on positions of two sprites
 * Return 1 if collision occurs. Otherwise, return 0.
 */
unsigned char checkCollision(unsigned char xa, unsigned char ya, unsigned char widtha, unsigned char heighta,
								unsigned char xb, unsigned char yb, unsigned char widthb, unsigned char heightb){

    if((xb + widthb >= xa) && (yb - heightb <= ya)){
        if((xa + widtha >= xb) && (ya - heighta <= yb)) 
            return 1; 
    }

    return 0;


}

/**
 *  Move sprite based on current position and direction.
 *  direction = 0 means to go left
 *  direction = 1 means to go right
 *  
 */
void moveSprite(Sprite2 *Enemy, unsigned char numOfEnemies, unsigned char width){

    unsigned char goDown = 0;
    unsigned char i;

    if(direction){
        if((Enemy[numOfEnemies - 1].x + width == 83)){ // check rightmost enemy (regardless of hp)
            direction = 0;
            goDown = 1;
        }
    }
    else{
        if(Enemy[0].x == 0){ // check leftmost enemy (regardless of hp)
            direction = 1;
            goDown = 1;
        }
    }

    for(i = 0; i < numOfEnemies; i++){
        if(!goDown){
            if(direction)
                Enemy[i].x++; // move all sprites to the right
            else
                Enemy[i].x--; // move all sprites to the left
        }
        else
        {
            Enemy[i].y++; // move all sprites downwards
        }
        
    }



    }

/**
 * Returns row # where 1 corresponds to top row (Enemy1). Otherwise, returns 0 if no enemies in column.
 */
unsigned char checkColForEnemy(Sprite2 *Enemy1, Sprite2 *Enemy2, Sprite2 *Enemy3, unsigned char col){

    if(Enemy3[col].life)
        return BOTTOMROW;
    if(Enemy2[col].life)
        return MIDDLEROW;
    if(Enemy1[col].life)
        return TOPROW;    

    return 0;

}

/**
 *  Creates missile on given column
 */
void createEnemyMissile(Sprite *Missile, Sprite2 *Enemy, unsigned char col){
 
        if(!Missile[col].life){
            Missile[col].life = 1;
            Missile[col].x = Enemy[col].x + 6; // place missile on middle of enemy
            Missile[col].y = Enemy[col].y + 5; // account for height of missile
        }
        
}

/**
 *  Creates missile for bonus enemy
 */
void createEnemyMissileBonus(Sprite *Missile, Sprite2 *EnemyBonus, unsigned char numOfMissiles, const unsigned char* img){
    unsigned char i;

        for(i = 0; i < numOfMissiles; i++){
            if(!Missile[i].life){
                Missile[i].life = 1;
                Missile[i].x = EnemyBonus->x + 8; // place missile on middle of enemy
                Missile[i].y = EnemyBonus->y + 5; // account for height of missile
                Missile[i].image = img;
                Sound_Fastinvader2();
                return;
            }
        }
}


/**
 *  Move bonus enemy based on global direction variable and boundary conditions
 */
void moveBonusEnemy(Sprite2 *Bonus, unsigned char width){

    if(Bonus->life){
    if(!directionBonus && (Bonus->x != 0))
        (Bonus->x) -= 2;
    else if(!directionBonus && (Bonus->x == 0)){
        directionBonus = 1;
        (Bonus->y) += 2;
    }
    else if((Bonus->x + width) != 82){
        (Bonus->x) += 2;
    }
    else{
        directionBonus = 0;
        (Bonus->y) += 2;
    }
    }

    return;
}

/**
 * Either move bonus missiles or destroy bonus missiles
 */
void moveBonusMissile(Sprite *Missile, unsigned char numOfMissiles, unsigned char height){
    unsigned char i;

    for(i=0; i<numOfMissiles; i++){
        if(Missile[i].life && (Missile[i].y >= height))
            Missile[i].y--; // move missile
        else{
            Missile[i].life = 0; // destroy missile
        }
        
    }

}