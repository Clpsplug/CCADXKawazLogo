/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2010-2013 CRI Middleware Co., Ltd.
 *
 * Library  : CRI Atom
 * Module   : Library User's Header for PC
 * File     : cri_le_atom_pc.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_le_atom_pc.h
 */

/* 多重定義防止					*/
/* Prevention of redefinition	*/
#ifndef	CRI_INCL_CRI_LE_ATOM_PC_H
#define	CRI_INCL_CRI_LE_ATOM_PC_H

/***************************************************************************
 *      インクルードファイル
 *      Include files
 ***************************************************************************/
#include <windows.h>
#include <cri_le_xpt.h>
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
 * \ingroup ATOMLIB_PC
 * \param[out]	p_config	初期化用コンフィグ構造体へのポインタ
 * \par 説明:
 * ::criAtomEx_Initialize_PC 関数に設定するコンフィグ構造体
 * （ ::CriAtomExConfig_PC ）に、デフォルトの値をセットします。<br>
 * \sa CriAtomExConfig_PC
 */
#define criAtomEx_SetDefaultConfig_PC(p_config)				\
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
 * \ingroup ATOMLIB_PC
 * CRI Atomライブラリの動作仕様を指定するための構造体です。<br>
 * ::criAtomEx_Initialize_PC 関数の引数に指定します。<br>
 * \sa criAtomEx_Initialize_PC, criAtomEx_SetDefaultConfig_PC
 */
typedef struct CriAtomExConfigTag_PC{
	CriAtomExConfig			atom_ex;	/*JP< AtomEx初期化用コンフィグ構造体	*/
	CriAtomExAsrConfig		asr;		/*JP< ASR初期化用コンフィグ			*/
	CriAtomExHcaMxConfig	hca_mx;		/*JP< HCA-MX初期化用コンフィグ構造体	*/
} CriAtomExConfig_PC;

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
void CRIAPI criAtom_SetThreadPriority_PC(int prio);
int CRIAPI criAtom_GetThreadPriority_PC(void);
void CRIAPI criAtom_SetThreadAffinityMask_PC(DWORD_PTR mask);
DWORD_PTR CRIAPI criAtom_GetThreadAffinityMask_PC(void);

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ライブラリ初期化用ワーク領域サイズの計算
 * \ingroup ATOMLIB_PC
 * \param[in]	config		初期化用コンフィグ構造体
 * \return		CriSint32	ワーク領域サイズ
 * \retval		0以上		正常に処理が完了
 * \retval		-1			エラーが発生
 * \par 説明:
 * ライブラリを使用するために必要な、ワーク領域のサイズを取得します。<br>
 * <br>
 * ワーク領域サイズの計算に失敗すると、本関数は -1 を返します。<br>
 * ワーク領域サイズの計算に失敗した理由については、エラーコールバックのメッセージで確認可能です。<br>
 * \par 備考:
 * ライブラリが必要とするワーク領域のサイズは、ライブラリ初期化用コンフィグ
 * 構造体（ ::CriAtomExConfig_PC ）の内容によって変化します。<br>
 * <br>
 * 引数にNULLを指定した場合、デフォルト設定
 * （ ::criAtomEx_SetDefaultConfig_PC 適用時と同じパラメータ）で
 * ワーク領域サイズを計算します。
 * <br>
 * 引数 config の情報は、関数内でのみ参照されます。<br>
 * 関数を抜けた後は参照されませんので、関数実行後に config の領域を解放しても
 * 問題ありません。
 * \sa CriAtomExConfig_PC, criAtomEx_Initialize_PC
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSize_PC(const CriAtomExConfig_PC *config);

