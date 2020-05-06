//
// Created by shiva on 5/5/2020.
//

#include "FeedBackLayer.h"
#include "reader/CreatorReader.h"
USING_NS_CC;

Layer* FeedBackLayer::createScene()
{
    return FeedBackLayer::create();
}

// on "init" you need to initialize your instance
bool FeedBackLayer::init() {
    //////////////////////////////
    // 1. super init first
    if (!Layer::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
//
//    /////////////////////////////
//    // 2. add a menu item with "X" image, which is clicked to quit the program
//    //    you may modify it.
//
//    // add a "close" icon to exit the progress. it's an autorelease object
//    auto closeItem = MenuItemImage::create(
//                                           "CloseNormal.png",
//                                           "CloseSelected.png",
//                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
//
//    if (closeItem == nullptr ||
//        closeItem->getContentSize().width <= 0 ||
//        closeItem->getContentSize().height <= 0)
//    {
//        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
//    }
//    else
//    {
//        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
//        float y = origin.y + closeItem->getContentSize().height/2;
//        closeItem->setPosition(Vec2(x,y));
//    }
//
//    // create menu, it's an autorelease object
//    auto menu = Menu::create(closeItem, NULL);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);
//
//    /////////////////////////////
//    // 3. add your codes below...
//
//    // add a label shows "Hello World"
//    // create and initialize a label
//
//    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
//    if (label == nullptr)
//    {
//        problemLoading("'fonts/Marker Felt.ttf'");
//    }
//    else
//    {
//        // position the label on the center of the screen
//        label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                                origin.y + visibleSize.height - label->getContentSize().height));
//
//        // add the label as a child to this layer
//        this->addChild(label, 1);
//    }
//
//    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("HelloWorld.png");
//    if (sprite == nullptr)
//    {
//        problemLoading("'HelloWorld.png'");
//    }
//    else
//    {
//        // position the sprite on the center of the screen
//        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//        // add the sprite as a child to this layer
//        this->addChild(sprite, 0);
//    }
//


    creator::CreatorReader *readerContent = creator::CreatorReader::createWithFilename(
            "creator/Scene/feedBackScene.ccreator");
    readerContent->setup();

    // get the scene graph
    Scene *sceneContent = readerContent->getSceneGraph();

    Node *canvasContent = sceneContent->getChildByName("Canvas");
    canvasContent->removeFromParentAndCleanup(false);
    this->addChild(canvasContent);


    creator::CreatorReader* readerAppBar = creator::CreatorReader::createWithFilename("creator/Scene/appBarTrial.ccreator");
    // will create the needed spritesheets + design resolution
    readerAppBar->setup();
    // get the scene graph
    Scene* scene = readerAppBar->getSceneGraph();
    Node *canvas = scene->getChildByName("Canvas");
    canvas->removeFromParentAndCleanup(false);
    this->addChild(canvas);




    return true;
}