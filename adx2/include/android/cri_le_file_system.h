/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2006-2013 CRI Middleware Co., Ltd.
 *
 * Library  : CRI File System
 * Module   : Library User's Header
 * File     : cri_le_file_system.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_le_file_system.h
 */

/* 多重定義防止					*/
/* Prevention of redefinition	*/
#ifndef	CRI_INCL_CRI_LE_FILE_SYSTEM_H
#define	CRI_INCL_CRI_LE_FILE_SYSTEM_H

/***************************************************************************
 *      インクルードファイル
 *      Include files
 ***************************************************************************/
#include <cri_le_xpt.h>
#include <cri_le_error.h>

/***************************************************************************
 *      定数マクロ
 *      Macro Constants
 ***************************************************************************/
/* バージョン情報 */
/* Version Number */
#define CRI_FS_VERSION		(0x02660200)
#define CRI_FS_VER_NUM		"2.66.02"
#define CRI_FS_VER_NAME		"CRI File System(LE)"


#define	CRIFS_CONFIG_DEFAULT_THREAD_MODEL		CRIFS_THREAD_MODEL_MULTI
#define	CRIFS_CONFIG_DEFAULT_NUM_BINDERS		(16)
#define	CRIFS_CONFIG_DEFAULT_NUM_LOADERS		(16)
#define	CRIFS_CONFIG_DEFAULT_NUM_GROUP_LOADERS	(2)
#define	CRIFS_CONFIG_DEFAULT_NUM_STDIO_HANDLES	(16)
#define	CRIFS_CONFIG_DEFAULT_NUM_INSTALLERS		(0)
#define	CRIFS_CONFIG_DEFAULT_MAX_BINDS			(16)
#define	CRIFS_CONFIG_DEFAULT_MAX_FILES			(16)
#define	CRIFS_CONFIG_DEFAULT_MAX_PATH			(256)

/***************************************************************************
 *      処理マクロ
 *      Macro Functions
 ***************************************************************************/
/*JP
 * \brief デフォルトコンフィギュレーションのセット
 * \ingroup FSLIB_CRIFS
 * \param[in]	config	コンフィギュレーション
 * \par 説明:
 * ::criFs_InitializeLibrary 関数に設定するコンフィギュレーション（ ::CriFsConfig ）に、デフォルトの値をセットします。<br>
 * \par 補足:
 * コンフィギュレーションに設定する各パラメータを、アプリケーションで使用するハンドルの数に応じて調節することで、
 * ライブラリが必要とするメモリサイズを小さく抑えることが可能です。<br>
 * しかし、アプリケーション中で使用するハンドルの数が明確でない開発初期段階や、メモリサイズがタイトではないケースでは、
 * 本マクロを使用することによりで、初期化処理を簡略化することが可能です。<br>
 * \attention:
 * 本マクロでは、ほとんどのケースで必要充分な数のハンドルが確保できるよう、コンフィギュレーションの各パラメータに大きめの値をセットします。<br>
 * そのため、本マクロを使用した場合、ライブラリが必要とするワーク領域のサイズは大きくなりますので、ご注意ください。<br>
 * （メモリサイズがタイトなケースでは、本マクロでコンフィギュレーションを初期化した後、各パラメータを個別に調節することをオススメいたします。）<br>
 * \sa
 * CriFsConfig
*/
#define criFs_SetDefaultConfig(p_config)	\
{\
	(p_config)->thread_model		= CRIFS_CONFIG_DEFAULT_THREAD_MODEL;\
	(p_config)->num_binders			= CRIFS_CONFIG_DEFAULT_NUM_BINDERS;\
	(p_config)->num_loaders			= CRIFS_CONFIG_DEFAULT_NUM_LOADERS;\
	(p_config)->num_group_loaders	= CRIFS_CONFIG_DEFAULT_NUM_GROUP_LOADERS;\
	(p_config)->num_stdio_handles	= CRIFS_CONFIG_DEFAULT_NUM_STDIO_HANDLES;\
	(p_config)->num_installers		= CRIFS_CONFIG_DEFAULT_NUM_INSTALLERS;\
	(p_config)->max_binds			= CRIFS_CONFIG_DEFAULT_MAX_BINDS;\
	(p_config)->max_files			= CRIFS_CONFIG_DEFAULT_MAX_FILES;\
	(p_config)->max_path			= CRIFS_CONFIG_DEFAULT_MAX_PATH;\
	(p_config)->version				= CRI_FS_VERSION;\
}

/***************************************************************************
 *      データ型宣言
 *      Data Type Declarations
 ***************************************************************************/
