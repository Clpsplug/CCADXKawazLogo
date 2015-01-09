//
//  LogoScene.h
//  KawazLogo
//
//  Created by CollapsedPlug on 1/7/15.
//
//

#ifndef __KawazLogo__LogoScene__
#define __KawazLogo__LogoScene__

#include <stdio.h>
#include "cocos2d.h"
#include "ADX2Manager.h"

class LogoScene :public cocos2d::Layer{
protected:
    LogoScene();
    virtual ~LogoScene();
    bool init() override;
    
public:
    static cocos2d::Scene* createScene();
    
    void onEnterTransitionDidFinish() override;
    void update(float dt);
    
    
    CC_SYNTHESIZE(float, _finalScale, FinalScale);
    CC_SYNTHESIZE(bool, _hasEnded, HasEnded);
    CC_SYNTHESIZE_RETAIN(cocos2d::Sprite *, _frog, Frog);
    CC_SYNTHESIZE_RETAIN(cocos2d::Sprite *, _K, K);
    CC_SYNTHESIZE_RETAIN(cocos2d::Sprite *, _a1,A1);
    CC_SYNTHESIZE_RETAIN(cocos2d::Sprite *, _w, W);
    CC_SYNTHESIZE_RETAIN(cocos2d::Sprite *, _a2,A2);
    CC_SYNTHESIZE_RETAIN(cocos2d::Sprite *, _z, Z);
    CC_SYNTHESIZE_RETAIN(cocos2d::Sprite *, _clearout, ClearOut);
    CC_SYNTHESIZE_RETAIN(cocos2d::Sprite *, _logo, Logo);
    CC_SYNTHESIZE_RETAIN(ADX2::CueSheet *, _cueSheet, CueSheet);
    
    CREATE_FUNC(LogoScene);
};

#endif /* defined(__KawazLogo__LogoScene__) */
