//===========================================
// 
// チュートリアルステージ[stage_001.h]
// Auther:UedaKou
// 
//===========================================
#ifndef _STAGE_BASE_H_
#define _STAGE_BASE_H_
#include "../scene_game.h"	// シーンゲームベース
#include "./../../../base/pch.h"	// プリコンパイル

class CObject2D;
namespace Scene {
	namespace Game {
		class CStage_Base : public CBase
		{
		public:
			CStage_Base(CBase* game);
			virtual ~CStage_Base();
			virtual nsPrev::CBase* Update()	override;
			virtual void Draw() const override;

			virtual bool GetPose()override;
		protected:
			// 更新描画
			class Stage_Strategy
			{
			public:
				Stage_Strategy(CStage_Base* pPrimary) : m_pPrimary(pPrimary) {}	// コンストラクタ
				virtual ~Stage_Strategy() { m_pPrimary = nullptr; };
				virtual Stage_Strategy* update(nsPrev::CBase*& owner) = 0;
				CStage_Base* m_pPrimary;	// 親
			};
			// プレイ状態
			class Stage_Play_Strategy : public Stage_Strategy
			{
			public:
				Stage_Play_Strategy(CStage_Base* pPrimary);
				virtual ~Stage_Play_Strategy() {};
				virtual Stage_Strategy* update(nsPrev::CBase*& owner);
			};
			// ゴール状態
			class Stage_Goal_Strategy : public Stage_Strategy
			{
			public:
				enum class SelectGoal {
					StageSelect = 0,	// ステージセレクト
					ReTry,				// リスタート
					MAX,
				};// セレクト種類
				Stage_Goal_Strategy(CStage_Base* pPrimary);
				virtual ~Stage_Goal_Strategy();
				virtual Stage_Strategy* update(nsPrev::CBase*& owner);
				int m_nSelect;
				int m_nSelectOld;

				static const D3DXVECTOR3 s_SelectPos;	// セレクト位置
				static const D3DXVECTOR3 s_SelectSiz;	// セレクト大きさ
				static const D3DXVECTOR3 s_PopupPos;	// セレクト位置
				static const D3DXVECTOR3 s_PopupSiz;	// セレクト大きさ

			};
			CObject2D* m_pGoal_Strategy_Select[static_cast<int>(Stage_Goal_Strategy::SelectGoal::MAX)];	// セレクト
			CObject2D* m_pGoal_Strategy_SelectBG;	// セレクト
			CObject2D* m_pGoal_Strategy_GoalPopup;	// ポップアップ
			CObject2D* m_pGoal_Strategy_BG;	// 背景

			// 死亡状態
			class Stage_Death_Strategy : public Stage_Strategy
			{
			public:
				enum class SelectGoal {
					StageSelect = 0,	// ステージセレクト
					ReTry,				// リスタート
					MAX,
				};// セレクト種類
				Stage_Death_Strategy(CStage_Base* pPrimary);
				virtual ~Stage_Death_Strategy();
				virtual Stage_Strategy* update(nsPrev::CBase*& owner);
				int m_nPLMotionCnt;
				int m_nSelect;
				int m_nSelectOld;
				static const int s_nPLMotionCnt;
				static const D3DXVECTOR3 s_SelectPos;	// セレクト位置
				static const D3DXVECTOR3 s_SelectSiz;	// セレクト大きさ
				static const D3DXVECTOR3 s_PopupPos;	// セレクト位置
				static const D3DXVECTOR3 s_PopupSiz;	// セレクト大きさ

			};
			CObject2D* m_pDeath_Strategy_Select[static_cast<int>(Stage_Death_Strategy::SelectGoal::MAX)];	// セレクト
			CObject2D* m_pDeath_Strategy_SelectBG;	// セレクト
			CObject2D* m_pDeath_Strategy_GoalPopup;	// ポップアップ
			CObject2D* m_pDeath_Strategy_BG;	// 背景

			Stage_Strategy* m_pStrategy;	// 更新ストラテジ

			// 関数
			void Load(const string& filePath);	// ロード

			// メンバ変数設定
			int m_nNumScroll;	// スクロール取得数
			int m_nNumScrollOld;	// 旧スクロール取得数
			bool m_bPose;	// ポーズ状態
			bool m_bCameraFollowPlayer;	// カメラがプレイヤーを追従するかそうか
			float m_fCameraRot;		// カメラの角度
			float m_fCameraRange;	// カメラ距離
			float m_fGool;	// 距離
			CObject2D* m_pNumScroll[static_cast<int>(CGameData::Stage::MAX)];	// スクロール取得数表示


		private:
			// メンバ変数の初期値
			static constexpr float s_fCameraRot = 2.25f;	// 初期プレイヤーからのカメラの角度
			static constexpr float s_fCameraRange = 115.0f;
			static const D3DXVECTOR3 NumScrollPos;	// 取得アイテム取得数表示位置(一番目)
			static const D3DXVECTOR3 NumScrollSiz;	// 取得アイテム取得数表示大きさ
		};
	}
}
#endif // !_STAGE_TUTORIAL_H_
