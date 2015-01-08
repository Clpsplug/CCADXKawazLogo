/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2013 CRI Middleware Co., Ltd.
 *
 * Library  : CRI Atom
 * Module   : Library User's Header for iOS
 * File     : cri_le_atom_ios.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_le_atom_ios.h
 */

/* 多重定義防止					*/
/* Prevention of redefinition	*/
#ifndef	CRI_INCL_CRI_LE_ATOM_PC_H
#define	CRI_INCL_CRI_LE_ATOM_PC_H

/***************************************************************************
 *      インクルードファイル
 *      Include files
 ***************************************************************************/
#include <cri_le_error.h>
#include <cri_le_atom.h>
#include <cri_le_atom_ex.h>
#include <cri_le_atom_asr.h>

/***************************************************************************
 *      定数マクロ
 *      Macro Constants
 ***************************************************************************/
/*==========================================================================
 *      CRI Atom API
 *=========================================================================*/
/*JP
 * \brief ライブラリ初期化用コンフィグ構造体にデフォルト値をセット
 * \ingroup ATOMLIB_IOS
 * \param[out]	p_config	初期化用コンフィグ構造体へのポインタ
 * \par 説明:
 * ::criAtom_Initialize_IOS 関数に設定するコンフィグ構造体
 * （ ::CriAtomConfig_IOS ）に、デフォルトの値をセットします。<br>
 * \attention
 * 本マクロは下位レイヤ向けのAPIです。<br>
 * AtomExレイヤの機能を利用する際には、本マクロの代わりに 
 * ::criAtomEx_SetDefaultConfig_IOS マクロをご利用ください。
 * \sa CriAtomConfig_IOS
 */
#define criAtom_SetDefaultConfig_IOS(p_config)				\
{															\
	criAtom_SetDefaultConfig(&(p_config)->atom);			\
	criAtomExAsr_SetDefaultConfig(&(p_config)->asr);		\
    criAtomHcaMx_SetDefaultConfig(&(p_config)->hca_mx);		\
    (p_config)->buffering_time = 50;						\
    (p_config)->output_sampling_rate = CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE; \
}

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ライブラリ初期化用コンフィグ構造体にデフォルト値をセット
 * \ingroup ATOMLIB_IOS
 * \param[out]	p_config	初期化用コンフィグ構造体へのポインタ
 * \par 説明:
 * ::criAtomEx_Initialize_IOS 関数に設定するコンフィグ構造体
 * （ ::CriAtomExConfig_IOS ）に、デフォルトの値をセットします。<br>
 * \sa CriAtomExConfig_IOS
 */
#define criAtomEx_SetDefaultConfig_IOS(p_config)			\
{															\
	criAtomEx_SetDefaultConfig(&(p_config)->atom_ex);		\
	criAtomExAsr_SetDefaultConfig(&(p_config)->asr);		\
    criAtomExHcaMx_SetDefaultConfig(&(p_config)->hca_mx);	\
    (p_config)->buffering_time = 50;						\
    (p_config)->output_sampling_rate = CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE; \
}

/***************************************************************************
 *      処理マクロ
 *      Macro Functions
 ***************************************************************************/

/***************************************************************************
 *      データ型宣言
 *      Data Type Declarations
 ***************************************************************************/
/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief Atomライブラリ初期化用コンフィグ構造体
 * \ingroup ATOMLIB_IOS
 * CRI Atomライブラリの動作仕様を指定するための構造体です。<br>
 * ::criAtomEx_Initialize_IOS 関数の引数に指定します。<br>
 * \sa criAtomEx_Initialize_IOS, criAtomEx_SetDefaultConfig_IOS
 */
typedef struct {
	CriAtomExConfig			atom_ex;	/* AtomEx初期化用コンフィグ構造体	*/
	CriAtomExAsrConfig		asr;		/* ASR初期化用コンフィグ		*/
	CriAtomExHcaMxConfig	hca_mx;		/* HCA-MX初期化用コンフィグ構造体	*/
	CriUint32				buffering_time;	/* 出力バッファリング時間(単位:msec)	*/
	CriSint32				output_sampling_rate;	/* 出力サンプリング周波数	*/
} CriAtomExConfig_IOS;

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
 *      CRI Atom API
 *=========================================================================*/

/*JP
 * \brief サーバスレッドプライオリティの設定
 * \ingroup ATOMLIB_IOS
 * \param[in]	prio	スレッドのプライオリティ
 * \par 説明:
 * CRIサーバスレッドのプライオリティを設定します。<br>
 * 引数 prio は pthread のプライオリティ設定値として使用します。<br>
 * プライオリティ設定値はメインスレッドからの相対値になります。<br>
 * アプリケーションのメインスレッド(0)よりも高いプライオリティを指定してください。<br>
 * プライオリティのデフォルト値は16です。<br>
 * \attention
 * ::criAtom_Initialize_IOS 関数実行前に本関数を実行することはできません。<br>
 * <br>
 * サーバ処理スレッドは、CRI File Systemライブラリでも利用されています。<br>
 * すでにCRI File SystemライブラリのAPIでサーバ処理スレッドの設定を変更している場合
 * 本関数により設定が上書きされますのでご注意ください。<br>
 */
