/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2010-2013 CRI Middleware Co., Ltd.
 *
 * Library  : CRI Atom
 * Module   : Library User's Header
 * File     : cri_le_atom_asr.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_le_atom_asr.h
 */

/* 多重定義防止					*/
/* Prevention of redefinition	*/
#ifndef CRI_INCL_CRI_LE_ATOM_ASR_H
#define CRI_INCL_CRI_LE_ATOM_ASR_H

/***************************************************************************
 *      インクルードファイル
 *      Include files
 ***************************************************************************/
#include <cri_le_xpt.h>
#include <cri_le_atom.h>
#include <cri_le_atom_ex.h>

/***************************************************************************
 *      定数マクロ
 *      Macro Constants
 ***************************************************************************/
/*JP
 * \brief 最大チャンネル数
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * ASRが処理可能な最大チャンネル数です。
 */
#define CRIATOMEXASR_MAX_CHANNELS		(8)

/*JP
 * \brief I3DL2リバーブプリセット "GENERIC"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_GENERIC \
	{ -1000,  -100, 1.49f, 0.83f,  -2602, 0.007f,    200, 0.011f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "PADED CELL"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_PADDEDCELL \
	{ -1000, -6000, 0.17f, 0.10f,  -1204, 0.001f,    207, 0.002f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "ROOM"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_ROOM \
	{ -1000,  -454, 0.40f, 0.83f,  -1646, 0.002f,     53, 0.003f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "BATH ROOM"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_BATHROOM \
	{ -1000, -1200, 1.49f, 0.54f,   -370, 0.007f,   1030, 0.011f, 100.0f,  60.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "LIVING ROOM"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_LIVINGROOM \
	{ -1000, -6000, 0.50f, 0.10f,  -1376, 0.003f,  -1104, 0.004f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "STONE ROOM"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_STONEROOM \
	{ -1000,  -300, 2.31f, 0.64f,   -711, 0.012f,     83, 0.017f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "AUDITORIUM"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_AUDITORIUM \
	{ -1000,  -476, 4.32f, 0.59f,   -789, 0.020f,   -289, 0.030f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "CONCERT HALL"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_CONCERTHALL \
	{ -1000,  -500, 3.92f, 0.70f,  -1230, 0.020f,     -2, 0.029f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "CAVE"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_CAVE \
	{ -1000,     0, 2.91f, 1.30f,   -602, 0.015f,   -302, 0.022f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "ARENA"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_ARENA \
	{ -1000,  -698, 7.24f, 0.33f,  -1166, 0.020f,     16, 0.030f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "HANGER"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_HANGAR \
	{ -1000, -1000, 10.05f, 0.23f,   -602, 0.020f,    198, 0.030f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "CARPETED HALLWAY"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_CARPETEDHALLWAY \
	{ -1000, -4000, 0.30f, 0.10f,  -1831, 0.002f,  -1630, 0.030f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "HALLWAY"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_HALLWAY \
	{ -1000,  -300, 1.49f, 0.59f,  -1219, 0.007f,    441, 0.011f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "STONE CORRIDOR"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_STONECORRIDOR \
	{ -1000,  -237, 2.70f, 0.79f,  -1214, 0.013f,    395, 0.020f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "ALLEY"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_ALLEY \
	{ -1000,  -270, 1.49f, 0.86f,  -1204, 0.007f,     -4, 0.011f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "FOREST"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_FOREST \
	{ -1000, -3300, 1.49f, 0.54f,  -2560, 0.162f,   -613, 0.088f,  79.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "CITY"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_CITY \
	{ -1000,  -800, 1.49f, 0.67f,  -2273, 0.007f,  -2217, 0.011f,  50.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "MOUNTAINS"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_MOUNTAINS \
	{ -1000, -2500, 1.49f, 0.21f,  -2780, 0.300f,  -2014, 0.100f,  27.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "QUARRY"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_QUARRY \
	{ -1000, -1000, 1.49f, 0.83f, -10000, 0.061f,    500, 0.025f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "PLAIN"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_PLAIN \
	{ -1000, -2000, 1.49f, 0.50f,  -2466, 0.179f,  -2514, 0.100f,  21.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "PARKINGLOT"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_PARKINGLOT \
	{ -1000,     0, 1.65f, 1.50f,  -1363, 0.008f,  -1153, 0.012f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "SEWER PIPE"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_SEWERPIPE \
	{ -1000, -1000, 2.81f, 0.14f,    429, 0.014f,    648, 0.021f,  80.0f,  60.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "UNDER WATER"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_UNDERWATER \
	{ -1000, -4000, 1.49f, 0.10f,   -449, 0.007f,   1700, 0.011f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "SMALL ROOM"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_SMALLROOM \
	{ -1000,  -600, 1.10f, 0.83f,   -400, 0.005f,    500, 0.010f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "MEDIUM ROOM"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_MEDIUMROOM \
	{ -1000,  -600, 1.30f, 0.83f,  -1000, 0.010f,   -200, 0.020f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "LARGE ROOM"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_LARGEROOM \
	{ -1000,  -600, 1.50f, 0.83f,  -1600, 0.020f,  -1000, 0.040f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "MEDIUM HALL"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_MEDIUMHALL \
	{ -1000,  -600, 1.80f, 0.70f,  -1300, 0.015f,   -800, 0.030f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "LARGE HALL"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_LARGEHALL \
	{ -1000,  -600, 1.80f, 0.70f,  -2000, 0.030f,  -1400, 0.060f, 100.0f, 100.0f, 5000.0f}
/*JP
 * \brief I3DL2リバーブプリセット "PLATE"
 * \ingroup ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_PLATE \
	{ -1000,  -200, 1.30f, 0.90f,      0, 0.002f,      0, 0.010f, 100.0f,  75.0f, 5000.0f}

/***************************************************************************
 *      処理マクロ
 *      Macro Functions
 ***************************************************************************/
/*==========================================================================
 *      CRI AtomEx ASR API
 *=========================================================================*/
/*JP
 * \brief ASRの初期化コンフィグ構造体にデフォルト値をセット
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * コンフィグ構造体（ ::CriAtomExAsrConfig ）に、デフォルト値をセットします。<br>
 * \sa CriAtomExAsrConfig
 */
