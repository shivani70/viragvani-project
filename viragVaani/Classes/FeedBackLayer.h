//
// Created by shiva on 5/5/2020.
//

#ifndef PROJ_ANDROID_FEEDBACKLAYER_H
#define PROJ_ANDROID_FEEDBACKLAYER_H

#include "cocos2d.h"
#include "../cocos2d/cocos/2d/CCLayer.h"

class FeedBackLayer: public cocos2d::Layer
{
public:
    static cocos2d::Layer* createScene();

    virtual bool init();
    // a selector callback

    // implement the "static create()" method manually
    CREATE_FUNC(FeedBackLayer);

};


#endif //PROJ_ANDROID_FEEDBACKLAYER_H
