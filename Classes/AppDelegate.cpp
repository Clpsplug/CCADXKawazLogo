#include "AppDelegate.h"
#include "LogoScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {
}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }
    
    // Initialize ADX2
    CriAtomExStandardVoicePoolConfig vp_config;
    criAtomExVoicePool_SetDefaultConfigForStandardVoicePool(&vp_config);
    // Maximum voices
    vp_config.num_voices = 8;
    // Enable Streaming
    vp_config.player_config.streaming_flag = CRI_TRUE;
    // Maximum sampling rate
    vp_config.player_config.max_sampling_rate = 48000 << 1;
    
    CriAtomExPlayerConfig pf_config;
    criAtomExPlayer_SetDefaultConfig(&pf_config);
    // Maximum number of file paths to be held
    pf_config.max_path_strings = 1;
    // Maximum length of a file path
    pf_config.max_path = 256;
    
    // ADX2を有効にする
    ADX2::Manager::initialize(pf_config, vp_config);


    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    // get surface size
    auto frameSize = glview->getFrameSize();
    
    //get designResolutionSize
    auto designResolutionSize = glview->getDesignResolutionSize();
    
    // set ContentScaleFactor
    director->setContentScaleFactor(frameSize.height / designResolutionSize.height);

    // create a scene. it's an autorelease object
    auto scene = LogoScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
