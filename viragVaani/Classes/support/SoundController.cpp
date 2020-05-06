/*
 * SoundController.cpp
 *
 *
 *
 */

#include "SoundController.h"
#include "../cocos2d/cocos/audio/include/AudioEngine.h"

int soundId[26];
bool    SoundController::isEffectOn;
bool    SoundController::isBackgroundOn;
bool    SoundController::bSound;
bool    SoundController::eSound;

int SoundController::background_id = -1;

//SimpleAudioEngine *SoundController::audioEngine = SimpleAudioEngine::getInstance();

SoundController::SoundController() {

    //audioEngine	=	audioEngine;
}

SoundController::~SoundController() {
    // TODO Auto-generated destructor stub
}

void SoundController::setAutoSelectSound() {
	log("");
    log("soundddddddddddddddddddddd playyyy");
    UserDefault *defaultSound = UserDefault::getInstance();
    bSound = defaultSound->getBoolForKey(EFFECT_SOUND_KEY, true);
    eSound = defaultSound->getBoolForKey(BACKGROUND_SOUND_KEY, true);

    if (bSound) {
        isEffectOn = true;
    } else {
        isEffectOn = false;
    }
    if (eSound) {
        isBackgroundOn = true;
    } else {
        isBackgroundOn = false;
    }
}


//method to play effect sound
void SoundController::playEffectSound(int sound) {
    UserDefault *defaultSound = UserDefault::getInstance();
    defaultSound->setBoolForKey(EFFECT_SOUND_KEY, true);
    //    audioEngine = SimpleAudioEngine::getInstance();
    log("sound effect play 00----++");
    if (true) {

        log("%s", String::createWithFormat("sound effect play----%d", sound)->getCString());
        switch (sound) {
            case SOUND_LOSS_FIRST_CLICK: {
                soundId[sound] = AudioEngine::play2d("audio/Loose_1.wav", false, 1, nullptr);
                break;
            } case SOUND_LOSS_CLICK: {
                soundId[sound] = AudioEngine::play2d("audio/Loose_2.wav", false,1, nullptr);
                break;
            } case SOUND_WIN_CORRECT: {
                soundId[sound] = AudioEngine::play2d("audio/Win.wav", false, 1, nullptr);
                break;
            }case SOUND_CARD_WRONG: {
                soundId[sound] = AudioEngine::play2d("sounds/wrong.wav", false, 1, nullptr);
                break;
            }
     
        }
    }
}

void SoundController::playMatchPairSound(int imgId,int themeId) {
    UserDefault *defaultSound = UserDefault::getInstance();
    defaultSound->setBoolForKey(EFFECT_SOUND_KEY, true);

    String *strSound = String::createWithFormat("theme%d/sounds/%d.mp3",themeId,imgId);

    if (true) {

        soundId[imgId] = AudioEngine::play2d(strSound->getCString(), false, 1, nullptr);

         }
    }

void SoundController::playCustomSound(std::string songName) {

    UserDefault *defaultSound = UserDefault::getInstance();
    defaultSound->setBoolForKey(EFFECT_SOUND_KEY, true);

    if (true) {

        AudioEngine::play2d(songName.c_str(), false, 1, nullptr);
    }


}


//method to play background music
void SoundController::playBackGroundMusic(int sound) {



    SoundController::isBackgroundOn = UserDefault::getInstance()->getBoolForKey(
            BACKGROUND_SOUND_KEY, true);
    AudioEngine::stopAll();
    if (SoundController::isBackgroundOn) {
    if (background_id != -1) {
        AudioEngine::stop(background_id);
    }
    background_id = AudioEngine::play2d("sound/background2.mp3", true, 0.1f, nullptr);
}
}

//method to stop background music
void SoundController::stopBackGroundMusic() {
AudioEngine::stop(background_id);
}

//method to stop Effect sound
void SoundController::stopEffectSound(int sound) {
//    UserDefault *defaultSound = UserDefault::getInstance();
//    defaultSound->setBoolForKey(EFFECT_SOUND_KEY, false);
//    audioEngine = SimpleAudioEngine::getInstance();
//    switch (sound) {
//        case SOUND_BTN_CLICK: {
//            audioEngine->stopEffect(soundId[sound]);
//            break;
//        }
//
//    }
}


//method to stop all Effect sound
void SoundController::stopAllEffectSound() {
    AudioEngine::stopAll();
}


// void SoundController::setAutoSelectSound(){
//
// UserDefault *defaultSound=UserDefault::getInstance();
//  bSound=defaultSound->getBoolForKey(EFFECT_SOUND_KEY,true);
//eSound=defaultSound->getBoolForKey(BACKGROUND_SOUND_KEY,true);
//
// if(bSound){
//     isEffectOn          =       true;
// }else{
//     isEffectOn          =       false;
// }
// if(eSound){
//     isBackgroundOn      =       true;
// }else{
//     isBackgroundOn      =       false;
// }
//}



void SoundController::resumeAllEffectSound() {
//    audioEngine = SimpleAudioEngine::getInstance();
//    audioEngine->resumeAllEffects();
}


void SoundController::pauseAllEffectSound() {
//    audioEngine = SimpleAudioEngine::getInstance();
//    audioEngine->pauseAllEffects();
}


void SoundController::pauseBackgroundMusic() {
    AudioEngine::stop(background_id);
}

void SoundController::resumeBackgroundMusic() {
//    audioEngine = SimpleAudioEngine::getInstance();
//    audioEngine->resumeBackgroundMusic();

}


void SoundController::setBackgroundMusicVolumn(float soundVolumn) {
//    audioEngine = SimpleAudioEngine::getInstance();
//    audioEngine->setBackgroundMusicVolume(soundVolumn);
}

void SoundController::playSoundEffectByName(std::string fileName) {
    SoundController::isEffectOn =  UserDefault::getInstance()->getBoolForKey(EFFECT_SOUND_KEY, true);

    if (SoundController::isEffectOn) {
        log("sound on");
        AudioEngine::play2d(fileName.c_str(), false, 1.0f, nullptr);
    }else{
        log("sound off");
    }
}
