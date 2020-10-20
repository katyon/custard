#include	"sprite.h"

#include	"assert.h"

#include	"framework.h"
#include	"resouce_manager.h"

using namespace DirectX;

//************************************************************************//
//
//	class Sprite
//
//************************************************************************//

void Sprite::_init(ID3D11Device* device, const wchar_t* texName,
	const char* vsName, D3D11_INPUT_ELEMENT_DESC* inputElementDescs, int numElement,
	const char* psName)
{
	HRESULT	hr;

	//	�����_��`
	Vertex vertices[4] = {
		{ XMFLOAT3(-0.5f, +0.5f, .0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f), XMFLOAT2(0.0f, 0.0f) },
		{ XMFLOAT3(+0.5f, +0.5f, .0f), XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f), XMFLOAT2(1.0f, 0.0f) },
		{ XMFLOAT3(-0.5f, -0.5f, .0f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f), XMFLOAT2(0.0f, 1.0f) },
		{ XMFLOAT3(+0.5f, -0.5f, .0f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f), XMFLOAT2(1.0f, 1.0f) },
	};

	//	���_�o�b�t�@�쐬
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(vertices);	//	���� sizeof(Vertex) * 4
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;
	hr = device->CreateBuffer(&bd, &InitData, &vertex_buffer);
	if (FAILED(hr))		assert(0 && "���_�o�b�t�@�쐬���s");


	//	���_�V�F�[�_�[/���̓��C�A�E�g�̐���
	if (!ResourceManager::LoadVertexShaders(device,
		vsName, inputElementDescs, numElement,
		&vertex_shader, &input_layout))
	{
		assert(0 && "���_�V�F�[�_�[or���̓��C�A�E�g�쐬���s");
	}

	//	�s�N�Z���V�F�[�_�[�쐬
	if (!ResourceManager::LoadPixelShaders(device, psName, &pixel_shader))
	{
		assert(0 && "�s�N�Z���V�F�[�_�[�쐬���s");
	}


	//	���X�^���C�U�[�X�e�[�g�̍쐬
	D3D11_RASTERIZER_DESC rsDesc;
	ZeroMemory(&rsDesc, sizeof(rsDesc));
	rsDesc.FillMode = D3D11_FILL_SOLID;
	rsDesc.CullMode = D3D11_CULL_NONE;
	rsDesc.DepthClipEnable = FALSE;
	hr = device->CreateRasterizerState(&rsDesc, &rasterizer_state);
	if (FAILED(hr))	assert(0 && "���X�^���C�U�[�쐬���s");


	//	�e�N�X�`���ǂݍ���
	if (!ResourceManager::LoadShaderResourceView(
		device, texName, &shader_resource_view, &texture2d_desc))
	{
		assert(0 && "�e�N�X�`���ǂݍ��ݎ��s");
	}


	//	�T���v���[�X�e�[�g�̍쐬
	D3D11_SAMPLER_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;	// 
	sd.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;		// 
	sd.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;		//
	sd.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;		//
	sd.MaxAnisotropy = 16;								//
	sd.ComparisonFunc = D3D11_COMPARISON_ALWAYS;			//
	sd.MaxLOD = D3D11_FLOAT32_MAX;				//
	hr = device->CreateSamplerState(&sd, &sampler_state);
	if (FAILED(hr))	assert(0 && "�T���v���[�X�e�[�g�쐬���s");


	//	�[�x�X�e���V��State�̍쐬
	D3D11_DEPTH_STENCIL_DESC dssDesc;
	ZeroMemory(&dssDesc, sizeof(dssDesc));
	dssDesc.DepthEnable = FALSE;				//	�[�x�e�X�g����
	dssDesc.StencilEnable = FALSE;				//	���łɃX�e���V��������
	hr = device->CreateDepthStencilState(&dssDesc, &depth_stencil_state);
	if (FAILED(hr))		assert(0 && "�[�x�X�e���V��State�쐬���s");
}

Sprite::~Sprite()
{
	if (depth_stencil_state)	depth_stencil_state->Release();
	if (sampler_state)			sampler_state->Release();
	ResourceManager::ReleaseShaderResourceView(shader_resource_view);
	shader_resource_view = nullptr;
	texture2d_desc = nullptr;

	if (rasterizer_state)		rasterizer_state->Release();

	ResourceManager::ReleasePixelShaders(pixel_shader);
	pixel_shader = nullptr;

	ResourceManager::ReleaseVertexShaders(vertex_shader, input_layout);
	vertex_shader = nullptr;
	input_layout = nullptr;

	if (vertex_buffer)			vertex_buffer->Release();
}


