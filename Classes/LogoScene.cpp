//
//  LogoScene.cpp
//  KawazLogo
//
//  Created by CollapsedPlug on 1/7/15.
//
//

/* What's this
 * cocos2d-x v3.3とADX2 LEを使用して制作したKawazの動画ロゴシーン。
 * ADX2 LEを使用しているプロジェクトならいろんな面で組み込みが簡単です。
 * なお、開発にあたっては
 * giginet氏のCCADX2Manager ( https://github.com/giginet/CCADX2Manager )を利用させていただきました。
 * 現在、16:9/9:16の画面に対応しています。ただし、このシーン中に縦横が切り替わることは想定していません。
 */

/* TODO List
 * 1. ADX2 LE のライセンス表記を忘れずに行う(重要)
 * 2. もしない場合は、https://github.com/giginet/CCADX2Manager をクローンしてプロジェクトに組み込む (注1)
 * 3. logoフォルダと音声ファイルをResourceの下に, logo.hファイルをClassesの下に配置して参照させる (注2)
 * 4. 音声ファイルの場所に応じて、init()内の auto cuesheet = ADX2::CueSheet::create の引数を書き換える
 * 5. 冒頭の #include "KawazLogo_acf.h" をプロジェクトで使用しているものに置き換える
 * 6. update(float dt)内で、次のシーンへ進める処理を行う
 * 7. 必要なら、AppDelegateで、このシーンを最初に読み込むようにする
 * 8. [推奨]スタートアップスクリーンを真っ白な画面にしておく
 * (注1) 使ってないなら使いましょう。
 * (注2) logoフォルダはフォルダ階層も参照させてください。logo.hファイルは必要ありません
 */

/* What needs to be done
 * 複数解像度への対応。もっと一般的な相対的位置指定が必要
 * ラムダが入れ子になりまくってる部分の修正
 * ファイルの時点でパーツとなっているKawazロゴを１つにして、プログラム上でパーツにさせる
 */
#include "LogoScene.h"
#include "KawazLogo_acf.h" //TODO:: ここをプロジェクトのacfに置き換えること(ゲーム変数やAISACは使ってないので多分大丈夫)
#include "logo.h"

USING_NS_CC;

LogoScene::LogoScene()
: _frog(nullptr)
, _K(nullptr)
, _a1(nullptr)
, _w(nullptr)
, _a2(nullptr)
, _z(nullptr)
, _clearout(nullptr)
, _logo(nullptr)
, _cueSheet(nullptr)
, _finalScale(0.0f)
, _hasEnded(false)
, _isNonSense(false)
{
    
}

LogoScene::~LogoScene(){
    
    CC_SAFE_RELEASE_NULL(_frog);
    CC_SAFE_RELEASE_NULL(_K);
    CC_SAFE_RELEASE_NULL(_a1);
    CC_SAFE_RELEASE_NULL(_w);
    CC_SAFE_RELEASE_NULL(_a2);
    CC_SAFE_RELEASE_NULL(_z);
    CC_SAFE_RELEASE_NULL(_clearout);
    CC_SAFE_RELEASE_NULL(_logo);
    CC_SAFE_RELEASE_NULL(_cueSheet);
    
}

Scene* LogoScene::createScene(){
    auto scene = Scene::create();
    auto layer = LogoScene::create();
    scene->addChild(layer);
    return scene;
}

