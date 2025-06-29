

template <typename T>
class Slice {
	T* data = undefined;
	size_t length = 0;
	size_t startIndex = 0;
	size_t endIndex = 0;

	// The real useful constructor, called only via Array
	Slice(Pointer<T*> source, size_t start = 0, size_t end) 
	: 	data(source),
		startIndex(start),
		endIndex(end)
	{ }

	~Slice();


public:
		// Publically accessible to create placeholder blank Slices
		Slice() {}
};