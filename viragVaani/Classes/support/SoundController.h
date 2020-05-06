/*
 * SoundController.h
 *
 *  Created on: 18-Feb-2015
 *      Author: Radhika InfoTech
 */
#ifndef SOUNDCONTROLLER_H_
#define SOUNDCONTROLLER_H_

//#include "SimpleAudioEngine.h"
#include "cocos2d.h"

USING_NS_CC;


#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;

//using namespace CocosDenshion;

/*****************************SOUND*********************************/
// ----------- Background Sounds -----------
#define                    SOUND_BACKGROUND_GAMEPLAY        1

// ------------- Effect Sound -------------
#define                    SOUND_LOSS_FIRST_CLICK                    0
#define                    SOUND_LOSS_CLICK                1
#define                    SOUND_WIN_CORRECT                2
#define                    SOUND_CARD_WRONG                3


#define                 EFFECT_SOUND_KEY                "effect_sound_key"
#define                 BACKGROUND_SOUND_KEY            "background_sound_key"






static bool soundCall = true;



class SoundController {
public:

//	 static bool	isSoundOn;		//variable to check for sound
    static bool isEffectOn;     //  Variable to check whether effects are on or not
    static bool isBackgroundOn; //  Variable to check whether background sound is ON or not
    static bool bSound;
    static bool eSound;
    static int background_id;
    SoundController();

    virtual ~SoundController();

//    static SimpleAudioEngine *audioEngine;


    //method to play effect sound
    static void playEffectSound(int fileName);
    static void playMatchPairSound(int imgId,int themeId);
    static void playCustomSound(std::string songName);
    //method to play background music
    static void playBackGroundMusic(int sound);

    //method to stop background music
    static void stopBackGroundMusic();

    /** set Sound according to last save */
    static void setAutoSelectSound();

    /** stop a effect sound*/
    static void stopEffectSound(int sound);

    /** stop all effect sound*/
    static void stopAllEffectSound();

    /** pause all sound effects */
    static void pauseAllEffectSound();

    /** resume all sound effects*/
    static void resumeAllEffectSound();

    /** pause Background music*/
    static void pauseBackgroundMusic();

    /** resume Background Music*/
    static void resumeBackgroundMusic();

    /** set Background Music volumn */
    static void setBackgroundMusicVolumn(float soundVolumn);

    /** set sound effect with file name**/
    static void playSoundEffectByName(std::string fileName);

};

#endif /* SOUNDCONTROLLER_H_ */
