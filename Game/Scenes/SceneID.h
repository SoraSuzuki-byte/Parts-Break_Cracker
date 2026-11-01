/*
    @file   SceneID.h
    @brief  シーンのID
    @author 鈴木蒼良
    @date   2026年10月28日
*/
#pragma once

enum class SceneID : uint8_t
{
    NoneID,
    TitleSceneID,
    PlaySceneID,
    ResultSceneID,
};

/*
    NOTE:
    ・「enum」「struct」など、野良にならないように名前空間で括った方がよい：参考「ResourceIdentifers.h」
    ・野良にならないために、クラスの中に含めるのも一手：参考「Enemy.h」
*/