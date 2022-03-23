/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "./LdLoader.hpp"

template <class T>
LDLoader<T>::~LDLoader()
{

}

template <class T>
void LDLoader<T>::loadLib(std::string libPath)
{
    if (this->_handle)
        dlclose(this->_handle);
    this->_handle = dlopen(libPath.c_str(), RTLD_NOW);
    if (!this->_handle)
        std::cerr << "Error opening shared library" << std::endl;
    else
        this->_lib_factory = (T *(*)())dlsym(this->_handle, "make");
    // RTLD_NOW seems better in order to manage errors and avoid crashes
    // at all cost
}

template <class T>
T *LDLoader<T>::getInstance()
{
    if (this->_lib_factory)
        return this->_lib_factory();
    else {
        std::cerr << "Error accessing factory" << std::endl;
        return NULL;
    }
}

template class LDLoader<IGraphicsLib>;
template class LDLoader<IGameLib>;