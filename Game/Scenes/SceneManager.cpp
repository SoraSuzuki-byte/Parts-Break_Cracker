/*
    @file   SceneManager.h
    @brief  シーンマネジャークラス
    @author 鈴木蒼良
    @date   2026年10月28日
*/
#include "pch.h"
#include "SceneManager.h"
#include "Game/Common/GameContext.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "ResultScene.h"
#include <cassert>

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="gameContext">ゲームコンテキスト</param>
SceneManager::SceneManager(GameContext& gameContext)
    : m_gameContext{ gameContext }
{
}

/// <summary>
/// 初期化
/// </summary>
void SceneManager::Initialize()
{
    // 初回のシーン生成
    CreateScene(SceneID::TitleSceneID);
}

/// <summary>
/// 更新
/// </summary>
void SceneManager::Update(float elapsedTime, int keyCondition, int keyTrigger)
{
    // 現在のシーンを更新
    if (m_currentScene)
    {
        m_currentScene->Update(*this, elapsedTime, keyCondition, keyTrigger);
    }

    // シーン切り替えのリクエストが発生していたら
    if (m_requedtedSceneID != SceneID::NoneID)
    {
        // 保持していたリクエストIDを使用して、次のシーンを指定する
        const SceneID nextID = m_requedtedSceneID;

        // リクエストのクリア
        m_requedtedSceneID = SceneID::NoneID;

        // シーンを切り替え
        ChangeScene(nextID);
    }
}

/// <summary>
/// 描画
/// </summary>
void SceneManager::Render()
{
    if (m_currentScene)
    {
        m_currentScene->Render();
        m_currentScene->DebugDraw();
    }
}

/// <summary>
/// 終了処理
/// </summary>
void SceneManager::Finalize()
{
    DeleteScene();
}

/// <summary>
/// 次のシーンをリクエストする
/// </summary>
/// <param name="requestSceneID">リクエストのシーンID</param>
void SceneManager::RequestNextSceneID(SceneID requestSceneID)
{
    m_requedtedSceneID = requestSceneID;
}

/// <summary>
/// デバッグ表示
/// </summary>
void SceneManager::DebugDraw()
{
    m_currentScene->DebugDraw();
}

/// <summary>
/// シーンを変更する
/// </summary>
/// <param name="sceneID">変更したいシーンのID</param>
void SceneManager::ChangeScene(SceneID sceneID)
{
    DeleteScene();
    CreateScene(sceneID);
}

/// <summary>
/// シーンを作成する
/// </summary>
/// <param name="sceneID">作成したいシーンのID</param>
void SceneManager::CreateScene(SceneID sceneID)
{
    assert(m_currentScene == nullptr && "SceneManager::CreateScene::既存シーンが破棄されていません");

    // 必要に応じてシーンを生成する
    switch (sceneID)
    {
        case SceneID::TitleSceneID:
        {
            m_currentScene = std::make_unique<TitleScene>(m_gameContext);
            break;
        }
        case SceneID::PlaySceneID:
        {
            m_currentScene = std::make_unique<PlayScene>(m_gameContext);
            break;
        }
        case SceneID::ResultSceneID:
        {
            m_currentScene = std::make_unique<ResultScene>(m_gameContext);
            break;
        }
        default:
        {
            assert(!"SceneManager::CreateScene::指定されたSceneIDが存在しません");
            break;
        }
    }
        // 現在シーンを初期化する
        assert(m_currentScene && "Scenemanager::CreateScene::シーン生成に失敗しました");
        m_currentScene->Initialize();
}

/// <summary>
/// シーンを削除する
/// </summary>
void SceneManager::DeleteScene()
{
    if (m_currentScene)
        {
            // 破棄する前に終了処理を行う
            m_currentScene->Finalize();

            // 現在のシーンを破棄
            m_currentScene.reset();
        }
}