/*==========================================================================
 *      CRI File System API
 *=========================================================================*/
/*JP
 * \brief スレッドモデル
 * \ingroup FSLIB_CRIFS
 * \par 説明:
 * CRI File Systemライブラリがどのようなスレッドモデルで動作するかを表します。<br>
 * ライブラリ初期化時（::criFs_InitializeLibrary関数）に、::CriFsConfig構造体にて指定します。
 * \sa CriFsConfig
 * \sa criFs_InitializeLibrary
 */
typedef enum CriFsThreadModelTag {
	/*JP
	 * \brief マルチスレッド
	 * \par 説明:
	 * ライブラリは内部でスレッドを作成し、マルチスレッドにて動作します。<br>
	 * スレッドは::criFs_InitializeLibrary関数呼び出し時に作成されます。
	 */
	/*EN Multi thread				*/
	CRIFS_THREAD_MODEL_MULTI = 0,

	/*JP
	 * \brief マルチスレッド（ユーザ駆動式）
	 * \par 説明:
	 * ライブラリは内部でスレッドを作成し、マルチスレッドにて動作します。<br>
	 * スレッドは ::criFs_InitializeLibrary 関数呼び出し時に作成されます。<br>
	 * サーバ処理自体は作成されたスレッド上で実行されますが、
	 * CRIFS_THREAD_MODEL_MULTI とは異なり、自動的には実行されません。<br>
	 * ユーザは ::criFs_ExecuteMain 関数で明示的にサーバ処理を駆動する必要があります。<br>
	 * （  ::criFs_ExecuteMain 関数を実行すると、スレッドが起動し、サーバ処理が実行されます。）<br>
	 */
	CRIFS_THREAD_MODEL_MULTI_USER_DRIVEN = 3,

	/*JP
	 * \brief ユーザマルチスレッド
	 * \par 説明:
	 * ライブラリ内部ではスレッドを作成しませんが、ユーザが独自に作成したスレッドからサーバ処理関数（::criFs_ExecuteFileAccess関数、::criFs_ExecuteDataDecompression関数）を呼び出せるよう、内部の排他制御は行います。
	 */
	/*EN User multi thread				*/
	CRIFS_THREAD_MODEL_USER_MULTI = 1,

	/*JP
	 * \brief シングルスレッド
	 * \par 説明:
	 * ライブラリ内部でスレッドを作成しません。また、内部の排他制御も行いません。<br>
	 * このモデルを選択した場合、各APIとサーバ処理関数（::criFs_ExecuteFileAccess関数、::criFs_ExecuteDataDecompression関数）とを同一スレッドから呼び出すようにしてください。
	 */
	/*EN Single thread				*/
	CRIFS_THREAD_MODEL_SINGLE = 2,

	/* enum be 4bytes */
	CRIFS_THREAD_MODEL_ENUM_BE_SINT32 = 0x7FFFFFFF
} CriFsThreadModel;

/*JP
 * \brief コンフィギュレーション
 * \ingroup FSLIB_CRIFS
 * \par 説明:
 * CRI File Systemライブラリの動作仕様を指定するための構造体です。<br>
 * ライブラリ初期化時（::criFs_InitializeLibrary関数）に引数として本構造体を指定します。<br>
 * \par
 * CRI File Systemライブラリは、初期化時に指定されたコンフィギュレーションに応じて、内部リソースを必要な数分だけ確保します。<br>
 * そのため、コンフィギュレーションに指定する値を小さくすることで、ライブラリが必要とするメモリのサイズを小さく抑えることが可能です。<br>
 * ただし、コンフィギュレーションに指定した数以上のハンドルを確保することはできなくなるため、値を小さくしすぎると、ハンドルの確保に失敗する可能性があります。<br>
 * \par 備考:
 * デフォルト設定を使用する場合、 ::criFs_SetDefaultConfig 関数でデフォルトパラメータをセットし、 ::criFs_InitializeLibrary 関数に指定してください。<br>
 * \attention
 * 将来的にメンバが増える可能性に備え、設定前に::criFs_SetDefaultConfig 関数で初期化してから使用してください。<br>
 * \sa criFs_InitializeLibrary, criFs_SetDefaultConfig
 */
