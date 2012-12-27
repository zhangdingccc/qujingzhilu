#ifndef __MAP_SCENE_H__
#define __MAP_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;

class MapLayer : public cocos2d::CCLayer
{
public:
    //MapLayer():_label(NULL) {};
    virtual ~MapLayer();
    bool init();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(MapLayer);

    //CC_SYNTHESIZE_READONLY(cocos2d::CCLabelTTF*, _label, Label);
};

class ProfileLayer : public cocos2d::CCLayer
{
public:
    //MapLayer():_label(NULL) {};
    virtual ~ProfileLayer();
    bool init();
    //void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(ProfileLayer);
};

class MapScene : public cocos2d::CCScene
{
public:
    MapScene():_layer(NULL) {};
    ~MapScene();
    bool init();
    CREATE_FUNC(MapScene);

    virtual void onEnter();
    virtual void onExit();
  
    CC_SYNTHESIZE_READONLY(MapLayer*, _layer, Layer);
};

#endif // __MAP_SCENE_H__
