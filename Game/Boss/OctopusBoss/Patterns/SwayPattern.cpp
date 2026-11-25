/*
	@file   SwayPattern.cpp
	@brief  ゆらゆら揺れるパターンのソースファイル
	@author 鈴木蒼良
	@date   2026年11月26日
*/
#include "pch.h"
#include "SwayPattern.h"
#include "Game/Boss/OctopusBoss/Tentacle.h"

/// <summary>
/// パターン開始時の初期化
/// </summary>
/// <param name="tentacles">操作対象の触手たち</param>
void SwayPattern::Start(std::vector<std::unique_ptr<Tentacle>>& tentacles)
{
	m_timer = ATTACK_TIME;

	// 攻撃を有効化
	for (auto& tentacle : tentacles)
	{
		if (tentacle != nullptr)
		{
			tentacle->SetAttacking(true);
		}
	}
}





/// <summary>
/// パターン終了時の設定
/// </summary>
/// <param name="tentacles">操作対象の触手たち</param>
void SwayPattern::End(std::vector<std::unique_ptr<Tentacle>>& tentacles)
{
	// 攻撃を無効化
	for (auto& tentacle : tentacles)
	{
		if (tentacle != nullptr)
		{
			tentacle->SetAttacking(false);
		}
	}
}





/// <summary>
/// 更新
/// </summary>
/// <param name="elapsedTime">経過時間</param>
/// <param name="tentacles">操作対象の触手たち</param>
/// <param name="playerPos">Playerの位置</param>
void SwayPattern::Update(float elapsedTime, std::vector<std::unique_ptr<Tentacle>>& tentacles, const Vector2D& playerPos)
{
	m_timer -= elapsedTime;
}
