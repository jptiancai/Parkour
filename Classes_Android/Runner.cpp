#include "Runner.h"
#include "GameOver.h"
#include "Size.h"

USING_NS_CC;

bool Runner::init(){
	//加载图片到缓存池
	auto frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("parkour.plist","parkour.png");

	m_runner = Sprite::createWithSpriteFrameName("runner0.png");

	run_jumpSize = m_runner->getContentSize();
	crouchSize = Sprite::createWithSpriteFrameName("runnerCrouch0.png")->getContentSize();

	this->addChild(m_runner);

	initActionSet(frameCache);//初始化动作集合

	initBody();

	this->scheduleUpdate();

	this->setTag(1);

	return true;
}

void Runner::initActionSet(SpriteFrameCache* frameCache){
	SpriteFrame* frame = NULL;
	//3.0中改用vector 而不是用Array
	Vector<SpriteFrame*>frameVector;
	
	/* 1.----------------加载跑动的Animation-----------------*/
	for(int i = 0; i <= 7; i ++) {
		//从缓存池中加载精灵到Vector
		frame = frameCache->spriteFrameByName(String::createWithFormat("runner%d.png",i)->getCString());
		frameVector.pushBack(frame);
	}

	//用vector里面的SpriteFrame列表创建Animation  以及设置一些参数
	auto run_animation = Animation::createWithSpriteFrames(frameVector,0.1f,-1);
	//将跑动的 Animation 取名为 running 
	AnimationCache::getInstance()->addAnimation(run_animation,"running");
	
	/*4---------------*/
	frameVector.clear();
	for(int i = 0; i <= 3; i ++){
		frame = frameCache->spriteFrameByName(String::createWithFormat("runnerJumpUp%d.png",i)->getCString());
		frameVector.pushBack(frame);
	}
	auto jumpUp_animation = Animation::createWithSpriteFrames(frameVector,0.2);//不设置无限循环
	AnimationCache::getInstance()->addAnimation(jumpUp_animation,"jumpUp");

	/**/
	frameVector.clear();
	for(int i = 0; i <= 1; i ++){
		frame = frameCache->spriteFrameByName(String::createWithFormat("runnerJumpDown%d.png",i)->getCString());
		frameVector.pushBack(frame);
	}
	auto jumpDown_animation = Animation::createWithSpriteFrames(frameVector,0.3);
	AnimationCache::getInstance()->addAnimation(jumpDown_animation,"jumpDown");

	/**/
	frameVector.clear();
	frame = frameCache->spriteFrameByName("runnerCrouch0.png");
	frameVector.pushBack(frame);
	auto crouch_animation = Animation::createWithSpriteFrames(frameVector,0.3);//不设置无限循环
	AnimationCache::getInstance()->addAnimation(crouch_animation,"crouch");

}

void Runner::doAction(const char* actionName){
	auto animation = AnimationCache::getInstance()->animationByName(actionName);
	auto action = Animate::create(animation);
	m_runner->runAction(action);
}

void Runner::initBody(){
	//根据不同状态设置不同刚体大小
	Size bodySize;
	if(m_state == crouch){
		bodySize = crouchSize;
	}
	else{
		bodySize = run_jumpSize;
	}

	bodySize.width -= 15;
	bodySize.height -= 15;
	//创建runner的刚体
	auto runerBody = PhysicsBody::createBox(bodySize,PHYSICSBODY_MATERIAL_DEFAULT);

	//设置可以碰撞检测
	runerBody->setCategoryBitmask(1);
	runerBody->setCollisionBitmask(1);
	runerBody->setContactTestBitmask(1);

	//绑定刚体
	this->setPhysicsBody(runerBody);
}

void Runner::Run(){
	m_state = running;
	initBody();
	doAction("running");
	this->setPosition(runner_posX,ground_hight+getRunJumpSize().height/2);
}

/**/
void Runner::Jump(){
	//只有在跑动时才能起跳
	if(m_state == running){
		m_state = jumpUp;
		
		auto mass = this->getPhysicsBody()->getMass()*200;

		this->getPhysicsBody()->applyImpulse(Vect(0,mass));

	    m_runner->stopAllActions();

	    doAction("jumpUp");
	}
}

void Runner::update(float dt){
	auto vel = this->getPhysicsBody()->getVelocity();
	if(m_state == jumpUp){
		if(vel.y < 0.1){
			m_state = jumpDown;
			m_runner->stopAllActions();
			doAction("jumpDown");
		}
	}

	if(m_state == jumpDown){
		CCLOG("%f",vel.y);
		//不应该是 等于 0
		if(vel.y > 0){
			m_runner->stopAllActions();
			Run();
		}
	}
}

void Runner::Crouch(){
	//只能在跑动的时候蹲下
	if(m_state == running){
		m_state = crouch;
		m_runner->stopAllActions();
		initBody();
		doAction("crouch");
		this->setPosition(runner_posX,ground_hight+getCrouchSize().height/2);
	}
}