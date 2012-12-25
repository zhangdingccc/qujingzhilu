#include "MapScene.h"
#include "AppMacros.h"
#include "MapControllerScene.h"
#include "City.h"
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
    pSprite = City::create("home.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/4 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
CCLOG("Test String");
    // add city
    pSprite = City::create("home.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width*3/4 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

		/*
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
		*/

    // Label Item (CCLabelBMFont)
    CCLabelBMFont* label = CCLabelBMFont::create("Chapters", "fonts/bitmapFontChinese.fnt");
    CCMenuItemLabel* item1 = CCMenuItemLabel::create(label, this, menu_selector(MapLayer::menuCloseCallback));
    #define FONT_SCALE 1.5f
    item1->setScale( FONT_SCALE );

    item1->setPosition(ccp(origin.x + visibleSize.width - item1->getContentSize().width*FONT_SCALE/2 - item1->getContentSize().height*FONT_SCALE/2,
                                    origin.y + item1->getContentSize().height*FONT_SCALE));
    CCMenu* menu = CCMenu::create( item1, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 1);

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
