#include <GL/glut.h>
#include "../Math Utilities/vector2d.h"
#include "../Common/FXTypes.h"



inline void DrawLine(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1);
inline void DrawLine(vector2d point1, vector2d point2);

inline void DrawLine(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, float alpha);
inline void DrawLine(vector2d point1, vector2d point2, float alpha);

inline void DrawLine(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, int red, int green, int blue, float alpha);
inline void DrawLine(vector2d point1, vector2d point2, int red, int green, int blue, float alpha);


inline void DrawTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2);
inline void DrawTriangle(vector2d point1, vector2d point2, vector2d point3);

inline void DrawTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2, float alpha);
inline void DrawTriangle(vector2d point1, vector2d point2, vector2d point3, float alpha);

inline void DrawTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2, int red, int green, int blue, float alpha);
inline void DrawTriangle(vector2d point1, vector2d point2, vector2d point3, int red, int green, int blue, float alpha);