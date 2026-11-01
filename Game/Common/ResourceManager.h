/*
    @file   ResourceManager.h
    @brief  リソースマネジャー
    @author 鈴木蒼良
    @date   2026年10月28日
*/
#pragma once
#include "ResourceIdentifiers.h"

class ResourceManager
{
private:
    // グラフィックスハンドルの連想配列
    std::unordered_map<sora::GraphicsID, int> m_graphicsHandles{};
public:
    // 処理を書く必要がないため「= default」を使っています
    ResourceManager()  = default; // コンストラクタ
    ~ResourceManager() = default; // デストラクタ

    // 再代入不可、所有権を持たないことを明示するため　コピーとムーブを禁止する
    // 「= delete」は、その関数を使用禁止にするための指定です
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    ResourceManager(ResourceManager&&) = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;


    // グラフィックスハンドルを登録する
    //void AddGraphicsHandle(sora::GraphicsID id, int graphicsHandle);

    // グラフィックスを読み込んで登録する（登録済みなら何もしない）
    bool LoadGraphics(sora::GraphicsID id, const wchar_t* path);

    // グラフィックスハンドルを削除する
    void DeleteGraphicsHandle(sora::GraphicsID id);

    // すべてのグラフィックスハンドルを削除する
    void DeleteAllGraphics();

    // 指定のグラフィックスハンドルを、取得する
    int GetGraphicsHandle(sora::GraphicsID id) const ;
};