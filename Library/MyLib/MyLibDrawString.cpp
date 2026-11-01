/*
    @file   MyLibDrawString.cpp
    @brief  文字列を描画する
    @author 鈴木蒼良
    @date   2026年10月29日
*/

#include "pch.h"
#include "MyLibDrawString.h"
#include <cassert>

//  -----------------------------------------------------------------
/// <summary>
/// 指定位置に文字列を描画する
/// </summary>
/// <param name="posX">描画の基準座標Ｘ</param>
/// <param name="posY">描画の基準座標Ｙ</param>
/// <param name="text">描画する文字列</param>
/// <param name="stringAlign">描画のオフセット指定</param>
/// <param name="fontSize">文字の大きさ</param>
/// <param name="color">文字の色</param>
/// -----------------------------------------------------------------
void mylib::DrawStringAligned(int posX, int posY, const wchar_t* text, StringAlign stringAlign, int fontSize, unsigned int color)
{
    // フォントサイズを一時的に変更する
    SetFontSize(fontSize);

    // 描画するフォントサイズに合った文字列の長さを取得する
    const int strWidth = GetDrawStringWidth(text, static_cast<int>(wcslen(text)));

    // 文字の描画位置（Ｘ座標）：switch-caseでStringAlignタイプに合わせて計算する
    int stringAlignX = 0;

    // 指定されたパラメータに合わせて、stringAlignXを計算する
    switch (stringAlign)
    {
        case StringAlign::Left:      stringAlignX = posX;                 break;
        case StringAlign::Center:    stringAlignX = posX - strWidth / 2;  break;
        case StringAlign::Right:     stringAlignX = posX - strWidth;      break;
        default:
            assert(!"mylib::DrawStringAligned::オフセットの指定が無効です！");
    }

    // 指定の描画位置に文字列を描画する
    DrawString(stringAlignX, posY, text, color);

    // フォントサイズを元に戻す
    SetFontSize(DEFAULT_FONT_SIZE);
}