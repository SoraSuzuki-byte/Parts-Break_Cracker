/*
    @file   IScene.h
    @brief  シーンのインターフェイスクラス
    @author 鈴木蒼良
    @date   2026年10月28日
*/

// インターフェイスのクラスは、純粋仮想関数のみを持たせることが多い（変数や、普通の関数はもたせない）
// 純粋仮想関数とは「= 0」を書かれていて基底クラスでは実装内容を記述しなくていい「virtual」の関数の事
// 「このクラスを継承するなら、この関数は必ず実装してね」という**インターフェース（約束事）**を定義したいときに使います。

#pragma once

// 前方宣言
class SceneManager;

class IScene
{
public:
    virtual ~IScene() = default;

    virtual void Initialize() = 0;
    virtual void Update(SceneManager& sceneManager, float elapsedTime, int keyCondition, int keyTrigger) = 0;
    virtual void Render() = 0;
    virtual void Finalize() = 0;
    virtual void DebugDraw() = 0;
};

/*
    NOTE: インターフェイスでは「仮想デストラクタ」「純粋仮想関数」のみ定義する
*/