/*JP
 * \brief ライブラリの初期化
 * \ingroup ATOMLIB_PC
 * \param[in]	config		初期化用コンフィグ構造体
 * \param[in]	work		ワーク領域
 * \param[in]	work_size	ワーク領域サイズ
 * \par 説明:
 * ライブラリを初期化します。<br>
 * ライブラリの機能を利用するには、必ずこの関数を実行する必要があります。<br>
 * （ライブラリの機能は、本関数を実行後、 ::criAtomEx_Finalize_PC 関数を実行するまでの間、
 * 利用可能です。）<br>
 * <br>
 * ライブラリを初期化する際には、ライブラリが内部で利用するためのメモリ領域（ワーク領域）
 * を確保する必要があります。<br>
 * ワーク領域を確保する方法には、以下の2通りの方法があります。<br>
 * <b>(a) User Allocator方式</b>：メモリの確保／解放に、ユーザが用意した関数を使用する方法。<br>
 * <b>(b) Fixed Memory方式</b>：必要なメモリ領域を直接ライブラリに渡す方法。<br>
 * <br>
 * User Allocator方式を用いる場合、ユーザはライブラリにメモリ確保関数を登録しておきます。<br>
 * workにNULL、work_sizeに0を指定して本関数を呼び出すことで、
 * ライブラリは登録済みのメモリ確保関数を使用して必要なメモリを自動的に確保します。<br>
 * ユーザがワーク領域を用意する必要はありません。<br>
 * 初期化時に確保されたメモリは、終了処理時（ ::criAtomEx_Finalize_PC 関数実行時）に解放されます。<br>
 * <br>
 * Fixed Memory方式を用いる場合、ワーク領域として別途確保済みのメモリ領域を本関数に
 * 設定する必要があります。<br>
 * ワーク領域のサイズは ::criAtomEx_CalculateWorkSize_PC 関数で取得可能です。<br>
 * 初期化処理の前に ::criAtomEx_CalculateWorkSize_PC 関数で取得したサイズ分のメモリを予め
 * 確保しておき、本関数に設定してください。<br>
 * 尚、Fixed Memory方式を用いた場合、ワーク領域はライブラリの終了処理（ ::criAtomEx_Finalize_PC 関数）
 * を行なうまでの間、ライブラリ内で利用され続けます。<br>
 * ライブラリの終了処理を行なう前に、ワーク領域のメモリを解放しないでください。<br>
 * \par 例:
 * 【User Allocator方式によるライブラリの初期化】<br>
 * User Allocator方式を用いる場合、ライブラリの初期化／終了の手順は以下の以下の通りです。<br>
 * 	-# 初期化処理実行前に、 ::criAtomEx_SetUserAllocator 関数を用いてメモリ確保／解放関数を登録する。<br>
 * 	-# 初期化用コンフィグ構造体にパラメータをセットする。<br>
 * 	-# ::criAtomEx_Initialize_PC 関数で初期化処理を行う。<br>
 * （workにはNULL、work_sizeには0を指定する。）<br>
 * 	-# アプリケーション終了時に ::criAtomEx_Finalize_PC 関数で終了処理を行なう。<br>
 * 	.
 * <br>具体的なコードは以下のとおりです。<br>
 * \code
 * // 独自のメモリ確保関数
 * void *user_malloc(void *obj, CriUint32 size)
 * {
 * 	void *mem;
 * 	
 * 	// メモリの確保
 * 	mem = malloc(size);
 * 	
 * 	return (mem);
 * }
 * 
 * // 独自のメモリ解放関数を用意
 * void user_free(void *obj, void *mem)
 * {
 * 	// メモリの解放
 * 	free(mem);
 * 	
 * 	return;
 * }
 * 
 * main()
 * {
 * 	CriAtomExConfig_PC config;	// ライブラリ初期化用コンフィグ構造体
 * 		:
 * 	// 独自のメモリアロケータを登録
 * 	criAtomEx_SetUserAllocator(user_malloc, user_free, NULL);
 * 	
 * 	// ライブラリ初期化用コンフィグ構造体にデフォルト値をセット
 * 	criAtomEx_SetDefaultConfig_PC(&config);
 * 	
 * 	// ライブラリの初期化
 * 	// ワーク領域にはNULLと0を指定する。
 * 	// →必要なメモリは、登録したメモリ確保関数を使って確保される。
 * 	criAtomEx_Initialize_PC(&config, NULL, 0);
 * 		:
 * 	// アプリケーションのメイン処理
 * 		:
 * 	// アプリケーションを終了する際に終了処理を行う
 * 	// →初期化時に確保されたメモリは、登録したメモリ解放関数を使って解放される。
 * 	criAtomEx_Finalize_PC();
 * 		:
 * }
 * \endcode
 * <br>
 * 【Fixed Memory方式によるライブラリの初期化】<br>
 * Fixed Memory方式を用いる場合、ライブラリの初期化／終了の手順は以下の以下の通りです。<br>
 * 	-# 初期化用コンフィグ構造体にパラメータをセットする。<br>
 * 	-# ライブラリの初期化に必要なワーク領域のサイズを、 ::criAtomEx_CalculateWorkSize_PC 
 * 関数を使って計算する。<br>
 * 	-# ワーク領域サイズ分のメモリを確保する。<br>
 * 	-# ::criAtomEx_Initialize_PC 関数で初期化処理を行う。<br>
 * （workには確保したメモリのアドレスを、work_sizeにはワーク領域のサイズを指定する。）<br>
 * 	-# アプリケーション終了時に ::criAtomEx_Finalize_PC 関数で終了処理を行なう。<br>
 * 	-# ワーク領域のメモリを解放する。<br>
 * 	.
 * <br>具体的なコードは以下のとおりです。<br>
 * \code
 * main()
 * {
 * 	CriAtomExConfig_PC config;	// ライブラリ初期化用コンフィグ構造体
 * 	void *work;					// ワーク領域アドレス
 * 	CriSint32 work_size;		// ワーク領域サイズ
 * 		:
 * 	// ライブラリ初期化用コンフィグ構造体にデフォルト値をセット
 * 	criAtomEx_SetDefaultConfig_PC(&config);
 * 	
 * 	// ライブラリの初期化に必要なワーク領域のサイズを計算
 * 	work_size = criAtomEx_CalculateWorkSize_PC(&config);
 * 	
 * 	// ワーク領域用にメモリを確保
 * 	work = malloc((size_t)work_size);
 * 	
 * 	// ライブラリの初期化
 * 	// →確保済みのワーク領域を指定する。
 * 	criAtomEx_Initialize_PC(&config, NULL, 0);
 * 		:
 * 	// アプリケーションのメイン処理
 * 	// →この間、確保したメモリは保持し続ける。
 * 		:
 * 	// アプリケーションを終了する際に終了処理を行う
 * 	criAtomEx_Finalize_PC();
 * 	
 * 	// 必要なくなったワーク領域を解放する
 * 	free(work);
 * 		:
 * }
 * \endcode
 * \par 備考:
 * ライブラリが必要とするワーク領域のサイズは、初期化用コンフィグ構造体の内容に応じて
 * 変化します。<br>
 * また、必要なワーク領域のサイズは、プラットフォームによっても異なります。
 * <br>
 * 引数 config の情報は、関数内でのみ参照されます。<br>
 * 関数を抜けた後は参照されませんので、関数実行後に config の領域を解放しても
 * 問題ありません。
 * \attention
 * 現状、ストリーム再生を行うかどうかに関係なく、 Atom ライブラリは必ず 
 * CRI File System ライブラリの機能を使用します。<br>
 * そのため、CRI File Systemライブラリの初期化が行われていない場合、
 * Atom ライブラリは初期化処理時に内部で CRI File System ライブラリの初期化を行います。<br>
 * <br>
 * Atom ライブラリが内部で CRI File System ライブラリを初期化する場合、
 * CRI File System の初期化パラメータとして、 ::CriAtomExConfig 構造体の
 * fs_config パラメータを使用します。<br>
 * fs_config が NULL の場合、 Atom ライブラリはデフォルトパラメータ（ 
 * ::criFs_SetDefaultConfig マクロの設定値）で CRI File System ライブラリを初期化します。<br>
 * <br>
 * 尚、本関数を実行する時点で、既に CRI File System ライブラリが初期化済みである場合、
 * 本関数内では CRI File System ライブラリの初期化は行われません。<br>
 * <br>
 * 本関数は完了復帰型の関数です。<br>
 * 本関数を実行すると、しばらくの間Atomライブラリのサーバ処理がブロックされます。<br>
 * 音声再生中に本関数を実行すると、音途切れ等の不具合が発生する可能性があるため、
 * 本関数の呼び出しはシーンの切り替わり等、負荷変動を許容できるタイミングで行ってください。
 * <br>
 * 本関数を実行後、必ず対になる ::criAtomEx_Finalize_PC 関数を実行してください。<br>
 * また、 ::criAtomEx_Finalize_PC 関数を実行するまでは、本関数を再度実行しないでください。<br>
 * \sa CriAtomExConfig_PC, criAtomEx_Finalize_PC,
 * criAtomEx_SetUserAllocator, criAtomEx_CalculateWorkSize_PC
 */
