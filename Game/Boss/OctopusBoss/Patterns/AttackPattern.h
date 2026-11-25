/*
	@file   AttackPattern.h
	@brief  攻撃パターンの基底クラス
	@author 鈴木蒼良
	@date   2026年11月26日
*/
#pragma once
#include "Library/GameMath.h"
#include <vector>
#include <memory>
class Tentacle;

class AttackPattern
{
public:
	// コンストラクタ
	AttackPattern() = default;;

	// デストラクタ
	virtual ~AttackPattern() = default;
	
	// パターン開始時の初期化
	virtual void Start(std::vector<std::unique_ptr<Tentacle>>& tentacles) = 0;

	// パターン終了時の設定
	virtual void End(std::vector<std::unique_ptr<Tentacle>>& tentacles) = 0;

	// 更新
	virtual void Update(
		float elapsedTime,
		std::vector<std::unique_ptr<Tentacle>>& tentacles,
		const Vector2D& playerPos
	) = 0;

	// 描画（パターン独自の）
	virtual void Render() const {};

	// 終了しているかどうか
	virtual bool IsFinished() const = 0;
};