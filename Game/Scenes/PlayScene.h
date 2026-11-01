/*
    @file   PlayScene.h
    @brief  プレイシーンクラス
    @author 鈴木蒼良
    @date   2026年10月29日
*/
#pragma once
#include "Game/Screen.h"
#include "Game/Scenes/IScene.h"

// 前方宣言
class SceneManager;
struct GameContext;


class PlayScene final
    : public IScene
{
private:
    // ゲームコンテキスト
    GameContext& m_gameContext;

    //// シーンで保持するオブジェクト
    //BulletManager m_playerBulletManager{ 10 };
    //BulletManager m_enemyBulletManager{ 20 };
    //PlayerFighter m_playerFighter{};
    //EnemyManager m_enemyManager{};
    //CollisionManager m_collisionManager{};


public:
    // コンストラクタ / デストラクタ
    explicit PlayScene(GameContext& gameContext);
    virtual ~PlayScene() override = default;

    // 初期化、更新、描画、後始末、デバッグ表示
    virtual void Initialize() override;
    virtual void Update(SceneManager& sceneManager) override;
    virtual void Render() override;
    virtual void Finalize() override;
    virtual void DebugDraw() override;
    
private:
    // キー操作
    void KeyOperation(SceneManager& sceneManager);
};