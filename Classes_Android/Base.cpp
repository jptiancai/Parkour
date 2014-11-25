#include "Base.h"

USING_NS_CC;

Base::Base(){
	m_sprite = NULL;
}

void Base::setSprite(Sprite* sprite){
	m_sprite = sprite; 
	//要添加到子节点中 ，才能被显示出来
	this->addChild(m_sprite);
}

Sprite* Base::getSprite(){
	return m_sprite;
}

Size Base::getConSize(){
	return m_sprite->getContentSize();
}
