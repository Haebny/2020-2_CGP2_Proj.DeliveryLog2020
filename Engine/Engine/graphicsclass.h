#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_ 

#include "d3dclass.h"
#include "cameraclass.h"
#include "modelclass.h"
#include "lightshaderclass.h"
#include "lightclass.h"
#include "textureshaderclass.h"
#include "bitmapclass.h"
#include "textclass.h"

#include <vector>
using namespace std;

// Globals
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = false;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass {
private:
	struct Model
	{
		ModelClass* model;
		char* obj_path;
		WCHAR* tex_path;
		char* name;
	};

public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame(int, int, int, int, float);

public:
	int m_input;

private:
	bool Render(float);

private:
	CameraClass* m_Camera;
	D3DClass* m_D3D;
	vector<Model> m_Models;
	Model dog, cat, wood, floor;
	LightShaderClass* m_LightShader;
	LightClass* m_Light;
	LightClass *m_Light2, *m_Light3, *m_Light4;
	TextureShaderClass* m_TextureShader;
	BitmapClass* m_Bitmap;
	TextClass* m_Text;
};

#endif 