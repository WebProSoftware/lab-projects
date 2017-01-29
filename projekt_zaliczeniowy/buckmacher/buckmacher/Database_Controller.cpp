#include "stdafx.h"
#include "Database_Controller.h"
#include "Zaklad.h"

template<typename T>
Database_Controller<T>::Database_Controller()
{
}

template<typename T>
Database_Controller<T>::~Database_Controller()
{

}

template class Database_Controller<Zaklad>;