void Sprite::Render(ID3D11DeviceContext* context)
{

	// ���_�o�b�t�@�̃o�C���h
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	context->IASetVertexBuffers(0, 1, &vertex_buffer, &stride, &offset);

	//	�v���~�e�B�u���[�h�̐ݒ�
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//	���̓��C�A�E�g�̃o�C���h
	context->IASetInputLayout(input_layout);

	//	���X�^���C�U�[�̐ݒ�
	context->RSSetState(rasterizer_state);

	//	�V�F�[�_�[(2��)�̐ݒ�
	context->VSSetShader(vertex_shader, nullptr, 0);
	context->PSSetShader(pixel_shader, nullptr, 0);

	//	�v���~�e�B�u�̕`��
	context->Draw(4, 0);
}


void Sprite::Render(ID3D11DeviceContext* context,
	float dx, float dy, float dw, float dh,
	float sx, float sy, float sw, float sh,
	DirectX::XMFLOAT4 col
)
{
	Vertex vertices[4] = {
		{ XMFLOAT3(dx,    dy,    .0f), col, XMFLOAT2(sx,    sy) },
		{ XMFLOAT3(dx + dw, dy,    .0f), col, XMFLOAT2(sx + sw, sy) },
		{ XMFLOAT3(dx,    dy + dh, .0f), col, XMFLOAT2(sx,    sy + sh) },
		{ XMFLOAT3(dx + dw, dy + dh, .0f), col, XMFLOAT2(sx + sw, sy + sh) },
	};

	Vertex verticesNDC[4];
	for (int n = 0; n < 4; n++)
	{
		//	NDC�ϊ�
		verticesNDC[n].pos.x = (vertices[n].pos.x / SCREEN_WIDTH) * 2.0f - 1.0f;
		verticesNDC[n].pos.y = -(vertices[n].pos.y / SCREEN_HEIGHT) * 2.0f + 1.0f;
		verticesNDC[n].pos.z = .0f;
		verticesNDC[n].color = vertices[n].color;

		//	UV���W���K��
		verticesNDC[n].texcoord.x = vertices[n].texcoord.x / texture2d_desc->Width;
		verticesNDC[n].texcoord.y = vertices[n].texcoord.y / texture2d_desc->Height;
	}

	D3D11_MAPPED_SUBRESOURCE sub_resource;
	context->Map(vertex_buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &sub_resource);
	memcpy(sub_resource.pData, verticesNDC, sizeof(verticesNDC));
	context->Unmap(vertex_buffer, 0);

	// ���_�o�b�t�@�̃o�C���h
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	context->IASetVertexBuffers(0, 1, &vertex_buffer, &stride, &offset);

	//	�v���~�e�B�u���[�h�̐ݒ�
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//	���̓��C�A�E�g�̃o�C���h
	context->IASetInputLayout(input_layout);

	//	���X�^���C�U�[�̐ݒ�
	context->RSSetState(rasterizer_state);

	//	�V�F�[�_�[(2��)�̐ݒ�
	context->VSSetShader(vertex_shader, nullptr, 0);
	context->PSSetShader(pixel_shader, nullptr, 0);

	//	�V�F�[�_�[���\�[�X�r���[�y�уT���v���[�X�e�[�g�̐ݒ�
	context->PSSetShaderResources(0, 1, &shader_resource_view);
	context->PSSetSamplers(0, 1, &sampler_state);

	//	�[�x�e�X�g�̐ݒ�
	context->OMSetDepthStencilState(depth_stencil_state, 0);

	//	�v���~�e�B�u�̕`��
	context->Draw(4, 0);
}


