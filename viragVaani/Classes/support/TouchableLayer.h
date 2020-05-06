//
// Created by assertinfotech on 16/3/18.
//

#ifndef PROJ_ANDROID_STUDIO_TOUCHABLELAYER_H
#define PROJ_ANDROID_STUDIO_TOUCHABLELAYER_H




#include "cocos2d.h"

USING_NS_CC;

class TouchableLayer : public LayerColor {
public:
    TouchableLayer();

    virtual ~TouchableLayer();

    static TouchableLayer *createLayer(Color4B color = Color4B(0, 0, 0, 150));

    bool init(Color4B color);

    //Methods to handle touch events
    bool onTouchBegan(Touch *touch, Event *event);

    void onTouchMoved(Touch *touch, Event *event);

    void onTouchEnded(Touch *touch, Event *event);
};

#endif /* TOUCHABLELAYER_H_ */
//#endif //PROJ_ANDROID_STUDIO_TOUCHABLELAYER_H
