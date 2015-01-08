//
//  CueSheet.h
//  CcAdx2Basic
//
//  Created by giginet on 2014/6/27.
//
//

#ifndef __CcAdx2Basic__CueSheet__
#define __CcAdx2Basic__CueSheet__

#include <iostream>
#include "cri_adx2le.h"
#include "cocos2d.h"

namespace ADX2 {
    
    class CueSheet :public cocos2d::Ref {
    private:
        /// 波形データバンクのハンドル
        CriAtomExAcbHn _acb;
        
    CC_CONSTRUCTOR_ACCESS:
        
        CueSheet();
        
        /**
         *  ファイルからCueSheetを初期化します
         *  @param acfのファイル名
         *  @param acbのファイル名
         *  @param awbのファイル名
         */
        bool initWithFile(const char* acf, const char* acb, const char* awb);
        
        virtual ~CueSheet();
        
    public:
        
        /**
         *  CueSheet内の指定IDの音声データを鳴らします
         *  @param cueID 再生する音声データのcueID
         *  @return 再生されたサウンドのPlaybackID
         */
        CriAtomExPlaybackId playCueByID(CriAtomExCueId cueID);
        
        static CueSheet* create(const char* acf, const char* acb, const char* awb);
        
        static CueSheet* create(const char* acf, const char* acb);
        
        /**
         *  指定したPlaybackIDのサウンドを停止します
         *  @param playbackID 停止するサウンドのPlaybackID
         */
        void stop(CriAtomExPlaybackId playbackID);
        
        /**
         *  CueSheet内の指定IDの音声データの名称を取り出します
         *  @param cueID 音声データのcueID
         *  @return 音声データ名
         */
        const char* getCueName(CriAtomExCueId cueID);
        
        /**
         *  指定されたサウンドの再生位置を取り出します
         *  指定IDが再生されていないときは-1が返ります
         *  @param playbackID 再生位置を取得するサウンドのplaybackID
         *  @return 再生位置
         *
         */
        int64_t getTime(CriAtomExPlaybackId playbackID);
        
        /**
         * 指定されたサウンドの状態を取り出します
         * @param playbackID 状態を取得するサウンドのplaybackID
         * @return サウンドの状態
         */
        CriAtomExPlaybackStatus getStatus(CriAtomExPlaybackId id);
        
        /**
         * 指定されたIdをもつAISACの値を返します。
         * 指定されたIDが無効(AISACがない等)の場合停止します。
         * @param conrtol_id AISACコントロールID
         * @return 指定されたAISACの値
         */
        CriFloat32 getAisacById(CriAtomExAisacControlId control_id);
        
        /**
         * 指定されたIdをもつAISACの値を設定します。
         * UpdateAllメソッドを呼ばないと反映されません。
         * @param control_id AISACコントロールID
         * @param value 設定する値
         */
        void setAisacById(CriAtomExAisacControlId control_id, float value);
        
        /**
         * プレイヤーの状態を更新します。
         * AISAC値を変更した後などに使用してください。
         * ただし、毎フレーム呼ぶようなことをすると重くなるので注意しましょう
         */
        void updateAll();
    };
    
}


#endif /* defined(__CcAdx2Basic__CueSheet__) */
