#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

namespace setAdapters {

template <typename T>
class VectorAdapter {
  public:
	typedef T keyType;
	typedef T innerType;

	VectorAdapter(std::vector<T> v) : innerContainer(v){};

	size_t size() const
	{
		return innerContainer.size();
	}

	bool contains(const T &x) const
	{
		return std::find(innerContainer.begin(), innerContainer.end(), x) != innerContainer.end();
	}

	void display() const
	{
		for (const T &x : innerContainer) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}

	void sort()
	{
		std::sort(innerContainer.begin(), innerContainer.end());
	}

  private:
	std::vector<T> innerContainer;
};

} // namespace setAdapters
