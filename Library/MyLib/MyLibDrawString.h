/*
    @file   MyLibDrawString.h
    @brief  文字列を描画する
    @author 鈴木蒼良
    @date   2026年10月29日
*/

#pragma once

namespace mylib
{
    // 文字列の揃え
    enum class StringAlign : uint8_t
    {
        Left, Center, Right
    };

    // 指定位置に文字列を描画する
    void DrawStringAligned(
        int posX,                           // 描画の基準座標
        int posY,
        const wchar_t* text,                // 描画する文字列
        StringAlign offset = StringAlign::Left,       // 描画のオフセット指定
        int fontSize = DEFAULT_FONT_SIZE,   // 文字の大きさ
        unsigned int color = Colors::WHITE  // 文字の色
    );
}