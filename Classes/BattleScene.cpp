#include "BattleScene.h"
#include "AppMacros.h"
#include "MapControllerScene.h"
#include "City.h"
//USING_NS_CC;

using namespace cocos2d;

bool BattleScene::init()
{
	if( CCScene::init() )
	{
		this->_layer = BattleLayer::create();
		this->_layer->retain();
		this->addChild(_layer);
		
		return true;
	}
	else
	{
		return false;
	}
}

BattleScene::~BattleScene()
{
	if (_layer)
	{
		_layer->release();
		_layer = NULL;
	}
}

bool BattleLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }	
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    // add "map" splash screen
    CCSprite* pSprite = CCSprite::create("battlescene.jpg");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

    // add city
    City* pcity = City::create("monkey.png");

    // position the sprite on the center of the screen
    pcity->setPosition(ccp(visibleSize.width/4 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pcity, 0);

    // add city
    enemy = CCSprite::create("spider.png");

    // position the sprite on the center of the screen
    enemy->setPosition(ccp(visibleSize.width*3/4 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(enemy, 0);

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
    CCLabelBMFont* label = CCLabelBMFont::create("Back", "fonts/bitmapFontChinese.fnt");
    CCMenuItemLabel* item1 = CCMenuItemLabel::create(label, this, menu_selector(BattleLayer::menuCloseCallback));
    #define FONT_SCALE 1.5f
    item1->setScale( FONT_SCALE );

    item1->setPosition(ccp(origin.x + visibleSize.width - item1->getContentSize().width*FONT_SCALE/2 - item1->getContentSize().height*FONT_SCALE/2,
                                    origin.y + item1->getContentSize().height*FONT_SCALE));
	/*
    CCMenu* menu1 = CCMenu::create( item1, NULL);
    menu1->setPosition(CCPointZero);
    this->addChild(menu1, 1);
	*/
    label = CCLabelBMFont::create("Attack", "fonts/bitmapFontTest.fnt");
    CCMenuItemLabel* item2 = CCMenuItemLabel::create(label, this, menu_selector(BattleLayer::attackCallback));
    item2->setScale( FONT_SCALE );

    item2->setPosition(ccp(origin.x + visibleSize.width/2,
                                    origin.y + visibleSize.height - item1->getContentSize().height*FONT_SCALE));
    CCMenu* menu = CCMenu::create( item1, item2, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 1);



	return true;    
}

void BattleLayer::menuCloseCallback(CCObject* pSender)
{
#define TRANSITION_DURATION (1.2f)

	// "close" menu item clicked
	//CCDirector::sharedDirector()->end();
	/*
	CCScene *pScene = MapControllerScene::create();
	pScene = CCTransitionSlideInT::create(TRANSITION_DURATION, pScene);
    if (pScene)
    {
        CCDirector::sharedDirector()->pushScene(pScene);
    }  
	*/
	CCDirector::sharedDirector()->popScene();
}

void BattleLayer::attackCallback(CCObject* pSender)
{
m_emitter =CCParticleSun::create();
this->addChild(m_emitter, 10);
m_emitter->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire.png") );
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    if (m_emitter != NULL)
    {
        m_emitter->setPosition( ccp(s.width / 4, s.height / 2) );
    }

    CCActionInterval* move = CCMoveBy::create(2, ccp(s.width / 2,0) );
    CCActionInterval* stay = CCMoveBy::create(2, ccp(0,0) );
    
    //CCActionInterval* move_back = move->reverse();
    //CCFiniteTimeAction* seq = CCSequence::create( move, move_back, NULL);
    //m_emitter->runAction( CCRepeatForever::create((CCActionInterval*)seq) );
	m_emitter->runAction( CCSequence::create( move, stay, CCCallFuncN::actionWithTarget(this, callfuncN_selector(BattleLayer::actionCallbackN)), NULL) );

}

void BattleLayer::actionCallbackN(CCNode *pSender)  
{  
   if(m_emitter== (CCParticleSystem *) pSender)
   {
	this->removeChild(pSender);
	//CCLOG("Particle finish");
	CCActionInterval*  blink = CCBlink::create(2, 10);
	enemy->runAction( CCSequence::create( blink, CCCallFuncN::actionWithTarget(this, callfuncN_selector(BattleLayer::actionCallbackN)), NULL) );
   } 
   if(enemy == (CCSprite*) pSender)
   {
   	this->removeChild(pSender);
   }
}  

BattleLayer::~BattleLayer()
{
/*
	if (_label)
	{
		_label->release();
		_label = NULL;
	}
*/
}
