/*
    @file   ResultScene.cpp
    @brief  リザルトシーンクラス
    @author 鈴木蒼良
    @date   2026年10月29日
*/
#include "pch.h"
#include "ResultScene.h"
#include "SceneID.h"
#include "SceneManager.h"
#include "Game/Screen.h"
#include "Game/Common/GameContext.h"
#include "Library/MyLib/MyLibDrawString.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="gameContext">ゲームコンテキスト</param>
ResultScene::ResultScene(GameContext& gameContext)
    : m_gameContext{ gameContext }
{
}

/// <summary>
/// 初期化
/// </summary>
void ResultScene::Initialize()
{
}

/// <summary>
/// 更新
/// </summary>
/// <param name="sceneManager">シーンマネージャー</param>
void ResultScene::Update(SceneManager& sceneManager, float elapsedTime, int keyCondition, int keyTrigger)
{
    // 未使用変数の警告を防止
    UNREFERENCED_PARAMETER(elapsedTime);

    // スペースキーが押されたら
    if (keyTrigger & PAD_INPUT_10)
    {
        // シーンを変更する
        sceneManager.RequestNextSceneID(SceneID::TitleSceneID);
    }
}

/// <summary>
/// 描画
/// </summary>
void ResultScene::Render()
{
}

/// <summary>
/// 終了処理
/// </summary>
void ResultScene::Finalize()
{
}

/// <summary>
/// デバッグ表示
/// </summary>
void ResultScene::DebugDraw()
{
    mylib::DrawStringAligned(Screen::CENTER_X, Screen::CENTER_Y, L"Result Scene", mylib::StringAlign::Center, 50);

#if defined(_DEBUG)
    DrawString(Screen::WIDTH - 120, Screen::HEIGHT - 30, L"Result Scene", Colors::YELLOW);
#endif

}
