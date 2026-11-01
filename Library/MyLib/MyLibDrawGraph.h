/*
    @file   MyLibDrawGraph.h
    @brief  画像を描画する
    @author 制作者
    @date   2026/08/02
*/

#pragma once

struct GraphicsContext
{
    POINT drawPosMin;
    POINT drawPosMax;
    POINT clipPosMin;
    POINT clipPosMax;
    int grapicsHandle;
    int transFlag;
};

namespace mylib
{
    void DrawGraphics(const GraphicsContext& graphicsContext);
}