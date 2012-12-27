#ifndef __BATTLE_SCENE_H__
#define __BATTLE_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;

class BattleLayer : public cocos2d::CCLayer
{

  CCParticleSystem*    m_emitter;
  CCSprite*		enemy;

public:
    //MapLayer():_label(NULL) {};
    virtual ~BattleLayer();
    bool init();
    void menuCloseCallback(CCObject* pSender);
    void attackCallback(CCObject* pSender);
    void actionCallbackN(CCNode *pSender);
    CREATE_FUNC(BattleLayer);

    //CC_SYNTHESIZE_READONLY(cocos2d::CCLabelTTF*, _label, Label);
};


class BattleScene : public cocos2d::CCScene
{
public:
    BattleScene():_layer(NULL) {};
    ~BattleScene();
    bool init();
    CREATE_FUNC(BattleScene);
  
    virtual void onEnter();
    virtual void onExit();

    CC_SYNTHESIZE_READONLY(BattleLayer*, _layer, Layer);
};

#endif // __BATTLE_SCENE_H__
