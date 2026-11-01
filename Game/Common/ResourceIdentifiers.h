/*
    @file   ResourceIdentifiers.h
    @brief  リソースで使用するIDの一覧
    @author 鈴木蒼良
    @date   2026年10月28日
*/
#pragma once

// 「uint8_t」は、8ビットの符号なし（マイナスがない）整数型のこと
// 「uint8_t」 の最大値は 255 です
namespace sora
{
    enum class GraphicsID : uint16_t
    {
        TridentLogo,
        StgAll,
        aaa,
        // 追加するときは この場所と
        // ResourceTable.hの　GraphicsEntryに一行。 
    };
    
    // サウンドID
    enum class BgmID : uint8_t
    {
        None,
    };
    enum class SeID : uint8_t
    {
        None,
    };
}

/*
    NOTE:
    ■「enum」などが野良にならないように名前空間で括っています
    ・グローバル空間で名前の重複を防ぐベストプラクティス
    ・全ての自作コードを共通の名前空間で括るとよい

    ■enumの型
    ・int：４バイト、uint8_t：１バイトなので、メモリの抑制になる
    ・構造体ではパディングの関係でintに切り上げられるので、意味がないかも
    ・迷ったらデフォルトのintやunsigned intを使う
*/
