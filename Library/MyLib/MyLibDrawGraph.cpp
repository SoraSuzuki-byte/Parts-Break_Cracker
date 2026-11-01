/*
    @file   MyLibDrawGraph.cpp
    @brief  画像を描画する
    @author 制作者
    @date   2026/08/02
*/

#include "pch.h"
#include "MyLibDrawGraph.h"

//  -----------------------------------------------------------------
/// <summary>
/// 画像を描画する：DrawRectExtendGraphのラッパー関数
/// </summary>
/// <param name="graphicsContext">グラフィクスコンテキスト</param>
/// -----------------------------------------------------------------
void mylib::DrawGraphics(const GraphicsContext& graphicsContext)
{
    // 画像を描画する
    DrawRectExtendGraph(
        graphicsContext.drawPosMin.x, graphicsContext.drawPosMin.y, // 描画始点
        graphicsContext.drawPosMax.x, graphicsContext.drawPosMax.y, // 描画終点
        graphicsContext.clipPosMin.x, graphicsContext.clipPosMin.y, // 切り抜き始点
        graphicsContext.clipPosMax.x, graphicsContext.clipPosMax.y, // 切り抜き終点
        graphicsContext.grapicsHandle, graphicsContext.transFlag    // 描画ハンドル、透過フラグ
    );
}