typedef struct CriFsConfigTag {
	/*JP
		\brief スレッドモデル
		\par 説明:
		CRI File Systemのスレッドモデルを指定します。<br>
		\sa CriFsThreadModel
	*/
	CriFsThreadModel thread_model;

	/*JP
		\brief 使用するCriFsBinderの数
		\par 説明:
		アプリケーション中で使用するバインダ（CriFsBinder）の数を指定します。<br>
		アプリケーション中で ::criFsBinder_Create 関数を使用してバインダを作成する場合、
		本パラメータに使用するバインダの数を指定する必要があります。<br>
		<br>
		num_bindersには「同時に使用するバインダの最大数」を指定します。<br>
		例えば、 ::criFsBinder_Create 関数と ::criFsBinder_Destroy 関数を交互に続けて実行するケースにおいては、
		最大同時には1つのバインダしか使用しないため、関数の呼び出し回数に関係なくnum_bindersに1を指定することが可能です。<br>
		逆に、ある場面でバインダを10個使用する場合には、その他の場面でバインダを全く使用しない場合であっても、
		num_bindersに10を指定する必要があります。<br>
		\par 備考:
		CRI File Systemライブラリは、使用するバインダの数分だけのメモリを初期化時に要求します。<br>
		そのため、num_bindersに必要最小限の値をセットすることで、ライブラリが必要とするメモリのサイズを抑えることが可能です。<br>
		\sa criFsBinder_Create, criFsBinder_Destroy
	*/
	CriSint32 num_binders;

	/*JP
		\brief 使用するCriFsLoaderの数
		\par 説明:
		アプリケーション中で使用するローダ（CriFsLoader）の数を指定します。<br>
		アプリケーション中で ::criFsLoader_Create 関数を使用してローダを作成する場合、
		本パラメータに使用するローダの数を指定する必要があります。<br>
		<br>
		num_loadersには「同時に使用するローダの最大数」を指定します。<br>
		例えば、 ::criFsLoader_Create 関数と ::criFsLoader_Destroy 関数を交互に続けて実行するケースにおいては、
		最大同時には1つのローダしか使用しないため、関数の呼び出し回数に関係なくnum_loadersに1を指定することが可能です。<br>
		逆に、ある場面でローダを10個使用する場合には、その他の場面でローダを全く使用しない場合であっても、
		num_loadersに10を指定する必要があります。<br>
		\par 備考:
		CRI File Systemライブラリは、使用するローダの数分だけのメモリを初期化時に要求します。<br>
		そのため、num_loadersに必要最小限の値をセットすることで、ライブラリが必要とするメモリのサイズを抑えることが可能です。<br>
		\sa criFsLoader_Create, criFsLoader_Destroy
	*/
	CriSint32 num_loaders;

	/*JP
		\brief 使用するCriFsGroupLoaderの数
		\par 説明:
		アプリケーション中で使用するグループローダ（CriFsGroupLoader）の数を指定します。<br>
		アプリケーション中で ::criFsGroupLoader_Create 関数を使用してグループローダを作成する場合、
		本パラメータに使用するグループローダの数を指定する必要があります。<br>
		<br>
		num_group_loadersには「同時に使用するグループローダの最大数」を指定します。<br>
		例えば、 ::criFsGoupLoader_Create 関数と ::criFsGroupLoader_Destroy 関数を交互に続けて実行するケースにおいては、
		最大同時には1つのグループローダしか使用しないため、関数の呼び出し回数に関係なくnum_group_loadersに1を指定することが可能です。<br>
		逆に、ある場面でグループローダを10個使用する場合には、その他の場面でグループローダを全く使用しない場合であっても、
		num_group_loadersに10を指定する必要があります。<br>
		\par 備考:
		CRI File Systemライブラリは、使用するグループローダの数分だけのメモリを初期化時に要求します。<br>
		そのため、num_group_loadersに必要最小限の値をセットすることで、ライブラリが必要とするメモリのサイズを抑えることが可能です。<br>
		\sa criFsGroupLoader_Create, criFsGroupLoader_Destroy
	*/
	CriSint32 num_group_loaders;

	/*JP
		\brief 使用するCriFsStdioの数
		\par 説明:
		アプリケーション中で使用するCriFsStdioハンドルの数を指定します。<br>
		アプリケーション中で ::criFsStdio_OpenFile 関数を使用してCriFsStdioハンドルを作成する場合、
		本パラメータに使用するCriFsStdioハンドルの数を指定する必要があります。<br>
		<br>
		num_stdio_handlesには「同時に使用するCriFsStdioハンドルの最大数」を指定します。<br>
		例えば、 ::criFsStdio_OpenFile 関数と ::criFsStdio_CloseFile 関数を交互に続けて実行するケースにおいては、
		最大同時には1つのCriFsStdioハンドルしか使用しないため、関数の呼び出し回数に関係なくnum_stdio_handlesに1を指定することが可能です。<br>
		逆に、ある場面でCriFsStdioハンドルを10個使用する場合には、その他の場面でCriFsStdioハンドルを全く使用しない場合であっても、
		num_stdio_handlesに10を指定する必要があります。<br>
		\par 備考:
		CRI File Systemライブラリは、使用するCriFsStdioハンドルの数分だけのメモリを初期化時に要求します。<br>
		そのため、num_stdio_handlesに必要最小限の値をセットすることで、ライブラリが必要とするメモリのサイズを抑えることが可能です。<br>
		\attention
		ブリッジライブラリを使用してADXライブラリや救声主ライブラリを併用する場合、
		ADXTハンドルやcriSsPlyハンドルは内部的にCriFsStdioハンドルを作成します。<br>
		そのため、ブリッジライブラリを使用する場合には、CRI File Systemライブラリ初期化時に
		num_stdio_handlesにADXTハンドルやcriSsPlyハンドルの数を加えた値を指定してください。<br>
		\sa criFsStdio_OpenFile, criFsStdio_CloseFile
	*/
	CriSint32 num_stdio_handles;

	/*JP
		\brief 使用するCriFsInstallerの数
		\par 説明:
		アプリケーション中で使用するインストーラ（CriFsInstaller）の数を指定します。<br>
		アプリケーション中で ::criFsInstaller_Create 関数を使用してインストーラを作成する場合、
		本パラメータに使用するインストーラの数を指定する必要があります。<br>
		<br>
		num_installersには「同時に使用するインストーラの最大数」を指定します。<br>
		例えば、 ::criFsInstaller_Create 関数と ::criFsInstaller_Destroy 関数を交互に続けて実行するケースにおいては、
		最大同時には1つのインストーラしか使用しないため、関数の呼び出し回数に関係なくnum_installersに1を指定することが可能です。<br>
		逆に、ある場面でインストーラを10個使用する場合には、その他の場面でインストーラを全く使用しない場合であっても、
		num_installersに10を指定する必要があります。<br>
		\par 備考:
		CRI File Systemライブラリは、使用するインストーラの数分だけのメモリを初期化時に要求します。<br>
		そのため、num_installersに必要最小限の値をセットすることで、ライブラリが必要とするメモリのサイズを抑えることが可能です。<br>
		\attention
		::criFs_SetDefaultConfig マクロを使用してコンフィギュレーションを初期化する場合、num_installersの数は0に設定されます。<br>
		そのため、インストーラを使用する場合には、アプリケーション中でnum_installersを明示的に指定する必要があります。<br>
		\sa criFsInstaller_Create, criFsInstaller_Destroy
	*/
	CriSint32 num_installers;

	/*JP
		\brief 最大同時バインド数
		\par 説明:
		アプリケーション中でバインド処理を行い、保持するバインドID（CriFsBindId）の数を指定します。<br>
		アプリケーション中で ::criBinder_BindCpk 関数等を使用してバインド処理を行う場合、
		本パラメータに使用するバインドIDの数を指定する必要があります。<br>
		<br>
		max_bindsには「同時に使用するバインドIDの最大数」を指定します。<br>
		例えば、 ::criFsBinder_BindCpk 関数と ::criFsBinder_Unbind 関数を交互に続けて実行するケースにおいては、
		最大同時には1つのバインドIDしか使用しないため、関数の呼び出し回数に関係なくmax_bindsに1を指定することが可能です。<br>
		逆に、ある場面でバインドIDを10個使用する場合には、その他の場面でバインドを一切行わない場合であっても、
		max_bindsに10を指定する必要があります。<br>
		\par 備考:
		CRI File Systemライブラリは、使用するバインドIDの数分だけのメモリを初期化時に要求します。<br>
		そのため、max_bindsに必要最小限の値をセットすることで、ライブラリが必要とするメモリのサイズを抑えることが可能です。<br>
		\sa criFsBinder_BindCpk, criFsBinder_BindFile, criFsBinder_BindFiles, criFsBinder_BindDirectory, criFsBinder_Unbind
	*/
	CriSint32 max_binds;

	/*JP
		\brief 最大同時オープンファイル数
		\par 説明:
		アプリケーション中でオープンするファイルの数を指定します。<br>
		アプリケーション中で ::criFsStdio_OpenFile 関数等を使用してファイルをオープンする場合、
		本パラメータにオープンするファイルの数を指定する必要があります。<br>
		<br>
		max_filesには「同時にオープンするファイルの最大数」を指定します。<br>
		例えば、 ::criFsStdio_OpenFile 関数と ::criFsStdio_CloseFile 関数を交互に続けて実行するケースにおいては、
		最大同時には1つのファイルしかオープンしないため、関数の呼び出し回数に関係なくmax_filesに1を指定することが可能です。<br>
		逆に、ある場面でファイルを10個オープンする場合には、その他の場面でファイルを1つしかオープンしない場合であっても、
		max_filesに10を指定する必要があります。<br>
		\par 補足:
		CRI File Systemライブラリは、以下の関数を実行した場合にファイルをオープンします。<br>
		\table "ファイルがオープンされる場面" align=center border=1 cellspacing=0 cellpadding=4
		{関数					|備考	}
		[criFsBinder_BindCpk	|オープンされるファイルの数は1つ。<br> criFsBinder_Unbind 関数が実行されるまでの間ファイルはオープンされ続ける。	]
		[criFsBinder_BindFile	|オープンされるファイルの数は1つ。<br> criFsBinder_Unbind 関数が実行されるまでの間ファイルはオープンされ続ける。	]
		[criFsBinder_BindFiles	|リストに含まれる数分ファイルがオープンされる。<br> criFsBinder_Unbind 関数が実行されるまでファイルはオープンされ続ける。	]
		[criFsLoader_Load		|オープンされるファイルの数は1つ。<br> ロードが完了するまでの間ファイルはオープンされ続ける。<br> バインダを指定した場合、ファイルはオープンされない（バインダが既にオープン済みのため）。	]
		[criFsStdio_OpenFile	|オープンされるファイルの数は1つ。<br> criFsStdio_CloseFile 関数が実行されるまでの間ファイルはオープンされ続ける。<br> バインダを指定した場合、ファイルはオープンされない（バインダが既にオープン済みのため）。	]
		[criFsInstaller_Copy	|オープンされるファイルの数は2つ。<br> ファイルコピーが完了するまでの間ファイルはオープンされ続ける。<br> バインダを指定した場合、オープンされるファイルは1つになる（1つをバインダが既にオープン済みのため）。	]
		\endtable
		\attention
		ブリッジライブラリを使用してADXライブラリや救声主ライブラリを併用する場合、
		ADXTハンドルやcriSsPlyハンドルは内部的にCriFsStdioハンドルを作成します。<br>
		そのため、ブリッジライブラリを使用する場合には、CRI File Systemライブラリ初期化時に
		max_filesにADXTハンドルやcriSsPlyハンドルの数を加えた値を指定してください。<br>
	*/
	CriSint32 max_files;

	/*JP
		\brief パスの最大長（バイト単位）
		\par 説明:
		アプリケーション中で指定するファイルパスの最大長を指定します。<br>
		アプリケーション中で ::criFsLoader_Load 関数等を使用してファイルにアクセスする場合、
		本パラメータにアプリケーションで使用するパス文字列の最大長を指定する必要があります。<br>
		<br>
		max_pathには「使用するパス文字列の最大数」を指定します。<br>
		ある場面で256バイトのファイルパスを使用する場合、その他の場面で32バイトのファイルパスしか使わない場合でも、
		max_pathには256を指定する必要があります。<br>
		\par 備考:
		パスの最大長には、終端のNULL文字を含んだ数を指定する必要があります。<br>
		（「文字数＋１バイト」の値を指定する必要があります。）<br>
		\attention
		PC等、ユーザがアプリケーションを自由な場所にインストール可能な場合には、想定される最大サイズを max_path に指定する必要がありますので、ご注意ください。<br>
	*/
	CriSint32 max_path;

	/*JP
		\brief ライブラリバージョン番号
		\par 説明:
		CRI File Systemライブラリのバージョン番号です。<br>
		::criFs_SetDefaultConfig 関数により、本ヘッダに定義されているバージョン番号が設定されます。<br>
		\attention
		アプリケーションでは、この値を変更しないでください。<br>
	*/
	CriUint32 version;
} CriFsConfig;

/*==========================================================================
 *      CRI File System Binder
 *=========================================================================*/
struct CriFsBinderHnObjTag;
/*JP
 * \brief CriFsBinderハンドル
 * \ingroup FSLIB_CRIFS
 * \par 説明:
 * ADX2 LE の場合、関数引数に渡すバインダハンドルはNULLを指定してください。
 */
typedef struct CriFsBinderHnObjTag *CriFsBinderHn;


#endif	/* CRI_INCL_CRI_LE_FILE_SYSTEM_H */

/* --- end of file --- */
