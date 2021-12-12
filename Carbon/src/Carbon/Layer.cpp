#include "cnpch.h"
#include "Layer.h"


namespace Carbon {



	Layer::Layer(const std::string& name /*= "Layer"*/)
	{
#ifdef CN_DEBUG
		m_DebugName = name;
#endif // CN_DEBUG

	}

	Layer::~Layer()
	{

	}

}