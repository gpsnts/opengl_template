#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <initializer_list> // "inline array"

#include <iostream>
using namespace std;

enum AssignOption {
	DATA,
	POSITION,
	COLOR
};

class Renderer
{
private:
	std::map<std::string, GLuint> vaos;
	std::map<std::string, GLuint> vbos;
	std::map<std::string, GLuint> uniforms_indexes;

	std::map<std::string, std::vector<GLfloat>> data;
	std::map<std::string, std::vector<GLfloat>> positions;
	std::map<std::string, std::vector<GLfloat>> colors;
public:
	Renderer() 
	: vaos(), vbos(), uniforms_indexes(),
		data(), positions(), colors() {};

	std::map<std::string, GLuint> get_vaos();
	std::map<std::string, GLuint> get_vbos();
	std::map<std::string, GLuint> get_uniforms_indexes();

	std::map<std::string, std::vector<GLfloat>> get_data();
	std::map<std::string, std::vector<GLfloat>> get_positions();
	std::map<std::string, std::vector<GLfloat>> get_colors();

	bool set_data(
		AssignOption selected,
		string key_selected,
		std::initializer_list<GLfloat> payload
	);
	// void bind_buffer();
	// void 
};

#endif // __RENDERER_HPP__