/*
    @file   GameContext.h
    @brief  ゲームコンテキストクラス（構造体）
    @author 鈴木蒼良
    @date   2026年10月28日
*/
#pragma once
#include "InputManager.h"
#include "ResourceManager.h"

struct GameContext
{
    InputManager& m_inputManager;
    ResourceManager& m_resourceManager;

    // デバッグ表示のフラグ
    bool& m_isDebugDraw;

    // コンストラクタ
    GameContext(
        InputManager& inputManager,
        ResourceManager& resourceManager,
        bool& isDebugDraw)
        : m_inputManager    { inputManager }
        , m_resourceManager { resourceManager }
        , m_isDebugDraw     { isDebugDraw }
    {
    }


    // 再代入不可、所有権を持たないことを明示するため　コピーとムーブを禁止する
    // 「= delete」は、その関数を使用禁止にするための指定です
    GameContext(const GameContext&) = delete;
    GameContext& operator=(const GameContext&) = delete;
    GameContext(GameContext&&) = delete;
    GameContext& operator=(GameContext&&) = delete;

};




/*
    NOTE:
    ・データメンバに参照を持つ場合、コンストラクタは必須（値だけを持つ構造体の場合、コンストラクタは不要）
    ・コピーとムーブを禁止することで、シングルトンやマネジャーでオブジェクトの唯一性を保証する
*/



// GameContextで管理するものの例↓

////いろいろなデータの保存
//int KillEnemyCount;
//int HitAttackCount;
//int HitAttackBodyCount;
//int HitDamageCount;
//int SumExpCount;
//int PushZSkill;
//int PushXSkill;
//int PushUp;
////初めてプレイ
//bool FirstPlay = false;
////サウンドの変数置き場
////0=タイトルBGM 1=プレイBGM 2=ボスBGM
//int BGM[3];
////0=select移動 1=決定 2=ショット打ち(ノーマル) 3=ショット打ち(パワー) 4=当てた 5=食らった 6=スキル 7=経験値 8=レベルアップ
//int SE[9];
////この世界の難易度レベル
//int worldLevel;

