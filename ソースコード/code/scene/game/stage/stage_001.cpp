//===========================================
// 
// ステージ001[stage_001.cpp]
// Auther:UedaKou
// 
//===========================================
#include "stage_001.h"		// ステージ

#include "../../../object/player.h"	// プレイヤー
#include "../../../object/base/object_2D.h"	// ポップアップ用2D
#include "../../../object/base/object_3D.h"	// ポップアップ用3D
#include "../../../object/base/object_X.h"	// ポップアップ用X
#include "../../../object/base/object_fade.h"	// フェード
#include "../../../object/base/object_billboard.h"	// ビルボード
#include "../game_data.h"	// ゲームデータ
#include "../../../object/base/text.h"	// テキスト
#include "../../../object/obstacles_tall.h"	// 障害物
#include "../../../object/obstacles_high.h"	// 障害物
#include "../../../object/obstacles_low.h"	// 障害物

#include <fstream>	// ファイルの読み込みに必要
#include <iostream>	// ファイルの読み込みに必要
#include "../scene_game_manager.h"		// ゲームマネージャー
namespace Scene {
	namespace Game {
		class CScen_Game_StageSelect;

		const float CStage_001::s_fGool = 20000.0f;	// ゴール距離
		const string CStage_001::s_aStage = "data/STAGE/Stage_001.txt";		// ステージパス
		const D3DXVECTOR3 CStage_001::s_PlayerFirstPos = { 0.0f, 0.0f, 0.0f };		// プレイヤー最初位置

		//============================================
		// コンスト
		//============================================
		CStage_001::CStage_001(CBase* scene) :
			CStage_Base(scene)
		{
			CManager* pManager = CManager::GetInstance();	// 全体マネージャー
			CCamera* pCamera = pManager->GetCamera();	// カメラ
			CSound* pSound = pManager->GetSound();	// サウンド
			pSound->PlaySound(CSound::SOUND_LABEL::SOUND_STAGE_00);	// BGMを再生


			CPlayer* pPlayer = m_gameData->GetPlayer();	// プレイヤー取得

			// メンバ変数設定
			m_bPose = false;
			m_fGool = s_fGool;

			// プレイヤー設定
			pPlayer->SetNormalUpdate(true);	// 通常時更新設定
			pPlayer->SetNormalDraw(true);	// 通常時描画設定
			pPlayer->SetPoseDraw(true);		// ポーズ時描画設定
			pPlayer->SetPos(s_PlayerFirstPos);	// 位置を初期位置に戻す
			pPlayer->SetMotion(static_cast<int>(CPlayer::Motion::ACTIVITY_MOVE));	// モーション設定
			pPlayer->SetMotionMove(true);	// モーションの動きを設定
			pPlayer->SetMove(true);	// 動きを設定
			pPlayer->SetLife(1);	// 体力設定

			D3DXVECTOR3 cameraPos = D3DXVECTOR3(s_PlayerFirstPos.x, s_PlayerFirstPos.y + sinf(m_fCameraRot) * m_fCameraRange, s_PlayerFirstPos.z + cosf(m_fCameraRot) * m_fCameraRange);
			pCamera->SetPosV(cameraPos);	// カメラに適応

			// カメラ向き
			pCamera->SetRotX(D3DX_PI - 2.0f);

			//フィールド生成
			CObject3D* pField = nullptr;
			pField = CObject3D::create(
				D3DXVECTOR3(0.0f, 0.0f, s_fGool * 0.5f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXVECTOR3(100.0f, 0.0f, 100.0f + 1000.0f));
			pField->SetBlock(100, static_cast<int>(s_fGool / 100.0f) + 1000);
			pField->SetTexture("data/TEXTURE/Load_000.png");

			// ステージ読み込み
			Load(s_aStage);
		}
		//============================================
		// デストラクタ
		//============================================
		CStage_001::~CStage_001()
		{

			CManager* pManager = CManager::GetInstance();	// マネージャー
			CSound* pSound = pManager->GetSound();			// サウンド
			pSound->StopSound(CSound::SOUND_LABEL::SOUND_STAGE_00);	// BGMを止める

			CPlayer* pPlayer = m_gameData->GetPlayer();	// プレイヤー取得
			CPlayer::ActivityStrategy* pPlActiv = pPlayer->GetActivity();	// 行動ストラテジー取得

			pPlActiv->SetInUP(true);		// 上入力設定
			pPlActiv->SetInDown(true);		// 下入力設定
			pPlActiv->SetInLeft(true);		// 左入力設定
			pPlActiv->SetInRight(true);	// 右入力設定
		}
		//============================================
		// 更新
		//============================================
		nsPrev::CBase* CStage_001::Update()
		{

			

			return CStage_Base::Update();;
		}
		void CStage_001::Draw() const
		{
		}
		//============================================
		// デストラクタ
		//============================================
		bool CStage_001::GetPose()
		{

			CStage_Base::Draw();

			return m_bPose;
		}

		//============================================
		// 生成
		//============================================
		template<>
		nsPrev::CBase* CBase::makeScene<CStage_001>() {
			nsPrev::CBase* p = new CStage_001(this);
			// ここでゲームマネージャーのネクストに生成したインスタンスを渡す

			return p;
		}
	}
}