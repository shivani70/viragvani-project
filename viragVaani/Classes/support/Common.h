//
// Created by assertinfotech on 10/1/18.
//

#ifndef PROJ_ANDROID_STUDIO_COMMON_H
#define PROJ_ANDROID_STUDIO_COMMON_H

#include <spine/Json.h>
#include "network/HttpClient.h"
using namespace cocos2d::network;
#include "cocos2d.h"
USING_NS_CC;

using namespace std;
class Common {

public:
    static void shareAppCall();
    static bool checkStringMatch(string str1,string str2);
    static bool showLayerOnScene(cocos2d::Node *ref);
    static bool checkResponseDataValid(char *responseData);
    static string convertJsonObjectToString(Json *jsonObj);
    static string convertJsonObjectArrayToString(Json *json);
    static char* getResponseDataIntoChar(HttpResponse *response);
    static string convertToLowerCase(string str);
    static string getPostData(std::map<std::string, std::string> postDataMap);
    static string getDeviceID();
};


#endif //PROJ_ANDROID_STUDIO_COMMON_H
