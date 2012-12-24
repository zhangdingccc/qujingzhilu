#include "MapControllerScene.h"
#include "AppMacros.h"
#include "MapScene.h"
//USING_NS_CC;

using namespace cocos2d;

bool MapControllerScene::init()
{
	if( CCScene::init() )
	{
		this->_layer = MapControllerLayer::create();
		this->_layer->retain();
		this->addChild(_layer);

		return true;
	}
	else
	{
		return false;
	}
}

void MapControllerScene::menuCloseCallback(CCObject* pSender)
{
#define TRANSITION_DURATION (1.2f)

	// "close" menu item clicked
	//CCDirector::sharedDirector()->end();
	/*CCScene *pScene = MapScene::create();
	CCTransitionMoveInL::create(TRANSITION_DURATION, pScene);
    if (pScene)
    {
        CCDirector::sharedDirector()->replaceScene(pScene);
    }  */
}

MapControllerScene::~MapControllerScene()
{

	if (_layer)
	{
		_layer->release();
		_layer = NULL;
	}

}

bool MapControllerLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }	
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    // add "map" splash screen
    CCSprite* pSprite = CCSprite::create("mapcontroller.jpg");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

    // add city
    pSprite = CCSprite::create("home.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/4 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

    // add city
    pSprite = CCSprite::create("home2.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width*3/4 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

		// Create a "close" menu item with close icon, it's an auto release object.
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
			"normal.png",
			"press.png",
			this,
			menu_selector(MapControllerLayer::menuCloseCallback));
		//CC_BREAK_IF(! pCloseItem);

		pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2,
                                    origin.y + pCloseItem->getContentSize().height/2));

		// Create a menu with the "close" menu item, it's an auto release object.
		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
		//CC_BREAK_IF(! pMenu);

		// Add the menu to HelloWorld layer as a child layer.
		this->addChild(pMenu, 1);

	return true;    
}

void MapControllerLayer::menuCloseCallback(CCObject* pSender)
{
	// "close" menu item clicked
	//CCDirector::sharedDirector()->end();
#define TRANSITION_DURATION (1.2f)

	// "close" menu item clicked
	//CCDirector::sharedDirector()->end();
	CCScene *pScene = MapControllerScene::create();
	pScene = CCTransitionSlideInB::create(TRANSITION_DURATION, pScene);
    if (pScene)
    {
        CCDirector::sharedDirector()->popSceneWithTransition<CCTransitionSlideInB>(TRANSITION_DURATION);//(pScene);
    }  
}

MapControllerLayer::~MapControllerLayer()
{
/*
	if (_label)
	{
		_label->release();
		_label = NULL;
	}
*/
}