void Sprite::Render(ID3D11DeviceContext* context,
	float dx, float dy, float dw, float dh,
	float sx, float sy, float sw, float sh,
	float angle, XMFLOAT4 col
)
{
	//	�P�ʋ�`��`
	Vertex vertices[4] = {
		{ XMFLOAT3(0.0f, 0.0f, .0f), col, XMFLOAT2(sx,    sy) },
		{ XMFLOAT3(1.0f, 0.0f, .0f), col, XMFLOAT2(sx + sw, sy) },
		{ XMFLOAT3(0.0f, 1.0f, .0f), col, XMFLOAT2(sx,    sy + sh) },
		{ XMFLOAT3(1.0f, 1.0f, .0f), col, XMFLOAT2(sx + sw, sy + sh) },
	};

	//	(dw,dh)�̊g��
	for (int i = 0; i < 4; i++) {
		vertices[i].pos.x *= dw;
		vertices[i].pos.y *= dh;
	}

	//	��]���̕ύX�i��`�����ցj
	for (int i = 0; i < 4; i++) {
		vertices[i].pos.x -= dw / 2.0f;
		vertices[i].pos.y -= dh / 2.0f;
	}

	//	angle�x�̉�]
	float degree = XMConvertToRadians(angle);
	float sn = sinf(degree);
	float cs = cosf(degree);
	for (int i = 0; i < 4; i++) {
		float bx = vertices[i].pos.x;
		float by = vertices[i].pos.y;
		vertices[i].pos.x = bx * cs - by * sn;
		vertices[i].pos.y = bx * sn + by * cs;
	}

	//	��]���̕ύX�i���̈ʒu�ցj
	for (int i = 0; i < 4; i++) {
		vertices[i].pos.x += dw / 2.0f;
		vertices[i].pos.y += dh / 2.0f;
	}

	//	(dx,dy)�̕��s�ړ�
	for (int i = 0; i < 4; i++) {
		vertices[i].pos.x += dx;
		vertices[i].pos.y += dy;
	}

	Vertex verticesNDC[4];
	for (int n = 0; n < 4; n++)
	{
		//	NDC�ϊ�
		verticesNDC[n].pos.x = (vertices[n].pos.x / SCREEN_WIDTH) * 2.0f - 1.0f;
		verticesNDC[n].pos.y = -(vertices[n].pos.y / SCREEN_HEIGHT) * 2.0f + 1.0f;
		verticesNDC[n].pos.z = .0f;
		verticesNDC[n].color = vertices[n].color;

		//	UV���W���K��
		verticesNDC[n].texcoord.x = vertices[n].texcoord.x / texture2d_desc->Width;
		verticesNDC[n].texcoord.y = vertices[n].texcoord.y / texture2d_desc->Height;
	}

	D3D11_MAPPED_SUBRESOURCE sub_resource;
	context->Map(vertex_buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &sub_resource);
	memcpy(sub_resource.pData, verticesNDC, sizeof(verticesNDC));
	context->Unmap(vertex_buffer, 0);

	// ���_�o�b�t�@�̃o�C���h
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	context->IASetVertexBuffers(0, 1, &vertex_buffer, &stride, &offset);

	//	�v���~�e�B�u���[�h�̐ݒ�
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//	���̓��C�A�E�g�̃o�C���h
	context->IASetInputLayout(input_layout);

	//	���X�^���C�U�[�̐ݒ�
	context->RSSetState(rasterizer_state);

	//	�V�F�[�_�[(2��)�̐ݒ�
	context->VSSetShader(vertex_shader, nullptr, 0);
	context->PSSetShader(pixel_shader, nullptr, 0);

	//	�V�F�[�_�[���\�[�X�r���[�y�уT���v���[�X�e�[�g�̐ݒ�
	context->PSSetShaderResources(0, 1, &shader_resource_view);
	context->PSSetSamplers(0, 1, &sampler_state);

	//	�[�x�e�X�g�̐ݒ�
	context->OMSetDepthStencilState(depth_stencil_state, 0);

	//	�v���~�e�B�u�̕`��
	context->Draw(4, 0);
}






//************************************************************************//
//
//	class SpriteBatch
//
//************************************************************************//