bool LogoScene::init(){
    if(!Layer::init()){
        return false;
    }
    
    // キューシートを開く
    // TODO:: プロジェクトのフォルダ構成に応じてacf, acbのパスを指定
    auto cuesheet = ADX2::CueSheet::create("adx/KawazLogo.acf", "adx/logo.acb");
    this->setCueSheet(cuesheet);
    
    auto director = Director::getInstance();
    
    auto isLandScape = director->getWinSize().width >= director->getWinSize().height;
    
    
    this->setFinalScale((isLandScape ? 0.70f : 0.55f));
    
    // 各パーツを読み込み、準備
    // FIXME:: ロゴがファイルの時点でパーツとなっているのはライセンス規約的にまずいかも。コードの中で処理させる
    auto frog = Sprite::create("logo/Parts/Frog.png");
    frog->setScale(50.0f);
    frog->setPosition(director->getWinSize() / 2);
    
    auto K = Sprite::create("logo/Parts/K.png");
    K->setScale(_finalScale);
    K->setPosition(Vec2(director->getWinSize().width * (isLandScape ? 0.25f : 0.1f) +
                        (frog->getContentSize().width / 2 + K->getContentSize().width / 2) * _finalScale +
                        (isLandScape ? 0.0f : director->getWinSize().width * 0.05),
                        director->getWinSize().height * 1.5));
    auto a1 = Sprite::create("logo/Parts/a.png");
    a1->setScale(_finalScale);
    a1->setPosition(Vec2(K->getPositionX() +
                         (K->getContentSize().width / 2 + a1->getContentSize().width / 2) * _finalScale,
                         director->getWinSize().height * 1.5));
    auto w = Sprite::create("logo/Parts/w.png");
    w->setScale(_finalScale);
    w->setPosition(Vec2(a1->getPositionX() +
                        (a1->getContentSize().width / 2 + w->getContentSize().width / 2) * _finalScale,
                        director->getWinSize().height * 1.5));
    auto a2 = Sprite::create("logo/Parts/a.png");
    a2->setScale(_finalScale);
    a2->setPosition(Vec2(w->getPositionX() +
                         (w->getContentSize().width / 2 + a2->getContentSize().width / 2) * _finalScale,
                         director->getWinSize().height * 1.5));
    auto z = Sprite::create("logo/Parts/z.png");
    z->setScale(_finalScale);
    z->setPosition(Vec2(a2->getPositionX() +
                        (a2->getContentSize().width / 2 + z->getContentSize().width / 2) * _finalScale,
                        director->getWinSize().height * 1.5));
    
    auto clearout = Sprite::create("logo/Clearout.png");
    clearout->setScale(0.0f);
    clearout->setPosition(director->getWinSize() / 2); //クソ横着なことをしたが反省はしていない
    
    //縦か横は画面の縦横の長さどちらが長いのかで決定
    auto logo = (director->getWinSize().width > director->getWinSize().height ? Sprite::create("logo/1334-750.png") : Sprite::create("logo/750-1334.png"));
    logo->setScale(30.0f);
    logo->setOpacity(0); //Opacityは0から255
    logo->setPosition(director->getWinSize() / 2);
    
    this->setFrog(frog);
    this->setK(K);
    this->setA1(a1);
    this->setW(w);
    this->setA2(a2);
    this->setZ(z);
    this->setClearOut(clearout);
    this->setLogo(logo);
    this->addChild(frog);
    this->addChild(K);
    this->addChild(a1);
    this->addChild(w);
    this->addChild(a2);
    this->addChild(z);
    this->addChild(clearout);
    this->addChild(logo);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this](Touch * touch, Event * event){
        
        if (_isNonSense){
            return false;
        }
        
        this->setIsNonSence(true);
        
        //タッチされたら全てのアクションがストップ
        for (Node * node: this->getChildren()){
            node->stopAllActions();
        }
        //Kawazロゴになる
        this->getLogo()->setScale(1.0f);
        this->getLogo()->setOpacity(255);
        this->getCueSheet()->stop(CRI_LOGO_FROG);
        this->getCueSheet()->stop(CRI_LOGO_LETTERANDMAIN);
        this->getCueSheet()->playCueByID(CRI_LOGO_SKIPPED);
        
        auto passon = Sequence::create(DelayTime::create(2.0f), CallFunc::create([this](){
            this->setHasEnded(true);
        }), NULL);
        
        this->getLogo()->runAction(passon);
        
        return  true;
    };
    director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void LogoScene::onEnterTransitionDidFinish(){
    
    auto director = Director::getInstance();
    
    auto isLandScape = (director->getWinSize().width >= director->getWinSize().height);
    auto firstDelay = DelayTime::create(0.5f);
    
    //カエルの部分のアニメーション　ズームアウト後、画面の左端から画面の幅の20%(縦画面なら12.5%)のところに陣取る
    auto FRanimationSound = CallFunc::create([this](){
        this->getCueSheet()->playCueByID(CRI_LOGO_FROG);
    });
    auto FRanimation = ScaleTo::create(1.0f, _finalScale);
    auto FRanimationEL = EaseOut::create(FRanimation, 3.0f);
    auto FRanimationEP = EaseOut::create(FRanimation, 3.0f);
    auto FRanimation2_1 = MoveBy::create(1.0f, Vec2::ZERO); //最初は動かない(ことを明示)(Delaytimeでもよい)
    auto FRanimation2_2 = MoveBy::create(1.2f, Vec2(-director->getWinSize().width * (isLandScape ? 0.25f : 0.375f), 0));
    auto FRanimation2_2EIO = EaseInOut::create(FRanimation2_2, 7.0f);
    auto FRanimation2 = Sequence::create(FRanimation2_1, FRanimation2_2EIO, NULL);
    if (isLandScape){
        auto FrSeq = Spawn::create(FRanimationSound, FRanimationEL, FRanimation2, NULL);
        this->getFrog()->runAction(Sequence::create(firstDelay, FrSeq, NULL));
    }
    else{
        auto FrSeq = Spawn::create(FRanimationSound, FRanimationEP, FRanimation2, NULL);
        this->getFrog()->runAction(Sequence::create(firstDelay, FrSeq, NULL));
    }

    //まずアニメーションを全て作成する
    //音の再生タイミングは落ちた時。
    auto FallSound = CallFunc::create([this](){
        this->getCueSheet()->playCueByID(CRI_LOGO_LETTERANDMAIN);
    });

    // 各スプライトに対してアニメーションを実行
    _K->runAction(Spawn::create(Sequence::create(DelayTime::create(2.7f),FallSound,NULL),this->createSequence(2.5f),NULL));
    _a1->runAction(this->createSequence(2.7f));
    _w->runAction(this->createSequence(2.9f));
    _a2->runAction(this->createSequence(3.1f));
    _z->runAction(this->createSequence(3.3f));
    
    auto coExpand = EaseIn::create(ScaleTo::create(1.2f, 400.0f), 3.0f);
    auto LogoSpawn = CallFunc::create([this,director](){
        auto ShrinkInto = ScaleTo::create(0.4f, 1.0f / director->getContentScaleFactor());
        auto appear = FadeTo::create(0.4f, 255);
        this->getLogo()->runAction(Sequence::create(DelayTime::create(0.2f),Spawn::create(ShrinkInto,appear, NULL), NULL));
        this->setIsNonSence(true);
    });
    this->getClearOut()->runAction(Sequence::create(DelayTime::create(3.8f),Spawn::create(coExpand, LogoSpawn, NULL), DelayTime::create(2.0f), CallFunc::create([this](){
        this->setHasEnded(true);
    }), NULL));
    
    this->scheduleUpdate();
    
}

