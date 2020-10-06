#pragma once

#include	"directxmath.h"

class Result
{
public:
	//DirectX::XMMATRIX view;
	//DirectX::XMMATRIX projection;
	//DirectX::XMFLOAT4 light_direction;

	char    str[128];
	char    comment[128];

	void	Initialize();
	void	Release();
	void	Update();
	void	Render();


	static Result& getInstance()
	{
		static Result instance;
		return	instance;
	}
};

#define	RESULT	Result::getInstance()
