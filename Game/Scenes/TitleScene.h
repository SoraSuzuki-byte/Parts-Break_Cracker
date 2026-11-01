/*
    @file   TitleScene.h
    @brief  タイトルシーンクラス
    @author 鈴木蒼良
    @date   2026年10月28日
*/

#pragma once
#include "Game/Scenes/IScene.h"

// 前方宣言
class SceneManager;
class GameContext;

// クラスの定義
class TitleScene final // 「final」を付ければ、もし　このクラスの派生クラスを作っちゃっても、コンパイラでエラーにしてくれる
    : public IScene
{
private:
    // ゲームコンテキスト
    GameContext& m_gameContext;

public:
    // コンストラクタ / デストラクタ
    explicit TitleScene(GameContext& gameContext);
    virtual ~TitleScene() override = default;

    // 初期化、更新、描画、後始末、デバッグ表示
    virtual void Initialize() override;
    virtual void Update(SceneManager& sceneManager) override;
    virtual void Render()override;
    virtual void Finalize() override;
    virtual void DebugDraw() override;
};