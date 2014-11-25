#include "Rock.h"

USING_NS_CC;

bool Rock::init(){
	if(!Node::init()){
		return false;
	}

	auto frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("parkour.plist","parkour.png");

	auto sprite = Sprite::createWithSpriteFrameName("rock.png");

	setSprite(sprite);

	initBody();

	return true;
}

void Rock::initBody(){
	auto bodySize = getSprite()->getContentSize();
	
	bodySize.width -= 15;
	bodySize.height -= 20;

	auto phyBody = PhysicsBody::createEdgeBox(bodySize);
	phyBody->setCategoryBitmask(1);
	phyBody->setCollisionBitmask(1);
	phyBody->setContactTestBitmask(1);
	
	this->setPhysicsBody(phyBody);
}
