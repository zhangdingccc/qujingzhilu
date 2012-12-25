#ifndef _CITY_H_
#define _CITY_H_

#include "cocos2d.h"

USING_NS_CC;

typedef enum tagPaddleState 
{
    kPaddleStateGrabbed,
    kPaddleStateUngrabbed
} PaddleState; 

class City : public CCSprite, public CCTargetedTouchDelegate
{
    PaddleState        m_state;

public:
    City(void);
    virtual ~City(void);

    CCRect rect();
    virtual void onEnter();
    virtual void onExit();
    bool containsTouchLocation(CCTouch* touch);
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
    virtual CCObject* copyWithZone(CCZone *pZone);

    virtual void touchDelegateRetain();
    virtual void touchDelegateRelease();
};

#endif
