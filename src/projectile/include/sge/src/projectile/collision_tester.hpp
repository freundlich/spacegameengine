/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2013 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_SRC_PROJECTILE_COLLISION_TESTER_HPP_INCLUDED
#define SGE_SRC_PROJECTILE_COLLISION_TESTER_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <BulletCollision/CollisionDispatch/btCollisionWorld.h>
#include <fcppt/config/external_end.hpp>


namespace sge
{
namespace projectile
{

class collision_tester
:
	public btCollisionWorld::ContactResultCallback
{
	FCPPT_NONCOPYABLE(
		collision_tester
	);
public:
	collision_tester();

	~collision_tester();

	bool
	result() const;
private:
	btScalar
	addSingleResult(
		btManifoldPoint &,
		btCollisionObjectWrapper const *colObj0Wrap,
		int partId0,
		int index0,
		btCollisionObjectWrapper const *colObj1Wrap,
		int partId1,
		int index1
	);

	bool result_;
};

}
}

#endif
