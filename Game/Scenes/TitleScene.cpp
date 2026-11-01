/*
    @file   TitleScene.cpp
    @brief  タイトルシーンクラス
    @author 鈴木蒼良
    @date   2026年10月28日
*/
#include "pch.h"
#include "TitleScene.h"
#include "SceneID.h"
#include "SceneManager.h"
#include "Game/Screen.h"
#include "Game/Common/GameContext.h"
#include "Library/MyLib/MyLibDrawString.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="gameContext">ゲームコンテキスト</param>
TitleScene::TitleScene(GameContext& gameContext)
    : m_gameContext{ gameContext }
{
}

/// <summary>
/// 初期化
/// </summary>
void TitleScene::Initialize()
{
}

/// <summary>
/// 更新
/// </summary>
/// <param name="sceneManager">シーンマネージャー</param>
void TitleScene::Update(SceneManager& sceneManager)
{
    // キー入力を取得する
    const auto keyTrigger = m_gameContext.m_inputManager.GetKeyTrigger();

    // スペースキーが押されたら
    if (keyTrigger & PAD_INPUT_10)
    {
        // シーンを変更
        sceneManager.RequestNextSceneID(SceneID::PlaySceneID);
    }
}

/// <summary>
/// 描画
/// </summary>
void TitleScene::Render()
{
    const int graphicsHandle = m_gameContext.m_resourceManager.GetGraphicsHandle(sora::GraphicsID::TridentLogo);
    DrawRotaGraph(Screen::WIDTH / 2, Screen::HEIGHT / 2, 1.0, 0.0, graphicsHandle, TRUE);
}

/// <summary>
/// 終了処理
/// </summary>
void TitleScene::Finalize()
{
}

/// <summary>
/// デバッグ表示
/// </summary>
void TitleScene::DebugDraw()
{
    mylib::DrawStringAligned(Screen::CENTER_X, Screen::CENTER_Y, L"Title Scene", mylib::StringAlign::Center, 50);

#if defined(_DEBUG)
    DrawString(Screen::WIDTH - 120, Screen::HEIGHT - 30, L"Title Scene", Colors::YELLOW);
#endif
}