void CRIAPI criAtom_SetServerThreadPriority_IOS(int prio);

/*JP
 * \brief サウンド処理の再開
 * \ingroup ATOMLIB_IOS
 * \par 説明:
 * AudioSessionのInterruption Callbak関数から呼び出すための関数です。<br>
 * サウンド処理を再開します。<br>
 * 本関数を呼び出す前に、AudioSessionのパメラータ設定とアクティベイトを行ってください。<br>
 * <br>
 * 本関数は下位レイヤ向けのAPIです。<br>
 * AtomExレイヤの機能を利用する際には、本関数の代わりに 
 * ::criAtomEx_StartSound_IOS 関数をご利用ください。
 * \attention
 * ::criAtom_Initialize_IOS 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtom_StopSound_IOS
 */
void CRIAPI criAtom_StartSound_IOS(void);

/*JP
 * \brief サウンド処理の停止
 * \ingroup ATOMLIB_IOS
 * \par 説明:
 * AudioSessionのInterruption Callbak関数から呼び出すための関数です。<br>
 * サウンド処理を停止します。<br>
 * <br>
 * 本関数は下位レイヤ向けのAPIです。<br>
 * AtomExレイヤの機能を利用する際には、本関数の代わりに 
 * ::criAtomEx_StopSound_IOS 関数をご利用ください。
 * \attention
 * ::criAtom_Initialize_IOS 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtom_StartSound_IOS
 */
void CRIAPI criAtom_StopSound_IOS(void);


/*JP
 * \brief サウンドの復旧
 * \ingroup ATOMLIB_IOS
 * \par 説明:
 * AudioSessionAddPropertyListener Callback関数から呼び出すための関数です。<br>
 * ライブラリ内部のボイスを復旧します。<br>
 * iOSのデーモンであるmediaserverdが死亡した際には、ライブラリ内のボイスが無効なボイスになり、
 * 再生成が必要になります。<br>
 * このように、ボイスの復旧が必要な際に呼び出してください。<br>
 * <br>
 * 本関数は下位レイヤ向けのAPIです。<br>
 * AtomExレイヤの機能を利用する際には、本関数の代わりに 
 * ::criAtomEx_RecoverSound_IOS 関数をご利用ください。
 */
void CRIAPI criAtom_RecoverSound_IOS(void);


/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ライブラリ初期化用ワーク領域サイズの計算
 * \ingroup ATOMLIB_IOS
 * \param[in]	config		初期化用コンフィグ構造体
 * \return		CriSint32	ワーク領域サイズ
 * \par 説明:
 * ライブラリを使用するために必要な、ワーク領域のサイズを取得します。<br>
 * \par 備考:
 * ライブラリが必要とするワーク領域のサイズは、ライブラリ初期化用コンフィグ
 * 構造体（ ::CriAtomExConfig_IOS ）の内容によって変化します。<br>
 * <br>
 * 引数 config の情報は、関数内でのみ参照されます。<br>
 * 関数を抜けた後は参照されませんので、関数実行後に config の領域を解放しても
 * 問題ありません。
 * \sa CriAtomExConfig_IOS, criAtomEx_Initialize_IOS
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSize_IOS(const CriAtomExConfig_IOS *config);

/*JP
 * \brief ライブラリの初期化
 * \ingroup ATOMLIB_IOS
 * \param[in]	config		初期化用コンフィグ構造体
 * \param[in]	work		ワーク領域
 * \param[in]	work_size	ワーク領域サイズ
 * \par 説明:
 * ライブラリを初期化します。<br>
 * ライブラリの機能を利用するには、必ずこの関数を実行する必要があります。<br>
 * （ライブラリの機能は、本関数を実行後、 ::criAtomEx_Finalize_IOS 関数を実行するまでの間、
 * 利用可能です。）<br>
 * <br>
 * ライブラリを初期化する際には、ライブラリが内部で利用するためのメモリ領域（ワーク領域）
 * を確保する必要があります。<br>
 * ライブラリが必要とするワーク領域のサイズは、初期化用コンフィグ構造体の内容に応じて
 * 変化します。<br>
 * ワーク領域サイズの計算には、 ::criAtomEx_CalculateWorkSize_IOS 
 * 関数を使用してください。<br>
 * \par 備考:
 * ::criAtomEx_SetUserAllocator マクロを使用してアロケータを登録済みの場合、
 * 本関数にワーク領域を指定する必要はありません。<br>
 * （ work に NULL 、 work_size に 0 を指定することで、登録済みのアロケータ
 * から必要なワーク領域サイズ分のメモリが動的に確保されます。）
 * <br>
 * 引数 config の情報は、関数内でのみ参照されます。<br>
 * 関数を抜けた後は参照されませんので、関数実行後に config の領域を解放しても
 * 問題ありません。
 * \attention
 * 本関数は内部的に以下の関数を実行します。<br>
 * 	- ::criAtomEx_Initialize
 * 	- ::criAtomExAsr_Initialize
 * 	- ::criAtomExHcaMx_Initialize
 * 	.
 * 本関数を実行する場合、上記関数を実行しないでください。<br>
 * <br>
 * 本関数を実行後、必ず対になる ::criAtomEx_Finalize_IOS 関数を実行してください。<br>
 * また、 ::criAtomEx_Finalize_IOS 関数を実行するまでは、本関数を再度実行しないでください。<br>
 * \sa CriAtomExConfig_IOS, criAtomEx_Finalize_IOS,
 * criAtomEx_SetUserAllocator, criAtomEx_CalculateWorkSize_IOS
 */
