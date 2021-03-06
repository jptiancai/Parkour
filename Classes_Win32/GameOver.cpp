#include "GameOver.h"  
#include "PlayScene.h"  
  
USING_NS_CC;  
  
Scene* GameOver::scene(){  
    Scene* scene = Scene::create();  
    Layer* layer = GameOver::create();  
    scene->addChild(layer);  
    return scene;  
}  
  
bool GameOver::init(){  
    if(!Layer::init()){  
        return false;  
    }  
  
    //create background  
    createBG();  
  
    return true;  
}  
  
void GameOver::createBG(){  
    auto winSize = Director::getInstance()->getWinSize();  
    auto centerPoint = ccp(winSize.width / 2, winSize.height / 2);  
  
    //BG  
    Sprite* spriteBg = Sprite::create("MainBG.png");  
    spriteBg->setPosition(centerPoint);  
    this->addChild(spriteBg);  
  
    //create button  
    createButton(centerPoint);  
}  
  
void GameOver::createButton(cocos2d::Point centerPoint){  
    //Start mutton  
    MenuItemImage* menuItem = MenuItemImage::create(  
        "restart_n.png",  
        "restart_s.png",  
        CC_CALLBACK_0(GameOver::reStart,this));  
  
    Menu* menu = Menu::create(menuItem,NULL);  
  
    menu->setPosition(centerPoint);  
  
    this->addChild(menu);  
}  
  
void GameOver::reStart(){  
    CCLOG("game is restart !");  
    Scene* playScene = TransitionFade::create(1,PlayScene::createScene());  
    Director::getInstance()->replaceScene(playScene);  
}  