void SpriteBatch::_init(ID3D11Device* device, const wchar_t* texName,
	const char* vsName, D3D11_INPUT_ELEMENT_DESC* inputElementDescs, int numElement,
	const char* psName, u_int maxInstance)
{
	HRESULT	hr;

	//	�����_��`
	Vertex vertices[4] = {
		{ XMFLOAT3(0.0f, 0.0f, .0f), XMFLOAT2(0.0f, 0.0f) },
		{ XMFLOAT3(1.0f, 0.0f, .0f), XMFLOAT2(1.0f, 0.0f) },
		{ XMFLOAT3(0.0f, 1.0f, .0f), XMFLOAT2(0.0f, 1.0f) },
		{ XMFLOAT3(1.0f, 1.0f, .0f), XMFLOAT2(1.0f, 1.0f) },
	};

	//	���_�o�b�t�@�쐬
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_IMMUTABLE;
	bd.ByteWidth = sizeof(vertices);	//	���� sizeof(Vertex) * 4
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;
	hr = device->CreateBuffer(&bd, &InitData, &vertex_buffer);
	if (FAILED(hr))		assert(0 && "���_�o�b�t�@�쐬���s");


	//	���_�V�F�[�_�[/���̓��C�A�E�g�̐���
	if (!ResourceManager::LoadVertexShaders(device,
		vsName, inputElementDescs, numElement,
		&vertex_shader, &input_layout))
	{
		assert(0 && "���_�V�F�[�_�[or���̓��C�A�E�g�쐬���s");
	}

	//	�s�N�Z���V�F�[�_�[�쐬
	if (!ResourceManager::LoadPixelShaders(device, psName, &pixel_shader))
	{
		assert(0 && "�s�N�Z���V�F�[�_�[�쐬���s");
	}

	//	�C���X�^���X����
	instances = new Instance[MAX_INSTANCE];
	ZeroMemory(instances, sizeof(Instance) * MAX_INSTANCE);

	ZeroMemory(&bd, sizeof(bd));
	bd.ByteWidth = sizeof(Instance) * MAX_INSTANCE;
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = instances;
	hr = device->CreateBuffer(&bd, &InitData, &instance_buffer);
	if (FAILED(hr))		assert(0 && "�C���X�^���X�o�b�t�@�쐬���s");

	//	���X�^���C�U�[�X�e�[�g�̍쐬
	D3D11_RASTERIZER_DESC rsDesc;
	ZeroMemory(&rsDesc, sizeof(rsDesc));
	rsDesc.FillMode = D3D11_FILL_SOLID;
	rsDesc.CullMode = D3D11_CULL_NONE;
	rsDesc.DepthClipEnable = FALSE;
	hr = device->CreateRasterizerState(&rsDesc, &rasterizer_state);
	if (FAILED(hr))	assert(0 && "���X�^���C�U�[�쐬���s");


	//	�e�N�X�`���ǂݍ���
	if (!ResourceManager::LoadShaderResourceView(
		device, texName, &shader_resource_view, &texture2d_desc))
	{
		assert(0 && "�e�N�X�`���ǂݍ��ݎ��s");
	}


	//	�T���v���[�X�e�[�g�̍쐬
	D3D11_SAMPLER_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;	// 
	sd.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;		// 
	sd.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;		//
	sd.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;		//
	sd.MaxAnisotropy = 16;								//
	sd.ComparisonFunc = D3D11_COMPARISON_ALWAYS;			//
	sd.MaxLOD = D3D11_FLOAT32_MAX;				//
	hr = device->CreateSamplerState(&sd, &sampler_state);
	if (FAILED(hr))	assert(0 && "�T���v���[�X�e�[�g�쐬���s");


	//	�[�x�X�e���V��State�̍쐬
	D3D11_DEPTH_STENCIL_DESC dssDesc;
	ZeroMemory(&dssDesc, sizeof(dssDesc));
	dssDesc.DepthEnable = FALSE;				//	�[�x�e�X�g����
	dssDesc.StencilEnable = FALSE;				//	���łɃX�e���V��������
	hr = device->CreateDepthStencilState(&dssDesc, &depth_stencil_state);
	if (FAILED(hr))		assert(0 && "�[�x�X�e���V��State�쐬���s");
}

SpriteBatch::~SpriteBatch()
{
	if (depth_stencil_state)	depth_stencil_state->Release();
	if (sampler_state)			sampler_state->Release();
	ResourceManager::ReleaseShaderResourceView(shader_resource_view);
	shader_resource_view = nullptr;
	texture2d_desc = nullptr;

	if (rasterizer_state)		rasterizer_state->Release();

	if (instance_buffer)			instance_buffer->Release();
	if (instances)		delete[]	instances;

	ResourceManager::ReleasePixelShaders(pixel_shader);
	pixel_shader = nullptr;

	ResourceManager::ReleaseVertexShaders(vertex_shader, input_layout);
	vertex_shader = nullptr;
	input_layout = nullptr;

	if (vertex_buffer)			vertex_buffer->Release();
}

