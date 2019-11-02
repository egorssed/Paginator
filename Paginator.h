#include <vector>


using namespace std;



template<typename Iterator>
class IteratorRange {
private:
	Iterator first,last;
public:
	IteratorRange(Iterator f, Iterator l) :first(f), last(l){}
	auto begin() { return first; }
	auto end() { return last; }

	auto begin() const { return first; }
	auto end() const { return last; }

	size_t size() const { return last - first; }
};

template <typename Iterator>
class Paginator {
public:
	Paginator(Iterator begin, Iterator end, size_t page_size):first(begin),last(end){
		for (size_t i = 0; i < (size_t)(end - begin); i += page_size) {
			pages.push_back({ begin + i,begin + min(i + page_size,(size_t)(end - begin)) });
		}
	}

	auto begin() const{ return pages.begin(); }
	auto end() const{ return pages.end(); }

	size_t size() const{ return pages.size(); }
private:
	Iterator first, last;
	vector<IteratorRange<Iterator>> pages;
};

template <typename C>
auto Paginate(C& c, size_t page_size) {
	return Paginator{ c.begin(), c.end(), page_size };
}


