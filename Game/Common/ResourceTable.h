/*
	@file   ResourceTable.h
	@brief  リソースのIDとファイルパスの対応表
	@author 鈴木蒼良
	@date   2026年10月29日
*/
#pragma once
#include "ResourceIdentifiers.h"

// マクロ（#define）は、コンパイルの直前(プリプロセス時)に指定した文字列へ置換される
#define SORA_TEXTURE_DIR L"Resources/Textures/"

namespace sora
{
	struct GraphicsEntry
	{
		GraphicsID id;
		const wchar_t* path;
	};

	// ヘッダーに定義を書くので inline（複数の .cpp から読まれても多重定義にならない）
	inline constexpr GraphicsEntry GRAPHICS_TABLE[] =
	{
		{ GraphicsID::TridentLogo, SORA_TEXTURE_DIR L"TridentLogo.png" },
		{ GraphicsID::StgAll,      SORA_TEXTURE_DIR L"ShootingGame.png" },
		{ GraphicsID::aaa,		   SORA_TEXTURE_DIR L"aaa.png" },
		// 追加するときは ここと
		// ResourceIdentifiers.hのGraphicsIDのenumに、1行
		
	};
}
    // inline について
	//ヘッダーに定義を書くと、複数の .cpp に取り込まれて多重定義になる。inline はその定義の重複を許可する指定。だから「ヘッダーに定義を書く関数・変数」に付けている。
	// 
	// 注意
	// inline を付ければ何でも解決するわけではありません。「定義が複数あっても全部同一」が前提なので、.cpp ごとに中身が違う定義を inline で書くと、未定義動作になります。