#define criAtomExAsr_SetDefaultConfig(p_config)	\
{\
	(p_config)->server_frequency = 60.0f;\
	(p_config)->output_channels = CRIATOM_DEFAULT_OUTPUT_CHANNELS;\
	(p_config)->output_sampling_rate = CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE;\
	(p_config)->sound_renderer_type	= CRIATOM_SOUND_RENDERER_NATIVE;\
}

/*JP
 * \brief レベル測定機能コンフィグ構造体にデフォルト値をセット
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * ::criAtomExAsr_AttachBusAnalyzer 関数に設定するコンフィグ構造体
 * （ ::CriAtomExAsrBusAnalyzerConfig ）に、デフォルト値をセットします。<br>
 * \sa criAtomExAsr_AttachBusAnalyzer, CriAtomExAsrBusAnalyzerConfig
 */
#define criAtomExAsr_SetDefaultConfigForBusAnalyzer(p_config) \
{\
	(p_config)->interval = 50;\
	(p_config)->peak_hold_time = 1000;\
}

/***************************************************************************
 *      データ型宣言
 *      Data Type Declarations
 ***************************************************************************/
/*==========================================================================
 *      CRI AtomEx ASR API
 *=========================================================================*/
/*JP
 * \brief ASR初期化用コンフィグ構造体
 * \ingroup ATOMEXLIB_ASR
 * ASR（Atom Sound Renderer）の動作仕様を指定するための構造体です。<br>
 * \attention
 * 将来的にメンバが増える可能性があるため、 ::criAtomExAsr_SetDefaultConfig 
 * マクロを使用しない場合には、使用前に必ず構造体をゼロクリアしてください。<br>
 * （構造体のメンバに不定値が入らないようご注意ください。）
 * \sa criAtomExAsr_SetDefaultConfig
 */
typedef struct CriAtomExAsrConfigTag {
	/*JP
		\brief サーバ処理の実行頻度
		\par 説明:
		サーバ処理を実行する頻度を指定します。<br>
		\attention
		Atomライブラリ初期化時に指定した値（ ::CriAtomExConfig 構造体の
		server_frequency ）と、同じ値をセットする必要があります。<br>
		\sa CriAtomExConfig
	*/
	CriFloat32 server_frequency;

	/*JP
		\brief 出力チャンネル数
		\par 説明:
		ASRの出力チャンネル数を指定します。<br>
		パン3Dもしくは3Dポジショニング機能を使用する場合は6ch以上を指定します。<br>
	*/
	CriSint32 output_channels;
	
	/*JP
		\brief 出力サンプリングレート
		\par 説明:
		出力および処理過程のサンプリングレートを指定します。<br>
		通常、ターゲット機のサウンドデバイスのサンプリングレートを指定します。<br>
		\par 備考:
		低くすると処理負荷を下げることができますが音質が落ちます。<br>
	*/
	CriSint32 output_sampling_rate;
	
	/*JP
		\brief サウンドレンダラタイプ
		\par 説明:
		ASRの出力先サウンドレンダラの種別を指定します。<br>
		sound_renderer_type に CRIATOM_SOUND_RENDERER_NATIVE を指定した場合、
		音声データはデフォルト設定の各プラットフォームのサウンド出力に転送されます。<br>
		\attention
		CRIATOM_SOUND_RENDERER_ASRおよびCRIATOM_SOUND_RENDERER_DEFAULTは指定しないでください。
	*/
	CriAtomSoundRendererType sound_renderer_type;
} CriAtomExAsrConfig;

/*JP
 * \brief レベル測定機能アタッチ用コンフィグ構造体
 * \ingroup ATOMEXLIB_ASR
 * レベル測定機能をDSPバスにアタッチするための構造体です。<br>
 * ::criAtomExAsr_AttachBusAnalyzer 関数の引数に指定します。<br>
 * \par 備考:
 * デフォルト設定を使用する場合、 ::criAtomExAsr_SetDefaultConfigForBusAnalyzer マクロで
 * 構造体にデフォルトパラメータをセットした後、 ::criAtomExAsr_AttachBusAnalyzer 関数
 * に構造体を指定してください。<br>
 * \attention
 * 将来的にメンバが増える可能性があるため、 ::criAtomExAsr_SetDefaultConfigForBusAnalyzer
 * マクロを使用しない場合には、使用前に必ず構造体をゼロクリアしてください。<br>
 * （構造体のメンバに不定値が入らないようご注意ください。）
 * \sa criAtomExAsr_AttachBusAnalyzer
 */
typedef struct {
	/*JP
		\brief 測定間隔（ミリ秒単位）
		\par 説明:
		測定結果を更新する間隔です。<br>
	*/
	CriSint32 interval;

	/*JP
		\brief ピークホールド時間（ミリ秒単位）
		\par 説明:
		ピーク値がより大きい値で更新されたとき、下がらないようにホールドする時間です。<br>
	*/
	CriSint32 peak_hold_time;
} CriAtomExAsrBusAnalyzerConfig;

/*JP
 * \brief レベル測定情報
 * \par 説明:
 * DSPバスのレベル測定情報を取得するための構造体です。<br>
 * ::criAtomExAsr_GetBusAnalyzerInfo 関数で利用します。
 * \par 備考:
 * 各レベル値は音声データの振幅に対する倍率です（単位はデシベルではありません）。<br>
 * 以下のコードでデシベル表記に変換することができます。<br>
 * dB = 10.0f * log10f(level);
 * \sa criAtomExAsr_GetBusAnalyzerInfo
 */
typedef struct CriAtomExAsrBusAnalyzerInfoTag {
	/*JP
		\brief 有効チャンネル数
		\par 説明:
		測定結果が有効なチャンネル数です。<br>
	*/
	CriSint32 num_channels;
	
	/*JP
		\brief RMSレベル
		\par 説明:
		測定間隔間の音声振幅のRMS（二乗平均平方根）を計算した値です。<br>
		音圧レベルとして扱われます。
	*/
	CriFloat32 rms_levels[CRIATOMEXASR_MAX_CHANNELS];
	
	/*JP
		\brief ピークレベル
		\par 説明:
		測定間隔間の音声振幅の最大値です。<br>
	*/
	CriFloat32 peak_levels[CRIATOMEXASR_MAX_CHANNELS];
	
	/*JP
		\brief ピークホールドレベル
		\par 説明:
		ホールドしているピークレベル値です。<br>
	*/
	CriFloat32 peak_hold_levels[CRIATOMEXASR_MAX_CHANNELS];
} CriAtomExAsrBusAnalyzerInfo;

