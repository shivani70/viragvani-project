//
//  CustomHttpRequest.cpp
//
//  Created by Branislav Siarsky on 28/03/2016.
//  Copyright © 2016 Smartdone GmbH. All rights reserved.
//

#include "CustomHttpRequest.h"


CustomHttpRequest::~CustomHttpRequest(){

}
CustomHttpRequest::CustomHttpRequest(){
    loaderLayer     = nullptr;
}

//
void CustomHttpRequest::sendRequestToGetData(const std::string& url,
                                             const std::map<std::string, std::string> postDataMap,
                                             const ccHttpRequestCallback& callback,
                                             bool isShowLoader
){

    _cusCallback    =   callback;

    std::vector<std::string> headers;
    headers.push_back("Content-Type: application/x-www-form-urlencoded");

    HttpRequest* request = new (std::nothrow) HttpRequest();
    request->setUrl(url);
    request->setRequestType(HttpRequest::Type::POST);
    request->setResponseCallback(CC_CALLBACK_2(CustomHttpRequest::onRequestCompleted, this));
    request->setHeaders(headers);

    loaderLayer     = nullptr;

    string postDataString = Common::getPostData(postDataMap);
    if(Common::checkStringMatch(postDataString,"")){
        //Do nothing
    }else {
        log("DEBUGG::API::POST ::DATA::%s",postDataString.c_str());
        request->setRequestData(postDataString.c_str(), strlen(postDataString.c_str()));
    }

    //Getting running scene
    if(loaderLayer == nullptr && isShowLoader == true){
        log("DEBUGG::POST REQUEST COMPLETE LOADING");
        loaderLayer =   LoaderLayer::create(Size(Director::getInstance()->getVisibleSize()));
        loaderLayer->setPosition(Director::getInstance()->getVisibleOrigin());
        if(!Common::showLayerOnScene(loaderLayer)){
            log("DEBUGG::LOADER NULL SCENE NOT READY");
            loaderLayer = nullptr;
        }
    }
    HttpClient *httpClient = HttpClient::getInstance();

    httpClient->send(request);
    request->release();

}

void CustomHttpRequest::onRequestCompleted(HttpClient *sender, HttpResponse *response){
    log("DEBUGG::POST REQUEST COMPLETE");
    try {
        log("DEBUGG::POST REQUEST COMPLETE noot try");
        if(loaderLayer != nullptr){
            log("DEBUGG::POST REQUEST COMPLETE noot 1");
            loaderLayer->removeFromParent();
            loaderLayer = nullptr;
            log("DEBUGG::POST REQUEST COMPLETE noot2 ");
        }
    }catch (exception e){
        log("DEBUGG::POST REQUEST COMPLETE noot catch");
        log("DEBUGG::exception call");
    }


    if (!response) {
        //log("DEBUGG:1:onHttpRequestCompleted - No Response");
        return;
    }

    //log("DEBUGG::POST 5");
    log("DEBUGG::POST REQUEST COMPLETE noot 3");
    log("DEBUGG::POST REQUEST COMPLETE noot - Response code: %lu", response->getResponseCode());
    if(response->getResponseCode() != 200 && response->getResponseCode() != 201){
        //If running scene is home then update the bookmark friends list

            if(this->_cusCallback != nullptr){
                this->_cusCallback(sender,response);
            }

    }

    if (!response->isSucceed())
    {
        //log("DEBUGG:1:onHttpRequestCompleted - Error buffer: %s", response->getErrorBuffer());
        return;
    }


    //Here we need to check the response json is valid or not

    char *responseData      =   Common::getResponseDataIntoChar(response);
    log("DEBUGG::onHttpRequestCompleted - Response code: %s---data %s", response->getResponseDataString(),responseData);

    if(Json_create(responseData)){ //0 if json is not correct
        ////log("DEBUGG::RESPONSE JSON SUCCESS::%s",responseData);
        if(this->_cusCallback != nullptr){
            this->_cusCallback(sender,response);
        }
    }else {
        log("DEBUGG::RESPONSE JSON ERROR::%s",responseData);
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        Director::getInstance()->end();
#endif
    }
}
