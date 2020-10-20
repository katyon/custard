#pragma once

#include	"directxmath.h"

#define	pGame	Game::getInstance()
class Game
{
public:
	DirectX::XMMATRIX view;
	DirectX::XMMATRIX projection;
	DirectX::XMFLOAT4 light_direction;

	char    SCORE[128];
	char    str[128];

	char    D[3];
	char    F[3];
	char    J[3];
	char    K[3];

	int     score = 0;

	bool    createFlg = false;
	int     createTimer = 0;

	void	Initialize();
	void	Release();
	bool	Update();
	void	Render();


	static Game& getInstance()
	{
		static Game instance;
		return	instance;
	}
};