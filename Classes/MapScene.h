#ifndef __MAP_SCENE_H__
#define __MAP_SCENE_H__

#include "cocos2d.h"

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


class MapScene : public cocos2d::CCScene
{
public:
    MapScene():_layer(NULL) {};
    ~MapScene();
    bool init();
    CREATE_FUNC(MapScene);
  
    CC_SYNTHESIZE_READONLY(MapLayer*, _layer, Layer);
};

#endif // __MAP_SCENE_H__
