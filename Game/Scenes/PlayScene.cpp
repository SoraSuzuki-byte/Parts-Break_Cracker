/*
    @file   PlayScene.cpp
    @brief  プレイシーンクラス
    @author 鈴木蒼良
    @date   2026年10月29日
*/
#include "pch.h"
#include "PlayScene.h"
#include "SceneID.h"
#include "SceneManager.h"
#include "Game/Common/GameContext.h"
#include "Library/MyLib/MyLibDrawString.h"
#include "Game/Player/PlayerConstants.h"

#include "Game/Player/Player.h"
#include "Game/Boss/OctopusBoss/OctopusBoss.h"
#include <cassert>

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="gameContext">ゲームコンテキスト</param>
PlayScene::PlayScene(GameContext& gameContext)
    : m_gameContext{ gameContext }
{
    m_player = std::make_unique<Player>();
}

/// <summary>
/// デストラクタ
/// </summary>
PlayScene::~PlayScene() = default;

/// <summary>
/// 初期化
/// </summary>
void PlayScene::Initialize()
{
    // プレイヤーの初期化
    if (m_player)
    {
        m_player->Initialize();
    }

    // ボスの生成・初期化
    m_boss = std::make_unique<OctopusBoss>();
}

/// <summary>
/// 更新
/// </summary>
/// <param name="sceneManager">シーンマネージャー</param>
void PlayScene::Update(SceneManager& sceneManager, float elapsedTime, int keyCondition, int keyTrigger)
{
    // スペースキーが押されたら
    if (keyTrigger & PAD_INPUT_10)
    {
        // シーンを変更する
        sceneManager.RequestNextSceneID(SceneID::ResultSceneID);
    }


    // Playerの攻撃が触手に当たるか
    if (m_player->CanDealAttackDamage()) // 攻撃判定を出せるなら
    {
        // 当たった部位へダメージを与え、当たった部位の個数を取得する
        const int hitCount = m_boss->TakeDamageByCircle(
            m_player->GetAttackCenter(),
            m_player->GetAttackRadius(),
            PlayerConstants::ATTACK_DAMAGE,
            m_player->GetAttackId());
    }


    // 触手とPlayerの体の判定（押し戻しと、触手が攻撃中ならPlayerにダメージを与える）
    Vector2D pushOut;
    if (m_boss->IsCollidingWithCircle(m_player->GetBodyCenter(), m_player->GetBodyRadius(), pushOut))
    {
        // 触れていれば、攻撃中でなくても押し戻す
        m_player->ApplyPushOut(pushOut);

        // ダメージは、攻撃中のときだけ
        if (m_boss->IsAttacking())
        {
            m_player->TakeDamage(1);
        }
    }



    m_player->Update(elapsedTime, keyCondition, keyTrigger);
    m_boss->Update(elapsedTime);
}





/// <summary>
/// 描画
/// </summary>
void PlayScene::Render()
{
    m_boss->Render();
    m_player->Render();
    m_boss->RenderHpBar();
}

/// <summary>
/// 終了処理
/// </summary>
void PlayScene::Finalize()
{
}





/// <summary>
/// デバッグ表示
/// </summary>
void PlayScene::DebugDraw()
{
    mylib::DrawStringAligned(Screen::CENTER_X, Screen::CENTER_Y, L"Play Scene", mylib::StringAlign::Center, 50);

#if defined(_DEBUG)
    // デバッグ時に表示したいことを、ここに書く
#endif

}