void CRIAPI criAtomEx_Initialize_PC(
	const CriAtomExConfig_PC *config, void *work, CriSint32 work_size);

/*JP
 * \brief ライブラリの終了
 * \ingroup ATOMLIB_PC
 * \par 説明:
 * ライブラリを終了します。<br>
 * \attention
 * 本関数は完了復帰型の関数です。<br>
 * 本関数を実行すると、しばらくの間Atomライブラリのサーバ処理がブロックされます。<br>
 * 音声再生中に本関数を実行すると、音途切れ等の不具合が発生する可能性があるため、
 * 本関数の呼び出しはシーンの切り替わり等、負荷変動を許容できるタイミングで行ってください。
 * <br>
 * ::criAtomEx_Initialize_PC 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtomEx_Initialize_PC
 */
void CRIAPI criAtomEx_Finalize_PC(void);

/*JP
 * \brief サーバ処理スレッドのプライオリティ変更
 * \ingroup ATOMLIB_PC
 * \param[in]	prio	スレッドプライオリティ
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのプライオリティを変更します。<br>
 * デフォルト状態（本関数を実行しない場合）では、サーバ処理スレッドのプライオリティは
 * THREAD_PRIORITY_HIGHEST に設定されます。<br>
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
 * \sa criAtomEx_Initialize_PC, criAtomEx_GetThreadPriority_PC
 */
