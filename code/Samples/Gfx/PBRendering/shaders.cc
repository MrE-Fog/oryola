//-----------------------------------------------------------------------------
// #version:14# machine generated, do not edit!
//-----------------------------------------------------------------------------
#include "Pre.h"
#include "shaders.h"

namespace Oryol {
namespace Shaders {
const char* vs_100_src = 
"#define _POSITION gl_Position\n"
"uniform mat4 modelViewProj;\n"
"uniform mat4 modelView;\n"
"attribute vec4 position;\n"
"attribute vec3 normal;\n"
"varying vec3 viewSpacePos;\n"
"varying vec3 viewSpaceNormal;\n"
"void main() {\n"
"_POSITION = modelViewProj * position;\n"
"viewSpacePos = vec3(modelView * position);\n"
"viewSpaceNormal = vec3(modelView * vec4(normal, 0.0));\n"
"}\n"
;
const char* fs_100_src = 
"precision mediump float;\n"
"#define _COLOR gl_FragColor\n"
"uniform vec3 lightVec;\n"
"varying vec3 viewSpacePos;\n"
"varying vec3 viewSpaceNormal;\n"
"const float PI = 3.14159265358979323846;\n"
"const float c = 0.4;\n"
"float square(float x) {\n"
"return x * x;\n"
"}\n"
"float TrowbridgeReitz(float c, float n_dot_h) {\n"
"float cSquared = c * c;\n"
"return square(cSquared / (n_dot_h*n_dot_h*(cSquared - 1.0) + 1.0));\n"
"}\n"
"vec3\n"
"D_TrowbridgeReitz(vec3 L, vec3 V, vec3 N) {\n"
"vec3 H = normalize(L + V);\n"
"float D = TrowbridgeReitz(c, dot(N, H));\n"
"D *= 1.0 / (c*c*PI);\n"
"return vec3(D);\n"
"}\n"
"float GGX(float c, float cosThetaM) {\n"
"float cosSquared = cosThetaM * cosThetaM;\n"
"float tanSquared = (1.0 - cosSquared) / cosSquared;\n"
"return (1.0 / PI) * square(c / (cosSquared * (c * c + tanSquared)));\n"
"}\n"
"vec3 D_GGX(vec3 L, vec3 V, vec3 N) {\n"
"vec3 H = normalize(L + V);\n"
"float D = GGX(c, dot(N, H));\n"
"return vec3(D);\n"
"}\n"
"const float m = 0.25;\n"
"float Gsch(float v, float m) {\n"
"float k = sqrt(2.0 * m * m / PI);\n"
"return v > 0.0 ? v / (v - k * v + k) : 0.0;\n"
"}\n"
"vec3\n"
"G_Schlick(vec3 L, vec3 V, vec3 N) {\n"
"float n_dot_l = dot(N, L);\n"
"float n_dot_v = dot(N, V);\n"
"float G = Gsch(n_dot_l, m) * Gsch(n_dot_v, m);\n"
"return vec3(G);\n"
"}\n"
"float Gue4(float v, float k) {\n"
"return v > 0.0 ? v / (v * (1.0 - k) + k) : 0.0;\n"
"}\n"
"vec3\n"
"G_UE4(vec3 L, vec3 V, vec3 N) {\n"
"float k = ((c + 1.0) * (c + 1.0)) / 8.0;\n"
"float n_dot_l = dot(N, L);\n"
"float n_dot_v = dot(N, V);\n"
"float G = Gue4(n_dot_l, k) * Gue4(n_dot_v, k);\n"
"return vec3(G);\n"
"}\n"
"vec4 gamma(vec4 c) {\n"
"return vec4(pow(c.xyz, vec3(1.0/2.2)), c.w);\n"
"}\n"
"void main() {\n"
"const vec3 eyePos = vec3(0.0, 0.0, 0.0);\n"
"vec3 N = normalize(viewSpaceNormal);\n"
"vec3 V = normalize(eyePos - viewSpacePos);\n"
"vec3 L = lightVec.xyz;\n"
"float n_dot_l = dot(N, L);\n"
"float n_dot_v = dot(N, V);\n"
"vec3 D = D_GGX(L, V, N);\n"
"vec3 G = G_UE4(L, V, N);\n"
"vec3 spec = D * G;\n"
"vec3 c = spec;\n"
"_COLOR = gamma(vec4(c, 1.0));\n"
"}\n"
;
const char* vs_120_src = 
"#version 120\n"
"#define _POSITION gl_Position\n"
"uniform mat4 modelViewProj;\n"
"uniform mat4 modelView;\n"
"attribute vec4 position;\n"
"attribute vec3 normal;\n"
"varying vec3 viewSpacePos;\n"
"varying vec3 viewSpaceNormal;\n"
"void main() {\n"
"_POSITION = modelViewProj * position;\n"
"viewSpacePos = vec3(modelView * position);\n"
"viewSpaceNormal = vec3(modelView * vec4(normal, 0.0));\n"
"}\n"
;
const char* fs_120_src = 
"#version 120\n"
"#define _COLOR gl_FragColor\n"
"uniform vec3 lightVec;\n"
"varying vec3 viewSpacePos;\n"
"varying vec3 viewSpaceNormal;\n"
"const float PI = 3.14159265358979323846;\n"
"const float c = 0.4;\n"
"float square(float x) {\n"
"return x * x;\n"
"}\n"
"float TrowbridgeReitz(float c, float n_dot_h) {\n"
"float cSquared = c * c;\n"
"return square(cSquared / (n_dot_h*n_dot_h*(cSquared - 1.0) + 1.0));\n"
"}\n"
"vec3\n"
"D_TrowbridgeReitz(vec3 L, vec3 V, vec3 N) {\n"
"vec3 H = normalize(L + V);\n"
"float D = TrowbridgeReitz(c, dot(N, H));\n"
"D *= 1.0 / (c*c*PI);\n"
"return vec3(D);\n"
"}\n"
"float GGX(float c, float cosThetaM) {\n"
"float cosSquared = cosThetaM * cosThetaM;\n"
"float tanSquared = (1.0 - cosSquared) / cosSquared;\n"
"return (1.0 / PI) * square(c / (cosSquared * (c * c + tanSquared)));\n"
"}\n"
"vec3 D_GGX(vec3 L, vec3 V, vec3 N) {\n"
"vec3 H = normalize(L + V);\n"
"float D = GGX(c, dot(N, H));\n"
"return vec3(D);\n"
"}\n"
"const float m = 0.25;\n"
"float Gsch(float v, float m) {\n"
"float k = sqrt(2.0 * m * m / PI);\n"
"return v > 0.0 ? v / (v - k * v + k) : 0.0;\n"
"}\n"
"vec3\n"
"G_Schlick(vec3 L, vec3 V, vec3 N) {\n"
"float n_dot_l = dot(N, L);\n"
"float n_dot_v = dot(N, V);\n"
"float G = Gsch(n_dot_l, m) * Gsch(n_dot_v, m);\n"
"return vec3(G);\n"
"}\n"
"float Gue4(float v, float k) {\n"
"return v > 0.0 ? v / (v * (1.0 - k) + k) : 0.0;\n"
"}\n"
"vec3\n"
"G_UE4(vec3 L, vec3 V, vec3 N) {\n"
"float k = ((c + 1.0) * (c + 1.0)) / 8.0;\n"
"float n_dot_l = dot(N, L);\n"
"float n_dot_v = dot(N, V);\n"
"float G = Gue4(n_dot_l, k) * Gue4(n_dot_v, k);\n"
"return vec3(G);\n"
"}\n"
"vec4 gamma(vec4 c) {\n"
"return vec4(pow(c.xyz, vec3(1.0/2.2)), c.w);\n"
"}\n"
"void main() {\n"
"const vec3 eyePos = vec3(0.0, 0.0, 0.0);\n"
"vec3 N = normalize(viewSpaceNormal);\n"
"vec3 V = normalize(eyePos - viewSpacePos);\n"
"vec3 L = lightVec.xyz;\n"
"float n_dot_l = dot(N, L);\n"
"float n_dot_v = dot(N, V);\n"
"vec3 D = D_GGX(L, V, N);\n"
"vec3 G = G_UE4(L, V, N);\n"
"vec3 spec = D * G;\n"
"vec3 c = spec;\n"
"_COLOR = gamma(vec4(c, 1.0));\n"
"}\n"
;
const char* vs_150_src = 
"#version 150\n"
"#define _POSITION gl_Position\n"
"uniform mat4 modelViewProj;\n"
"uniform mat4 modelView;\n"
"in vec4 position;\n"
"in vec3 normal;\n"
"out vec3 viewSpacePos;\n"
"out vec3 viewSpaceNormal;\n"
"void main() {\n"
"_POSITION = modelViewProj * position;\n"
"viewSpacePos = vec3(modelView * position);\n"
"viewSpaceNormal = vec3(modelView * vec4(normal, 0.0));\n"
"}\n"
;
const char* fs_150_src = 
"#version 150\n"
"#define _COLOR _FragColor\n"
"uniform vec3 lightVec;\n"
"in vec3 viewSpacePos;\n"
"in vec3 viewSpaceNormal;\n"
"out vec4 _FragColor;\n"
"const float PI = 3.14159265358979323846;\n"
"const float c = 0.4;\n"
"float square(float x) {\n"
"return x * x;\n"
"}\n"
"float TrowbridgeReitz(float c, float n_dot_h) {\n"
"float cSquared = c * c;\n"
"return square(cSquared / (n_dot_h*n_dot_h*(cSquared - 1.0) + 1.0));\n"
"}\n"
"vec3\n"
"D_TrowbridgeReitz(vec3 L, vec3 V, vec3 N) {\n"
"vec3 H = normalize(L + V);\n"
"float D = TrowbridgeReitz(c, dot(N, H));\n"
"D *= 1.0 / (c*c*PI);\n"
"return vec3(D);\n"
"}\n"
"float GGX(float c, float cosThetaM) {\n"
"float cosSquared = cosThetaM * cosThetaM;\n"
"float tanSquared = (1.0 - cosSquared) / cosSquared;\n"
"return (1.0 / PI) * square(c / (cosSquared * (c * c + tanSquared)));\n"
"}\n"
"vec3 D_GGX(vec3 L, vec3 V, vec3 N) {\n"
"vec3 H = normalize(L + V);\n"
"float D = GGX(c, dot(N, H));\n"
"return vec3(D);\n"
"}\n"
"const float m = 0.25;\n"
"float Gsch(float v, float m) {\n"
"float k = sqrt(2.0 * m * m / PI);\n"
"return v > 0.0 ? v / (v - k * v + k) : 0.0;\n"
"}\n"
"vec3\n"
"G_Schlick(vec3 L, vec3 V, vec3 N) {\n"
"float n_dot_l = dot(N, L);\n"
"float n_dot_v = dot(N, V);\n"
"float G = Gsch(n_dot_l, m) * Gsch(n_dot_v, m);\n"
"return vec3(G);\n"
"}\n"
"float Gue4(float v, float k) {\n"
"return v > 0.0 ? v / (v * (1.0 - k) + k) : 0.0;\n"
"}\n"
"vec3\n"
"G_UE4(vec3 L, vec3 V, vec3 N) {\n"
"float k = ((c + 1.0) * (c + 1.0)) / 8.0;\n"
"float n_dot_l = dot(N, L);\n"
"float n_dot_v = dot(N, V);\n"
"float G = Gue4(n_dot_l, k) * Gue4(n_dot_v, k);\n"
"return vec3(G);\n"
"}\n"
"vec4 gamma(vec4 c) {\n"
"return vec4(pow(c.xyz, vec3(1.0/2.2)), c.w);\n"
"}\n"
"void main() {\n"
"const vec3 eyePos = vec3(0.0, 0.0, 0.0);\n"
"vec3 N = normalize(viewSpaceNormal);\n"
"vec3 V = normalize(eyePos - viewSpacePos);\n"
"vec3 L = lightVec.xyz;\n"
"float n_dot_l = dot(N, L);\n"
"float n_dot_v = dot(N, V);\n"
"vec3 D = D_GGX(L, V, N);\n"
"vec3 G = G_UE4(L, V, N);\n"
"vec3 spec = D * G;\n"
"vec3 c = spec;\n"
"_COLOR = gamma(vec4(c, 1.0));\n"
"}\n"
;
ProgramBundleSetup Main::CreateSetup() {
    ProgramBundleSetup setup("Main");
    setup.AddProgramFromSources(0, ShaderLang::GLSL100, vs_100_src, fs_100_src);
    setup.AddProgramFromSources(0, ShaderLang::GLSL120, vs_120_src, fs_120_src);
    setup.AddProgramFromSources(0, ShaderLang::GLSL150, vs_150_src, fs_150_src);
    setup.AddUniform("modelViewProj", ModelViewProj);
    setup.AddUniform("modelView", ModelView);
    setup.AddUniform("lightVec", LightVec);
    return setup;
}
}
}

