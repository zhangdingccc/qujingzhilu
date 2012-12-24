#include "MapScene.h"
#include "AppMacros.h"
#include "MapControllerScene.h"
//USING_NS_CC;

using namespace cocos2d;

bool MapScene::init()
{
	if( CCScene::init() )
	{
		this->_layer = MapLayer::create();
		this->_layer->retain();
		this->addChild(_layer);
		
		return true;
	}
	else
	{
		return false;
	}
}

MapScene::~MapScene()
{
	if (_layer)
	{
		_layer->release();
		_layer = NULL;
	}
}

bool MapLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }	
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    // add "map" splash screen
    CCSprite* pSprite = CCSprite::create("map.jpg");

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
    pSprite = CCSprite::create("home.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width*3/4 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

		// Create a "close" menu item with close icon, it's an auto release object.
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
			"normal.png",
			"press.png",
			this,
			menu_selector(MapLayer::menuCloseCallback));
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

void MapLayer::menuCloseCallback(CCObject* pSender)
{
#define TRANSITION_DURATION (1.2f)

	// "close" menu item clicked
	//CCDirector::sharedDirector()->end();
	CCScene *pScene = MapControllerScene::create();
	pScene = CCTransitionSlideInT::create(TRANSITION_DURATION, pScene);
    if (pScene)
    {
        CCDirector::sharedDirector()->pushScene(pScene);
    }  
}

MapLayer::~MapLayer()
{
/*
	if (_label)
	{
		_label->release();
		_label = NULL;
	}
*/
}
