/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2010-2013 CRI Middleware Co., Ltd.
 *
 * Library  : CRI Atom
 * Module   : Library User's Header for Mac OS X
 * File     : cri_le_atom_macosx.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_le_atom_macosx.h
 */

/* 多重定義防止					*/
/* Prevention of redefinition	*/
#ifndef	CRI_INCL_CRI_LE_ATOM_MACOSX_H
#define	CRI_INCL_CRI_LE_ATOM_MACOSX_H

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

/***************************************************************************
 *      処理マクロ
 *      Macro Functions
 ***************************************************************************/
/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ライブラリ初期化用コンフィグ構造体にデフォルト値をセット
 * \ingroup ATOMLIB_MACOSX
 * \param[out]	p_config	初期化用コンフィグ構造体へのポインタ
 * \par 説明:
 * ::criAtomEx_Initialize_MACOSX 関数に設定するコンフィグ構造体
 * （ ::CriAtomExConfig_MACOSX ）に、デフォルトの値をセットします。<br>
 * \sa CriAtomExConfig_MACOSX
 */
#define criAtomEx_SetDefaultConfig_MACOSX(p_config)			\
{															\
	criAtomEx_SetDefaultConfig(&(p_config)->atom_ex);		\
	criAtomExAsr_SetDefaultConfig(&(p_config)->asr);		\
	criAtomExHcaMx_SetDefaultConfig(&(p_config)->hca_mx);	\
}

/***************************************************************************
 *      データ型宣言
 *      Data Type Declarations
 ***************************************************************************/
/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief Atomライブラリ初期化用コンフィグ構造体
 * \ingroup ATOMLIB_MACOSX
 * CRI Atomライブラリの動作仕様を指定するための構造体です。<br>
 * ::criAtomEx_Initialize_MACOSX 関数の引数に指定します。<br>
 * \sa criAtomEx_Initialize_MACOSX, criAtomEx_SetDefaultConfig_MACOSX
 */
typedef struct {
	CriAtomExConfig			atom_ex;	/* AtomEx初期化用コンフィグ構造体	*/
	CriAtomExAsrConfig		asr;		/* ASR初期化用コンフィグ			*/
	CriAtomExHcaMxConfig	hca_mx;		/* HCA-MX初期化用コンフィグ構造体	*/
} CriAtomExConfig_MACOSX;

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
void CRIAPI criAtom_SetServerThreadPriority_MACOSX(int prio);

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ライブラリ初期化用ワーク領域サイズの計算
 * \ingroup ATOMLIB_MACOSX
 * \param[in]	config		初期化用コンフィグ構造体
 * \return		CriSint32	ワーク領域サイズ
 * \par 説明:
 * ライブラリを使用するために必要な、ワーク領域のサイズを取得します。<br>
 * \par 備考:
 * ライブラリが必要とするワーク領域のサイズは、ライブラリ初期化用コンフィグ
 * 構造体（ ::CriAtomExConfig_MACOSX ）の内容によって変化します。<br>
 * <br>
 * 引数 config の情報は、関数内でのみ参照されます。<br>
 * 関数を抜けた後は参照されませんので、関数実行後に config の領域を解放しても
 * 問題ありません。
 * \sa CriAtomExConfig_MACOSX, criAtomEx_Initialize_MACOSX
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSize_MACOSX(const CriAtomExConfig_MACOSX *config);

/*JP
 * \brief ライブラリの初期化
 * \ingroup ATOMLIB_MACOSX
 * \param[in]	config		初期化用コンフィグ構造体
 * \param[in]	work		ワーク領域
 * \param[in]	work_size	ワーク領域サイズ
 * \par 説明:
 * ライブラリを初期化します。<br>
 * ライブラリの機能を利用するには、必ずこの関数を実行する必要があります。<br>
 * （ライブラリの機能は、本関数を実行後、 ::criAtomEx_Finalize_MACOSX 関数を実行するまでの間、
 * 利用可能です。）<br>
 * <br>
 * ライブラリを初期化する際には、ライブラリが内部で利用するためのメモリ領域（ワーク領域）
 * を確保する必要があります。<br>
 * ライブラリが必要とするワーク領域のサイズは、初期化用コンフィグ構造体の内容に応じて
 * 変化します。<br>
 * ワーク領域サイズの計算には、 ::criAtom_CalculateWorkSize_MACOSX 
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
 * 本関数を実行後、必ず対になる ::criAtomEx_Finalize_MACOSX 関数を実行してください。<br>
 * また、 ::criAtomEx_Finalize_MACOSX 関数を実行するまでは、本関数を再度実行しないでください。<br>
 * \sa CriAtomExConfig_MACOSX, criAtomEx_Finalize_MACOSX,
 * criAtomEx_SetUserAllocator, criAtomEx_CalculateWorkSize_MACOSX
 */
void CRIAPI criAtomEx_Initialize_MACOSX(
	const CriAtomExConfig_MACOSX *config, void *work, CriSint32 work_size);

/*JP
 * \brief ライブラリの終了
 * \ingroup ATOMLIB_MACOSX
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
 * ::criAtomEx_Initialize_MACOSX 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtomEx_Initialize_MACOSX
 */
void CRIAPI criAtomEx_Finalize_MACOSX(void);

/*JP
 * \brief サーバスレッドプライオリティの設定
 * \ingroup ATOMLIB_MACOSX
 * \param[in]	prio	スレッドのプライオリティ
 * \par 説明:
 * CRIサーバスレッドのプライオリティを設定します。<br>
 * 引数 prio は pthread のプライオリティ設定値として使用します。<br>
 * 指定できる値の範囲は通常 -16〜99で、数字が大きい方が優先度が高くなります。<br>
 * アプリケーションのメインスレッド(0)よりも高いプライオリティを指定してください。<br>
 * プライオリティのデフォルト値は10です。<br>
 * \attention
 * ::criAtomEx_Initialize_MACOSX 関数実行前に本関数を実行することはできません。<br>
 * <br>
 * サーバ処理スレッドは、CRI File Systemライブラリでも利用されています。<br>
 * すでにCRI File SystemライブラリのAPIでサーバ処理スレッドの設定を変更している場合
 * 本関数により設定が上書きされますのでご注意ください。<br>
 */
void CRIAPI criAtomEx_SetServerThreadPriority_MACOSX(int prio);

#ifdef __cplusplus
}
#endif

#endif	/* CRI_INCL_CRI_LE_ATOM_MACOSX_H */

/* --- end of file --- */
