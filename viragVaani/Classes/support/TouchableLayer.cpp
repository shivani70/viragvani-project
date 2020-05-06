//

//

/*
 * TouchableLayer.cpp
 *
 *
 */

#include "TouchableLayer.h"

TouchableLayer::TouchableLayer() {
	log("");
    // TODO Auto-generated constructor stub
    // TODO Auto-generated constructor stub
    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = CC_CALLBACK_2(TouchableLayer::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(TouchableLayer::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(TouchableLayer::onTouchEnded, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

TouchableLayer::~TouchableLayer() {
    // TODO Auto-generated destructor stub
}

TouchableLayer *TouchableLayer::createLayer(Color4B color) {
    TouchableLayer *pRet = new TouchableLayer();
    if (pRet && pRet->init(color)) {
        pRet->autorelease();
        return pRet;
    } else {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool TouchableLayer::init(Color4B color) {

    if (!LayerColor::initWithColor(color)) {
        return false;
    }

    return true;
}

bool TouchableLayer::onTouchBegan(Touch *touch, Event *event) {
    CCLOG("inside touch begin");

    return true;
}

void TouchableLayer::onTouchMoved(Touch *touch, Event *event) {

    CCLOG("inside touch move");

}

void TouchableLayer::onTouchEnded(Touch *touch, Event *event) {

    CCLOG("inside touch end");

}
