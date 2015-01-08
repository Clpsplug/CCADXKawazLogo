/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2010-2013 CRI Middleware Co., Ltd.
 *
 * Library  : CRI AtomEx Monitor Library
 * Module   : Monitor Library C Interface Header
 * File     : cri_le_atom_ex_monitor.h
 *
 ****************************************************************************/
/*!
 *	\file	cri_le_atom_ex_monitor.h
 */

#ifndef CRI_INCL_CRI_LE_ATOM_EX_MONITOR_H
#define CRI_INCL_CRI_LE_ATOM_EX_MONITOR_H

/***************************************************************************
 *      インクルードファイル
 *      Include files
 ***************************************************************************/

#include <cri_le_xpt.h>

/***************************************************************************
 *      定数マクロ
 *      Macro Constants
 ***************************************************************************/
/* バージョン情報 */
/* Version Number */
#define CRIATOMEX_MONITOR_VERSION				(0x01070000)
#define CRIATOMEX_MONITOR_VER_NUM				"1.07.00"
#define CRIATOMEX_MONITOR_VER_NAME				"CRI AtomEx Monitor(LE)"
#define CRIATOMEX_MONITOR_VER_OPTION


/*JP
 * \brief デフォルトプレビューオブジェクト
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par 説明:
 * デフォルトのプレビューオブジェクト数です。<br>
 * \sa criAtomExMonitor_SetDefaultConfig
 */
#define CRIATOMX_MONITOR_DEFAULT_NUM_PUREVIEW_OBJECTS		(200)
/*JP
 * \brief デフォルト通信バッファサイズ
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par 説明:
 * デフォルトの通信バッファサイズです。<br>
 * \sa criAtomExMonitor_SetDefaultConfig
 */
#define CRIATOMX_MONITOR_DEFAULT_COMMUNICATION_BUFFER_SIZE	(2*1024*1024)
/*JP
 * \brief デフォルト再生位置情報更新間隔
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par 説明:
 * デフォルトの再生位置情報更新間隔です。<br>
 * \sa criAtomExMonitor_SetDefaultConfig
 */
#define CRIATOMX_MONITOR_DEFAULT_PLAYBACK_POSITION_UPDATE_INTERVAL	(8)

/*JP
 * \brief ログ取得モード
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par 説明:
 * ログ取得のモードです。<br>
 * \sa criAtomExMonitor_SetLogMode
 */
#define CRIATOMEX_MONITOR_LOG_MODE_OFF					(0)
#define CRIATOMEX_MONITOR_LOG_MODE_PLAYBACK				(1)			/* 再生制御関連 */
#define CRIATOMEX_MONITOR_LOG_MODE_ERROR				(1 << 1)	/* エラー関連 */
#define CRIATOMEX_MONITOR_LOG_MODE_LOW_LEVEL_PLAYBACK	(1 << 2)	/* 低レベル再生制御関連 */
#define CRIATOMEX_MONITOR_LOG_MODE_SYSTEM_INFORMATION	(1 << 3)	/* システム情報関連 */
#define CRIATOMEX_MONITOR_LOG_MODE_HANDLE_INFORMATION	(1 << 4)	/* システム情報関連 */
#define CRIATOMEX_MONITOR_LOG_MODE_CUE_LIMIT			(1 << 5)	/* キューリミット処理関連 */
#define CRIATOMEX_MONITOR_LOG_MODE_PROBABILITY			(1 << 6)	/* プロバビリティ処理関連 */
#define CRIATOMEX_MONITOR_LOG_MODE_CATEGORY				(1 << 7)	/* カテゴリ処理関連 */

#define CRIATOMEX_MONITOR_LOG_MODE_ALL					(0xFFFFFFFF)


/***************************************************************************
 *      処理マクロ
 *      Macro Functions
 ***************************************************************************/

#define criAtomExMonitor_SetDefaultConfig(p_config)	\
{\
	(p_config)->max_preivew_object = CRIATOMX_MONITOR_DEFAULT_NUM_PUREVIEW_OBJECTS;\
	(p_config)->communication_buffer_size = CRIATOMX_MONITOR_DEFAULT_COMMUNICATION_BUFFER_SIZE;\
	(p_config)->additional_buffer = 0;\
	(p_config)->additional_buffer_size = 0;\
	(p_config)->playback_position_update_interval = CRIATOMX_MONITOR_DEFAULT_PLAYBACK_POSITION_UPDATE_INTERVAL;\
}
 
/***************************************************************************
 *      データ型宣言
 *      Data Type Declarations
 ***************************************************************************/
typedef struct CriAtomExMonitorConfigTag {
	CriUint32	max_preivew_object;
	CriUint32	communication_buffer_size;
	CriUintPtr	additional_buffer;
	CriUint32	additional_buffer_size;
	/*JP
		\brief 再生位置情報更新間隔
		\par 説明:
		サーバ処理実行時に再生位置情報の送信処理を行う間隔を指定します。<br>
		playback_position_update_interval の値を変更することで、
		サーバ処理の実行回数を変えることなく再生位置情報の送信頻度を下げることが可能です。<br>
		<br>
		playback_position_update_interval には、再生位置情報の送信処理を何サーバごとに行うかを指定します。<br>
		例えば、 playback_position_update_interval を 2 に設定すると、
		サーバ処理 2 回に対し、 1 回だけ再生位置情報の送信が行われます。<br>
		（再生位置情報の送信頻度が 1/2 になります。）<br>
	*/
	CriSint32	playback_position_update_interval;
} CriAtomExMonitorConfig;

