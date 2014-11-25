#ifndef __MainScene__H__
#define __MainScene__H__

#include "cocos2d.h"

class MainScene : cocos2d::Layer{
public:
	virtual bool init();
	static cocos2d::Scene* scene();
	CREATE_FUNC(MainScene);

private:
	//background
	void createBG();
	//start button
	void createButton(cocos2d::Point centerPoint);
	//before start game,load music
	void preLoadMusic();
	//menu start the game
	void start();
};/**/

#endif