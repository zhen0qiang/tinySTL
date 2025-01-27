#ifndef TYPE_TRAITS_H
#define TYPE_TRAITS_H

namespace tinySTL {
	
	namespace {
		template<bool, class Ta, class Tb>
		struct IfThenElse;
		
		template<class Ta, class Tb>
