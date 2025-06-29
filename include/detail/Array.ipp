#pragma once
#include "include/cppscript/Array.h"

template <typename T>
Array<T>::Array(size_t capacity) :
	length(capacity),
	data(std::make_unique<T*>(capacity))
{ }

template <typename T>
Array<T>::Array(size_t capacity, T* source) :
	length(capacity),
	data(std::make_unique<T*>(capacity))
{
	size_t sourceSize = sizeof(source) / sizeof(T);
	size_t 
}

template <typename T>
Array<T>::Array(const Array& rhs) : 
	length(rhs.length),
	data(std::make_unique<T*>(length))
{
	
}

template <typename T>
ForEach<T>()
{
	for(int i = 0; i < length; i++)
	{
	
	}
}

template <typename T>
Array<T>::Array(const Array&& rhs)
	length(0),
	data(std::move(rhs)){
	this.length = data.length;
}

template <typename T>
Array<T>::~Array()
{

}

template <typename T>
ElementProxy<T> Array<T>::operator[](size_t index){

}             // non-const

template <typename T>
const T& Array<T>::operator[](size_t index) const{

}                // const

template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& rhs){

}

template <typename T>
Array<T>& Array<T>::operator = (const Array<T>&& rhs){

}

template <typename T>
bool Array<T>::operator != (const Array<T>& rhs) const{

}

template <typename T>
bool Array<T>::IsEquivalent(Array<T> rhs){

}

template <typename T>
bool Array<T>::IsEquivalent(T* rhs){

}

template <typename T>
bool Array<T>::IsSubarrayOf(Array<T> standard){

}

template <typename T>
bool Array<T>::IsSubarrayOf(T* standard){

}

template <typename T>
bool Array<T>::Includes(T target){

}

template <typename T>
bool Array<T>::ContainsSubarray(Array<T> rhs){

}

template <typename T>
bool Array<T>::ContainsSubarray(T* rhs){

}

template <typename T>
bool Array<T>::IsPrefixOf(Array<T> standard){

}

template <typename T>
bool Array<T>::IsSuffixOf(Array<T> standard)
{

}

template <typename T>
size_t Array<T>::FirstInstanceOf(T target) const{

}

template <typename T>
size_t Array<T>::LastInstanceOf(T target) const{

}

template <typename T>
T* Array<T>::DeepCopy_AsPrimitive(){

}

template <typename T>
Array<T> Array<T>::DeepCopy(){

}

template <typename T>
void Array<T>::Reverse(){

}

template <typename T>
Array<T> Array<T>::ReverseClone(){

}