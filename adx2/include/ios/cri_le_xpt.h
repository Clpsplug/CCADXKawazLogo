/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * copyright (c) 2014 CRI Middleware Co., Ltd.
 *
 * Library  : CRI Middleware Library
 * Module   : CRI Common Header for iOS
 * File     : cri_le_xpt_ios.h
 * Date     : 2014-07-03
 * Version  : 1.00LE
 *
 ****************************************************************************/
#ifndef CRI_INCL_CRI_LE_XPT_IOS_H
#define CRI_INCL_CRI_LE_XPT_IOS_H

#include <stddef.h>
#include <stdint.h>

#include <TargetConditionals.h>
#include <Availability.h>

#define XPT_TGT_IOS
#define XPT_TGT_IPHONE
#define XPT_CCS_LEND

#if TARGET_IPHONE_SIMULATOR
	#if TARGET_CPU_X86
    	#define CRI_TARGET_STR "iOS_SIM_X86"
	#elif TARGET_CPU_X86_64
    	#define CRI_TARGET_STR "iOS_SIM_X86_64"
	#else
		#error unsupported architecture
	#endif
#elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__)
    #define CRI_TARGET_STR "iOS_ARMv6"
#elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__)
    #define CRI_TARGET_STR "iOS_ARMv7"
#elif defined(__ARM_ARCH_7S__)
    #define CRI_TARGET_STR "iOS_ARMv7s"
#elif defined(__ARM64_ARCH_8__)
    #define CRI_TARGET_STR "iOS_ARMv8_A64"
#else
	#error unsupported architecture
#endif

#define XPT_SUPPORT_MULTICHANNEL

/*****************************************************************************
 * 基本データ型宣言
 *****************************************************************************/

#ifndef _TYPEDEF_CriUint8
#define _TYPEDEF_CriUint8
typedef uint8_t					CriUint8;		/* 符号なし１バイト整数 */
#endif

#ifndef _TYPEDEF_CriSint8
#define _TYPEDEF_CriSint8
typedef int8_t					CriSint8;		/* 符号つき１バイト整数 */
#endif

#ifndef _TYPEDEF_CriUint16
#define _TYPEDEF_CriUint16
typedef uint16_t				CriUint16;		/* 符号なし２バイト整数 */
#endif

#ifndef _TYPEDEF_CriSint16
#define _TYPEDEF_CriSint16
typedef int16_t					CriSint16;		/* 符号つき２バイト整数 */
#endif

#ifndef _TYPEDEF_CriUint32
#define _TYPEDEF_CriUint32
typedef uint32_t				CriUint32;		/* 符号なし４バイト整数 */
#endif

#ifndef _TYPEDEF_CriSint32
#define _TYPEDEF_CriSint32
typedef int32_t					CriSint32;		/* 符号つき４バイト整数 */
#endif

#ifndef _TYPEDEF_CriUint64
#define _TYPEDEF_CriUint64
typedef uint64_t				CriUint64;		/* 符号なし８バイト整数 */
#endif

#ifndef _TYPEDEF_CriSint64
#define _TYPEDEF_CriSint64
typedef int64_t					CriSint64;		/* 符号つき８バイト整数 */
#endif

#ifndef _TYPEDEF_CriUint128
#define _TYPEDEF_CriUint128
typedef struct {								/* 符号なし16バイト整数 */
	CriUint64			h;						/* 上位64ビット */
	CriUint64			l;						/* 下位64ビット */
} CriUint128;
#endif

#ifndef _TYPEDEF_CriSint128
#define _TYPEDEF_CriSint128
typedef struct {								/* 符号つき16バイト整数 */
	CriSint64	h;								/* 上位64ビット */
	CriUint64	l;								/* 下位64ビット */
} CriSint128;
#endif

#ifndef _TYPEDEF_CriFloat16
#define _TYPEDEF_CriFloat16
typedef CriSint16				CriFloat16;		/* ２バイト実数 */
#endif

#ifndef _TYPEDEF_CriFloat32
#define _TYPEDEF_CriFloat32
typedef float					CriFloat32;		/* ４バイト実数 */
#endif

#ifndef _TYPEDEF_CriFloat64
#define _TYPEDEF_CriFloat64
typedef double					CriFloat64;		/* ８バイト実数 */
#endif

#ifndef _TYPEDEF_CriFixed32
#define _TYPEDEF_CriFixed32
typedef CriSint32				CriFixed32;		/* 固定小数点32ビット */
#endif

#ifndef _TYPEDEF_CriBool
#define _TYPEDEF_CriBool
typedef CriSint32				CriBool;		/* 論理型（論理定数を値にとる） */
#endif

#ifndef _TYPEDEF_CriChar8
#define _TYPEDEF_CriChar8
typedef char					CriChar8;		/* 文字型 */
#endif

/*****************************************************************************
 * ポインタを格納可能な整数型
 *****************************************************************************/
#ifndef _TYPEDEF_CriSintPtr
#define _TYPEDEF_CriSintPtr
typedef intptr_t				CriSintPtr;
#endif

#ifndef _TYPEDEF_CriUintPtr
#define _TYPEDEF_CriUintPtr
typedef uintptr_t				CriUintPtr;
#endif

/*****************************************************************************
 * 定数マクロ
 * Macros of constant value
 *****************************************************************************/

/* NULL ポインタ型 */
#if !defined(CRI_NULL)
#ifdef __cplusplus
#define CRI_NULL	(0)
#else
#define CRI_NULL	((void *)0)
#endif
#endif

/* 論理定数１（偽、真） */
#if !defined(CRI_FALSE)
#define CRI_FALSE	(0)
#endif
#if !defined(CRI_TRUE)
#define CRI_TRUE	(1)
#endif

/* 論理定数２（スイッチ） */
#if !defined(CRI_OFF)
#define CRI_OFF		(0)
#endif
#if !defined(CRI_ON)
#define CRI_ON		(1)
#endif

/* 結果判定の定数（成功、失敗） */
#if !defined(CRI_OK)
#define CRI_OK		(0)			/* 成功 */
#endif
#if !defined(CRI_NG)
#define CRI_NG		(-1)		/* 失敗 */
#endif

/*****************************************************************************
 * ポインタまたは64ビットアドレスを格納できる整数型
 * 備考: ポインタ32bitかつROMアドレス空間64bitの環境で、両者を透過的に扱える。
 * The integer type which can hold an pointer or an address up to 64 bits.
 * NOTE: In the environment of pointer 32bit and ROM address space 64bit, 
 *       this type can treat both transparently. 
 *****************************************************************************/

#if !defined(_TYPEDEF_CriUint64Adr)
#define _TYPEDEF_CriUint64Adr
typedef CriUint64				CriUint64Adr;		/* ポインタまたは64ビットアドレスを格納できる整数型 */
#endif

#if !defined(CRI_PTR_TO_UINT64ADR)
#define CRI_PTR_TO_UINT64ADR(ptr)		((CriUint64Adr)(ptr))	/* Convert pointer to CriUint64Adr */
#endif

#if !defined(CRI_UINT64ADR_TO_PTR)
#define CRI_UINT64ADR_TO_PTR(uint64adr)	((void *)(CriUintPtr)(uint64adr))	/* Convert CriUint64Adr to pointer */
#endif

/*****************************************************************************
 * 呼び出し規約
 *****************************************************************************/

#ifndef CRIAPI
#define CRIAPI
#endif	/* endif CRIAPI */

#endif  /* CRI_INCL_CRI_LE_XPT_IOS_H */
/* End Of File */
