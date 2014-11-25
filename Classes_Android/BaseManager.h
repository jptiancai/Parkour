#ifndef __BaseManager__H__
#define __BaseManager__H__

#include "cocos2d.h"
#include "Coin.h"
#include "Rock.h"

class BaseManager : public cocos2d::Node{
public:
	CREATE_FUNC(BaseManager);
	virtual bool init();
	virtual void update(float dt);

private:
	void createCoin();
	cocos2d::Array* m_coinArr;

	void createRock(cocos2d::Size visibleSize);
	cocos2d::Array* m_rockArr;
};/**/

#endif