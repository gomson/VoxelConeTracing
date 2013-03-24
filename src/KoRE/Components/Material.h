﻿/*
  Copyright (c) 2012 The KoRE Project

  This file is part of KoRE.

  KoRE is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  KoRE is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with KoRE.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef KORE_SRC_KORE_COMPONENTS_MATERIAL_H_
#define KORE_SRC_KORE_COMPONENTS_MATERIAL_H_

#include "KoRE/Common.h"
#include "KoRE/Components/SceneNodeComponent.h"

namespace kore {
  class Material : public SceneNodeComponent {
    friend class SceneLoader;

  public:
    explicit Material();
    virtual ~Material();

    /*! \brief Appends a new value to the Material. The method creates and
               appends a new ShaderData-instance to the component's shaderData-
               list with the provided information.
        \param dataType The openGL-datatype of this value (e.g. GL_FLOAT3).
        \param name The (unique) name of the material-parameter
                    (e.g. "diffuse reflectivity").
        \param value The value of the material-parameter. This has to be
                     a pointer to an heap-allocated object. */
    void addValue(const std::string& name,
                  const GLuint dataType,
                  void* value);

    /*! \brief Sets the value of a material-parameter.
        \param name The name of the parameter (e.g. "diffuse reflectivity").
        \param value A pointer to the memory with the new value. */
    template<typename ValueT>
    void setValue(const std::string& name,
                  const GLuint dataType,
                  const ValueT& value);

    /*! \brief Returns true, if there is a material-parameter with the provided
               name. */
    bool hasValue(const std::string& name);

  private:
    ShaderData* getValue(const std::string& name);
  };
}

#endif  // KORE_SRC_KORE_COMPONENTS_MATERIAL_H_
