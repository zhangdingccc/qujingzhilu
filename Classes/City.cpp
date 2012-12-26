#include "City.h"
#include "BattleScene.h"

City::City(void)
{
}

City::~City(void)
{
}

City* City::create(const char *pszFileName)
{
    City *pobSprite = new City();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

CCRect City::rect()
{
    CCSize s = getContentSize();
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
    if ( !containsTouchLocation(touch) ) 
    {
	m_state = kCityStateUnTouched;
    	return false;
    }else
    {
	m_state = kCityStateTouched;
    }
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
    /*	
    CCPoint touchPoint = touch->getLocation();
    CCLOG("touch x %f y %f", touchPoint.x, getPosition().y);
    setPosition( ccp(touchPoint.x, getPosition().y) );
    */
}

void City::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    if ( !containsTouchLocation(touch) ) 
    {
	m_state = kCityStateUnTouched;
    }else
    {
	if(m_state == kCityStateTouched)
	{
		//CCLOG("City Touched");
		BattleScene* pScene = BattleScene::create();
		if (pScene)
    		{
        		CCDirector::sharedDirector()->pushScene(pScene);
    		}  
	}
	m_state = kCityStateUnTouched;
    }
} 

void City::touchDelegateRetain()
{
    this->retain();
}

void City::touchDelegateRelease()
{
    this->release();
}
