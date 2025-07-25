//============================================
//
// 光源[light.h]
// Author:Uedakou
// 
//============================================
#ifndef _LIGHT_H_
#define _LIGHT_H_
#include "main.h"	

#define MAX_LIGHT (3)	// 光源生成数
class CLight
{
public:
	CLight();
	~CLight();
	HRESULT Init();	// 初期化
	void Uninit();	// 終了
	void Update();	// 更新
private:
	D3DLIGHT9 m_light[MAX_LIGHT];	// 光源
};




#endif // _LIGHT_H_