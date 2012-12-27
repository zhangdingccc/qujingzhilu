#include "LoadingScene.h"
#include "AppMacros.h"
#include "MapScene.h"


using namespace cocos2d;

bool LoadingScene::init()
{
	if( CCScene::init() )
	{
		this->_layer = LoadingLayer::create();
		this->_layer->retain();
		this->addChild(_layer);
		
		return true;
	}
	else
	{
		return false;
	}
}

LoadingScene::~LoadingScene()
{
	if (_layer)
	{
		_layer->release();
		_layer = NULL;
	}
}

bool LoadingLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }	
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    // add loading background 
    CCSprite* pSprite = CCSprite::create("loading.jpg");
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);

    // add loading bar frame
    pSprite = CCSprite::create("loadingbarframe.png");
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/4 + origin.y));
    this->addChild(pSprite, 0);

     //add loading bar timer
     /*m_loadingTimer =  CCProgressTimer::create(CCSprite::create("loadingbar.png"));
     m_loadingTimer->setType(kCCProgressTimerTypeBar);  
     m_loadingTimer->setMidpoint(ccp(0,0));
     m_loadingTimer->setBarChangeRate(ccp(1, 0));
     m_loadingTimer->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/4 + origin.y));  
     this->addChild(m_loadingTimer);  
     */
     
     //here CCControlSlider effect is better than CCProgressTimer
     m_slider = CCControlSlider::create("loadingbarframe.png", "loadingbar.png", "sliderThumb.png");  
     m_slider->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/4 + origin.y));    
     m_slider->setMinimumValue(0);  
     m_slider->setMaximumValue(100);  
     m_slider->setValue(0);  
     m_slider->setTouchEnabled(false);
     this->addChild(m_slider);  
     m_slider->retain();

    m_numOfTotalLoadingObjects = 11;
    m_numOfLoadedObjects = 0;
    // load textrues async
    CCTextureCache::sharedTextureCache()->addImageAsync("map.jpg", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("myprofile.jpg", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("mapcontroller.jpg", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("battlescene.jpg", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("enemyprofile.jpg", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("fire.png", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("home.png", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("home2.png", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("monkey.png", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("profileframe.png", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("spider.png", this, callfuncO_selector(LoadingLayer::loadingCallBack));

	return true;    
}

void LoadingLayer::loadingCallBack(CCObject* pSender)
{
++m_numOfLoadedObjects;

/*CCProgressTo* to = CCProgressTo::actionWithDuration(0.1, (int)(((float)m_numOfLoadedObjects / m_numOfTotalLoadingObjects) * 100));  
if(m_loadingTimer)
     m_loadingTimer->runAction(to); 
*/

m_slider->setValue((int)(((float)m_numOfLoadedObjects / m_numOfTotalLoadingObjects) * 100));  

//if finish loading, change scene
if(m_numOfLoadedObjects == m_numOfTotalLoadingObjects)
{
    CCScene *pScene = MapScene::create();
    if (pScene)
    {
        CCDirector::sharedDirector()->replaceScene(pScene);
    }  
}

}

LoadingLayer::~LoadingLayer()
{
/*
	if (_label)
	{
		_label->release();
		_label = NULL;
	}
*/
	if(m_slider)
	{
		m_slider->release();
		m_slider = NULL;
	}
}

LoadingBar* LoadingBar::create(const char *pszFileName)
{
    LoadingBar *pobSprite = new LoadingBar();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

void LoadingBar::onEnter()
{
    CCSprite::onEnter();

 
}
