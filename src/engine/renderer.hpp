#pragma once

#include <GL/glew.h>

#include "opengl/glwrappers.hpp"
#include "../math/math.hpp"
#include "../game/combat/camera.hpp"

class Sprite;

class Renderer {

public:
	Renderer();

	void clear() const;
	void drawLine_fast(ScreenCoord v1, ScreenCoord v2, Colour colour);
	void drawLine(ScreenCoord v1, ScreenCoord v2, Colour colour);
	void drawRect_fast(ScreenCoord v, int width, int height, Colour colour);
	void drawRect(ScreenCoord v, int width, int height, Colour colour);
	void drawTexture(ScreenCoord v, int width, int height, const Texture& texture);
	void drawSprite_fast(const Sprite& sprite);
	void drawSprite(const Sprite& sprite);
	void setAlpha(float a);
<<<<<<< HEAD
	Camera camera;

=======
	void setRectAlpha(float a) { rect_alpha = a; }
>>>>>>> 9a81c511c2697c677aaa28d3bb7f622b33500205
private:
	void drawTriangles(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
	void drawLines(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
	void drawLineStrip(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
	void draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader, GLenum type) const;

	// static shaders for sprite and solid fill drawing
	Shader basicShader;
	Shader textureShader;

	float rect_alpha = 1;
	float alpha = 1;


	void initRectangleData();
	void initLineData();
	GLuint rectangleVAO_;
	GLuint lineVAO_;
};