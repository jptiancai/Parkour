#include "Coin.h"  
  
USING_NS_CC;  
  
bool Coin::init(){  
    if(!Node::init()){  
        return false;  
    }  
  
    //缓存池  
    auto frameCache = SpriteFrameCache::getInstance();  
    frameCache->addSpriteFramesWithFile("parkour.plist","parkour.png");  
  
    auto sprite = Sprite::createWithSpriteFrameName("coin0.png");  
  
    //绑定  
    setSprite(sprite);  
    //执行动作  
    getSprite()->runAction(createAnimate(frameCache));  
	////设置金币为2,为碰撞做准备
	//this->setTag(2);
    //绑定刚体  
    initBody();  
  
    return true;  
}  
  
Animate* Coin::createAnimate(SpriteFrameCache* frameCache){  
  
  
    SpriteFrame* frame = NULL;  
    //数组不行 要用vector  
    //auto frameArray = Array::create();  
    //frameArray->retain();  
    Vector<SpriteFrame*>frameVector;  
  
    // 用一个列表保存所有SpriteFrame对象   
    for(int i = 0; i <= 7; i++) {  
        /* 从SpriteFrame缓存池中获取CCSpriteFrame对象 */  
        frame = frameCache->spriteFrameByName(String::createWithFormat("coin%d.png", i)->getCString());  
        frameVector.pushBack(frame);  
  
    }   
    /* 使用SpriteFrame列表创建动画对象 */  
    auto animation = Animation::createWithSpriteFrames(frameVector);  
  
    animation->setLoops(-1);  
  
    animation->setDelayPerUnit(0.1f);  
  
    /* 将动画包装成一个动作 */  
    auto action = Animate::create(animation);  
  
    return action;  
}  
  
void Coin::initBody(){  
	auto bodySize = getSprite()->getContentSize();
	
	//bodySize.width -= 20;
	//bodySize.height -= 15;
    auto phyBody = PhysicsBody::createEdgeBox(bodySize);  
    phyBody->setCategoryBitmask(1);  
    phyBody->setCollisionBitmask(1);  
    phyBody->setContactTestBitmask(1);  
      
    this->setPhysicsBody(phyBody);  
}  