# 🌀 Interactive OpenGL Transformations  
**Authors:** DePaz & Dela Cruz  
**Language:** C++ with OpenGL and GLUT  

---

## 🎯 Overview
This program demonstrates **interactive transformations** in OpenGL using vertex arrays.  
It displays a set of colorful triangles that continuously rotate, and allows the user to:
- Zoom in and out using the keyboard  
- Adjust the rotation speed dynamically  

The project applies key OpenGL transformation functions such as:
- `glPushMatrix()` and `glPopMatrix()` for isolating transformations  
- `glScalef()` for zooming  
- `glRotatef()` for rotation  
- `glutPostRedisplay()` for continuous animation refresh  

---

## 🧩 Features
| Key | Function | Description |
|-----|-----------|-------------|
| **L** | Zoom In | Increases the size of the triangles |
| **M** | Zoom Out | Decreases the size of the triangles |
| **+** | Speed Up | Increases the rotation speed |
| **-** | Slow Down | Decreases the rotation speed |

---

## ⚙️ Requirements
- **C++ compiler** (e.g., GCC, MSVC, or Visual Studio 2022)
- **OpenGL** and **GLUT** libraries installed

For Windows users, include:
```cpp
#include <GL/glut.h>
#include <GLUT/glut.h> //for Mac users


