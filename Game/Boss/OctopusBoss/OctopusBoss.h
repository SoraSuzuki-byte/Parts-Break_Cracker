/**
 * @file   OctopusBoss.h
 *
 * @brief タコ型ボスのクラス
 *
 * @author 鈴木蒼良
 *
 * @date   2026年11月24日
 */

#pragma once
#include "Game/Boss/Boss.h"
#include "ITentacleObserver.h"
#include <vector>
#include <memory>
class Tentacle;
class AttackPattern;

class OctopusBoss : public Boss, public ITentacleObserver
{
private:
	// 地面の高さ
	static constexpr float GROUND_Y = 700.0f;
	// 各段階の時間（秒）
	static constexpr float ENTER_TIME = 1.0f;		// 登場
	static constexpr float CHANCE_TIME = 3.5f;		// チャンス
	static constexpr float RETREAT_TIME = 1.0f;		// 退場

	// 最初に作った触手の部位数
	static constexpr float SEGMENT_COUNT = 12;

	// 地面から生える触手の部位数
	static constexpr float ERUPT_SEGMENT_COUNT = 6;

	// 画面外までの移動距離（ピクセル）
	static constexpr float OFFSCREEN_DISTANCE = 700.0f; // 触手全体を画面の右端に完全に隠すために必要な横移動の量

	/// <summary>
	/// ボスの行動段階（1サイクルの流れ）
	/// </summary>
	enum class Stage
	{
		Enter,      // 登場（画面外から定位置へ移動）
		Attack,     // 攻撃（触れるとダメージを与える）
		Chance,     // チャンス（攻撃が通り、部位を壊せる）
		Retreat     // 退場（画面外へ引っ込み、部位を復活させる）
	};
	// 現在の行動段階
	Stage m_stage{ Stage::Enter };

	// 現在の段階の残り時間（秒）
	float m_stageTimer{ ENTER_TIME };

	// 最大HP
	static constexpr int MAX_HP = 250;
	// 1部位壊れるごとに減るHP量
	static constexpr int DAMAGE_PER_SEGMENT = 5;

	// ゆれている触手のリスト
	std::vector<std::unique_ptr<Tentacle>> m_tentacles;

	// 地面から生える触手のリスト
	std::vector<std::unique_ptr<Tentacle>> m_eruptTentacles;

	// 攻撃パターンを保持するインスタンス
	std::unique_ptr<AttackPattern> m_pattern;


public:
#pragma region コンストラクタ・デストラクタ・コピーとムーブの禁止
	// コンストラクタ / デストラクタ
	OctopusBoss();
	~OctopusBoss() override;
	// 触手（Tentacle）が OctopusBoss の this を覚えるので、コピーおよびムーブを禁止する
	OctopusBoss(const OctopusBoss&) = delete;
	OctopusBoss& operator=(const OctopusBoss&) = delete;
	OctopusBoss(OctopusBoss&&) = delete;
	OctopusBoss& operator=(OctopusBoss&&) = delete;
#pragma endregion

	// Boss からのオーバーライド
	void Update(float elapsedTime) override;
	void Render() const override;
	bool IsCollidingWithCircle(const Vector2D& center, float radius, Vector2D& pushOut, bool& dealsDamage) const override;
	bool IsAttacking() const override;
	int TakeDamageByCircle(const Vector2D& center, float radius, int damage, int attackId) override;

	// ITentacleObserver からのオーバーライド（
	// 部位が1つ壊れたときに呼ばれる）
	void OnSegmentBroken() override;

#pragma region 内部実装
private:
	// 行動段階（登場→攻撃→チャンス→退場）のタイマー更新と切り替え
	void UpdateStage(float elapsedTime);

#pragma endregion
};