/*	Log Callback Function type	*/
typedef void (*CriAtomExMonitorLogCbFunc)(void* obj, const CriChar8 *log_string);

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

/*JP
 * \brief モニター機能初期化用ワーク領域サイズの計算
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \param[in]	config		初期化用コンフィグ構造体
 * \return		CriSint32	ワーク領域サイズ
 * \par 説明:
 * モニター機能を使用するために必要な、ワーク領域のサイズを取得します。<br>
 * <br>
 * ワーク領域サイズの計算に失敗すると、本関数は -1 を返します。<br>
 * ワーク領域サイズの計算に失敗した理由については、エラーコールバックのメッセージで確認可能です。<br>
 * \par 備考:
 * モニター機能が必要とするワーク領域のサイズは、モニター機能初期化用コンフィグ
 * 構造体（ ::CriAtomExMonitorConfig ）の内容によって変化します。<br>
 * <br>
 * 引数にNULLを指定した場合、デフォルト設定
 * （ ::criAtomExMonitor_SetDefaultConfig 適用時と同じパラメータ）で
 * ワーク領域サイズを計算します。
 * <br>
 * 引数 config の情報は、関数内でのみ参照されます。<br>
 * 関数を抜けた後は参照されませんので、関数実行後に config の領域を解放しても
 * 問題ありません。
 * \sa criAtomExMonitor_SetDefaultConfig, criAtomExMonitor_Initialize, CriAtomExMonitorConfig
 */
CriSint32 CRIAPI criAtomExMonitor_CalculateWorkSize(const CriAtomExMonitorConfig* config);

/*JP
 * \brief モニター機能の初期化
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \param[in]	config		初期化用コンフィグ構造体
 * \param[in]	work		ワーク領域
 * \param[in]	work_size	ワーク領域サイズ
 * \par 説明:
 * モニター機能を初期化します。<br>
 * モニター機能を利用するには、必ずこの関数を実行する必要があります。<br>
 * （モニター機能は、本関数を実行後、 ::criAtomExMonitor_Finalize 関数を実行するまでの間、
 * 利用可能です。）<br>
 * 本関数の呼び出しは、criAtomEx_Initialize 関数実行後 ::criAtomEx_Finalize 関数を実行するまでの間に
 * 行うようにしてください。<br>
 * \sa criAtomExMonitor_Finalize, CriAtomExMonitorConfig
 */
void CRIAPI criAtomExMonitor_Initialize(
	const CriAtomExMonitorConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief モニター機能の終了
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par 説明:
 * モニター機能を終了します。<br>
 * \attention
 * ::criAtomExMonitor_Initialize 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtomExMonitor_Initialize
 */
void CRIAPI criAtomExMonitor_Finalize(void);

/*JP
 * \brief サーバーIPアドレス文字列の取得
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par 説明:
 * サーバーIPアドレス文字列を取得します。<br>
 * \attention
 * ::criAtomExMonitor_Initialize 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtomExMonitor_Initialize, criAtomExMonitor_GetClientIpString
 */
const CriChar8* CRIAPI criAtomExMonitor_GetServerIpString(void);

/*JP
 * \brief クライアントIPアドレス文字列の取得
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par 説明:
 * クライアントIPアドレス文字列を取得します。<br>
 * \attention
 * ::criAtomExMonitor_Initialize 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtomExMonitor_Initialize, criAtomExMonitor_GetServerIpString
 */
const CriChar8* CRIAPI criAtomExMonitor_GetClientIpString(void);

/*JP
 * \brief ツール接続状態の取得
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \return		CriBool	接続状態（CRI_TRUE:接続、CRI_FALSE:未接続）
 * \par 説明:
 * ツール接続状態を取得します。<br>
 * \attention
 * ::criAtomExMonitor_Initialize 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtomExMonitor_Initialize
 */
CriBool CRIAPI criAtomExMonitor_IsConnected(void);

/*JP
 * \brief ログ取得コールバックの登録
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par 説明:
 * \param		cbf			コールバック関数
 * \param		obj			ユーザ指定オブジェクト
 * ログ取得用コールバック関数を登録します。<br>
 * 関数を登録するとログ取得を開始し、NULLを設定することでログ取得を停止します。<br>
 * 取得するログのモード切替は ::criAtomExMonito_SetLogMode 関数で設定指定ください。<br>
 * \attention
 * ::criAtomExMonitor_Initialize 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtomExMonitor_Initialize, criAtomExMonito_SetLogMode
 */
void CRIAPI criAtomExMonitor_SetLogCallback(CriAtomExMonitorLogCbFunc cbf, void* obj);

/*JP
 * \brief ログモードの設定
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par 説明:
 * ログ取得のモードを設定します。<br>
 * 本関数で設定したモードにしたがって ::criAtomExMonitor_SetLogCallback 関数で
 * 登録したログ取得用コールバック関数が呼び出されます。<br>
 * \sa criAtomExMonitor_SetLogCallback
 */
void CRIAPI criAtomExMonitor_SetLogMode(CriUint32 mode);

#ifdef __cplusplus
}
#endif

#endif // CRI_INCL_CRI_LE_ATOM_EX_MONITOR_H
