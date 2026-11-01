/*
    @file   SceneManager.h
    @brief  シーンマネジャークラス
    @author 鈴木蒼良
    @date   2026年10月28日
*/
#pragma once

// ヘッダファイルの読み込み ===================================================
#include "SceneID.h"
#include "IScene.h"

// 前方宣言 =================================================================
struct GameContext;



class SceneManager
{
// 公開する定数や列挙型の宣言 ---------------------------------------
    public:

// 隠蔽する定数や列挙型の宣言 ---------------------------------------
    private:


// データメンバの宣言 -----------------------------------------------
private:
    // リクエストされたシーン
    SceneID m_requedtedSceneID{ SceneID::NoneID };

    // 現在のシーン
    std::unique_ptr<IScene> m_currentScene{ nullptr };

    // ゲームコンテキスト
    GameContext& m_gameContext;


    // メンバ関数の宣言 -------------------------------------------------
public:
    // コンストラクタ / デストラクタ
    explicit SceneManager(GameContext& gameContext);
    ~SceneManager() = default;

    

// 操作
public:
    // 初期化
    void Initialize();

    // 更新
    void Update();

    // 描画
    void Render();

    // 終了処理
    void Finalize();

    // 次のシーンをリクエストする
    void RequestNextSceneID(SceneID requestSceneID);

    // デバッグ表示
    void DebugDraw();


// 内部実装
private:
    // シーンの変更、生成、破棄
    void ChangeScene(SceneID sceneID);
    void CreateScene(SceneID sceneID);
    void DeleteScene();
};