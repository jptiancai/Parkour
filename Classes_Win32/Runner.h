#ifndef __Runner__H__
#define __Runner__H__

#include "cocos2d.h"

enum runnerState{
	running,
	jumpUp,
	jumpDown,
	crouch
};

class Runner : public cocos2d::Node{
public:
	virtual bool init();
	CREATE_FUNC(Runner);

	//初始化 action 集合
	void initActionSet(cocos2d::SpriteFrameCache* frameCache);

	//根据动作名称执行动作
	void doAction(const char* actionName);//
	//初始化物理刚体
	void initBody();
	//获取当前的状态，后面要用到
	runnerState getState(){ return m_state;};
	//获取不同时候的Size
	cocos2d::Size getRunJumpSize(){ return run_jumpSize;};
	cocos2d::Size getCrouchSize() { return crouchSize;};

	void Run();
	void Jump();

	void Crouch();

	virtual void update(float dt);
private:
	//  需要一个主要的精灵执行动作
	cocos2d::Sprite* m_runner;

	// 不同的动作需要不同的刚体大小,跑和跳的大小一样
	cocos2d::Size run_jumpSize;
	//蹲下来的大小
	cocos2d::Size crouchSize;

	runnerState m_state;
};

#endif