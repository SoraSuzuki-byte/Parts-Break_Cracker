/*
    @file   PlayScene.cpp
    @brief  プレイシーンクラス
    @author 鈴木蒼良
    @date   2026年10月29日
*/
#include "pch.h"
#include "PlayScene.h"
#include "SceneID.h"
#include "SceneManager.h"
#include "Game/Common/GameContext.h"
#include "Library/MyLib/MyLibDrawString.h"
#include <cassert>

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="gameContext">ゲームコンテキスト</param>
PlayScene::PlayScene(GameContext& gameContext)
    : m_gameContext{ gameContext }
{
}

/// <summary>
/// 初期化
/// </summary>
void PlayScene::Initialize()
{
}

/// <summary>
/// 更新
/// </summary>
/// <param name="sceneManager">シーンマネージャー</param>
void PlayScene::Update(SceneManager& sceneManager)
{
    // キー操作
    KeyOperation(sceneManager);


}

/// <summary>
/// 描画
/// </summary>
void PlayScene::Render()
{
}

/// <summary>
/// 終了処理
/// </summary>
void PlayScene::Finalize()
{
}

/// <summary>
/// デバッグ表示
/// </summary>
void PlayScene::DebugDraw()
{
    mylib::DrawStringAligned(Screen::CENTER_X, Screen::CENTER_Y, L"Play Scene", mylib::StringAlign::Center, 50);

#if defined(_DEBUG)
    // デバッグ時に表示したいことを、ここに書く
#endif

}

/// <summary>
/// キー操作
/// </summary>
/// <param name="sceneManager">シーンマネージャー</param>
void PlayScene::KeyOperation(SceneManager& sceneManager)
{
    // キー入力を取得する
    const auto& keyTrigger = m_gameContext.m_inputManager.GetKeyTrigger();

    // スペースキーが押されると、シーン変更される
    if (keyTrigger & PAD_INPUT_10)
    {
        sceneManager.RequestNextSceneID(SceneID::ResultSceneID);
    }

    //// Ｃキーでプレイヤーをリスポーン
    //if ((!m_playerFighter.IsActive()) && (keyTrigger & PAD_INPUT_3))
    //{
    //    m_playerFighter.Initialize(INITIAL_POSITION, m_playerBulletManager);
    //}
}
