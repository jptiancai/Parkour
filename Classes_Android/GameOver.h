#ifndef __GameOver__H__
#define __GameOver__H__

#include "cocos2d.h"
USING_NS_CC;

class GameOver : cocos2d::Layer{
public:
	virtual bool init();
	static cocos2d::Scene* scene();
	CREATE_FUNC(GameOver);

	void createBG();

	void reStart(cocos2d::Object *sneder);
};/**/

#endif