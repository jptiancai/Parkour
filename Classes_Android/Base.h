#ifndef __Base__H__
#define __Base__H__

#include "cocos2d.h"

class Base : public cocos2d::Node{
public:
	Base();

	void setSprite(cocos2d::Sprite* sprite);
	cocos2d::Sprite* getSprite();

	cocos2d::Size getConSize();

private:
	cocos2d::Sprite* m_sprite;
};/**/

#endif