Action* LogoScene::createSequence(float delay){
    auto FallAction = MoveBy::create(0.2f, Vec2(0, -Director::getInstance()->getWinSize().height));
    auto FallActionEase = EaseIn::create(FallAction, 2.0f);
    auto FallStretch = ScaleBy::create(0.1f,1.0f, 1.2f);
    auto Fall = Spawn::create(FallActionEase, FallStretch, NULL);
    auto LandTremble = EaseElasticOut::create((ScaleTo::create(0.5f,_finalScale)));
    
    return Sequence::create(DelayTime::create(delay), Fall, LandTremble, NULL);
}

void LogoScene::update(float dt){
    
    
    if (_hasEnded){
        
        /* TODO:: ここで次のシーンへ遷移します。行き先のシーンのヘッダファイルをIncludeするのをわすれずに
         * Example : 以下の例はこのシーンをリピートします。
         * [Beginning of code]
         * this->unscheduleUpdate();
         * auto scene = LogoScene::createScene();
         * auto sceneTr = TransitionFade::create(1.0f,scene);
         * Director::getInstance()->replaceScene(sceneTr);
         * [End of code]
         * 注意 : this->unscheduleUpdate();を実行しないとsceneが生成され続けて予期しない結果を生むことがあります。
         */
        this->unscheduleUpdate();
        auto scene = LogoScene::createScene();
        auto sceneTr = TransitionFade::create(1.0f,scene);
        Director::getInstance()->replaceScene(sceneTr);
        
    }
    
    
}