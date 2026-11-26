/*
	@file   SwayPattern.h
	@brief  ゆらゆら揺れるパターンのヘッダーファイル
	@author 鈴木蒼良
	@date   2026年11月26日
*/
#pragma once
#include "AttackPattern.h"
#include "Library/GameMath.h"
#include <vector>
#include <memory>
class Tentacle;

class SwayPattern : public AttackPattern
{
private:
	// 攻撃する時間
	static constexpr float ATTACK_TIME = 2.0f;

	// 残り時間のタイマー
	float m_timer{ ATTACK_TIME };

public:
	/// <summary>
	/// パターン開始時の初期化
	/// </summary>
	/// <param name="tentacles">操作対象の触手たち</param>
	void Start(
		std::vector<std::unique_ptr<Tentacle>>& tentacles,
		const Vector2D& playerPos) override;


	/// <summary>
	/// パターン終了時の設定
	/// </summary>
	/// <param name="tentacles">操作対象の触手たち</param>
	void End(std::vector<std::unique_ptr<Tentacle>>& tentacles) override;


	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="elapsedTime">経過時間</param>
	/// <param name="tentacles">操作対象の触手たち</param>
	/// <param name="playerPos">Playerの位置</param>
	void Update(
		float elapsedTime,
		std::vector<std::unique_ptr<Tentacle>>& tentacles,
		const Vector2D& playerPos
	) override;


	/// <summary>
	/// 終了しているかを取得
	/// </summary>
	/// <returns>終了していたらtrue</returns>
	bool IsFinished() const override { return m_timer <= 0.0f; }
};