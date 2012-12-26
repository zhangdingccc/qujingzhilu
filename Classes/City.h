#ifndef _CITY_H_
#define _CITY_H_

#include "cocos2d.h"

USING_NS_CC;

typedef enum CityState 
{
    kCityStateTouched,
    kCityStateUnTouched
} PaddleState; 

class City : public CCSprite, public CCTargetedTouchDelegate
{
    CityState        m_state;
public:
    City(void);
    virtual ~City(void);

    static City* create(const char *pszFileName);

    CCRect rect();
    virtual void onEnter();
    virtual void onExit();
    bool containsTouchLocation(CCTouch* touch);
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

    virtual void touchDelegateRetain();
    virtual void touchDelegateRelease();
};

#endif
