/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2014 CRI Middleware Co., Ltd.
 *
 * Library  : CRI Atom
 * Module   : Library User's Header for Android
 * File     : cri_le_atom_android.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_le_atom_android.h
 */

/* 多重定義防止					*/
/* Prevention of redefinition	*/
#ifndef	CRI_INCL_CRI_LE_ATOM_ANDROID_H
#define	CRI_INCL_CRI_LE_ATOM_ANDROID_H

/***************************************************************************
 *      インクルードファイル
 *      Include files
 ***************************************************************************/
#include <jni.h>
#include <cri_le_xpt.h>
#include <cri_le_error.h>
#include <cri_le_atom.h>
#include <cri_le_atom_ex.h>
#include <cri_le_atom_asr.h>


/***************************************************************************
 *      定数マクロ
 *      Macro Constants
 ***************************************************************************/
/*JP
 * \brief Stream Type ID
 * \ingroup ATOMLIB_Android
 * 音声出力先のストリームタイプを設定する値です。<br>
 */
typedef enum {
    CRIATOMANDROID_STREAM_TYPE_MUSIC,
    CRIATOMANDROID_STREAM_TYPE_ALARM,
    CRIATOMANDROID_STREAM_TYPE_DTMF ,
    CRIATOMANDROID_STREAM_TYPE_NOTIFICATION,
    CRIATOMANDROID_STREAM_TYPE_RING,
    CRIATOMANDROID_STREAM_TYPE_SYSTEM,
    CRIATOMANDROID_STREAM_TYPE_VOICE_CALL,
	CRIATOMANDROID_STREAM_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomAndroidStreamType;

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ライブラリ初期化用コンフィグ構造体にデフォルト値をセット
 * \ingroup ATOMLIB_Android
 * \param[out]	p_config	初期化用コンフィグ構造体へのポインタ
 * \par 説明:
 * ::criAtomEx_Initialize_ANDROID 関数に設定するコンフィグ構造体
 * （ ::CriAtomExConfig_ANDROID ）に、デフォルトの値をセットします。<br>
 * \sa CriAtomExConfig_ANDROID
 */
#define criAtomEx_SetDefaultConfig_ANDROID(p_config)		\
{															\
	(p_config)->initialize_hca_mx = CRI_TRUE;				\
	criAtomEx_SetDefaultConfig(&(p_config)->atom_ex);		\
	criAtomExAsr_SetDefaultConfig(&(p_config)->asr);		\
	criAtomExHcaMx_SetDefaultConfig(&(p_config)->hca_mx);	\
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
 * \ingroup ATOMLIB_Android
 * CRI Atomライブラリの動作仕様を指定するための構造体です。<br>
 * ::criAtomEx_Initialize_ANDROID 関数の引数に指定します。<br>
 * \sa criAtomEx_Initialize_ANDROID, criAtomEx_SetDefaultConfig_ANDROID
 */
typedef struct {
	CriBool					initialize_hca_mx;	/*JP< HCA-MXを初期化するかどうか		*/
	CriAtomExConfig			atom_ex;			/*JP< AtomEx初期化用コンフィグ構造体	*/
	CriAtomExAsrConfig		asr;				/*JP< ASR初期化用コンフィグ				*/
	CriAtomExHcaMxConfig	hca_mx;				/*JP< HCA-MX初期化用コンフィグ構造体	*/
} CriAtomExConfig_ANDROID;

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
 * \brief サーバ処理スレッドのプライオリティ変更
 * \ingroup ATOMLIB_Android
 * \param[in]	prio	スレッドプライオリティ
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのプライオリティを変更します。<br>
 * デフォルト状態（本関数を実行しない場合）では、サーバ処理スレッドのプライオリティは
 * -19(ナイス値) に設定されます。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数は何も処理を行いません。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行しても、効果はありません。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * サーバ処理スレッドは、CRI File Systemライブラリでも利用されています。<br>
 * すでにCRI File SystemライブラリのAPIでサーバ処理スレッドの設定を変更している場合
 * 本関数により設定が上書きされますのでご注意ください。<br>
 * \sa criAtom_Initialize_ANDROID, criAtom_GetThreadPriority_ANDROID
 */
void CRIAPI criAtom_SetThreadPriority_ANDROID(int prio);

/*JP
 * \brief サーバ処理スレッドのプライオリティ取得
 * \ingroup ATOMLIB_Android
 * \return	int		スレッドプライオリティ
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのプライオリティを取得します。<br>
 * 取得に成功すると、本関数はサーバ処理を行うスレッドのプライオリティ(ナイス値)を返します。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * \sa criAtom_Initialize_ANDROID, criAtom_SetThreadPriority_ANDROID
 */
int CRIAPI criAtom_GetThreadPriority_ANDROID(void);

/*JP
 * \brief JavaVMオブジェクトの設定
 * \ingroup ATOMLIB_Android
 * \return	JavaVM*		JavaVMオブジェクト
 * \par 説明:
 * JavaVMオブジェクトをAtomライブラリに登録します。<br>
 * Android OS 2.3より前のOSをサポートする場合は、本関数を必ず使用し、JavaVMオブジェクトを登録してください。<br>
 * Android OS 2.3以降のOSのみを対象とする場合は、本関数を呼び出さなくても動作します。<br>
 * \attention:
 * JavaVMオブジェクトを登録した場合、ライブラリ内部で作成したスレッドをJavaVMにアタッチします。<br>
 * 
 * <br>
 * 本関数はライブラリ初期化前に実行する必要があります。<br>
 * \sa criAtomEx_Initialize_ANDROID
 */
void CRIAPI criAtom_SetJavaVM_ANDROID(JavaVM* vm);

/*JP
 * \brief 音声出力先ストリームタイプの設定
 * \ingroup ATOMLIB_Android
 * \return	
 * \par 説明:
 * 音声出力先ストリームタイプを設定します。<br>
 * <br>
 * 本関数はライブラリ初期化前に実行する必要があります。<br>
 * \sa criAtomEx_Initialize_ANDROID
 */
void CRIAPI criAtom_SetOutputStreamType(CriAtomAndroidStreamType type);

/*JP
 * \brief 再生開始バッファリング時間の設定
 * \ingroup ATOMLIB_Android
 * \param[in]	time	再生開始バッファリング時間（ミリ秒単位）
 * \par 説明:
 * Atomライブラリ内で音声再生開始時にバッファリングする時間（ミリ秒単位）を指定します。<br>
 * 0 を指定した場合、デフォルトサイズでバッファリングします。<br>
 * 本関数の設定値はNSR（ネイティブサウンドレンダラ）モードでの再生開始レイテンシに影響します。<br>
 * （大きい値を設定してしまうとその分、再生開始レイテンシが大きくなることになります）<br>
 * \par 備考:
 * デフォルトでは3V相当の再生開始バッファリング時間を設定しています。
 * （サーバ周波数の設定が60[fps]：16.6[ms]の場合、3Vは約50[ms]の再生開始バッファリング時間になります）<br>
 * <br>
 * Android端末によっては再生開始バッファリング時間が少ないとノイズになってしまう場合があります。
 * その場合は本関数で調整することで改善する事があります。
 * \sa criAtom_SetSoundBufferingTime_ANDROID
 */
void CRIAPI criAtom_SetSoundStartBufferingTime_ANDROID(CriSint32 time);

/*JP
 * \brief サウンドデコードバッファ量の設定（ミリ秒単位）
 * \ingroup ATOMLIB_Android
 * \param[in]	time	サウンドデコードバッファ量（ミリ秒単位）
 * \par 説明:
 * Atomライブラリ内で音声再生で使用するデコードバッファ量（ミリ秒単位）を指定します。<br>
 * 0 を指定した場合、デフォルトサイズのサウンドデコードバッファ量を設定します。<br>
 * 本関数の設定値はASR（Atomサウンドレンダラ）モードでの再生開始レイテンシに影響します。<br>
 * （大きい値を設定してしまうとその分、再生開始レイテンシが大きくなることになります）<br>
 * \par 備考:
 * デフォルトでは4V相当のデコードバッファ量を設定します。
 * （サーバ周波数の設定が60[fps]：16.6[ms]の場合、4Vは約66[ms]のサウンドデコードバッファ量になります）<br>
 * <br>
 * Android端末によってはサウンドデコードバッファ量が少ないとノイズになってしまう場合があります。
 * その場合は本関数で調整することで改善する事があります。
 * \attention
 * 本関数は初期化よりも前に実行しておく必要があります。<br>
 * \sa criAtom_SetSoundStartBufferingTime_ANDROID
 */
void CRIAPI criAtom_SetSoundBufferingTime_ANDROID(CriSint32 time);

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ライブラリ初期化用ワーク領域サイズの計算
 * \ingroup ATOMLIB_Android
 * \param[in]	config		初期化用コンフィグ構造体
 * \return		CriSint32	ワーク領域サイズ
 * \par 説明:
 * ライブラリを使用するために必要な、ワーク領域のサイズを取得します。<br>
 * \par 備考:
 * ライブラリが必要とするワーク領域のサイズは、ライブラリ初期化用コンフィグ
 * 構造体（ ::CriAtomExConfig_ANDROID ）の内容によって変化します。<br>
 * <br>
 * 引数 config の情報は、関数内でのみ参照されます。<br>
 * 関数を抜けた後は参照されませんので、関数実行後に config の領域を解放しても
 * 問題ありません。
 * \sa CriAtomExConfig_ANDROID, criAtomEx_Initialize_ANDROID
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSize_ANDROID(const CriAtomExConfig_ANDROID *config);

/*JP
 * \brief ライブラリの初期化
 * \ingroup ATOMLIB_Android
 * \param[in]	config		初期化用コンフィグ構造体
 * \param[in]	work		ワーク領域
 * \param[in]	work_size	ワーク領域サイズ
 * \par 説明:
 * ライブラリを初期化します。<br>
 * ライブラリの機能を利用するには、必ずこの関数を実行する必要があります。<br>
 * （ライブラリの機能は、本関数を実行後、 ::criAtomEx_Finalize_ANDROID 関数を実行するまでの間、
 * 利用可能です。）<br>
 * <br>
 * ライブラリを初期化する際には、ライブラリが内部で利用するためのメモリ領域（ワーク領域）
 * を確保する必要があります。<br>
 * ライブラリが必要とするワーク領域のサイズは、初期化用コンフィグ構造体の内容に応じて
 * 変化します。<br>
 * ワーク領域サイズの計算には、 ::criAtomEx_CalculateWorkSize_ANDROID 
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
 * 本関数を実行後、必ず対になる ::criAtomEx_Finalize_ANDROID 関数を実行してください。<br>
 * また、 ::criAtomEx_Finalize_ANDROID 関数を実行するまでは、本関数を再度実行しないでください。<br>
 * \sa CriAtomExConfig_ANDROID, criAtomEx_Finalize_ANDROID,
 * criAtomEx_SetUserAllocator, criAtomEx_CalculateWorkSize_ANDROID
 */
void CRIAPI criAtomEx_Initialize_ANDROID(
	const CriAtomExConfig_ANDROID *config, void *work, CriSint32 work_size);

/*JP
 * \brief ライブラリの終了
 * \ingroup ATOMLIB_Android
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
 * ::criAtomEx_Initialize_ANDROID 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtomEx_Initialize_ANDROID
 */
void CRIAPI criAtomEx_Finalize_ANDROID(void);

/*JP
 * \brief サウンド処理の再開
 * \ingroup ATOMLIB_Android
 * \par 説明:
 * 本関数内ではAtomサーバスレッドのロック状態が解除されます。<br>
 * また、ASRの停止を解除します。<br>
 * 本関数の動作保証のため、呼び出しの前には必ずcriAtom_StopSound_ANDROID関数が<br>
 * 呼ばれることを確認してください。
 * \sa criAtomEx_StartSound_ANDROID
 */
void CRIAPI criAtomEx_StartSound_ANDROID(void);

/*JP
 * \brief サウンド処理の停止
 * \ingroup ATOMLIB_Android
 * \par 説明:
 * 本関数内ではAtomサーバスレッドをロック状態にします。<br>
 * また、ASRの処理を停止します。<br>
 * 本関数の動作保証のため、呼び出しの後には必ずcriAtom_StartSound_ANDROID関数が<br>
 * 呼ばれることを確認してください。
 * \sa criAtomEx_StopSound_ANDROID
 */
void CRIAPI criAtomEx_StopSound_ANDROID(void);
	
/*JP
 * \brief サーバ処理スレッドのプライオリティ変更
 * \ingroup ATOMLIB_Android
 * \param[in]	prio	スレッドプライオリティ
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのプライオリティを変更します。<br>
 * デフォルト状態（本関数を実行しない場合）では、サーバ処理スレッドのプライオリティは
 * -19(ナイス値) に設定されます。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数は何も処理を行いません。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行しても、効果はありません。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * サーバ処理スレッドは、CRI File Systemライブラリでも利用されています。<br>
 * すでにCRI File SystemライブラリのAPIでサーバ処理スレッドの設定を変更している場合
 * 本関数により設定が上書きされますのでご注意ください。<br>
 * \sa criAtomEx_Initialize_ANDROID, criAtomEx_GetThreadPriority_ANDROID
 */
#define criAtomEx_SetThreadPriority_ANDROID(prio)	\
	criAtom_SetThreadPriority_ANDROID(prio)

/*JP
 * \brief サーバ処理スレッドのプライオリティ取得
 * \ingroup ATOMLIB_Android
 * \return	int		スレッドプライオリティ
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのプライオリティを取得します。<br>
 * 取得に成功すると、本関数はサーバ処理を行うスレッドのプライオリティ(ナイス値)を返します。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * \sa criAtomEx_Initialize_ANDROID, criAtomEx_SetThreadPriority_ANDROID
 */
#define criAtomEx_GetThreadPriority_ANDROID()	\
	criAtom_GetThreadPriority_ANDROID()

/*JP
 * \brief JavaVMオブジェクトの設定
 * \ingroup ATOMLIB_Android
 * \return	JavaVM*		JavaVMオブジェクト
 * \par 説明:
 * JavaVMオブジェクトをAtomライブラリに登録します。<br>
 * Android OS 2.3より前のOSをサポートする場合は、本関数を必ず使用し、JavaVMオブジェクトを登録してください。<br>
 * Android OS 2.3以降のOSのみを対象とする場合は、本関数を呼び出さなくても動作します。<br>
 * \attention:
 * JavaVMオブジェクトを登録した場合、ライブラリ内部で作成したスレッドをJavaVMにアタッチします。<br>
 * 
 * <br>
 * 本関数はライブラリ初期化前に実行する必要があります。<br>
 * \sa criAtomEx_Initialize_ANDROID
 */
#define criAtomEx_SetJavaVM_ANDROID(vm)		\
	criAtom_SetJavaVM_ANDROID(vm)

/*JP
 * \brief 音声出力先ストリームタイプの設定
 * \ingroup ATOMLIB_Android
 * \return	JavaVM*		JavaVMオブジェクト
 * \par 説明:
 * 音声出力先ストリームタイプを設定します。<br>
 * <br>
 * 本関数はライブラリ初期化前に実行する必要があります。<br>
 * \sa criAtomEx_Initialize_ANDROID
 */
#define criAtomEx_SetOutputStreamType(type)		\
	criAtom_SetOutputStreamType(type)

#ifdef __cplusplus
}
#endif

#endif	/* CRI_INCL_CRI_LE_ATOM_ANDROID_H */

/* --- end of file --- */
