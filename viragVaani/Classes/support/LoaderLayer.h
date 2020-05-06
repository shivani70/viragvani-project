#ifndef __POKER__LoaderLayer__
#define __POKER__LoaderLayer__

#include "cocos2d.h"
#include "Common.h"
using namespace std;
USING_NS_CC;
class LoaderLayer:public LayerColor{

    Label *loaderTextLabel;
    Sprite  *loaderSprite;
public:
    ~LoaderLayer();
    LoaderLayer();

    static LoaderLayer* create(cocos2d::Size size,bool isAddEventListner = true,string strMessage = "");

    virtual bool init(cocos2d::Size size,bool isAddEventListner = true,string strMessage = "");

    void hideLoaderText();
    void setLoaderText(string loaderTextString);
    void setLoaderImageScale(float scaleVal);
    void pauseTouchEvent();
    bool onTouchBegan(Touch *pTouch, Event *pEvent);
    void onTouchEnded(Touch *pTouch, Event *pEvent);

};

#endif /* defined(__POKER__LoaderLayer__) */
