#ifndef __MAP_CONTROLLER_SCENE_H__
#define __MAP_CONTROLLER_SCENE_H__

#include "cocos2d.h"

class MapControllerLayer : public cocos2d::CCLayer
{
public:
    //MapLayer():_label(NULL) {};
    virtual ~MapControllerLayer();
    bool init();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(MapControllerLayer);

    //CC_SYNTHESIZE_READONLY(cocos2d::CCLabelTTF*, _label, Label);
};


class MapControllerScene : public cocos2d::CCScene
{
public:
    MapControllerScene():_layer(NULL) {};
    ~MapControllerScene();
    int MapNum;
    int index;
    bool init();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(MapControllerScene);
  
    virtual void onEnter();
    virtual void onExit();

    CC_SYNTHESIZE_READONLY(MapControllerLayer*, _layer, Layer);
};

#endif // __MAP_CONTROLLER_SCENE_H__