void CRIAPI criAtomEx_Initialize_IOS(
	const CriAtomExConfig_IOS *config, void *work, CriSint32 work_size);

/*JP
 * \brief ライブラリの終了
 * \ingroup ATOMLIB_IOS
 * \par 説明:
 * ライブラリを終了します。<br>
 * \attention
 * 本関数は内部的に以下の関数を実行します。<br>
 * 	- ::criAtomEx_Finalize
 * 	- ::criAtomExAsr_Finalize
 * 	- ::criAtomExHcaMx_Finalize
 * 	.
 * 本関数を実行する場合、上記関数を実行しないでください。<br>
 * <br>
 * ::criAtomEx_Initialize_IOS 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtomEx_Initialize_IOS
 */
void CRIAPI criAtomEx_Finalize_IOS(void);

/*JP
 * \brief サーバスレッドプライオリティの設定
 * \ingroup ATOMLIB_IOS
 * \param[in]	prio	スレッドのプライオリティ
 * \par 説明:
 * CRIサーバスレッドのプライオリティを設定します。<br>
 * 引数 prio は pthread のプライオリティ設定値として使用します。<br>
 * プライオリティ設定値はメインスレッドからの相対値になります。<br>
 * アプリケーションのメインスレッド(0)よりも高いプライオリティを指定してください。<br>
 * プライオリティのデフォルト値は16です。<br>
 * \attention
 * ::criAtomEx_Initialize_IOS 関数実行前に本関数を実行することはできません。<br>
 * <br>
 * サーバ処理スレッドは、CRI File Systemライブラリでも利用されています。<br>
 * すでにCRI File SystemライブラリのAPIでサーバ処理スレッドの設定を変更している場合
 * 本関数により設定が上書きされますのでご注意ください。<br>
 */
void CRIAPI criAtomEx_SetServerThreadPriority_IOS(int prio);

/*JP
 * \brief サウンド処理の再開
 * \ingroup ATOMLIB_IOS
 * \par 説明:
 * AudioSessionのInterruption Callbak関数から呼び出すための関数です。<br>
 * サウンド処理を再開します。<br>
 * 本関数を呼び出す前に、AudioSessionのパメラータ設定とアクティベイトを行ってください。<br>
 * \par 例:
 * \code
 * // AudioSession Interruption Callbak
 * static void interruptionListenerCallback(void *inUserData, UInt32 interruptionState)
 * {
 * 	if (interruptionState == kAudioSessionBeginInterruption) {
 * 		// オーディオ処理の停止
 * 		criAtomEx_StopSound_IOS();
 * 	}
 * 	if (interruptionState == kAudioSessionEndInterruption) {
 * 		// AudioSessionのプロパティ設定とアクティベイト
 * 		setupAudioSession();
 * 		// オーディオ処理の開始
 * 		criAtomEx_StartSound_IOS();
 * 	}
 * }
 * // AudioSessionのプロパティ設定とアクティベイト
 * static void setupAudioSession(void)
 * {
 * 		:
 * }
 * \endcode
 * \attention
 * ::criAtomEx_Initialize_IOS 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtomEx_StopSound_IOS
 */
void CRIAPI criAtomEx_StartSound_IOS(void);

/*JP
 * \brief サウンド処理の停止
 * \ingroup ATOMLIB_IOS
 * \par 説明:
 * AudioSessionのInterruption Callbak関数から呼び出すための関数です。<br>
 * サウンド処理を停止します。<br>
 * \attention
 * ::criAtomEx_Initialize_IOS 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtomEx_StartSound_IOS
 */
void CRIAPI criAtomEx_StopSound_IOS(void);

/*JP
 * \brief サウンドの復旧
 * \ingroup ATOMLIB_IOS
 * \par 説明:
 * AudioSessionAddPropertyListener Callback関数から呼び出すための関数です。<br>
 * ライブラリ内部のボイスを復旧します。<br>
 * iOSのデーモンであるmediaserverdが死亡した際には、ライブラリ内のボイスが無効なボイスになり、
 * 再生成が必要になります。<br>
 * このように、ボイスの復旧が必要な際に呼び出してください。<br>
 */
void CRIAPI criAtomEx_RecoverSound_IOS(void);

#ifdef __cplusplus
}
#endif

#endif	/* CRI_INCL_CRI_LE_ATOM_PC_H */

/* --- end of file --- */