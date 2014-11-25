#ifndef __Coin__H__  
#define __Coin__H__  
  
#include "Base.h"  
  
class Coin : public Base{  
public:  
    virtual bool init();  
    CREATE_FUNC(Coin);  
  
    //金币动作  
    cocos2d::Animate* createAnimate(cocos2d::SpriteFrameCache* frameCache);  
    //物理刚体  
    void initBody();  
  
private:   
};/**/  
  
#endif  