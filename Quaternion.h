#pragma once
#include <cmath>
#include "Struct.h"

//加算
Quaternion Add(const Quaternion& q1, const Quaternion& q2);

Quaternion Normalize(const Quaternion& q);

//内積
float Dot(const Quaternion& q1, const Quaternion& q2);

//スカラー倍
Quaternion Multiply(float scalar, const Quaternion& q);

//Quaternionの積
Quaternion Multiply(const Quaternion& q1, const Quaternion& q2);

//単位Quaternion
Quaternion IdentityQuaternion();

//共役Quaternion
Quaternion Conjugate(const Quaternion& quaternion);

//逆Quaternion
Quaternion Inverse(const Quaternion& quaternion);

//長さ(ノルム)
float Norm(const Quaternion& q);

void QuaternionScreenPrintf(int x, int y, const Quaternion& quaternion, const char* label);

Quaternion operator+(const Quaternion& q1, const Quaternion& q2);

Quaternion operator*(float s, const Quaternion& q);

Quaternion operator*(const Quaternion& q, float s);

Quaternion operator/(const Quaternion& q, float s);

bool operator==(const Quaternion& q1, const Quaternion& q2);
