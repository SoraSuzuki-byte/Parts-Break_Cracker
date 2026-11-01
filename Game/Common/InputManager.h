/*
    @file   InputManager.h
    @brief  キーボードやジョイパッドからの入力を受け付けるクラス
    @author 2026年10月28日
    @date   鈴木蒼良
*/
#pragma once

class InputManager
{
private:
    int m_key{};     // いまのフレームの入力情報
    int m_oldKey{};  // ひとつ前のフレームの入力情報
    int m_trigger{}; // トリガー情報

public:
    // 処理を書く必要がないため「= default」を使っています
    InputManager()  = default; // コンストラクタ
    ~InputManager() = default; // デストラクタ

    // 再代入不可、所有権を持たないことを明示するため　コピーとムーブを禁止する
    // 「= delete」は、その関数を使用禁止にするための指定です
    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;
    InputManager(InputManager&&) = delete;
    InputManager& operator=(InputManager&&) = delete;

    void Initialize();// 初期化処理

    void Update();    // 更新処理

    // いまのフレームの入力情報を取得する
    int GetKeyCondition() const;

    // トリガー情報を取得する
    int GetKeyTrigger() const;
};