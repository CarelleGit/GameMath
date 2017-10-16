#include "Mathutils.h"
#include "Vec2.h"
#include "Vec3.h"
#include <iostream>
using std::cout;
int main()
{
	//int val = min(1, 3);
	////OPEN 1
	////Addtion
	//vec2 test;
	//test.x = 7;
	//test.y = 1;
	//vec2 test2;
	//test2.x = 3;
	//test2.y = 2;
	//vec2 res = test + test2;
	////Subtraction
	//vec2 sub;
	//sub.x = 2;
	//sub.y = 5;
	//vec2 sub2;
	//sub2.x = 4;
	//sub2.y = 8;
	//vec2 sRes = sub - sub2;
	////Muti
	//vec2 sca;
	//sca.x = 2;
	//sca.y = 2;
	//vec2 multi;
	//multi.x = 3;
	//vec2 mRes = sca * multi;
	////Divide
	//vec2 div;
	//div.x = 6;
	//div.y = 6;
	//vec2 Sca;
	//Sca.x = 2;
	//vec2 dRes = div / Sca;
	////Negative
	//vec2 negative;
	//negative.x = 5;
	//negative.y = 2;
	//vec2 nRes = negative | negative;
	////Equal
	//vec2 eq1;
	//eq1.x = 7;
	//eq1.y = 1;
	//vec2 eq2;
	//eq2.x = 7;
	//eq2.y = 1;
	//bool eRes = eq1 == eq2;
	////Not Equal
	//vec2 nEq;
	//nEq.x = 2;
	//nEq.y = 5;
	//vec2 nEq2;
	//nEq2.x = 4;
	//nEq2.y = 8;
	//bool nEres = nEq != nEq2;
	////CLOSED 1
	////+=
	//vec2 pEq;
	//pEq.x = 7;
	//pEq.y = 1;
	//vec2 pEq2;
	//pEq2.x = 3;
	//pEq2.y = 2;
	//vec2 pEres = pEq += pEq2;
	////-=
	//vec2 sEq;
	//sEq.x = 2;
	//sEq.y = 5;
	//vec2 sEq2;
	//sEq2.x = 4;
	//sEq2.y = 8;
	//vec2 sEres = sEq -= sEq2;
	////*=
	//vec2 mEq;
	//mEq.x = 2;
	//mEq.y = 2;
	//vec2 mEq2;
	//mEq2.x = 3;
	//vec2 mEres = mEq *= mEq2;
	//// /=
	//vec2 dEq;
	//dEq.x = 6;
	//dEq.y = 6;
	//vec2 dEq2;
	//dEq2.x = 2;
	//vec2 dEres = dEq /= dEq2;

	vec3 add;
	add.x = 7;
	add.y = 1;
	add.z = 4;
	vec3 rAdd;
	rAdd.x = 3;
	rAdd.y = 2;
	rAdd.z = 1;
	vec3 aRes = add + rAdd;

	vec3 lsub;
	lsub.x = 2;
	lsub.y = 5;
	lsub.z = 0;
	vec3 rSub;
	rSub.x = 4;
	rSub.y = 8;
	rSub.z = 6;
	vec3 sRes = lsub - rSub;

	vec3 lSca;
	lSca.x = 2;
	lSca.y = 2;
	lSca.z = 1;
	vec3 scRes = lSca * 3;

	vec3 r2Sca;
	r2Sca.x = 2;
	r2Sca.y = 2;
	r2Sca.z = 1;
	vec3 sc2Res = 3 * r2Sca;

	vec3 rDiv;
	rDiv.x = 6;
	rDiv.y = 6;
	rDiv.z = 2;
	vec3 dRes = rDiv / 2;

	vec3 a2Res = add += rAdd;

	vec3 s2Res = lsub -= rSub;

	vec3 sc3Res = lSca *= 3;

	vec3 d2Res = rDiv /= 2;
	
	vec3 sub;
	sub.x = 7;
	sub.y = 4;
	sub.z = 9;
	sub[1];

	vec3 m;
	m.x = 1;
	m.y = 1;
	m.z = 1;
	mag(m);

	norm(m);
 	while (true) {}
}