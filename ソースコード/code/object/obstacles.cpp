//============================================
//
// プレイヤー[obstacles.cpp]
// Author:Uedakou
// 
//============================================
#include"obstacles.h"	// オブジェクト障害物
#include "player.h"		// プレイヤー
#include "base/character.h"	// キャラクター




const D3DXVECTOR3 CObstacles::s_Collision = { 20.0f, 50.0f, 20.0f };
/// <summary>
/// コンストラクタ
/// </summary>
CObstacles::CObstacles()
{
	SetType(CObjectX::TYPE::OBSTACLES);	// 種類を障害物に設定
}
/// <summary>
/// デストラクタ
/// </summary>
CObstacles::~CObstacles()
{
}
/// <summary>
/// 初期化処理
/// </summary>
bool CObstacles::Init()
{
	CObjectX::Init();
	return true;
}
/// <summary>
/// 終了処理
/// </summary>
void CObstacles::Uninit()
{
	CObjectX::Uninit();
}
/// <summary>
/// 更新
/// </summary>
void CObstacles::Update()
{
	CObjectX::Update();
	HitTest();
}
/// <summary>
/// 描画
/// </summary>
void CObstacles::Draw()
{
	CObjectX::Draw();
}