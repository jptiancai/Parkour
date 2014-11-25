#ifndef __Rock__H__
#define __Rock__H__

#include "Base.h"
#include "cocos2d.h"

class Rock : public Base{
public:
	virtual bool init();
	CREATE_FUNC(Rock);

	void initBody();
};/**/

#endif