#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <list>

namespace setAdapters {

template <typename T>
class VectorAdapter {
  public:
	typedef T keyType;
	typedef T innerType;

	VectorAdapter() = default;
	VectorAdapter(const std::vector<T> &v) : innerContainer(v){};
	VectorAdapter(std::initializer_list<T> l) : innerContainer(l){};

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

	void add(const T &x)
	{
		innerContainer.push_back(x);
	}

	void remove(const T &x)
	{
		innerContainer.erase(std::find(innerContainer.begin(), innerContainer.end(), x));
	}

	void forEach(std::function<void(const T &x)> f) const
	{
		std::for_each(innerContainer.begin(), innerContainer.end(), f);
	}

	static T getKey(const T &x)
	{
		return x;
	}

  private:
	std::vector<T> innerContainer;
};

template <typename T>
class ListAdapter {
  public:
	typedef T keyType;
	typedef T innerType;

	ListAdapter() = default;
	ListAdapter(const std::list<T> &l) : innerContainer(l){};
	ListAdapter(std::initializer_list<T> l) : innerContainer(l){};

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
		innerContainer.sort();
	}

	void add(const T &x)
	{
		innerContainer.push_back(x);
	}

	void remove(const T &x)
	{
		innerContainer.erase(std::find(innerContainer.begin(), innerContainer.end(), x));
	}

	void forEach(std::function<void(const T &x)> f) const
	{
		std::for_each(innerContainer.begin(), innerContainer.end(), f);
	}

	static T getKey(const T &x)
	{
		return x;
	}

  private:
	std::list<T> innerContainer;
};

} // namespace setAdapters
