#pragma once

#include <utility>   // for std::forward
#include <functional> // for std::invoke
#include <type_traits> // for constexpr optimization


namespace cpps {
	template <typename T>
	concept Nullable = requires {
		{ T::CreateDefault() } -> std::same_as<T>;
	};

	template <typename T>
	concept NullConstructible =
		std::default_initializable<T> || Nullable<T>;


	/// @brief Nullor<T> is a lightweight container that represents a possibly "null" value.
	/// 
	/// Unlike std::optional, this class is a minimal wrapper intended primarily for short-lived 
	//  nullable returns (equivalent to TypeScript's T | undefined). 
	/// However, it is also safe and efficient enough for longer-term use if needed.
	///
	/// It stores the value in-place without heap allocation, tracks validity via a bool,
	/// and exposes the expected methods to check nullness and resolve the value.
	///
	/// Typical usage:
	/// ```cpp
	/// Nullor<int> obj = SomeFunction();
	/// if (obj)
	/// {
	///     int v = n.Resolve();
	///     // v now has the value
	/// }
	/// ```
	/// Resolving a null object will null-construct a new object with no meaningful data. 
	/// To avoid depending on meaningless data, remember to check for nullness before you resolve!
	template<NullConstructible T>
	class Nullor {
	private:
		bool hasMeaning = false;

		// Placement storage for T with proper alignment
		alignas(T) unsigned char storage[sizeof(T)];

		// Accessor to stored object (non-const)
		T* ptr() noexcept {
			return reinterpret_cast<T*>(storage);
		}

		// Accessor to stored object (const)
		const T* ptr() const noexcept {
			return reinterpret_cast<const T*>(storage);
		}

		// Destroys the stored object if valid.
		void Destroy() noexcept {
			if (hasMeaning) {
				ptr()->~T();
				hasMeaning = false;
			}
		}

	public:
		// Nullary constructor creates null state.
		Nullor() noexcept = default;

		// Construct from const T& (copy)
		Nullor(const T& value)
			: hasMeaning(true) {
			new (storage) T(value);
		}

		// Construct from T&& (move)
		Nullor(T&& value) noexcept(std::is_nothrow_move_constructible_v<T>)
			: hasMeaning(true) {
			new (storage) T(std::move(value));
		}

		// Copy constructor
		Nullor(const Nullor& rhs)
			: hasMeaning(rhs.hasMeaning) {
			if (hasMeaning) {
				new (storage) T(*rhs.ptr());
			}
		}

		// Move constructor
		Nullor(Nullor&& rhs) noexcept(std::is_nothrow_move_constructible_v<T>)
			: hasMeaning(rhs.hasMeaning) {
			if (hasMeaning) {
				new (storage) T(std::move(*rhs.ptr()));
				rhs.Destroy();
			}
		}

		// Copy assignment
		Nullor& operator=(const Nullor& rhs) {
			if (this != &rhs) {
				if (hasMeaning && rhs.hasMeaning) {
					*ptr() = *rhs.ptr();
				}
				else if (hasMeaning) {
					Destroy();
				}
				else if (rhs.hasMeaning) {
					new (storage) T(*rhs.ptr());
					hasMeaning = true;
				}
			}
			return *this;
		}

		// Move assignment
		Nullor& operator=(Nullor&& rhs) noexcept(std::is_nothrow_move_assignable_v<T>&& std::is_nothrow_move_constructible_v<T>) {
			if (this != &rhs) {
				if (hasMeaning && rhs.hasMeaning) {
					*ptr() = std::move(*rhs.ptr());
					rhs.Destroy();
				}
				else if (hasMeaning) {
					Destroy();
				}
				else if (rhs.hasMeaning) {
					new (storage) T(std::move(*rhs.ptr()));
					hasMeaning = true;
					rhs.Destroy();
				}
			}
			return *this;
		}

		// Destructor destroys the contained object if valid.
		~Nullor() {
			Destroy();
		}

		/// @brief Check whether the contained value is null.
		/// @return true if null (empty), false otherwise.
		bool IsNull() const noexcept {
			return !hasMeaning;
		}

		/// @brief Allows idiomatic if (nullable) checks.
		explicit operator bool() const noexcept {
			return hasMeaning;
		}

		/**
		 * @brief Effectively converts Nullable<T> to the underlying T.
		 *
		 * This is the primary way to extract the value for further use.
		 *
		 * @warning
		 * Always check nullness before resolving.
		 * Resolving a null returns a null-constructed object with meaningless
		 * data. Treating such data as if it were meaningful could cause headaches.
		 *
		 * @return an object of type T
		 */
		T Resolve() {
			if (hasMeaning)
			{
				hasMeaning = false;
				return std::move(*ptr()); // consume stored T
			}
			else
			{
				if constexpr (std::default_initializable<T>)
				{
					return T{};
				}
				else if constexpr (Nullable<T>)
				{
					return T::CreateDefault();
				}
			}
		}

		const T* Content() const {
			return (hasMeaning) ? ptr() : nullptr;
		}
	};
}
