#include "Quaternion.h"
#include <Novice.h>

Quaternion Add(const Quaternion& q1, const Quaternion& q2)
{
	
	Quaternion anser;

	anser.x = q1.x + q2.x;
	anser.y = q1.y + q2.y;
	anser.z = q1.z + q2.z;
	anser.w = q1.w + q2.w;

	return anser;

}

Quaternion Normalize(const Quaternion& q) {
	float norm = Norm(q);
	return q / norm;
}

float Dot(const Quaternion& q1, const Quaternion& q2)
{
	float anser;
	anser = (q1.x * q2.x) + (q1.y * q2.y) + (q1.z * q2.z) + (q1.w * q2.w);

	return anser;
}

Quaternion Multiply(float scalar, const Quaternion& q)
{
	
	Quaternion anser;

	anser.x = q.x * scalar;
	anser.y = q.y * scalar;
	anser.z = q.z * scalar;
	anser.w = q.w * scalar;

	return anser;

}

Quaternion Multiply(const Quaternion& q1, const Quaternion& q2)
{
	Quaternion anser;

	anser.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	anser.x = q1.y * q2.z - q1.z * q2.y + q1.x * q2.w + q1.w * q2.x;
	anser.y = q1.z * q2.x - q1.x * q2.z + q1.y * q2.w + q1.w * q2.y;
	anser.z = q1.x * q2.y - q1.y * q2.x + q1.z * q2.w + q1.w * q2.z;

	return anser;
}

Quaternion IdentityQuaternion()
{
	Quaternion anser;

	anser.w = 1.0f;
	anser.x = 0.0f;
	anser.y = 0.0f;
	anser.z = 0.0f;

	return anser;
}

Quaternion Conjugate(const Quaternion& quaternion)
{
	Quaternion anser;

	anser.w = quaternion.w;
	anser.x = -quaternion.x;
	anser.y = -quaternion.y;
	anser.z = -quaternion.z;

	return anser;
}

Quaternion Inverse(const Quaternion& quaternion)
{
	float norm = Norm(quaternion);
	return Conjugate(quaternion) / (norm * norm);
}

float Norm(const Quaternion& q)
{
	float anser;
	anser = sqrtf(Dot(q, q));

	return anser;

}

Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis, float angle)
{
	Quaternion q;

	float halfCosTheta = std::cos(angle / 2.0f);
	float halfSinTheta = std::sin(angle / 2.0f);

	q.x = axis.x * halfSinTheta;
	q.y = axis.y * halfSinTheta;
	q.z = axis.z * halfSinTheta;
	q.w = halfCosTheta;

	return Normalize(q);
}

Vector3 RotateVector(const Vector3& vector, const Quaternion& quaternion)
{
	Quaternion vectorQ;
	vectorQ.x = vector.x;
	vectorQ.y = vector.y;
	vectorQ.z = vector.z;
	vectorQ.w = 0.0f;

	Vector3 anser;
	Quaternion q = Multiply(Multiply(quaternion, vectorQ), Conjugate(quaternion));
	anser.x = q.x;
	anser.y = q.y;
	anser.z = q.z;

	return anser;
}

void QuaternionScreenPrintf(int x, int y, const Quaternion& quaternion, const char* label)
{
	Novice::ScreenPrintf(x, y, "%.02f", quaternion.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", quaternion.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", quaternion.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%.02f", quaternion.w);
	Novice::ScreenPrintf(x + kColumnWidth * 4, y, "%s", label);
}

Quaternion operator+(const Quaternion& q1, const Quaternion& q2)
{
	return Add(q1, q2);
}

Quaternion operator-(const Quaternion& q)
{
	return { -q.x, -q.y, -q.z, -q.w };
}

Quaternion operator*(float s, const Quaternion& q)
{
	return Multiply(s, q);
}

Quaternion operator*(const Quaternion& v, float s)
{
	return s * v;
}

Quaternion operator/(const Quaternion& q, float s)
{
	return Multiply(1.0f / s, q);
}

bool operator==(const Quaternion& q1, const Quaternion& q2)
{
	if (q1.x == q2.x && q1.y == q2.y && q1.z == q2.z && q1.w == q2.w) {
		return true;
	}
	return false;
}
