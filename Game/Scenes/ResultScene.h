/*
    @file   ResultScene.h
    @brief  リザルトシーンクラス
    @author 鈴木蒼良
    @date   2026年10月29日
*/
#pragma once
#include "Game/Scenes/IScene.h"

// 前方宣言
class SceneManager;
struct GameContext;


class ResultScene final
    : public IScene
{
private:
    // ゲームコンテキスト
    GameContext& m_gameContext;

public:
    // コンストラクタ / デストラクタ
    explicit ResultScene(GameContext& gameContext);
    virtual ~ResultScene() override = default;

    // 初期化、更新、描画、後始末、デバッグ表示
    virtual void Initialize() override;
    virtual void Update(SceneManager& sceneManager, float elapsedTime, int keyCondition, int keyTrigger) override;
    virtual void Render() override;
    virtual void Finalize() override;
    virtual void DebugDraw() override;
};