bool	SpriteBatch::Reserve(
	float dx, float dy, float dw, float dh,
	float sx, float sy, float sw, float sh,
	float angle, DirectX::XMFLOAT4 col)
{
	if (reserveNum >= MAX_INSTANCE)	return	false;

	//	��]�͋�`�̒�������(�K�v�ɉ����ď����g������)
	float cx = dw * 0.5f, cy = dh * 0.5f;

	FLOAT c = cosf(angle * 0.01745f);
	FLOAT s = sinf(angle * 0.01745f);
	FLOAT w = 2.0f / SCREEN_WIDTH;
	FLOAT h = -2.0f / SCREEN_HEIGHT;
	instances[reserveNum].ndc_transform._11 = w * dw * c;
	instances[reserveNum].ndc_transform._21 = h * dw * s;
	instances[reserveNum].ndc_transform._31 = 0.0f;
	instances[reserveNum].ndc_transform._41 = 0.0f;
	instances[reserveNum].ndc_transform._12 = w * dh * -s;
	instances[reserveNum].ndc_transform._22 = h * dh * c;
	instances[reserveNum].ndc_transform._32 = 0.0f;
	instances[reserveNum].ndc_transform._42 = 0.0f;
	instances[reserveNum].ndc_transform._13 = 0.0f;
	instances[reserveNum].ndc_transform._23 = 0.0f;
	instances[reserveNum].ndc_transform._33 = 1.0f;
	instances[reserveNum].ndc_transform._43 = 0.0f;
	instances[reserveNum].ndc_transform._14 = w * (-cx * c + -cy * -s + cx + dx) - 1.0f;
	instances[reserveNum].ndc_transform._24 = h * (-cx * s + -cy * c + cy + dy) + 1.0f;
	instances[reserveNum].ndc_transform._34 = 0.0f;
	instances[reserveNum].ndc_transform._44 = 1.0f;

	float tw = (float)(texture2d_desc->Width);
	float th = (float)(texture2d_desc->Height);
	instances[reserveNum].texcoord_transform = DirectX::XMFLOAT4(sx / tw, sy / th, sw / tw, sh / th);
	instances[reserveNum].color = col;

	reserveNum++;
	return	true;
}

void	SpriteBatch::Render(ID3D11DeviceContext* context)
{
	if (reserveNum == 0)		return;


	HRESULT hr = S_OK;

	UINT strides[2] = { sizeof(Vertex), sizeof(Instance) };
	UINT offsets[2] = { 0, 0 };
	ID3D11Buffer* vbs[2] = { vertex_buffer, instance_buffer };
	context->IASetVertexBuffers(0, 2, vbs, strides, offsets);

	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	context->IASetInputLayout(input_layout);
	context->OMSetDepthStencilState(depth_stencil_state, 1);
	context->RSSetState(rasterizer_state);
	context->VSSetShader(vertex_shader, nullptr, 0);
	context->PSSetShader(pixel_shader, nullptr, 0);
	context->PSSetShaderResources(0, 1, &shader_resource_view);
	context->PSSetSamplers(0, 1, &sampler_state);

	D3D11_MAP map = D3D11_MAP_WRITE_DISCARD;
	D3D11_MAPPED_SUBRESOURCE mapped_buffer;
	hr = context->Map(instance_buffer, 0, map, 0, &mapped_buffer);
	_ASSERT_EXPR(SUCCEEDED(hr), hr_trace(hr));

	memcpy(mapped_buffer.pData, instances, sizeof(Instance) * reserveNum);

	context->Unmap(instance_buffer, 0);

	context->DrawInstanced(4, reserveNum, 0, 0);

	//	�\�񃊃X�g�̃��Z�b�g
	ZeroMemory(instances, sizeof(Instance) * MAX_INSTANCE);
	reserveNum = 0;
}





//************************************************************************//
//
//	class Text
//
//************************************************************************//

Text::Text(ID3D11Device* device, const wchar_t* texName, u_int imageFontSizeW, u_int imageFontSizeH) :
	SpriteBatch(device, texName, MAX_INSTANCES), IMAGE_FONT_SIZE_W(imageFontSizeW), IMAGE_FONT_SIZE_H(imageFontSizeH)
{
	if (IMAGE_FONT_SIZE_H <= 0)	IMAGE_FONT_SIZE_H = IMAGE_FONT_SIZE_W;
	NUM_OF_1_LINE = texture2d_desc->Width / imageFontSizeW;
}

bool	Text::Set(const char* str, float x, float y, float dispSizeW, float dispSizeH)
{
	if (IMAGE_FONT_SIZE_W <= 0)	return false;

	if (dispSizeW <= 0)
	{
		dispSizeW = (float)IMAGE_FONT_SIZE_W;
	}
	if (dispSizeH <= 0)
	{
		dispSizeH = dispSizeW;
	}

	for (int n = 0; str[n] != '\0'; n++)
	{
		char c = str[n];
		float wx = x + dispSizeW * n;
		float wy = y;

		bool ret = Reserve(wx, wy,
			(float)dispSizeW, (float)dispSizeH,
			(float)(c % NUM_OF_1_LINE) * IMAGE_FONT_SIZE_W, (float)(c / NUM_OF_1_LINE) * IMAGE_FONT_SIZE_H,
			(float)IMAGE_FONT_SIZE_W, (float)IMAGE_FONT_SIZE_H);

		if (!ret)	return	false;
	}
	return	true;
}
