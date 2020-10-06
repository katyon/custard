#pragma once

#include	"directxmath.h"

class Title
{
public:
	DirectX::XMMATRIX view;
	DirectX::XMMATRIX projection;
	DirectX::XMFLOAT4 light_direction;


	char    str[128];
	char    push[128];
	int     flash_timer;

	void	Initialize();
	void	Release();
	void	Update();
	void	Render();


	static Title& getInstance()
	{
		static Title instance;
		return	instance;
	}
};

#define	TITLE	Title::getInstance()
