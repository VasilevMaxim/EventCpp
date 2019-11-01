/*
MIT License
Copyright (c) 2019 Maxim Vasilev
*/

#pragma once
#include <vector>

template <class T, typename... Arg>
class Event
{
	typedef void(T::*delegate)(Arg...);

	std::vector<delegate> methods;
	std::vector<T*> objects;
public:
	Event();
	~Event();

	void Add(T* t, delegate x);
	void Insert(Arg... arg);
	void Remove(T* t, delegate x);
	void RemoveAll();
};

template <class T, typename... Arg>
Event<T, Arg...>::Event()
{
}

template <class T, typename... Arg>
Event<T, Arg...>::~Event()
{
}

template <class T, typename... Arg>
void Event<T, Arg...>::Add(T* t, delegate x)
{
	methods.push_back(x);
	objects.push_back(t);
}

template <class T, typename... Arg>
void Event<T, Arg...>::Insert(Arg... arg)
{
	int size = methods.size();
	for (int i = 0; i < size; i++)
	{
		((*objects[i]).*(methods[i]))(arg...);
	}
}
