/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "./LdLoader.hpp"
#include "../../shared/ArcadeError.hpp"

template<class T>
LDLoader<T>::~LDLoader()
= default;

template<class T>
void LDLoader<T>::loadLib(const std::string &libPath)
{
    int res = 0;

    if (this->_handle)
        res = LDLoader<void>::close(this->_handle);

    if (res != 0)
        std::cerr << "ERROR (" << std::to_string(res) << "): while closing a dynamic library" << std::endl;

    this->_handle = LDLoader<void>::open(libPath);

    this->_lib_factory = (T *(*)()) LDLoader<void>::getSymbol(this->_handle, "make");

    this->_id = *(int *) LDLoader<void>::getSymbol(this->_handle, "id");

    std::cout << "Library \"" << libPath << "\" loaded." << std::endl;
}

template<class T>
T *LDLoader<T>::getInstance()
{
    if (this->_lib_factory)
        return this->_lib_factory();
    else {
        std::cerr << "Error accessing factory" << std::endl;
        return nullptr;
    }
}

template<class T>
void *LDLoader<T>::open(const std::string &path)
{
    // RTLD_NOW seems better in order to manage errors and avoid crashes
    // at all cost
    void *handle = dlopen(path.c_str(), RTLD_NOW);

    if (handle == nullptr)
        throw Error::Arcade(dlerror());
    return handle;
}

template<class T>
void *LDLoader<T>::getSymbol(void *handle, const std::string &name)
{
    void *symbol = dlsym(handle, name.c_str());

    if (symbol == nullptr)
        throw Error::Arcade(dlerror());
    return symbol;
}

template<class T>
int LDLoader<T>::close(void *handle)
{
    if (handle != nullptr)
        return dlclose(handle);
    return 84;
}

template<class T>
void LDLoader<T>::clear()
{
    this->_handle = nullptr;
    this->_lib_factory = nullptr;
}

template<class T>
int LDLoader<T>::getId()
{
    return this->_id;
}

template<class T>
void LDLoader<T>::closeLoadedLib()
{
    if (this->_handle) {
        LDLoader<void>::close(this->_handle);
        this->_handle = nullptr;
        this->_lib_factory = nullptr;
    }
}

template
class LDLoader<IGraphicsLib>;

template
class LDLoader<IGameLib>;

// for static functions
template
class LDLoader<void>;
