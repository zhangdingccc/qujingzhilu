#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class LoadingLayer : public cocos2d::CCLayer
{
    int m_numOfTotalLoadingObjects;
    int m_numOfLoadedObjects;
    CCProgressTimer* m_loadingTimer;
    CCControlSlider* m_slider;
public:
    //MapLayer():_label(NULL) {};
    virtual ~LoadingLayer();
    bool init();
    void menuCloseCallback(CCObject* pSender);
    void loadingCallBack(CCObject* pSender);
    CREATE_FUNC(LoadingLayer);

    //CC_SYNTHESIZE_READONLY(cocos2d::CCLabelTTF*, _label, Label);
};

class LoadingBar : public cocos2d::CCSprite
{
public:
    static LoadingBar* create(const char *pszFileName);
    virtual void onEnter();
};

class LoadingScene : public cocos2d::CCScene
{
public:
    LoadingScene():_layer(NULL) {};
    ~LoadingScene();
    bool init();
    CREATE_FUNC(LoadingScene);
  
    CC_SYNTHESIZE_READONLY(LoadingLayer*, _layer, Layer);
};

#endif // __LOADING_SCENE_H__
