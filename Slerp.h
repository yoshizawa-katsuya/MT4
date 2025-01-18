#pragma once
#include "Struct.h"

//球面線形補完
Vector3 Slerp(const Vector3& v1, const Vector3& v2, float t);

Quaternion Slerp(const Quaternion& q1, const Quaternion& q2, float t);
