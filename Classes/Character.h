//
//  Character.h
//  qujingzhilu
//
//  Created by Ding Zhang on 24/12/12.
//
//

#ifndef __qujingzhilu__Character__
#define __qujingzhilu__Character__

#include "cocos2d.h"

USING_NS_CC;

class Character
{
    private:
    public:
    CCString name;
    CCString summary;
    bool isAlive;
    CCInteger health;
    CCInteger mana;
    CCInteger attack;
    CCInteger defence;
    CCInteger magic;
    CCInteger level;
    CCInteger exp;
    CCImage image;
};

#endif /* defined(__qujingzhilu__Character__) */
