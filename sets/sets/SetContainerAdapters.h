#pragma once

#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>

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

template <typename T>
class DequeAdapter {
  public:
	typedef T keyType;
	typedef T innerType;

	DequeAdapter() = default;
	DequeAdapter(const std::deque<T> &d) : innerContainer(d){};
	DequeAdapter(std::initializer_list<T> l) : innerContainer(l){};

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
	std::deque<T> innerContainer;
};

template <typename T>
class SetAdapter {
  public:
	typedef T keyType;
	typedef T innerType;

	SetAdapter() = default;
	SetAdapter(const std::set<T> &s) : innerContainer(s){};
	SetAdapter(std::initializer_list<T> l) : innerContainer(l){};

	size_t size() const
	{
		return innerContainer.size();
	}

	bool contains(const T &x) const
	{
		return innerContainer.find(x) != innerContainer.end();
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
	}

	void add(const T &x)
	{
		innerContainer.insert(x);
	}

	void remove(const T &x)
	{
		innerContainer.erase(x);
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
	std::set<T> innerContainer;
};

template <typename KeyT, typename ValueT>
class MapAdapter {
  public:
	typedef KeyT keyType;
	typedef std::pair<const KeyT, ValueT> innerType;

	MapAdapter() = default;
	MapAdapter(const std::map<KeyT, ValueT> &m) : innerContainer(m){};
	MapAdapter(std::initializer_list<std::pair<const KeyT, ValueT>> l) : innerContainer(l){};

	size_t size() const
	{
		return innerContainer.size();
	}

	bool contains(const KeyT &x) const
	{
		return innerContainer.find(x) != innerContainer.end();
	}

	void display() const
	{
		for (const auto &p : innerContainer) {
			std::cout << '(' << p.first << ", " << p.second << ") ";
		}
		std::cout << std::endl;
	}

	void sort()
	{
	}

	void add(const std::pair<KeyT, ValueT> &p)
	{
		innerContainer.insert(p);
	}

	void remove(const KeyT &x)
	{
		innerContainer.erase(x);
	}

	void forEach(std::function<void(const std::pair<KeyT, ValueT> &p)> f) const
	{
		std::for_each(innerContainer.begin(), innerContainer.end(), f);
	}

	static KeyT getKey(const std::pair<KeyT, ValueT> &p)
	{
		return p.first;
	}

  private:
	std::map<KeyT, ValueT> innerContainer;
};

} // namespace setAdapters
