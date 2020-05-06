//
//  CustomHttpRequest.h
//
//  Created by Branislav Siarsky on 28/03/2016.
//  Copyright © 2016 Smartdone GmbH. All rights reserved.
//

#ifndef CustomHttpRequest_h
#define CustomHttpRequest_h

#include "Common.h"
#include "network/HttpClient.h"
using namespace cocos2d::network;
#include "ui/CocosGUI.h"
#include "LoaderLayer.h"

class CustomHttpRequest {

    ccHttpRequestCallback       _cusCallback;
    ccHttpRequestCallback       _cusImageCallback;

    LoaderLayer                 *loaderLayer;

public:
    CustomHttpRequest();
    ~CustomHttpRequest();

    void sendRequestToGetData(const std::string& url,
                              const std::map<std::string, std::string> postDataMap,
                              const ccHttpRequestCallback& callback,
                              const bool isShowLoader = true
    );
    void onRequestCompleted(HttpClient *sender, HttpResponse *response);

};

#endif /* CustomHttpRequest_h */
