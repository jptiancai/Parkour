#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include "PlayScene.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* MainScene::scene(){
	Scene* scene = Scene::create();
	Layer* layer = MainScene::create();
	scene->addChild(layer);
	return scene;
}

bool MainScene::init(){
	if(!Layer::init()){
		return false;
	}

	//preloadMusic
	preLoadMusic();

	//create background
	createBG();

	return true;
}

void MainScene::createBG(){
	auto winSize = Director::getInstance()->getWinSize();
	auto centerPoint = ccp(winSize.width / 2, winSize.height / 2);

	//BG
	Sprite* spriteBg = Sprite::create("MainBG.png");
	spriteBg->setPosition(centerPoint);
	this->addChild(spriteBg);

	//create button
	createButton(centerPoint);
}

void MainScene::createButton(cocos2d::Point centerPoint){
	//Start mutton
	MenuItemImage* menuItem = MenuItemImage::create(
		"start_n.png",
		"start_s.png",
		CC_CALLBACK_0(MainScene::start,this));

	Menu* menu = Menu::create(menuItem,NULL);

	menu->setPosition(centerPoint);

	this->addChild(menu);
}

void MainScene::preLoadMusic(){
	SimpleAudioEngine* audioEngin = SimpleAudioEngine::getInstance();
	audioEngin->preloadBackgroundMusic("background.mp3");
	audioEngin->preloadEffect("jump.mp3");
	audioEngin->preloadEffect("crouch.mp3");
}

void MainScene::start(){
	CCLOG("game is start !");
	Scene* playScene = TransitionFade::create(1,PlayScene::createScene());
	Director::getInstance()->replaceScene(playScene);
}