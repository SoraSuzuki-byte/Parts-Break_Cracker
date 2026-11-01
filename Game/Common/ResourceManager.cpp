/*
    @file   ResourceManager.cpp
    @brief  リソースマネジャー
    @author 鈴木蒼良
    @date   2026年10月28日
*/
#include "pch.h"
#include "ResourceManager.h"
#include <cassert>

///// <summary>
///// グラフィックスハンドルを登録する
///// </summary>
///// <param name="id">登録するグラフィックスのID</param>
///// <param name="graphicsHandle">LoadGraph などで取得した画像ハンドル（-1 は不可）</param>
///// <remarks>
///// すでに同じIDが登録されている場合は、何もせず先の登録を維持する
///// </remarks>
//void ResourceManager::AddGraphicsHandle(sora::GraphicsID id, int graphicsHandle)
//{
//    assert(graphicsHandle != (-1) && "ResourceManager::AddGraphicsHandle::画像をロードできませんでした");
//
//    // 二重登録の防止
//    if (!m_graphicsHandles.contains(id))
//    {
//        m_graphicsHandles[id] = graphicsHandle;
//    }
//}
//// contains は、std::map や std::unordered_map などの連想配列に「そのキーがすでに登録されているか」を調べる関数です。あれば true、なければ false を返します。

/// <summary>
/// グラフィックスを読み込んで登録する
/// </summary>
/// <param name="id">登録するグラフィックスのID</param>
/// <param name="path">画像ファイルのパス</param>
/// <returns>登録済み、または読み込みに成功したら true</returns>
/// <remarks>
/// すでに同じIDが登録されている場合は、読み込まずに true を返す
/// </remarks>
bool ResourceManager::LoadGraphics(sora::GraphicsID id, const wchar_t* path)
{
    // 登録済みなら、読み込む前に終了する
    if (m_graphicsHandles.contains(id))
    {
        return true;
    }

    const int handle = LoadGraph(path);
    assert(handle != (-1) && "ResourceManager::LoadGraphics::画像をロードできませんでした");
    if (handle == (-1))
    {
        return false;   // リリースビルドで assert が無効でも安全にする
    }

    m_graphicsHandles.emplace(id, handle);
    return true;
}//// contains は、std::map や std::unordered_map などの連想配列に「そのキーがすでに登録されているか」を調べる関数です。あれば true、なければ false を返します。


/// <summary>
/// グラフィクスハンドルを削除する
/// </summary>
/// <param name="id">削除するグラフィクスのID</param>
void ResourceManager::DeleteGraphicsHandle(sora::GraphicsID id)
{
    auto it = m_graphicsHandles.find(id);   // 探すだけ（作らない）
    if (it != m_graphicsHandles.end())      // 見つかった場合だけ
    {
        DeleteGraph(it->second);
        m_graphicsHandles.erase(it);
    }
}

/// <summary>
/// すべてのグラフィックスハンドルを削除する
/// </summary>
void ResourceManager::DeleteAllGraphics()
{
    for (auto& pair : m_graphicsHandles)
    {
        if (pair.second != (-1))
        {
            DeleteGraph(pair.second);// pair が持っているデータのうち、2番目の要素を消している
        }
    }
    m_graphicsHandles.clear(); // clear() はコンテナに格納されている要素を削除するものであり、コンテナそのものを破棄するわけではありません。
}

/// <summary>
/// 指定のグラフィックスハンドルを取得する
/// </summary>
/// <param name="id">削除するグラフィックスのID</param>
/// <returns>グラフィックスハンドル。該当するIDが存在しない場合は-1</returns>
int ResourceManager::GetGraphicsHandle(sora::GraphicsID id) const
{
    auto it = m_graphicsHandles.find(id);
    if (it != m_graphicsHandles.end())
    {
        return it->second;
    }

    return (-1);
}