#define criAtomEx_SetThreadPriority_PC(prio)	\
	criAtom_SetThreadPriority_PC(prio)

/*JP
 * \brief サーバ処理スレッドのプライオリティ取得
 * \ingroup ATOMLIB_PC
 * \return	int		スレッドプライオリティ
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのプライオリティを取得します。<br>
 * 取得に成功すると、本関数はサーバ処理を行うスレッドのプライオリティを返します。<br>
 * 取得に失敗した場合、本関数は THREAD_PRIORITY_ERROR_RETURN を返します。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * \sa criAtomEx_Initialize_PC, criAtomEx_SetThreadPriority_PC
 */
#define criAtomEx_GetThreadPriority_PC()	\
	criAtom_GetThreadPriority_PC()

/*JP
 * \brief サーバ処理スレッドのアフィニティマスク変更
 * \ingroup ATOMLIB_PC
 * \param[in]	mask	スレッドアフィニティマスク
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのアフィニティマスクを変更します。<br>
 * デフォルト状態（本関数を実行しない場合）では、サーバ処理が動作するプロセッサは
 * 一切制限されません。<br>
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
 * \sa criAtomEx_Initialize_PC, criAtomEx_GetThreadAffinityMask_PC
 */
#define criAtomEx_SetThreadAffinityMask_PC(mask)	\
	criAtom_SetThreadAffinityMask_PC(mask)

/*JP
 * \brief サーバ処理スレッドのアフィニティマスクの取得
 * \ingroup ATOMLIB_PC
 * \return	DWORD_PTR	スレッドアフィニティマスク
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのアフィニティマスクを取得します。<br>
 * 取得に成功すると、本関数はサーバ処理を行うスレッドのアフィニティマスクを返します。<br>
 * 取得に失敗した場合、本関数は 0 を返します。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * \sa criAtomEx_Initialize_PC, criAtomEx_SetThreadAffinityMask_PC
 */
#define criAtomEx_GetThreadAffinityMask_PC()	\
	criAtom_GetThreadAffinityMask_PC()

#ifdef __cplusplus
}
#endif

#endif	/* CRI_INCL_CRI_LE_ATOM_PC_H */

/* --- end of file --- */
