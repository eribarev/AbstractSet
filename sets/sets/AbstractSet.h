#pragma once

#include "SetContainerAdapter.h"

#include <vector>

template <typename AdapterT>
class AbstractSet {
  public:
	AbstractSet(AdapterT adapter) : adapter(adapter){};

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

	AbstractSet<AdapterT> unionWith(const AbstractSet<AdapterT> &other) const;
	AbstractSet<AdapterT> intersectWith(const AbstractSet<AdapterT> &other) const;
	AbstractSet<AdapterT> complementWith(const AbstractSet<AdapterT> &other) const;
	static AbstractSet<AdapterT> symmetrictComplement(const AbstractSet<AdapterT> &lhs,
													  const AbstractSet<AdapterT> &rhs);
	static std::vector<std::pair<typename AdapterT::innerType, typename AdapterT::innerType>> cartesianProduct(
		const AbstractSet<AdapterT> &lhs, const AbstractSet<AdapterT> &rhs);

  private:
	AdapterT adapter;

	void sort()
	{
		adapter.sort();
	}
};
