/*
    @file   MyLibCircleCollision.h
    @brief  衝突円を扱う
    @author 鈴木蒼良
    @date   2026年10月29日
*/
#pragma once

namespace mylib
{
    // 円コライダー
    struct BoundingCircle
    {
        Vector2D center; // 円の中心座標
        float    radius; // 半径
    };

    // 円と円の衝突判定
    inline bool Intersects(const BoundingCircle& lhs, const BoundingCircle& rhs)
    {
        // 各軸で差分を計算
        const float dx = lhs.center.x - rhs.center.x;
        const float dy = lhs.center.y - rhs.center.y;

        // 三平方の定理で　斜辺の2乗　に該当する部分を計算
        const float distanceSq = (dx * dx) + (dy * dy);

        // 2つの円コライダーの半径を、合計する
        const float totalRadius = lhs.radius + rhs.radius;

        // 斜辺の2乗　が　半径の合計の2乗　より小さければ「true」
        return distanceSq <= (totalRadius * totalRadius);
    }
}






//このように、引数の型が異なれば、同じ名前の関数を定義できます。これは 関数のオーバーロード というC++の機能です。
//
//なお、実際にこの宣言を追加する場合は、関数の定義方法や inline の扱いも統一してください。
// ↓
// ↓
// ↓
//namespace mylib
//{
//    // 円と円の衝突判定
//    bool Intersects(
//        const BoundingCircle& lhs,
//        const BoundingCircle& rhs);
//
//    // 矩形と矩形の衝突判定
//    bool Intersects(
//        const BoundingBox& lhs,
//        const BoundingBox& rhs);
//}
//
//このように、引数の型が異なれば、同じ名前の関数を定義できます。これは 関数のオーバーロード というC++の機能です。
//
//なお、実際にこの宣言を追加する場合は、関数の定義方法や inline の扱いも統一してください。