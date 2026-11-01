/*
	@file   Game.cpp
	@brief  ゲーム全体に関するソースファイル
	@author 鈴木蒼良
	@date   2026年10月28日
*/
#include "pch.h"
#include "Game.h"

#include "Game/Screen.h"
#include "Common/ResourceIdentifiers.h"
#include "Common/ResourceTable.h"

/// <summary>
/// コンストラクタ
/// </summary>
Game::Game()
{
}

/// <summary>
/// デストラクタ
/// </summary>
Game::~Game()
{
}

/// <summary>
/// 初期化
/// </summary>
void Game::Initialize()
{
    // 入力マネジャーを初期化する
    m_inputManager.Initialize();

    // 画像を読み込んで登録する
    for (const auto& entry : sora::GRAPHICS_TABLE)
    {
        m_resourceManager.LoadGraphics(entry.id, entry.path);
    }

    // デバッグ描画フラグを初期化する
    m_isDebugDraw = false;

    // ゲームコンテキストを作成する
    m_gameContext = std::make_unique<GameContext>(m_inputManager, m_resourceManager, m_isDebugDraw);

    // シーンマネジャーの作成と初期化をする
    m_sceneManager = std::make_unique<SceneManager>(*m_gameContext);
    m_sceneManager->Initialize();
}

/// <summary>
/// 更新
/// </summary>
void Game::Update(float elapsedTime)
{
    // 入力マネジャーを更新する
    m_inputManager.Update();

    // シーンマネジャーを更新する
    m_sceneManager->Update();


    // キートリガーの取得
    const auto& keyTrigger = m_inputManager.GetKeyTrigger();

    // Ｑキーが押されたら
    if (keyTrigger & PAD_INPUT_7)
    {
        // デバッグ描画フラグの切り替え
        m_isDebugDraw = (!m_isDebugDraw);
    }

}

/// <summary>
/// 描画
/// </summary>
void Game::Render()
{
    // シーンを描画する
    m_sceneManager->Render();
}

/// <summary>
/// 終了処理
/// </summary>
void Game::Finalize()
{
    // すべてのグラフィックスハンドルを削除
    m_resourceManager.DeleteAllGraphics();

	// シーンマネジャーを終了する
	m_sceneManager->Finalize();

	// ゲームコンテキストを破棄する
	m_gameContext.reset();
}
