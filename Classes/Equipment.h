//
//  Equipment.h
//  qujingzhilu
//
//  Created by Ding Zhang on 24/12/12.
//
//

#ifndef __qujingzhilu__Equipment__
#define __qujingzhilu__Equipment__

#include "cocos2d.h"

USING_NS_CC;

class Equipment
{
    private:
    public:
    CCString name;
    CCInteger type;//weapon, armor etc..
    CCInteger value;
    CCImage image;
};

#endif /* defined(__qujingzhilu__Equipment__) */
