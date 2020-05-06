/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "reader/CreatorReader.h"
#include "ui/UIWebView.h"
#include "FeedBackLayer.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
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
//
//
//    creator::CreatorReader* readerContent = creator::CreatorReader::createWithFilename("creator/Scene/ContentTrial.ccreator");
//
//
//    readerContent->setup();
//
//    // get the scene graph
//    Scene* sceneContent = readerContent->getSceneGraph();
//
//    Node *canvasContent = sceneContent->getChildByName("Canvas");
//    canvasContent->removeFromParentAndCleanup(false);
//    this->addChild(canvasContent);
//
//
//
//
//    creator::CreatorReader* readerAppBar = creator::CreatorReader::createWithFilename("creator/Scene/appBarTrial.ccreator");
//    // will create the needed spritesheets + design resolution
//    readerAppBar->setup();
//    // get the scene graph
//    Scene* scene = readerAppBar->getSceneGraph();
//    Node *canvas = scene->getChildByName("Canvas");
//    canvas->removeFromParentAndCleanup(false);
//    this->addChild(canvas);


//    ui::RichText *richText = ui::RichText::createWithXML("<b>Privacy policy</b>…personal data.<br>");
//    richText->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
////
////        // add the sprite as a child to this layer
//        this->addChild(richText, 0);

//cocos2d::experimental::ui::WebView *createWeb = cocos2d::experimental::ui::WebView::create();
//    createWeb->setContentSize(Size(50,50));
//std::string str1 = "<html><head><title>Page Title</title></head><body>";
//    createWeb->loadHTMLString(str1+"<h1>This is a Heading</h1><p>This is a paragraph.</p></body></html>");
////createWeb->setContentSize(visibleSize);
//    createWeb->setPosition(Vec2(visibleSize.width/2 + origin.x,visibleSize.height/2+origin.y));
////    createWeb->setScalesPageToFit(true);
//
//    this->addChild(createWeb);

//
//
//    ui::ScrollView *scroll = (ui::ScrollView*)canvas->getChildByName("scrollview");
//    scroll->setInnerContainerSize(Size(scroll->getContentSize().width,scroll->getContentSize().height*3));


Layer *layer = FeedBackLayer::createScene();
this->addChild(layer);
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
