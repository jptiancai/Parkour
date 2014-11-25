#ifndef __GameOver__H__  
#define __GameOver__H__  
  
#include "cocos2d.h"  
  
class GameOver : cocos2d::Layer{  
public:  
    virtual bool init();  
    static cocos2d::Scene* scene();  
    CREATE_FUNC(GameOver);  
  
    void createBG();  
  
private:  
  
    void createButton(cocos2d::Point centerPoint);  
  
    void reStart();  
};
  
#endif