/*JP
 * \brief 波形フィルタコールバック関数
 * \ingroup ATOMEXLIB_PLAYER
 * \par 説明:
 * \param[in]		obj				ユーザ指定オブジェクト
 * \param[in]		format			PCMの形式
 * \param[in]		num_channels	チャンネル数
 * \param[in]		num_samples		サンプル数
 * \param[in,out]	data			PCMデータのチャンネル配列
 * \return							なし
 * \par 説明:
 * DSPバスに登録することができる PCM データを受け取るコールバック関数です。<br>
 * <br>
 * コールバック関数の登録には ::criAtomExAsr_SetBusFilterCallback 関数を使用します。<br>
 * コールバック関数を登録すると、サウンドレンダラが音声処理を行う度に、
 * コールバック関数が実行されるようになります。<br>
 * <br>
 * フィルタコールバック関数には、 PCM データのフォーマットやチャンネル数、
 * 参照可能なサンプル数、 PCM データを格納した領域のアドレスが返されます。<br>
 * コールバック内では PCM データの値を直接参照可能になるので、
 * 再生中の音声の振幅をチェックするといった用途に利用可能です。<br>
 * <br>
 * また、コールバック関数内で PCM データを加工すると、再生音に反映されるため、
 * PCM データに対してユーザ独自のエフェクトをかけることも可能です。<br>
 * （ただし、タイムストレッチ処理のようなデータ量が増減する加工を行うことはできません。）<br>
 * \par 備考:
 * PCM データはチャンネル単位で分離されています。<br>
 * （インターリーブされていません。）<br>
 * 第 6 引数（ data 配列）には、各チャンネルの PCM データ配列の先頭アドレスが格納されています。<br>
 * （二次元配列の先頭アドレスではなく、チャンネルごとの PCM データ配列の先頭アドレスを格納した
 * 一次元のポインタ配列です。）<br>
 * 格納されてくる PCM データはDSPバスに設定されているDSPの処理後の音声です。<br>
 * <br>
 * プラットフォームによって、 PCM データのフォーマットは異なります。<br>
 * 実行環境のデータフォーマットについては、第 3 引数（ format ）で判別可能です。<br>
 * PCM データのフォーマットが 16 bit 整数型の場合、 format は CRIATOM_PCM_FORMAT_SINT16 となり、
 * PCM データのフォーマットが 32 bit 浮動小数点数型の場合、 format は CRIATOM_PCM_FORMAT_FLOAT32 となります。<br>
 * それぞれのケースで PCM データの値域は異なりますのでご注意ください。<br>
 * - CRIATOM_PCM_FORMAT_SINT16 時は -32768 〜 +32767
 * - CRIATOM_PCM_FORMAT_FLOAT32 時は -1.0f 〜 +1.0f
 * .
 * （多重音声のミキシングや前段のエフェクトによっては上記範囲を超えた値が出る可能性があります。）<br>
 * \attention
 * <br>
 * 本コールバック関数内で、AtomライブラリのAPIを実行しないでください。<br>
 * コールバック関数はAtomライブラリ内のサーバ処理から実行されます。<br>
 * そのため、サーバ処理への割り込みを考慮しないAPIを実行した場合、
 * エラーが発生したり、デッドロックが発生する可能性があります。<br>
 * <br>
 * コールバック関数内で長時間処理をブロックすると、音切れ等の問題が発生する可能性があります。<br>
 * \sa criAtomExAsr_SetBusFilterCallback
 */
typedef void (*CriAtomExAsrBusFilterCbFunc)(void *obj, CriAtomPcmFormat format,
	CriSint32 num_channels, CriSint32 num_samples, void *data[]);

/*JP
 * \brief DSP ID
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * ASR（Atom Sound Renderer）のDSPを指定するための値です。<br>
 * \sa criAtomExAsr_SetDspParameter
 */
