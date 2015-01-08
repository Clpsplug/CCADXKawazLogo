/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2014 CRI Middleware Co., Ltd.
 *
 * Library  : CRI File System
 * Module   : Library User's Header for Android
 * File     : cri_le_file_system_android.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_le_file_system_android.h
 */

/* 多重定義防止					*/
/* Prevention of redefinition	*/
#ifndef	CRI_LE_FILE_SYSTEM_ANDROID_H_INCLUDED
#define	CRI_LE_FILE_SYSTEM_ANDROID_H_INCLUDED

/***************************************************************************
 *      インクルードファイル
 *      Include files
 ***************************************************************************/
#include "cri_le_xpt.h"
#include "cri_le_error.h"
#include "cri_le_file_system.h"
#include <jni.h>

/***************************************************************************
 *      定数マクロ
 *      Macro Constants
 ***************************************************************************/

/***************************************************************************
 *      処理マクロ
 *      Macro Functions
 ***************************************************************************/

/***************************************************************************
 *      データ型宣言
 *      Data Type Declarations
 ***************************************************************************/

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
 * \brief Androidプロジェクト内のassetsフォルダに対するアクセスの有効化
 * \ingroup FSLIB_CRIFS_ANDROID
 * \param[out]	vm		JavaVMオブジェクトへの参照
 * \param[in]	jobj	android.content.Contextオブジェクト
 * \return	CriError	エラーコード
 * \par 説明:
 * assetフォルダへのアクセスを有効化します。<br>
 * <br>
 * 本関数は、assetsフォルダへのアクセスを有効化します。<br>
 * ::criFs_SetJavaVM_ANDROIDと::criFs_SetContext_ANDROIDの処理を、１つにまとめた関数に相当します。<br>
 * 本関数の引数として渡されたJavaVMオブジェクトへの参照(vm)と、android.content.Contextオブジェクト(jobj)は<br>
 * CriFileSystemライブラリに登録されます。<br>
 * \attention:
 * 本関数の誤使用は、期待しない動作につながります。以下の点に注意して下さい。<br>
 * (1) 本関数を呼び出す前に、CRI File Systemライブラリの初期化が完了済みである事を確認して下さい。<br>
 * (2) assetsフォルダへのアクセス前に、本関数を呼び出して下さい。<br>
 * (3) 登録したContextオブジェクトは、Java VMのガベージコレクション対象から外れます。<br>
 *     登録を解除するには、::criFs_DisableAssetsAccess_ANDROID関数を呼び出してください。<br>
 *     または、新たなContextオブジェクトを登録し直すことでも、古いContextの登録解除が可能です。
 */
CriError CRIAPI criFs_EnableAssetsAccess_ANDROID(JavaVM* vm, jobject jobj);

/*JP
 * \brief Androidプロジェクト内のassetsフォルダに対するアクセスの無効化
 * \ingroup FSLIB_CRIFS_ANDROID
 * \return	CriError	エラーコード
 * \par 説明:
 * assetフォルダへのアクセスを無効化します。<br>
 * <br>
 * 本関数は、::criFs_SetContext_ANDROID関数にNULL引数を渡した場合と同様に動作します。
 */
CriError CRIAPI criFs_DisableAssetsAccess_ANDROID();


#ifdef __cplusplus
}
#endif

#endif	/* CRI_LE_FILE_SYSTEM_ANDROID_H_INCLUDED */


/* --- end of file --- */
