//
//  CueSheet.cpp
//  CcAdx2Basic
//
//  Created by giginet on 2014/6/27.
//
//

#include "CueSheet.h"
#include "Manager.h"

namespace ADX2 {
    
    CueSheet::CueSheet() : _acb(nullptr)
    {
    }
    
    CueSheet* CueSheet::create(const char *acf, const char *acb)
    {
        return CueSheet::create(acf, acb, nullptr);
    }
    
    CueSheet* CueSheet::create(const char *acf, const char *acb, const char *awb)
    {
        auto cue = new CueSheet();
        if (cue && cue->initWithFile(acf, acb, awb)) {
            cue->autorelease();
            return cue;
        }
        CC_SAFE_DELETE(cue);
        return nullptr;
    }
    
    bool CueSheet::initWithFile(const char* acf, const char* acb, const char* awb)
    {
        
        auto fp = [](const char* filename)
        {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            return cocos2d::FileUtils::getInstance()->fullPathForFilename(filename);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
            /* assetsへのアクセスパスは、必ずassets以下からの相対パスでファイルを指定する
             * パスの先頭に'/'文字が入ってはダメ */
            return std::string(filename);
#endif
        };
        
        auto acfPath = fp(acf);
        auto acbPath = fp(acb);
        
        criAtomEx_RegisterAcfFile(NULL, acfPath.c_str(), NULL, 0);
        if (awb) {
            auto awbPath = fp(awb);
            _acb = criAtomExAcb_LoadAcbFile(NULL, acbPath.c_str(), NULL, awbPath.c_str(), NULL, 0);
        } else {
            _acb = criAtomExAcb_LoadAcbFile(NULL, acbPath.c_str(), NULL, NULL, NULL, 0);
        }
        
        if (_acb == nullptr) {
            return false;
        }
        
        return true;
    }
    
    CueSheet::~CueSheet()
    {
        criAtomExAcb_Release(_acb);
    }
    
    CriAtomExPlaybackId CueSheet::playCueByID(CriAtomExCueId cueID)
    {
        auto player = Manager::getInstance()->getDefaultPlayer();
        criAtomExPlayer_SetCueId(player, _acb, cueID);
        
        CriAtomExPlaybackId playbackID = criAtomExPlayer_Start(player);
        
        return playbackID;
    }
    
    void CueSheet::stop(CriAtomExPlaybackId playbackID)
    {
        criAtomExPlayback_Stop(playbackID);
    }
        
    const char* CueSheet::getCueName(CriAtomExCueId cueID)
    {
        return criAtomExAcb_GetCueNameById(_acb, cueID);
    }
    
    int64_t CueSheet::getTime(CriAtomExPlaybackId playbackID)
    {
        return criAtomExPlayback_GetTime(playbackID);
    }
    
    CriAtomExPlaybackStatus CueSheet::getStatus(CriAtomExPlaybackId playbackID)
    {
        return criAtomExPlayback_GetStatus(playbackID);
    }
    
    CriFloat32 CueSheet::getAisacById(CriAtomExAisacControlId control_id){
        auto player = Manager::getInstance()->getDefaultPlayer();
        auto result = criAtomExPlayer_GetAisacById (player, control_id);
        CCASSERT(result >= 0.0f, "THAT CONRTOL ID IS NOT VALID! I couldn't find any AISAC attatched to it.");
        return std::move(result);
    }
    
    void CueSheet::setAisacById(CriAtomExAisacControlId control_id, float value){
        auto player = Manager::getInstance()->getDefaultPlayer();
        CCASSERT(value >= 0.0f and value <= 1.0f, "THAT VALUE IS NOT VALID FOR AISAC! It must be between 0 and 1.");
        criAtomExPlayer_SetAisacById(player, control_id, (CriFloat32)value);
    }
    
    void CueSheet::updateAll(){
        auto player = Manager::getInstance()->getDefaultPlayer();
        criAtomExPlayer_UpdateAll(player);
    }
    
}