typedef enum {
	CRIATOMEXASR_DSP_ID_INVALID = 0,		/*JP< 無効ID				*/
	CRIATOMEXASR_DSP_ID_BANDPASS_FILTER,	/*JP< バンドパスフィルタ	*/
	CRIATOMEXASR_DSP_ID_BIQUAD_FILTER,		/*JP< バイクアッドフィルタ	*/
	CRIATOMEXASR_DSP_ID_DELAY,				/*JP< ディレイ				*/
	CRIATOMEXASR_DSP_ID_ECHO,				/*JP< エコー				*/
	CRIATOMEXASR_DSP_ID_REVERB,				/*JP< リバーブ				*/
	CRIATOMEXASR_DSP_ID_PITCH_SHIFTER,		/*JP< ピッチシフタ			*/
	CRIATOMEXASR_DSP_ID_3BAND_EQ,			/*JP< 3バンドイコライザ		*/
	CRIATOMEXASR_DSP_ID_COMPRESSOR,			/*JP< コンプレッサ			*/
	CRIATOMEXASR_DSP_ID_CHORUS,				/*JP< コーラス				*/
	CRIATOMEXASR_DSP_ID_FLANGER,			/*JP< フランジャー			*/
	CRIATOMEXASR_DSP_ID_DISTORTION,			/*JP< ディストーション		*/
	CRIATOMEXASR_DSP_ID_AMPLITUDE_ANALYZER,	/*JP< 振幅解析器			*/
	CRIATOMEXASR_DSP_ID_SURROUNDER,			/*JP< サラウンダ			*/
	CRIATOMEXASR_DSP_ID_I3DL2_REVERB,		/*JP< I3DL2リバーブ			*/
	CRIATOMEXASR_DSP_ID_MULTI_TAP_DELAY,	/*JP< マルチタップディレイ	*/
	CRIATOMEXASR_DSP_ID_LIMITER,			/*JP< リミッタ				*/
	CRIATOMEXASR_DSP_ID_MATRIX,				/*JP< マトリクス			*/
	CRIATOMEXASR_DSP_ID_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrDspId;

/*JP
 * \brief バンドパスフィルタのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * バンドパスフィルタDSPのパラメータを設定するための構造体です。<br>
 * 各値の扱いについては、::criAtomExPlayer_SetBandpassFilterParameters 関数と同様です。<br>
 * \sa criAtomExAsr_SetDspParameter,criAtomExPlayer_SetBandpassFilterParameters
 */
typedef struct CriAtomExAsrBandpassFilterParameterTag {
	/*JP 正規化高域カットオフ周波数 */
	CriFloat32 cof_high;
	/*JP 正規化低域カットオフ周波数 */
	CriFloat32 cof_low;
} CriAtomExAsrBandpassFilterParameter;

/*JP
 * \brief バンドパスフィルタのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * バンドパスフィルタDSPのパラメータを設定するための構造体です。<br>
 * 各値の扱いについては、::criAtomExPlayer_SetBiquadFilterParameters 関数と同様です。<br>
 * \sa criAtomExAsr_SetDspParameter,criAtomExPlayer_SetBiquadFilterParameters
 */
typedef struct CriAtomExAsrBiquadFilterParameterTag {
	/*JP フィルタタイプ */
	CriAtomExBiquadFilterType type;
	/*JP 正規化周波数 */
	CriFloat32 frequency;
	/*JP Q値 */
	CriFloat32 q_value;
	/*JP ゲイン */
	CriFloat32 gain;
} CriAtomExAsrBiquadFilterParameter;

/*JP
 * \brief ディレイのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * ディレイDSPのパラメータを設定するための構造体です。<br>
 * max_delay_time_msメンバは ::criAtomExAcf_GetDspFxParameters 関数
 * でパラメータを取得するときにだけ使用します。<br>
 * このメンバは ::criAtomExAsr_SetDspParameter 関数でのパラメータ変更時にには無視されます。
 * \sa criAtomExAcf_GetDspFxParameters, criAtomExAsr_SetDspParameter
 */
typedef struct CriAtomExAsrDelayParameterTag {
	/* 初期化パラメータ */
	/*JP 最大ディレイ時間（ミリ秒単位） */
	CriFloat32 max_delay_time_ms;
	/* 動作時パラメータ */
	/*JP ディレイ時間（ミリ秒単位） */
	CriFloat32 delay_time_ms;
} CriAtomExAsrDelayParameter;

/*JP
 * \brief エコーのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * エコーDSPのパラメータを設定するための構造体です。<br>
 * \sa criAtomExAsr_SetDspParameter
 */
typedef struct CriAtomExAsrEchoParameterTag {
	/* 初期化パラメータ */
	/*JP 最大ディレイ時間（ミリ秒単位） */
	CriFloat32 max_delay_time_ms;
	/*JP ディレイ時間（ミリ秒単位） */
	CriFloat32 delay_time_ms;
	/*JP フィードバックゲイン（0.0f〜1.0f） */
	CriFloat32 gain;
} CriAtomExAsrEchoParameter;

/*JP
 * \brief リバーブの動作モード
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * リバーブの動作モードを取得するためのデータ型です。<br>
 * ::criAtomExAcf_GetDspFxParameters 関数で利用します。
 * \sa criAtomExAcf_GetDspFxParameters
 */
typedef enum {
	CRIATOMEXASR_REVERB_MODE_SURROUND = 0,
	CRIATOMEXASR_REVERB_MODE_STEREO,
	CRIATOMEXASR_REVERB_MODE_REAR_ONLY,
	CRIATOMEXASR_REVERB_MODE_CENTER_ONLY,
	/* enum size is 4bytes */
	CRIATOMEXASR_REVERB_MODE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrReverbMode;

/*JP
 * \brief リバーブのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * リバーブDSPのパラメータを設定するための構造体です。<br>
 * max_predelay_time_msメンバとmax_room_sizeメンバは ::criAtomExAcf_GetDspFxParameters 関数
 * でパラメータを取得するときにだけ使用します。<br>
 * これらのメンバは ::criAtomExAsr_SetDspParameter 関数でのパラメータ変更時にには無視されます。
 * \sa criAtomExAcf_GetDspFxParameters, criAtomExAsr_SetDspParameter
 */
typedef struct CriAtomExAsrReverbParameterTag {
	/* リバーブの初期化パラメータ */
	/*JP 最大プリディレイ時間（ミリ秒単位） */
	CriFloat32 max_predelay_time_ms;
	/*JP 最大ルームサイズ（メートル秒単位） */
	CriFloat32 max_room_size;
	/*JP リバーブの動作モード */
	CriAtomExAsrReverbMode mode;
	/* リバーブの動作時パラメータ */
	/*JP 残響時間（ミリ秒単位） */
	CriFloat32 reverb_time_ms;
	/*JP 部屋の大きさ（メートル単位） */
	CriFloat32 room_size;
	/*JP プリディレイ時間（ミリ秒単位） */
	CriFloat32 predelay_time_ms;
	/*JP 低域カットオフ周波数（Hz単位） */
	CriFloat32 cof_low;
	/*JP 高域カットオフ周波数（Hz単位） */
	CriFloat32 cof_high;
} CriAtomExAsrReverbParameter;

/*JP
 * \brief ピッチシフタのウィンドウ幅
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * ピッチシフタのウィンドウ幅を取得するためのデータ型です。<br>
 * ::criAtomExAcf_GetDspFxParameters 関数で利用します。
 * \sa criAtomExAcf_GetDspFxParameters
 */
typedef enum {
	CRIATOMEXASR_PITCHSHIFTER_WINDOW_WIDTH_128 = 0,
	CRIATOMEXASR_PITCHSHIFTER_WINDOW_WIDTH_256,
	CRIATOMEXASR_PITCHSHIFTER_WINDOW_WIDTH_512,
	CRIATOMEXASR_PITCHSHIFTER_WINDOW_WIDTH_1024,
	CRIATOMEXASR_PITCHSHIFTER_WINDOW_WIDTH_2048,
	/* enum size is 4bytes */
	CRIATOMEXASR_PITCHSHIFTER_WINDOW_WIDTH_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrPitchShifterWindowWidthType;

/*JP
 * \brief ピッチシフタのオーバーラップ量
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * ピッチシフタのオーバーラップ量を取得するためのデータ型です。<br>
 * ::criAtomExAcf_GetDspFxParameters 関数で利用します。
 * \sa criAtomExAcf_GetDspFxParameters
 */
typedef enum {
	CRIATOMEXASR_PITCHSHIFTER_OVERLAP_1 = 0,
	CRIATOMEXASR_PITCHSHIFTER_OVERLAP_2,
	CRIATOMEXASR_PITCHSHIFTER_OVERLAP_4,
	CRIATOMEXASR_PITCHSHIFTER_OVERLAP_8,
	/* enum size is 4bytes */
	CRIATOMEXASR_PITCHSHIFTER_OVERLAP_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrPitchShifterOverlapType;

/*JP
 * \brief ピッチシフタのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * ピッチシフタDSPのパラメータを設定するための構造体です。<br>
 * window_widthメンバとoverlapメンバは ::criAtomExAcf_GetDspFxParameters 関数
 * でパラメータを取得するときにだけ使用します。<br>
 * これらのメンバは ::criAtomExAsr_SetDspParameter 関数でのパラメータ変更時にには無視されます。
 * \sa criAtomExAcf_GetDspFxParameters, criAtomExAsr_SetDspParameter
 */
typedef struct CriAtomExAsrPitchShifterParameterTag {
	/* ピッチシフタの動作時パラメータ */
	/*JP ピッチシフト値（セント単位） */
	CriFloat32 pitch_cent;
	/*JP フォルマントシフト値（セント単位） */
	CriFloat32 formant_cent;
	/*JP ピッチシフトモード */
	CriSint32 mode;
	/* ピッチシフタの初期化パラメータ */
	/*JP ウインドウ幅 */
    CriAtomExAsrPitchShifterWindowWidthType window_width;
	/*JP オーバーラップ量 */
    CriAtomExAsrPitchShifterOverlapType overlap;
} CriAtomExAsrPitchShifterParameter;

/*JP
 * \brief イコライザのバンドタイプ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * イコライザのバンドタイプを指定するためのデータ型です。<br>
 * ::CriAtomExAsr3BandsEqParameter 関数で利用します。
 */
typedef enum {
	CRIATOMEX_EQ_BAND_TYPE_LOWSHELF = 0,	/*JP<ローシェルフタイプ	*/
	CRIATOMEX_EQ_BAND_TYPE_HIGHSHELF = 1,	/*JP<ハイシェルフタイプ	*/
	CRIATOMEX_EQ_BAND_TYPE_PEAKING = 2,		/*JP<ピーキングフタイプ	*/

	/* enum size is 4bytes */
	CRIATOMEX_EQ_BAND_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrEqBandType;

/*JP
 * \brief 3バンドイコライザのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * 3バンドイコライザDSPのパラメータを設定するための構造体です。<br>
 * \sa criAtomExAsr_SetDspParameter
 */
typedef struct CriAtomExAsr3BandsEqParameterTag {
	struct {
		/*JP バンドタイプ */
		CriAtomExAsrEqBandType type;
		/*JP 正規化周波数 */
		CriFloat32 frequency;
		/*JP Q値 */
		CriFloat32 q_value;
		/*JP ゲイン */
		CriFloat32 gain;
	} bands[3];
} CriAtomExAsr3BandsEqParameter;

/*JP
 * \brief コンプレッサのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * コンプレッサDSPのパラメータを設定するための構造体です。<br>
 * side_chain_input_bus_noメンバは ::criAtomExAcf_GetDspFxParameters 関数
 * でパラメータを取得するときにだけ使用します。<br>
 * このメンバは ::criAtomExAsr_SetDspParameter 関数でのパラメータ変更時にには無視されます。
 * \sa criAtomExAcf_GetDspFxParameters, criAtomExAsr_SetDspParameter
 */
typedef struct CriAtomExAsrCompressorParameterTag {
	/*JP スレッショルド（dB単位） */
	CriFloat32 threshold;
	/*JP 圧縮レート（0.0f〜。負値で無限圧縮） */
	CriFloat32 ratio;
	/*JP アタック時間（ミリ秒単位） */
	CriFloat32 attack_time;
	/*JP リリース時間（ミリ秒単位） */
	CriFloat32 release_time;
	/*JP 出力ゲイン（dB単位） */
	CriFloat32 output_gain; 
	/*JP サラウンドリンク（0.0f〜1.0f） */
	CriFloat32 surround_link;
	/*JP サイドチェイン入力バス番号（0の場合はサイドチェインなし） */
	CriSint32 side_chain_input_bus_no;
} CriAtomExAsrCompressorParameter;

/*JP
 * \brief コーラスのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * コーラスDSPのパラメータを設定するための構造体です。<br>
 * max_delay_time_msメンバは ::criAtomExAcf_GetDspFxParameters 関数
 * でパラメータを取得するときにだけ使用します。<br>
 * このメンバは ::criAtomExAsr_SetDspParameter 関数でのパラメータ変更時にには無視されます。
 * \sa criAtomExAcf_GetDspFxParameters, criAtomExAsr_SetDspParameter
 */
typedef struct CriAtomExAsrChorusParameterTag {
	/* コーラスの初期化パラメータ */
	/*JP 最大プリディレイ時間（ミリ秒単位） */
	CriFloat32 max_delay_time_ms;
	/* コーラスの動作時パラメータ */
	/*JP ディレイ時間（ミリ秒） */
	CriFloat32 delay_time_ms;
	/*JP LFO周波数（Hz） */
	CriFloat32 rate;
	/*JP LFO振幅（0.0f〜1.0f） */
	CriFloat32 depth;
	/*JP フィードバック量（0.0f〜1.0f） */
	CriFloat32 feedback;
	/*JP 原音成分の割合（0.0f〜1.0f） */
	CriFloat32 dry_mix; 
	/*JP エフェクトタップ1の割合（0.0f〜1.0f） */
	CriFloat32 wet_mix1;
	/*JP エフェクトタップ2の割合（0.0f〜1.0f） */
	CriFloat32 wet_mix2;
	/*JP エフェクトタップ3の割合（0.0f〜1.0f） */
	CriFloat32 wet_mix3;
} CriAtomExAsrChorusParameter;

/*JP
 * \brief フランジャーのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * フランジャーDSPのパラメータを設定するための構造体です。<br>
 * \sa criAtomExAsr_SetDspParameter
 */
typedef struct CriAtomExAsrFlangerParameterTag {
	/*JP ディレイ時間（ミリ秒） */
	CriFloat32 delay_time_ms;
	/*JP LFO周波数（Hz） */
	CriFloat32 rate;
	/*JP LFO振幅（0.0f〜1.0f） */
	CriFloat32 depth;
	/*JP フィードバック量（0.0f〜1.0f） */
	CriFloat32 feedback;
	/*JP 原音成分の割合（0.0f〜1.0f） */
	CriFloat32 dry_mix; 
	/*JP エフェクト成分の割合（0.0f〜1.0f） */
	CriFloat32 wet_mix;
} CriAtomExAsrFlangerParameter;

/*JP
 * \brief ディストーションのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * ディストーションDSPのパラメータを設定するための構造体です。<br>
 * \sa criAtomExAsr_SetDspParameter
 */
typedef struct CriAtomExAsrDistortionParameterTag {
	/*JP 歪み（dB単位） */
	CriFloat32 drive;
	/*JP 原音成分の割合（0.0f〜1.0f） */
	CriFloat32 dry_mix; 
	/*JP エフェクト成分の割合（0.0f〜1.0f） */
	CriFloat32 wet_mix;
	/*JP 出力ゲイン（dB単位） */
	CriFloat32 output_gain; 
} CriAtomExAsrDistortionParameter;

/*JP
 * \brief サラウンダのモード
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * サラウンダDSPの処理モードを指定するためのデータ型です。<br>
 * \sa criAtomExAsr_SetDspParameter
 */
typedef enum {
	CRIATOMEX_SURROUNDER_MODE_STRAIGHT = 0,
	CRIATOMEX_SURROUNDER_MODE_CROSS = 1,
	CRIATOMEX_SURROUNDER_MODE_MATRIX = 2,
	/* enum size is 4bytes */
	CRIATOMEX_SURROUNDER_MODE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrSurrounderMode;

/*JP
 * \brief サラウンダのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * サラウンダDSPのパラメータを設定するための構造体です。<br>
 * \sa criAtomExAsr_SetDspParameter
 */
typedef struct CriAtomExAsrSurrounderParameterTag {
	/* サラウンダの初期化パラメータ */
	/*JP 最大プリディレイ時間（ミリ秒単位） */
	CriFloat32 max_delay_time_ms;
	/* サラウンダの動作時パラメータ */
	/*JP ディレイ時間（ミリ秒） */
	CriFloat32 delay_time_ms;
	/*JP 出力ゲイン（dB単位） */
	CriFloat32 gain;
	/*JP サラウンド処理モード */
	CriAtomExAsrSurrounderMode mode;
} CriAtomExAsrSurrounderParameter;

/*JP
 * \brief I3DL2リバーブのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * I3DL2リバーブDSPのパラメータを設定するための構造体です。<br>
 * \sa criAtomExAsr_SetDspParameter
 */
typedef struct CriAtomExAsrI3DL2ReverbParameterTag {
	/*JP ディレイ時間（ミリ秒） */
	CriFloat32 room;
	/*JP 参照周波数より高域のレベル（ミリベル） */
	CriFloat32 room_hf;
	/*JP 後期残響時間（秒） */
	CriFloat32 decay_time;
	/*JP 後期残響音の参照周波数より高域の減衰率 */
	CriFloat32 decay_hf_ratio;
	/*JP 初期反射音のレベル（ミリベル） */
	CriFloat32 reflections;
	/*JP 初期反射音のディレイ（秒） */
	CriFloat32 reflections_delay;
	/*JP 後期残響音のレベル（ミリベル） */
	CriFloat32 reverb;
	/*JP 後期残響音のディレイ（秒） */
	CriFloat32 reverb_delay;
	/*JP 後期残響音のエコー密度 */
	CriFloat32 diffusion;
	/*JP 後期残響音のモデル密度 */
	CriFloat32 density;
	/*JP 参照周波数（Hz） */
	CriFloat32 hf_reference;
	/*JP フロントCH入力レベル */
	CriFloat32 front_input;
	/*JP リアCH入力レベル */
	CriFloat32 rear_input;
	/*JP センターCH入力レベル */
	CriFloat32 center_input;
	/*JP フロントCH出力レベル */
	CriFloat32 front_output;
	/*JP リアCH出力レベル */
	CriFloat32 rear_output;
	/*JP センターCH出力レベル */
	CriFloat32 center_output;
} CriAtomExAsrI3DL2ReverbParameter;

/*JP
 * \brief Multi tap delayのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * Multi tap delayDSPのパラメータを設定するための構造体です。<br>
 * \sa criAtomExAsr_SetDspParameter
 */
typedef struct CriAtomExAsrMultiTapDelayParameterTag {
	/*JP 最大ディレイ時間（50〜1000ms） */
	CriFloat32 max_delay_time_ms;
	struct {
		/*JP ディレイ時間（0〜最大） */
		CriFloat32 delay_time_ms;
		/*JP レベル（0.0〜1.0） */
		CriFloat32 level;
		/*JP パン角度（-180 〜 180） */
		CriFloat32 pan;
		/*JP フィードバック量（0.0 〜 1.0） */
		CriFloat32 feedback;
	} taps[4];
} CriAtomExAsrMultiTapDelayParameter;

/*JP
 * \brief リミッタのタイプ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * リミッタDSPの処理タイプを指定するためのデータ型です。<br>
 * \sa criAtomExAsr_SetDspParameter
 */
typedef enum {
	CRIATOMEX_LIMITER_TYPE_PEAK = 0,
	CRIATOMEX_LIMITER_TYPE_RMS = 1,
	/* enum size is 4bytes */
	CRIATOMEX_LIMITER_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrLimiterType;

/*JP
 * \brief リミッタのパラメータ
 * \ingroup ATOMEXLIB_ASR
 * \par 説明:
 * リミッタDSPのパラメータを設定するための構造体です。<br>
 * side_chain_input_bus_noメンバは ::criAtomExAcf_GetDspFxParameters 関数
 * でパラメータを取得するときにだけ使用します。<br>
 * このメンバは ::criAtomExAsr_SetDspParameter 関数でのパラメータ変更時にには無視されます。
 * \sa criAtomExAcf_GetDspFxParameters, criAtomExAsr_SetDspParameter
 */
typedef struct CriAtomExAsrLimiterParameterTag {
	/*JP タイプ */
	CriAtomExAsrLimiterType type;
	/*JP スレッショルド（dB単位） */
	CriFloat32 threshold;
	/*JP アタック時間（ミリ秒単位） */
	CriFloat32 attack_time;
	/*JP リリース時間（ミリ秒単位） */
	CriFloat32 release_time;
	/*JP 出力ゲイン（dB単位） */
	CriFloat32 output_gain; 
	/*JP サラウンドリンク（0.0f〜1.0f） */
	CriFloat32 surround_link;
	/*JP サイドチェイン入力バス番号（0の場合はサイドチェインなし） */
	CriSint32 side_chain_input_bus_no;
} CriAtomExAsrLimiterParameter;

/***************************************************************************
 *      変数宣言
 *      Prototype Variables
 ***************************************************************************/

/***************************************************************************
 *      関数宣言
 *      Prototype Functions
 ***************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*==========================================================================
 *      CRI AtomEx ASR API
 *=========================================================================*/

/*JP
 * \brief DSPバスのボリュームの設定
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_no		DSPバス番号
 * \param[in]	volume		ボリューム値
 * \par 説明:
 * DSPバスのボリュームを設定します。<br>
 * センドタイプがポストボリューム、ポストパンのセンド先に有効です。<br>
 * <br>
 * ボリューム値には、0.0f〜1.0fの範囲で実数値を指定します。<br>
 * ボリューム値は音声データの振幅に対する倍率です（単位はデシベルではありません）。<br>
 * 例えば、1.0fを指定した場合、原音はそのままのボリュームで出力されます。<br>
 * 0.5fを指定した場合、原音波形の振幅を半分にしたデータと同じ音量（-6dB）で
 * 音声が出力されます。<br>
 * 0.0fを指定した場合、音声はミュートされます（無音になります）。<br>
 * ボリュームのデフォルト値はCRI Atom Craftで設定した値です。<br>
 */
void CRIAPI criAtomExAsr_SetBusVolume(CriSint32 bus_no, CriFloat32 volume);

/*JP
 * \brief DSPバスのパンニング3Dの設定
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_no				DSPバス番号
 * \param[in]	pan3d_angle			Pan3D 角度
 * \param[in]	pan3d_distance		Pan3D インテリア距離
 * \param[in]	pan3d_volume		Pan3D 音量
 * \par 説明:
 * DSPバスのパンニング3Dのパラメータを設定します。<br>
 * センドタイプがポストパンのセンド先に有効です。<br>
 * <br>
 * Pan3D角度は、-180.0f 〜 180.0fの範囲で設定します。<br>
 * <br>
 * Pan3Dインテリア距離は、0.0f 〜 1.0fの範囲で設定します。<br>
 * <br>
 * Pan3Dボリュームは、0.0f 〜 1.0fの範囲で設定します。<br>
 * 通常のボリュームと掛け合わされます。
 * <br>
 * パン3Dのデフォルト値はCRI Atom Craftで設定した値です。<br>
 */
void CRIAPI criAtomExAsr_SetBusPan3d(CriSint32 bus_no, 
	CriFloat32 pan3d_angle, CriFloat32 pan3d_distance, CriFloat32 pan3d_volume);

/*JP
 * \brief DSPバスのレベル行列の設定
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_no			DSPバス番号
 * \param[in]	input_channels	入力チャンネル数
 * \param[in]	output_channels	出力チャンネル数
 * \param[in]	matrix			レベル行列を1次元に表したレベル値の配列
 * \par 説明:
 * DSPバスのレベル行列を設定します。<br>
 * センドタイプがポストパンのセンド先に有効です。<br>
 * <br>
 * レベルマトリックスは、音声データの各チャンネルの音声を、どのスピーカーから
 * どの程度の音量で出力するかを指定するための仕組みです。<br>
 * matrixは[input_channels * output_channels]の配列です。<br>
 * 入力チャンネルch_inから出力チャンネルch_outにセンドされるレベルは
 * matrix[ch_in * output_channels + ch_out]にセットします。<br>
 * レベル行列のデフォルト値は単位行列です。<br>
 * <br>
 * レベル値には、0.0f〜1.0fの範囲で実数値を指定します。<br>
 * レベル値は音声データの振幅に対する倍率です（単位はデシベルではありません）。<br>
 * 例えば、1.0fを指定した場合、原音はそのままのレベルで出力されます。<br>
 * 0.5fを指定した場合、原音波形の振幅を半分にしたデータと同じ音量（-6dB）で
 * 音声が出力されます。<br>
 * 0.0fを指定した場合、音声はミュートされます（無音になります）。<br>
 */
void CRIAPI criAtomExAsr_SetBusMatrix(CriSint32 bus_no, 
	CriSint32 input_channels, CriSint32 output_channels, const CriFloat32 matrix[]);

/*JP
 * \brief DSPバスのセンドレベルの設定
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_no		DSPバス番号
 * \param[in]	sendto_no	センド先のDSPバス番号
 * \param[in]	level		レベル値
 * \par 説明:
 * センド先DSPバスに音声データを送る際のレベルを設定します。<br>
 * <br>
 * レベル値には、0.0f〜1.0fの範囲で実数値を指定します。<br>
 * レベル値は音声データの振幅に対する倍率です（単位はデシベルではありません）。<br>
 * 例えば、1.0fを指定した場合、原音はそのままのレベルで出力されます。<br>
 * 0.5fを指定した場合、原音波形の振幅を半分にしたデータと同じ音量（-6dB）で
 * 音声が出力されます。<br>
 * 0.0fを指定した場合、音声はミュートされます（無音になります）。<br>
 * レベルのデフォルト値はCRI Atom Craftで設定した値です。<br>
 */
void CRIAPI criAtomExAsr_SetBusSendLevel(
	CriSint32 bus_no, CriSint32 sendto_no, CriFloat32 level);

/*JP
 * \brief DSPパラメータの設定
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_no		DSPバス番号
 * \param[in]	dsp_id		DSP ID
 * \param[in]	parameter	DSPパラメータ
 * \par 説明:
 * DSPパラメータを設定します。<br>
 * DSPパラメータを設定する際は、本関数呼び出し前にあらかじめ
 * ::criAtomExAsr_AttachDspBusSetting 関数でDSPバスが構築されている必要があります。<br>
 * どのDSPバスにどのDSPが存在するかは、アタッチしたDSPバス設定に依存します。指定したDSPバスに指定したIDのDSPが存在しない場合、関数は失敗します。<br>
 * DSPパラメータには、各DSPのパラメータ構造体を指定してください。
 * \sa criAtomExAsr_AttachDspBusSetting
 */
void CRIAPI criAtomExAsr_SetDspParameter(
	CriSint32 bus_no, CriAtomExAsrDspId dsp_id, const void* parameter);

/*JP
 * \brief DSPのバイパス設定
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_no		DSPバス番号
 * \param[in]	dsp_id		DSP ID
 * \param[in]	bypass		バイパス設定
 * \par 説明:
 * DSPのバイパス設定を行います。<br>
 * バイパス設定されたDSPは音声処理の際、スルーされるようになります。<br>
 * DSPのバイパス設定をする際は、本関数呼び出し前にあらかじめ
 * ::criAtomExAsr_AttachDspBusSetting 関数でDSPバスが構築されている必要があります。<br>
 * どのDSPバスにどのDSPが存在するかは、アタッチしたDSPバス設定に依存します。指定したDSPバスに指定したIDのDSPが存在しない場合、関数は失敗します。<br>
 * DSPパラメータには、各DSPのパラメータ構造体を指定してください。
 * \attention
 * 音声再生中にバイパス設定を行うとノイズが発生することがあります。<br>
 * \sa criAtomExAsr_AttachDspBusSetting
 */
void CRIAPI criAtomExAsr_SetDspBypass(
	CriSint32 bus_no, CriAtomExAsrDspId dsp_id, CriBool bypass);

/*JP
 * \brief レベル測定機能の追加
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_no		DSPバス番号
 * \param[in]	config		レベル測定機能のコンフィグ構造体
 * \par 説明:
 * DSPバスにレベル測定機能を追加し、レベル測定処理を開始します。<br>
 * 本関数を実行後、 ::criAtomExAsr_GetBusAnalyzerInfo 関数を実行することで、
 * RMSレベル（音圧）、ピークレベル（最大振幅）、ピークホールドレベルを
 * 取得することが可能です。
 * 複数DSPバスのレベルを計測するには、DSPバスごとに本関数を呼び出す必要があります。
 * \par 例:
 * \code
 * 	// レベル測定情報取得用構造体
 * 	CriAtomExAsrBusAnalyzerInfo info;
 * 	
 * 	// 0番バス（マスターバス）にレベル測定機能の追加
 * 	criAtomExAsr_AttachBusAnalyzer(0, NULL);
 * 	
 * 	　　：
 * 	
 * 	// レベル測定情報の取得
 * 	criAtomExAsr_GetBusAnalyzerInfo(0, &info);
 * 	
 * 	// 計測結果の表示
 *  for (i = 0; i < CRIATOMEXASR_MAX_CHANNELS; i++) {
 * 	    printf("[%d] RMS: %1.6f, Peak: %1.6f, Hold: %1.6f", 
 * 	        i, info.rms_levels[i], info.peak_levels[i], info.peak_hold_levels[i]);
 *  }
 * \endcode
 * \attention
 * 本関数は ::criAtomExAsr_AttachDspBusSetting 関数と同一のリソースを操作します。<br>
 * そのため、現状は ::criAtomExAsr_AttachDspBusSetting 関数を実行すると、
 * ::criAtomExAsr_GetBusAnalyzerInfo 関数による情報取得ができなくなります。<br>
 * 本関数と ::criAtomExAsr_AttachDspBusSetting 関数を併用する際には、
 * ::criAtomExAsr_AttachDspBusSetting 関数を実行する前に一旦
 * ::criAtomExAsr_DetachBusAnalyzer 関数でレベル測定機能を無効化し、
 * ::criAtomExAsr_AttachDspBusSetting 関数実行後に再度本関数を実行してください。<br>
 * \code
 * 		：
 * 	// DSPバス設定の変更前に一旦レベル測定機を無効化
 * 	criAtomExAsr_DetachBusAnalyzer(0);
 * 	
 * 	// DSPバス設定の更新
 * 	criAtomExAsr_AttachDspBusSetting("DspBusSetting_0", NULL, 0);
 * 	
 * 	// レベル測定機の再アタッチ
 * 	criAtomExAsr_AttachBusAnalyzer(0, NULL);
 * 		：
 * \endcode
 * \sa criAtomExAsr_GetBusAnalyzerInfo, criAtomExAsr_DetachBusAnalyzer
 */
void CRIAPI criAtomExAsr_AttachBusAnalyzer(
	CriSint32 bus_no, const CriAtomExAsrBusAnalyzerConfig* config);

/*JP
 * \brief レベル測定機能の削除
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_no		DSPバス番号
 * \par 説明:
 * DSPバスからレベル測定機能を削除します。
 * \sa criAtomExAsr_AttachBusAnalyzer
 */
void CRIAPI criAtomExAsr_DetachBusAnalyzer(CriSint32 bus_no);

/*JP
 * \brief レベル測定結果の取得
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_no		DSPバス番号
 * \param[out]	info		レベル測定結果の構造体
 * \par 説明:
 * DSPバスからレベル測定機能の結果を取得します。
 * \sa criAtomExAsr_AttachBusAnalyzer
 */
void CRIAPI criAtomExAsr_GetBusAnalyzerInfo(
	CriSint32 bus_no, CriAtomExAsrBusAnalyzerInfo *info);

/*JP
 * \brief 波形フィルタコールバック関数の登録
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_no		DSPバス番号
 * \param[in]	pre_func	DSP処理前のフィルタコールバック関数
 * \param[in]	post_func	DSP処理後のフィルタコールバック関数
 * \param[in]	obj			ユーザ指定オブジェクト
 * \par 説明:
 * DSPバスに流れている PCM データを受け取るコールバック関数を登録します。<br>
 * 登録されたコールバック関数は、サウンドレンダラが音声処理を行ったタイミングで呼び出されます。<br>
 * DSP処理前とDSP処理後の2種類の使用しないほうはNULL指定が可能です。<br>
 * \attention
 * コールバック関数内で、AtomライブラリのAPIを実行しないでください。<br>
 * コールバック関数はAtomライブラリ内のサーバ処理から実行されます。<br>
 * そのため、サーバ処理への割り込みを考慮しないAPIを実行した場合、
 * エラーが発生したり、デッドロックが発生する可能性があります。<br>
 * <br>
 * 波形フィルタコールバック関数内で長時間処理をブロックすると、音切れ等の問題
 * が発生しますので、ご注意ください。<br>
 * \sa CriAtomExPlayerFilterCbFunc
 */
void CRIAPI criAtomExAsr_SetBusFilterCallback(CriSint32 bus_no, 
	CriAtomExAsrBusFilterCbFunc pre_func, CriAtomExAsrBusFilterCbFunc post_func, void *obj);

#ifdef __cplusplus
}
#endif

#endif	/* CRI_INCL_CRI_LE_ATOM_ASR_H */

/* --- end of file --- */
