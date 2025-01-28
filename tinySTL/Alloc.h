#ifndef _ALLOC_H_
#define _ALLOC_H_

#include <cstdlib>

namespace tinySTL {

	class alloc {
		private:
			enum EAlign{ ALIGN = 8 };
			enum EMaxBytes{ MAX_BYTES = 128 };
			enum ENFreeLists{ NFREELISTS = (EMaxBytes::MAX_BYTES / EAlign::ALIGN) };
			enum ENObjs{ NOBJS = 20 };
		private:
			union obj {
				union obj* next;
				char client[1];
			};

			static obj* free_list[ENFreeLists::NFREELISTS];
		private:
			static char *start_free;
			static char *end_free;
			static size_t heap_size;
		private:
			static size_t ROUND_UP(size_t bytes) {
				return ((bytes + EAlign::ALIGN - 1) & ~(EAlign::ALIGN - 1));
			}
			static size_t FREELIST_INDEX(size_t bytes) {
				return (((bytes)+EAlign::ALIGN - 1) / EAlign::ALIGN - 1);
			}
			static void *refill(size_t bytes);
			static void *chunck_alloc(size_t size, size_t& nobjs);

		public:
			static void *allocate(size_t bytes);
			static void deallocate(void *ptr, size_t bytes);
			static void *reallocate(void *ptr, size_t old_sz, size_t new_sz);
	};

} // namespace tinySTL

#endif // !

