#pragma once

#include "external/glad/glad.h"
#include <GLFW/glfw3.h>

#include <string>

//! \brief Namespace containing a few helpers for the EDA221 labs.
namespace eda221
{
	//! \brief Formalise mapping between an OpenGL VAO attribute binding,
	//!        and the meaning of that attribute.
	enum class shader_bindings : unsigned int{
		vertices = 0u,
		normals,
		texcoords,
		tangents,
		binormals
	};

	//! \brief Contains the data for a mesh in OpenGL.
	struct mesh_data {
		GLuint vao;        //!< OpenGL name of the Vertex Array Object
		GLuint bo;         //!< OpenGL name of the Buffer Object
		GLuint ibo;        //!< OpenGL name of the Buffer Object for indices
		size_t indices_nb; //!< number of indices stored in ibo
	};

	//! \brief Load a PNG image into an OpenGL 2D-texture.
	//!
	//! @param [in] filename of the PNG image, relative to the `textures`
	//!             folder within the `resources` folder.
	//! @return the name of the OpenGL 2D-texture
	GLuint loadTexture2D(std::string const& filename);

	//! \brief Create an OpenGL program consisting of a vertex and a
	//!        fragment shader.
	//!
	//! @param [in] vert_shader_source_path of the vertex shader source
	//!             code, relative to the `shaders/EDA221` folder
	//! @param [in] frag_shader_source_path of the fragment shader source
	//!             code, relative to the `shaders/EDA221` folder
	//! @return the name of the OpenGL shader program
	GLuint createProgram(std::string const& vert_shader_source_path,
	                     std::string const& frag_shader_source_path);
}
