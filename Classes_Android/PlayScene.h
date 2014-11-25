#ifndef __PlayScene__H__
#define __PlayScene__H__

#include "cocos2d.h"
#include "Runner.h"
#include "cocos-ext.h"
#include "BaseManager.h"

USING_NS_CC_EXT;

class PlayScene : public cocos2d::Layer{
public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(PlayScene);

	//这里两行的作用是：为后面的layer->setPhysicsWorld(scene->getPhysicsWorld());
	cocos2d::PhysicsWorld* m_world;
	void setPhysicsWorld(cocos2d::PhysicsWorld* world){ m_world = world;};/**/

	//初始化背景
	void initBG();

	//用update函数让地图滚动
	virtual void update(float dt);

	//Jump
	void createJumpButton();
	void jumpEvent(Ref* pSender,Control::EventType event);

	//Crouch
	void createCrouchButton();
	void crouchDown(Ref* pSender,Control::EventType event);
	void crouchUp(Ref* pSender,Control::EventType event);
	
	//碰撞检测
	//cocos2d::EventDispatcher* dispatcher;这里是不需要的
	void onEnter();
	void onExit();
	bool onContactBegin(cocos2d::PhysicsContact& contact);

	void GameOver();
	
private:

	//初始化一个地板的物理刚体
	void initPhysicWorld();

	Runner* m_runner;
	
	//背景精灵
	cocos2d::Sprite* bgSprite1;
	cocos2d::Sprite* bgSprite2;
	cocos2d::Sprite* groundSprite1;
	cocos2d::Sprite* groundSprite2;

	//
	BaseManager* m_manager;
};

#endif