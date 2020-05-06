//
// Created by assertinfotech on 10/1/18.
//

#include "Common.h"
#include "cocos2d.h"
#include "audio/include/AudioEngine.h"
#include "audio/android/AudioEngine-inl.h"

    #if (CC_TARGET_PLATFORM ==CC_PLATFORM_ANDROID)
const char *AppActivityClassName = "org/cocos2dx/cpp/AppActivity";

void Common::shareAppCall(){
    log("calling google plus from common");

    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t, AppActivityClassName, "shareAppCall",
                                                "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }

}


std::string Common::getDeviceID(){
    cocos2d::JniMethodInfo t;
    std::string deviceID = "";
    if (cocos2d::JniHelper::getStaticMethodInfo(t, AppActivityClassName, "getDeviceID",
                                                "()Ljava/lang/String;")) {
        jstring  data = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);
        const char*  d =      t.env->GetStringUTFChars(data,NULL);
        t.env->DeleteLocalRef(t.classID);

        deviceID = d;

    }
    return  deviceID;
}
#endif

bool Common::checkStringMatch(string str1,string str2){
    if(strcmp(Common::convertToLowerCase(str1).c_str(),
              Common::convertToLowerCase(str2).c_str()) == 0){
        return true; //String match
    }else {
        return false;//String not match
    }
}

string Common::convertToLowerCase(string str){
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}


string Common::getPostData(std::map<std::string, std::string> postDataMap){
    string postDataString = "";

    for (std::map<string,string>::iterator it=postDataMap.begin(); it!=postDataMap.end(); ++it) {
        if(!Common::checkStringMatch(postDataString,"")){
            postDataString.append("&");
        }
        postDataString.append(StringUtils::format("%s",it->first.c_str()));
        postDataString.append("=");
        postDataString.append(StringUtils::format("%s",it->second.c_str()));
    }
    return postDataString;
}



bool Common::showLayerOnScene(cocos2d::Node *ref){
    Scene *runningScene = Director::getInstance()->getRunningScene();
    if(runningScene == nullptr){
        log("DEBUGG::RUNNING SCENE :: not here");

        return false;
    }else {
        log("DEBUGG::RUNNING SCENE :: %s",runningScene->getName().c_str());

        runningScene->addChild(ref,40000);

        return true;
    }
}
bool Common::checkResponseDataValid(char *responseData){
    if(Common::checkStringMatch("",StringUtils::format("%s",responseData))){
        return false;
    }
//    Json *json                  =   Json_create(responseData);
//    int   responseStatus        =   Json_getInt(json,API_RKEY_STATUS,0);
//    int   responseStatusCode    =   Json_getInt(json,API_RKEY_STATUS_CODE,0);
//    string responseStatusMsg    =   Json_getString(json,API_RKEY_MESSAGE,"");
//    string responseStatusMsgT   =   Json_getString(json,API_RKEY_MESSAGE_TITLE,"");
//    if(responseStatus == 1){ //SUCCESS
//
//        return true;
//    }else { //FAILED response
//
//        return false;
//    }
    return true;
}

string Common::convertJsonObjectToString(Json *jsonObj){
    string jsonObjString    =     "";
////    log("DEBUGG::JSON CONVERT TYPE::%d",jsonObj->type);
//
//    if(jsonObj->type == JSON_TYPE_ARRAY){ //array
//        string arrayObjStr = ApiFunctions::convertJsonObjectArrayToString(jsonObj);
//        jsonObjString.append(arrayObjStr.c_str());
//    }else if(jsonObj->type == JSON_TYPE_OBJ){//Object
//        Json *c                 =   jsonObj->child;
////        log("DEBUGG::JSON TYPE :object:%d",c->type);
//        jsonObjString.append("{");
//        int cnt1     =   0;
//        while(c){
//            cnt1++;
//            if(c->type == JSON_TYPE_STRING) {
//                jsonObjString.append(StringUtils::format("\"%s\":\"%s\",",c->name,c->valueString));
//            }else if(c->type == JSON_TYPE_ARRAY){ //Json Array Type
//                string arrayObjStr = ApiFunctions::convertJsonObjectArrayToString(c);
//                jsonObjString.append(StringUtils::format("\"%s\":",c->name));
//                jsonObjString.append(arrayObjStr.c_str());
//                jsonObjString.append(",");
//            }
//            c = c->next;
//        }
//        if(cnt1 != 0) {
//            jsonObjString = jsonObjString.substr(0, jsonObjString.size() - 1);
//        }
//        jsonObjString.append("}");
//    }

    //  log("DEBUGG::JSON AFTER CONVERT JSON STRING ::%s",jsonObjString.c_str());
    return jsonObjString;
}


string Common::convertJsonObjectArrayToString(Json *json) {
//    log("DEBUGG::JSON CONVERT JSON OBJECT ARRAY TO STRING::");
    if (!json) {
//        log("DEBUGG::JSON CONVERT JSON OBJECT ARRAY TO STRING::NULL");
        return "[]";
    }
//    log("DEBUGG::JSON CONVERT JSON OBJECT ARRAY TO STRING::%d",json->type);
    string jsonObjString = "";
    jsonObjString.append("[");
    Json *usersubArrayObj = json->child;
    int cnt = 0;
    while (usersubArrayObj) {
        cnt++;
        int counter = 0;
        Json *usersubArrayChildObj = usersubArrayObj->child;
//        while(usersubArrayChildObj){
//            if(counter == 0){
//                jsonObjString.append("{");
//            }
//            if(usersubArrayChildObj->type == JSON_TYPE_INT){
//                jsonObjString.append(StringUtils::format("\"%s\":%d,",usersubArrayChildObj->name,
//                                                         usersubArrayChildObj->valueInt));
//            }else{
//                jsonObjString.append(StringUtils::format("\"%s\":\"%s\",",usersubArrayChildObj->name,
//                                                         usersubArrayChildObj->valueString));
//            }
//
//            counter++;
//            usersubArrayChildObj     =   usersubArrayChildObj->next;
//        }
//        if(counter != 0){
//            jsonObjString = jsonObjString.substr(0, jsonObjString.size()-1);
//            jsonObjString.append("},");
//        }
//        usersubArrayObj     =   usersubArrayObj->next;
//    }
//    if(cnt != 0) {
//        jsonObjString = jsonObjString.substr(0, jsonObjString.size() - 1);
//    }
//    jsonObjString.append("]");
        return jsonObjString;
    }
}


char* Common::getResponseDataIntoChar(HttpResponse *response){
    std::vector<char> *buffer   = response->getResponseData();
    char * concatenated         = (char *) malloc(buffer->size() + 1);
    std::string s2(buffer->begin(), buffer->end());
    strcpy(concatenated, s2.c_str());
    return concatenated;
}

