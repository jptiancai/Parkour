#ifndef __BaseManager__H__  
#define __BaseManager__H__  
  
#include "cocos2d.h"  
#include "Coin.h"  
#include "Rock.h"  
  
  
#define coinNum 4  
#define coinTag 2  //这里关于Tag 用于后面的碰撞检测  
#define rockNum 2  
#define rockTag 3  
  
class BaseManager : public cocos2d::Node{  
public:  
    CREATE_FUNC(BaseManager);  
    virtual bool init();  
    virtual void update(float dt);  
  
private:  
    void createCoin();  
    cocos2d::Array* m_coinArr;  
  
	void createRock();  
    cocos2d::Array* m_rockArr;  
};/**/  
  
#endif  