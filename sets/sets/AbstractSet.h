#pragma once

#include "SetContainerAdapter.h"

#include <vector>

template <typename AdapterT>
class AbstractSet {
  public:
	AbstractSet() = default;
	AbstractSet(AdapterT adapter) : adapter(adapter){};
	AbstractSet(std::initializer_list<typename AdapterT::innerType> l) : adapter(l){};

	size_t getSize() const
	{
		return adapter.size();
	}

	bool contains(const typename AdapterT::keyType &key) const
	{
		return adapter.contains(key);
	}

	void display() const
	{
		adapter.display();
	}

	void add(const typename AdapterT::innerType &x)
	{
		if (adapter.contains(AdapterT::getKey(x))) return;

		adapter.add(x);
		adapter.sort();
	}

	bool remove(const typename AdapterT::keyType &x)
	{
		if (!adapter.contains(x)) return false;

		adapter.remove(x);

		return true;
	}

	AbstractSet<AdapterT> unionWith(const AbstractSet<AdapterT> &other) const
	{
		AbstractSet<AdapterT> out(adapter);

		other.forEach([&out](const typename AdapterT::innerType &x) { out.add(x); });

		return out;
	}

	AbstractSet<AdapterT> intersectWith(const AbstractSet<AdapterT> &other) const
	{
		AbstractSet<AdapterT> out;

		this->forEach([&out, &other](const typename AdapterT::innerType &x) {
			if (other.contains(AdapterT::getKey(x))) {
				out.add(x);
			}
		});

		return out;
	}

	AbstractSet<AdapterT> complementWith(const AbstractSet<AdapterT> &other) const
	{
		return other.differenceWith(*this);
	}

	AbstractSet<AdapterT> differenceWith(const AbstractSet<AdapterT> &other) const
	{
		AbstractSet<AdapterT> out;

		this->forEach([&out, &other](const typename AdapterT::innerType &x) {
			if (!other.contains(AdapterT::getKey(x))) {
				out.add(x);
			}
		});

		return out;
	}

	static AbstractSet<AdapterT> symmetricComplement(const AbstractSet<AdapterT> &lhs, const AbstractSet<AdapterT> &rhs)
	{
		return lhs.unionWith(rhs).differenceWith(lhs.intersectWith(rhs));
	}

	static std::vector<std::pair<typename AdapterT::innerType, typename AdapterT::innerType>> cartesianProduct(
	    const AbstractSet<AdapterT> &lhs, const AbstractSet<AdapterT> &rhs)
	{
		std::vector<std::pair<typename AdapterT::innerType, typename AdapterT::innerType>> out;

		lhs.forEach([&out, &rhs](const typename AdapterT::innerType &x) {
			rhs.forEach([&out, &x](const typename AdapterT::innerType& y) {
				out.emplace_back(x, y);
			});
		});

		return out;
	}

	void forEach(std::function<void(const typename AdapterT::innerType &)> f) const
	{
		adapter.forEach(f);
	}

  private:
	AdapterT adapter;

	void sort()
	{
		adapter.sort();
	}
};
