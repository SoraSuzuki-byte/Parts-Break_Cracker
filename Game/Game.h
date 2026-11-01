 /*
	 @file   Game.h
	 @brief  ゲーム全体に関するヘッダファイル
	 @author 鈴木蒼良
	 @date   2026年10月28日
 */

 // 多重インクルードの防止 =====================================================
#pragma once

// ヘッダファイルの読み込み ===================================================
#include "Game/Common/GameContext.h"
#include "Scenes/SceneManager.h"

// クラスの定義 ===============================================================
/**
 * @brief ゲーム
 */

class Game
{
public:
	static constexpr const wchar_t* TITLE = L"Copy_SouceCode";

private:
	// 入力関連
	InputManager m_inputManager{};

	// リソースマネージャー
	ResourceManager m_resourceManager{};

	// デバッグ描画フラグ
	bool m_isDebugDraw{ false };

	// ゲームコンテキスト
	std::unique_ptr<GameContext> m_gameContext{}; // このコードは、ゲームコンテキストを管理するためのポインタを用意し、最初は何も管理していない状態(nullptr)にしている
															  // その後、必要なタイミングでこのように生成できます。
															  //m_gameContext = std::make_unique<GameContext>(
															  //	inputManager,
															  //	resourceManager,
															  //	isDebugDraw
															  //);

	// シーンマネージャー
	std::unique_ptr<SceneManager> m_sceneManager{ nullptr };


// メンバ関数の宣言 ===============================================================
public:
// コンストラクタ / デストラクタ
	Game();
	~Game();

// 操作（クラスの外から呼ぶ公開関数）・初期化・更新・描画・終了処理
public:
	void Initialize();
	void Update(float elapsedTime);
	void Render();
	void Finalize();

// 取得 / 設定 
public:
	//Get
	//Set

// 内部実装
private:


};