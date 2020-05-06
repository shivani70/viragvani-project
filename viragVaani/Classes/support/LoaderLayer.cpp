#include "LoaderLayer.h"
#include "Common.h"
LoaderLayer::~LoaderLayer(){

}
LoaderLayer::LoaderLayer(){

}

LoaderLayer* LoaderLayer::create(Size size,bool isAddEventListner,string strMessage){
    LoaderLayer	*LoaderLayerLayer			=		new LoaderLayer();
    if(LoaderLayerLayer && LoaderLayerLayer->init(size,isAddEventListner,strMessage)){
        LoaderLayerLayer->autorelease();
        return LoaderLayerLayer;
    }
    CC_SAFE_DELETE(LoaderLayerLayer);
    return NULL;
}

bool LoaderLayer::init(Size size,bool isAddEventListner,string strMessage) {
    this->initWithColor(Color4B(0, 0, 0, 120));
    this->setContentSize(size);
//    this->setName(LAYER_NAME_LOADER);


    if(isAddEventListner){
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan 		= CC_CALLBACK_2(LoaderLayer::onTouchBegan, this);
        listener->onTouchEnded 		= CC_CALLBACK_2(LoaderLayer::onTouchEnded, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    }

    loaderSprite   =   Sprite::create("loader.png");
    loaderSprite->setPosition(Vec2(this->getContentSize().width/2,
                                   this->getContentSize().height/2));
    loaderSprite->setScale(0.4);
    this->addChild(loaderSprite);

    loaderSprite->runAction(RepeatForever::create(Sequence::create(RotateBy::create(2.0,360),NULL)));

    loaderTextLabel       =   Label::createWithTTF("Loading data ...","fonts/Font.ttf",20);
    loaderTextLabel->setPosition(Vec2(this->getContentSize().width/2,
                                 this->getContentSize().height/2 - loaderSprite->getContentSize().height/2));
    this->addChild(loaderTextLabel);

    if(!Common::checkStringMatch(strMessage,"")){

        loaderTextLabel->setString(strMessage);
    }

    return true;
}

void LoaderLayer::hideLoaderText(){
    loaderTextLabel->setVisible(false);
}

void LoaderLayer::setLoaderText(string loaderTextString){
    loaderTextLabel->setString(loaderTextString);
}

void LoaderLayer::setLoaderImageScale(float scaleVal){
    loaderSprite->setScale(scaleVal);
}

void LoaderLayer::pauseTouchEvent(){
    _eventDispatcher->pauseEventListenersForTarget(this,true);
}

//Method to handle the touch events
bool LoaderLayer::onTouchBegan(Touch *pTouch, Event *pEvent){
//    log("DEBUGG::Loader screen touch began");
    return true;
}

//Handle the touch end
void LoaderLayer::onTouchEnded(Touch *pTouch, Event *pEvent){
//    log("DEBUGG::Loader screen touch end");
}
