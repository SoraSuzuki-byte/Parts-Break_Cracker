/*
    @file   PlayScene.h
    @brief  プレイシーンクラス
    @author 鈴木蒼良
    @date   2026年10月29日
*/
#pragma once
#include "Game/Screen.h"
#include "Game/Scenes/IScene.h"
#include <memory>

// 前方宣言
class SceneManager;
struct GameContext;
class Player;
class Boss;

class PlayScene final : public IScene
{
private:
    // ゲームコンテキスト
    GameContext& m_gameContext;

    //// シーンで保持するオブジェクト
    std::unique_ptr<Player> m_player;
    std::unique_ptr<Boss>   m_boss; // ボスを基底クラスで保持
    //CollisionManager m_collisionManager{};


public:
    // コンストラクタ / デストラクタ
    explicit PlayScene(GameContext& gameContext);
    virtual ~PlayScene() override;

    // 初期化、更新、描画、後始末、デバッグ表示
    virtual void Initialize() override;
    virtual void Update(SceneManager& sceneManager, float elapsedTime, int keyCondition, int keyTrigger) override;
    virtual void Render() override;
    virtual void Finalize() override;
    virtual void DebugDraw() override;
    
private:
};