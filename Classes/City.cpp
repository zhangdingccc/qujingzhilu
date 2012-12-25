#include "City.h"

City::City(void)
{
}

City::~City(void)
{
}

CCRect City::rect()
{
    CCSize s = boundingBox().size;
    return CCRectMake(-s.width / 2, -s.height / 2, s.width, s.height);
}

void City::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCSprite::onEnter();
}

void City::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    CCSprite::onExit();
}    

bool City::containsTouchLocation(CCTouch* touch)
{
    return rect().containsPoint(convertTouchToNodeSpaceAR(touch));
}

bool City::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    if (m_state != kPaddleStateUngrabbed) return false;
    if ( !containsTouchLocation(touch) ) return false;
    
    m_state = kPaddleStateGrabbed;
    return true;
}

void City::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    // If it weren't for the TouchDispatcher, you would need to keep a reference
    // to the touch from touchBegan and check that the current touch is the same
    // as that one.
    // Actually, it would be even more complicated since in the Cocos dispatcher
    // you get CCSets instead of 1 UITouch, so you'd need to loop through the set
    // in each touchXXX method.
    
    CCAssert(m_state == kPaddleStateGrabbed, L"Paddle - Unexpected state!");    
    
    CCPoint touchPoint = touch->getLocation();
    
    setPosition( ccp(touchPoint.x, getPosition().y) );
}

CCObject* City::copyWithZone(CCZone *pZone)
{
    this->retain();
    return this;
}

void City::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    CCAssert(m_state == kPaddleStateGrabbed, L"Paddle - Unexpected state!");    
    
    m_state = kPaddleStateUngrabbed;
} 

void City::touchDelegateRetain()
{
    this->retain();
}

void City::touchDelegateRelease()
{
    this->release();
}
